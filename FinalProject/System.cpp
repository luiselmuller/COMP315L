/*---------------------------------------------------
  Luisel A. Muller Rodriguez
  #S01394043
  11/28/2021

  This file contains all of the functions used to 
  manage the patient system. It basically contains
  the system itself and the only thing needed to
  run it in the driver program is to call the
  main menu function. 
---------------------------------------------------*/

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <chrono>
#include <ctime>
#include "BSTree.h"
#include "System.h"

std::list<Patient> plist;     //Patient List.
std::list<Doctor> dlist;      //Doctor List.
std::deque<int> pqueue;		  //Patient queue, they are put in the queue by ID.


/**************** DEFAULT CONSTRUCTOR ****************/
System::System() { /*Empty on purpose*/ }

/**************** SYSTEM FUNCTIONS ****************/
/* Displays all the doctors in dlist. */
void System::displayDoctors()
{
	//Iterates through dlist.
	for (Doctor n : dlist)
	{
		//Displays the doctors ID and Name.
		std::cout << "ID | " << n.getID() << " | Full Name | " << n.getFullName() << std::endl;
	}
}

/* Displays all the patients in plist. */
void System::displayPatients()
{
	//Iterates through plist.
	for (Patient n : plist)
	{
		//Displays the patients ID, full name and their turn in the queue. 
		std::cout << "| ID | " << n.getID() << " | Full Name | " << n.getFullName() << " | Turn | " << findTurn(n) + 1<< std::endl;
	}
}

/* Adds a doctor to dlist. */
void System::addDoctor()
{
	Doctor doctor;			   //Create doctor.	
	doctor.setID(duid());	   //Setting the doctors ID.
	dlist.push_back(doctor);   //Add the doctor object to the back of dlist.

	//Display the doctors ID after adding them to the system.
	std::cout << "Successfully added the Doctor.\nDoctor ID is " << doctor.getID();
}

/* Adds a patient to plist. */
void System::addPatient()
{
	Patient patient;			//Create patient.	
	patient.setID(puid());		//Setting the patients ID.
	plist.push_back(patient);	//Add the patient object to the back of plist.

	//Display the patients ID after adding them to the system.
	std::cout << "Successfully added the patient. Patient ID = " << patient.getID();

	//Add the patient to the queue.
	pqueue.push_back(patient.getID());
}

/* Finds a patient in plist and returns the object. */
Patient* System::findPatient(int pid)
{
	for (Patient &n : plist)
	{
		if (pid == n.getID())
		{
			auto *i = &n;
			return i;
		}

		continue;
	}
	//If the patient isn't found return to the main menu.
	mMenu();
}

/* Finds a patient in dlist and returns the object. */
Doctor System::findDoctor(int did)
{
	for (Doctor n : dlist)
	{
		if (did == n.getID())
			return n;

		continue;
	}
	//If the doctor isn't found return to the main menu.
	mMenu();
}

/* Finds a patient in the queue and removes them. */
void System::removeFromQueue(Patient p)
{
	/********************************************************************************************************************
	* Removes the patient from the queue, pqueue.begin() returns the first element in it, findTurn(p) returns the index
	* of the element to be removed, this offsets the element. Example: queue = 1, 2, 3, 4 element = 3
	* The elements position is 2, this gives us pqueue.erase(0 + 2) which erases the element in position 2.
	********************************************************************************************************************/
	pqueue.erase(pqueue.begin() + findTurn(p));
}

/**************** MENU FUNCTIONS ****************/
/* Menu displayed after a patient logs in, it displays a 'dashboard' with the patient information. */
void System::patientLogin(Patient &p)
{

	int loginChoice = 0;     //Stores the users choice for dashboard options.
	std::string symp = " ";  //Stores patient symptoms.
	std::string temp = " ";  //Can store a physicians name or ID.

	std::cout << "\n";	//New line to show the system pause under the previous text.
	system("pause");

	//Patient 'Dashboard' that shows the patient information and gives them more options.
	std::cout << "\n\n========================================================\n"
		"\t\t" << p.getFullName() << "'s Dashboard"
		"\n========================================================\n\n"
		"ID        - " << p.getID() << "\n"
		"Name      - " << p.getName() << "\n"
		"Last Name - " << p.getLastNames() << "\n"
		"Age       - " << p.getAge() << "\n"
		"Turn      - " << findTurn(p) + 1<< "\n"
		"Birthday  - " << p.getBirthday() << "\n"
		"Gender    - " << p.getGend() << "\n"
		"Number of visits  - " << p.getVisits() << "\n"
		"\n========================================================\n"
		"\tPick an option from the menu below\n"
		"--------------------------------------------------------\n"
		"1. Visit Purpose\n"
		"2. Find a Physician\n"
		"3. See Invoices\n"
		"4. See Visit History\n"
		"5. See Physicians in System\n"
		"6. Update Information\n"
		"0. Back\n>";

	std::cin >> loginChoice;  //Getting users choice.
	std::cin.ignore();        //Ignoring the characters that cin leaves behind so getline wont be affected.

	switch (loginChoice)
	{
		case 1:
			//Patient inputs their symptoms.
			std::cout << "Enter the patients symptoms: ";
			getline(std::cin, symp);
			p.setSymp(symp);

			//If the patient is not in the queue we add them.
			if (inQueue(p) == false)
				pqueue.push_back(p.getID());

			//Updating the visits count and the visit history.
			p.updtVisits();
			p.setVisHis(("Visit " + its(p.getVisits()) + " " + getTime()));
		
			//Goes back to the dashboard.
			patientLogin(p);
			break;

		case 2:
			//Patient enters a physicians name or ID to search.
			std::cout << "Enter the Physicians name or ID: ";
			getline(std::cin, temp);

			//Iterates through the list comparing either an ID or name to the objects in it.
			for (Doctor n : dlist)
			{
				//If the doctor is found the doctors information is displayed and the patient can choose more options.
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
		
		//Goes back to the patient dashboard.
		patientLogin(p);
			break;

		case 3:

			std::cout << "No invoices for patient " << p.getFullName() << std::endl;

			patientLogin(p); //Goes back to the patients dashboard.
			break;

		case 4:
			//Printing the visit history stack.
			p.printVisHis();

			patientLogin(p); //Goes back to the patients dashboard.
			break;

		case 5:
			//All the physicians in the system are displayed so the patient can see if theirs is on the list.
			std::cout << "Displaying all physicians in the system\n\n";

			//Displays the doctors.
			displayDoctors();

			//Goes back to the patients dashboard.
			patientLogin(p);
			break;

		case 6:
			{
				int infoupdt = 0;			//Users choice of information to update.
				std::string ninfo = " ";    //New information entered by the user.

				std::cout << "\n\n========================================================\n"
					"\t\t" << p.getFullName() << "'s Information"
					"\n========================================================\n\n"
					"1. Name      - " << p.getName() << "\n"
					"2. Last Name - " << p.getLastNames() << "\n"
					"3. Age       - " << p.getAge() << "\n"
					"4. Birthday  - " << p.getBirthday() << "\n"
					"5. Gender    - " << p.getGend() << "\n"
					"\n========================================================\n"
					"\tPick an option from the menu above"
					"\n--------------------------------------------------------\n>";
				std::cin >> infoupdt;
				std::cin.ignore();

				//Information is updated depending on the choice using setters from the Patient class.
				switch (infoupdt)
				{
					case 1:
						std::cout << "\nEnter a new name: ";
						getline(std::cin, ninfo);
						p.setName(ninfo);
						std::cout << "\nInformation updated.\n";
						break;
						
					case 2:
						std::cout << "\nEnter a new last name: ";
						getline(std::cin, ninfo);
						p.setLastNames(ninfo);
						std::cout << "\nInformation updated.\n";
						break;

					case 3:
						std::cout << "\nEnter a new age: ";
						getline(std::cin, ninfo);
						p.setAge(ninfo);
						std::cout << "\nInformation updated.\n";
						break;

					case 4:
						std::cout << "\nEnter a new birthday: ";
						getline(std::cin, ninfo);
						p.setBirthday(ninfo);
						std::cout << "\nInformation updated.\n";
						break;

					case 5:
						std::cout << "\nEnter a new gender: ";
						getline(std::cin, ninfo);
						p.setGend(ninfo);
						std::cout << "\nInformation updated.\n";
						break;
				}
				patientLogin(p); //Goes back to the patients dashboard.
			}
			break;

		default:
			//Goes back to the main menu.
			mMenu();
			break;
	}
}

/* Menu displayed after a doctor logs in, it displays a 'dashboard' with the doctor information. */
void System::doctorLogin(Doctor d)
{
	//loginChoice stores the doctors first choice from the ones in the dashboard, 
	//docChoice is a choice stored after the doctor starts to attend a patient.
	int loginChoice = 0, docChoice = 0;  
	std::string temp = " ";			     //Stores either the patients name or ID.


	std::cout << "\n";	//New line to seperate the system pause from the previous text.
	system("pause");

	//Doctor dashboard, displays the doctors information and the amount of patients in the queue.
	std::cout << "\n\n========================================================\n"
		"\t\t" << d.getFullName() << "'s Dashboard"
		"\n========================================================\n\n"
		"ID        - " << d.getID() << "\n"
		"Name      - " << d.getName() << "\n"
		"Last Name - " << d.getLastNames() << "\n"
		"Number of patients in queue  - " << pqueue.size() << "\n"
		"\n========================================================\n"
		"\tPick an option from the menu below\n"
		"--------------------------------------------------------\n"
		"1. Find Patient\n"
		"2. Display all Patients\n"
		"3. Register a patient\n"
		"0. Back\n>";

	std::cin >> loginChoice;  
	std::cin.ignore();        //Ignoring the characters that cin leaves behind so getline wont be affected.

	switch (loginChoice)
	{
		case 1:
			//Finding the patient in the list with their name or id.
			std::cout << "Enter the patients name or ID: ";
			getline(std::cin, temp);

			//Iterating through the patient list.
			for (Patient n : plist)
			{
				//If their name or ID match then their information is displayed.
				if (temp == n.getName() || temp == its(n.getID()))
				{
					std::cout << "Patient " << n.getName() << " - ID-" << n.getID() << " is in the system.\n\n";
					std::cout << "Would you like to attend this patient? (y/n): ";
					getline(std::cin, temp);

					//If the doctor chooses to attent this patient more detailed information is displayed.
					if (temp == "y" || temp == "yes")
					{
						std::cout << "\n\n========================================================\n"
							"\t\t" << n.getFullName() << "'s Information"
							"\n========================================================\n\n"
							"ID        - " << n.getID() << "\n"
							"Name      - " << n.getName() << "\n"
							"Last Name - " << n.getLastNames() << "\n"
							"Age       - " << n.getAge() << "\n"
							"Turn      - " << findTurn(n) + 1<< "\n"
							"Birthday  - " << n.getBirthday() << "\n"
							"Gender    - " << n.getGend() << "\n"
							"Number of visits  - " << n.getVisits() << "\n"
							"Symptoms  - " << n.getSymp() << "\n"
							"\n========================================================\n"
							"\tPick an option from the menu below\n"
							"--------------------------------------------------------\n"
							"1. Write Invoice\n"
							"2. View visit history\n"
							"0. Back \n>";
						std::cin >> docChoice;  //Choice to either write an invoice or go back.

						//The patient is only removed from the queue if their invoice gets written.
						if (docChoice == 1)
						{
							//Doctor can write an invoice.
							std::cout << "Invoice written";
							removeFromQueue(n);
						}
						else if(docChoice == 2)
						{
							//Doctor can see the patients visit history.
							//Printing the visit history stack.
							n.printVisHis();
						}

						//Going back to doctors login screen.
						doctorLogin(d);
					}
				}
			}

			//Goes back to the doctors dashboard
			doctorLogin(d);
			break;

		case 2:
			//Displays all the patients in system.
			std::cout << "\nPatients registered in the system: \n\n";
			displayPatients();
			doctorLogin(d);
			break;

		case 3:
			//Adds a patient from the doctors dashboard.
			addPatient();
			doctorLogin(d);
			break;

		default:
			mMenu();
			break;
	}
}

/* Main menu of the system, allows doctors and patients to login. */
int System::mMenu()
{
	int choice = 0; //Choice stores the first choice the user makes, if they'are a doctor or patient.
	do
	{
		getTime();
		//Menu to allow the user to make a choice.
		cout << "\n========================================================\n"
			"  Emergency Room Patients Healthcare Management System  \n"
			"--------------------------------------------------------\n"
			"  Are you a Doctor or a Patient?                        \n"
			"  1. Doctor                                             \n"
			"  2. Patient                                          \n\n"
			"  0. Exit                                               \n"
			"========================================================\n"
			"  >";
		cin >> choice; //Reading the users input for the choice.

		//If the choice is not one that is on the menu the user is asked to enter it again
		if (choice < 0 || choice > 2)
		{
			cout << "Enter a valid option.\n>";
			cin >> choice;
			cin.ignore();
		}

		switch (choice)
		{
			/****************************************************************************************************
			* If the user is a doctor they can add themselves to the system and then sign in to their dashboard.
			****************************************************************************************************/
			case 1:
			{
				string dans;
				int didLogin = 0;

				cout << "Have you been registered in the system before? (yes/no)\n>";
				cin.ignore();
				getline(cin, dans);

				if (dans == "no" || dans == "n" || dans == "NO")
				{
					addDoctor();
				}
				else
				{
					cout << "\nEnter your ID: ";
					cin >> didLogin;
					doctorLogin(findDoctor(didLogin));
				}
			}
			break;

			/****************************************************************************************************
			* If the user is a patient they can add themselves to the system and then sign in to their dashboard.
			****************************************************************************************************/
			case 2:

				//NEED TO ADD DASHBOARD OPTIONS TO CHANGE INFO AND MAKE IT LOOK BETTER
			{
				string ans;			//Stores the patients answer.
				int pidLogin = 0;   //Stores the patients id.

				cout << "Have you been registered in the system before? (yes/no)\n>";
				cin.ignore();
				getline(cin, ans);
				if (ans == "no" || ans == "n" || ans == "NO")
				{
					addPatient();
				}
				else
				{
					cout << "\nEnter your ID: ";
					cin >> pidLogin;
					patientLogin(*findPatient(pidLogin));
				}
			}
			break;

		}
	//If the choice is 0 the program exits the loop and then the user is given the choice to restart or exit.
	} while (choice != 0);

	//Allows the user to restart the program or exit it.
	char ec = ' ';
	cout << "Are you sure you want to exit the program? (y/n): ";
	cin >> ec;
	return ec == 'n' ? mMenu() : 0;
}


/**************** HELPER FUNCTIONS ****************/

/* Returns the current time. */
std::string System::getTime()
{
	//Getting the current time and date.
	time_t now = time(0);
	//The time is stored in this array.
	char str[26] = {};
	//First argument is the buffer, second argument the size and the third one is the time itself.
	ctime_s(str, 26, &now);

	//Converting the time into a string.
	string time = " ";
	for (char i : str)
		time += i;
	
	return time;
}

/* Converts an integer value to string and returns it. */
std::string System::its(int i)
{
	auto s = std::to_string(i);
	return s;
}

/* Generates a random id for patients. */
int System::puid()
{
	int generatedID = rand() & 1001;
	for (Patient n : plist)
	{
		while (n.getID() == generatedID)
			generatedID = rand() % 1001;
	}
	return generatedID;
}

/* Generates a random id for doctors. */
int System::duid()
{
	int generatedID = (rand() & 1001) + 2000;
	for (Doctor n : dlist)
	{
		while (n.getID() == generatedID)
			generatedID = rand() % 1001;
	}
	return generatedID;
}

/* Finds a patients turn in the queue. */
int System::findTurn(Patient p)
{
	//Iterates through the queue and when it finds the ID it returns the position. Else it returns -1.
	while (!pqueue.empty())
	{
		auto pos = std::find(pqueue.begin(), pqueue.end(), p.getID());
		if (pos != pqueue.end())
		{
			int distance = pos - pqueue.begin();
			return distance;
		}
		else
		{
			return -1;
		}
	}
	
}

/* Helps find if a patient is in the queue or not. */
bool System::inQueue(Patient p)
{
	bool flag = false;

	//If the queue is not empty we iterate through it till we find the patient id. When it's found flag is set to true and the loop is exited.
	while (!pqueue.empty())
	{
		auto pos = std::find(pqueue.begin(), pqueue.end(), p.getID());
		if (pos != pqueue.end())
		{
			flag = true;
			break;
		}
		else
		{
			return 0;
		}
	}

	return flag;
}