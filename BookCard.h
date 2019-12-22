#pragma once

#ifndef _BOOKCARD
#define _BOOKCARD_

#include "LibrarySystem.h"
#include "Book.h"
#include "Date.h"

class BookCard :public LibrarySystem, Date
{
private:
	string _customerID;
	string _customername;
	int _borrowtype;
	string _borrowID;
	string _borrowISBN;
	string _borrowname;
	Date _borrowdate;
	Date _returndate;
public:
	BookCard();
	~BookCard();

	Date Get_borrowdate();
	Date Get_returndate();

	void input();
	void output();
	void importFromFile(ifstream&);
	void exportToFile(ofstream&);
};

#endif

