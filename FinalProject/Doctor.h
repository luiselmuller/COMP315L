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
		void updatePatientInfo(Patient p);
		
		/* Getters */
		std::string getName();
		std::string getLastNames();
		std::string getFullName();
		int getID();

		/* Setters */
		void setName(std::string n);
		void setLastNames(std::string ln);
		void setID(int id);
	private:
		std::string name, lastNames, observations, treatment;
		int ID = 0;


};


#endif