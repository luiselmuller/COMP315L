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

/* Returns the ID of the doctor as an integer. */
int Doctor::getID() { return ID;  }

/* Sets the doctors name. */
void Doctor::setName(std::string n) { name = n; }

/* Sets the doctors last name. */
void Doctor::setLastNames(std::string ln) { lastNames = ln; }

/* Sets the doctors ID */
void Doctor::setID(int id) { ID = id; }



//NEEDS FIX
void Doctor::updatePatientInfo(Patient p)
{
	int infoToChange = -1;
	std::string infVal = " ";

	std::cout << "\n\n========================================================\n"
		"\t\t" << p.getFullName() << "'s Information"
		"\n========================================================\n"
		"1. Name - " << p.getName() << "\n"
		"2. Last Name - " << p.getLastNames() << "\n"
		"3. Age  - " << p.getAge() << "\n"
		"4. Number of visits - " << p.getVisits() << "\n"
		"5. Birthday - " << p.getBirthday() <<
		"0. Back "
		"\n========================================================\n"
		"\tPick an option from the menu above\n"
		"\n--------------------------------------------------------\n"
		">";
	std::cin >> infoToChange;
	std::cin.ignore();

	switch (infoToChange)
	{
		case 1:
			std::cout << "Enter the new Name: ";
			getline(std::cin, infVal);
			p.setName(infVal);
			break;
	}
}




