/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

// #include "Version_test.h"

#include <string>
#include <iostream>
using namespace std;

class Sales_data
{
	friend Sales_data add(const Sales_data &, const Sales_data &);
	friend std::ostream &print(std::ostream &, const Sales_data &);
	friend std::istream &read(std::istream &, Sales_data &);
	friend bool operator<(const Sales_data &, const Sales_data &);
	friend bool operator==(const Sales_data &, const Sales_data &);
	friend bool operator!=(const Sales_data &, const Sales_data &);
	friend std::istream &operator>>(std::istream &, Sales_data &);
	friend std::ostream &operator<<(std::ostream &, const Sales_data &);
	friend Sales_data operator+(const Sales_data &, const Sales_data &);
	friend Sales_data &operator+=(Sales_data &, const Sales_data &);

public:
	// constructors
// using the synthesized version is safe only
// if we can also use in-class initializers
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
	Sales_data() = default;
#else
	Sales_data() : units_sold(0), revenue(0.0)
	{
	}
#endif
#ifdef IN_CLASS_INITS
	Sales_data(const std::string &s) : bookNo(s)
	{
	}
#else
	// Sales_data(const std::string &s) : bookNo(s), units_sold(0), revenue(0.0)
	// {
	// }
#endif
	Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n)
	{
	}
	Sales_data(std::istream &is) { is >> *this; }

	Sales_data(const std::string &s) : bookNo(s), units_sold(0), sellingprice(0.0),
									   saleprice(0.0), discount(0.0) {}

	// operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &);
	inline double avg_price() const;
	Sales_data &operator=(const string &);
	// Sales_data &operator+=(const Sales_data &);

private:
	// 书籍编号，隐式初始化为空串
	std::string bookNo;
#ifdef IN_CLASS_INITS // using the synthesized version is safe only
	unsigned units_sold = 0;
	double revenue = 0.0;
#else
	// 销售量，显式初始化为 0
	unsigned units_sold;
	// 总收入
	double revenue;
	// 原始价格，显式初始化为 0.0
	double sellingprice;
	// 实售价格，显式初始化为 0.0
	double saleprice;
	// 折扣，显式初始化为 0.0
	double discount;
#endif
};

Sales_data &operator+=(Sales_data &lhs, const Sales_data &rhs)
{
	lhs.units_sold += rhs.units_sold;
	lhs.saleprice = (lhs.units_sold * lhs.saleprice + rhs.units_sold * rhs.saleprice) / (lhs.units_sold + rhs.units_sold);
	if (lhs.sellingprice != 0)
	{
		lhs.discount = lhs.saleprice / lhs.sellingprice;
	}
	return lhs;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data ret(lhs);
	ret += rhs;
	return ret;
}

Sales_data &Sales_data::operator=(const string &isbn)
{
	this->bookNo = isbn;
	return *this;
}

// Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
// {
// 	Sales_data sum = lhs;

// 	sum.units_sold += rhs.units_sold;
// 	sum.revenue += rhs.revenue;
// 	return sum;
// }

// Sales_data &Sales_data::operator+=(const Sales_data &rhs)
// {
// 	*this = *this + rhs;
// 	return *this;
// }

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.units_sold == rhs.units_sold && lhs.sellingprice == rhs.sellingprice && lhs.saleprice == rhs.saleprice && lhs.isbn() == rhs.isbn();
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(rhs == lhs);
}

std::istream &operator>>(std::istream &is, Sales_data &rhs)
{
	is >> rhs.bookNo >> rhs.units_sold >> rhs.sellingprice >> rhs.saleprice;
	if (is && rhs.discount != 0)
	{
		rhs.discount = rhs.saleprice / rhs.sellingprice;
	}
	else
	{
		rhs = Sales_data();
	}
	return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &s)
{
	os << s.isbn() << " " << s.units_sold << " "
	   << s.sellingprice << " "
	   << s.saleprice << " "
	   << s.discount;
	return os;
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
	*this += rhs;
	return *this;
}

// nonmember Sales_data interface functions
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data ret(lhs);
	ret.combine(rhs);
	return ret;
}

std::ostream &print(std::ostream &os, const Sales_data &s)
{
	os << s;
	return os;
}

std::istream &read(std::istream &is, Sales_data &s)
{
	is >> s;
	return is;
}

// used in future chapters
inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() <= rhs.isbn();
}
#endif
