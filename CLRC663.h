#ifndef _CLRC663_H_
#define _CLRC663_H_

#include <inttypes.h>

enum Reg : uint8_t {
  Command = 0x00, // Starts and stops command execution
  HostCtrl = 0x01, // Host control register
  FIFOControl = 0x02, // Control register of the FIFO
  WaterLevel = 0x03, // Level of the FIFO underflow and overflow warning
  FIFOLength = 0x04, // Length of the FIFO
  FIFOData = 0x05, // Data In/Out exchange register of FIFO buffer
  IRQ0 = 0x06, // Interrupt register 0
  IRQ1 = 0x07, // Interrupt register 1
  IRQ0En = 0x08, // Interrupt enable register 0
  IRQ1En = 0x09, // Interrupt enable register 1
  Error = 0x0A, // Error bits showing the error status of the last command execution
  Status = 0x0B, // Contains status of the communication
  RxBitCtrl = 0x0C, // Control register for anticollision adjustments for bit oriented protocols
  RxColl = 0x0D, // Collision position register
  TControl = 0x0E, // Control of Timer 0..3
  T0Control = 0x0F, // Control of Timer0
  T0ReloadHi = 0x10, // High register of the reload value of Timer0
  T0ReloadLo = 0x11, // Low register of the reload value of Timer0
  T0CounterValHi = 0x12, // Counter value high register of Timer0
  T0CounterValLo = 0x13, // Counter value low register of Timer0
  T1Control = 0x14, // Control of Timer1
  T1ReloadHi = 0x15, // High register of the reload value of Timer1
  T1ReloadLo = 0x16, // Low register of the reload value of Timer1
  T1CounterValHi = 0x17, // Counter value high register of Timer1
  T1CounterValLo = 0x18, // Counter value low register of Timer1
  T2Control = 0x19, // Control of Timer2
  T2ReloadHi = 0x1A, // High byte of the reload value of Timer2
  T2ReloadLo = 0x1B, // Low byte of the reload value of Timer2
  T2CounterValHi = 0x1C, // Counter value high byte of Timer2
  T2CounterValLo = 0x1D, // Counter value low byte of Timer2
  T3Control = 0x1E, // Control of Timer3
  T3ReloadHi = 0x1F, // High byte of the reload value of Timer3
  T3ReloadLo = 0x20, // Low byte of the reload value of Timer3
  T3CounterValHi = 0x21, // Counter value high byte of Timer3
  T3CounterValLo = 0x22, // Counter value low byte of Timer3
  T4Control = 0x23, // Control of Timer4
  T4ReloadHi = 0x24, // High byte of the reload value of Timer4
  T4ReloadLo = 0x25, // Low byte of the reload value of Timer4
  T4CounterValHi = 0x26, // Counter value high byte of Timer4
  T4CounterValLo = 0x27, // Counter value low byte of Timer4
  DrvMod = 0x28, // Driver mode register
  TxAmp = 0x29, // Transmitter amplifier register
  DrvCon = 0x2A, // Driver configuration register
  Txl = 0x2B, // Transmitter register
  TxCrcPreset = 0x2C, // Transmitter CRC control register, preset value
  RxCrcPreset = 0x2D, // Receiver CRC control register, preset value
  TxDataNum = 0x2E, // Transmitter data number register
  TxModWidth = 0x2F, // Transmitter modulation width register
  TxSym10BurstLen = 0x30, // Transmitter symbol 1 + symbol 0 burst length register
  TXWaitCtrl = 0x31, // Transmitter wait control
  TxWaitLo = 0x32, // Transmitter wait low
  FrameCon = 0x33, // Transmitter frame control
  RxSofD = 0x34, // Receiver start of frame detection
  RxCtrl = 0x35, // Receiver control register
  RxWait = 0x36, // Receiver wait register
  RxThreshold = 0x37, // Receiver threshold register
  Rcv = 0x38, // Receiver register
  RxAna = 0x39, // Receiver analog register
  SerialSpeed = 0x3B, // Serial speed register
  LFO_Trimm = 0x3C, // Low-power oscillator trimming register
  PLL_Ctrl = 0x3D, // IntegerN PLL control register, for microcontroller clock output adjustment
  PLL_DivOut = 0x3E, // IntegerN PLL control register, for microcontroller clock output adjustment
  LPCD_QMin = 0x3F, // Low-power card detection Q channel minimum threshold
  LPCD_QMax = 0x40, // Low-power card detection Q channel maximum threshold
  LPCD_IMin = 0x41, // Low-power card detection I channel minimum threshold
  LPCD_I_Result = 0x42, // Low-power card detection I channel result register
  LPCD_Q_Result = 0x43, // Low-power card detection Q channel result register
  PadEn = 0x44, // PIN enable register
  PadOut = 0x45, // PIN out register
  PadIn = 0x46, // PIN in register
  SigOut = 0x47, // Enables and controls the SIGOUT Pin
  TxBitMod = 0x48, // Transmitter bit mode register
  TxDataCon = 0x4A, // Transmitter data configuration register
  TxDataMod = 0x4B, // Transmitter data modulation register
  TxSymFreq = 0x4C, // Transmitter symbol frequency
  TxSym0H = 0x4D, // Transmitter symbol 0 high register
  TxSym0L = 0x4E, // Transmitter symbol 0 low register
  TxSym1H = 0x4F, // Transmitter symbol 1 high register
  TxSym1L = 0x50, // Transmitter symbol 1 low register
  TxSym2 = 0x51, // Transmitter symbol 2 register
  TxSym3 = 0x52, // Transmitter symbol 3 register
  TxSym10Len = 0x53, // Transmitter symbol 1 + symbol 0 length register
  TxSym32Len = 0x54, // Transmitter symbol 3 + symbol 2 length register
  TxSym10BurstCtrl = 0x55, // Transmitter symbol 1 + symbol 0 burst control register
  TxSym10Mod = 0x56, // Transmitter symbol 1 + symbol 0 modulation register
  TxSym32Mod = 0x57, // Transmitter symbol 3 + symbol 2 modulation register
  RxBitMod = 0x58, // Receiver bit modulation register
  RxEofSym = 0x59, // Receiver end of frame symbol register
  RxSyncValH = 0x5A, // Receiver synchronisation value high register
  RxSyncValL = 0x5B, // Receiver synchronisation value low register
  RxSyncMod = 0x5C, // Receiver synchronisation mode register
  RxMod = 0x5D, // Receiver modulation register
  RxCorr = 0x5E, // Receiver correlation register
  FabCal = 0x5F, // Calibration register of the receiver, calibration performed at production
  Version = 0x7F, // Version and subversion register
};

enum Command : uint8_t {
  Idle = 0x00, // no action, cancels current command execution
  LPCD = 0x01, // low-power card detection
  LoadKey = 0x02, // reads a MIFARE key (size of 6 bytes) from FIFO buffer ant puts it into Key buffer
  MFAuthent = 0x03, // performs the MIFARE standard authentication
  AckReq = 0x04, // performs a query, an Ack and a Req-Rn for ISO/IEC 18000-3 mode 3/ EPC Class-1 HF
  Receive = 0x05, // activates the receive circuit
  Transmit = 0x06, // transmits data from the FIFO buffer
  Transceive = 0x07, // transmits data from the FIFO buffer and automatically activates the receiver after transmission finished
  WriteE2 = 0x08, // gets one byte from FIFO buffer and writes it to the internal EEPROM
  WriteE2Page = 0x09, // gets up to 64 bytes (one EEPROM page) from the FIFO buffer and writes it to the EEPROM
  ReadE2 = 0x0A, // reads data from the EEPROM and copies it into the FIFO buffer
  LoadReg = 0x0C, // reads data from the internal EEPROM and initializes the CLRC663 registers. EEPROM address needs to be within EEPROM sector 2
  LoadProtocol = 0x0D, // reads data from the internal EEPROM and initializes the CLRC663 registers needed for a Protocol change
  LoadKeyE2 = 0x0E, // copies a key from the EEPROM into the key buffer
};

class Clrc663 {
  private:
    uint8_t addr;
  public:
    Clrc663(uint8_t address = 0x2A);
    uint8_t read_reg(Reg reg);
    void write_reg(Reg reg, uint8_t val);
    void iso_14443A_init();
    void transmit_enable(bool enable);
    int iso_14443A_reqa(uint8_t *atqa);
};

#endif

/* vim: set expandtab ts=2 sw=2: */
