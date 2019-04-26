/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: Timer
//!	Generated Date	: Fri, 26, Apr 2019  
	File Path	: StopwatchTest/MontaVista/Timer.h
*********************************************************************/

#ifndef Timer_H
#define Timer_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include "StopwatchPkg.h"
//## auto_generated
#include <oxf/omreactive.h>
//## auto_generated
#include <oxf/state.h>
//## auto_generated
#include <oxf/event.h>
//## link itsDisplay
class Display_C;

//## package StopwatchPkg

//## class TopLevel::Timer
class Timer_C : public OMReactive {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    Timer_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Timer_C();
    
    ////    Operations    ////
    
    //## operation print()
    void print();
    
    //## operation reset()
    void reset();
    
    //## operation tick()
    void tick();
    
    ////    Additional operations    ////
    
    //## auto_generated
    int getMinutes() const;
    
    //## auto_generated
    void setMinutes(int p_minutes);
    
    //## auto_generated
    int getSeconds() const;
    
    //## auto_generated
    void setSeconds(int p_seconds);
    
    //## auto_generated
    Display_C* getItsDisplay() const;
    
    //## auto_generated
    void setItsDisplay(Display_C* p_Display);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    //## auto_generated
    void cancelTimeouts();
    
    //## auto_generated
    bool cancelTimeout(const IOxfTimeout* arg);
    
    ////    Attributes    ////
    
    int minutes;		//## attribute minutes
    
    int seconds;		//## attribute seconds
    
    ////    Relations and components    ////
    
    Display_C* itsDisplay;		//## link itsDisplay
    
    ////    Framework operations    ////

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // state_0:
    //## statechart_method
    inline bool state_0_IN() const;
    
    //## statechart_method
    void state_0_entDef();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_0_handleEvent();
    
    // state_2:
    //## statechart_method
    inline bool state_2_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_2_handleEvent();
    
    // state_1:
    //## statechart_method
    inline bool state_1_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Timer_Enum {
        OMNonState = 0,
        state_0 = 1,
        state_2 = 2,
        state_1 = 3
    };
    
    int rootState_subState;
    
    int rootState_active;
    
    int state_0_subState;
    
    IOxfTimeout* state_0_timeout;
//#]
};

inline bool Timer_C::rootState_IN() const {
    return true;
}

inline bool Timer_C::state_0_IN() const {
    return rootState_subState == state_0;
}

inline bool Timer_C::state_2_IN() const {
    return state_0_subState == state_2;
}

inline bool Timer_C::state_1_IN() const {
    return state_0_subState == state_1;
}

#endif
/*********************************************************************
	File Path	: StopwatchTest/MontaVista/Timer.h
*********************************************************************/
