#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream>
namespace sdds {
	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};
	class Basket {
	private:
		Fruit* m_fruits;
		int m_cnt;
		double m_price;
	public:
		Basket();
		Basket(Fruit* fruit, int cnt, double price);
		Basket(const Basket&);//copy constructor
		Basket& operator=(const Basket&);
		~Basket();
		void setPrice(double price);
		operator bool()const;
		Basket& operator+=(Fruit);
		std::ostream& display(std::ostream& ostr) const;
	};
	std::ostream& operator<<(std::ostream& ostr, Basket& B);

}

#endif // !SDDS_BASKET_H

