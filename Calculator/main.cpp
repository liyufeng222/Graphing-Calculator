/*
 * Author: Yufeng Li
 * Project: Final Project Graphing Calculator
 * Purpose: Create a Graphing Calculator using sfml interface. User can enter
 *          any funtion into this, and it will draw the function, user can
 *          pan the graph up down left right, Also can zoom in zoom out the
 *          graph, every funtion has been input will appear in the sidebar
 *          user can click on the sidebar to change the graph. Press F2 at
 *          the end of the program, it save the fucntion list in sidebar to
 *          file, next time open up, the history function list still in the
 *          sidebar, also can click to switch to that graph. There is a help
 *          screen in the calculator.
 * Notes:   input same fucntion will not save twice
 */

#include <iostream>
#include "animate.h"

using namespace std;

int main()
{
    animate calculator;     //object for calculator
    calculator.run();
    cout<<endl<<endl<<"------ MAIN EXITING --------------------------"<<endl;
    return 0;
}
