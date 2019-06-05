/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: ReceiveMessageObj
//!	Generated Date	: Wed, 05, Jun 2019  
	File Path	: CanButtonTest/MontaVista/ReceiveMessageObj.h
*********************************************************************/

#ifndef ReceiveMessageObj_H
#define ReceiveMessageObj_H

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
//## link itsElevatorControl
class ElevatorControl_C;

//## package CanButton

//## class TopLevel::ReceiveMessageObj

extern int can_init(void);extern int send_can_frame(int id, unsigned char *data);

class ReceiveMessageObj_C : public OMReactive {
    ////    Constructors and destructors    ////
    
public :

    //## operation ReceiveMessageObj()
    ReceiveMessageObj_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~ReceiveMessageObj_C();
    
    ////    Operations    ////
    
    //## operation data()
    void data();
    
    ////    Additional operations    ////
    
    //## auto_generated
    ElevatorControl_C* getItsElevatorControl() const;
    
    //## auto_generated
    void setItsElevatorControl(ElevatorControl_C* p_ElevatorControl);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    ElevatorControl_C* itsElevatorControl;		//## link itsElevatorControl
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsElevatorControl(ElevatorControl_C* p_ElevatorControl);
    
    //## auto_generated
    void _setItsElevatorControl(ElevatorControl_C* p_ElevatorControl);
    
    //## auto_generated
    void _clearItsElevatorControl();
    
    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // MessageArrived:
    //## statechart_method
    inline bool MessageArrived_IN() const;
    
    // InitialState:
    //## statechart_method
    inline bool InitialState_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum ReceiveMessageObj_Enum {
        OMNonState = 0,
        MessageArrived = 1,
        InitialState = 2
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

inline bool ReceiveMessageObj_C::rootState_IN() const {
    return true;
}

inline bool ReceiveMessageObj_C::MessageArrived_IN() const {
    return rootState_subState == MessageArrived;
}

inline bool ReceiveMessageObj_C::InitialState_IN() const {
    return rootState_subState == InitialState;
}

#endif
/*********************************************************************
	File Path	: CanButtonTest/MontaVista/ReceiveMessageObj.h
*********************************************************************/
