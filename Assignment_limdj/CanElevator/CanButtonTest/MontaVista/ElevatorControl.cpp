/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: ElevatorControl
//!	Generated Date	: Wed, 05, Jun 2019  
	File Path	: CanButtonTest/MontaVista/ElevatorControl.cpp
*********************************************************************/

//## auto_generated
#include <oxf/omthread.h>
//## auto_generated
#include "ElevatorControl.h"
//## link itsReceiveMessageObj
#include "ReceiveMessageObj.h"
//## package CanButton

//## class TopLevel::ElevatorControl
ElevatorControl_C::ElevatorControl_C(IOxfActive* theActiveContext) : moving(true) {
    setActiveContext(theActiveContext, false);
    itsReceiveMessageObj = NULL;
    initStatechart();
}

ElevatorControl_C::~ElevatorControl_C() {
    cleanUpRelations();
    cancelTimeouts();
}

void ElevatorControl_C::check() {
    //#[ operation check()
    if(moving == true)
    {
    	for(int i=3; i>-1; i--)
    	{
    		if(check_floor[i] == 1)
    		{
    			high_floor = i+2;
    			break;
    		}		
    	}
    	
    	if(height == high_floor*80)
    	{
    		check_floor[high_floor-2] = 0;
    		GEN(evDoor);     
    	}
    	else
    		GEN(evMove);    
    		  
    }
    
    else if(moving == false)
    {
    	int i = 1;
    	high_floor = 1;
    	while(height/80 >= i)
    	{
    		if(check_floor[i-1] == 1)
    			high_floor = i+1;
    		i++;
    	}
    	
    	if(height == high_floor*80)
    	{
    		check_floor[high_floor-2] = 0;
    		GEN(evDoor);
    	}
    	else
    		GEN(evMove);
    }
    //#]
}

void ElevatorControl_C::moveDown() {
    //#[ operation moveDown()
    upload_data_buf[0] = 1;
    upload_data_buf[1] = 2;
    
    send_can_frame(1, upload_data_buf);
    //#]
}

void ElevatorControl_C::moveUp() {
    //#[ operation moveUp()
    upload_data_buf[0] = 1;
    upload_data_buf[1] = 1;
    
    send_can_frame(1, upload_data_buf);
    //#]
}

bool ElevatorControl_C::getMoving() const {
    return moving;
}

void ElevatorControl_C::setMoving(bool p_moving) {
    moving = p_moving;
}

ReceiveMessageObj_C* ElevatorControl_C::getItsReceiveMessageObj() const {
    return itsReceiveMessageObj;
}

void ElevatorControl_C::setItsReceiveMessageObj(ReceiveMessageObj_C* p_ReceiveMessageObj) {
    if(p_ReceiveMessageObj != NULL)
        {
            p_ReceiveMessageObj->_setItsElevatorControl(this);
        }
    _setItsReceiveMessageObj(p_ReceiveMessageObj);
}

bool ElevatorControl_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void ElevatorControl_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    MovingUp_subState = OMNonState;
    MovingUp_timeout = NULL;
    MovingDown_subState = OMNonState;
    MovingDown_timeout = NULL;
}

void ElevatorControl_C::cleanUpRelations() {
    if(itsReceiveMessageObj != NULL)
        {
            ElevatorControl_C* p_ElevatorControl = itsReceiveMessageObj->getItsElevatorControl();
            if(p_ElevatorControl != NULL)
                {
                    itsReceiveMessageObj->__setItsElevatorControl(NULL);
                }
            itsReceiveMessageObj = NULL;
        }
}

void ElevatorControl_C::cancelTimeouts() {
    if(MovingUp_timeout != NULL)
        {
            MovingUp_timeout->cancel();
            MovingUp_timeout = NULL;
        }
    if(MovingDown_timeout != NULL)
        {
            MovingDown_timeout->cancel();
            MovingDown_timeout = NULL;
        }
}

bool ElevatorControl_C::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(MovingUp_timeout == arg)
        {
            MovingUp_timeout = NULL;
            res = true;
        }
    if(MovingDown_timeout == arg)
        {
            MovingDown_timeout = NULL;
            res = true;
        }
    return res;
}

void ElevatorControl_C::__setItsReceiveMessageObj(ReceiveMessageObj_C* p_ReceiveMessageObj) {
    itsReceiveMessageObj = p_ReceiveMessageObj;
}

void ElevatorControl_C::_setItsReceiveMessageObj(ReceiveMessageObj_C* p_ReceiveMessageObj) {
    if(itsReceiveMessageObj != NULL)
        {
            itsReceiveMessageObj->__setItsElevatorControl(NULL);
        }
    __setItsReceiveMessageObj(p_ReceiveMessageObj);
}

void ElevatorControl_C::_clearItsReceiveMessageObj() {
    itsReceiveMessageObj = NULL;
}

void ElevatorControl_C::rootState_entDef() {
    {
        rootState_subState = Idle;
        rootState_active = Idle;
        //#[ state ROOT.Idle.(Entry) 
        moving = true;
        //#]
    }
}

IOxfReactive::TakeEventStatus ElevatorControl_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        case Idle:
        {
            if(IS_EVENT_TYPE_OF(evCalled_CanButton_id))
                {
                    MovingUp_entDef();
                    res = eventConsumed;
                }
            
        }
        break;
        case Moving:
        {
            if(IS_EVENT_TYPE_OF(evMove_CanButton_id))
                {
                    MovingUp_subState = state;
                    rootState_active = state;
                    //#[ state ROOT.MovingUp.state.(Entry) 
                    check();
                    //#]
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = MovingUp_handleEvent();
                }
        }
        break;
        case state:
        {
            res = state_handleEvent();
        }
        break;
        case OffLamp:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == MovingUp_timeout)
                        {
                            if(MovingUp_timeout != NULL)
                                {
                                    MovingUp_timeout->cancel();
                                    MovingUp_timeout = NULL;
                                }
                            MovingUp_subState = OpenDoor;
                            rootState_active = OpenDoor;
                            //#[ state ROOT.MovingUp.OpenDoor.(Entry) 
                            upload_data_buf[0] = 2;
                            upload_data_buf[1] = 1;
                            
                            send_can_frame(1, upload_data_buf);
                            //#]
                            MovingUp_timeout = scheduleTimeout(2000, NULL);
                            res = eventConsumed;
                        }
                }
            
            if(res == eventNotConsumed)
                {
                    res = MovingUp_handleEvent();
                }
        }
        break;
        case OpenDoor:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == MovingUp_timeout)
                        {
                            if(MovingUp_timeout != NULL)
                                {
                                    MovingUp_timeout->cancel();
                                    MovingUp_timeout = NULL;
                                }
                            MovingUp_subState = CloseDoor;
                            rootState_active = CloseDoor;
                            //#[ state ROOT.MovingUp.CloseDoor.(Entry) 
                            upload_data_buf[0] = 2;
                            upload_data_buf[1] = 2;
                            
                            send_can_frame(1, upload_data_buf);
                            GEN(evMoveDown);
                            //#]
                            res = eventConsumed;
                        }
                }
            
            if(res == eventNotConsumed)
                {
                    res = MovingUp_handleEvent();
                }
        }
        break;
        case CloseDoor:
        {
            res = MovingUp_handleEvent();
        }
        break;
        case MovingDown_Moving:
        {
            if(IS_EVENT_TYPE_OF(evMove_CanButton_id))
                {
                    MovingDown_subState = MovingDown_state;
                    rootState_active = MovingDown_state;
                    //#[ state ROOT.MovingDown.state.(Entry) 
                    check();
                    //#]
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = MovingDown_handleEvent();
                }
        }
        break;
        case MovingDown_state:
        {
            if(IS_EVENT_TYPE_OF(evMove_CanButton_id))
                {
                    MovingDown_subState = MovingDown_Moving;
                    rootState_active = MovingDown_Moving;
                    //#[ state ROOT.MovingDown.Moving.(Entry) 
                    moving = false;
                    moveDown();
                    //#]
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evDoor_CanButton_id))
                {
                    MovingDown_subState = MovingDown_OffLamp;
                    rootState_active = MovingDown_OffLamp;
                    //#[ state ROOT.MovingDown.OffLamp.(Entry) 
                    upload_data_buf[0] = 1;
                    upload_data_buf[1] = 0;
                    send_can_frame(1, upload_data_buf);
                    
                    upload_data_buf[0] = 3;
                    upload_data_buf[1] = high_floor;
                    upload_data_buf[2] = 2;
                    send_can_frame(1, upload_data_buf);
                    //#]
                    MovingDown_timeout = scheduleTimeout(500, NULL);
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = MovingDown_handleEvent();
                }
        }
        break;
        case MovingDown_OffLamp:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == MovingDown_timeout)
                        {
                            if(MovingDown_timeout != NULL)
                                {
                                    MovingDown_timeout->cancel();
                                    MovingDown_timeout = NULL;
                                }
                            MovingDown_subState = MovingDown_OpenDoor;
                            rootState_active = MovingDown_OpenDoor;
                            //#[ state ROOT.MovingDown.OpenDoor.(Entry) 
                            upload_data_buf[0] = 2;
                            upload_data_buf[1] = 1;
                            
                            send_can_frame(1, upload_data_buf);
                            //#]
                            MovingDown_timeout = scheduleTimeout(2000, NULL);
                            res = eventConsumed;
                        }
                }
            
            if(res == eventNotConsumed)
                {
                    res = MovingDown_handleEvent();
                }
        }
        break;
        case MovingDown_OpenDoor:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == MovingDown_timeout)
                        {
                            if(MovingDown_timeout != NULL)
                                {
                                    MovingDown_timeout->cancel();
                                    MovingDown_timeout = NULL;
                                }
                            MovingDown_subState = MovingDown_CloseDoor;
                            rootState_active = MovingDown_CloseDoor;
                            //#[ state ROOT.MovingDown.CloseDoor.(Entry) 
                            upload_data_buf[0] = 2;
                            upload_data_buf[1] = 2;
                            send_can_frame(1, upload_data_buf);
                            
                            if(high_floor == 1)
                             GEN(evAtFirstFloor);
                            else GEN(evState);
                            //#]
                            res = eventConsumed;
                        }
                }
            
            if(res == eventNotConsumed)
                {
                    res = MovingDown_handleEvent();
                }
        }
        break;
        case MovingDown_CloseDoor:
        {
            if(IS_EVENT_TYPE_OF(evState_CanButton_id))
                {
                    MovingDown_subState = MovingDown_state;
                    rootState_active = MovingDown_state;
                    //#[ state ROOT.MovingDown.state.(Entry) 
                    check();
                    //#]
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = MovingDown_handleEvent();
                }
        }
        break;
        case FirstFloor_check:
        {
            if(IS_EVENT_TYPE_OF(evMove_CanButton_id))
                {
                    MovingUp_entDef();
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evAtFirstFloor_CanButton_id))
                {
                    rootState_subState = Idle;
                    rootState_active = Idle;
                    //#[ state ROOT.Idle.(Entry) 
                    moving = true;
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

void ElevatorControl_C::MovingUp_entDef() {
    rootState_subState = MovingUp;
    MovingUp_subState = Moving;
    rootState_active = Moving;
    //#[ state ROOT.MovingUp.Moving.(Entry) 
    moving = true;
    moveUp();
    //#]
}

void ElevatorControl_C::MovingUp_exit() {
    switch (MovingUp_subState) {
        case OffLamp:
        {
            if(MovingUp_timeout != NULL)
                {
                    MovingUp_timeout->cancel();
                    MovingUp_timeout = NULL;
                }
        }
        break;
        case OpenDoor:
        {
            if(MovingUp_timeout != NULL)
                {
                    MovingUp_timeout->cancel();
                    MovingUp_timeout = NULL;
                }
        }
        break;
        
        default:
            break;
    }
    MovingUp_subState = OMNonState;
    
}

IOxfReactive::TakeEventStatus ElevatorControl_C::MovingUp_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evMoveDown_CanButton_id))
        {
            MovingUp_exit();
            MovingDown_entDef();
            res = eventConsumed;
        }
    
    return res;
}

IOxfReactive::TakeEventStatus ElevatorControl_C::state_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evMove_CanButton_id))
        {
            MovingUp_subState = Moving;
            rootState_active = Moving;
            //#[ state ROOT.MovingUp.Moving.(Entry) 
            moving = true;
            moveUp();
            //#]
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(evDoor_CanButton_id))
        {
            MovingUp_subState = OffLamp;
            rootState_active = OffLamp;
            //#[ state ROOT.MovingUp.OffLamp.(Entry) 
            upload_data_buf[0] = 1;
            upload_data_buf[1] = 0;
            send_can_frame(1, upload_data_buf);
            
            upload_data_buf[0] = 3;
            upload_data_buf[1] = high_floor;
            upload_data_buf[2] = 2;
            send_can_frame(1, upload_data_buf);
            //#]
            MovingUp_timeout = scheduleTimeout(500, NULL);
            res = eventConsumed;
        }
    
    if(res == eventNotConsumed)
        {
            res = MovingUp_handleEvent();
        }
    return res;
}

void ElevatorControl_C::MovingDown_entDef() {
    rootState_subState = MovingDown;
    MovingDown_subState = MovingDown_Moving;
    rootState_active = MovingDown_Moving;
    //#[ state ROOT.MovingDown.Moving.(Entry) 
    moving = false;
    moveDown();
    //#]
}

void ElevatorControl_C::MovingDown_exit() {
    switch (MovingDown_subState) {
        case MovingDown_OffLamp:
        {
            if(MovingDown_timeout != NULL)
                {
                    MovingDown_timeout->cancel();
                    MovingDown_timeout = NULL;
                }
        }
        break;
        case MovingDown_OpenDoor:
        {
            if(MovingDown_timeout != NULL)
                {
                    MovingDown_timeout->cancel();
                    MovingDown_timeout = NULL;
                }
        }
        break;
        
        default:
            break;
    }
    MovingDown_subState = OMNonState;
    
}

IOxfReactive::TakeEventStatus ElevatorControl_C::MovingDown_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evAtFirstFloor_CanButton_id))
        {
            MovingDown_exit();
            rootState_subState = FirstFloor_check;
            rootState_active = FirstFloor_check;
            //#[ state ROOT.FirstFloor_check.(Entry) 
            int i = 0;
            
            for(i=0; i<4; i++)
            {
             if(check_floor[i] == 1)
              GEN(evMove);
            }
            
            GEN(evAtFirstFloor);
            //#]
            res = eventConsumed;
        }
    
    return res;
}

/*********************************************************************
	File Path	: CanButtonTest/MontaVista/ElevatorControl.cpp
*********************************************************************/
