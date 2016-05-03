<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.6.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="15" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="14" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="53" name="tGND_GNDA" color="7" fill="9" visible="no" active="no"/>
<layer number="54" name="bGND_GNDA" color="1" fill="9" visible="no" active="no"/>
<layer number="56" name="wert" color="7" fill="1" visible="no" active="no"/>
<layer number="57" name="tCAD" color="7" fill="1" visible="no" active="no"/>
<layer number="59" name="tCarbon" color="7" fill="1" visible="no" active="no"/>
<layer number="60" name="bCarbon" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="7" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Muster" color="7" fill="1" visible="no" active="no"/>
<layer number="101" name="Patch_Top" color="12" fill="4" visible="yes" active="yes"/>
<layer number="102" name="Vscore" color="7" fill="1" visible="yes" active="yes"/>
<layer number="103" name="tMap" color="7" fill="1" visible="yes" active="yes"/>
<layer number="104" name="Name" color="16" fill="1" visible="yes" active="yes"/>
<layer number="105" name="tPlate" color="7" fill="1" visible="yes" active="yes"/>
<layer number="106" name="bPlate" color="7" fill="1" visible="yes" active="yes"/>
<layer number="107" name="Crop" color="7" fill="1" visible="yes" active="yes"/>
<layer number="108" name="tplace-old" color="10" fill="1" visible="yes" active="yes"/>
<layer number="109" name="ref-old" color="11" fill="1" visible="yes" active="yes"/>
<layer number="110" name="fp0" color="7" fill="1" visible="yes" active="yes"/>
<layer number="111" name="LPC17xx" color="7" fill="1" visible="yes" active="yes"/>
<layer number="112" name="tSilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="113" name="IDFDebug" color="7" fill="1" visible="yes" active="yes"/>
<layer number="114" name="Badge_Outline" color="7" fill="1" visible="yes" active="yes"/>
<layer number="115" name="ReferenceISLANDS" color="7" fill="1" visible="yes" active="yes"/>
<layer number="116" name="Patch_BOT" color="9" fill="4" visible="yes" active="yes"/>
<layer number="118" name="Rect_Pads" color="7" fill="1" visible="yes" active="yes"/>
<layer number="121" name="_tsilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="122" name="_bsilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="123" name="tTestmark" color="7" fill="1" visible="yes" active="yes"/>
<layer number="124" name="bTestmark" color="7" fill="1" visible="yes" active="yes"/>
<layer number="125" name="_tNames" color="7" fill="1" visible="yes" active="yes"/>
<layer number="126" name="_bNames" color="7" fill="1" visible="yes" active="yes"/>
<layer number="127" name="_tValues" color="7" fill="1" visible="yes" active="yes"/>
<layer number="128" name="_bValues" color="7" fill="1" visible="yes" active="yes"/>
<layer number="129" name="Mask" color="7" fill="1" visible="yes" active="yes"/>
<layer number="131" name="tAdjust" color="7" fill="1" visible="yes" active="yes"/>
<layer number="132" name="bAdjust" color="7" fill="1" visible="yes" active="yes"/>
<layer number="144" name="Drill_legend" color="7" fill="1" visible="yes" active="yes"/>
<layer number="150" name="Notes" color="7" fill="1" visible="yes" active="yes"/>
<layer number="151" name="HeatSink" color="7" fill="1" visible="yes" active="yes"/>
<layer number="152" name="_bDocu" color="7" fill="1" visible="yes" active="yes"/>
<layer number="153" name="FabDoc1" color="7" fill="1" visible="yes" active="yes"/>
<layer number="154" name="FabDoc2" color="7" fill="1" visible="yes" active="yes"/>
<layer number="155" name="FabDoc3" color="7" fill="1" visible="yes" active="yes"/>
<layer number="199" name="Contour" color="7" fill="1" visible="yes" active="yes"/>
<layer number="200" name="200bmp" color="1" fill="10" visible="yes" active="yes"/>
<layer number="201" name="201bmp" color="2" fill="10" visible="yes" active="yes"/>
<layer number="202" name="202bmp" color="3" fill="10" visible="yes" active="yes"/>
<layer number="203" name="203bmp" color="4" fill="10" visible="yes" active="yes"/>
<layer number="204" name="204bmp" color="5" fill="10" visible="yes" active="yes"/>
<layer number="205" name="205bmp" color="6" fill="10" visible="yes" active="yes"/>
<layer number="206" name="206bmp" color="7" fill="10" visible="yes" active="yes"/>
<layer number="207" name="207bmp" color="8" fill="10" visible="yes" active="yes"/>
<layer number="208" name="208bmp" color="9" fill="10" visible="yes" active="yes"/>
<layer number="209" name="209bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="210" name="210bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="211" name="211bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="212" name="212bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="213" name="213bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="214" name="214bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="215" name="215bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="216" name="216bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="217" name="217bmp" color="18" fill="1" visible="no" active="no"/>
<layer number="218" name="218bmp" color="19" fill="1" visible="no" active="no"/>
<layer number="219" name="219bmp" color="20" fill="1" visible="no" active="no"/>
<layer number="220" name="220bmp" color="21" fill="1" visible="no" active="no"/>
<layer number="221" name="221bmp" color="22" fill="1" visible="no" active="no"/>
<layer number="222" name="222bmp" color="23" fill="1" visible="no" active="no"/>
<layer number="223" name="223bmp" color="24" fill="1" visible="no" active="no"/>
<layer number="224" name="224bmp" color="25" fill="1" visible="no" active="no"/>
<layer number="225" name="225bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="226" name="226bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="227" name="227bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="228" name="228bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="229" name="229bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="230" name="230bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="231" name="231bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="248" name="Housing" color="7" fill="1" visible="yes" active="yes"/>
<layer number="249" name="Edge" color="7" fill="1" visible="yes" active="yes"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
<layer number="254" name="cooling" color="7" fill="1" visible="yes" active="yes"/>
<layer number="255" name="routoute" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="SparkFun-DigitalIC">
<description>&lt;h3&gt;SparkFun Electronics' preferred foot prints&lt;/h3&gt;
In this library you'll find all manner of digital ICs- microcontrollers, memory chips, logic chips, FPGAs, etc.&lt;br&gt;&lt;br&gt;
We've spent an enormous amount of time creating and checking these footprints and parts, but it is the end user's responsibility to ensure correctness and suitablity for a given componet or application. If you enjoy using this library, please buy one of our products at www.sparkfun.com.
&lt;br&gt;&lt;br&gt;
&lt;b&gt;Licensing:&lt;/b&gt; Creative Commons ShareAlike 4.0 International - https://creativecommons.org/licenses/by-sa/4.0/ 
&lt;br&gt;&lt;br&gt;
You are welcome to use this library for commercial purposes. For attribution, we ask that when you begin to sell your device using our footprint, you email us with a link to the product being sold. We want bragging rights that we helped (in a very small part) to create your 8th world wonder. We would like the opportunity to feature your device on our homepage.</description>
<packages>
<package name="TQFP32-08">
<description>&lt;B&gt;Thin Plasic Quad Flat Package&lt;/B&gt; Grid 0.8 mm</description>
<wire x1="3.505" y1="3.505" x2="3.505" y2="-3.505" width="0.2032" layer="21"/>
<wire x1="3.505" y1="-3.505" x2="-3.505" y2="-3.505" width="0.2032" layer="21"/>
<wire x1="-3.505" y1="-3.505" x2="-3.505" y2="3.15" width="0.2032" layer="21"/>
<wire x1="-3.15" y1="3.505" x2="3.505" y2="3.505" width="0.2032" layer="21"/>
<wire x1="-3.15" y1="3.505" x2="-3.505" y2="3.15" width="0.2032" layer="21"/>
<circle x="-3.6576" y="3.683" radius="0.1524" width="0.2032" layer="21"/>
<smd name="1" x="-4.2926" y="2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="2" x="-4.2926" y="2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="3" x="-4.2926" y="1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="4" x="-4.2926" y="0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="5" x="-4.2926" y="-0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="6" x="-4.2926" y="-1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="7" x="-4.2926" y="-2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="8" x="-4.2926" y="-2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="9" x="-2.8" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="10" x="-2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="11" x="-1.2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="12" x="-0.4" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="13" x="0.4" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="14" x="1.2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="15" x="2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="16" x="2.8" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="17" x="4.2926" y="-2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="18" x="4.2926" y="-2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="19" x="4.2926" y="-1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="20" x="4.2926" y="-0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="21" x="4.2926" y="0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="22" x="4.2926" y="1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="23" x="4.2926" y="2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="24" x="4.2926" y="2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="25" x="2.8" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="26" x="2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="27" x="1.2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="28" x="0.4" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="29" x="-0.4" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="30" x="-1.2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="31" x="-2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="32" x="-2.8" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<text x="-3.175" y="5.08" size="0.4064" layer="25">&gt;NAME</text>
<text x="-2.54" y="-6.35" size="0.4064" layer="27">&gt;VALUE</text>
<rectangle x1="-4.5466" y1="2.5714" x2="-3.556" y2="3.0286" layer="51"/>
<rectangle x1="-4.5466" y1="1.7714" x2="-3.556" y2="2.2286" layer="51"/>
<rectangle x1="-4.5466" y1="0.9714" x2="-3.556" y2="1.4286" layer="51"/>
<rectangle x1="-4.5466" y1="0.1714" x2="-3.556" y2="0.6286" layer="51"/>
<rectangle x1="-4.5466" y1="-0.6286" x2="-3.556" y2="-0.1714" layer="51"/>
<rectangle x1="-4.5466" y1="-1.4286" x2="-3.556" y2="-0.9714" layer="51"/>
<rectangle x1="-4.5466" y1="-2.2286" x2="-3.556" y2="-1.7714" layer="51"/>
<rectangle x1="-4.5466" y1="-3.0286" x2="-3.556" y2="-2.5714" layer="51"/>
<rectangle x1="-3.0286" y1="-4.5466" x2="-2.5714" y2="-3.556" layer="51"/>
<rectangle x1="-2.2286" y1="-4.5466" x2="-1.7714" y2="-3.556" layer="51"/>
<rectangle x1="-1.4286" y1="-4.5466" x2="-0.9714" y2="-3.556" layer="51"/>
<rectangle x1="-0.6286" y1="-4.5466" x2="-0.1714" y2="-3.556" layer="51"/>
<rectangle x1="0.1714" y1="-4.5466" x2="0.6286" y2="-3.556" layer="51"/>
<rectangle x1="0.9714" y1="-4.5466" x2="1.4286" y2="-3.556" layer="51"/>
<rectangle x1="1.7714" y1="-4.5466" x2="2.2286" y2="-3.556" layer="51"/>
<rectangle x1="2.5714" y1="-4.5466" x2="3.0286" y2="-3.556" layer="51"/>
<rectangle x1="3.556" y1="-3.0286" x2="4.5466" y2="-2.5714" layer="51"/>
<rectangle x1="3.556" y1="-2.2286" x2="4.5466" y2="-1.7714" layer="51"/>
<rectangle x1="3.556" y1="-1.4286" x2="4.5466" y2="-0.9714" layer="51"/>
<rectangle x1="3.556" y1="-0.6286" x2="4.5466" y2="-0.1714" layer="51"/>
<rectangle x1="3.556" y1="0.1714" x2="4.5466" y2="0.6286" layer="51"/>
<rectangle x1="3.556" y1="0.9714" x2="4.5466" y2="1.4286" layer="51"/>
<rectangle x1="3.556" y1="1.7714" x2="4.5466" y2="2.2286" layer="51"/>
<rectangle x1="3.556" y1="2.5714" x2="4.5466" y2="3.0286" layer="51"/>
<rectangle x1="2.5714" y1="3.556" x2="3.0286" y2="4.5466" layer="51"/>
<rectangle x1="1.7714" y1="3.556" x2="2.2286" y2="4.5466" layer="51"/>
<rectangle x1="0.9714" y1="3.556" x2="1.4286" y2="4.5466" layer="51"/>
<rectangle x1="0.1714" y1="3.556" x2="0.6286" y2="4.5466" layer="51"/>
<rectangle x1="-0.6286" y1="3.556" x2="-0.1714" y2="4.5466" layer="51"/>
<rectangle x1="-1.4286" y1="3.556" x2="-0.9714" y2="4.5466" layer="51"/>
<rectangle x1="-2.2286" y1="3.556" x2="-1.7714" y2="4.5466" layer="51"/>
<rectangle x1="-3.0286" y1="3.556" x2="-2.5714" y2="4.5466" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="ATMEGAXX8-32PIN_NOPAD">
<wire x1="-20.32" y1="33.02" x2="17.78" y2="33.02" width="0.254" layer="94"/>
<wire x1="17.78" y1="33.02" x2="17.78" y2="-30.48" width="0.254" layer="94"/>
<wire x1="17.78" y1="-30.48" x2="-20.32" y2="-30.48" width="0.254" layer="94"/>
<wire x1="-20.32" y1="-30.48" x2="-20.32" y2="33.02" width="0.254" layer="94"/>
<text x="-20.32" y="33.782" size="1.778" layer="95">&gt;NAME</text>
<text x="-20.32" y="-33.02" size="1.778" layer="96">&gt;VALUE</text>
<pin name="PB5(SCK)" x="22.86" y="-27.94" length="middle" rot="R180"/>
<pin name="PB7(XTAL2/TOSC2)" x="-25.4" y="0" length="middle"/>
<pin name="PB6(XTAL1/TOSC1)" x="-25.4" y="5.08" length="middle"/>
<pin name="GND@3" x="-25.4" y="-22.86" length="middle"/>
<pin name="GND@5" x="-25.4" y="-25.4" length="middle"/>
<pin name="VCC@4" x="-25.4" y="22.86" length="middle"/>
<pin name="VCC@6" x="-25.4" y="20.32" length="middle"/>
<pin name="AGND" x="-25.4" y="-20.32" length="middle"/>
<pin name="AREF" x="-25.4" y="15.24" length="middle"/>
<pin name="AVCC" x="-25.4" y="25.4" length="middle"/>
<pin name="PB4(MISO)" x="22.86" y="-25.4" length="middle" rot="R180"/>
<pin name="PB3(MOSI/OC2)" x="22.86" y="-22.86" length="middle" rot="R180"/>
<pin name="PB2(SS/OC1B)" x="22.86" y="-20.32" length="middle" rot="R180"/>
<pin name="PB1(OC1A)" x="22.86" y="-17.78" length="middle" rot="R180"/>
<pin name="PB0(ICP)" x="22.86" y="-15.24" length="middle" rot="R180"/>
<pin name="PD7(AIN1)" x="22.86" y="-10.16" length="middle" rot="R180"/>
<pin name="PD6(AIN0)" x="22.86" y="-7.62" length="middle" rot="R180"/>
<pin name="PD5(T1)" x="22.86" y="-5.08" length="middle" rot="R180"/>
<pin name="PD4(XCK/T0)" x="22.86" y="-2.54" length="middle" rot="R180"/>
<pin name="PD3(INT1)" x="22.86" y="0" length="middle" rot="R180"/>
<pin name="PD2(INT0)" x="22.86" y="2.54" length="middle" rot="R180"/>
<pin name="PD1(TXD)" x="22.86" y="5.08" length="middle" rot="R180"/>
<pin name="PD0(RXD)" x="22.86" y="7.62" length="middle" rot="R180"/>
<pin name="ADC7" x="22.86" y="12.7" length="middle" rot="R180"/>
<pin name="ADC6" x="22.86" y="15.24" length="middle" rot="R180"/>
<pin name="PC5(ADC5/SCL)" x="22.86" y="17.78" length="middle" rot="R180"/>
<pin name="PC4(ADC4/SDA)" x="22.86" y="20.32" length="middle" rot="R180"/>
<pin name="PC3(ADC3)" x="22.86" y="22.86" length="middle" rot="R180"/>
<pin name="PC2(ADC2)" x="22.86" y="25.4" length="middle" rot="R180"/>
<pin name="PC1(ADC1)" x="22.86" y="27.94" length="middle" rot="R180"/>
<pin name="PC0(ADC0)" x="22.86" y="30.48" length="middle" rot="R180"/>
<pin name="PC6(/RESET)" x="-25.4" y="30.48" length="middle" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ATMEGA328P_TQFP" prefix="U">
<gates>
<gate name="U$1" symbol="ATMEGAXX8-32PIN_NOPAD" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TQFP32-08">
<connects>
<connect gate="U$1" pin="ADC6" pad="19"/>
<connect gate="U$1" pin="ADC7" pad="22"/>
<connect gate="U$1" pin="AGND" pad="21"/>
<connect gate="U$1" pin="AREF" pad="20"/>
<connect gate="U$1" pin="AVCC" pad="18"/>
<connect gate="U$1" pin="GND@3" pad="3"/>
<connect gate="U$1" pin="GND@5" pad="5"/>
<connect gate="U$1" pin="PB0(ICP)" pad="12"/>
<connect gate="U$1" pin="PB1(OC1A)" pad="13"/>
<connect gate="U$1" pin="PB2(SS/OC1B)" pad="14"/>
<connect gate="U$1" pin="PB3(MOSI/OC2)" pad="15"/>
<connect gate="U$1" pin="PB4(MISO)" pad="16"/>
<connect gate="U$1" pin="PB5(SCK)" pad="17"/>
<connect gate="U$1" pin="PB6(XTAL1/TOSC1)" pad="7"/>
<connect gate="U$1" pin="PB7(XTAL2/TOSC2)" pad="8"/>
<connect gate="U$1" pin="PC0(ADC0)" pad="23"/>
<connect gate="U$1" pin="PC1(ADC1)" pad="24"/>
<connect gate="U$1" pin="PC2(ADC2)" pad="25"/>
<connect gate="U$1" pin="PC3(ADC3)" pad="26"/>
<connect gate="U$1" pin="PC4(ADC4/SDA)" pad="27"/>
<connect gate="U$1" pin="PC5(ADC5/SCL)" pad="28"/>
<connect gate="U$1" pin="PC6(/RESET)" pad="29"/>
<connect gate="U$1" pin="PD0(RXD)" pad="30"/>
<connect gate="U$1" pin="PD1(TXD)" pad="31"/>
<connect gate="U$1" pin="PD2(INT0)" pad="32"/>
<connect gate="U$1" pin="PD3(INT1)" pad="1"/>
<connect gate="U$1" pin="PD4(XCK/T0)" pad="2"/>
<connect gate="U$1" pin="PD5(T1)" pad="9"/>
<connect gate="U$1" pin="PD6(AIN0)" pad="10"/>
<connect gate="U$1" pin="PD7(AIN1)" pad="11"/>
<connect gate="U$1" pin="VCC@4" pad="4"/>
<connect gate="U$1" pin="VCC@6" pad="6"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="IC-09069" constant="no"/>
<attribute name="VALUE" value="ATMEGA328P_TQFP" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="CLRC633">
<packages>
<package name="QFN32">
<description>32-pin QFN package</description>
<wire x1="-2.5" y1="2.5" x2="-2.5" y2="-2.5" width="0.127" layer="51"/>
<wire x1="-2.5" y1="-2.5" x2="2.5" y2="-2.5" width="0.127" layer="51"/>
<wire x1="2.5" y1="-2.5" x2="2.5" y2="2.5" width="0.127" layer="51"/>
<wire x1="2.5" y1="2.5" x2="-2.5" y2="2.5" width="0.127" layer="51"/>
<wire x1="2.1" y1="2.627" x2="2.627" y2="2.627" width="0.2032" layer="21"/>
<wire x1="2.627" y1="2.627" x2="2.627" y2="2.1" width="0.2032" layer="21"/>
<wire x1="2.627" y1="-2.1" x2="2.627" y2="-2.627" width="0.2032" layer="21"/>
<wire x1="2.627" y1="-2.627" x2="2.1" y2="-2.627" width="0.2032" layer="21"/>
<wire x1="-2.1" y1="-2.627" x2="-2.627" y2="-2.627" width="0.2032" layer="21"/>
<wire x1="-2.627" y1="-2.627" x2="-2.627" y2="-2.1" width="0.2032" layer="21"/>
<wire x1="-2.1" y1="2.754" x2="-2.754" y2="2.1" width="0.2032" layer="21"/>
<smd name="1" x="-2.5" y="1.75" dx="0.8" dy="0.2846" layer="1"/>
<smd name="2" x="-2.5" y="1.25" dx="0.8" dy="0.2846" layer="1"/>
<smd name="3" x="-2.5" y="0.75" dx="0.8" dy="0.2846" layer="1"/>
<smd name="4" x="-2.5" y="0.25" dx="0.8" dy="0.2846" layer="1"/>
<smd name="5" x="-2.5" y="-0.25" dx="0.8" dy="0.2846" layer="1"/>
<smd name="6" x="-2.5" y="-0.75" dx="0.8" dy="0.2846" layer="1"/>
<smd name="7" x="-2.5" y="-1.25" dx="0.8" dy="0.2846" layer="1"/>
<smd name="8" x="-2.5" y="-1.75" dx="0.8" dy="0.2846" layer="1"/>
<smd name="9" x="-1.75" y="-2.5" dx="0.8" dy="0.2846" layer="1" rot="R90"/>
<smd name="10" x="-1.25" y="-2.5" dx="0.8" dy="0.2846" layer="1" rot="R90"/>
<smd name="11" x="-0.75" y="-2.5" dx="0.8" dy="0.2846" layer="1" rot="R90"/>
<smd name="12" x="-0.25" y="-2.5" dx="0.8" dy="0.2846" layer="1" rot="R90"/>
<smd name="13" x="0.25" y="-2.5" dx="0.8" dy="0.2846" layer="1" rot="R90"/>
<smd name="14" x="0.75" y="-2.5" dx="0.8" dy="0.2846" layer="1" rot="R90"/>
<smd name="15" x="1.25" y="-2.5" dx="0.8" dy="0.2846" layer="1" rot="R90"/>
<smd name="16" x="1.75" y="-2.5" dx="0.8" dy="0.2846" layer="1" rot="R90"/>
<smd name="17" x="2.5" y="-1.75" dx="0.8" dy="0.2846" layer="1" rot="R180"/>
<smd name="18" x="2.5" y="-1.25" dx="0.8" dy="0.2846" layer="1" rot="R180"/>
<smd name="19" x="2.5" y="-0.75" dx="0.8" dy="0.2846" layer="1" rot="R180"/>
<smd name="20" x="2.5" y="-0.25" dx="0.8" dy="0.2846" layer="1" rot="R180"/>
<smd name="21" x="2.5" y="0.25" dx="0.8" dy="0.2846" layer="1" rot="R180"/>
<smd name="22" x="2.5" y="0.75" dx="0.8" dy="0.2846" layer="1" rot="R180"/>
<smd name="23" x="2.5" y="1.25" dx="0.8" dy="0.2846" layer="1" rot="R180"/>
<smd name="24" x="2.5" y="1.75" dx="0.8" dy="0.2846" layer="1" rot="R180"/>
<smd name="25" x="1.75" y="2.5" dx="0.8" dy="0.2846" layer="1" rot="R270"/>
<smd name="26" x="1.25" y="2.5" dx="0.8" dy="0.2846" layer="1" rot="R270"/>
<smd name="27" x="0.75" y="2.5" dx="0.8" dy="0.2846" layer="1" rot="R270"/>
<smd name="28" x="0.25" y="2.5" dx="0.8" dy="0.2846" layer="1" rot="R270"/>
<smd name="29" x="-0.25" y="2.5" dx="0.8" dy="0.2846" layer="1" rot="R270"/>
<smd name="30" x="-0.75" y="2.5" dx="0.8" dy="0.2846" layer="1" rot="R270"/>
<smd name="31" x="-1.25" y="2.5" dx="0.8" dy="0.2846" layer="1" rot="R270"/>
<smd name="32" x="-1.75" y="2.5" dx="0.8" dy="0.2846" layer="1" rot="R270"/>
<smd name="EP" x="0" y="0" dx="3.15" dy="3.15" layer="1" cream="no"/>
<text x="-2.5" y="3.1" size="0.4318" layer="25">&gt;Name</text>
<text x="-2.5" y="-3.1" size="0.4318" layer="27" align="top-left">&gt;Value</text>
<rectangle x1="0.05" y1="2.18" x2="0.45" y2="2.42" layer="51" rot="R270"/>
<rectangle x1="-0.45" y1="2.18" x2="-0.05" y2="2.42" layer="51" rot="R270"/>
<rectangle x1="-0.95" y1="2.18" x2="-0.55" y2="2.42" layer="51" rot="R270"/>
<rectangle x1="-1.45" y1="2.18" x2="-1.05" y2="2.42" layer="51" rot="R270"/>
<rectangle x1="-1.95" y1="2.18" x2="-1.55" y2="2.42" layer="51" rot="R270"/>
<rectangle x1="0.55" y1="2.18" x2="0.95" y2="2.42" layer="51" rot="R270"/>
<rectangle x1="1.05" y1="2.18" x2="1.45" y2="2.42" layer="51" rot="R270"/>
<rectangle x1="1.55" y1="2.18" x2="1.95" y2="2.42" layer="51" rot="R270"/>
<rectangle x1="2.1" y1="-0.37" x2="2.5" y2="-0.13" layer="51" rot="R180"/>
<rectangle x1="2.1" y1="0.13" x2="2.5" y2="0.37" layer="51" rot="R180"/>
<rectangle x1="2.1" y1="0.63" x2="2.5" y2="0.87" layer="51" rot="R180"/>
<rectangle x1="2.1" y1="1.13" x2="2.5" y2="1.37" layer="51" rot="R180"/>
<rectangle x1="2.1" y1="1.63" x2="2.5" y2="1.87" layer="51" rot="R180"/>
<rectangle x1="2.1" y1="-0.87" x2="2.5" y2="-0.63" layer="51" rot="R180"/>
<rectangle x1="2.1" y1="-1.37" x2="2.5" y2="-1.13" layer="51" rot="R180"/>
<rectangle x1="2.1" y1="-1.87" x2="2.5" y2="-1.63" layer="51" rot="R180"/>
<rectangle x1="-2.5" y1="0.13" x2="-2.1" y2="0.37" layer="51"/>
<rectangle x1="-2.5" y1="-0.37" x2="-2.1" y2="-0.13" layer="51"/>
<rectangle x1="-2.5" y1="-0.87" x2="-2.1" y2="-0.63" layer="51"/>
<rectangle x1="-2.5" y1="-1.37" x2="-2.1" y2="-1.13" layer="51"/>
<rectangle x1="-2.5" y1="-1.87" x2="-2.1" y2="-1.63" layer="51"/>
<rectangle x1="-2.5" y1="0.63" x2="-2.1" y2="0.87" layer="51"/>
<rectangle x1="-2.5" y1="1.13" x2="-2.1" y2="1.37" layer="51"/>
<rectangle x1="-2.5" y1="1.63" x2="-2.1" y2="1.87" layer="51"/>
<rectangle x1="-0.45" y1="-2.42" x2="-0.05" y2="-2.18" layer="51" rot="R90"/>
<rectangle x1="0.05" y1="-2.42" x2="0.45" y2="-2.18" layer="51" rot="R90"/>
<rectangle x1="0.55" y1="-2.42" x2="0.95" y2="-2.18" layer="51" rot="R90"/>
<rectangle x1="1.05" y1="-2.42" x2="1.45" y2="-2.18" layer="51" rot="R90"/>
<rectangle x1="1.55" y1="-2.42" x2="1.95" y2="-2.18" layer="51" rot="R90"/>
<rectangle x1="-0.95" y1="-2.42" x2="-0.55" y2="-2.18" layer="51" rot="R90"/>
<rectangle x1="-1.45" y1="-2.42" x2="-1.05" y2="-2.18" layer="51" rot="R90"/>
<rectangle x1="-1.95" y1="-2.42" x2="-1.55" y2="-2.18" layer="51" rot="R90"/>
<rectangle x1="-1.45" y1="0.15" x2="-0.15" y2="1.45" layer="31"/>
<rectangle x1="0.15" y1="0.15" x2="1.45" y2="1.45" layer="31" rot="R270"/>
<rectangle x1="-1.45" y1="-1.45" x2="-0.15" y2="-0.15" layer="31" rot="R90"/>
<rectangle x1="0.15" y1="-1.45" x2="1.45" y2="-0.15" layer="31" rot="R180"/>
<circle x="-2.7" y="2.7" radius="0.2032" width="0" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="CLRC663">
<wire x1="-20.32" y1="38.1" x2="20.32" y2="38.1" width="0.254" layer="94"/>
<wire x1="20.32" y1="38.1" x2="20.32" y2="-38.1" width="0.254" layer="94"/>
<wire x1="20.32" y1="-38.1" x2="-20.32" y2="-38.1" width="0.254" layer="94"/>
<wire x1="-20.32" y1="-38.1" x2="-20.32" y2="38.1" width="0.254" layer="94"/>
<pin name="TDO" x="-25.4" y="35.56" length="middle"/>
<pin name="TDI" x="-25.4" y="33.02" length="middle"/>
<pin name="TMS" x="-25.4" y="30.48" length="middle"/>
<pin name="TCK" x="-25.4" y="27.94" length="middle"/>
<pin name="GPIO0/SIGIN" x="-25.4" y="25.4" length="middle"/>
<pin name="SIGOUT" x="-25.4" y="22.86" length="middle"/>
<pin name="DVDD" x="-25.4" y="-35.56" length="middle"/>
<pin name="VDD" x="-25.4" y="-27.94" length="middle"/>
<pin name="AVDD" x="-25.4" y="-33.02" length="middle"/>
<pin name="AUX1" x="-25.4" y="20.32" length="middle"/>
<pin name="AUX2" x="-25.4" y="17.78" length="middle"/>
<pin name="RXP" x="25.4" y="22.86" length="middle" rot="R180"/>
<pin name="RXN" x="25.4" y="-20.32" length="middle" rot="R180"/>
<pin name="VMID" x="25.4" y="30.48" length="middle" rot="R180"/>
<pin name="TX2" x="25.4" y="-7.62" length="middle" rot="R180"/>
<pin name="TVSS" x="25.4" y="2.54" length="middle" rot="R180"/>
<pin name="TX1" x="25.4" y="12.7" length="middle" rot="R180"/>
<pin name="TVDD" x="25.4" y="35.56" length="middle" rot="R180"/>
<pin name="XTAL1" x="25.4" y="-25.4" length="middle" rot="R180"/>
<pin name="XTAL2" x="25.4" y="-35.56" length="middle" rot="R180"/>
<pin name="N_PDOWN" x="-25.4" y="-17.78" length="middle"/>
<pin name="CLKOUT" x="-25.4" y="-20.32" length="middle"/>
<pin name="SCL2" x="-25.4" y="-10.16" length="middle"/>
<pin name="SDA2" x="-25.4" y="-12.7" length="middle"/>
<pin name="PVDD" x="-25.4" y="-25.4" length="middle"/>
<pin name="IFSEL0" x="-25.4" y="12.7" length="middle"/>
<pin name="IFSEL1" x="-25.4" y="10.16" length="middle"/>
<pin name="IF0" x="-25.4" y="7.62" length="middle"/>
<pin name="IF1/SCL" x="-25.4" y="5.08" length="middle"/>
<pin name="IF2" x="-25.4" y="2.54" length="middle"/>
<pin name="IF3/SDA" x="-25.4" y="0" length="middle"/>
<pin name="IRQ" x="-25.4" y="-2.54" length="middle"/>
<text x="-5.08" y="40.64" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.08" y="-40.64" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="CLRC663">
<gates>
<gate name="G$1" symbol="CLRC663" x="0" y="0"/>
</gates>
<devices>
<device name="" package="QFN32">
<connects>
<connect gate="G$1" pin="AUX1" pad="10"/>
<connect gate="G$1" pin="AUX2" pad="11"/>
<connect gate="G$1" pin="AVDD" pad="9"/>
<connect gate="G$1" pin="CLKOUT" pad="22"/>
<connect gate="G$1" pin="DVDD" pad="7"/>
<connect gate="G$1" pin="GPIO0/SIGIN" pad="5"/>
<connect gate="G$1" pin="IF0" pad="28"/>
<connect gate="G$1" pin="IF1/SCL" pad="29"/>
<connect gate="G$1" pin="IF2" pad="30"/>
<connect gate="G$1" pin="IF3/SDA" pad="31"/>
<connect gate="G$1" pin="IFSEL0" pad="26"/>
<connect gate="G$1" pin="IFSEL1" pad="27"/>
<connect gate="G$1" pin="IRQ" pad="32"/>
<connect gate="G$1" pin="N_PDOWN" pad="21"/>
<connect gate="G$1" pin="PVDD" pad="25"/>
<connect gate="G$1" pin="RXN" pad="13"/>
<connect gate="G$1" pin="RXP" pad="12"/>
<connect gate="G$1" pin="SCL2" pad="23"/>
<connect gate="G$1" pin="SDA2" pad="24"/>
<connect gate="G$1" pin="SIGOUT" pad="6"/>
<connect gate="G$1" pin="TCK" pad="4"/>
<connect gate="G$1" pin="TDI" pad="2"/>
<connect gate="G$1" pin="TDO" pad="1"/>
<connect gate="G$1" pin="TMS" pad="3"/>
<connect gate="G$1" pin="TVDD" pad="18"/>
<connect gate="G$1" pin="TVSS" pad="16"/>
<connect gate="G$1" pin="TX1" pad="17"/>
<connect gate="G$1" pin="TX2" pad="15"/>
<connect gate="G$1" pin="VDD" pad="8"/>
<connect gate="G$1" pin="VMID" pad="14"/>
<connect gate="G$1" pin="XTAL1" pad="19"/>
<connect gate="G$1" pin="XTAL2" pad="20"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U1" library="SparkFun-DigitalIC" deviceset="ATMEGA328P_TQFP" device="" value="ATMEGA328P_TQFP"/>
<part name="U2" library="CLRC633" deviceset="CLRC663" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U1" gate="U$1" x="0" y="0"/>
<instance part="U2" gate="G$1" x="93.98" y="-2.54"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
