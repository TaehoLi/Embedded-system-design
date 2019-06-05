/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: CanButton
//!	Generated Date	: Wed, 05, Jun 2019  
	File Path	: CanButtonTest/MontaVista/CanButton.cpp
*********************************************************************/

//## auto_generated
#include "CanButton.h"
//## classInstance ElevatorControl
#include "ElevatorControl.h"
//## classInstance ReceiveMessageObj
#include "ReceiveMessageObj.h"
//## package CanButton


//## attribute check_floor
unsigned char check_floor[4];

//## attribute download_data_buf
unsigned char download_data_buf[8];

//## attribute height
int height;

//## attribute high_floor
int high_floor(1);

//## attribute upload_data_buf
unsigned char upload_data_buf[8];

//## classInstance ElevatorControl
ElevatorControl_C ElevatorControl;

//## classInstance ReceiveMessageObj
ReceiveMessageObj_C ReceiveMessageObj;

//## operation CanReceiveIsr()
void CanReceiveIsr() {
    //#[ operation CanReceiveIsr()
    ReceiveMessageObj.GEN(evMessageReceived());
    //#]
}

void CanButton_initRelations() {
    {
        {
            ReceiveMessageObj.setShouldDelete(false);
        }
        {
            ElevatorControl.setShouldDelete(false);
        }
    }
    ReceiveMessageObj.setItsElevatorControl(&ElevatorControl);
}

bool CanButton_startBehavior() {
    bool done = true;
    done &= ElevatorControl.startBehavior();
    done &= ReceiveMessageObj.startBehavior();
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

//## event evMessageReceived()
evMessageReceived::evMessageReceived() {
    setId(evMessageReceived_CanButton_id);
}

bool evMessageReceived::isTypeOf(short id) const {
    return (evMessageReceived_CanButton_id==id);
}

//## event evState()
evState::evState() {
    setId(evState_CanButton_id);
}

bool evState::isTypeOf(short id) const {
    return (evState_CanButton_id==id);
}

//## event evMoveDown()
evMoveDown::evMoveDown() {
    setId(evMoveDown_CanButton_id);
}

bool evMoveDown::isTypeOf(short id) const {
    return (evMoveDown_CanButton_id==id);
}

//## event evAtFirstFloor()
evAtFirstFloor::evAtFirstFloor() {
    setId(evAtFirstFloor_CanButton_id);
}

bool evAtFirstFloor::isTypeOf(short id) const {
    return (evAtFirstFloor_CanButton_id==id);
}

//## event evCalled()
evCalled::evCalled() {
    setId(evCalled_CanButton_id);
}

bool evCalled::isTypeOf(short id) const {
    return (evCalled_CanButton_id==id);
}

/*********************************************************************
	File Path	: CanButtonTest/MontaVista/CanButton.cpp
*********************************************************************/
