/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: Display
//!	Generated Date	: Fri, 26, Apr 2019  
	File Path	: StopwatchTest/MontaVista/Display.cpp
*********************************************************************/

//## auto_generated
#include "Display.h"
//## package StopwatchPkg

//## class TopLevel::Display


//#[ ignore
using namespace std;
extern int initSevenSegment(void);
extern void displaySevenSegment(int min, int sec);
//#]


Display_C::Display_C() {
    //#[ operation Display()
    cout << "Constructed" << endl;
    initSevenSegment();
    //#]
}

Display_C::~Display_C() {
}

void Display_C::print(int min, int sec) {
    //#[ operation print(int,int)
    printf("%d:%d\n",min,sec);
    displaySevenSegment(min,sec);
    //#]
}

/*********************************************************************
	File Path	: StopwatchTest/MontaVista/Display.cpp
*********************************************************************/
