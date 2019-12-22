#include "Reader.h"

Reader::Reader()
{

}

Reader::~Reader()
{

}

string Reader::Get_ID()
{
	return _ID;
}

string Reader::Get_fullname()
{
	return _fullname;
}

istream& operator>> (istream& is, Reader& reader)
{
	try
	{
		cout << "Nhap ID cua doc gia: ";
		getline(is, reader._ID);
		cout << "Nhap ho ten doc gia: ";
		getline(is, reader._fullname);
		cout << "Nhap dia chi: ";
		getline(is, reader._address);
		cout << "Nhap tuoi: ";
		is >> reader._age;
		if (is.fail() || std::isnan((double)reader._age) || reader._age <= 0)
		{
			throw "Tuoi vua nhap vao khong dung";
		}
		cout << "Nhap ngay sinh: ";
		is >> reader._dateofbirth;

		return is;
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

ostream& operator<< (ostream& os, const Reader& reader)
{
	os << "ID cua doc gia: " << reader._ID << endl;
	os << "Ho ten doc gia: " << reader._fullname << endl;
	os << "Dia chi: " << reader._address << endl;
	os << "Tuoi: " << reader._age << endl;
	os << "Ngay sinh: " << reader._dateofbirth << endl;

	return os;
}

void Reader::input()
{
	try
	{
		cin.ignore();
		cout << "Nhap ID cua doc gia: ";
		getline(cin, _ID);
		cout << "Nhap ho ten: ";
		getline(cin, _fullname);
		cout << "Nhap dia chi: ";
		getline(cin, _address);
		cout << "Nhap tuoi: ";
		cin >> _age;
		if (cin.fail() || _age <= 0)
		{
			throw "Tuoi vua nhap vao khong dung";
		}
		cout << "Nhap ngay sinh: ";
		cin >> _dateofbirth;
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

void Reader::output()
{
	cout << "ID cua doc gia: " << _ID << endl;
	cout << "Ho ten doc gia: " << _fullname << endl;
	cout << "Dia chi: " << _address << endl;
	cout << "Tuoi: " << _age << endl;
	cout << "Ngay sinh: " << _dateofbirth << endl;
}

void Reader::importFromFile(ifstream& is)
{
	return;
}

void Reader::exportToFile(ofstream& os)
{
	os << _ID << "\n" << _fullname << "\n" << _address << "\n" << _age << "\n" << _dateofbirth << endl;
}
