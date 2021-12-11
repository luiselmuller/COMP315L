#ifndef Doctor_H
#define Doctor_H

/*====================================================
  Luisel A. Muller Rodriguez
  #S01394041
  11/28/2021

  This file contains the Doctor class, a class that
  contains all of the functions that allow a doctor
  to enter the system and manage patient information.
====================================================*/
#include "Patient.h"

class Doctor
{
	public:
		Doctor();
		Doctor(std::string n);
		void addPatient();
		//void addPhcsRecord();
		void patientInSystem(int pid);
		//void findPatient();	//MIGHT CHANGE FROM VOID TO SOMETHING ELSE
		//void findPhysician();
		void displayPatients();
		//void printInvoice(int id);
		//void changeTurn(int id);
		//void setSymp(std::string s);
		//std::string getSymp();


	private:
		std::string name;// , symptoms;


};


#endif