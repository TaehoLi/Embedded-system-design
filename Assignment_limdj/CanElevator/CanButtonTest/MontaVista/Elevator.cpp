/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: Elevator
//!	Generated Date	: Wed, 15, May 2019  
	File Path	: CanButtonTest/MontaVista/Elevator.cpp
*********************************************************************/

//## auto_generated
#include <oxf/omthread.h>
//## auto_generated
#include "Elevator.h"
//## link itsCanButton
#include "CanButton.h"
//## package CanButton

//## class TopLevel::Elevator
Elevator_C::Elevator_C(IOxfActive* theActiveContext) : upstate(true) {
    setActiveContext(theActiveContext, false);
    itsCanButton = NULL;
    initStatechart();
}

Elevator_C::~Elevator_C() {
    cleanUpRelations();
    cancelTimeouts();
}

void Elevator_C::array_check() {
    //#[ operation array_check()
    if(upstate==true){
    	for(int i=3;i>-1;i--){
    		if(floor_check[i]==1){
    			high_floor=i+2;
    			break;
    		}		
    	}
    	
    	if(high_pixel==high_floor*80){
    		floor_check[high_floor-2]=0;
    		GEN(evDoor);     
    	}
    	else
    		GEN(evMove);    
    		  
    }
    
    else if(upstate==false){
    	int i=1;
    	high_floor=1;
    	while(high_pixel/80>=i){
    		if(floor_check[i-1]==1)
    			high_floor=i+1;
    		i++;
    	}
    	
    	if(high_pixel==(high_floor)*80){
    		floor_check[high_floor-2]=0;
    		GEN(evDoor);
    	}
    	else
    		GEN(evMove);
    }
    //#]
}

void Elevator_C::move_down() {
    //#[ operation move_down()
    upload_data_buf[0]=1;
    upload_data_buf[1]=2;
    
    send_can_frame(1,upload_data_buf);
    //#]
}

void Elevator_C::move_up() {
    //#[ operation move_up()
    upload_data_buf[0]=1;
    upload_data_buf[1]=1;
    
    send_can_frame(1,upload_data_buf);
    //#]
}

bool Elevator_C::getUpstate() const {
    return upstate;
}

void Elevator_C::setUpstate(bool p_upstate) {
    upstate = p_upstate;
}

CanButton_C* Elevator_C::getItsCanButton() const {
    return itsCanButton;
}

void Elevator_C::setItsCanButton(CanButton_C* p_CanButton) {
    if(p_CanButton != NULL)
        {
            p_CanButton->_setItsElevator(this);
        }
    _setItsCanButton(p_CanButton);
}

bool Elevator_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Elevator_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    up_subState = OMNonState;
    up_timeout = NULL;
    down_subState = OMNonState;
    down_timeout = NULL;
}

void Elevator_C::cleanUpRelations() {
    if(itsCanButton != NULL)
        {
            Elevator_C* p_Elevator = itsCanButton->getItsElevator();
            if(p_Elevator != NULL)
                {
                    itsCanButton->__setItsElevator(NULL);
                }
            itsCanButton = NULL;
        }
}

void Elevator_C::cancelTimeouts() {
    if(up_timeout != NULL)
        {
            up_timeout->cancel();
            up_timeout = NULL;
        }
    if(down_timeout != NULL)
        {
            down_timeout->cancel();
            down_timeout = NULL;
        }
}

bool Elevator_C::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(up_timeout == arg)
        {
            up_timeout = NULL;
            res = true;
        }
    if(down_timeout == arg)
        {
            down_timeout = NULL;
            res = true;
        }
    return res;
}

void Elevator_C::__setItsCanButton(CanButton_C* p_CanButton) {
    itsCanButton = p_CanButton;
}

void Elevator_C::_setItsCanButton(CanButton_C* p_CanButton) {
    if(itsCanButton != NULL)
        {
            itsCanButton->__setItsElevator(NULL);
        }
    __setItsCanButton(p_CanButton);
}

void Elevator_C::_clearItsCanButton() {
    itsCanButton = NULL;
}

void Elevator_C::rootState_entDef() {
    {
        rootState_subState = init;
        rootState_active = init;
        //#[ state ROOT.init.(Entry) 
        upstate=true;
        //#]
    }
}

IOxfReactive::TakeEventStatus Elevator_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        case init:
        {
            if(IS_EVENT_TYPE_OF(evButtoncall_CanButton_id))
                {
                    up_entDef();
                    res = eventConsumed;
                }
            
        }
        break;
        case moving:
        {
            if(IS_EVENT_TYPE_OF(evMove_CanButton_id))
                {
                    up_subState = check;
                    rootState_active = check;
                    //#[ state ROOT.up.check.(Entry) 
                    array_check();
                    //#]
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = up_handleEvent();
                }
        }
        break;
        case check:
        {
            res = check_handleEvent();
        }
        break;
        case stop:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == up_timeout)
                        {
                            if(up_timeout != NULL)
                                {
                                    up_timeout->cancel();
                                    up_timeout = NULL;
                                }
                            up_subState = open;
                            rootState_active = open;
                            //#[ state ROOT.up.open.(Entry) 
                            upload_data_buf[0]=2;
                            upload_data_buf[1]=1;
                            
                            send_can_frame(1,upload_data_buf);
                            //#]
                            up_timeout = scheduleTimeout(300, NULL);
                            res = eventConsumed;
                        }
                }
            
            if(res == eventNotConsumed)
                {
                    res = up_handleEvent();
                }
        }
        break;
        case open:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == up_timeout)
                        {
                            if(up_timeout != NULL)
                                {
                                    up_timeout->cancel();
                                    up_timeout = NULL;
                                }
                            up_subState = close;
                            rootState_active = close;
                            //#[ state ROOT.up.close.(Entry) 
                            upload_data_buf[0]=2;
                            upload_data_buf[1]=2;
                            
                            send_can_frame(1,upload_data_buf);
                            GEN(evDown);
                            //#]
                            res = eventConsumed;
                        }
                }
            
            if(res == eventNotConsumed)
                {
                    res = up_handleEvent();
                }
        }
        break;
        case close:
        {
            res = up_handleEvent();
        }
        break;
        case down_moving:
        {
            if(IS_EVENT_TYPE_OF(evMove_CanButton_id))
                {
                    down_subState = down_check;
                    rootState_active = down_check;
                    //#[ state ROOT.down.check.(Entry) 
                    array_check();
                    //#]
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = down_handleEvent();
                }
        }
        break;
        case down_check:
        {
            if(IS_EVENT_TYPE_OF(evMove_CanButton_id))
                {
                    down_subState = down_moving;
                    rootState_active = down_moving;
                    //#[ state ROOT.down.moving.(Entry) 
                    upstate=false;
                    move_down();
                    //#]
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evDoor_CanButton_id))
                {
                    down_subState = down_stop;
                    rootState_active = down_stop;
                    //#[ state ROOT.down.stop.(Entry) 
                    upload_data_buf[0]=1;
                    upload_data_buf[1]=0;
                    send_can_frame(1,upload_data_buf);
                    
                    upload_data_buf[0]=3;
                    upload_data_buf[1]=high_floor;
                    upload_data_buf[2]=2;
                    send_can_frame(1,upload_data_buf);
                    //#]
                    down_timeout = scheduleTimeout(300, NULL);
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = down_handleEvent();
                }
        }
        break;
        case down_stop:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == down_timeout)
                        {
                            if(down_timeout != NULL)
                                {
                                    down_timeout->cancel();
                                    down_timeout = NULL;
                                }
                            down_subState = down_open;
                            rootState_active = down_open;
                            //#[ state ROOT.down.open.(Entry) 
                            upload_data_buf[0]=2;
                            upload_data_buf[1]=1;
                            
                            send_can_frame(1,upload_data_buf);
                            //#]
                            down_timeout = scheduleTimeout(300, NULL);
                            res = eventConsumed;
                        }
                }
            
            if(res == eventNotConsumed)
                {
                    res = down_handleEvent();
                }
        }
        break;
        case down_open:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == down_timeout)
                        {
                            if(down_timeout != NULL)
                                {
                                    down_timeout->cancel();
                                    down_timeout = NULL;
                                }
                            down_subState = down_close;
                            rootState_active = down_close;
                            //#[ state ROOT.down.close.(Entry) 
                            upload_data_buf[0]=2;
                            upload_data_buf[1]=2;
                            send_can_frame(1,upload_data_buf);
                            if(high_floor==1)
                             GEN(evFirstfloor);
                            else
                             GEN(evCheck);
                            //#]
                            res = eventConsumed;
                        }
                }
            
            if(res == eventNotConsumed)
                {
                    res = down_handleEvent();
                }
        }
        break;
        case down_close:
        {
            if(IS_EVENT_TYPE_OF(evCheck_CanButton_id))
                {
                    down_subState = down_check;
                    rootState_active = down_check;
                    //#[ state ROOT.down.check.(Entry) 
                    array_check();
                    //#]
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = down_handleEvent();
                }
        }
        break;
        case first_floor_check:
        {
            if(IS_EVENT_TYPE_OF(evMove_CanButton_id))
                {
                    up_entDef();
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evFirstfloor_CanButton_id))
                {
                    rootState_subState = init;
                    rootState_active = init;
                    //#[ state ROOT.init.(Entry) 
                    upstate=true;
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

void Elevator_C::up_entDef() {
    rootState_subState = up;
    up_subState = moving;
    rootState_active = moving;
    //#[ state ROOT.up.moving.(Entry) 
    upstate=true;
    move_up();
    //#]
}

void Elevator_C::up_exit() {
    switch (up_subState) {
        case stop:
        {
            if(up_timeout != NULL)
                {
                    up_timeout->cancel();
                    up_timeout = NULL;
                }
        }
        break;
        case open:
        {
            if(up_timeout != NULL)
                {
                    up_timeout->cancel();
                    up_timeout = NULL;
                }
        }
        break;
        
        default:
            break;
    }
    up_subState = OMNonState;
    
}

IOxfReactive::TakeEventStatus Elevator_C::up_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evDown_CanButton_id))
        {
            up_exit();
            down_entDef();
            res = eventConsumed;
        }
    
    return res;
}

IOxfReactive::TakeEventStatus Elevator_C::check_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evMove_CanButton_id))
        {
            up_subState = moving;
            rootState_active = moving;
            //#[ state ROOT.up.moving.(Entry) 
            upstate=true;
            move_up();
            //#]
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(evDoor_CanButton_id))
        {
            up_subState = stop;
            rootState_active = stop;
            //#[ state ROOT.up.stop.(Entry) 
            upload_data_buf[0]=1;
            upload_data_buf[1]=0;
            send_can_frame(1,upload_data_buf);
            
            upload_data_buf[0]=3;
            upload_data_buf[1]=high_floor;
            upload_data_buf[2]=2;
            send_can_frame(1,upload_data_buf);
            //#]
            up_timeout = scheduleTimeout(300, NULL);
            res = eventConsumed;
        }
    
    if(res == eventNotConsumed)
        {
            res = up_handleEvent();
        }
    return res;
}

void Elevator_C::down_entDef() {
    rootState_subState = down;
    down_subState = down_moving;
    rootState_active = down_moving;
    //#[ state ROOT.down.moving.(Entry) 
    upstate=false;
    move_down();
    //#]
}

void Elevator_C::down_exit() {
    switch (down_subState) {
        case down_stop:
        {
            if(down_timeout != NULL)
                {
                    down_timeout->cancel();
                    down_timeout = NULL;
                }
        }
        break;
        case down_open:
        {
            if(down_timeout != NULL)
                {
                    down_timeout->cancel();
                    down_timeout = NULL;
                }
        }
        break;
        
        default:
            break;
    }
    down_subState = OMNonState;
    
}

IOxfReactive::TakeEventStatus Elevator_C::down_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evFirstfloor_CanButton_id))
        {
            down_exit();
            rootState_subState = first_floor_check;
            rootState_active = first_floor_check;
            //#[ state ROOT.first_floor_check.(Entry) 
            int i=0;
            
            for(i=0;i<4;i++){
             if(floor_check[i]==1)
              GEN(evMove);
            }
            GEN(evFirstfloor);
            //#]
            res = eventConsumed;
        }
    
    return res;
}

/*********************************************************************
	File Path	: CanButtonTest/MontaVista/Elevator.cpp
*********************************************************************/
