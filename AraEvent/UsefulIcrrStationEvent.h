//////////////////////////////////////////////////////////////////////////////
/////  UsefulIcrrStationEvent.h        Useful ARA event class                      /////
/////                                                                    /////
/////  Description:                                                      /////
/////     A simple class for storing useful ARA events in a TTree         /////
/////  Author: Ryan Nichol (rjn@hep.ucl.ac.uk)                           /////
//////////////////////////////////////////////////////////////////////////////

#ifndef USEFULICRRSTATIONEVENT_H
#define USEFULICRRSTATIONEVENT_H

//Includes
#include <TObject.h>
#include <TGraph.h>
#include <TH1.h>
#include "araIcrrStructures.h"
#include "araIcrrDefines.h"
#include "RawIcrrStationEvent.h"
#include "AraEventCalibrator.h"
#include "UsefulAraStationEvent.h"

//!  UsefulIcrrStationEvent -- The Useful ARA Event Data
/*!
  The ROOT implementation of the useful ARA event data

  This is the most useful class for analysing the ARA data. The raw ADC values from a RawIcrrStationEvent object are converted into calibrated voltage-time arrays using one of the calibration types defined in AraEventCalibrator. Utility functions are provided to access these arrays as TGraphs, or in the frequency domain.

  \ingroup rootclasses
*/
class UsefulIcrrStationEvent: public RawIcrrStationEvent, public UsefulAraStationEvent
{
 public:
   UsefulIcrrStationEvent(); ///< Default constructor
   UsefulIcrrStationEvent(RawIcrrStationEvent *rawEvent, AraCalType::AraCalType_t calType=AraCalType::kVoltageTime); ///< Assignment constructor
   ~UsefulIcrrStationEvent(); ///< Destructor

   Double_t fVolts[NUM_DIGITIZED_ICRR_CHANNELS][MAX_NUMBER_SAMPLES_LAB3]; ///< Array of the calibrated voltages
   Double_t fTimes[NUM_DIGITIZED_ICRR_CHANNELS][MAX_NUMBER_SAMPLES_LAB3]; ///<Array of the times
   Int_t fNumPoints[NUM_DIGITIZED_ICRR_CHANNELS]; ///< Array of the number of valid samples
   Double_t fVoltsRF[MAX_RFCHANS_PER_ICRR][2*MAX_NUMBER_SAMPLES_LAB3]; ///< Array of the calibrated, interleaved voltages for the RF input channels
   Double_t fTimesRF[MAX_RFCHANS_PER_ICRR][2*MAX_NUMBER_SAMPLES_LAB3]; ///< Array of the calibrated, interleaved times for the RF input channels
   Int_t fNumPointsRF[MAX_RFCHANS_PER_ICRR]; ///< Number of valid samples for thecalibrated, interleaved waveforms from the RF input channels


   Int_t getNumElecChannels() {return NUM_DIGITIZED_ICRR_CHANNELS;}
   Int_t getNumRFChannels() {return numRFChans;} //jpd this will need to change to accomodate the extra 4 RF signals diplexed into last 4 Elec channels
   TGraph *getGraphFromElecChan(int chan); ///< Returns the voltages-time graph for the appropriate electronics channel
   TGraph *getGraphFromRFChan(int chan); ///< Returns the voltage-time graph for the appropriate rf channel //jpd This will need to change to pull out extra 4 channels, need to do in frequency domain
   TGraph *getFFTForRFChan(int chan); ///<Utility function for webplotter, all channels are interpolated to 0.5 ns
   TH1D *getFFTHistForRFChan(int chan); ///< Utility function for webplotter
   int fillFFTHistoForRFChan(int chan, TH1D *histFFT); ///< Utility function for webplotter
   int guessRCO(int chanIndex); ///< Looks at clock channel to try and guess which RCO phase we are in.
   int getRCO(int chanIndex) { return guessRCO(chanIndex);} ///< Note that this function now calls guessRCO rather than relying on the predetermined RCO phase
   TGraph *getFFTForClock(int clock_number); ///< Returns the FFT for the clock channel on lab A, B, or C for clock_number 0 ,1 , or 2 respectively.
   TH1D   *getFFTHistForClock(int clock_number); ///<Utility function for webplotter
   int     fillFFTHistoForClock(int clock_number, TH1D *histFFT); ///<Utility function for webplotter
   bool    isCalPulserEvent( ); ///< Returns whether (true) or not (false) the event is a calpulser event based on a cut applied to the Rb clock counter

   Int_t getRawRCO(Int_t chanIndex) {
     return chan[chanIndex].getRCO();
   } ///< Returns the RCO phase

   Int_t numRFChans;

   AraEventCalibrator *fCalibrator; ///< Pointer to the AraEventCalibrator

  ClassDef(UsefulIcrrStationEvent,1);
};


#endif //USEFULICRRSTATIONEVENT_H