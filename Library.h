#pragma once

#ifndef _LIBRARY_
#define _LIBRARY_
 
#include "Book.h"
#include "Reader.h"
#include "BookCard.h"
#include "Date.h"


class Library
{
private:
	vector<Book> listbooks;
	vector<Reader> listreaders;
	vector<BookCard> listcards;
public:
	void Input_ExportListBooks(ofstream&);
	void Output_ImportListBooks(ifstream&);
	void SearchBookWithID();
	void SearchBookWithISBN();
	void SearchBookWithBookName();
	void Input_ExportListReaders(ofstream&);
	void Output_ImportListReaders(ifstream&);
	void SearchReaderWithID();
	void SearchReaderWithName();
	void Input_ExportListCards(ofstream&);
	void Output_ImportListCards(ifstream&);

	void Output_ImportListOutOfDate(ifstream&);
};

#endif

