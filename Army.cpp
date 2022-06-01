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
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#include "Army.h"
#define MAX_NAME_LEN 50
using namespace std;
namespace sdds {
	void Army::setEmpty() {
		Army army;
		army.m_nationality[MAX_NAME_LEN];
		army.m_noOfunits;
		army.m_power;

	}
	void Army::createArmy(const char* country, double pow, int troops) {
		if (country != nullptr && !(strlen(country) <= 0)) {
			for (int i = 0; i < MAX_NAME_LEN; i++) {
				m_nationality[i]= country[i];
			}
		}
		if (pow > 0) {
			pow = m_power;
		}
		if (troops > 0) {
			troops=m_noOfunits;
		}
		else {
			setEmpty();
		}

	}
	void Army::updateUnits(int troops) {
		m_noOfunits += troops;
		m_power = ((25 / 100) * troops);
	}
	const char* Army::checkNationality() const {
		return m_nationality;
	}
	int Army::checkCapacity() const {
		return m_noOfunits;
	}
	double Army::checkPower() const {
		return m_power;
	}
	bool Army::isEmpty() const {
		if (m_nationality==0|| m_noOfunits==0|| m_power==0){
			return true;
		}
		else {
			return false;
		}
	}
	bool Army::isStrongerThan(const Army& army)const {
		if (m_power > army.m_power) {
			return true;
		}
		else {
			return false;
		}
	}
	void battle(Army& arm1, Army& arm2) {
		if (arm1.isStrongerThan(arm2)) {
			(arm2.updateUnits())
		}
	}
	void displayDetails(const Army* armies, int size) {

	}

}
