#include "GenXMP.h"

using namespace std;

// create dummy xmp

void GenXMP(string filename){
	string xmp1 =
	R"(<?xml version="1.0" encoding="UTF-8"?>
<x:xmpmeta xmlns:x="adobe:ns:meta/" x:xmptk="XMP Core 4.4.0-Exiv2">
 <rdf:RDF xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">
  <rdf:Description rdf:about=""
    xmlns:xmp="http://ns.adobe.com/xap/1.0/"
    xmlns:xmpMM="http://ns.adobe.com/xap/1.0/mm/"
    xmlns:darktable="http://darktable.sf.net/"
   xmp:Rating="1"
   xmpMM:DerivedFrom=")";
   
   string xmp2 = filename;
   
   string xmp3 = R"("
   darktable:xmp_version="2"
   darktable:raw_params="0"
   darktable:auto_presets_applied="1"
   darktable:history_end="4">
   <darktable:mask_id>
    <rdf:Seq/>
   </darktable:mask_id>
   <darktable:mask_type>
    <rdf:Seq/>
   </darktable:mask_type>
   <darktable:mask_name>
    <rdf:Seq/>
   </darktable:mask_name>
   <darktable:mask_version>
    <rdf:Seq/>
   </darktable:mask_version>
   <darktable:mask>
    <rdf:Seq/>
   </darktable:mask>
   <darktable:mask_nb>
    <rdf:Seq/>
   </darktable:mask_nb>
   <darktable:mask_src>
    <rdf:Seq/>
   </darktable:mask_src>
   <darktable:history>
    <rdf:Seq>
     <rdf:li
      darktable:operation="flip"
      darktable:enabled="1"
      darktable:modversion="2"
      darktable:params="ffffffff"
      darktable:multi_name=""
      darktable:multi_priority="0"
      darktable:blendop_version="8"
      darktable:blendop_params="gz11eJxjYGBgkGAAgRNODGiAEV0AJ2iwh+CRxQcA5qIZBA=="/>
     <rdf:li
      darktable:operation="sharpen"
      darktable:enabled="1"
      darktable:modversion="1"
      darktable:params="000000400000003f0000003f"
      darktable:multi_name=""
      darktable:multi_priority="0"
      darktable:blendop_version="8"
      darktable:blendop_params="gz11eJxjYGBgkGAAgRNODGiAEV0AJ2iwh+CRxQcA5qIZBA=="/>
     <rdf:li
      darktable:operation="basecurve"
      darktable:enabled="1"
      darktable:modversion="5"
      darktable:params="gz09eJxjYIAAM6vnNnqyn22E9n235b6aa3cy6rVdRaK9/Y970fYf95bbMzA0QPEoGEqADYnNhCELiVMAudcSGA=="
      darktable:multi_name=""
      darktable:multi_priority="0"
      darktable:blendop_version="8"
      darktable:blendop_params="gz11eJxjYGBgkGAAgRNODGiAEV0AJ2iwh+CRxQcA5qIZBA=="/>
     <rdf:li
      darktable:operation="flip"
      darktable:enabled="1"
      darktable:modversion="2"
      darktable:params="05000000"
      darktable:multi_name=""
      darktable:multi_priority="0"/>
    </rdf:Seq>
   </darktable:history>
  </rdf:Description>
 </rdf:RDF>
</x:xmpmeta>
)";

	cout<<xmp1 + xmp2 + xmp3 << "\n";
}

void ListFiles(string path){
	
}

int main(){
	ListFiles("CR2");
	GenXMP("MGCL_1085284_L.CR2");
	// cout<<__cplusplus<<"\n";
	return 0;
}
