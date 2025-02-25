<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
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
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
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
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="MODULAR">
<packages>
<package name="ESP32WROOM">
<wire x1="7.73" y1="-11.315" x2="7.73" y2="-5.275" width="0.127" layer="21"/>
<wire x1="7.73" y1="-5.275" x2="7.73" y2="-4.496" width="0.127" layer="21"/>
<wire x1="-10.287" y1="-4.496" x2="-10.287" y2="-11.303" width="0.127" layer="21"/>
<wire x1="7.73" y1="-5.275" x2="-6.535" y2="-5.275" width="0.127" layer="21"/>
<wire x1="-6.535" y1="-5.275" x2="-8.567" y2="-5.275" width="0.127" layer="21"/>
<wire x1="-8.567" y1="-5.275" x2="-10.27" y2="-5.275" width="0.127" layer="21"/>
<wire x1="-10.27" y1="-11.315" x2="7.73" y2="-11.315" width="0.127" layer="21"/>
<wire x1="-3.683" y1="-8.001" x2="-1.143" y2="-8.001" width="0.127" layer="21"/>
<wire x1="-1.143" y1="-10.16" x2="1.397" y2="-10.16" width="0.127" layer="21"/>
<wire x1="1.397" y1="-8.001" x2="3.683" y2="-8.001" width="0.127" layer="21"/>
<wire x1="3.683" y1="-10.16" x2="5.969" y2="-10.16" width="0.127" layer="21"/>
<wire x1="-6.535" y1="-10.16" x2="-3.683" y2="-10.16" width="0.127" layer="21"/>
<wire x1="-8.567" y1="-10.16" x2="-6.535" y2="-10.16" width="0.127" layer="21"/>
<wire x1="5.969" y1="-10.16" x2="5.969" y2="-6.477" width="0.127" layer="21"/>
<wire x1="3.683" y1="-8.001" x2="3.683" y2="-10.16" width="0.127" layer="21"/>
<wire x1="1.397" y1="-10.16" x2="1.397" y2="-8.001" width="0.127" layer="21"/>
<wire x1="-1.143" y1="-8.001" x2="-1.143" y2="-10.16" width="0.127" layer="21"/>
<wire x1="-3.683" y1="-10.16" x2="-3.683" y2="-8.001" width="0.127" layer="21"/>
<wire x1="-6.535" y1="-5.275" x2="-6.535" y2="-10.16" width="0.127" layer="21"/>
<wire x1="-8.567" y1="-5.275" x2="-8.567" y2="-10.16" width="0.127" layer="21"/>
<text x="5.08" y="-2.54" size="1.27" layer="21" rot="R180">ESP32WROOM</text>
<pad name="D18" x="-10.16" y="3.81" drill="0.6" shape="square"/>
<pad name="D23" x="-10.16" y="-3.81" drill="0.6" shape="square"/>
<pad name="D22" x="-10.16" y="-2.54" drill="0.6" shape="square"/>
<pad name="TX0" x="-10.16" y="-1.27" drill="0.6" shape="square"/>
<pad name="RX0" x="-10.16" y="0" drill="0.6" shape="square"/>
<pad name="D21" x="-10.16" y="1.27" drill="0.6" shape="square"/>
<pad name="D19" x="-10.16" y="2.54" drill="0.6" shape="square"/>
<pad name="D5" x="-10.16" y="5.08" drill="0.6" shape="square"/>
<pad name="TX2" x="-10.16" y="6.35" drill="0.6" shape="square"/>
<pad name="RX2" x="-10.16" y="7.62" drill="0.6" shape="square"/>
<pad name="D4" x="-10.16" y="8.89" drill="0.6" shape="square"/>
<pad name="D2" x="-10.16" y="10.16" drill="0.6" shape="square"/>
<pad name="D15" x="-10.16" y="11.43" drill="0.6" shape="square"/>
<pad name="GND@1" x="-10.16" y="12.7" drill="0.6" shape="square"/>
<pad name="3V3" x="-10.16" y="13.97" drill="0.6" shape="square"/>
<pad name="EN" x="7.62" y="-3.81" drill="0.6" shape="square"/>
<pad name="VP" x="7.62" y="-2.54" drill="0.6" shape="square"/>
<pad name="VN" x="7.62" y="-1.27" drill="0.6" shape="square"/>
<pad name="D34" x="7.62" y="0" drill="0.6" shape="square"/>
<pad name="D35" x="7.62" y="1.27" drill="0.6" shape="square"/>
<pad name="D32" x="7.62" y="2.54" drill="0.6" shape="square"/>
<pad name="D33" x="7.62" y="3.81" drill="0.6" shape="square"/>
<pad name="D25" x="7.62" y="5.08" drill="0.6" shape="square"/>
<pad name="D26" x="7.62" y="6.35" drill="0.6" shape="square"/>
<pad name="D27" x="7.62" y="7.62" drill="0.6" shape="square"/>
<pad name="D14" x="7.62" y="8.89" drill="0.6" shape="square"/>
<pad name="D12" x="7.62" y="10.16" drill="0.6" shape="square"/>
<pad name="D13" x="7.62" y="11.43" drill="0.6" shape="square"/>
<pad name="GND@0" x="7.62" y="12.7" drill="0.6" shape="square"/>
<pad name="VIN" x="7.62" y="13.97" drill="0.6" shape="square"/>
<pad name="IO" x="-2.54" y="16.51" drill="0.6" shape="square"/>
<pad name="D+" x="-1.27" y="16.51" drill="0.6" shape="square"/>
<pad name="D-" x="0" y="16.51" drill="0.6" shape="square"/>
<pad name="VBUS" x="1.27" y="16.51" drill="0.6" shape="square"/>
<pad name="GND" x="-3.81" y="16.51" drill="0.6" shape="square"/>
<wire x1="-5.08" y1="16.51" x2="-6.35" y2="16.51" width="0.127" layer="21"/>
<wire x1="-6.35" y1="16.51" x2="-10.16" y2="16.51" width="0.127" layer="21"/>
<wire x1="-10.16" y1="16.51" x2="-10.16" y2="15.24" width="0.127" layer="21"/>
<wire x1="2.54" y1="16.51" x2="3.81" y2="16.51" width="0.127" layer="21"/>
<wire x1="3.81" y1="16.51" x2="7.62" y2="16.51" width="0.127" layer="21"/>
<wire x1="7.62" y1="16.51" x2="7.62" y2="15.24" width="0.127" layer="21"/>
<wire x1="-6.35" y1="16.51" x2="-6.35" y2="12.7" width="0.127" layer="21"/>
<wire x1="-6.35" y1="12.7" x2="3.81" y2="12.7" width="0.127" layer="21"/>
<wire x1="3.81" y1="12.7" x2="3.81" y2="16.51" width="0.127" layer="21"/>
<text x="-2.54" y="13.97" size="1.27" layer="21">USB</text>
</package>
<package name="LCD">
<pad name="GND" x="-1.27" y="0" drill="0.6" shape="square"/>
<pad name="VCC" x="0" y="0" drill="0.6" shape="square"/>
<pad name="SDA" x="1.27" y="0" drill="0.6" shape="square"/>
<pad name="SCL" x="2.54" y="0" drill="0.6" shape="square"/>
<text x="-3.81" y="1.27" size="1.524" layer="21">LCD+I2C</text>
<wire x1="2.54" y1="0" x2="6.35" y2="0" width="0.127" layer="21"/>
<wire x1="6.35" y1="0" x2="6.35" y2="3.81" width="0.127" layer="21"/>
<wire x1="6.35" y1="3.81" x2="-5.08" y2="3.81" width="0.127" layer="21"/>
<wire x1="-5.08" y1="3.81" x2="-5.08" y2="0" width="0.127" layer="21"/>
<wire x1="-5.08" y1="0" x2="-1.27" y2="0" width="0.127" layer="21"/>
</package>
<package name="RFID">
<pad name="SDA" x="-7.62" y="1.27" drill="0.6" shape="square"/>
<pad name="SCK" x="-6.35" y="1.27" drill="0.6" shape="square"/>
<pad name="MOSI" x="-5.08" y="1.27" drill="0.6" shape="square"/>
<pad name="MISO" x="-3.81" y="1.27" drill="0.6" shape="square"/>
<pad name="IRQ" x="-2.54" y="1.27" drill="0.6" shape="square"/>
<pad name="GND" x="-1.27" y="1.27" drill="0.6" shape="square"/>
<pad name="RST" x="0" y="1.27" drill="0.6" shape="square"/>
<pad name="3.3V" x="1.27" y="1.27" drill="0.6" shape="square"/>
<wire x1="-10.16" y1="-1.27" x2="-10.16" y2="5.08" width="0.127" layer="21"/>
<wire x1="-10.16" y1="5.08" x2="3.81" y2="5.08" width="0.127" layer="21"/>
<wire x1="3.81" y1="5.08" x2="3.81" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-10.16" y1="-1.27" x2="3.81" y2="-1.27" width="0.127" layer="21"/>
<text x="-6.35" y="2.54" size="1.27" layer="21">RFID</text>
</package>
</packages>
<symbols>
<symbol name="ESP32WROOM">
<wire x1="15.24" y1="-40.64" x2="10.16" y2="-40.64" width="0.254" layer="94"/>
<wire x1="10.16" y1="-40.64" x2="10.16" y2="-35.56" width="0.254" layer="94"/>
<wire x1="10.16" y1="-35.56" x2="2.54" y2="-35.56" width="0.254" layer="94"/>
<wire x1="2.54" y1="-35.56" x2="2.54" y2="-40.64" width="0.254" layer="94"/>
<wire x1="2.54" y1="-40.64" x2="0" y2="-40.64" width="0.254" layer="94"/>
<wire x1="0" y1="-40.64" x2="0" y2="-35.56" width="0.254" layer="94"/>
<wire x1="0" y1="-35.56" x2="-5.08" y2="-35.56" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-35.56" x2="-5.08" y2="-40.64" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-40.64" x2="-12.7" y2="-40.64" width="0.254" layer="94"/>
<wire x1="15.24" y1="-40.64" x2="15.24" y2="-33.02" width="0.254" layer="94"/>
<wire x1="-17.78" y1="22.86" x2="-7.62" y2="22.86" width="0.254" layer="94"/>
<wire x1="7.62" y1="22.86" x2="20.32" y2="22.86" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-45.72" x2="20.32" y2="-45.72" width="0.254" layer="94"/>
<pin name="3V3" x="-22.86" y="15.24" length="middle"/>
<pin name="GND@1" x="-22.86" y="12.7" length="middle"/>
<pin name="D15" x="-22.86" y="10.16" length="middle"/>
<pin name="D2" x="-22.86" y="7.62" length="middle"/>
<pin name="D4" x="-22.86" y="5.08" length="middle"/>
<pin name="RX2" x="-22.86" y="2.54" length="middle"/>
<pin name="TX2" x="-22.86" y="0" length="middle"/>
<pin name="D5" x="-22.86" y="-2.54" length="middle"/>
<pin name="D18" x="-22.86" y="-5.08" length="middle"/>
<pin name="D19" x="-22.86" y="-7.62" length="middle"/>
<pin name="D21" x="-22.86" y="-10.16" length="middle"/>
<pin name="RX0" x="-22.86" y="-12.7" length="middle"/>
<pin name="TX0" x="-22.86" y="-15.24" length="middle"/>
<pin name="D22" x="-22.86" y="-17.78" length="middle"/>
<pin name="D23" x="-22.86" y="-20.32" length="middle"/>
<pin name="VBUS" x="5.08" y="27.94" length="middle" rot="R270"/>
<pin name="D-" x="2.54" y="27.94" length="middle" rot="R270"/>
<pin name="D+" x="0" y="27.94" length="middle" rot="R270"/>
<pin name="IO" x="-2.54" y="27.94" length="middle" rot="R270"/>
<pin name="GND" x="-5.08" y="27.94" length="middle" rot="R270"/>
<pin name="EN" x="25.4" y="-20.32" length="middle" rot="R180"/>
<pin name="VP" x="25.4" y="-17.78" length="middle" rot="R180"/>
<pin name="VN" x="25.4" y="-15.24" length="middle" rot="R180"/>
<pin name="D34" x="25.4" y="-12.7" length="middle" rot="R180"/>
<pin name="D35" x="25.4" y="-10.16" length="middle" rot="R180"/>
<pin name="D32" x="25.4" y="-7.62" length="middle" rot="R180"/>
<pin name="D33" x="25.4" y="-5.08" length="middle" rot="R180"/>
<pin name="D25" x="25.4" y="-2.54" length="middle" rot="R180"/>
<pin name="D26" x="25.4" y="0" length="middle" rot="R180"/>
<pin name="D27" x="25.4" y="2.54" length="middle" rot="R180"/>
<pin name="D14" x="25.4" y="5.08" length="middle" rot="R180"/>
<pin name="D12" x="25.4" y="7.62" length="middle" rot="R180"/>
<pin name="D13" x="25.4" y="10.16" length="middle" rot="R180"/>
<pin name="GND@0" x="25.4" y="12.7" length="middle" rot="R180"/>
<pin name="VIN" x="25.4" y="15.24" length="middle" rot="R180"/>
<wire x1="-17.78" y1="22.86" x2="-17.78" y2="-27.94" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-27.94" x2="20.32" y2="-27.94" width="0.254" layer="94"/>
<wire x1="20.32" y1="-27.94" x2="20.32" y2="22.86" width="0.254" layer="94"/>
<text x="-7.62" y="-22.86" size="3.81" layer="94">ESP32</text>
<wire x1="-17.78" y1="-27.94" x2="-17.78" y2="-45.72" width="0.254" layer="94"/>
<wire x1="20.32" y1="-45.72" x2="20.32" y2="-27.94" width="0.254" layer="94"/>
<wire x1="-7.62" y1="12.7" x2="7.62" y2="12.7" width="0.254" layer="94"/>
<text x="-2.54" y="15.24" size="2.54" layer="94">USB</text>
<wire x1="-7.62" y1="12.7" x2="-7.62" y2="22.86" width="0.254" layer="94"/>
<wire x1="-7.62" y1="22.86" x2="7.62" y2="22.86" width="0.254" layer="94"/>
<wire x1="7.62" y1="22.86" x2="7.62" y2="12.7" width="0.254" layer="94"/>
</symbol>
<symbol name="LCD">
<pin name="GND" x="-2.54" y="-5.08" length="middle" rot="R90"/>
<pin name="VCC" x="0" y="-5.08" length="middle" rot="R90"/>
<pin name="SDA" x="2.54" y="-5.08" length="middle" rot="R90"/>
<pin name="SCL" x="5.08" y="-5.08" length="middle" rot="R90"/>
<text x="-10.16" y="7.62" size="3.81" layer="94">LCD+I2C</text>
<wire x1="-10.16" y1="0" x2="12.7" y2="0" width="0.254" layer="94"/>
<wire x1="12.7" y1="0" x2="12.7" y2="12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="12.7" x2="-10.16" y2="12.7" width="0.254" layer="94"/>
<wire x1="-10.16" y1="12.7" x2="-10.16" y2="0" width="0.254" layer="94"/>
</symbol>
<symbol name="RFID">
<pin name="SDA" x="-10.16" y="-17.78" length="middle" rot="R90"/>
<pin name="SCK" x="-7.62" y="-17.78" length="middle" rot="R90"/>
<pin name="MOSI" x="-5.08" y="-17.78" length="middle" rot="R90"/>
<pin name="MISO" x="-2.54" y="-17.78" length="middle" rot="R90"/>
<pin name="IRQ" x="0" y="-17.78" length="middle" rot="R90"/>
<pin name="GND" x="2.54" y="-17.78" length="middle" rot="R90"/>
<pin name="RST" x="5.08" y="-17.78" length="middle" rot="R90"/>
<pin name="3.3V" x="7.62" y="-17.78" length="middle" rot="R90"/>
<wire x1="-12.7" y1="-12.7" x2="10.16" y2="-12.7" width="0.254" layer="94"/>
<wire x1="10.16" y1="-12.7" x2="10.16" y2="15.24" width="0.254" layer="94"/>
<wire x1="10.16" y1="15.24" x2="-12.7" y2="15.24" width="0.254" layer="94"/>
<wire x1="-12.7" y1="15.24" x2="-12.7" y2="-12.7" width="0.254" layer="94"/>
<text x="-10.16" y="7.62" size="5.08" layer="94">RFID</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ESP32WROOM">
<gates>
<gate name="G$1" symbol="ESP32WROOM" x="0" y="0"/>
</gates>
<devices>
<device name="" package="ESP32WROOM">
<connects>
<connect gate="G$1" pin="3V3" pad="3V3"/>
<connect gate="G$1" pin="D+" pad="D+"/>
<connect gate="G$1" pin="D-" pad="D-"/>
<connect gate="G$1" pin="D12" pad="D12"/>
<connect gate="G$1" pin="D13" pad="D13"/>
<connect gate="G$1" pin="D14" pad="D14"/>
<connect gate="G$1" pin="D15" pad="D15"/>
<connect gate="G$1" pin="D18" pad="D18"/>
<connect gate="G$1" pin="D19" pad="D19"/>
<connect gate="G$1" pin="D2" pad="D2"/>
<connect gate="G$1" pin="D21" pad="D21"/>
<connect gate="G$1" pin="D22" pad="D22"/>
<connect gate="G$1" pin="D23" pad="D23"/>
<connect gate="G$1" pin="D25" pad="D25"/>
<connect gate="G$1" pin="D26" pad="D26"/>
<connect gate="G$1" pin="D27" pad="D27"/>
<connect gate="G$1" pin="D32" pad="D32"/>
<connect gate="G$1" pin="D33" pad="D33"/>
<connect gate="G$1" pin="D34" pad="D34"/>
<connect gate="G$1" pin="D35" pad="D35"/>
<connect gate="G$1" pin="D4" pad="D4"/>
<connect gate="G$1" pin="D5" pad="D5"/>
<connect gate="G$1" pin="EN" pad="EN"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND@0" pad="GND@0"/>
<connect gate="G$1" pin="GND@1" pad="GND@1"/>
<connect gate="G$1" pin="IO" pad="IO"/>
<connect gate="G$1" pin="RX0" pad="RX0"/>
<connect gate="G$1" pin="RX2" pad="RX2"/>
<connect gate="G$1" pin="TX0" pad="TX0"/>
<connect gate="G$1" pin="TX2" pad="TX2"/>
<connect gate="G$1" pin="VBUS" pad="VBUS"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
<connect gate="G$1" pin="VN" pad="VN"/>
<connect gate="G$1" pin="VP" pad="VP"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="LCD+I2C">
<gates>
<gate name="G$1" symbol="LCD" x="0" y="-5.08"/>
</gates>
<devices>
<device name="" package="LCD">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="RFID">
<gates>
<gate name="G$1" symbol="RFID" x="0" y="0"/>
</gates>
<devices>
<device name="" package="RFID">
<connects>
<connect gate="G$1" pin="3.3V" pad="3.3V"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="IRQ" pad="IRQ"/>
<connect gate="G$1" pin="MISO" pad="MISO"/>
<connect gate="G$1" pin="MOSI" pad="MOSI"/>
<connect gate="G$1" pin="RST" pad="RST"/>
<connect gate="G$1" pin="SCK" pad="SCK"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="frames" urn="urn:adsk.eagle:library:229">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="A4L-LOC" urn="urn:adsk.eagle:symbol:13874/1" library_version="1">
<wire x1="256.54" y1="3.81" x2="256.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="256.54" y1="8.89" x2="256.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="256.54" y1="13.97" x2="256.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="256.54" y1="19.05" x2="256.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="161.29" y1="3.81" x2="161.29" y2="24.13" width="0.1016" layer="94"/>
<wire x1="161.29" y1="24.13" x2="215.265" y2="24.13" width="0.1016" layer="94"/>
<wire x1="215.265" y1="24.13" x2="256.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="246.38" y1="3.81" x2="246.38" y2="8.89" width="0.1016" layer="94"/>
<wire x1="246.38" y1="8.89" x2="256.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="246.38" y1="8.89" x2="215.265" y2="8.89" width="0.1016" layer="94"/>
<wire x1="215.265" y1="8.89" x2="215.265" y2="3.81" width="0.1016" layer="94"/>
<wire x1="215.265" y1="8.89" x2="215.265" y2="13.97" width="0.1016" layer="94"/>
<wire x1="215.265" y1="13.97" x2="256.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="215.265" y1="13.97" x2="215.265" y2="19.05" width="0.1016" layer="94"/>
<wire x1="215.265" y1="19.05" x2="256.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="215.265" y1="19.05" x2="215.265" y2="24.13" width="0.1016" layer="94"/>
<text x="217.17" y="15.24" size="2.54" layer="94">&gt;DRAWING_NAME</text>
<text x="217.17" y="10.16" size="2.286" layer="94">&gt;LAST_DATE_TIME</text>
<text x="230.505" y="5.08" size="2.54" layer="94">&gt;SHEET</text>
<text x="216.916" y="4.953" size="2.54" layer="94">Sheet:</text>
<frame x1="0" y1="0" x2="260.35" y2="179.07" columns="6" rows="4" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="A4L-LOC" urn="urn:adsk.eagle:component:13926/1" prefix="FRAME" uservalue="yes" library_version="1">
<description>&lt;b&gt;FRAME&lt;/b&gt;&lt;p&gt;
DIN A4, landscape with location and doc. field</description>
<gates>
<gate name="G$1" symbol="A4L-LOC" x="0" y="0"/>
</gates>
<devices>
<device name="">
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
<part name="U$1" library="MODULAR" deviceset="ESP32WROOM" device=""/>
<part name="U$2" library="MODULAR" deviceset="LCD+I2C" device=""/>
<part name="U$3" library="MODULAR" deviceset="RFID" device=""/>
<part name="FRAME2" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="A4L-LOC" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<text x="68.58" y="157.48" size="10.16" layer="91">MODULO BAHIA</text>
<text x="170.18" y="27.94" size="2.54" layer="94">MODULO BAHIA  VER 1.0 FECHA 20/02/2025 </text>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="119.38" y="99.06" smashed="yes"/>
<instance part="U$2" gate="G$1" x="160.02" y="127" smashed="yes"/>
<instance part="U$3" gate="G$1" x="76.2" y="134.62" smashed="yes"/>
<instance part="FRAME2" gate="G$1" x="0" y="0" smashed="yes">
<attribute name="DRAWING_NAME" x="217.17" y="15.24" size="2.54" layer="94"/>
<attribute name="LAST_DATE_TIME" x="217.17" y="10.16" size="2.286" layer="94"/>
<attribute name="SHEET" x="230.505" y="5.08" size="2.54" layer="94"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="SDA"/>
<wire x1="66.04" y1="116.84" x2="66.04" y2="88.9" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="D21"/>
<wire x1="66.04" y1="88.9" x2="96.52" y2="88.9" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="SCK"/>
<pinref part="U$1" gate="G$1" pin="D18"/>
<wire x1="68.58" y1="116.84" x2="68.58" y2="93.98" width="0.1524" layer="91"/>
<wire x1="68.58" y1="93.98" x2="96.52" y2="93.98" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="MOSI"/>
<wire x1="71.12" y1="116.84" x2="71.12" y2="78.74" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="D23"/>
<wire x1="71.12" y1="78.74" x2="96.52" y2="78.74" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="MISO"/>
<pinref part="U$1" gate="G$1" pin="D19"/>
<wire x1="73.66" y1="116.84" x2="73.66" y2="91.44" width="0.1524" layer="91"/>
<wire x1="73.66" y1="91.44" x2="96.52" y2="91.44" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="GND"/>
<pinref part="U$1" gate="G$1" pin="GND@1"/>
<wire x1="78.74" y1="116.84" x2="78.74" y2="111.76" width="0.1524" layer="91"/>
<wire x1="78.74" y1="111.76" x2="96.52" y2="111.76" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="RST"/>
<pinref part="U$1" gate="G$1" pin="D22"/>
<wire x1="81.28" y1="116.84" x2="81.28" y2="81.28" width="0.1524" layer="91"/>
<wire x1="81.28" y1="81.28" x2="96.52" y2="81.28" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="3.3V"/>
<pinref part="U$1" gate="G$1" pin="3V3"/>
<wire x1="83.82" y1="116.84" x2="83.82" y2="114.3" width="0.1524" layer="91"/>
<wire x1="83.82" y1="114.3" x2="96.52" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="VIN"/>
<wire x1="144.78" y1="114.3" x2="160.02" y2="114.3" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="VCC"/>
<wire x1="160.02" y1="114.3" x2="160.02" y2="121.92" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND@0"/>
<pinref part="U$2" gate="G$1" pin="GND"/>
<wire x1="144.78" y1="111.76" x2="157.48" y2="111.76" width="0.1524" layer="91"/>
<wire x1="157.48" y1="111.76" x2="157.48" y2="121.92" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="SCL"/>
<pinref part="U$1" gate="G$1" pin="D26"/>
<wire x1="165.1" y1="121.92" x2="165.1" y2="99.06" width="0.1524" layer="91"/>
<wire x1="165.1" y1="99.06" x2="144.78" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D25"/>
<pinref part="U$2" gate="G$1" pin="SDA"/>
<wire x1="144.78" y1="96.52" x2="162.56" y2="96.52" width="0.1524" layer="91"/>
<wire x1="162.56" y1="96.52" x2="162.56" y2="121.92" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
