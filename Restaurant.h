/*
Student Name: Temirlan Tolen
Student Email: ttolen@myseneca.ca
Student ID: 104571187
Date: 14.02.21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#pragma once
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class Restaurant
	{
	private:
		Reservation* m_arr;
		size_t m_res;
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);

		Restaurant(const Restaurant& right);
		Restaurant(Restaurant&& right);

		Restaurant& operator=(const Restaurant& right);
		Restaurant& operator= (Restaurant&& right);

		size_t size() const;
		~Restaurant();
		friend std::ostream& operator<<(std::ostream& ostr, const Restaurant& rest);
	};
}

#endif // !SDDS_RESTAURANT_H



