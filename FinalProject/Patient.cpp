/*------------------------------------------------------
  Luisel A. Muller Rodriguez
  #S01394043
  11/28/2021

  This files contains all of the function definitions
  for the Patient class.
------------------------------------------------------*/

#include <iostream>
#include <string>
#include <stack>
#include "Patient.h"

/* Constructor that initializes the name, lastNames, age, birthday, gener and symptoms variables from user input. */
Patient::Patient()
{
	std::cout << "Enter the patients name: ";
	getline(std::cin, name);
	std::cout << "\n";

	std::cout << "Enter the patients last names: ";
	getline(std::cin, lastNames);
	std::cout << "\n";

	std::cout << "Enter the patients age (if patient is less\n"
		"than one year old enter it as '# month/s old'): ";
	getline(std::cin, age);
	std::cout << "\n";

	std::cout << "Enter the patients birthday (dd/mm/yyyy): ";
	getline(std::cin, birthday);
	std::cout << "\n";

	std::cout << "Enter the patients gender: ";
	getline(std::cin, gender);
	std::cout << "\n";

	std::cout << "Enter the patients symptoms: ";
	getline(std::cin, symptoms);
	std::cout << "\n";
}

/* Returns the  name of the patient as a string. */
std::string Patient::getName(){ return name; }

/* Returns the last name of the patient as a string. */
std::string Patient::getLastNames(){ return lastNames; }

/* Concatenates the name and last name of the patient to return the full name as a string. */
std::string Patient::getFullName() { return name + " " + lastNames; }

/* Returns the patients birthday as a string. */
std::string Patient::getBirthday(){ return birthday; }

/* Returns the age of the patient as a string. */
std::string Patient::getAge(){ return age; }

/* Returns the gender of the patient as a string. */
std::string Patient::getGend() { return gender; }

/* Returns the patients symptoms as a string. */
std::string Patient::getSymp() { return symptoms; }

/* Returns and integer value that corresponds to the amount of visits the patient has. */
int Patient::getVisits(){ return visits; }

/* Returns the patients ID as an integer. */
int Patient::getID(){ return ID; }

/* Sets the patients name. */
void Patient::setName(std::string n){ name = n; }

/* Sets the patients last name. */
void Patient::setLastNames(std::string ln){ lastNames = ln; }

/* Sets the patients age. */
void Patient::setAge(std::string a){ age = a; }

/* Sets the patients birthday. */
void Patient::setBirthday(std::string bd){ birthday = bd; }

/* Sets the patients visits (adds one to visits variable). */
void Patient::updtVisits(){ visits += 1; } 

/* Sets the patients ID. */
void Patient::setID(int id){ ID = id; }

/* Sets the patients gender. */
void Patient::setGend(std::string g) { gender = g; }

/* Sets the patients symptoms. */
void Patient::setSymp(std::string s) { symptoms = s; }

/* Pushes the string taken as an argument to the stack. */
void Patient::setVisHis(std::string s) { vhis.push(s); }

/* Sets the cost of the treatment. */

/* Prints out the visit history stack by making a copy and popping its contents with cout. */
void Patient::printVisHis()
{
	for (std::stack<std::string> dump = vhis; !dump.empty(); dump.pop())
	{
		std::cout << dump.top() << "\n";
	}
}

/* Prints out the invoices that the patient has. */
void Patient::printInvoices()
{
	for (std::string i : ilist)
	{
		std::cout << i << "\n";
	}
}

/* Stores the patients invoice in the invoice list (ilist). */
void Patient::sInvoice(std::string cost) { ilist.push_back(cost); }



