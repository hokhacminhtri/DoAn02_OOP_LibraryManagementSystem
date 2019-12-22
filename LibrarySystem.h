#pragma once

#ifndef _LIBRARYSYSTEM_
#define _LIBRARYSYSTEM_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class LibrarySystem
{
public:
	LibrarySystem();
	~LibrarySystem();

	virtual void input() = 0;
	virtual void output() = 0;
	virtual void importFromFile(ifstream&) = 0;
	virtual void exportToFile(ofstream&) = 0;
};

#endif
