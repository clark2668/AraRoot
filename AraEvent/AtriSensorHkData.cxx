//////////////////////////////////////////////////////////////////////////////
/////  AtriSensorHkData.cxx        Definition of the AtriSensorHkData            /////
/////                                                                    /////
/////  Description:                                                      /////
/////     A simple class that holds AtriSensorHkData                         /////
/////  Author: Ryan Nichol (rjn@hep.ucl.ac.uk)                           /////
//////////////////////////////////////////////////////////////////////////////

#include "AtriSensorHkData.h"
#include "TMath.h"
#include <iostream>
#include <fstream>
#include <cstring>
ClassImp(AtriSensorHkData);

AtriSensorHkData::AtriSensorHkData() 
{
   //Default Constructor
}

AtriSensorHkData::~AtriSensorHkData() {
   //Default Destructor
}


AtriSensorHkData::AtriSensorHkData(AraSensorHk_t *theHk)
  :RawAraGenericHeader(&(theHk->gHdr))
{

  unixTime=theHk->unixTime; ///< Time in seconds (64-bits for future proofing)
  unixTimeUs=theHk->unixTimeUs; ///< Time in microseconds (32-bits)

  atriVoltage=theHk->atriVoltage; ///< ATRI Voltage (conversion?)
  atriCurrent=theHk->atriCurrent; ///< ATRI Current (conversion?)
  memcpy(ddaTemp,theHk->ddaTemp,sizeof(UShort_t)*DDA_PER_ATRI); ///< DDA Temperature conversion??
  memcpy(tdaTemp,theHk->tdaTemp,sizeof(UShort_t)*TDA_PER_ATRI); ///< TDA Temperature conversion??
  memcpy(ddaVoltageCurrent,theHk->ddaVoltageCurrent,sizeof(UInt_t)*DDA_PER_ATRI); ///< 3 bytes only will work out better packing when I know what the numbers mean
  memcpy(tdaVoltageCurrent,theHk->tdaVoltageCurrent,sizeof(UInt_t)*DDA_PER_ATRI); ///< 3 bytes only will work out better packing when I know what the numbers mean

}


Double_t AtriSensorHkData::getDdaVoltage(Int_t dda){
  if(dda >= DDA_PER_ATRI || dda < 0) return -99;
  uint32_t ddaVoltageADC = (ddaVoltageCurrent[dda] & 0xff) << 4;
  ddaVoltageADC = ddaVoltageADC | (ddaVoltageCurrent[dda] & 0xf00000)>>20;
  Double_t ddaVoltageVolts = (6.65/4096)*ddaVoltageADC;
  return ddaVoltageVolts;
}
Double_t AtriSensorHkData::getDdaCurrent(Int_t dda){
  if(dda >= DDA_PER_ATRI) return -99;
  UInt_t ddaCurrentADC = (ddaVoltageCurrent[dda] & 0x00ff00) >> 4;
  ddaCurrentADC = ddaCurrentADC | (ddaVoltageCurrent[dda] & 0x0f0000)>>16 ;
  Double_t ddaCurrentAmps = ddaCurrentADC * (0.10584/4096) / 0.1;
  return ddaCurrentAmps;

}

Double_t AtriSensorHkData::getTdaVoltage(Int_t tda){
  if(tda >= TDA_PER_ATRI || tda < 0) return -99;
  uint32_t tdaVoltageADC = (tdaVoltageCurrent[tda] & 0xff) << 4;
  tdaVoltageADC = tdaVoltageADC | (tdaVoltageCurrent[tda] & 0xf00000)>>20;
  Double_t tdaVoltageVolts = (6.65/4096)*tdaVoltageADC;
  return tdaVoltageVolts;

}
Double_t AtriSensorHkData::getTdaCurrent(Int_t tda){
  if(tda >= TDA_PER_ATRI) return -99;
  UInt_t tdaCurrentADC = (tdaVoltageCurrent[tda] & 0x00ff00) >> 4;
  tdaCurrentADC = tdaCurrentADC | (tdaVoltageCurrent[tda] & 0x0f0000)>>16 ;
  Double_t tdaCurrentAmps = tdaCurrentADC * (0.10584/4096) / 0.1;
  return tdaCurrentAmps;

}
