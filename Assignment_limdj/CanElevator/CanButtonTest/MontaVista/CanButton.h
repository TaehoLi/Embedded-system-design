/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: CanButton
//!	Generated Date	: Wed, 05, Jun 2019  
	File Path	: CanButtonTest/MontaVista/CanButton.h
*********************************************************************/

#ifndef CanButton_H
#define CanButton_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include <oxf/event.h>
//## classInstance ElevatorControl
class ElevatorControl_C;

//## classInstance ReceiveMessageObj
class ReceiveMessageObj_C;

//#[ ignore
#define evMove_CanButton_id 28001

#define evDoor_CanButton_id 28002

#define evMessageReceived_CanButton_id 28003

#define evState_CanButton_id 28004

#define evMoveDown_CanButton_id 28005

#define evAtFirstFloor_CanButton_id 28006

#define evCalled_CanButton_id 28007
//#]

//## package CanButton


//## attribute check_floor
extern unsigned char check_floor[4];

//## attribute download_data_buf
extern unsigned char download_data_buf[8];

//## attribute height
extern int height;

//## attribute high_floor
extern int high_floor;

//## attribute upload_data_buf
extern unsigned char upload_data_buf[8];

//## classInstance ElevatorControl
extern ElevatorControl_C ElevatorControl;

//## classInstance ReceiveMessageObj
extern ReceiveMessageObj_C ReceiveMessageObj;

//## operation CanReceiveIsr()
void CanReceiveIsr();

//## auto_generated
void CanButton_initRelations();

//## auto_generated
bool CanButton_startBehavior();

//#[ ignore
class CanButton_OMInitializer {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    CanButton_OMInitializer();
    
    //## auto_generated
    ~CanButton_OMInitializer();
};
//#]

//## event evMove()
class evMove : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evMove();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evDoor()
class evDoor : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evDoor();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evMessageReceived()
class evMessageReceived : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evMessageReceived();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evState()
class evState : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evState();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evMoveDown()
class evMoveDown : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evMoveDown();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evAtFirstFloor()
class evAtFirstFloor : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evAtFirstFloor();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evCalled()
class evCalled : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evCalled();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

#endif
/*********************************************************************
	File Path	: CanButtonTest/MontaVista/CanButton.h
*********************************************************************/
