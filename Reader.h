#pragma once

#ifndef _READER_
#define _READER_

#include "LibrarySystem.h"
#include "Date.h"

class Reader :public LibrarySystem
{
private:
	string _ID;
	string _fullname;
	string _address;
	int _age;
	Date _dateofbirth;
public:
	Reader();
	~Reader();

	string Get_ID();
	string Get_fullname();

	friend istream& operator>> (istream&, Reader&);
	friend ostream& operator<< (ostream&, const Reader&);

	void input();
	void output();
	void importFromFile(ifstream&);
	void exportToFile(ofstream&);
};

#endif

