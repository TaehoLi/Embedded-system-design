/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: CanButton
//!	Generated Date	: Wed, 15, May 2019  
	File Path	: CanButtonTest/MontaVista/CanButton.h
*********************************************************************/

#ifndef CanButton_H
#define CanButton_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include <oxf/omreactive.h>
//## auto_generated
#include <oxf/state.h>
//## auto_generated
#include <oxf/event.h>
//## classInstance CanButton
class CanButton_C;

//## classInstance Elevator
class Elevator_C;

//#[ ignore
#define evCanReceive_CanButton_id 28001

#define evstart_CanButton_id 28002

#define evRecieve_CanButton_id 28003

#define evFirstfloor_CanButton_id 28004

#define evButtoncall_CanButton_id 28005

#define evMove_CanButton_id 28006

#define evDoor_CanButton_id 28007

#define evDown_CanButton_id 28008

#define evCheck_CanButton_id 28009
//#]

//## package CanButton

//## class TopLevel::CanButton

extern int can_init(void);extern int send_can_frame(int id, unsigned char *data);

//## attribute download_data_buf
extern unsigned char download_data_buf[8];

//## attribute floor_check
extern unsigned char floor_check[4];

//## attribute high_floor
extern int high_floor;

//## attribute high_pixel
extern int high_pixel;

//## attribute upload_data_buf
extern unsigned char upload_data_buf[8];

//## classInstance CanButton
extern CanButton_C CanButton;

//## classInstance Elevator
extern Elevator_C Elevator;

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

class CanButton_C : public OMReactive {
    ////    Constructors and destructors    ////
    
public :

    //## operation CanButton()
    CanButton_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~CanButton_C();
    
    ////    Operations    ////
    
    //## operation decode()
    void decode();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Elevator_C* getItsElevator() const;
    
    //## auto_generated
    void setItsElevator(Elevator_C* p_Elevator);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    Elevator_C* itsElevator;		//## link itsElevator
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsElevator(Elevator_C* p_Elevator);
    
    //## auto_generated
    void _setItsElevator(Elevator_C* p_Elevator);
    
    //## auto_generated
    void _clearItsElevator();
    
    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // On:
    //## statechart_method
    inline bool On_IN() const;
    
    // init:
    //## statechart_method
    inline bool init_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum CanButton_Enum {
        OMNonState = 0,
        On = 1,
        init = 2
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

//## event evCanReceive()
class evCanReceive : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evCanReceive();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evstart()
class evstart : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evstart();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evRecieve()
class evRecieve : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evRecieve();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evFirstfloor()
class evFirstfloor : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evFirstfloor();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evButtoncall()
class evButtoncall : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evButtoncall();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

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

//## event evDown()
class evDown : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evDown();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

//## event evCheck()
class evCheck : public OMEvent {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    evCheck();
    
    ////    Framework operations    ////
    
    //## statechart_method
    bool isTypeOf(short id) const;
};

inline bool CanButton_C::rootState_IN() const {
    return true;
}

inline bool CanButton_C::On_IN() const {
    return rootState_subState == On;
}

inline bool CanButton_C::init_IN() const {
    return rootState_subState == init;
}

#endif
/*********************************************************************
	File Path	: CanButtonTest/MontaVista/CanButton.h
*********************************************************************/
