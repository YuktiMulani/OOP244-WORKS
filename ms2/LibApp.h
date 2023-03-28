/******************************************************
				Milestone-2
	NAME          : Yukti Manoj Mulani
	EMAIL         : ymulani@myseneca
	STUDENT ID    : 156809212
	DATE COMPLETED: 22-Jul-2022
	I have done all the coding by myself
	and only copied the code that my professor provided
	to complete my workshops and assignments.
********************************************************
*/

#include "Menu.h"

namespace sdds
{
	class LibApp
	{
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;

		bool confirm(const char* message);
		void load();
		void save();
		void search();

		void returnPub();

	public:
		void newPublication();
		void removePublication();
		void checkOutPub();

		LibApp();
		void run();
	};
}