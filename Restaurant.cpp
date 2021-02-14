/*
Student Name: Temirlan Tolen
Student Email: ttolen@myseneca.ca
Student ID: 104571187
Date: 14.02.21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Restaurant.h"

namespace sdds{
	Restaurant::Restaurant() :m_arr{ nullptr }, m_res{ 0 }{}

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) : m_res{ cnt } {
		m_arr = new sdds::Reservation[cnt];
		
		for (int i = 0; i < cnt; i++) {
			m_arr[i] = *reservations[i];
		}
	}
	/*
	Restaurant::Restaurant(const Restaurant& right) {
		m_res = right.m_res;
		if (right.m_arr != nullptr && right.m_res > 0) {
			m_arr = new Reservation[right.m_res];
			for (int i = 0; i < right.m_res; i++) {
				m_arr[i] = right.m_arr[i];
			}
		}
		else m_arr = nullptr;
	}
	*/
	////////////
	Restaurant::Restaurant(const Restaurant& right) : m_arr{ nullptr } {
		m_res = 0;
		*this = right;
	}
	Restaurant& Restaurant::operator=(const Restaurant& right) {
		if (this != &right) {
			delete[] this->m_arr;
			this->m_res = right.m_res;
			if (right.m_arr != nullptr && right.m_res > 0) {
				m_arr = new Reservation[m_res];
				for (int i = 0; i < m_res; i++) {
					m_arr[i] = right.m_arr[i];
				}
			}
			else m_arr = nullptr;
		}
		return *this;
	}
	////////////


	/*
	Restaurant::Restaurant(Restaurant&& right) {
		if (right.m_arr != nullptr) {
			m_arr = right.m_arr;
			right.m_arr = nullptr;
			m_res = right.m_res;
			right.m_res = 0;
		}
	}
	*/

	/////////
	Restaurant& Restaurant::operator= (Restaurant&& right) {
		if (this != &right) {
			delete[] m_arr;
			m_arr = right.m_arr;
			right.m_arr = nullptr;
			m_res = right.m_res;
			right.m_res = 0;
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& right) : m_arr{ nullptr } {
		m_res = 0;
		*this = std::move(right);
	}
	////////


	size_t Restaurant::size() const {
		return m_res;
	}

	Restaurant::~Restaurant() {
		delete[] m_arr;
		m_arr = nullptr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Restaurant& rest) {
		static size_t count = 1;
		if (rest.size() == 0) {
			ostr << "--------------------------\n";
			ostr << "Fancy Restaurant (" << count <<")\n";
			ostr << "--------------------------\n";
			ostr << "This restaurant is empty!\n";
			ostr << "--------------------------\n";
		}
		else {
			ostr << "--------------------------\n";
			ostr << "Fancy Restaurant (" << count << ")\n";
			ostr << "--------------------------\n";
			for (int i = 0; i < rest.size(); i++) {
				ostr << rest.m_arr[i];
			}
			ostr << "--------------------------\n";
		}
		count++;
		return ostr;
	}
}