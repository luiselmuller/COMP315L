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

/********************************************************************************
 * DOCTOR CLASS DETAILS :
 *
 * || CONSTRUCTORS ||
 * +Doctor() -> Empty constructor that prompts the user to enter their name, it
 *  also initializes the name and lastname variables.
 * 
 * || GETTER FUNCTIONS ||
 * +getName()      -> Returns the name of the doctor as a string.
 * +getLastNames() -> Returns the last name of the doctor as a string.
 * +getFullName()  -> Returns the full name of the doctor by concatenating the 
 *  name and last name.
 * +getID()        -> Returns the ID of the doctor as an integer value.
 * +getObservations() -> Returns the observations made by the doctor.
 * +getTreatment() -> Returns the treatment the doctor applied.
 * 
 * || SETTER FUNCTIONS ||
 * +setName(std::string) -> Takes in a string as an argument and sets it as the 
 *  doctors name.
 * +setLastNames(std::string) -> Takes in a string as an argument and sets it
 *  as the doctors last name.
 * +setID(int) -> Takes in an int as an argument and sets it as the doctors ID.
 * 
 * || VARIABLES ||
 * Strings:
 *      -name         -> Stores the doctors name.
 *      -lastNames    -> Stores the doctors last name.
 *		-observations -> Stores the observations made on a patient.
 *      -treatment    -> Stores the treatment given to a patient.
 * 
 * Integers:
 *      -ID -> Stores the doctors ID.
 * 
 *******************************************************************************/

class Doctor 
{
	public:
		/* Constructor */
		Doctor();
		
		/* Getters */
		std::string getName();
		std::string getLastNames();
		std::string getFullName();
		std::string getTreatment();
		std::string getObservations();
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