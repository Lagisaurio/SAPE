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
<text x="-2.17" y="13.78" size="3" layer="21" rot="R180">ESP32WROOM</text>
<pad name="D18" x="-20.32" y="25.4" drill="1.3" rot="R270"/>
<pad name="D23" x="-35.56" y="25.4" drill="1.3" rot="R270"/>
<pad name="D22" x="-33.02" y="25.4" drill="1.3" rot="R270"/>
<pad name="TX0" x="-30.48" y="25.4" drill="1.3" rot="R270"/>
<pad name="RX0" x="-27.94" y="25.4" drill="1.3" rot="R270"/>
<pad name="D21" x="-25.4" y="25.4" drill="1.3" rot="R270"/>
<pad name="D19" x="-22.86" y="25.4" drill="1.3" rot="R270"/>
<pad name="D5" x="-17.78" y="25.4" drill="1.3" rot="R270"/>
<pad name="TX2" x="-15.24" y="25.4" drill="1.3" rot="R270"/>
<pad name="RX2" x="-12.7" y="25.4" drill="1.3" rot="R270"/>
<pad name="D4" x="-10.16" y="25.4" drill="1.3" rot="R270"/>
<pad name="D2" x="-7.62" y="25.4" drill="1.3" rot="R270"/>
<pad name="D15" x="-5.08" y="25.4" drill="1.3" rot="R270"/>
<pad name="GND@1" x="-2.54" y="25.4" drill="1.3" rot="R270"/>
<pad name="3V3" x="0" y="25.4" drill="1.3" shape="square" rot="R270"/>
<pad name="EN" x="-35.56" y="0" drill="1.3" rot="R270"/>
<pad name="VP" x="-33.02" y="0" drill="1.3" rot="R270"/>
<pad name="VN" x="-30.48" y="0" drill="1.3" rot="R270"/>
<pad name="D34" x="-27.94" y="0" drill="1.3" rot="R270"/>
<pad name="D35" x="-25.4" y="0" drill="1.3" rot="R270"/>
<pad name="D32" x="-22.86" y="0" drill="1.3" rot="R270"/>
<pad name="D33" x="-20.32" y="0" drill="1.3" rot="R270"/>
<pad name="D25" x="-17.78" y="0" drill="1.3" rot="R270"/>
<pad name="D26" x="-15.24" y="0" drill="1.3" rot="R270"/>
<pad name="D27" x="-12.7" y="0" drill="1.3" rot="R270"/>
<pad name="D14" x="-10.16" y="0" drill="1.3" rot="R270"/>
<pad name="D12" x="-7.62" y="0" drill="1.3" rot="R270"/>
<pad name="D13" x="-5.08" y="0" drill="1.3" rot="R270"/>
<pad name="GND@0" x="-2.54" y="0" drill="1.3" rot="R270"/>
<pad name="VIN" x="0" y="0" drill="1.3" shape="square" rot="R270"/>
<wire x1="-36.55" y1="25.4" x2="-37" y2="25.4" width="0.1524" layer="21"/>
<wire x1="-37" y1="25.4" x2="-44.55" y2="25.4" width="0.1524" layer="21"/>
<wire x1="-44.55" y1="25.4" x2="-44.55" y2="0" width="0.1524" layer="21"/>
<wire x1="-44.55" y1="0" x2="-37" y2="0" width="0.1524" layer="21"/>
<wire x1="-37" y1="0" x2="-36.55" y2="0" width="0.1524" layer="21"/>
<wire x1="-37" y1="25.4" x2="-37" y2="0" width="0.1524" layer="21"/>
<wire x1="-38.55" y1="4.42" x2="-43.05" y2="4.42" width="0.1524" layer="21"/>
<wire x1="-43.05" y1="4.42" x2="-43.05" y2="6.42" width="0.1524" layer="21"/>
<wire x1="-43.05" y1="6.42" x2="-40.55" y2="6.42" width="0.1524" layer="21"/>
<wire x1="-40.55" y1="6.42" x2="-40.55" y2="8.92" width="0.1524" layer="21"/>
<wire x1="-40.55" y1="8.92" x2="-43.05" y2="8.92" width="0.1524" layer="21"/>
<wire x1="-43.05" y1="8.92" x2="-43.05" y2="11.42" width="0.1524" layer="21"/>
<wire x1="-43.05" y1="11.42" x2="-40.55" y2="11.42" width="0.1524" layer="21"/>
<wire x1="-40.55" y1="11.42" x2="-40.55" y2="14.42" width="0.1524" layer="21"/>
<wire x1="-40.55" y1="14.42" x2="-43.05" y2="14.42" width="0.1524" layer="21"/>
<wire x1="-43.05" y1="14.42" x2="-43.05" y2="17.92" width="0.1524" layer="21"/>
<wire x1="-43.05" y1="17.92" x2="-38.55" y2="17.92" width="0.1524" layer="21"/>
<wire x1="-43.05" y1="17.92" x2="-43.05" y2="20.92" width="0.1524" layer="21"/>
<wire x1="-43.05" y1="20.92" x2="-38.55" y2="20.92" width="0.1524" layer="21"/>
<wire x1="1.25" y1="25.4" x2="3.95" y2="25.4" width="0.1524" layer="21"/>
<wire x1="3.95" y1="25.4" x2="3.95" y2="0" width="0.1524" layer="21"/>
<wire x1="3.95" y1="0" x2="1.25" y2="0" width="0.1524" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="ESP32WROOM">
<wire x1="15.24" y1="-33.02" x2="10.16" y2="-33.02" width="0.254" layer="94"/>
<wire x1="10.16" y1="-33.02" x2="10.16" y2="-27.94" width="0.254" layer="94"/>
<wire x1="10.16" y1="-27.94" x2="2.54" y2="-27.94" width="0.254" layer="94"/>
<wire x1="2.54" y1="-27.94" x2="2.54" y2="-33.02" width="0.254" layer="94"/>
<wire x1="2.54" y1="-33.02" x2="0" y2="-33.02" width="0.254" layer="94"/>
<wire x1="0" y1="-33.02" x2="0" y2="-27.94" width="0.254" layer="94"/>
<wire x1="0" y1="-27.94" x2="-5.08" y2="-27.94" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-27.94" x2="-5.08" y2="-33.02" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-33.02" x2="-12.7" y2="-33.02" width="0.254" layer="94"/>
<wire x1="15.24" y1="-33.02" x2="15.24" y2="-25.4" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-35.56" x2="20.32" y2="-35.56" width="0.254" layer="94"/>
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
<wire x1="-17.78" y1="17.78" x2="-17.78" y2="-22.86" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-22.86" x2="20.32" y2="-22.86" width="0.254" layer="94"/>
<wire x1="20.32" y1="-22.86" x2="20.32" y2="17.78" width="0.254" layer="94"/>
<text x="-7.62" y="-20.32" size="3.81" layer="94">ESP32</text>
<wire x1="-17.78" y1="-22.86" x2="-17.78" y2="-35.56" width="0.254" layer="94"/>
<wire x1="20.32" y1="-35.56" x2="20.32" y2="-22.86" width="0.254" layer="94"/>
<wire x1="-17.78" y1="17.78" x2="20.32" y2="17.78" width="0.254" layer="94"/>
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
<connect gate="G$1" pin="GND@0" pad="GND@0"/>
<connect gate="G$1" pin="GND@1" pad="GND@1"/>
<connect gate="G$1" pin="RX0" pad="RX0"/>
<connect gate="G$1" pin="RX2" pad="RX2"/>
<connect gate="G$1" pin="TX0" pad="TX0"/>
<connect gate="G$1" pin="TX2" pad="TX2"/>
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
<library name="con-lstb" urn="urn:adsk.eagle:library:162">
<description>&lt;b&gt;Pin Headers&lt;/b&gt;&lt;p&gt;
Naming:&lt;p&gt;
MA = male&lt;p&gt;
# contacts - # rows&lt;p&gt;
W = angled&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="MA04-1" urn="urn:adsk.eagle:footprint:8285/1" library_version="2">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-4.445" y1="1.27" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-0.635" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-0.635" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-5.08" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-6.223" y="-0.635" size="1.27" layer="21" ratio="10">1</text>
<text x="0.635" y="1.651" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="5.334" y="-0.635" size="1.27" layer="21" ratio="10">4</text>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
</package>
<package name="MA07-1" urn="urn:adsk.eagle:footprint:8291/1" library_version="2">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-8.255" y1="1.27" x2="-6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="1.27" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-0.635" x2="-6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="0.635" x2="-5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="1.27" x2="-4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-0.635" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.27" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-1.27" x2="-6.35" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="0.635" x2="-8.89" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="1.27" x2="-8.89" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-0.635" x2="-8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-1.27" x2="-8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-0.635" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="1.27" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-0.635" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-1.27" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="6.985" y1="1.27" x2="8.255" y2="1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="1.27" x2="8.89" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="0.635" x2="8.89" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="-0.635" x2="8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="1.27" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-0.635" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-1.27" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-7.62" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-5.08" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="0" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="5.08" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="7.62" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-8.89" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-8.255" y="-2.921" size="1.27" layer="21" ratio="10">1</text>
<text x="-2.54" y="-2.921" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="7.239" y="1.651" size="1.27" layer="21" ratio="10">7</text>
<rectangle x1="-5.334" y1="-0.254" x2="-4.826" y2="0.254" layer="51"/>
<rectangle x1="-7.874" y1="-0.254" x2="-7.366" y2="0.254" layer="51"/>
<rectangle x1="-2.794" y1="-0.254" x2="-2.286" y2="0.254" layer="51"/>
<rectangle x1="2.286" y1="-0.254" x2="2.794" y2="0.254" layer="51"/>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
<rectangle x1="4.826" y1="-0.254" x2="5.334" y2="0.254" layer="51"/>
<rectangle x1="7.366" y1="-0.254" x2="7.874" y2="0.254" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="MA04-1" urn="urn:adsk.eagle:package:8337/1" type="box" library_version="2">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="MA04-1"/>
</packageinstances>
</package3d>
<package3d name="MA07-1" urn="urn:adsk.eagle:package:8341/1" type="box" library_version="2">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="MA07-1"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MA04-1" urn="urn:adsk.eagle:symbol:8284/1" library_version="2">
<wire x1="3.81" y1="-7.62" x2="-1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="2.54" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="5.08" x2="-1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-7.62" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="5.08" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<text x="-1.27" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<text x="-1.27" y="5.842" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
<symbol name="MA07-1" urn="urn:adsk.eagle:symbol:8290/1" library_version="2">
<wire x1="3.81" y1="-10.16" x2="-1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="2.54" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-7.62" x2="2.54" y2="-7.62" width="0.6096" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="1.27" y1="7.62" x2="2.54" y2="7.62" width="0.6096" layer="94"/>
<wire x1="1.27" y1="5.08" x2="2.54" y2="5.08" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="10.16" x2="-1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-10.16" x2="3.81" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="10.16" x2="3.81" y2="10.16" width="0.4064" layer="94"/>
<text x="-1.27" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
<text x="-1.27" y="10.922" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="6" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="7" x="7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MA04-1" urn="urn:adsk.eagle:component:8375/2" prefix="SV" uservalue="yes" library_version="2">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="MA04-1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="MA04-1">
<connects>
<connect gate="1" pin="1" pad="1"/>
<connect gate="1" pin="2" pad="2"/>
<connect gate="1" pin="3" pad="3"/>
<connect gate="1" pin="4" pad="4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8337/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="41" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="MA07-1" urn="urn:adsk.eagle:component:8380/2" prefix="SV" uservalue="yes" library_version="2">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="MA07-1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="MA07-1">
<connects>
<connect gate="1" pin="1" pad="1"/>
<connect gate="1" pin="2" pad="2"/>
<connect gate="1" pin="3" pad="3"/>
<connect gate="1" pin="4" pad="4"/>
<connect gate="1" pin="5" pad="5"/>
<connect gate="1" pin="6" pad="6"/>
<connect gate="1" pin="7" pad="7"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8341/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="4" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="buzzer" urn="urn:adsk.eagle:library:113">
<description>&lt;b&gt;Speakers and Buzzers&lt;/b&gt;&lt;p&gt;
&lt;ul&gt;Distributors:
&lt;li&gt;Buerklin
&lt;li&gt;Spoerle
&lt;li&gt;Schukat
&lt;/ul&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="F/CM12P" urn="urn:adsk.eagle:footprint:5223/1" library_version="2">
<description>&lt;b&gt;BUZZER&lt;/b&gt;</description>
<wire x1="3.175" y1="3.048" x2="4.445" y2="3.048" width="0.254" layer="21"/>
<wire x1="3.81" y1="3.683" x2="3.81" y2="2.413" width="0.254" layer="21"/>
<circle x="0" y="0" radius="6.985" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="1.27" width="0.1524" layer="21"/>
<circle x="3.81" y="3.048" radius="1.27" width="0.1524" layer="21"/>
<pad name="-" x="-3.81" y="0" drill="1.016" diameter="2.54" shape="octagon"/>
<pad name="+" x="3.81" y="0" drill="1.016" diameter="2.54" shape="octagon"/>
<text x="2.54" y="6.985" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-4.445" y="-3.81" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="F/CM12P" urn="urn:adsk.eagle:package:5265/1" type="box" library_version="2">
<description>BUZZER</description>
<packageinstances>
<packageinstance name="F/CM12P"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="B2P" urn="urn:adsk.eagle:symbol:5221/1" library_version="2">
<wire x1="-1.27" y1="3.175" x2="0" y2="3.175" width="0.1524" layer="94"/>
<wire x1="0" y1="3.175" x2="0" y2="3.81" width="0.1524" layer="94"/>
<wire x1="0" y1="3.175" x2="0" y2="2.54" width="0.1524" layer="94"/>
<wire x1="0.635" y1="4.445" x2="0.635" y2="1.905" width="0.1524" layer="94"/>
<wire x1="0.635" y1="1.905" x2="1.905" y2="1.905" width="0.1524" layer="94"/>
<wire x1="1.905" y1="1.905" x2="1.905" y2="4.445" width="0.1524" layer="94"/>
<wire x1="1.905" y1="4.445" x2="0.635" y2="4.445" width="0.1524" layer="94"/>
<wire x1="2.54" y1="3.81" x2="2.54" y2="3.175" width="0.1524" layer="94"/>
<wire x1="2.54" y1="3.175" x2="3.81" y2="3.175" width="0.1524" layer="94"/>
<wire x1="2.54" y1="3.175" x2="2.54" y2="2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="2.54" y2="1.27" width="0.1524" layer="94"/>
<wire x1="0" y1="-2.54" x2="0" y2="1.27" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="1.27" x2="0" y2="1.27" width="0.254" layer="94"/>
<wire x1="5.08" y1="1.27" x2="5.08" y2="5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="5.08" x2="5.715" y2="5.08" width="0.254" layer="94"/>
<wire x1="5.715" y1="5.08" x2="5.715" y2="5.715" width="0.254" layer="94"/>
<wire x1="5.715" y1="5.715" x2="-3.175" y2="5.715" width="0.254" layer="94"/>
<wire x1="-3.175" y1="5.715" x2="-3.175" y2="5.08" width="0.254" layer="94"/>
<wire x1="-3.175" y1="5.08" x2="-2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="-2.54" y2="1.27" width="0.254" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="5.08" y2="5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="1.27" x2="5.08" y2="1.27" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="2.54" y2="1.27" width="0.254" layer="94"/>
<text x="-2.54" y="6.35" size="1.778" layer="95">&gt;NAME</text>
<text x="6.35" y="0" size="1.778" layer="96">&gt;VALUE</text>
<pin name="2" x="5.08" y="-2.54" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="1" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="F/CM12P" urn="urn:adsk.eagle:component:5310/2" prefix="SG" library_version="2">
<description>&lt;b&gt;BUZZER&lt;/b&gt;&lt;p&gt; Source: Buerklin</description>
<gates>
<gate name="G$1" symbol="B2P" x="0" y="0"/>
</gates>
<devices>
<device name="" package="F/CM12P">
<connects>
<connect gate="G$1" pin="1" pad="+"/>
<connect gate="G$1" pin="2" pad="-"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5265/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="9" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply2" urn="urn:adsk.eagle:library:372">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
Please keep in mind, that these devices are necessary for the
automatic wiring of the supply signals.&lt;p&gt;
The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26990/1" library_version="2">
<wire x1="-1.27" y1="0" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="-1.27" width="0.254" layer="94"/>
<wire x1="0" y1="-1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<text x="-1.905" y="-3.175" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:27037/1" prefix="SUPPLY" library_version="2">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="GND" symbol="GND" x="0" y="0"/>
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
<part name="FRAME2" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="A4L-LOC" device=""/>
<part name="SV1" library="con-lstb" library_urn="urn:adsk.eagle:library:162" deviceset="MA04-1" device="" package3d_urn="urn:adsk.eagle:package:8337/1"/>
<part name="SV2" library="con-lstb" library_urn="urn:adsk.eagle:library:162" deviceset="MA07-1" device="" package3d_urn="urn:adsk.eagle:package:8341/1"/>
<part name="SG2" library="buzzer" library_urn="urn:adsk.eagle:library:113" deviceset="F/CM12P" device="" package3d_urn="urn:adsk.eagle:package:5265/1"/>
<part name="SUPPLY1" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<text x="68.58" y="157.48" size="10.16" layer="91">MODULO BAHIA</text>
<text x="170.18" y="27.94" size="2.54" layer="94">MODULO BAHIA  VER 1.0 FECHA 20/02/2025 </text>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="119.38" y="99.06" smashed="yes"/>
<instance part="FRAME2" gate="G$1" x="0" y="0" smashed="yes">
<attribute name="DRAWING_NAME" x="217.17" y="15.24" size="2.54" layer="94"/>
<attribute name="LAST_DATE_TIME" x="217.17" y="10.16" size="2.286" layer="94"/>
<attribute name="SHEET" x="230.505" y="5.08" size="2.54" layer="94"/>
</instance>
<instance part="SV1" gate="1" x="177.8" y="109.22" smashed="yes" rot="R180">
<attribute name="VALUE" x="179.07" y="119.38" size="1.778" layer="96" rot="R180"/>
<attribute name="NAME" x="179.07" y="103.378" size="1.778" layer="95" rot="R180"/>
</instance>
<instance part="SV2" gate="1" x="63.5" y="106.68" smashed="yes">
<attribute name="VALUE" x="62.23" y="93.98" size="1.778" layer="96"/>
<attribute name="NAME" x="62.23" y="117.602" size="1.778" layer="95"/>
</instance>
<instance part="SG2" gate="G$1" x="167.64" y="88.9" smashed="yes" rot="R270">
<attribute name="NAME" x="173.99" y="91.44" size="1.778" layer="95" rot="R270"/>
<attribute name="VALUE" x="167.64" y="82.55" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="SUPPLY1" gate="GND" x="165.1" y="73.66" smashed="yes">
<attribute name="VALUE" x="163.195" y="70.485" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="SDA" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D21"/>
<wire x1="83.82" y1="88.9" x2="96.52" y2="88.9" width="0.1524" layer="91"/>
<pinref part="SV2" gate="1" pin="3"/>
<wire x1="71.12" y1="104.14" x2="83.82" y2="104.14" width="0.1524" layer="91"/>
<wire x1="83.82" y1="104.14" x2="83.82" y2="88.9" width="0.1524" layer="91"/>
<label x="71.12" y="104.14" size="1.778" layer="95"/>
</segment>
</net>
<net name="SCK" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D18"/>
<wire x1="88.9" y1="93.98" x2="96.52" y2="93.98" width="0.1524" layer="91"/>
<pinref part="SV2" gate="1" pin="5"/>
<wire x1="71.12" y1="109.22" x2="88.9" y2="109.22" width="0.1524" layer="91"/>
<wire x1="88.9" y1="109.22" x2="88.9" y2="93.98" width="0.1524" layer="91"/>
<label x="71.12" y="109.22" size="1.778" layer="95"/>
</segment>
</net>
<net name="MOSI" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D23"/>
<wire x1="78.74" y1="78.74" x2="96.52" y2="78.74" width="0.1524" layer="91"/>
<pinref part="SV2" gate="1" pin="1"/>
<wire x1="71.12" y1="99.06" x2="78.74" y2="99.06" width="0.1524" layer="91"/>
<wire x1="78.74" y1="99.06" x2="78.74" y2="78.74" width="0.1524" layer="91"/>
<label x="71.12" y="99.06" size="1.778" layer="95"/>
</segment>
</net>
<net name="MISO" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D19"/>
<wire x1="86.36" y1="91.44" x2="96.52" y2="91.44" width="0.1524" layer="91"/>
<pinref part="SV2" gate="1" pin="4"/>
<wire x1="71.12" y1="106.68" x2="86.36" y2="106.68" width="0.1524" layer="91"/>
<wire x1="86.36" y1="106.68" x2="86.36" y2="91.44" width="0.1524" layer="91"/>
<label x="71.12" y="106.68" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND@1"/>
<pinref part="SV2" gate="1" pin="6"/>
<wire x1="71.12" y1="111.76" x2="96.52" y2="111.76" width="0.1524" layer="91"/>
<label x="71.12" y="111.76" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND@0"/>
<pinref part="SV1" gate="1" pin="2"/>
<wire x1="144.78" y1="111.76" x2="170.18" y2="111.76" width="0.1524" layer="91"/>
<label x="160.02" y="111.76" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SG2" gate="G$1" pin="2"/>
<pinref part="SUPPLY1" gate="GND" pin="GND"/>
<wire x1="165.1" y1="83.82" x2="165.1" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="RST" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D22"/>
<pinref part="SV2" gate="1" pin="2"/>
<wire x1="71.12" y1="101.6" x2="81.28" y2="101.6" width="0.1524" layer="91"/>
<wire x1="81.28" y1="101.6" x2="81.28" y2="81.28" width="0.1524" layer="91"/>
<wire x1="81.28" y1="81.28" x2="96.52" y2="81.28" width="0.1524" layer="91"/>
<label x="71.12" y="101.6" size="1.778" layer="95"/>
</segment>
</net>
<net name="3V3" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="3V3"/>
<wire x1="71.12" y1="114.3" x2="96.52" y2="114.3" width="0.1524" layer="91"/>
<pinref part="SV2" gate="1" pin="7"/>
<label x="71.12" y="114.3" size="1.778" layer="95"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="VIN"/>
<pinref part="SV1" gate="1" pin="1"/>
<wire x1="144.78" y1="114.3" x2="170.18" y2="114.3" width="0.1524" layer="91"/>
<label x="160.02" y="114.3" size="1.778" layer="95"/>
</segment>
</net>
<net name="SCL" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D26"/>
<wire x1="154.94" y1="99.06" x2="144.78" y2="99.06" width="0.1524" layer="91"/>
<pinref part="SV1" gate="1" pin="3"/>
<wire x1="154.94" y1="99.06" x2="154.94" y2="109.22" width="0.1524" layer="91"/>
<wire x1="154.94" y1="109.22" x2="170.18" y2="109.22" width="0.1524" layer="91"/>
<label x="160.02" y="109.22" size="1.778" layer="95"/>
</segment>
</net>
<net name="SDA_I2C" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D25"/>
<wire x1="144.78" y1="96.52" x2="157.48" y2="96.52" width="0.1524" layer="91"/>
<pinref part="SV1" gate="1" pin="4"/>
<wire x1="157.48" y1="96.52" x2="157.48" y2="106.68" width="0.1524" layer="91"/>
<wire x1="157.48" y1="106.68" x2="170.18" y2="106.68" width="0.1524" layer="91"/>
<label x="160.02" y="106.68" size="1.778" layer="95"/>
</segment>
</net>
<net name="BUZZER" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D33"/>
<pinref part="SG2" gate="G$1" pin="1"/>
<wire x1="144.78" y1="93.98" x2="165.1" y2="93.98" width="0.1524" layer="91"/>
<wire x1="165.1" y1="93.98" x2="165.1" y2="91.44" width="0.1524" layer="91"/>
<label x="154.94" y="93.98" size="1.778" layer="95"/>
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
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
