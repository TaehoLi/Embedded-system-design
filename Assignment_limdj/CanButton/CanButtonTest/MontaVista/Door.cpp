/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: Door
//!	Generated Date	: Fri, 10, May 2019  
	File Path	: CanButtonTest/MontaVista/Door.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Door.h"
//## link itsMove
#include "Move.h"
//#[ ignore
#define CanButton_Door_Door_SERIALIZE OM_NO_OP

#define CanButton_Door_close_SERIALIZE OM_NO_OP

#define CanButton_Door_open_SERIALIZE OM_NO_OP
//#]

//## package CanButton

//## class TopLevel::Door
Door_C::Door_C() {
    NOTIFY_CONSTRUCTOR_OBJECT(Door, Door(), 0, CanButton_Door_Door_SERIALIZE, Door_C);
    itsMove = NULL;
}

Door_C::~Door_C() {
    NOTIFY_DESTRUCTOR(~Door, true);
    cleanUpRelations();
}

void Door_C::close() {
    NOTIFY_OPERATION(close, close(), 0, CanButton_Door_close_SERIALIZE);
    //#[ operation close()
    upload_data_buf[0]=2;
    upload_data_buf[0]=2;
    send_can_frame(1,upload_data_buf);
    //#]
}

void Door_C::open() {
    NOTIFY_OPERATION(open, open(), 0, CanButton_Door_open_SERIALIZE);
    //#[ operation open()
    upload_data_buf[0]=2;
    upload_data_buf[0]=1;
    send_can_frame(1,upload_data_buf);
    //#]
}

Move_C* Door_C::getItsMove() const {
    return itsMove;
}

void Door_C::setItsMove(Move_C* p_Move) {
    itsMove = p_Move;
    if(p_Move != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsMove", p_Move, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsMove");
        }
}

void Door_C::cleanUpRelations() {
    if(itsMove != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsMove");
            itsMove = NULL;
        }
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedDoor_C::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsMove", false, true);
    if(myReal->itsMove)
        {
            aomsRelations->ADD_ITEM(myReal->itsMove);
        }
}
//#]

IMPLEMENT_META_OBJECT_P(Door, Door_C, CanButton, CanButton, false, OMAnimatedDoor_C)
#endif // _OMINSTRUMENT

extern int send_can_frame(int a, unsigned char *b);

/*********************************************************************
	File Path	: CanButtonTest/MontaVista/Door.cpp
*********************************************************************/
