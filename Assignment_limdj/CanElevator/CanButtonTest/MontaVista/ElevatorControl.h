/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: ElevatorControl
//!	Generated Date	: Wed, 05, Jun 2019  
	File Path	: CanButtonTest/MontaVista/ElevatorControl.h
*********************************************************************/

#ifndef ElevatorControl_H
#define ElevatorControl_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include "CanButton.h"
//## auto_generated
#include <oxf/omreactive.h>
//## auto_generated
#include <oxf/state.h>
//## auto_generated
#include <oxf/event.h>
//## link itsReceiveMessageObj
class ReceiveMessageObj_C;

//## package CanButton

//## class TopLevel::ElevatorControl
class ElevatorControl_C : public OMReactive {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    ElevatorControl_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~ElevatorControl_C();
    
    ////    Operations    ////
    
    //## operation check()
    void check();
    
    //## operation moveDown()
    void moveDown();
    
    //## operation moveUp()
    void moveUp();
    
    ////    Additional operations    ////
    
    //## auto_generated
    bool getMoving() const;
    
    //## auto_generated
    void setMoving(bool p_moving);
    
    //## auto_generated
    ReceiveMessageObj_C* getItsReceiveMessageObj() const;
    
    //## auto_generated
    void setItsReceiveMessageObj(ReceiveMessageObj_C* p_ReceiveMessageObj);
    
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
    
    bool moving;		//## attribute moving
    
    ////    Relations and components    ////
    
    ReceiveMessageObj_C* itsReceiveMessageObj;		//## link itsReceiveMessageObj
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsReceiveMessageObj(ReceiveMessageObj_C* p_ReceiveMessageObj);
    
    //## auto_generated
    void _setItsReceiveMessageObj(ReceiveMessageObj_C* p_ReceiveMessageObj);
    
    //## auto_generated
    void _clearItsReceiveMessageObj();
    
    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // MovingUp:
    //## statechart_method
    inline bool MovingUp_IN() const;
    
    //## statechart_method
    void MovingUp_entDef();
    
    //## statechart_method
    void MovingUp_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus MovingUp_handleEvent();
    
    // state:
    //## statechart_method
    inline bool state_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_handleEvent();
    
    // OpenDoor:
    //## statechart_method
    inline bool OpenDoor_IN() const;
    
    // OffLamp:
    //## statechart_method
    inline bool OffLamp_IN() const;
    
    // Moving:
    //## statechart_method
    inline bool Moving_IN() const;
    
    // CloseDoor:
    //## statechart_method
    inline bool CloseDoor_IN() const;
    
    // MovingDown:
    //## statechart_method
    inline bool MovingDown_IN() const;
    
    //## statechart_method
    void MovingDown_entDef();
    
    //## statechart_method
    void MovingDown_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus MovingDown_handleEvent();
    
    // MovingDown_state:
    //## statechart_method
    inline bool MovingDown_state_IN() const;
    
    // MovingDown_OpenDoor:
    //## statechart_method
    inline bool MovingDown_OpenDoor_IN() const;
    
    // MovingDown_OffLamp:
    //## statechart_method
    inline bool MovingDown_OffLamp_IN() const;
    
    // MovingDown_Moving:
    //## statechart_method
    inline bool MovingDown_Moving_IN() const;
    
    // MovingDown_CloseDoor:
    //## statechart_method
    inline bool MovingDown_CloseDoor_IN() const;
    
    // Idle:
    //## statechart_method
    inline bool Idle_IN() const;
    
    // FirstFloor_check:
    //## statechart_method
    inline bool FirstFloor_check_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum ElevatorControl_Enum {
        OMNonState = 0,
        MovingUp = 1,
        state = 2,
        OpenDoor = 3,
        OffLamp = 4,
        Moving = 5,
        CloseDoor = 6,
        MovingDown = 7,
        MovingDown_state = 8,
        MovingDown_OpenDoor = 9,
        MovingDown_OffLamp = 10,
        MovingDown_Moving = 11,
        MovingDown_CloseDoor = 12,
        Idle = 13,
        FirstFloor_check = 14
    };
    
    int rootState_subState;
    
    int rootState_active;
    
    int MovingUp_subState;
    
    IOxfTimeout* MovingUp_timeout;
    
    int MovingDown_subState;
    
    IOxfTimeout* MovingDown_timeout;
//#]
};

inline bool ElevatorControl_C::rootState_IN() const {
    return true;
}

inline bool ElevatorControl_C::MovingUp_IN() const {
    return rootState_subState == MovingUp;
}

inline bool ElevatorControl_C::state_IN() const {
    return MovingUp_subState == state;
}

inline bool ElevatorControl_C::OpenDoor_IN() const {
    return MovingUp_subState == OpenDoor;
}

inline bool ElevatorControl_C::OffLamp_IN() const {
    return MovingUp_subState == OffLamp;
}

inline bool ElevatorControl_C::Moving_IN() const {
    return MovingUp_subState == Moving;
}

inline bool ElevatorControl_C::CloseDoor_IN() const {
    return MovingUp_subState == CloseDoor;
}

inline bool ElevatorControl_C::MovingDown_IN() const {
    return rootState_subState == MovingDown;
}

inline bool ElevatorControl_C::MovingDown_state_IN() const {
    return MovingDown_subState == MovingDown_state;
}

inline bool ElevatorControl_C::MovingDown_OpenDoor_IN() const {
    return MovingDown_subState == MovingDown_OpenDoor;
}

inline bool ElevatorControl_C::MovingDown_OffLamp_IN() const {
    return MovingDown_subState == MovingDown_OffLamp;
}

inline bool ElevatorControl_C::MovingDown_Moving_IN() const {
    return MovingDown_subState == MovingDown_Moving;
}

inline bool ElevatorControl_C::MovingDown_CloseDoor_IN() const {
    return MovingDown_subState == MovingDown_CloseDoor;
}

inline bool ElevatorControl_C::Idle_IN() const {
    return rootState_subState == Idle;
}

inline bool ElevatorControl_C::FirstFloor_check_IN() const {
    return rootState_subState == FirstFloor_check;
}

#endif
/*********************************************************************
	File Path	: CanButtonTest/MontaVista/ElevatorControl.h
*********************************************************************/
