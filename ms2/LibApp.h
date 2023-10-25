


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