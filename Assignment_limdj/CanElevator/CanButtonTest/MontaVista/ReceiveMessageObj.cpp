/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: ReceiveMessageObj
//!	Generated Date	: Wed, 05, Jun 2019  
	File Path	: CanButtonTest/MontaVista/ReceiveMessageObj.cpp
*********************************************************************/

//## auto_generated
#include <oxf/omthread.h>
//## auto_generated
#include "ReceiveMessageObj.h"
//## link itsElevatorControl
#include "ElevatorControl.h"
//## package CanButton

//## class TopLevel::ReceiveMessageObj
ReceiveMessageObj_C::ReceiveMessageObj_C(IOxfActive* theActiveContext) {
    setActiveContext(theActiveContext, false);
    itsElevatorControl = NULL;
    initStatechart();
    //#[ operation ReceiveMessageObj()
    can_init();
    //#]
}

ReceiveMessageObj_C::~ReceiveMessageObj_C() {
    cleanUpRelations();
}

void ReceiveMessageObj_C::data() {
    //#[ operation data()
    if(download_data_buf[0] == 1)
    {   
    	height = download_data_buf[1]*256 + download_data_buf[2]+80;   
    	ElevatorControl.GEN(evMove);
    }
    
    else if(download_data_buf[0] == 2)
    { 
        check_floor[download_data_buf[1]-2] = 1;
        ElevatorControl.GEN(evCalled);
    }
    //#]
}

ElevatorControl_C* ReceiveMessageObj_C::getItsElevatorControl() const {
    return itsElevatorControl;
}

void ReceiveMessageObj_C::setItsElevatorControl(ElevatorControl_C* p_ElevatorControl) {
    if(p_ElevatorControl != NULL)
        {
            p_ElevatorControl->_setItsReceiveMessageObj(this);
        }
    _setItsElevatorControl(p_ElevatorControl);
}

bool ReceiveMessageObj_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void ReceiveMessageObj_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void ReceiveMessageObj_C::cleanUpRelations() {
    if(itsElevatorControl != NULL)
        {
            ReceiveMessageObj_C* p_ReceiveMessageObj = itsElevatorControl->getItsReceiveMessageObj();
            if(p_ReceiveMessageObj != NULL)
                {
                    itsElevatorControl->__setItsReceiveMessageObj(NULL);
                }
            itsElevatorControl = NULL;
        }
}

void ReceiveMessageObj_C::__setItsElevatorControl(ElevatorControl_C* p_ElevatorControl) {
    itsElevatorControl = p_ElevatorControl;
}

void ReceiveMessageObj_C::_setItsElevatorControl(ElevatorControl_C* p_ElevatorControl) {
    if(itsElevatorControl != NULL)
        {
            itsElevatorControl->__setItsReceiveMessageObj(NULL);
        }
    __setItsElevatorControl(p_ElevatorControl);
}

void ReceiveMessageObj_C::_clearItsElevatorControl() {
    itsElevatorControl = NULL;
}

void ReceiveMessageObj_C::rootState_entDef() {
    {
        rootState_subState = InitialState;
        rootState_active = InitialState;
    }
}

IOxfReactive::TakeEventStatus ReceiveMessageObj_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        case InitialState:
        {
            if(IS_EVENT_TYPE_OF(evMessageReceived_CanButton_id))
                {
                    rootState_subState = MessageArrived;
                    rootState_active = MessageArrived;
                    //#[ state ROOT.MessageArrived.(Entry) 
                    data();
                    //#]
                    res = eventConsumed;
                }
            
        }
        break;
        case MessageArrived:
        {
            if(IS_EVENT_TYPE_OF(evMessageReceived_CanButton_id))
                {
                    rootState_subState = MessageArrived;
                    rootState_active = MessageArrived;
                    //#[ state ROOT.MessageArrived.(Entry) 
                    data();
                    //#]
                    res = eventConsumed;
                }
            
        }
        break;
        default:
            break;
    }
    return res;
}

/*********************************************************************
	File Path	: CanButtonTest/MontaVista/ReceiveMessageObj.cpp
*********************************************************************/
