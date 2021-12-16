/*---------------------------------------------------
  Luisel A. Muller Rodriguez
  #S01394043
  11/28/2021

  This program is an Emergency Room Patients
  Healthcare System that keeps the patients records,
  visits, turns, diagnostics, treatments, etc.
---------------------------------------------------*/
#include <iostream>
#include "System.h"

using namespace std;
int main()
{
    //The Patient manegement system is all in the System class since this could be one of many systems in the hospital.

    /* Creating a system object. */
    System system;
   
    /* Displays the Main Menu of the System, everything else is managed by the system class.*/
    return system.mMenu();
}