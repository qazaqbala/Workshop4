/*
Student Name: Temirlan Tolen
Student Email: ttolen@myseneca.ca
Student ID: 104571187
Date: 14.02.21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::ConfirmationSender() : m_arr(nullptr), m_size(0u), m_capacity(10u) {
        m_arr = new const Reservation * [m_capacity];
    }

	ConfirmationSender::~ConfirmationSender() {
		delete[] m_arr;
		m_arr = nullptr;
	}
	
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool check = false;
		for (int i = 0; i < m_size; i++) {
			if (m_arr[i] == &res) check = true;
		}
		if (!check) {
            //m_arr = new const Reservation* [m_capacity];
            m_arr[m_size] = &res;
            m_size++;
            if (m_size == m_capacity) {
                m_capacity *= 2;
                const Reservation** ptr = new const Reservation * [m_capacity];
                for (int i = 0; i < m_size; i++) {
                    ptr[i] = m_arr[i];
                }
                delete[] m_arr;
                m_arr = ptr;
            }
            
		}
        return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        bool check = false; 
        int index = -1;
        if (m_arr != nullptr) {
            for (int i = 0; i < m_size; i++) {
                if (m_arr[i] == &res) {
                    check = true;
                    index = i;
                }
            }
            if (check == true) {
                m_arr[index] = nullptr;
            }
        }
        return *this;
	}

    std::ostream& operator<<(std::ostream& ostr, ConfirmationSender& right) {
        if (right.m_size == 0) {
            ostr << "--------------------------\n";
            ostr << "Confirmations to Send\n";
            ostr << "--------------------------\n";
            ostr << "There are no confirmations to send!\n";
            ostr << "--------------------------\n";
        }
        else {
            ostr << "--------------------------\n";
            ostr << "Confirmations to Send\n";
            ostr << "--------------------------\n";
            for (int i = 0; i < right.m_size; i++) {
                if (right.m_arr[i] != nullptr) {
                    ostr << *right.m_arr[i] << "\n";
                }
            }
            ostr << "--------------------------\n";
        }
        return ostr;
    }
    /*
    ConfirmationSender::ConfirmationSender(ConfirmationSender& cs) {
        if (cs.m_arr != nullptr) {
            m_arr = new Reservation * [cs.m_size];
            for (int i = 0; i < cs.m_size; ++i) {
                m_arr[i] = cs.m_arr[i];
            }
            m_size = cs.m_size;
        }
    }
    */
    ////// Modified
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& right) : m_arr{ nullptr } {
        m_size = 0u;
        *this = right;
    }
    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& right) {
        if (this != &right) {
            delete[] this->m_arr;
            this->m_size = right.m_size;
            if (right.m_arr != nullptr && right.m_size > 0) {
                m_arr = new const Reservation *[m_size];
                for (int i = 0; i < m_size; i++) {
                    m_arr[i] = right.m_arr[i];
                }
            }
            else m_arr = nullptr;
        }
        return *this;
    }
    //////

    /*
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& right) {
        if (right.m_arr != nullptr) {
            m_arr = right.m_arr;
            right.m_arr = nullptr;
            m_size = right.m_size;
            right.m_size = 0;
        }
    }
    */

    /////Modified
    ConfirmationSender& ConfirmationSender::operator= (ConfirmationSender&& right) {
        if (this != &right) {
            delete[] m_arr;
            m_arr = right.m_arr;
            right.m_arr = nullptr;
            m_size = right.m_size;
            right.m_size = 0;
        }
        return *this;
    }
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& right) : m_arr{ nullptr } {
        m_size = 0;
        *this = std::move(right);
    }
    /////
}
