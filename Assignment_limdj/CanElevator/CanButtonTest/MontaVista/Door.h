/*********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: Door
//!	Generated Date	: Fri, 10, May 2019  
	File Path	: CanButtonTest/MontaVista/Door.h
*********************************************************************/

#ifndef Door_H
#define Door_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include <aom/aom.h>
//## auto_generated
#include "CanButton.h"
//## link itsMove
class Move_C;

//## package CanButton

//## class TopLevel::Door
class Door_C {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedDoor_C;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Door_C();
    
    //## auto_generated
    ~Door_C();
    
    ////    Operations    ////
    
    //## operation close()
    void close();
    
    //## operation open()
    void open();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Move_C* getItsMove() const;
    
    //## auto_generated
    void setItsMove(Move_C* p_Move);

protected :

    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    Move_C* itsMove;		//## link itsMove
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedDoor_C : virtual public AOMInstance {
    DECLARE_META(Door_C, OMAnimatedDoor_C)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: CanButtonTest/MontaVista/Door.h
*********************************************************************/
