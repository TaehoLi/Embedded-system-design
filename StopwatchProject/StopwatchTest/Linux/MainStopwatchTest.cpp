/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: StopwatchTest 
	Configuration 	: Linux
	Model Element	: Linux
//!	Generated Date	: Fri, 26, Apr 2019  
	File Path	: StopwatchTest/Linux/MainStopwatchTest.cpp
*********************************************************************/

//## auto_generated
#include "MainStopwatchTest.h"
//## auto_generated
#include "StopwatchPkg.h"
StopwatchTest::StopwatchTest() {
    StopwatchPkg_initRelations();
    StopwatchPkg_startBehavior();
}

int main(int argc, char* argv[]) {
    int status = 0;
    if(OXF::initialize())
        {
            StopwatchTest initializer_StopwatchTest;
            //#[ configuration StopwatchTest::Linux 
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
	File Path	: StopwatchTest/Linux/MainStopwatchTest.cpp
*********************************************************************/
