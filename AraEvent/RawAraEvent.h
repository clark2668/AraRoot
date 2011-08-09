//////////////////////////////////////////////////////////////////////////////
/////  RawAraEvent.h        Raw ARA event class                      /////
/////                                                                    /////
/////  Description:                                                      /////
/////     A simple class for storing raw ARA events in a TTree         /////
/////  Author: Ryan Nichol (rjn@hep.ucl.ac.uk)                           /////
//////////////////////////////////////////////////////////////////////////////

#ifndef RAWARAEVENT_H
#define RAWARAEVENT_H

//Includes
#include <TObject.h>
#include "araStructures.h"
#include "araDefines.h"
#include "RawAraHeader.h"
#include "AraRawRFChannel.h"
#include "AraTriggerMonitor.h"
#include "AraHkData.h"

//!  RawAraEvent -- The Raw ARA Event Data
/*!
  The ROOT implementation of the raw ARA event data
  \ingroup rootclasses
*/
class RawAraEvent: public TObject
{
 public:
   RawAraEvent(); ///< Default constructor
   RawAraEvent(AraEventBody_t *theBody); ///< Assignment constructor
   ~RawAraEvent(); ///< Destructor

   //Important Stuff
   UInt_t whichPeds; ///< Timestamp of pedestals used in subtraction

   //The data
   RawAraHeader head; ///< The header
   AraRawRFChannel chan[NUM_DIGITIZED_CHANNELS]; ///< RawRF data
   AraTriggerMonitor trig; ///< The trigger
   AraHkData hk; ///< The hk
   
   Int_t getLabChip(Int_t chanIndex) {
     return chan[chanIndex].getLabChip();
   } ///< Returns the LABRADOR number
   Int_t getRCO(Int_t chanIndex) {
     return chan[chanIndex].getRCO();
   } ///< Returns the RCO phase
   Int_t getFirstHitBus(Int_t chanIndex) {
     return chan[chanIndex].getFirstHitBus();
   } ///< Returns the firstHitbus value for the channel
   Int_t getLastHitBus(Int_t chanIndex) {
     return chan[chanIndex].getLastHitBus();
   } ///< Returns the lastHitbus value for the channel
   Int_t getWrappedHitBus(Int_t chanIndex) {
     return chan[chanIndex].getWrappedHitBus();
   } ///< Return the wrapped hitbus flag for the channel. When the HITBUS is wrapped the waveform runs from firstHitbus+1 to lastHitbus-1, otherwise it runs from lastHitbus+1 to firstHitbus-1 (crossing the 259-->0 boudnary).

   Int_t getLatestSample(Int_t chanIndex); ///<Returns the latest sample in the waveform
   Int_t getEarliestSample(Int_t chanIndex); ///< Returns the earliest sample in the waveform
   Int_t isInTrigPattern(int bit) {return trig.isInTrigPattern(bit);} ///<Returns whetehr or not bit is in the trigger pattern
   UInt_t getRubidiumTriggerTime() {return trig.getRubidiumTriggerTime();} ///<Returns the 32-bit (well maybe 28-bit) trigger time
   Double_t getRubidiumTriggerTimeInSec() {return trig.getRubidiumTriggerTimeInSec();} ///< Returns the rubidium time divided by 280M


  ClassDef(RawAraEvent,1);
};


#endif //RAWARAEVENT_H
