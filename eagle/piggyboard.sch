<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.5.0">
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
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="200" name="200bmp" color="1" fill="10" visible="no" active="no"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="ATMega324P-piggy">
<packages>
<package name="TQFP-44">
<wire x1="-7.34" y1="8.21" x2="-6.94" y2="8.61" width="0.2032" layer="21"/>
<wire x1="-6.94" y1="8.61" x2="1.86" y2="8.61" width="0.2032" layer="21"/>
<wire x1="1.86" y1="8.61" x2="2.26" y2="8.21" width="0.2032" layer="21"/>
<wire x1="2.26" y1="8.21" x2="2.26" y2="-0.59" width="0.2032" layer="21"/>
<wire x1="2.26" y1="-0.59" x2="1.86" y2="-0.99" width="0.2032" layer="21"/>
<wire x1="1.86" y1="-0.99" x2="-6.94" y2="-0.99" width="0.2032" layer="21"/>
<wire x1="-6.94" y1="-0.99" x2="-7.34" y2="-0.59" width="0.2032" layer="21"/>
<wire x1="-7.34" y1="-0.59" x2="-7.34" y2="8.21" width="0.2032" layer="21"/>
<circle x="-6.54" y="7.81" radius="0.2827" width="0.254" layer="21"/>
<smd name="1" x="-8.34" y="7.81" dx="1.5" dy="0.5" layer="1"/>
<smd name="2" x="-8.34" y="7.01" dx="1.5" dy="0.5" layer="1"/>
<smd name="3" x="-8.34" y="6.21" dx="1.5" dy="0.5" layer="1"/>
<smd name="4" x="-8.34" y="5.41" dx="1.5" dy="0.5" layer="1"/>
<smd name="5" x="-8.34" y="4.61" dx="1.5" dy="0.5" layer="1"/>
<smd name="6" x="-8.34" y="3.81" dx="1.5" dy="0.5" layer="1"/>
<smd name="7" x="-8.34" y="3.01" dx="1.5" dy="0.5" layer="1"/>
<smd name="8" x="-8.34" y="2.21" dx="1.5" dy="0.5" layer="1"/>
<smd name="9" x="-8.34" y="1.41" dx="1.5" dy="0.5" layer="1"/>
<smd name="10" x="-8.34" y="0.61" dx="1.5" dy="0.5" layer="1"/>
<smd name="11" x="-8.34" y="-0.19" dx="1.5" dy="0.5" layer="1"/>
<smd name="12" x="-6.54" y="-1.99" dx="0.5" dy="1.5" layer="1"/>
<smd name="13" x="-5.74" y="-1.99" dx="0.5" dy="1.5" layer="1"/>
<smd name="14" x="-4.94" y="-1.99" dx="0.5" dy="1.5" layer="1"/>
<smd name="15" x="-4.14" y="-1.99" dx="0.5" dy="1.5" layer="1"/>
<smd name="16" x="-3.34" y="-1.99" dx="0.5" dy="1.5" layer="1"/>
<smd name="17" x="-2.54" y="-1.99" dx="0.5" dy="1.5" layer="1"/>
<smd name="18" x="-1.74" y="-1.99" dx="0.5" dy="1.5" layer="1"/>
<smd name="19" x="-0.94" y="-1.99" dx="0.5" dy="1.5" layer="1"/>
<smd name="20" x="-0.14" y="-1.99" dx="0.5" dy="1.5" layer="1"/>
<smd name="21" x="0.66" y="-1.99" dx="0.5" dy="1.5" layer="1"/>
<smd name="22" x="1.46" y="-1.99" dx="0.5" dy="1.5" layer="1"/>
<smd name="23" x="3.26" y="-0.19" dx="1.5" dy="0.5" layer="1"/>
<smd name="24" x="3.26" y="0.61" dx="1.5" dy="0.5" layer="1"/>
<smd name="25" x="3.26" y="1.41" dx="1.5" dy="0.5" layer="1"/>
<smd name="26" x="3.26" y="2.21" dx="1.5" dy="0.5" layer="1"/>
<smd name="27" x="3.26" y="3.01" dx="1.5" dy="0.5" layer="1"/>
<smd name="28" x="3.26" y="3.81" dx="1.5" dy="0.5" layer="1"/>
<smd name="29" x="3.26" y="4.61" dx="1.5" dy="0.5" layer="1"/>
<smd name="30" x="3.26" y="5.41" dx="1.5" dy="0.5" layer="1"/>
<smd name="31" x="3.26" y="6.21" dx="1.5" dy="0.5" layer="1"/>
<smd name="32" x="3.26" y="7.01" dx="1.5" dy="0.5" layer="1"/>
<smd name="33" x="3.26" y="7.81" dx="1.5" dy="0.5" layer="1"/>
<smd name="34" x="1.46" y="9.61" dx="0.5" dy="1.5" layer="1"/>
<smd name="35" x="0.66" y="9.61" dx="0.5" dy="1.5" layer="1"/>
<smd name="36" x="-0.14" y="9.61" dx="0.5" dy="1.5" layer="1"/>
<smd name="37" x="-0.94" y="9.61" dx="0.5" dy="1.5" layer="1"/>
<smd name="38" x="-1.74" y="9.61" dx="0.5" dy="1.5" layer="1"/>
<smd name="39" x="-2.54" y="9.61" dx="0.5" dy="1.5" layer="1"/>
<smd name="40" x="-3.34" y="9.61" dx="0.5" dy="1.5" layer="1"/>
<smd name="41" x="-4.14" y="9.61" dx="0.5" dy="1.5" layer="1"/>
<smd name="42" x="-4.94" y="9.61" dx="0.5" dy="1.5" layer="1"/>
<smd name="43" x="-5.74" y="9.61" dx="0.5" dy="1.5" layer="1"/>
<smd name="44" x="-6.54" y="9.61" dx="0.5" dy="1.5" layer="1"/>
<text x="14.732" y="18.796" size="1.778" layer="25" rot="R90">&gt;NAME</text>
<text x="14.4701" y="-20.574" size="1.778" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-8.6401" y1="7.6101" x2="-7.49" y2="8.0099" layer="51"/>
<rectangle x1="-8.6401" y1="6.81" x2="-7.49" y2="7.21" layer="51"/>
<rectangle x1="-8.6401" y1="6.0099" x2="-7.49" y2="6.4099" layer="51"/>
<rectangle x1="-8.6401" y1="5.21" x2="-7.49" y2="5.6101" layer="51"/>
<rectangle x1="-8.6401" y1="4.4099" x2="-7.49" y2="4.81" layer="51"/>
<rectangle x1="-8.6401" y1="3.6101" x2="-7.49" y2="4.0099" layer="51"/>
<rectangle x1="-8.6401" y1="2.81" x2="-7.49" y2="3.2101" layer="51"/>
<rectangle x1="-8.6401" y1="2.0099" x2="-7.49" y2="2.41" layer="51"/>
<rectangle x1="-8.6401" y1="1.2101" x2="-7.49" y2="1.6101" layer="51"/>
<rectangle x1="-8.6401" y1="0.41" x2="-7.49" y2="0.81" layer="51"/>
<rectangle x1="-8.6401" y1="-0.3899" x2="-7.49" y2="0.0099" layer="51"/>
<rectangle x1="-6.7399" y1="-2.2901" x2="-6.3401" y2="-1.14" layer="51"/>
<rectangle x1="-5.94" y1="-2.2901" x2="-5.54" y2="-1.14" layer="51"/>
<rectangle x1="-5.1399" y1="-2.2901" x2="-4.7399" y2="-1.14" layer="51"/>
<rectangle x1="-4.3401" y1="-2.2901" x2="-3.94" y2="-1.14" layer="51"/>
<rectangle x1="-3.54" y1="-2.2901" x2="-3.1399" y2="-1.14" layer="51"/>
<rectangle x1="-2.7399" y1="-2.2901" x2="-2.3401" y2="-1.14" layer="51"/>
<rectangle x1="-1.9401" y1="-2.2901" x2="-1.54" y2="-1.14" layer="51"/>
<rectangle x1="-1.14" y1="-2.2901" x2="-0.7399" y2="-1.14" layer="51"/>
<rectangle x1="-0.3401" y1="-2.2901" x2="0.0599" y2="-1.14" layer="51"/>
<rectangle x1="0.46" y1="-2.2901" x2="0.86" y2="-1.14" layer="51"/>
<rectangle x1="1.2601" y1="-2.2901" x2="1.6599" y2="-1.14" layer="51"/>
<rectangle x1="2.41" y1="-0.3899" x2="3.5601" y2="0.0099" layer="51"/>
<rectangle x1="2.41" y1="0.41" x2="3.5601" y2="0.81" layer="51"/>
<rectangle x1="2.41" y1="1.2101" x2="3.5601" y2="1.6101" layer="51"/>
<rectangle x1="2.41" y1="2.0099" x2="3.5601" y2="2.41" layer="51"/>
<rectangle x1="2.41" y1="2.81" x2="3.5601" y2="3.2101" layer="51"/>
<rectangle x1="2.41" y1="3.6101" x2="3.5601" y2="4.0099" layer="51"/>
<rectangle x1="2.41" y1="4.4099" x2="3.5601" y2="4.81" layer="51"/>
<rectangle x1="2.41" y1="5.21" x2="3.5601" y2="5.6101" layer="51"/>
<rectangle x1="2.41" y1="6.0099" x2="3.5601" y2="6.4099" layer="51"/>
<rectangle x1="2.41" y1="6.81" x2="3.5601" y2="7.21" layer="51"/>
<rectangle x1="2.41" y1="7.6101" x2="3.5601" y2="8.0099" layer="51"/>
<rectangle x1="1.2601" y1="8.76" x2="1.6599" y2="9.9101" layer="51"/>
<rectangle x1="0.46" y1="8.76" x2="0.86" y2="9.9101" layer="51"/>
<rectangle x1="-0.3401" y1="8.76" x2="0.0599" y2="9.9101" layer="51"/>
<rectangle x1="-1.14" y1="8.76" x2="-0.7399" y2="9.9101" layer="51"/>
<rectangle x1="-1.9401" y1="8.76" x2="-1.54" y2="9.9101" layer="51"/>
<rectangle x1="-2.7399" y1="8.76" x2="-2.3401" y2="9.9101" layer="51"/>
<rectangle x1="-3.54" y1="8.76" x2="-3.1399" y2="9.9101" layer="51"/>
<rectangle x1="-4.3401" y1="8.76" x2="-3.94" y2="9.9101" layer="51"/>
<rectangle x1="-5.1399" y1="8.76" x2="-4.7399" y2="9.9101" layer="51"/>
<rectangle x1="-5.94" y1="8.76" x2="-5.54" y2="9.9101" layer="51"/>
<rectangle x1="-6.7399" y1="8.76" x2="-6.3401" y2="9.9101" layer="51"/>
<wire x1="-20.32" y1="27.94" x2="-20.32" y2="-27.94" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-27.94" x2="15.24" y2="-27.94" width="0.127" layer="21"/>
<wire x1="15.24" y1="-27.94" x2="15.24" y2="27.94" width="0.127" layer="21"/>
<wire x1="15.24" y1="27.94" x2="-20.32" y2="27.94" width="0.127" layer="21"/>
<wire x1="-8.89" y1="3.81" x2="-16.51" y2="3.81" width="0.3048" layer="1"/>
<wire x1="-16.51" y1="3.81" x2="-16.51" y2="3.175" width="0.3048" layer="1"/>
<wire x1="-16.51" y1="3.175" x2="-18.542" y2="3.175" width="0.3048" layer="1"/>
<wire x1="-8.89" y1="6.9596" x2="-11.43" y2="6.9596" width="0.3048" layer="1"/>
<wire x1="-11.43" y1="6.9596" x2="-11.43" y2="13.335" width="0.3048" layer="1"/>
<wire x1="-11.43" y1="13.335" x2="-18.542" y2="13.335" width="0.3048" layer="1"/>
<wire x1="-8.89" y1="7.7724" x2="-10.16" y2="7.7724" width="0.3048" layer="1"/>
<wire x1="-10.16" y1="7.7724" x2="-10.16" y2="15.875" width="0.3048" layer="1"/>
<wire x1="-10.16" y1="15.875" x2="-18.542" y2="15.875" width="0.3048" layer="1"/>
<wire x1="-8.89" y1="6.1722" x2="-12.7" y2="6.1722" width="0.3048" layer="1"/>
<wire x1="-12.7" y1="6.1722" x2="-12.7" y2="10.795" width="0.3048" layer="1"/>
<wire x1="-12.7" y1="10.795" x2="-18.542" y2="10.795" width="0.3048" layer="1"/>
<wire x1="-8.89" y1="5.3594" x2="-13.97" y2="5.3594" width="0.3048" layer="1"/>
<wire x1="-13.97" y1="5.3594" x2="-13.97" y2="8.255" width="0.3048" layer="1"/>
<wire x1="-13.97" y1="8.255" x2="-18.542" y2="8.255" width="0.3048" layer="1"/>
<wire x1="-8.89" y1="4.572" x2="-15.24" y2="4.572" width="0.3048" layer="1"/>
<wire x1="-15.24" y1="4.572" x2="-15.24" y2="5.715" width="0.3048" layer="1"/>
<wire x1="-15.24" y1="5.715" x2="-18.542" y2="5.715" width="0.3048" layer="1"/>
<wire x1="-8.89" y1="2.921" x2="-15.24" y2="2.921" width="0.3048" layer="1"/>
<wire x1="-15.24" y1="2.921" x2="-15.24" y2="0.635" width="0.3048" layer="1"/>
<wire x1="-15.24" y1="0.635" x2="-18.542" y2="0.635" width="0.3048" layer="1"/>
<wire x1="-8.89" y1="-0.1524" x2="-10.16" y2="-0.1524" width="0.3048" layer="1"/>
<wire x1="-10.16" y1="-0.1524" x2="-10.16" y2="-9.525" width="0.3048" layer="1"/>
<wire x1="-10.16" y1="-9.525" x2="-18.542" y2="-9.525" width="0.3048" layer="1"/>
<wire x1="-8.89" y1="0.5842" x2="-11.43" y2="0.5842" width="0.3048" layer="1"/>
<wire x1="-11.43" y1="0.5842" x2="-11.43" y2="-6.985" width="0.3048" layer="1"/>
<wire x1="-11.43" y1="-6.985" x2="-18.542" y2="-6.985" width="0.3048" layer="1"/>
<wire x1="-8.89" y1="1.3716" x2="-12.7" y2="1.3716" width="0.3048" layer="1"/>
<wire x1="-12.7" y1="1.3716" x2="-12.7" y2="-4.445" width="0.3048" layer="1"/>
<wire x1="-12.7" y1="-4.445" x2="-18.542" y2="-4.445" width="0.3048" layer="1"/>
<wire x1="-8.89" y1="2.1844" x2="-13.97" y2="2.1844" width="0.3048" layer="1"/>
<wire x1="-13.97" y1="2.1844" x2="-13.97" y2="-1.905" width="0.3048" layer="1"/>
<wire x1="-13.97" y1="-1.905" x2="-18.542" y2="-1.905" width="0.3048" layer="1"/>
<wire x1="3.81" y1="7.7724" x2="5.08" y2="7.7724" width="0.3048" layer="1"/>
<wire x1="5.08" y1="7.7724" x2="5.08" y2="15.9004" width="0.3048" layer="1"/>
<wire x1="5.08" y1="15.9004" x2="13.462" y2="15.875" width="0.3048" layer="1"/>
<wire x1="3.81" y1="6.9596" x2="6.35" y2="6.9596" width="0.3048" layer="1"/>
<wire x1="6.35" y1="6.9596" x2="6.35" y2="13.335" width="0.3048" layer="1"/>
<wire x1="6.35" y1="13.335" x2="13.462" y2="13.335" width="0.3048" layer="1"/>
<wire x1="3.81" y1="-0.1524" x2="5.08" y2="-0.1524" width="0.3048" layer="1"/>
<wire x1="5.08" y1="-0.1524" x2="5.08" y2="-9.525" width="0.3048" layer="1"/>
<wire x1="5.08" y1="-9.525" x2="13.462" y2="-9.525" width="0.3048" layer="1"/>
<wire x1="3.81" y1="0.5842" x2="6.35" y2="0.5842" width="0.3048" layer="1"/>
<wire x1="6.35" y1="0.5842" x2="6.35" y2="-6.985" width="0.3048" layer="1"/>
<wire x1="6.35" y1="-6.985" x2="13.462" y2="-6.985" width="0.3048" layer="1"/>
<wire x1="3.81" y1="1.3716" x2="7.62" y2="1.3716" width="0.3048" layer="1"/>
<wire x1="7.62" y1="1.3716" x2="7.62" y2="-4.445" width="0.3048" layer="1"/>
<wire x1="7.62" y1="-4.445" x2="13.462" y2="-4.445" width="0.3048" layer="1"/>
<wire x1="3.81" y1="2.1844" x2="8.89" y2="2.1844" width="0.3048" layer="1"/>
<wire x1="8.89" y1="2.1844" x2="8.89" y2="-1.905" width="0.3048" layer="1"/>
<wire x1="8.89" y1="-1.905" x2="13.462" y2="-1.905" width="0.3048" layer="1"/>
<wire x1="3.81" y1="6.1722" x2="7.62" y2="6.1722" width="0.3048" layer="1"/>
<wire x1="7.62" y1="6.1722" x2="7.62" y2="10.7696" width="0.3048" layer="1"/>
<wire x1="7.62" y1="10.7696" x2="13.462" y2="10.795" width="0.3048" layer="1"/>
<wire x1="3.81" y1="5.3594" x2="8.89" y2="5.3594" width="0.3048" layer="1"/>
<wire x1="8.89" y1="5.3594" x2="8.89" y2="8.255" width="0.3048" layer="1"/>
<wire x1="8.89" y1="8.255" x2="13.462" y2="8.255" width="0.3048" layer="1"/>
<wire x1="3.81" y1="4.572" x2="10.16" y2="4.572" width="0.3048" layer="1"/>
<wire x1="10.16" y1="4.572" x2="10.16" y2="5.715" width="0.3048" layer="1"/>
<wire x1="10.16" y1="5.715" x2="13.462" y2="5.715" width="0.3048" layer="1"/>
<wire x1="3.81" y1="2.921" x2="10.16" y2="2.921" width="0.3048" layer="1"/>
<wire x1="10.16" y1="2.921" x2="10.16" y2="0.635" width="0.3048" layer="1"/>
<wire x1="10.16" y1="0.635" x2="13.462" y2="0.635" width="0.3048" layer="1"/>
<wire x1="3.81" y1="3.81" x2="11.43" y2="3.81" width="0.3048" layer="1"/>
<wire x1="11.43" y1="3.81" x2="11.43" y2="3.175" width="0.3048" layer="1"/>
<wire x1="11.43" y1="3.175" x2="13.462" y2="3.175" width="0.3048" layer="1"/>
<wire x1="-6.5024" y1="-2.54" x2="-6.5024" y2="-11.43" width="0.3048" layer="1"/>
<wire x1="-6.5024" y1="-11.43" x2="-15.875" y2="-11.43" width="0.3048" layer="1"/>
<wire x1="-15.875" y1="-11.43" x2="-15.875" y2="-26.162" width="0.3048" layer="1"/>
<wire x1="1.4732" y1="-2.54" x2="1.4732" y2="-11.43" width="0.3048" layer="1"/>
<wire x1="1.4732" y1="-11.43" x2="9.525" y2="-11.43" width="0.3048" layer="1"/>
<wire x1="9.525" y1="-11.43" x2="9.525" y2="-26.162" width="0.3048" layer="1"/>
<wire x1="-5.6896" y1="-2.54" x2="-5.6896" y2="-12.7" width="0.3048" layer="1"/>
<wire x1="-5.6896" y1="-12.7" x2="-13.335" y2="-12.7" width="0.3048" layer="1"/>
<wire x1="-13.335" y1="-12.7" x2="-13.335" y2="-26.162" width="0.3048" layer="1"/>
<wire x1="0.6604" y1="-2.54" x2="0.6604" y2="-12.7" width="0.3048" layer="1"/>
<wire x1="0.6604" y1="-12.7" x2="6.985" y2="-12.7" width="0.3048" layer="1"/>
<wire x1="6.985" y1="-12.7" x2="6.985" y2="-26.162" width="0.3048" layer="1"/>
<wire x1="-4.9022" y1="-2.54" x2="-4.9022" y2="-13.97" width="0.3048" layer="1"/>
<wire x1="-4.9022" y1="-13.97" x2="-10.795" y2="-13.97" width="0.3048" layer="1"/>
<wire x1="-10.795" y1="-13.97" x2="-10.795" y2="-26.162" width="0.3048" layer="1"/>
<wire x1="-0.1016" y1="-2.54" x2="-0.1016" y2="-13.97" width="0.3048" layer="1"/>
<wire x1="-0.1016" y1="-13.97" x2="4.445" y2="-13.97" width="0.3048" layer="1"/>
<wire x1="4.445" y1="-13.97" x2="4.445" y2="-26.162" width="0.3048" layer="1"/>
<wire x1="-4.0894" y1="-2.54" x2="-4.0894" y2="-15.24" width="0.3048" layer="1"/>
<wire x1="-4.0894" y1="-15.24" x2="-8.255" y2="-15.24" width="0.3048" layer="1"/>
<wire x1="-8.255" y1="-15.24" x2="-8.255" y2="-26.162" width="0.3048" layer="1"/>
<wire x1="-0.9652" y1="-2.54" x2="-0.9652" y2="-15.24" width="0.3048" layer="1"/>
<wire x1="-0.9652" y1="-15.24" x2="1.905" y2="-15.24" width="0.3048" layer="1"/>
<wire x1="1.905" y1="-15.24" x2="1.905" y2="-26.162" width="0.3048" layer="1"/>
<wire x1="-3.302" y1="-2.54" x2="-3.302" y2="-16.51" width="0.3048" layer="1"/>
<wire x1="-3.302" y1="-16.51" x2="-5.715" y2="-16.51" width="0.3048" layer="1"/>
<wire x1="-5.715" y1="-16.51" x2="-5.715" y2="-26.162" width="0.3048" layer="1"/>
<wire x1="-1.7018" y1="-2.54" x2="-1.7018" y2="-16.51" width="0.3048" layer="1"/>
<wire x1="-1.7018" y1="-16.51" x2="-0.635" y2="-16.51" width="0.3048" layer="1"/>
<wire x1="-0.635" y1="-16.51" x2="-0.635" y2="-26.162" width="0.3048" layer="1"/>
<wire x1="-3.175" y1="-26.162" x2="-3.175" y2="-17.78" width="0.3048" layer="1"/>
<wire x1="-3.175" y1="-17.78" x2="-2.54" y2="-17.78" width="0.3048" layer="1"/>
<wire x1="-2.54" y1="-17.78" x2="-2.54" y2="-2.54" width="0.3048" layer="1"/>
<wire x1="-6.5024" y1="10.16" x2="-6.5024" y2="17.78" width="0.3048" layer="1"/>
<wire x1="-6.5024" y1="17.78" x2="-15.875" y2="17.78" width="0.3048" layer="1"/>
<wire x1="-15.875" y1="17.78" x2="-15.875" y2="26.162" width="0.3048" layer="1"/>
<wire x1="-5.6896" y1="10.16" x2="-5.6896" y2="19.05" width="0.3048" layer="1"/>
<wire x1="-5.6896" y1="19.05" x2="-13.335" y2="19.05" width="0.3048" layer="1"/>
<wire x1="-13.335" y1="19.05" x2="-13.335" y2="26.162" width="0.3048" layer="1"/>
<wire x1="1.4732" y1="10.16" x2="1.4732" y2="17.78" width="0.3048" layer="1"/>
<wire x1="1.4732" y1="17.78" x2="9.525" y2="17.78" width="0.3048" layer="1"/>
<wire x1="9.525" y1="17.78" x2="9.525" y2="26.162" width="0.3048" layer="1"/>
<wire x1="0.6604" y1="10.16" x2="0.6604" y2="19.05" width="0.3048" layer="1"/>
<wire x1="0.6604" y1="19.05" x2="6.985" y2="19.05" width="0.3048" layer="1"/>
<wire x1="6.985" y1="19.05" x2="6.985" y2="26.162" width="0.3048" layer="1"/>
<wire x1="-4.9022" y1="10.16" x2="-4.9022" y2="20.32" width="0.3048" layer="1"/>
<wire x1="-4.9022" y1="20.32" x2="-10.795" y2="20.32" width="0.3048" layer="1"/>
<wire x1="-10.795" y1="20.32" x2="-10.795" y2="26.162" width="0.3048" layer="1"/>
<wire x1="-0.1016" y1="10.16" x2="-0.1016" y2="20.32" width="0.3048" layer="1"/>
<wire x1="-0.1016" y1="20.32" x2="4.445" y2="20.32" width="0.3048" layer="1"/>
<wire x1="4.445" y1="20.32" x2="4.445" y2="26.162" width="0.3048" layer="1"/>
<wire x1="-4.0894" y1="10.16" x2="-4.0894" y2="21.59" width="0.3048" layer="1"/>
<wire x1="-4.0894" y1="21.59" x2="-8.255" y2="21.59" width="0.3048" layer="1"/>
<wire x1="-8.255" y1="21.59" x2="-8.255" y2="26.162" width="0.3048" layer="1"/>
<wire x1="-3.302" y1="10.16" x2="-3.302" y2="22.86" width="0.3048" layer="1"/>
<wire x1="-3.302" y1="22.86" x2="-5.715" y2="22.86" width="0.3048" layer="1"/>
<wire x1="-5.715" y1="22.86" x2="-5.715" y2="26.162" width="0.3048" layer="1"/>
<wire x1="-0.9652" y1="10.16" x2="-0.9652" y2="21.59" width="0.3048" layer="1"/>
<wire x1="-0.9652" y1="21.59" x2="1.905" y2="21.59" width="0.3048" layer="1"/>
<wire x1="1.905" y1="21.59" x2="1.905" y2="26.162" width="0.3048" layer="1"/>
<wire x1="-2.54" y1="10.16" x2="-2.54" y2="24.13" width="0.3048" layer="1"/>
<wire x1="-2.54" y1="24.13" x2="-3.175" y2="24.13" width="0.3048" layer="1"/>
<wire x1="-3.175" y1="24.13" x2="-3.175" y2="26.162" width="0.3048" layer="1"/>
<wire x1="-1.7018" y1="10.16" x2="-1.7018" y2="22.86" width="0.3048" layer="1"/>
<wire x1="-1.7018" y1="22.86" x2="-0.635" y2="22.86" width="0.3048" layer="1"/>
<wire x1="-0.635" y1="22.86" x2="-0.635" y2="26.162" width="0.3048" layer="1"/>
<text x="-17.78" y="-24.13" size="1.27" layer="21" rot="R90">PIGGY BOARD</text>
<pad name="P$1" x="-15.875" y="27.051" drill="1" shape="offset" rot="R270"/>
<pad name="P$2" x="-13.335" y="27.051" drill="1" shape="offset" rot="R270"/>
<pad name="P$3" x="-10.795" y="27.051" drill="1" shape="offset" rot="R270"/>
<pad name="P$4" x="-8.255" y="27.051" drill="1" shape="offset" rot="R270"/>
<pad name="P$5" x="-5.715" y="27.051" drill="1" shape="offset" rot="R270"/>
<pad name="P$6" x="-3.175" y="27.051" drill="1" shape="offset" rot="R270"/>
<pad name="P$7" x="-0.635" y="27.051" drill="1" shape="offset" rot="R270"/>
<pad name="P$8" x="1.905" y="27.051" drill="1" shape="offset" rot="R270"/>
<pad name="P$9" x="4.445" y="27.051" drill="1" shape="offset" rot="R270"/>
<pad name="P$10" x="6.985" y="27.051" drill="1" shape="offset" rot="R270"/>
<pad name="P$11" x="9.525" y="27.051" drill="1" shape="offset" rot="R270"/>
<pad name="P$12" x="9.525" y="-27.051" drill="1" shape="offset" rot="R90"/>
<pad name="P$13" x="6.985" y="-27.051" drill="1" shape="offset" rot="R90"/>
<pad name="P$14" x="4.445" y="-27.051" drill="1" shape="offset" rot="R90"/>
<pad name="P$15" x="1.905" y="-27.051" drill="1" shape="offset" rot="R90"/>
<pad name="P$16" x="-0.635" y="-27.051" drill="1" shape="offset" rot="R90"/>
<pad name="P$17" x="-3.175" y="-27.051" drill="1" shape="offset" rot="R90"/>
<pad name="P$18" x="-5.715" y="-27.051" drill="1" shape="offset" rot="R90"/>
<pad name="P$19" x="-8.255" y="-27.051" drill="1" shape="offset" rot="R90"/>
<pad name="P$20" x="-10.795" y="-27.051" drill="1" shape="offset" rot="R90"/>
<pad name="P$21" x="-13.335" y="-27.051" drill="1" shape="offset" rot="R90"/>
<pad name="P$22" x="-15.875" y="-27.051" drill="1" shape="offset" rot="R90"/>
<pad name="P$23" x="-19.431" y="15.875" drill="1" shape="offset"/>
<pad name="P$24" x="-19.431" y="13.335" drill="1" shape="offset"/>
<pad name="P$25" x="-19.431" y="10.795" drill="1" shape="offset"/>
<pad name="P$26" x="-19.431" y="8.255" drill="1" shape="offset"/>
<pad name="P$27" x="-19.431" y="5.715" drill="1" shape="offset"/>
<pad name="P$28" x="-19.431" y="3.175" drill="1" shape="offset"/>
<pad name="P$29" x="-19.431" y="0.635" drill="1" shape="offset"/>
<pad name="P$30" x="-19.431" y="-1.905" drill="1" shape="offset"/>
<pad name="P$31" x="-19.431" y="-4.445" drill="1" shape="offset"/>
<pad name="P$32" x="-19.431" y="-6.985" drill="1" shape="offset"/>
<pad name="P$33" x="-19.431" y="-9.525" drill="1" shape="offset"/>
<pad name="P$34" x="14.351" y="15.875" drill="1" shape="offset" rot="R180"/>
<pad name="P$35" x="14.351" y="13.335" drill="1" shape="offset" rot="R180"/>
<pad name="P$36" x="14.351" y="10.795" drill="1" shape="offset" rot="R180"/>
<pad name="P$37" x="14.351" y="8.255" drill="1" shape="offset" rot="R180"/>
<pad name="P$38" x="14.351" y="5.715" drill="1" shape="offset" rot="R180"/>
<pad name="P$39" x="14.351" y="3.175" drill="1" shape="offset" rot="R180"/>
<pad name="P$40" x="14.351" y="0.635" drill="1" shape="offset" rot="R180"/>
<pad name="P$41" x="14.351" y="-1.905" drill="1" shape="offset" rot="R180"/>
<pad name="P$42" x="14.351" y="-4.445" drill="1" shape="offset" rot="R180"/>
<pad name="P$43" x="14.351" y="-6.985" drill="1" shape="offset" rot="R180"/>
<pad name="P$44" x="14.351" y="-9.525" drill="1" shape="offset" rot="R180"/>
</package>
</packages>
<symbols>
<symbol name="ATMEGA324P">
<wire x1="-22.86" y1="43.18" x2="22.86" y2="43.18" width="0.254" layer="94"/>
<wire x1="22.86" y1="43.18" x2="22.86" y2="-48.26" width="0.254" layer="94"/>
<wire x1="22.86" y1="-48.26" x2="-22.86" y2="-48.26" width="0.254" layer="94"/>
<wire x1="-22.86" y1="-48.26" x2="-22.86" y2="43.18" width="0.254" layer="94"/>
<text x="5.08" y="43.942" size="1.778" layer="95">&gt;NAME</text>
<text x="5.08" y="-53.34" size="1.778" layer="96">&gt;VALUE</text>
<pin name="(ADC7)PA7" x="27.94" y="40.64" length="middle" rot="R180"/>
<pin name="(ADC6)PA6" x="27.94" y="38.1" length="middle" rot="R180"/>
<pin name="(ADC5)PA5" x="27.94" y="35.56" length="middle" rot="R180"/>
<pin name="(ADC4)PA4" x="27.94" y="33.02" length="middle" rot="R180"/>
<pin name="(ADC3)PA3" x="27.94" y="30.48" length="middle" rot="R180"/>
<pin name="(ADC2)PA2" x="27.94" y="27.94" length="middle" rot="R180"/>
<pin name="(ADC1)PA1" x="27.94" y="25.4" length="middle" rot="R180"/>
<pin name="(ADC0)PA0" x="27.94" y="22.86" length="middle" rot="R180"/>
<pin name="(SCK)PB7" x="27.94" y="17.78" length="middle" rot="R180"/>
<pin name="(MISO)PB6" x="27.94" y="15.24" length="middle" rot="R180"/>
<pin name="(MOSI)PB5" x="27.94" y="12.7" length="middle" rot="R180"/>
<pin name="(SS)PB4" x="27.94" y="10.16" length="middle" rot="R180"/>
<pin name="(AIN1/OC0)PB3" x="27.94" y="7.62" length="middle" rot="R180"/>
<pin name="(AIN0/INT2)PB2" x="27.94" y="5.08" length="middle" rot="R180"/>
<pin name="(T1)PB1" x="27.94" y="2.54" length="middle" rot="R180"/>
<pin name="(T0/XCK0)PB0" x="27.94" y="0" length="middle" rot="R180"/>
<pin name="(TOSC2)PC7" x="27.94" y="-5.08" length="middle" rot="R180"/>
<pin name="(TOSC1)PC6" x="27.94" y="-7.62" length="middle" rot="R180"/>
<pin name="(TDI)PC5" x="27.94" y="-10.16" length="middle" rot="R180"/>
<pin name="(TDO)PC4" x="27.94" y="-12.7" length="middle" rot="R180"/>
<pin name="(TMS)PC3" x="27.94" y="-15.24" length="middle" rot="R180"/>
<pin name="(TCK)PC2" x="27.94" y="-17.78" length="middle" rot="R180"/>
<pin name="PC1(SDA)" x="27.94" y="-20.32" length="middle" rot="R180"/>
<pin name="PC0(SCL)" x="27.94" y="-22.86" length="middle" rot="R180"/>
<pin name="GND4" x="0" y="-53.34" length="middle" rot="R90"/>
<pin name="AVCC" x="0" y="48.26" length="middle" rot="R270"/>
<pin name="AREF" x="-27.94" y="10.16" length="middle" direction="pas"/>
<pin name="XTAL1" x="-27.94" y="20.32" length="middle"/>
<pin name="XTAL2" x="-27.94" y="30.48" length="middle"/>
<pin name="GND2" x="-5.08" y="-53.34" length="middle" rot="R90"/>
<pin name="GND3" x="-2.54" y="-53.34" length="middle" rot="R90"/>
<pin name="RESET" x="-27.94" y="40.64" length="middle" direction="in" function="dot"/>
<pin name="(RXD0)PD0" x="27.94" y="-45.72" length="middle" rot="R180"/>
<pin name="(TXD0)PD1" x="27.94" y="-43.18" length="middle" rot="R180"/>
<pin name="(INT0)PD2" x="27.94" y="-40.64" length="middle" rot="R180"/>
<pin name="(INT1)PD3" x="27.94" y="-38.1" length="middle" rot="R180"/>
<pin name="(OC1B)PD4" x="27.94" y="-35.56" length="middle" rot="R180"/>
<pin name="(OC1A)PD5" x="27.94" y="-33.02" length="middle" rot="R180"/>
<pin name="(ICP)PD6" x="27.94" y="-30.48" length="middle" rot="R180"/>
<pin name="(OC2A)PD7" x="27.94" y="-27.94" length="middle" rot="R180"/>
<pin name="VCC3" x="-2.54" y="48.26" length="middle" rot="R270"/>
<pin name="VCC2" x="-5.08" y="48.26" length="middle" rot="R270"/>
<pin name="VCC1" x="-7.62" y="48.26" length="middle" rot="R270"/>
<pin name="GND1" x="-7.62" y="-53.34" length="middle" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ATMEGA324P">
<gates>
<gate name="G$1" symbol="ATMEGA324P" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TQFP-44">
<connects>
<connect gate="G$1" pin="(ADC0)PA0" pad="37 P$1 P$2 P$3 P$4 P$5 P$6 P$7 P$8 P$9 P$10 P$11 P$12 P$13 P$14 P$15 P$16 P$17 P$18 P$19 P$20 P$21 P$22 P$23 P$24 P$25 P$26 P$27 P$28 P$29 P$30 P$31 P$32 P$33 P$34 P$35 P$36 P$37 P$38 P$39 P$40 P$41 P$42 P$43 P$44"/>
<connect gate="G$1" pin="(ADC1)PA1" pad="36"/>
<connect gate="G$1" pin="(ADC2)PA2" pad="35"/>
<connect gate="G$1" pin="(ADC3)PA3" pad="34"/>
<connect gate="G$1" pin="(ADC4)PA4" pad="33"/>
<connect gate="G$1" pin="(ADC5)PA5" pad="32"/>
<connect gate="G$1" pin="(ADC6)PA6" pad="31"/>
<connect gate="G$1" pin="(ADC7)PA7" pad="30"/>
<connect gate="G$1" pin="(AIN0/INT2)PB2" pad="42"/>
<connect gate="G$1" pin="(AIN1/OC0)PB3" pad="43"/>
<connect gate="G$1" pin="(ICP)PD6" pad="15"/>
<connect gate="G$1" pin="(INT0)PD2" pad="11"/>
<connect gate="G$1" pin="(INT1)PD3" pad="12"/>
<connect gate="G$1" pin="(MISO)PB6" pad="2"/>
<connect gate="G$1" pin="(MOSI)PB5" pad="1"/>
<connect gate="G$1" pin="(OC1A)PD5" pad="14"/>
<connect gate="G$1" pin="(OC1B)PD4" pad="13"/>
<connect gate="G$1" pin="(OC2A)PD7" pad="16"/>
<connect gate="G$1" pin="(RXD0)PD0" pad="9"/>
<connect gate="G$1" pin="(SCK)PB7" pad="3"/>
<connect gate="G$1" pin="(SS)PB4" pad="44"/>
<connect gate="G$1" pin="(T0/XCK0)PB0" pad="40"/>
<connect gate="G$1" pin="(T1)PB1" pad="41"/>
<connect gate="G$1" pin="(TCK)PC2" pad="21"/>
<connect gate="G$1" pin="(TDI)PC5" pad="24"/>
<connect gate="G$1" pin="(TDO)PC4" pad="23"/>
<connect gate="G$1" pin="(TMS)PC3" pad="22"/>
<connect gate="G$1" pin="(TOSC1)PC6" pad="25"/>
<connect gate="G$1" pin="(TOSC2)PC7" pad="26"/>
<connect gate="G$1" pin="(TXD0)PD1" pad="10"/>
<connect gate="G$1" pin="AREF" pad="29"/>
<connect gate="G$1" pin="AVCC" pad="27"/>
<connect gate="G$1" pin="GND1" pad="6"/>
<connect gate="G$1" pin="GND2" pad="18"/>
<connect gate="G$1" pin="GND3" pad="28"/>
<connect gate="G$1" pin="GND4" pad="39"/>
<connect gate="G$1" pin="PC0(SCL)" pad="19"/>
<connect gate="G$1" pin="PC1(SDA)" pad="20"/>
<connect gate="G$1" pin="RESET" pad="4"/>
<connect gate="G$1" pin="VCC1" pad="38"/>
<connect gate="G$1" pin="VCC2" pad="5"/>
<connect gate="G$1" pin="VCC3" pad="17"/>
<connect gate="G$1" pin="XTAL1" pad="8"/>
<connect gate="G$1" pin="XTAL2" pad="7"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="hirosemicrosd-piggy">
<packages>
<package name="HIROSE-MICROSD-V2">
<wire x1="-1.27" y1="-1.27" x2="12.58" y2="-1.27" width="0.127" layer="21"/>
<wire x1="12.58" y1="-1.27" x2="12.58" y2="14.68" width="0.127" layer="21"/>
<wire x1="12.58" y1="14.68" x2="-1.27" y2="14.68" width="0.127" layer="21"/>
<wire x1="-1.27" y1="14.68" x2="-1.27" y2="-1.27" width="0.127" layer="21"/>
<smd name="CDS-B" x="-0.17" y="14.68" dx="0.7" dy="1.2" layer="1"/>
<rectangle x1="-1.52" y1="11.08" x2="-0.77" y2="14.33" layer="39"/>
<smd name="DAT2" x="8.48" y="14.68" dx="0.7" dy="1.2" layer="1"/>
<smd name="CD/DAT3" x="7.38" y="14.68" dx="0.7" dy="1.2" layer="1"/>
<smd name="CMD" x="6.28" y="14.68" dx="0.7" dy="1.2" layer="1"/>
<smd name="VDD" x="5.18" y="14.68" dx="0.7" dy="1.2" layer="1"/>
<smd name="CLK" x="4.08" y="14.68" dx="0.7" dy="1.2" layer="1"/>
<smd name="VSS" x="2.98" y="14.68" dx="0.7" dy="1.2" layer="1"/>
<smd name="DAT0" x="1.88" y="14.68" dx="0.7" dy="1.2" layer="1"/>
<smd name="DAT1" x="0.78" y="14.68" dx="0.7" dy="1.2" layer="1"/>
<rectangle x1="-1.52" y1="6.28" x2="-0.77" y2="9.88" layer="39"/>
<smd name="CDS-A" x="-1.17" y="4.28" dx="1" dy="0.8" layer="1"/>
<rectangle x1="0.23" y1="8.08" x2="8.93" y2="9.68" layer="39"/>
<rectangle x1="8.58" y1="-1.27" x2="11.13" y2="-0.02" layer="39"/>
<text x="7.1374" y="13.6144" size="0.508" layer="21" rot="R270">#2</text>
<text x="6.0452" y="13.6144" size="0.508" layer="21" rot="R270">#3</text>
<text x="4.953" y="13.6144" size="0.508" layer="21" rot="R270">#4</text>
<text x="3.8608" y="13.6144" size="0.508" layer="21" rot="R270">#5</text>
<text x="2.7686" y="13.6144" size="0.508" layer="21" rot="R270">#6</text>
<text x="1.6764" y="13.6144" size="0.508" layer="21" rot="R270">#7</text>
<text x="0.635" y="13.6144" size="0.508" layer="21" rot="R270">#8</text>
<text x="-0.4318" y="13.6144" size="0.508" layer="21" rot="R270">CDS-B</text>
<text x="8.2296" y="13.6144" size="0.508" layer="21" rot="R270">#1</text>
<text x="18.034" y="-3.1242" size="1.524" layer="21" rot="R90">Micro SD Piggy Board</text>
<text x="11.43" y="-2.54" size="1.27" layer="25" rot="R180">&gt;Name</text>
<polygon width="0.127" layer="1">
<vertex x="11.23" y="-1.27"/>
<vertex x="12.98" y="-1.27"/>
<vertex x="12.98" y="0.63"/>
<vertex x="11.68" y="0.63"/>
<vertex x="11.68" y="-1.02"/>
<vertex x="11.23" y="-1.02"/>
</polygon>
<polygon width="0.127" layer="1">
<vertex x="9.53" y="15.28"/>
<vertex x="9.53" y="14.08"/>
<vertex x="10.53" y="14.08"/>
<vertex x="10.53" y="15.28"/>
</polygon>
<text x="0" y="3.9878" size="0.508" layer="21">CDS-A</text>
<rectangle x1="-1.62" y1="-1.27" x2="-0.62" y2="1.52999375" layer="1"/>
<rectangle x1="-1.62" y1="9.93" x2="-0.62" y2="11.13" layer="1"/>
<wire x1="-10.16" y1="25.4" x2="-10.16" y2="-5.08" width="0.127" layer="21"/>
<wire x1="-10.16" y1="-5.08" x2="19.05" y2="-5.08" width="0.127" layer="21"/>
<wire x1="19.05" y1="-5.08" x2="19.05" y2="25.4" width="0.127" layer="21"/>
<wire x1="19.05" y1="25.4" x2="-10.16" y2="25.4" width="0.127" layer="21"/>
<wire x1="0.8128" y1="15.24" x2="0.8128" y2="17.78" width="0.254" layer="1"/>
<wire x1="0.8128" y1="17.78" x2="-1.905" y2="17.78" width="0.254" layer="1"/>
<wire x1="-1.905" y1="17.78" x2="-1.905" y2="23.622" width="0.254" layer="1"/>
<wire x1="-0.1524" y1="15.24" x2="-0.1524" y2="16.51" width="0.254" layer="1"/>
<wire x1="-0.1524" y1="16.51" x2="-4.445" y2="16.51" width="0.254" layer="1"/>
<wire x1="-4.445" y1="16.51" x2="-4.445" y2="23.622" width="0.254" layer="1"/>
<wire x1="1.88" y1="15.24" x2="1.88" y2="19.05" width="0.254" layer="1"/>
<wire x1="1.88" y1="19.05" x2="0.635" y2="19.05" width="0.254" layer="1"/>
<wire x1="0.635" y1="19.05" x2="0.635" y2="23.622" width="0.254" layer="1"/>
<wire x1="2.9718" y1="15.24" x2="2.9718" y2="21.59" width="0.254" layer="1"/>
<wire x1="2.9718" y1="21.59" x2="3.175" y2="21.59" width="0.254" layer="1"/>
<wire x1="3.175" y1="21.59" x2="3.175" y2="23.622" width="0.254" layer="1"/>
<wire x1="4.064" y1="15.24" x2="4.064" y2="21.59" width="0.254" layer="1"/>
<wire x1="4.064" y1="21.59" x2="5.715" y2="21.59" width="0.254" layer="1"/>
<wire x1="5.715" y1="21.59" x2="5.715" y2="23.622" width="0.254" layer="1"/>
<wire x1="5.1816" y1="15.24" x2="5.1816" y2="20.32" width="0.254" layer="1"/>
<wire x1="5.1816" y1="20.32" x2="8.255" y2="20.32" width="0.254" layer="1"/>
<wire x1="8.255" y1="20.32" x2="8.255" y2="23.622" width="0.254" layer="1"/>
<wire x1="6.2738" y1="15.24" x2="6.2738" y2="19.05" width="0.254" layer="1"/>
<wire x1="6.2738" y1="19.05" x2="10.795" y2="19.05" width="0.254" layer="1"/>
<wire x1="10.795" y1="19.05" x2="10.795" y2="23.622" width="0.254" layer="1"/>
<wire x1="7.366" y1="15.24" x2="7.366" y2="17.78" width="0.254" layer="1"/>
<wire x1="7.366" y1="17.78" x2="13.335" y2="17.78" width="0.254" layer="1"/>
<wire x1="13.335" y1="17.78" x2="13.335" y2="23.622" width="0.254" layer="1"/>
<wire x1="8.4582" y1="15.24" x2="8.4582" y2="16.51" width="0.254" layer="1"/>
<wire x1="8.4582" y1="16.51" x2="15.875" y2="16.51" width="0.254" layer="1"/>
<wire x1="15.875" y1="16.51" x2="15.875" y2="23.622" width="0.254" layer="1"/>
<wire x1="-1.27" y1="4.28" x2="-6.985" y2="4.28" width="0.254" layer="1"/>
<wire x1="-6.985" y1="4.28" x2="-6.985" y2="23.622" width="0.254" layer="1"/>
<pad name="P$1" x="-6.985" y="24.511" drill="1" shape="offset" rot="R270"/>
<pad name="P$2" x="-4.445" y="24.511" drill="1" shape="offset" rot="R270"/>
<pad name="P$3" x="-1.905" y="24.511" drill="1" shape="offset" rot="R270"/>
<pad name="P$4" x="0.635" y="24.511" drill="1" shape="offset" rot="R270"/>
<pad name="P$5" x="3.175" y="24.511" drill="1" shape="offset" rot="R270"/>
<pad name="P$6" x="5.715" y="24.511" drill="1" shape="offset" rot="R270"/>
<pad name="P$7" x="8.255" y="24.511" drill="1" shape="offset" rot="R270"/>
<pad name="P$8" x="10.795" y="24.511" drill="1" shape="offset" rot="R270"/>
<pad name="P$9" x="13.335" y="24.511" drill="1" shape="offset" rot="R270"/>
<pad name="P$10" x="15.875" y="24.511" drill="1" shape="offset" rot="R270"/>
</package>
</packages>
<symbols>
<symbol name="HIROSE-MICRO-SD">
<wire x1="-7.62" y1="-12.7" x2="12.7" y2="-12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="-12.7" x2="12.7" y2="10.16" width="0.254" layer="94"/>
<wire x1="12.7" y1="10.16" x2="-7.62" y2="10.16" width="0.254" layer="94"/>
<wire x1="-7.62" y1="10.16" x2="-7.62" y2="-12.7" width="0.254" layer="94"/>
<pin name="DAT1" x="-12.7" y="-10.16" length="middle"/>
<pin name="VSS" x="-12.7" y="-5.08" length="middle" direction="pas"/>
<pin name="CLK" x="-12.7" y="5.08" length="middle"/>
<pin name="VDD" x="-12.7" y="-7.62" length="middle" direction="pas"/>
<pin name="CMD" x="-12.7" y="0" length="middle"/>
<pin name="CD/DAT3" x="-12.7" y="-2.54" length="middle"/>
<pin name="DAT2" x="-12.7" y="7.62" length="middle"/>
<text x="-2.54" y="12.7" size="1.27" layer="95" rot="R180">&gt;Name</text>
<text x="-7.62" y="-15.24" size="1.27" layer="96">&gt;Value</text>
<pin name="DAT0" x="-12.7" y="2.54" length="middle"/>
<wire x1="5.08" y1="5.08" x2="5.08" y2="-7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="-7.62" x2="7.62" y2="-10.16" width="0.254" layer="94" curve="90"/>
<wire x1="7.62" y1="-10.16" x2="20.32" y2="-10.16" width="0.254" layer="94"/>
<wire x1="20.32" y1="-10.16" x2="22.86" y2="-7.62" width="0.254" layer="94" curve="90"/>
<wire x1="22.86" y1="-7.62" x2="22.86" y2="5.08" width="0.254" layer="94"/>
<wire x1="22.86" y1="5.08" x2="20.32" y2="7.62" width="0.254" layer="94" curve="90"/>
<wire x1="20.32" y1="7.62" x2="7.62" y2="7.62" width="0.254" layer="94"/>
<wire x1="7.62" y1="7.62" x2="5.08" y2="5.08" width="0.254" layer="94" curve="90"/>
</symbol>
<symbol name="MICRO-SD-CDS">
<wire x1="-10.16" y1="5.08" x2="-10.16" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-2.54" x2="10.16" y2="-2.54" width="0.254" layer="94"/>
<wire x1="10.16" y1="-2.54" x2="10.16" y2="5.08" width="0.254" layer="94"/>
<wire x1="10.16" y1="5.08" x2="-10.16" y2="5.08" width="0.254" layer="94"/>
<pin name="CDS-A" x="-15.24" y="0" length="middle"/>
<pin name="CDS-B" x="15.24" y="0" length="middle" rot="R180"/>
<wire x1="-7.62" y1="0" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="7.62" y1="0" x2="2.54" y2="0" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="2.54" y2="2.54" width="0.254" layer="94"/>
<text x="5.08" y="4.445" size="1.27" layer="94" rot="R180">Card Detect</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="HIROSE-MICRO-SD">
<gates>
<gate name="MICRO-SD" symbol="HIROSE-MICRO-SD" x="0" y="2.54"/>
<gate name="CD" symbol="MICRO-SD-CDS" x="0" y="-38.1"/>
</gates>
<devices>
<device name="" package="HIROSE-MICROSD-V2">
<connects>
<connect gate="CD" pin="CDS-A" pad="CDS-A"/>
<connect gate="CD" pin="CDS-B" pad="CDS-B"/>
<connect gate="MICRO-SD" pin="CD/DAT3" pad="CD/DAT3"/>
<connect gate="MICRO-SD" pin="CLK" pad="CLK"/>
<connect gate="MICRO-SD" pin="CMD" pad="CMD"/>
<connect gate="MICRO-SD" pin="DAT0" pad="DAT0"/>
<connect gate="MICRO-SD" pin="DAT1" pad="DAT1"/>
<connect gate="MICRO-SD" pin="DAT2" pad="DAT2"/>
<connect gate="MICRO-SD" pin="VDD" pad="VDD"/>
<connect gate="MICRO-SD" pin="VSS" pad="VSS"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="MCP1710T-piggy">
<description>&lt;b&gt;Microchip PIC Microcontrollers and other Devices&lt;/b&gt;&lt;p&gt;
Based on the following sources :
&lt;ul&gt;
&lt;li&gt;Microchip Data Book, 1993
&lt;li&gt;THE EMERGING WORLD STANDARD, 1995/1996
&lt;li&gt;Microchip, Technical Library CD-ROM, June 1998
&lt;li&gt;www.microchip.com
&lt;/ul&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="DFN-2X2">
<smd name="SHDN" x="0" y="0" dx="0.65" dy="0.35" layer="1" rot="R90"/>
<smd name="VIN" x="0.5" y="0" dx="0.65" dy="0.35" layer="1" rot="R90"/>
<smd name="FB" x="1" y="0" dx="0.65" dy="0.35" layer="1" rot="R90"/>
<smd name="GND3" x="1.5" y="0" dx="0.65" dy="0.35" layer="1" rot="R90"/>
<smd name="GND" x="0" y="2" dx="0.65" dy="0.35" layer="1" rot="R90"/>
<smd name="VOUT" x="0.5" y="2" dx="0.65" dy="0.35" layer="1" rot="R90"/>
<smd name="GND1" x="1" y="2" dx="0.65" dy="0.35" layer="1" rot="R90"/>
<smd name="GND2" x="1.5" y="2" dx="0.65" dy="0.35" layer="1" rot="R90"/>
<text x="2.286" y="0" size="0.3048" layer="21" rot="R90">&gt;MCP1710T</text>
<text x="-0.3556" y="2" size="0.381" layer="21" rot="R90">1</text>
<rectangle x1="-0.1" y1="0.55" x2="1.6" y2="1.45" layer="1"/>
<wire x1="-8.89" y1="8.89" x2="-8.89" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-8.89" y1="-6.35" x2="10.16" y2="-6.35" width="0.127" layer="21"/>
<wire x1="10.16" y1="-6.35" x2="10.16" y2="8.89" width="0.127" layer="21"/>
<wire x1="10.16" y1="8.89" x2="-8.89" y2="8.89" width="0.127" layer="21"/>
<wire x1="0" y1="0" x2="0" y2="-1.27" width="0.3048" layer="1"/>
<wire x1="0" y1="-1.27" x2="-3.175" y2="-1.27" width="0.3048" layer="1"/>
<wire x1="-3.175" y1="-1.27" x2="-3.175" y2="-4.572" width="0.3048" layer="1"/>
<wire x1="1.524" y1="0" x2="1.524" y2="-1.27" width="0.3048" layer="1"/>
<wire x1="1.524" y1="-1.27" x2="4.445" y2="-1.27" width="0.3048" layer="1"/>
<wire x1="4.445" y1="-1.27" x2="4.445" y2="-4.572" width="0.3048" layer="1"/>
<wire x1="1.524" y1="1.99898125" x2="1.524" y2="3.81" width="0.3048" layer="1"/>
<wire x1="1.524" y1="3.81" x2="4.445" y2="3.81" width="0.3048" layer="1"/>
<wire x1="4.445" y1="3.81" x2="4.445" y2="7.112" width="0.3048" layer="1"/>
<wire x1="0" y1="1.99898125" x2="0" y2="3.81" width="0.3048" layer="1"/>
<wire x1="0" y1="3.81" x2="-3.175" y2="3.81" width="0.3048" layer="1"/>
<wire x1="-3.175" y1="3.81" x2="-3.175" y2="7.112" width="0.3048" layer="1"/>
<text x="8.89" y="-5.08" size="0.6096" layer="21" rot="R90">LCD BLK Voltage Regulator</text>
<wire x1="-0.635" y1="7.112" x2="-0.635" y2="5.08" width="0.3048" layer="1"/>
<wire x1="-0.635" y1="5.08" x2="0.508" y2="5.08" width="0.3048" layer="1"/>
<wire x1="0.508" y1="5.08" x2="0.508" y2="1.99898125" width="0.3048" layer="1"/>
<wire x1="1.016" y1="1.99898125" x2="1.016" y2="5.08" width="0.3048" layer="1"/>
<wire x1="1.016" y1="5.08" x2="1.905" y2="5.08" width="0.3048" layer="1"/>
<wire x1="1.905" y1="5.08" x2="1.905" y2="7.112" width="0.3048" layer="1"/>
<wire x1="0.508" y1="0" x2="0.508" y2="-2.54" width="0.3048" layer="1"/>
<wire x1="0.508" y1="-2.54" x2="-0.635" y2="-2.54" width="0.3048" layer="1"/>
<wire x1="-0.635" y1="-2.54" x2="-0.635" y2="-4.572" width="0.3048" layer="1"/>
<wire x1="1.016" y1="0" x2="1.016" y2="-2.54" width="0.3048" layer="1"/>
<wire x1="1.016" y1="-2.54" x2="1.905" y2="-2.54" width="0.3048" layer="1"/>
<wire x1="1.905" y1="-2.54" x2="1.905" y2="-4.572" width="0.3048" layer="1"/>
<pad name="P$1" x="-3.175" y="8.001" drill="1" shape="offset" rot="R270"/>
<pad name="P$2" x="-0.635" y="8.001" drill="1" shape="offset" rot="R270"/>
<pad name="P$3" x="1.905" y="8.001" drill="1" shape="offset" rot="R270"/>
<pad name="P$4" x="4.445" y="8.001" drill="1" shape="offset" rot="R270"/>
<pad name="P$5" x="4.445" y="-5.461" drill="1" shape="offset" rot="R90"/>
<pad name="P$6" x="1.905" y="-5.461" drill="1" shape="offset" rot="R90"/>
<pad name="P$7" x="-0.635" y="-5.461" drill="1" shape="offset" rot="R90"/>
<pad name="P$8" x="-3.175" y="-5.461" drill="1" shape="offset" rot="R90"/>
</package>
</packages>
<symbols>
<symbol name="MCP1710">
<wire x1="0" y1="0" x2="12.7" y2="0" width="0.254" layer="94"/>
<wire x1="12.7" y1="0" x2="12.7" y2="12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="12.7" x2="0" y2="12.7" width="0.254" layer="94"/>
<wire x1="0" y1="12.7" x2="0" y2="0" width="0.254" layer="94"/>
<pin name="GND" x="15.24" y="5.08" length="short" direction="pas" rot="R180"/>
<pin name="GND2" x="-2.54" y="2.54" length="short" direction="pas"/>
<pin name="GND1" x="-2.54" y="5.08" length="short" direction="pas"/>
<pin name="VOUT" x="-2.54" y="7.62" length="short" direction="out"/>
<pin name="SHDN" x="15.24" y="10.16" length="short" direction="in" rot="R180"/>
<pin name="VIN" x="15.24" y="7.62" length="short" direction="in" rot="R180"/>
<pin name="FB" x="-2.54" y="10.16" length="short" direction="in"/>
<pin name="GND3" x="15.24" y="2.54" length="short" direction="pas" rot="R180"/>
<text x="2.54" y="-2.54" size="1.778" layer="96">&gt;Value</text>
<text x="10.16" y="15.24" size="1.778" layer="95" rot="R180">&gt;Name</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="MCP1710">
<gates>
<gate name="G$1" symbol="MCP1710" x="-7.62" y="-5.08"/>
</gates>
<devices>
<device name="" package="DFN-2X2">
<connects>
<connect gate="G$1" pin="FB" pad="FB P$1 P$2 P$3 P$4 P$5 P$6 P$7 P$8"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND1" pad="GND1"/>
<connect gate="G$1" pin="GND2" pad="GND2"/>
<connect gate="G$1" pin="GND3" pad="GND3"/>
<connect gate="G$1" pin="SHDN" pad="SHDN"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
<connect gate="G$1" pin="VOUT" pad="VOUT"/>
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
<part name="ATMEGA-2" library="ATMega324P-piggy" deviceset="ATMEGA324P" device="" value="324P"/>
<part name="ATMEGA-1" library="ATMega324P-piggy" deviceset="ATMEGA324P" device="" value="324P"/>
<part name="MICROSD-2" library="hirosemicrosd-piggy" deviceset="HIROSE-MICRO-SD" device=""/>
<part name="MICROSD-1" library="hirosemicrosd-piggy" deviceset="HIROSE-MICRO-SD" device=""/>
<part name="U$1" library="MCP1710T-piggy" deviceset="MCP1710" device=""/>
<part name="U$2" library="MCP1710T-piggy" deviceset="MCP1710" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="ATMEGA-2" gate="G$1" x="7.62" y="38.1"/>
<instance part="ATMEGA-1" gate="G$1" x="76.2" y="38.1"/>
<instance part="MICROSD-2" gate="MICRO-SD" x="127" y="25.4"/>
<instance part="MICROSD-2" gate="CD" x="129.54" y="0"/>
<instance part="MICROSD-1" gate="MICRO-SD" x="170.18" y="73.66"/>
<instance part="MICROSD-1" gate="CD" x="170.18" y="43.18"/>
<instance part="U$1" gate="G$1" x="116.84" y="68.58"/>
<instance part="U$2" gate="G$1" x="119.38" y="50.8"/>
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
