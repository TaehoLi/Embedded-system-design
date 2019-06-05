/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: Move
//!	Generated Date	: Wed, 15, May 2019  
	File Path	: CanButtonTest/MontaVista/Move.h
*********************************************************************/

#ifndef Move_H
#define Move_H

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
//## link itsCanButton
class CanButton_C;

//## package CanButton

//## class TopLevel::Move
class Move_C : public OMReactive {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    Move_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Move_C();
    
    ////    Operations    ////
    
    //## operation array_check()
    void array_check();
    
    //## operation move_down()
    void move_down();
    
    //## operation move_up()
    void move_up();
    
    ////    Additional operations    ////
    
    //## auto_generated
    bool getUpstate() const;
    
    //## auto_generated
    void setUpstate(bool p_upstate);
    
    //## auto_generated
    CanButton_C* getItsCanButton() const;
    
    //## auto_generated
    void setItsCanButton(CanButton_C* p_CanButton);
    
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
    
    bool upstate;		//## attribute upstate
    
    ////    Relations and components    ////
    
    CanButton_C* itsCanButton;		//## link itsCanButton
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsCanButton(CanButton_C* p_CanButton);
    
    //## auto_generated
    void _setItsCanButton(CanButton_C* p_CanButton);
    
    //## auto_generated
    void _clearItsCanButton();
    
    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // up:
    //## statechart_method
    inline bool up_IN() const;
    
    //## statechart_method
    void up_entDef();
    
    //## statechart_method
    void up_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus up_handleEvent();
    
    // stop:
    //## statechart_method
    inline bool stop_IN() const;
    
    // open:
    //## statechart_method
    inline bool open_IN() const;
    
    // moving:
    //## statechart_method
    inline bool moving_IN() const;
    
    // close:
    //## statechart_method
    inline bool close_IN() const;
    
    // check:
    //## statechart_method
    inline bool check_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus check_handleEvent();
    
    // init:
    //## statechart_method
    inline bool init_IN() const;
    
    // first_floor_check:
    //## statechart_method
    inline bool first_floor_check_IN() const;
    
    // down:
    //## statechart_method
    inline bool down_IN() const;
    
    //## statechart_method
    void down_entDef();
    
    //## statechart_method
    void down_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus down_handleEvent();
    
    // down_stop:
    //## statechart_method
    inline bool down_stop_IN() const;
    
    // down_open:
    //## statechart_method
    inline bool down_open_IN() const;
    
    // down_moving:
    //## statechart_method
    inline bool down_moving_IN() const;
    
    // down_close:
    //## statechart_method
    inline bool down_close_IN() const;
    
    // down_check:
    //## statechart_method
    inline bool down_check_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Move_Enum {
        OMNonState = 0,
        up = 1,
        stop = 2,
        open = 3,
        moving = 4,
        close = 5,
        check = 6,
        init = 7,
        first_floor_check = 8,
        down = 9,
        down_stop = 10,
        down_open = 11,
        down_moving = 12,
        down_close = 13,
        down_check = 14
    };
    
    int rootState_subState;
    
    int rootState_active;
    
    int up_subState;
    
    IOxfTimeout* up_timeout;
    
    int down_subState;
    
    IOxfTimeout* down_timeout;
//#]
};

inline bool Move_C::rootState_IN() const {
    return true;
}

inline bool Move_C::up_IN() const {
    return rootState_subState == up;
}

inline bool Move_C::stop_IN() const {
    return up_subState == stop;
}

inline bool Move_C::open_IN() const {
    return up_subState == open;
}

inline bool Move_C::moving_IN() const {
    return up_subState == moving;
}

inline bool Move_C::close_IN() const {
    return up_subState == close;
}

inline bool Move_C::check_IN() const {
    return up_subState == check;
}

inline bool Move_C::init_IN() const {
    return rootState_subState == init;
}

inline bool Move_C::first_floor_check_IN() const {
    return rootState_subState == first_floor_check;
}

inline bool Move_C::down_IN() const {
    return rootState_subState == down;
}

inline bool Move_C::down_stop_IN() const {
    return down_subState == down_stop;
}

inline bool Move_C::down_open_IN() const {
    return down_subState == down_open;
}

inline bool Move_C::down_moving_IN() const {
    return down_subState == down_moving;
}

inline bool Move_C::down_close_IN() const {
    return down_subState == down_close;
}

inline bool Move_C::down_check_IN() const {
    return down_subState == down_check;
}

#endif
/*********************************************************************
	File Path	: CanButtonTest/MontaVista/Move.h
*********************************************************************/
