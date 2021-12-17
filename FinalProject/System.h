#ifndef System_H
#define System_H

/*====================================================
  Luisel A. Muller Rodriguez
  #S01394041
  11/28/2021

  This file contains the System class which has all
  the functions needed to manage the system itself, 
  like adding or finding patients.
====================================================*/

/********************************************************************************
 * SYSTEM CLASS DETAILS :
 *
 * || CONSTRUCTORS ||
 * +System() -> Default constructor.
 * 
 * || SYSTEM FUNCTIONS ||
 * +findPatient(int) -> Takes in the id(integer) of a patient as an argument 
 *  and uses it to find the patient in the patient list (plist).
 * +findDoctor(int) -> Takes in the id(integer) of a doctor as an argument
 *  and uses it to find the doctor from the doctor list (dlist).
 * +setPatientTurn(int, Patient) -> Takes in an integer and a Patient class
 *  object to set a specific patients turn in the queue (pqueue).
 * +displayDoctors() -> Displays all of the doctors in the doctor list.
 * +displayPatients() -> Displays all of the patients in the patient list.
 * +addDoctor() -> Adds a doctor to the system using the default constructor.
 * +addPatient() -> Adds a patient to the system using the default constructor.
 * +createInvoice() -> Creates a patient invoice, takes in a patient object
 *  as an argument to know which patients invoice it is.
 * 
 * || MENUS ||
 * +mMenu() -> Displays the main menu of the system, this is the first menu the
 *  user sees where they are asked if they are a doctor or a patient, they can 
 *  then add themselves to the system or login with their ID.
 * +doctorLogin(Doctor) -> This is the menu which allows the doctor to
 *  manage patients within the system after they login, the function takes
 *  a doctor object as an argument so it knows which doctor is accessing the
 *  system.
 * +patientLogin(Patient) -> This is the menu which allows the Patient to
 *  manage their patient profile in the system, it takes in a Patient object
 *  so it knows which patient has logged in to the system and display their
 *  information accurately.
 * 
 * || HELPER FUNCTIONS ||
 * +getTime() -> Returns the current time and date as a string.
 * +its(int) -> The name stands for "int to string", this function converts 
 *  an integer to a string and returns it.
 * +puid() -> The name stands for "patient unique ID", it generates an id 
 *  with a range of 0 - 1000 for a patient.
 * +duid() -> The name stands for "doctor unique ID", it generates an id
 *  with a range of 2000 - 3000 for a doctor.
 * +findTurn(Patient) -> Helps find a patients turn, takes in a patient object to
 *  know which patients turn to find.
 * +inQueue(Patient) -> ********
 * 
 * || VARIABLES ||
 * No variables in the class
 * 
 *******************************************************************************/
#include "Doctor.h"
#include "Patient.h"


class System
{
	public:
		/* Constructor */
		System();

		/* System functions */
		Patient* findPatient(int pid);
		Doctor findDoctor(int did);
		void displayDoctors();
		void displayPatients();
		void addDoctor();
		void addPatient();
		void removeFromQueue(Patient p);
		void createInvoice(Patient &p, Doctor d);
		
		/* Menus */
		void mMenu();
		void doctorLogin(Doctor d);
		void patientLogin(Patient &p);

		/* Helper Functions */
		std::string getTime();
		std::string its(int i);
		int puid();
		int duid();
		int findTurn(Patient p);
		bool inQueue(Patient p);

};
#endif