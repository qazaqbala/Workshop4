/*
Student Name: Temirlan Tolen
Student Email: ttolen@myseneca.ca
Student ID: 104571187
Date: 14.02.21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include "Reservation.h"

namespace sdds {
	Reservation::Reservation() {
		m_resId = "";
		m_resName = "";
		m_email = "";
		m_numOfPeople = 0u;
		m_day = 0u;
		m_hour = 0u;
	}
	Reservation::Reservation(const std::string& res) {
		std::string str = res;
		std::string index = "";

		index = str.substr(0, str.find(":"));
		index.erase(index.find_last_not_of(' ') + 1);
		index.erase(0, index.find_first_not_of(' '));
		m_resId = index;
		str.erase(0, str.find(":") + 1);
		index.clear();

		index = str.substr(0, str.find(","));
		index.erase(index.find_last_not_of(' ') + 1);
		index.erase(0, index.find_first_not_of(' '));
		m_resName = index;
		str.erase(0, str.find(",") + 1);
		index.clear();

		index = str.substr(0, str.find(","));
		index.erase(index.find_last_not_of(' ') + 1);
		index.erase(0, index.find_first_not_of(' '));
		m_email = index;
		str.erase(0, str.find(",")+1);
		index.clear();

		index = str.substr(0, str.find(","));
		m_numOfPeople = stoi(index);
		str.erase(0, str.find(",")+1);
		index.clear();

		index = str.substr(0, str.find(","));
		m_day = stoi(index);
		str.erase(0, str.find(",") + 1);
		index.clear();

		index = str.substr(0);
		m_hour = stoi(index);
		str.erase(0);
		index.clear();
	}

	std::ostream& operator<< (std::ostream& ostr, const Reservation& rsv) {
		std::string serve[4]{ "Breakfast", "Lunch", "Dinner", "Drinks" };
		size_t t;
		if (rsv.m_hour <= 9 && rsv.m_hour >= 6) t = 0;
		else if (rsv.m_hour <= 15 && rsv.m_hour >= 11) t = 1;
		else if (rsv.m_hour <= 21 && rsv.m_hour >= 17) t = 2;
		else t = 3;

		std::string people[2] = { "person", "people" };
		size_t p = 1;
		if (rsv.m_numOfPeople == 1) p=0;

		ostr << "Reservation " << std::setw(10) << std::right << std::setfill(' ') << rsv.m_resId << ": "
			<< std::setw(20) << std::right << rsv.m_resName << " "
			<< std::setw(20)<<std::left<< '<'+ rsv.m_email + '>'
			<< " " << serve[t] << " on day " << rsv.m_day << " @ " << rsv.m_hour << ":00 for " << rsv.m_numOfPeople << " " << people[p] << ".\n";

		return ostr;
	}

}