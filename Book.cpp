#include "Book.h"

Book::Book()
{

}

Book::~Book()
{

}

string Book::Get_bookID()
{
	return _bookID;
}

string Book::Get_ISBN()
{
	return _ISBN;
}

string Book::Get_bookname()
{
	return _bookname;
}

istream& operator>> (istream& is, Book& book)
{
	try
	{
		cout << "Nhap ma sach: ";
		getline(is, book._bookID);
		do {
			cout << "Nhap ma ISBN-13 cua sach(978- hoac 979-): ";
			getline(is, book._ISBN);
		} while (book._ISBN.size() != 13 || book._ISBN[0] != '9' || book._ISBN[1] != '7' ||
			(book._ISBN[2] != '8' && book._ISBN[2] != '9'));
		cout << "Nhap ten tac gia: ";
		getline(is, book._author);
		cout << "Nhap nha xuat ban: ";
		getline(is, book._publisher);
		cout << "Nhap gia tien cua sach: ";
		is >> book._price;
		if (is.fail() || std::isnan(book._price) || book._price <= 0)
		{
			throw "Gia tien sach vua nhap vao khong dung";
		}

		return is;
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

ostream& operator<< (ostream& os, const Book& book)
{
	os << "Ma sach: " << book._bookID << endl;
	os << "Ma ISBN cua sach: " << book._ISBN << endl;
	os << "Ten sach" << book._bookname << endl;
	os << "Ten tac gia: " << book._author << endl;
	os << "Nha xuat ban: " << book._publisher << endl;
	os << "Gia tien cua sach: " << book._price << endl;

	return os;
}

void Book::input()
{
	try
	{
		cin.ignore();
		cout << "Nhap ma sach: ";
		getline(cin, _bookID);
		do {
			cout << "Nhap ma ISBN-13 cua sach(978- hoac 979-): ";
			getline(cin, _ISBN);
		} while (_ISBN.size() != 13 || _ISBN[0] != '9' || _ISBN[1] != '7' ||
			(_ISBN[2] != '8' && _ISBN[2] != '9'));
		cout << "Nhap ten sach: ";
		getline(cin, _bookname);
		cout << "Nhap ten tac gia: ";
		getline(cin, _author);
		cout << "Nhap nha xuat ban: ";
		getline(cin, _publisher);
		cout << "Nhap gia tien cua sach: ";
		cin >> _price;
		if (cin.fail() || _price <= 0)
		{
			throw "Gia tien sach vua nhap vao khong dung";
		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

void Book::output()
{
	cout << "Ma sach: " << _bookID << endl;
	cout << "Ma ISBN cua sach: " << _ISBN << endl;
	cout << "Ten sach: " << _bookname << endl;
	cout << "Ten tac gia: " << _author << endl;
	cout << "Nha xuat ban: " << _publisher << endl;
	cout << "Gia tien cua sach: " << _price << endl;
}

void Book::importFromFile(ifstream& is)
{
	return;
}

void Book::exportToFile(ofstream& os)
{
	os << _bookID << "\n" << _ISBN << "\n" << _bookname << "\n" << _author << "\n" << _publisher << "\n" << _price << endl;
}

