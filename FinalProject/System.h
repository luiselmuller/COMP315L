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
#include "Patient.h"
#include "Doctor.h"

class System
{
	public:
		void addPatient();
		void displayPatients();
		Patient findPatient(int pid);
		void patientLogin(int pid, Patient p);
		void setPatientTurn(int t, Patient p);
		std::string getTime();
		void doctorLogin(int did, Doctor d);
		Doctor findDoctor(int did);
		void addDoctor();
		void displayDoctors();

		std::string its(int i);
		

	private:


};
#endif