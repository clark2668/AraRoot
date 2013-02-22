//////////////////////////////////////////////////////////////////////////////
/////  AraStationInfo.h       ARA Station Information                    /////
/////                                                                    /////
/////  Description:                                                      /////
/////     A simple class for storing information about an Ara Stations   /////
/////  Author: Jonathan Davies (jdavies@hep.ucl.ac.uk)                   /////
/////          & Ryan Nichol (rjn@hep.ucl.ac.uk)                         /////
//////////////////////////////////////////////////////////////////////////////

#ifndef ARASTATIONINFO_H
#define ARASTATIONINFO_H

//Includes
#include <TObject.h>
#include "araIcrrDefines.h"
#include "AraAntennaInfo.h"
#include "AraCalAntennaInfo.h"

#include <vector>
//!  Part of the AraEvent library. Stores information about the station's location and the antenna information. Populated by AraGeomTool
/*!
  A simple class for storing information about an Ara Station
  \ingroup rootclasses
*/

class AraStationInfo: public TObject
{
  
 public:
  
  AraStationInfo(); ///< Default constructor
  AraStationInfo(AraStationId_t stationId); ///< Assignment constructor
  ~AraStationInfo(); ////< Destructor

  Int_t getNumCalAnts() {return fNumberCalAntennas;}
  Int_t getNumAnts() {return fNumberAntennas;}
  void setNumAnts(int numAnts) { fNumberAntennas=numAnts;}

  Int_t getNumRFChans() {return numberRFChans;}
  void setNumRFChans(int numChans) { numberRFChans=numChans;}

  Double_t getCableDelay(int rfChanNum);
  AraAntennaInfo *getAntennaInfo(int antNum, AraAntPol::AraAntPol_t polType) { return getAntennaInfo(getRFChanByPolAndAnt(antNum,polType));}
  AraAntennaInfo *getAntennaInfo(int rfChanNum);
  AraCalAntennaInfo *getCalAntennaInfo(int calAntId); ///< Simple 0-3 numeric id


  Int_t getRFChanByPolAndAnt(Int_t antNum, AraAntPol::AraAntPol_t polType);
  Int_t getElecChanFromRFChan(Int_t rfChan);
  Int_t getNumAntennasByPol(AraAntPol::AraAntPol_t polType) {return fAntIndexVec[polType].size();}

  //Should add some error checking at some point
   Double_t getLowPassFilter(int rfChan) { return fAntInfo[rfChan].lowPassFilterMhz; }
   Double_t getHighPassFilter(int rfChan) { return fAntInfo[rfChan].highPassFilterMhz; }


  //Below are just for ICRR station
   //Maybe they should live elsewhere?
  int getIcrrChanIndex(AraLabChip::AraLabChip_t chip, int chan) {return chip*CHANNELS_PER_LAB3 +chan;}
  AraLabChip::AraLabChip_t getLabChipForChan(int rfChan) {return fAntInfo[rfChan].labChip;}
  int getNumLabChansForChan(int rfChan) { return fAntInfo[rfChan].numLabChans;}
  int getFirstLabChanForChan(int rfChan) { return fAntInfo[rfChan].labChans[0];}
  int getSecondLabChanForChan(int rfChan) { return fAntInfo[rfChan].labChans[1];}
  int getFirstLabChanIndexForChan(int rfChan) { return getIcrrChanIndex(getLabChipForChan(rfChan),getFirstLabChanForChan(rfChan));}
  int getSecondLabChanIndexForChan(int rfChan) { return getIcrrChanIndex(getLabChipForChan(rfChan),getSecondLabChanForChan(rfChan));}
  int isDiplexed(int rfChan) {return fAntInfo[rfChan].isDiplexed;}





  
  //At some point will make these private
  AraStationId_t fStationId;
  std::vector<AraAntennaInfo> fAntInfo; ///< One object per antenna
  std::vector<AraCalAntennaInfo> fCalAntInfo; ///< Vector of local station Calibration Pulsers

  Double_t fStationLocation[3]; ///< array-centric co-ordinates of the station
  Double_t fRotationMatrix[3][3]; ///< Rotation matrix to convert from array centric to station centric

  int numberRFChans;  ///< Currently a copy of fNumberAntennas
  int fNumberAntennas; ///<This is the number of antennas on an ATRI
  int fNumberCalAntennas; ///< Number of calibration antennas
  
  std::vector<int> fAntIndexVec[3]; ///<The antenna to logical channel index one vector per polarisation


 private:
  ///These are helper functions that should not be called
  AraAntennaInfo *getNewAntennaInfo(int rfChanNum);
  AraCalAntennaInfo *getNewCalAntennaInfo(int antCalId);
  void fillAntIndexVec();
  void readChannelMapDbAtri();
  void readChannelMapDbIcrr();
  void readCalPulserDb();

  ClassDef(AraStationInfo,1);
};

#endif //ARASTATIONINFO_H
