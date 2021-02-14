/*
Student Name: Temirlan Tolen
Student Email: ttolen@myseneca.ca
Student ID: 104571187
Date: 14.02.21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender
	{
	private:
		const sdds::Reservation** m_arr;
		size_t m_size;
		size_t m_capacity;

	public:
		ConfirmationSender();

		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender& operator+=(const Reservation& res);
		~ConfirmationSender();

		ConfirmationSender(const ConfirmationSender& right);
		ConfirmationSender& operator=(const ConfirmationSender& right);

		ConfirmationSender(ConfirmationSender&& right);
		ConfirmationSender& operator= (ConfirmationSender&& right);

		friend std::ostream& operator<<(std::ostream& ostr, ConfirmationSender& right);
	};
}
#endif // !SDDS_CONFIRMATIONSENDER_H


