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
#include <list>
#include <queue>

std::list<Patient> plist;
std::queue<Patient> pqueue;

int idCount = 000;

Doctor::Doctor()
{
	//default values
}

Doctor::Doctor(std::string n)
{
	name = n;
}

void Doctor::addPatient()
{
	Patient patient;			//create patient	
	patient.setID(idCount);		//setting ID
	plist.push_back(patient);	//add them to the list
	std::cout << "Successfully added the patient. ID - " << idCount;
	idCount++;		//updating global id variable

	
}

void Doctor::patientInSystem(int pid)
{
	for (Patient n : plist)
	{
		if (pid == n.getID())
		{
			std::cout << "\nPatient Found   ";
			system("pause");
			//patient dashboard
			std::cout << "\n\n========================================================\n"
						 "\t\t" << n.getFullName() << "'s Dashboard"
						 "\n========================================================\n"
						 "ID   - " << n.getID()       << "\n"
				         "Name - " << n.getFullName() << "\n"
						 "Age  - " << n.getAge()      << "\n"
				         "# visits - " << n.getVisits() << "\n"
						 "Turn - "	<< "\n"
				         "Birthday - " << n.getBirthday() ;
		}
	}
}

void Doctor::displayPatients()
{
	for (Patient n : plist)
	{
		std::cout  << "ID | " << n.getID() << " | Full Name | " << n.getFullName() << std::endl;
	}
}


//void Doctor::setSymp(std::string s) { symptoms = s; }

//std::string Doctor::getSymp() { return symptoms; }