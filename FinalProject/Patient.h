#ifndef Patient_H
#define Patient_H

/*====================================================
  Luisel A. Muller Rodriguez
  #S01394041
  11/28/2021

  This file contains the Patient class, a class that
  has all the information related to a patient such
  as their name, age, birthday and other personal
  information.
====================================================*/  

/********************************************************************************
 * PATIENT CLASS DETAILS : 
 * 
 * || CONSTRUCTORS ||
 * +Patient() -> Empty/default constructor.
 * +Patient() -> Constructor used to create a patient object with all of 
 * the patients personalinformation.
 * 
 * || GETTER FUNCTIONS ||
 * +getName()      -> Returns a string that contains the name of the patient.
 * +getLastNames() -> Returns a string containing the last names of a patient.
 * +getFullName()  -> Concatenates the patients name and last names into a 
 *                   single string and returns it.
 * +getBirthday()  -> Returns a string containing the patients birthday.
 * +getAge() -> Returns the patients age as an integer value.
 * +getTurns()     -> Returns the patients turns as an integer.
 * +getVisits()    -> Returns the patients visits as an integer.
 * 
 * || SETTER FUNCTIONS ||
 * ## None of these functions return any values ##
 * +setName()      -> Sets the name of the patient. 
 * +setLastNames() -> Sets the last names of the patient, these should be 
 *                   separated by a space so it's more legible.
 * +setBirthday()  -> Sets the birthday of the patient.                  
 * +setAge()       -> Sets the age of the patient. 
 * +setVisits()    -> Sets the visits the patient has had.
 * +setTurns()     -> Sets the patients turn.
 * 
 * || VARIABLES ||
 * Strings:
 *      -name      -> Stores the name of the patient.
 *      -lastNames -> Holds the last names of the patient.
 *      -birthday  -> Stores the patients birthday sperated by "/" in a 
 *                   "mm/dd/yyyy" format.
 *      -age       -> Stores the age of the patient, cannot be <= 0. The 
 *                    variable holds a string in the case the age is < 1, in
 *                    that case it should be specified that the age is months.
 * Integers:
 *      -visits    -> Stores the visits a patient has had.
 *      -turns     -> Stores the patients turns.
 * 
 *******************************************************************************/

class Patient
{
    public:
        /* Constructors */
        Patient();

        /* Getters */
        std::string getName();
        std::string getLastNames();
        std::string getFullName();
        std::string getBirthday();
        std::string getAge();
        
        int getTurns();
        int getVisits();
        int getID();

        /* Setters */
        void setName(std::string n);
        void setLastNames(std::string ln);
        void setAge(std::string a);
        void setBirthday(std::string bd);
        void setVisits(int v);
        void setTurns(int t);
        void setID(int id);
        
        


    private:
        std::string name, lastNames, birthday, age;
        int visits = 0, turns = 0, ID = 0;
};

#endif