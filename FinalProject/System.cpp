#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include "System.h"

std::list<Patient> plist;
std::list<Doctor> dlist;
std::queue<Patient> pqueue;

int pidCount = 000;

void System::displayDoctors()
{
	for (Doctor n : dlist)
	{
		std::cout << "ID | " << n.getID() << " | Full Name | " << n.getFullName() << std::endl;
	}
}


void System::displayPatients()
{
	for (Patient n : plist)
	{
		std::cout << "ID | " << n.getID() << " | Full Name | " << n.getFullName() << std::endl;
	}
}


void System::addPatient()
{
	Patient patient;			//create patient	
	patient.setID(pidCount);		//setting ID
	plist.push_back(patient);	//add them to the list
	std::cout << "Successfully added the patient. Patient ID = " << pidCount;
	pidCount++;		//updating global id variable

}

Patient System::findPatient(int pid)
{
	for (Patient n : plist)
		if (pid == n.getID())
		{
			return n;
		}
		else
		{
			std::cout << "Patient not found in system, register the patient.\n";
			addPatient();
		}
}

Doctor System::findDoctor(int did)
{
	for (Doctor n : dlist)
		if (did == n.getID())
		{
			return n;
		}
}


void System::patientLogin(int pid, Patient p)
{


	int loginChoice = -1;
	std::string symp = " ";
	std::string temp = " ";

	p.updtVisits();

	std::cout << "\n";
	system("pause");
	//patient dashboard
	std::cout << "\n\n========================================================\n"
		"\t\t" << p.getFullName() << "'s Dashboard"
		"\n========================================================\n\n"
		"ID        - " << p.getID() << "\n"
		"Name      - " << p.getName() << "\n"
		"Last Name - " << p.getLastNames() << "\n"
		"Age       - " << p.getAge() << "\n"
		"Turn      - " << p.getTurns() << "\n"
		"Birthday  - " << p.getBirthday() << "\n"
		"Gender    - " << p.getGend() << "\n"
		"Number of visits  - " << p.getVisits() << "\n"
		"\n========================================================\n"
		"\tPick an option from the menu below\n"
		"--------------------------------------------------------\n"
		"1. Visit purpose\n"
		"2. Find a Physician\n"
		"3. See Invoices\n"
		"4. See Visit History\n"
		"5. See Physicians in sytem\n"
		"0. Exit\n>";

	std::cin >> loginChoice;
	std::cin.ignore();

	switch (loginChoice)
	{
	case 1:
		std::cout << "Enter the patients symptoms: ";
		getline(std::cin, symp);
		p.setSymp(symp);
		pqueue.push(p);
		//need to display patients turn

		//setting the visit time and date
		//p.setVisHis(getTime());

		patientLogin(pid, p);
		break;

	case 2:
		std::cout << "Enter the Physicians name or ID: ";
		getline(std::cin, temp);
		for (Doctor n : dlist)
		{
			if (temp == n.getName() || temp == its(n.getID()))
			{
				std::cout << "Doctor " << n.getName() << " - ID-" << n.getID() << " is in the system.\n\n";
				std::cout << "Would you like to see this doctors invoices? (y/n): ";
			}
			else
			{
				std::cout << "Doctor not in system.\n";
			}
		}
			
		patientLogin(pid, p);
			break;
		case 3:
			std::cout << "No invoices for patient " << p.getFullName() << std::endl;
			break;
		case 4:
			//p.printVisHis();
			break;

		case 5:
			std::cout << "Displaying all physicians in the system\n\n";
			displayDoctors();
			patientLogin(pid, p);
		default:
			exit(0);
	}

}

void System::setPatientTurn(int t, Patient p) { p.setTurns(t + 1); }

std::string System::getTime()
{
	return "time";
}


void System::doctorLogin(int did, Doctor d)
{

	int loginChoice = -1, docChoice = -1;
	std::string temp = " ";


	std::cout << "\n";
	system("pause");
	//patient dashboard
	std::cout << "\n\n========================================================\n"
		"\t\t" << d.getFullName() << "'s Dashboard"
		"\n========================================================\n\n"
		"ID        - " << d.getID() << "\n"
		"Name      - " << d.getName() << "\n"
		"Last Name - " << d.getLastNames() << "\n"
		"Number of patients in queue  - " << //d.getVisits() << "\n"
		"\n========================================================\n"
		"\tPick an option from the menu below\n"
		"--------------------------------------------------------\n"
		"1. Find Patient\n"
		"2. Display all Patients\n"
		"3. Register a patient\n"
		"0. Exit\n>";

	std::cin >> loginChoice;
	std::cin.ignore();

	switch (loginChoice)
	{
		case 1:
			std::cout << "Enter the patients name or ID: ";
			getline(std::cin, temp);
			for (Patient n : plist)
			{
				if (temp == n.getName() || temp == its(n.getID()))
				{
					std::cout << "Patient " << n.getName() << " - ID-" << n.getID() << " is in the system.\n\n";
					std::cout << "Would you like to attend this patient? (y/n): ";
					getline(std::cin, temp);
					if (temp == "y" || temp == "yes")
					{
						std::cout << "\n\n========================================================\n"
							"\t\t" << n.getFullName() << "'s Information"
							"\n========================================================\n\n"
							"ID        - " << n.getID() << "\n"
							"Name      - " << n.getName() << "\n"
							"Last Name - " << n.getLastNames() << "\n"
							"Age       - " << n.getAge() << "\n"
							"Turn      - " << n.getTurns() << "\n"
							"Birthday  - " << n.getBirthday() << "\n"
							"Gender    - " << n.getGend() << "\n"
							"Number of visits  - " << n.getVisits() << "\n"
							"Symptoms  - " << n.getSymp() << "\n"
							"\n========================================================\n"
							"\tPick an option from the menu below\n"
							"--------------------------------------------------------\n"
							"1. Write Invoice\n"
							"0. Back \n>";
						std::cin >> docChoice;
						if (docChoice != 1)
						{
							doctorLogin(did, d);
						}
						else
						{
							std::cout << "Invoice written";
						}
						
					}
				}
			}

			doctorLogin(did, d);
			break;

		case 2:
			std::cout << "\nPatients registered in the system: \n\n";
			displayPatients();
			doctorLogin(did, d);

			break;

		case 3:
			addPatient();
			doctorLogin(did, d);
			break;

		case 4:
		
			break;

		default:
			exit(0);
	}
}

void System::addDoctor()
{
	Doctor doctor;			//create doctor	
	doctor.setID(00);		//setting ID
	dlist.push_back(doctor);	//add them to the list
	std::cout << "Successfully added the Doctor.\nDoctor ID is " << 0;

}

//int to string
std::string System::its(int i)
{
	auto s = std::to_string(i);
	return s;
}