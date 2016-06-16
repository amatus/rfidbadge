#include <Arduino.h>
#include <Wire.h>
#include "CLRC663.h"

Clrc663::Clrc663(uint8_t address) : addr(address)
{
}

uint8_t Clrc663::read_reg(Reg reg)
{
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(addr, (uint8_t)1);
  return Wire.read();
}

void Clrc663::write_reg(Reg reg, uint8_t val)
{
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

void Clrc663::iso_14443A_init()
{
  //> Configure Timers
  write_reg(T0Control, 0x98);           //Starts at the end of Tx. Stops after Rx of first data. Auto-reloaded. 13.56 MHz input clock.
  write_reg(T1Control, 0x92);          //Starts at the end of Tx. Stops after Rx of first data. Input clock - cascaded with Timer-0.
  write_reg(T2Control, 0x20);          //Set Timer-2, T2Control_Reg:  Timer used for LFO trimming
  write_reg(T2ReloadHi, 0x03);         //Set Timer-2 reload value (T2ReloadHi_Reg and T2ReloadLo_Reg)
  write_reg(T2ReloadLo, 0xFF);         //
  write_reg(T3Control, 0x00);          // Not started automatically. Not reloaded. Input clock 13.56 MHz
  write_reg(FIFOControl, 0x10);

  write_reg(WaterLevel, 0xFE);        //Set WaterLevel =(FIFO length -1),cause fifo length has been set to 255=0xff,so water level is oxfe
  write_reg(RxBitCtrl, 0x80);         //RxBitCtrl_Reg(0x0c)  Received bit after collision are replaced with 1.
  write_reg(DrvMod, 0x80);            //DrvMod reg(0x28), Tx2Inv=1,Inverts transmitter 1 at TX1 pin
  write_reg(TxAmp, 0x00);             // TxAmp_Reg(0x29),output amplitude  0: TVDD -100 mV(maxmum)
  write_reg(DrvCon, 0x01);            // TxCon register (address 2Ah),TxEnvelope
  write_reg(Txl, 0x05);               //
  write_reg(RxSofD, 0x00);            //
  write_reg(Rcv, 0x12);               //
//> =============================================
//>  LoadProtocol( bTxProtocol=0, bRxProtocol=0)
//> =============================================
  write_reg(Command, Idle);           // Terminate any running command.
  write_reg(FIFOControl, 0xB0);       // Flush_FiFo,low alert


  write_reg(IRQ0, 0x7F);             // Clear all IRQ 0,1 flags
  write_reg(IRQ1, 0x7F);             //
  //> Write in Fifo: Tx and Rx protocol numbers(0,0)
  write_reg(FIFOData, 0x00);         //
  write_reg(FIFOData, 0x00);         //
  ////allows the Idle interrupt request means the command is finished and set gobal irq
  write_reg(IRQ0En, 0x10);          // Idle interrupt(Command terminated), RC663_BIT_IDLEIRQ=0x10
  write_reg(IRQ1En, 0x40);         //bit 6Set to logic 1, it allows the global interrupt request (indicated by the bit
                                      //GlobalIrq) to be propagated to the interrupt pin
  write_reg(Command, LoadProtocol);    // Start RC663 command "Load Protocol"=0x0d
  while (!(read_reg(IRQ1) & 0x40)); //Wait untill global interrupt set,meanning the command has done execution

  write_reg(IRQ0, 0x00);              //Disable Irq 0,1 sources
  write_reg(IRQ1, 0x00);              //


  write_reg(FIFOControl, 0xB0);       // Flush_FiFo

// Apply RegisterSet
//
//> Configure CRC-16 calculation, preset value(0x6363) for Tx&Rx

  write_reg(TxCrcPreset, 0x18);           //means preset value is 6363,and uses CRC 16,but CRC is not automaticlly apended to the data
  write_reg(RxCrcPreset, 0x18);           //


  write_reg(TxDataNum, 0x08);             //
  write_reg(TxModWidth, 0x20);            // Length of the pulse modulation in carrier clks+1
  write_reg(TxSym10BurstLen, 0x00);       // Symbol 1 and 0 burst lengths = 8 bits.
  write_reg(FrameCon, 0xCF);             // Start symbol=Symbol2, Stop symbol=Symbol3
  write_reg(RxCtrl, 0x04);               // Set Rx Baudrate 106 kBaud

  write_reg(RxThreshold, 0x32);          // Set min-levels for Rx and phase shift
  write_reg(RxAna, 0x00);
  write_reg(RxWait, 0x90);             // Set Rx waiting time
  write_reg(TXWaitCtrl, 0xC0);
  write_reg(TxWaitLo, 0x0B);
  write_reg(T0ReloadHi, 0x08);         // Set Timeout. Write T0,T1 reload values(hi,Low)
  write_reg(T0ReloadLo, 0xD8);
  write_reg(T1ReloadHi, 0x00);
  write_reg(T1ReloadLo, 0x00);

  write_reg(DrvMod, 0x81);               // Write DrvMod register

  //> MIFARE Crypto1 state is further disabled.
  write_reg(Status, 0x00);
}

void Clrc663::transmit_enable(bool enable)
{
  write_reg(DrvMod, enable ? 0x89 : 0x81);
}

int Clrc663::iso_14443A_reqa(uint8_t *atqa)
{
  atqa[0] = 0;
  atqa[1] = 0;
  //> =============================================
//>  I14443p3a_Sw_RequestA
//> =============================================
  write_reg(TXWaitCtrl, 0xC0);       //  TxWaitStart at the end of Rx data
  write_reg(TxWaitLo, 0x0B);         // Set min.time between Rx and Tx or between two Tx
  //tempErrorCode=read_reg(Error);
  write_reg(T0ReloadHi, 0x08);       //> Set timeout for this command cmd. Init reload values for timers-0,1
  write_reg(T0ReloadLo, 0x94);
  write_reg(T1ReloadHi, 0x00);
  write_reg(T1ReloadLo, 0x00);
  write_reg(IRQ0, 0x08);  //why ? ,传送完成中断，TxIrq Set, when data transmission is completed, which is immediately after the last bit is sent. Can only be reset if Set is cleared.
  write_reg(RxWait, 0x90);    // bit9,If set to 1, the RxWait time is RxWait x(0.5/DBFreq).  bit0--bit6,Defines the time after sending, where every input is ignored
  write_reg(TxDataNum, 0x0F);
//> ---------------------
//> Send the ReqA command
//> ---------------------
  write_reg(Command, Idle);           // Terminate any running command.
  write_reg(FIFOControl, 0xB0);       // Flush_FiFo


  write_reg(IRQ0, 0x7F);           // Clear all IRQ 0,1 flags
  write_reg(IRQ1, 0x7F);           //

  delay(10);
  write_reg(FIFOData, 0x26);       //Write ReqA=26(wake up all the idle card ,not sleeping，0x52) into FIFO
  write_reg(Command, Transceive);        // Start RC663 command "Transcieve"=0x07. Activate Rx after Tx finishes.

  write_reg(IRQ0En, 0x18);         // Wait until the command is finished. Enable IRQ sources.
  write_reg(IRQ1En, 0x42);         //
  while (!(read_reg(IRQ1) & 0x40)); //Wait untill global interrupt set
  write_reg(IRQ0En, 0x00);        //
  write_reg(IRQ1En, 0x00);        //
  uint8_t len = read_reg(FIFOLength); //read FIFO length
  for (int i = 0; i < len; ++i) {
    atqa[i] = read_reg(FIFOData);   // Read FIFO, expecting: the two byte ATQA,we could tell from ATQA how long the UID is ,4、7、10 byte?,then decide wether to go through  the subsquent anti-collision procedure
  }
  return len;
}

int Clrc663::iso_14443A_select(uint8_t *uid)
{
  // Get UID, Apply cascade level-1
  write_reg(TxDataNum, 0x08);       //BIT3 If cleared - it is possible to send a single symbol pattern.If set - data is sent.
  write_reg(RxBitCtrl, 0x00);       //
  write_reg(Command, Idle);           // Terminate any running command.
  write_reg(FIFOControl, 0xB0);       // Flush_FiFo

  write_reg(IRQ0, 0x7F);              // Clear all IRQ 0,1 flags
  write_reg(IRQ1, 0x7F);             //
  write_reg(FIFOData, 0x93);                 //Write "Select" cmd into FIFO (SEL=93, NVB=20,cascade level-1)
  write_reg(FIFOData, 0x20);                 //字节计数=2
  write_reg(Command, Transceive);          //Start tranceive command

  write_reg(IRQ0En, 0x18);           //Enable Irqs 0,1
  write_reg(IRQ1En, 0x42);           //Enable the global IRQ to be propagated to the IRQ pin
  while (!(read_reg(IRQ1) & 0x40));    // Wait until the command is finished
  write_reg(IRQ0En, 0x00);                    //Disable IRQ0 interrupt sources
  write_reg(IRQ0En, 0x00);
  //read_reg(IRQ0);                    // Read IRQ 0,1 Status register
  //read_reg(IRQ1);       //

  uint8_t len = read_reg(FIFOLength);//read FIFO length
  for (int i = 0; i < len; i++) {
    uid[i] = read_reg(FIFOData);  // Read FIFO,Expected - Complete UID (one PICC in HF)
  }

  //now we got UID ,we continue to use this UID to select the card
  //this command needs CRC appended
  write_reg(TxCrcPreset, 0x19);          //preset value is6363,use crc16,crc is apended to the data stream
  write_reg(RxCrcPreset, 0x19);          //

  write_reg(Command, Idle);           // Terminate any running command.
  write_reg(FIFOControl, 0xB0);       // Flush_FiFo

  write_reg(IRQ0, 0x7F);              // Clear all IRQ 0,1 flags
  write_reg(IRQ1, 0x7F);             //
  write_reg(FIFOData, 0x93);          //select
  write_reg(FIFOData, 0x70);          //字节计数=7
  for (int i = 0; i < len; i++) {
    write_reg(FIFOData, uid[i]);  // Read FIFO,Expected - Complete UID (one PICC in HF)
  }
  write_reg(Command, Transceive);          //Start tranceive command ,expecting to receive SAK ,select acknowlegement

  write_reg(IRQ0En, 0x18);           //Enable Irqs 0,1
  write_reg(IRQ1En, 0x42);           //Enable the global IRQ to be propagated to the IRQ pin
  while (!(read_reg(IRQ1) & 0x40));    // Wait until the command is finished
  write_reg(IRQ0En, 0x00);                    //Disable IRQ0 interrupt sources
  write_reg(IRQ0En, 0x00);
  uint8_t sak = read_reg(FIFOData);  // Read FIFO,Expecting SAK,here wo should next level of anti-collision
                                      //if SAK's bit2=1,then UID is not finished yet
  //结束防冲突环.Here we assuming the UID is 4 bytes ,so just finish the anti-collision loop
  return len; //sak & 0x02 ? -1 : 0;
}

int Clrc663::iso_14443A_rats(uint8_t *ats)
{
  write_reg(TxCrcPreset, 0x19);          //preset value is6363,use crc16,crc is apended to the data stream
  write_reg(RxCrcPreset, 0x19);          //
  write_reg(Command, Idle);           // Terminate any running command.
  write_reg(FIFOControl, 0xB0);       // Flush_FiFo
  write_reg(IRQ0, 0x7F);              // Clear all IRQ 0,1 flags
  write_reg(IRQ1, 0x7F);             //
  write_reg(FIFOData, 0xE0);          //RATS,E0为命令，
  write_reg(FIFOData, 0x80);          //5为FSDI(5对应于64,8对应于256)， 1为CID（card ID），为此卡在此次通信中的临时ID
  write_reg(Command, Transceive);          //Start tranceive command ,expecting to receive SAK ,select acknowlegement
  write_reg(IRQ0En, 0x18);           //Enable Irqs 0,1
  write_reg(IRQ1En, 0x42);           //Enable the global IRQ to be propagated to the IRQ pin
  while (!(read_reg(IRQ1) & 0x40));    // Wait until the command is finished
  write_reg(IRQ0En, 0x00);                    //Disable IRQ0 interrupt sources
  write_reg(IRQ0En, 0x00);
  uint8_t len = read_reg(FIFOLength);//read FIFO length
  for (int i = 0; i < len; i++) {
    ats[i] = read_reg(FIFOData);  // Read FIFO,Expecting ATS,after receiving the ATS the PICC enters protocol state,ready to process APDUs
  }
  return len;
}

/* vim: set expandtab ts=2 sw=2: */
