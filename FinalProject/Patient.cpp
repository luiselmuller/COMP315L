/*------------------------------------------------------
  Luisel A. Muller Rodriguez
  #S01394043
  11/28/2021

  This files contains all of the function definitions
  for the Patient class.
------------------------------------------------------*/

#include <iostream>
#include <string>
#include "Patient.h"

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

	std::cout << "Enter the patients symptoms: ";
	getline(std::cin, symptoms);

}

std::string Patient::getName(){ return name; }

std::string Patient::getLastNames(){ return lastNames; }

std::string Patient::getFullName(){ return name + lastNames; }

std::string Patient::getBirthday(){ return birthday; }

std::string Patient::getAge(){ return age; }



int Patient::getTurns(){ return turns; }

int Patient::getVisits(){ return visits; }

int Patient::getID(){ return ID; }

void Patient::setName(std::string n){ name = n; }

void Patient::setLastNames(std::string ln){ lastNames = ln; }

void Patient::setAge(std::string a){ age = a; }

void Patient::setBirthday(std::string bd){ birthday = bd; }

void Patient::setVisits(int v){ visits += v; } //FIX

void Patient::setTurns(int t){ turns = t; }

void Patient::setID(int id){ ID = id; }

void Patient::setSymp(std::string s) { symptoms = s; }

std::string Patient::getSymp() { return symptoms; }
