#pragma once

#ifndef _BOOK_
#define _BOOK_

#include "LibrarySystem.h"

class Book :public LibrarySystem
{
private:
	string _bookID;
	string _ISBN;
	string _bookname;
	string _author;
	string _publisher;
	double _price;
public:
	Book();
	~Book();

	string Get_bookID();
	string Get_ISBN();
	string Get_bookname();

	friend istream& operator>> (istream&, Book&);
	friend ostream& operator<< (ostream&, const Book&);

	void input();
	void output();
	void importFromFile(ifstream&);
	void exportToFile(ofstream&);
};

#endif
