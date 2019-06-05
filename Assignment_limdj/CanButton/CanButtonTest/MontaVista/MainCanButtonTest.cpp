/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: MontaVista
//!	Generated Date	: Fri, 10, May 2019  
	File Path	: CanButtonTest/MontaVista/MainCanButtonTest.cpp
*********************************************************************/

//## auto_generated
#include "MainCanButtonTest.h"
//## auto_generated
#include "CanButton.h"
CanButtonTest::CanButtonTest() {
    CanButton_initRelations();
    CanButton_startBehavior();
}

int main(int argc, char* argv[]) {
    int status = 0;
    if(OXF::initialize())
        {
            CanButtonTest initializer_CanButtonTest;
            //#[ configuration CanButtonTest::MontaVista 
            //#]
            OXF::start();
            status = 0;
        }
    else
        {
            status = 1;
        }
    return status;
}

/*********************************************************************
	File Path	: CanButtonTest/MontaVista/MainCanButtonTest.cpp
*********************************************************************/
