#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class RawAraEvent+;
#pragma link C++ class RawAraHeader+;
#pragma link C++ class AraRawRFChannel+;
#pragma link C++ class AraHkData+;
#pragma link C++ class FullAraHkEvent+;
#pragma link C++ class AraTriggerMonitor+;
#pragma link C++ class UsefulAraEvent+;
#pragma link C++ class AraAntennaInfo+;
#pragma link C++ class AraGeomTool+;
#pragma link C++ class AraEventCalibrator+;

#pragma link C++ namespace     AraCalType;
#pragma link C++ enum          AraCalType::EAraCalType;
#pragma link C++ nestedtypedef AraCalType::AraCalType_t;

#pragma link C++ namespace     AraAntType;
#pragma link C++ enum          AraAntType::EAraAntType;
#pragma link C++ nestedtypedef AraAntType::AraAntType_t;


#pragma link C++ namespace     AraAntPol;
#pragma link C++ enum          AraAntPol::EAraAntPol;
#pragma link C++ nestedtypedef AraAntPol::AraAntPol_t;


#pragma link C++ namespace     AraDaqChanType;
#pragma link C++ enum          AraDaqChanType::EAraDaqChanType;
#pragma link C++ nestedtypedef AraDaqChanType::AraDaqChanType_t;


#pragma link C++ namespace     AraLabChip;
#pragma link C++ enum          AraLabChip::EAraLabChip;
#pragma link C++ nestedtypedef AraLabChip::AraLabChip_t;


#pragma link C++ namespace     AraAntDir;
#pragma link C++ enum          AraAntDir::EAraAntDir;
#pragma link C++ nestedtypedef AraAntDir::AraAntDir_t;

#pragma link C++ namespace     AraSurfaceOrientation;
#pragma link C++ enum          AraSurfaceOrientation::EAraSurfaceOrientation;
#pragma link C++ nestedtypedef AraSurfaceOrientation::AraSurfaceOrientation_t;



#endif

