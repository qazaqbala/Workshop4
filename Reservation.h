/*
Student Name: Temirlan Tolen
Student Email: ttolen@myseneca.ca
Student ID: 104571187
Date: 14.02.21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#pragma once
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <string>

namespace sdds {
	class Reservation
	{
	private:
		std::string m_resId;
		std::string m_resName;
		std::string m_email;
		size_t m_numOfPeople;
		size_t m_day; //the day is an integer between 1 and 28
		size_t m_hour; //the hour is an integer between 1 and 24
	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator<< (std::ostream& ostr, const Reservation& rsv);
	};
}

#endif // !SDDS_RESERVATION_H



