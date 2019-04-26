/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: Timer
//!	Generated Date	: Fri, 26, Apr 2019  
	File Path	: StopwatchTest/MontaVista/Timer.cpp
*********************************************************************/

//## auto_generated
#include <oxf/omthread.h>
//## auto_generated
#include "Timer.h"
//## link itsDisplay
#include "Display.h"
//## package StopwatchPkg

//## class TopLevel::Timer
Timer_C::Timer_C(IOxfActive* theActiveContext) {
    setActiveContext(theActiveContext, false);
    itsDisplay = NULL;
    initStatechart();
}

Timer_C::~Timer_C() {
    cleanUpRelations();
    cancelTimeouts();
}

void Timer_C::print() {
    //#[ operation print()
    Display.print(minutes,seconds);
    //#]
}

void Timer_C::reset() {
    //#[ operation reset()
    seconds=0;
    minutes=0;
    //#]
}

void Timer_C::tick() {
    //#[ operation tick()
    seconds++;
    if(seconds>59){
    	seconds=0;
    	minutes++;
    }
    //#]
}

int Timer_C::getMinutes() const {
    return minutes;
}

void Timer_C::setMinutes(int p_minutes) {
    minutes = p_minutes;
}

int Timer_C::getSeconds() const {
    return seconds;
}

void Timer_C::setSeconds(int p_seconds) {
    seconds = p_seconds;
}

Display_C* Timer_C::getItsDisplay() const {
    return itsDisplay;
}

void Timer_C::setItsDisplay(Display_C* p_Display) {
    itsDisplay = p_Display;
}

bool Timer_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Timer_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    state_0_subState = OMNonState;
    state_0_timeout = NULL;
}

void Timer_C::cleanUpRelations() {
    if(itsDisplay != NULL)
        {
            itsDisplay = NULL;
        }
}

void Timer_C::cancelTimeouts() {
    if(state_0_timeout != NULL)
        {
            state_0_timeout->cancel();
            state_0_timeout = NULL;
        }
}

bool Timer_C::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(state_0_timeout == arg)
        {
            state_0_timeout = NULL;
            res = true;
        }
    return res;
}

void Timer_C::rootState_entDef() {
    {
        state_0_entDef();
    }
}

IOxfReactive::TakeEventStatus Timer_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        case state_1:
        {
            if(IS_EVENT_TYPE_OF(evStartStop_StopwatchPkg_id))
                {
                    state_0_subState = state_2;
                    rootState_active = state_2;
                    state_0_timeout = scheduleTimeout(1000, NULL);
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = state_0_handleEvent();
                }
        }
        break;
        case state_2:
        {
            res = state_2_handleEvent();
        }
        break;
        default:
            break;
    }
    return res;
}

void Timer_C::state_0_entDef() {
    rootState_subState = state_0;
    //#[ transition 0 
    reset();
    print();
    //#]
    state_0_subState = state_2;
    rootState_active = state_2;
    state_0_timeout = scheduleTimeout(1000, NULL);
}

IOxfReactive::TakeEventStatus Timer_C::state_0_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evReset_StopwatchPkg_id))
        {
            switch (state_0_subState) {
                case state_2:
                {
                    if(state_0_timeout != NULL)
                        {
                            state_0_timeout->cancel();
                            state_0_timeout = NULL;
                        }
                }
                break;
                default:
                    break;
            }
            state_0_subState = OMNonState;
            //#[ transition 4 
            
            reset();print();
            //#]
            state_0_entDef();
            res = eventConsumed;
        }
    
    return res;
}

IOxfReactive::TakeEventStatus Timer_C::state_2_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == state_0_timeout)
                {
                    if(state_0_timeout != NULL)
                        {
                            state_0_timeout->cancel();
                            state_0_timeout = NULL;
                        }
                    //#[ transition 1 
                    
                    tick();print();
                    //#]
                    state_0_subState = state_2;
                    rootState_active = state_2;
                    state_0_timeout = scheduleTimeout(1000, NULL);
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(evStartStop_StopwatchPkg_id))
        {
            if(state_0_timeout != NULL)
                {
                    state_0_timeout->cancel();
                    state_0_timeout = NULL;
                }
            state_0_subState = state_1;
            rootState_active = state_1;
            res = eventConsumed;
        }
    
    if(res == eventNotConsumed)
        {
            res = state_0_handleEvent();
        }
    return res;
}

/*********************************************************************
	File Path	: StopwatchTest/MontaVista/Timer.cpp
*********************************************************************/
