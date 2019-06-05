/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: CanButton
//!	Generated Date	: Wed, 15, May 2019  
	File Path	: CanButtonTest/MontaVista/CanButton.cpp
*********************************************************************/

//## auto_generated
#include <oxf/omthread.h>
//## auto_generated
#include "CanButton.h"
//## link itsElevator
#include "Elevator.h"
//## package CanButton

//## class TopLevel::CanButton
//## attribute download_data_buf
unsigned char download_data_buf[8];

//## attribute floor_check
unsigned char floor_check[4];

//## attribute high_floor
int high_floor(1);

//## attribute high_pixel
int high_pixel;

//## attribute upload_data_buf
unsigned char upload_data_buf[8];

//## classInstance CanButton
CanButton_C CanButton;

//## classInstance Elevator
Elevator_C Elevator;

//## operation CanReceiveIsr()
void CanReceiveIsr() {
    //#[ operation CanReceiveIsr()
    CanButton.GEN(evCanReceive());
    //#]
}

void CanButton_initRelations() {
    {
        {
            CanButton.setShouldDelete(false);
        }
        {
            Elevator.setShouldDelete(false);
        }
    }
    CanButton.setItsElevator(&Elevator);
}

bool CanButton_startBehavior() {
    bool done = true;
    done &= CanButton.startBehavior();
    done &= Elevator.startBehavior();
    return done;
}

//#[ ignore
CanButton_OMInitializer::CanButton_OMInitializer() {
    CanButton_initRelations();
    CanButton_startBehavior();
}

CanButton_OMInitializer::~CanButton_OMInitializer() {
}
//#]

CanButton_C::CanButton_C(IOxfActive* theActiveContext) {
    setActiveContext(theActiveContext, false);
    itsElevator = NULL;
    initStatechart();
    //#[ operation CanButton()
    can_init();
    //#]
}

CanButton_C::~CanButton_C() {
    cleanUpRelations();
}

void CanButton_C::decode() {
    //#[ operation decode()
    if(download_data_buf[0]==1){   //position
    	high_pixel=download_data_buf[1]*256+download_data_buf[2]+80;   
    	Elevator.GEN(evMove);
    }
    
    else if(download_data_buf[0]==2){ //button
        floor_check[download_data_buf[1]-2]=1;
        Elevator.GEN(evButtoncall);
    }
    //#]
}

Elevator_C* CanButton_C::getItsElevator() const {
    return itsElevator;
}

void CanButton_C::setItsElevator(Elevator_C* p_Elevator) {
    if(p_Elevator != NULL)
        {
            p_Elevator->_setItsCanButton(this);
        }
    _setItsElevator(p_Elevator);
}

bool CanButton_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void CanButton_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void CanButton_C::cleanUpRelations() {
    if(itsElevator != NULL)
        {
            CanButton_C* p_CanButton = itsElevator->getItsCanButton();
            if(p_CanButton != NULL)
                {
                    itsElevator->__setItsCanButton(NULL);
                }
            itsElevator = NULL;
        }
}

void CanButton_C::__setItsElevator(Elevator_C* p_Elevator) {
    itsElevator = p_Elevator;
}

void CanButton_C::_setItsElevator(Elevator_C* p_Elevator) {
    if(itsElevator != NULL)
        {
            itsElevator->__setItsCanButton(NULL);
        }
    __setItsElevator(p_Elevator);
}

void CanButton_C::_clearItsElevator() {
    itsElevator = NULL;
}

void CanButton_C::rootState_entDef() {
    {
        rootState_subState = init;
        rootState_active = init;
    }
}

IOxfReactive::TakeEventStatus CanButton_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        case init:
        {
            if(IS_EVENT_TYPE_OF(evCanReceive_CanButton_id))
                {
                    rootState_subState = On;
                    rootState_active = On;
                    //#[ state ROOT.On.(Entry) 
                    decode();
                    //#]
                    res = eventConsumed;
                }
            
        }
        break;
        case On:
        {
            if(IS_EVENT_TYPE_OF(evCanReceive_CanButton_id))
                {
                    rootState_subState = On;
                    rootState_active = On;
                    //#[ state ROOT.On.(Entry) 
                    decode();
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

//## event evCanReceive()
evCanReceive::evCanReceive() {
    setId(evCanReceive_CanButton_id);
}

bool evCanReceive::isTypeOf(short id) const {
    return (evCanReceive_CanButton_id==id);
}

//## event evstart()
evstart::evstart() {
    setId(evstart_CanButton_id);
}

bool evstart::isTypeOf(short id) const {
    return (evstart_CanButton_id==id);
}

//## event evRecieve()
evRecieve::evRecieve() {
    setId(evRecieve_CanButton_id);
}

bool evRecieve::isTypeOf(short id) const {
    return (evRecieve_CanButton_id==id);
}

//## event evFirstfloor()
evFirstfloor::evFirstfloor() {
    setId(evFirstfloor_CanButton_id);
}

bool evFirstfloor::isTypeOf(short id) const {
    return (evFirstfloor_CanButton_id==id);
}

//## event evButtoncall()
evButtoncall::evButtoncall() {
    setId(evButtoncall_CanButton_id);
}

bool evButtoncall::isTypeOf(short id) const {
    return (evButtoncall_CanButton_id==id);
}

//## event evMove()
evMove::evMove() {
    setId(evMove_CanButton_id);
}

bool evMove::isTypeOf(short id) const {
    return (evMove_CanButton_id==id);
}

//## event evDoor()
evDoor::evDoor() {
    setId(evDoor_CanButton_id);
}

bool evDoor::isTypeOf(short id) const {
    return (evDoor_CanButton_id==id);
}

//## event evDown()
evDown::evDown() {
    setId(evDown_CanButton_id);
}

bool evDown::isTypeOf(short id) const {
    return (evDown_CanButton_id==id);
}

//## event evCheck()
evCheck::evCheck() {
    setId(evCheck_CanButton_id);
}

bool evCheck::isTypeOf(short id) const {
    return (evCheck_CanButton_id==id);
}

/*********************************************************************
	File Path	: CanButtonTest/MontaVista/CanButton.cpp
*********************************************************************/
