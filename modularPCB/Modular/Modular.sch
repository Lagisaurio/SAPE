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
<library name="Act4_classroom">
<packages>
<package name="ESP32-S3-WROOM-1-N16">
<smd name="1" x="-8.75" y="8.895" dx="1.778" dy="0.9144" layer="1"/>
<smd name="2" x="-8.75" y="7.625" dx="1.778" dy="0.9144" layer="1"/>
<smd name="3" x="-8.75" y="6.355" dx="1.778" dy="0.9144" layer="1"/>
<smd name="4" x="-8.75" y="5.085" dx="1.778" dy="0.9144" layer="1"/>
<smd name="5" x="-8.75" y="3.815" dx="1.778" dy="0.9144" layer="1"/>
<smd name="6" x="-8.75" y="2.545" dx="1.778" dy="0.9144" layer="1"/>
<smd name="7" x="-8.75" y="1.275" dx="1.778" dy="0.9144" layer="1"/>
<smd name="8" x="-8.75" y="0.005" dx="1.778" dy="0.9144" layer="1"/>
<smd name="9" x="-8.75" y="-1.265" dx="1.778" dy="0.9144" layer="1"/>
<smd name="10" x="-8.75" y="-2.535" dx="1.778" dy="0.9144" layer="1"/>
<smd name="11" x="-8.75" y="-3.805" dx="1.778" dy="0.9144" layer="1"/>
<smd name="12" x="-8.75" y="-5.075" dx="1.778" dy="0.9144" layer="1"/>
<smd name="13" x="-8.75" y="-6.345" dx="1.778" dy="0.9144" layer="1"/>
<smd name="14" x="-8.75" y="-7.615" dx="1.778" dy="0.9144" layer="1"/>
<smd name="40" x="8.75" y="8.895" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="39" x="8.75" y="7.625" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="38" x="8.75" y="6.355" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="37" x="8.75" y="5.085" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="36" x="8.75" y="3.815" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="35" x="8.75" y="2.545" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="34" x="8.75" y="1.275" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="33" x="8.75" y="0.005" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="32" x="8.75" y="-1.265" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="31" x="8.75" y="-2.535" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="30" x="8.75" y="-3.805" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="29" x="8.75" y="-5.075" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="28" x="8.75" y="-6.345" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="27" x="8.75" y="-7.615" dx="1.5" dy="0.899996875" layer="1"/>
<smd name="15" x="-6.985" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="16" x="-5.715" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="17" x="-4.445" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="18" x="-3.175" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="19" x="-1.905" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="20" x="-0.635" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="21" x="0.635" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="22" x="1.905" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="23" x="3.175" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="24" x="4.445" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="25" x="5.715" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="26" x="6.985" y="-8.895" dx="1.5" dy="0.899996875" layer="1" rot="R90"/>
<smd name="41" x="-2.9" y="2.575" dx="0.899996875" dy="0.899996875" layer="1"/>
<smd name="42" x="-1.5" y="2.575" dx="0.899996875" dy="0.899996875" layer="1"/>
<smd name="43" x="-0.1" y="2.575" dx="0.899996875" dy="0.899996875" layer="1"/>
<smd name="44" x="-2.9" y="1.175" dx="0.899996875" dy="0.899996875" layer="1"/>
<smd name="45" x="-1.5" y="1.175" dx="0.899996875" dy="0.899996875" layer="1"/>
<smd name="46" x="-0.1" y="1.175" dx="0.899996875" dy="0.899996875" layer="1"/>
<smd name="47" x="-2.9" y="-0.225" dx="0.899996875" dy="0.899996875" layer="1"/>
<smd name="48" x="-1.5" y="-0.225" dx="0.899996875" dy="0.899996875" layer="1"/>
<smd name="49" x="-0.1" y="-0.225" dx="0.899996875" dy="0.899996875" layer="1"/>
<wire x1="-9" y1="-8.296" x2="-9" y2="-9.144" width="0.127" layer="21"/>
<wire x1="-9" y1="-9.144" x2="-7.666" y2="-9.144" width="0.127" layer="21"/>
<wire x1="9.017" y1="-8.296" x2="9.017" y2="-9.144" width="0.127" layer="21"/>
<wire x1="7.666" y1="-9.144" x2="9.017" y2="-9.144" width="0.127" layer="21"/>
<wire x1="-9" y1="16.395" x2="-9" y2="10.355" width="0.127" layer="21"/>
<wire x1="-9" y1="10.355" x2="-9" y2="9.576" width="0.127" layer="21"/>
<wire x1="9.017" y1="9.576" x2="9.017" y2="16.383" width="0.127" layer="21"/>
<wire x1="-9" y1="10.355" x2="5.265" y2="10.355" width="0.127" layer="21"/>
<wire x1="5.265" y1="10.355" x2="7.297" y2="10.355" width="0.127" layer="21"/>
<wire x1="7.297" y1="10.355" x2="9" y2="10.355" width="0.127" layer="21"/>
<wire x1="9" y1="16.395" x2="-9" y2="16.395" width="0.127" layer="21"/>
<wire x1="2.413" y1="13.081" x2="-0.127" y2="13.081" width="0.127" layer="21"/>
<wire x1="-0.127" y1="15.24" x2="-2.667" y2="15.24" width="0.127" layer="21"/>
<wire x1="-2.667" y1="13.081" x2="-4.953" y2="13.081" width="0.127" layer="21"/>
<wire x1="-4.953" y1="15.24" x2="-7.239" y2="15.24" width="0.127" layer="21"/>
<wire x1="5.062" y1="15.24" x2="2.413" y2="15.24" width="0.127" layer="21"/>
<wire x1="7.297" y1="15.24" x2="5.265" y2="15.24" width="0.127" layer="21"/>
<wire x1="5.265" y1="15.24" x2="5.062" y2="15.24" width="0.127" layer="21"/>
<wire x1="-7.239" y1="15.24" x2="-7.239" y2="11.557" width="0.127" layer="21"/>
<wire x1="-4.953" y1="13.081" x2="-4.953" y2="15.24" width="0.127" layer="21"/>
<wire x1="-2.667" y1="15.24" x2="-2.667" y2="13.081" width="0.127" layer="21"/>
<wire x1="-0.127" y1="13.081" x2="-0.127" y2="15.24" width="0.127" layer="21"/>
<wire x1="2.413" y1="15.24" x2="2.413" y2="13.081" width="0.127" layer="21"/>
<wire x1="5.265" y1="10.355" x2="5.265" y2="15.24" width="0.127" layer="21"/>
<wire x1="7.297" y1="10.355" x2="7.297" y2="15.24" width="0.127" layer="21"/>
<circle x="-10.4" y="8.9" radius="0.5099" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="ESP32-S3-WROOM-1-N16">
<wire x1="-12.7" y1="33.02" x2="-7.62" y2="33.02" width="0.254" layer="94"/>
<wire x1="-7.62" y1="33.02" x2="-7.62" y2="27.94" width="0.254" layer="94"/>
<wire x1="-7.62" y1="27.94" x2="0" y2="27.94" width="0.254" layer="94"/>
<wire x1="0" y1="27.94" x2="0" y2="33.02" width="0.254" layer="94"/>
<wire x1="0" y1="33.02" x2="2.54" y2="33.02" width="0.254" layer="94"/>
<wire x1="2.54" y1="33.02" x2="2.54" y2="27.94" width="0.254" layer="94"/>
<wire x1="2.54" y1="27.94" x2="7.62" y2="27.94" width="0.254" layer="94"/>
<wire x1="7.62" y1="27.94" x2="7.62" y2="33.02" width="0.254" layer="94"/>
<wire x1="7.62" y1="33.02" x2="15.24" y2="33.02" width="0.254" layer="94"/>
<wire x1="-12.7" y1="33.02" x2="-12.7" y2="25.4" width="0.254" layer="94"/>
<wire x1="-17.78" y1="22.86" x2="20.32" y2="22.86" width="0.254" layer="94"/>
<wire x1="20.32" y1="22.86" x2="20.32" y2="38.1" width="0.254" layer="94"/>
<wire x1="20.32" y1="38.1" x2="-17.78" y2="38.1" width="0.254" layer="94"/>
<wire x1="-17.78" y1="38.1" x2="-17.78" y2="22.86" width="0.254" layer="94"/>
<pin name="GND" x="-22.86" y="15.24" length="middle"/>
<pin name="3V3" x="-22.86" y="12.7" length="middle"/>
<pin name="EN" x="-22.86" y="10.16" length="middle"/>
<pin name="IO4" x="-22.86" y="7.62" length="middle"/>
<pin name="IO5" x="-22.86" y="5.08" length="middle"/>
<pin name="IO6" x="-22.86" y="2.54" length="middle"/>
<pin name="IO7" x="-22.86" y="0" length="middle"/>
<pin name="IO15" x="-22.86" y="-2.54" length="middle"/>
<pin name="IO16" x="-22.86" y="-5.08" length="middle"/>
<pin name="IO17" x="-22.86" y="-7.62" length="middle"/>
<pin name="IO18" x="-22.86" y="-10.16" length="middle"/>
<pin name="IO8" x="-22.86" y="-12.7" length="middle"/>
<pin name="IO19" x="-22.86" y="-15.24" length="middle"/>
<pin name="IO20" x="-22.86" y="-17.78" length="middle"/>
<pin name="IO3" x="-12.7" y="-33.02" length="middle" rot="R90"/>
<pin name="IO46" x="-10.16" y="-33.02" length="middle" rot="R90"/>
<pin name="IO9" x="-7.62" y="-33.02" length="middle" rot="R90"/>
<pin name="IO10" x="-5.08" y="-33.02" length="middle" rot="R90"/>
<pin name="IO11" x="-2.54" y="-33.02" length="middle" rot="R90"/>
<pin name="IO12" x="0" y="-33.02" length="middle" rot="R90"/>
<pin name="IO13" x="2.54" y="-33.02" length="middle" rot="R90"/>
<pin name="IO14" x="5.08" y="-33.02" length="middle" rot="R90"/>
<pin name="IO21" x="7.62" y="-33.02" length="middle" rot="R90"/>
<pin name="IO47" x="10.16" y="-33.02" length="middle" rot="R90"/>
<pin name="IO48" x="12.7" y="-33.02" length="middle" rot="R90"/>
<pin name="IO45" x="15.24" y="-33.02" length="middle" rot="R90"/>
<pin name="IO0" x="25.4" y="-17.78" length="middle" rot="R180"/>
<pin name="IO35" x="25.4" y="-15.24" length="middle" rot="R180"/>
<pin name="IO36" x="25.4" y="-12.7" length="middle" rot="R180"/>
<pin name="IO37" x="25.4" y="-10.16" length="middle" rot="R180"/>
<pin name="IO38" x="25.4" y="-7.62" length="middle" rot="R180"/>
<pin name="IO39" x="25.4" y="-5.08" length="middle" rot="R180"/>
<pin name="IO40" x="25.4" y="-2.54" length="middle" rot="R180"/>
<pin name="IO41" x="25.4" y="0" length="middle" rot="R180"/>
<pin name="IO42" x="25.4" y="2.54" length="middle" rot="R180"/>
<pin name="RXD0" x="25.4" y="5.08" length="middle" rot="R180"/>
<pin name="TXD0" x="25.4" y="7.62" length="middle" rot="R180"/>
<pin name="IO2" x="25.4" y="10.16" length="middle" rot="R180"/>
<pin name="IO1" x="25.4" y="12.7" length="middle" rot="R180"/>
<pin name="GND@0" x="25.4" y="15.24" length="middle" rot="R180"/>
<pin name="GND@1" x="25.4" y="17.78" length="middle" rot="R180"/>
<wire x1="-17.78" y1="22.86" x2="-17.78" y2="-27.94" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-27.94" x2="20.32" y2="-27.94" width="0.254" layer="94"/>
<wire x1="20.32" y1="-27.94" x2="20.32" y2="22.86" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ESP32-S3-WROOM-1-N16">
<gates>
<gate name="G$1" symbol="ESP32-S3-WROOM-1-N16" x="-2.54" y="22.86"/>
</gates>
<devices>
<device name="" package="ESP32-S3-WROOM-1-N16">
<connects>
<connect gate="G$1" pin="3V3" pad="2"/>
<connect gate="G$1" pin="EN" pad="3"/>
<connect gate="G$1" pin="GND" pad="1"/>
<connect gate="G$1" pin="GND@0" pad="40"/>
<connect gate="G$1" pin="GND@1" pad="41"/>
<connect gate="G$1" pin="IO0" pad="27"/>
<connect gate="G$1" pin="IO1" pad="39"/>
<connect gate="G$1" pin="IO10" pad="18"/>
<connect gate="G$1" pin="IO11" pad="19"/>
<connect gate="G$1" pin="IO12" pad="20"/>
<connect gate="G$1" pin="IO13" pad="21"/>
<connect gate="G$1" pin="IO14" pad="22"/>
<connect gate="G$1" pin="IO15" pad="8"/>
<connect gate="G$1" pin="IO16" pad="9"/>
<connect gate="G$1" pin="IO17" pad="10"/>
<connect gate="G$1" pin="IO18" pad="11"/>
<connect gate="G$1" pin="IO19" pad="13"/>
<connect gate="G$1" pin="IO2" pad="38"/>
<connect gate="G$1" pin="IO20" pad="14"/>
<connect gate="G$1" pin="IO21" pad="23"/>
<connect gate="G$1" pin="IO3" pad="15"/>
<connect gate="G$1" pin="IO35" pad="28"/>
<connect gate="G$1" pin="IO36" pad="29"/>
<connect gate="G$1" pin="IO37" pad="30"/>
<connect gate="G$1" pin="IO38" pad="31"/>
<connect gate="G$1" pin="IO39" pad="32"/>
<connect gate="G$1" pin="IO4" pad="4"/>
<connect gate="G$1" pin="IO40" pad="33"/>
<connect gate="G$1" pin="IO41" pad="34"/>
<connect gate="G$1" pin="IO42" pad="35"/>
<connect gate="G$1" pin="IO45" pad="26"/>
<connect gate="G$1" pin="IO46" pad="16"/>
<connect gate="G$1" pin="IO47" pad="24"/>
<connect gate="G$1" pin="IO48" pad="25"/>
<connect gate="G$1" pin="IO5" pad="5"/>
<connect gate="G$1" pin="IO6" pad="6"/>
<connect gate="G$1" pin="IO7" pad="7"/>
<connect gate="G$1" pin="IO8" pad="12"/>
<connect gate="G$1" pin="IO9" pad="17"/>
<connect gate="G$1" pin="RXD0" pad="36"/>
<connect gate="G$1" pin="TXD0" pad="37"/>
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
<part name="U$1" library="Act4_classroom" deviceset="ESP32-S3-WROOM-1-N16" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="-2.54" y="0" smashed="yes"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
<sheet>
<plain>
</plain>
<instances>
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
