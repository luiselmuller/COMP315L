/*------------------------------------------------------
  Luisel A. Muller Rodriguez
  #S01394043
  11/28/2021

  This file contains all of the function declarations
  for the Doctor class.
------------------------------------------------------*/

#include <iostream>
#include <string>
#include "Doctor.h"

/* Default constructor, initializes name and lastNames from the users input. */
Doctor::Doctor()
{
	std::cout << "Enter your name: ";
	getline(std::cin, name);
	std::cout << "\n";

	std::cout << "Enter your last names: ";
	getline(std::cin, lastNames);
	std::cout << "\n";
}

/* Returns the name of the doctor as a string. */
std::string Doctor::getName() { return name; }

/* Returns the last name of the doctor as a string. */
std::string Doctor::getLastNames() { return lastNames; }

/* Returns the full name of the doctor as a string. */
std::string Doctor::getFullName() { return name + " " + lastNames; }

/* Returns treatements applied by the doctor. */
std::string Doctor::getTreatment() { return treatment; }

/* Returns observations made by the doctor. */
std::string Doctor::getObservations() { return observations; }

/* Returns the ID of the doctor as an integer. */
int Doctor::getID() { return ID;  }

/* Sets the doctors name. */
void Doctor::setName(std::string n) { name = n; }

/* Sets the doctors last name. */
void Doctor::setLastNames(std::string ln) { lastNames = ln; }

/* Sets the doctors ID */
void Doctor::setID(int id) { ID = id; }
