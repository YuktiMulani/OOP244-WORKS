/*
*****************************************************************************
							Workshop 3 part 1
Full Name   : Yukti Manoj Mulani
Student ID# : 156809212
Senecamail  : ymulani@myseneca.ca
Date        : May 31, 2022
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_ARMY_H // replace with relevant names
#define SDDS_ARMY_H
#define MAX_NAME_LEN 50
namespace sdds {
	struct Army {
	private:
		char m_nationality[MAX_NAME_LEN];
		int m_noOfunits;
		double m_power;
	public:
		void setEmpty();
		void createArmy(const char* country, double pow, int troops);
		void updateUnits(int troops);
		const char* checkNationality() const;
		int checkCapacity() const;
		double checkPower() const;
		bool isEmpty() const;
		bool isStrongerThan(const Army& army)const;
		void set(const char*, int, double);
	};
	void battle(Army& arm1, Army& arm2);
	void displayDetails(const Army* armies, int size);
}

#endif