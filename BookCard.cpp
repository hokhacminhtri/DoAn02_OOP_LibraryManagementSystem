#include "BookCard.h"

BookCard::BookCard()
{

}

BookCard::~BookCard()
{

}

Date BookCard::Get_borrowdate()
{
	return _borrowdate;
}

Date BookCard::Get_returndate()
{
	return _returndate;
}

void BookCard::input()
{
	try
	{
		cin.ignore();
		cout << "Nhap ID cua nguoi muon sach: ";
		getline(cin, _customerID);
		cout << "Nhap ho ten nguoi muon sach: ";
		getline(cin, _customername);
		do {
			cout << "Nhap loai sach muon(1-sach tieng Viet, 2-sach Ngoai van): ";
			cin >> _borrowtype;
			if (cin.fail())
			{
				throw "Loai sach vua nhap vao khong dung";
			}
		} while (_borrowtype != 1 && _borrowtype != 2);
		cin.ignore();
		cout << "Nhap ID cua sach muon: ";
		getline(cin, _borrowID);
		do {
			cout << "Nhap ma ISBN-13 cua sach muon(978- hoac 979-): ";
			getline(cin, _borrowISBN);
		} while (_borrowISBN.size() != 13 || _borrowISBN[0] != '9' || _borrowISBN[1] != '7' ||
			(_borrowISBN[2] != '8' && _borrowISBN[2] != '9'));
		cout << "Nhap ten sach muon: ";
		getline(cin, _borrowname);
		cout << "Nhap ngay muon sach: ";
		cin >> _borrowdate;
		cout << "Nhap ngay tra sach: ";
		cin >> _returndate;
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

void BookCard::output()
{
	cout << "ID cua nguoi muon sach: " << _customerID << endl;
	cout << "Ho ten nguoi muon sach: " << _customername << endl;
	cout << "loai sach muon(1-sach tieng Viet, 2-sach Ngoai van): " << _borrowtype << endl;
	cout << "ID cua sach muon: " << _borrowID << endl;
	cout << "ISBN cua sach muon: " << _borrowISBN << endl;
	cout << "Ten cua sach muon: " << _borrowname << endl;
	cout << "Ngay muon sach: " << _borrowdate << endl;
	cout << "Ngay tra sach: " << _returndate << endl;
}

void BookCard::importFromFile(ifstream& is)
{
	return;
}

void BookCard::exportToFile(ofstream& os)
{
	os << _customerID << "\n" << _customername << "\n" << _borrowtype << "\n" << _borrowID << "\n" << _borrowISBN << "\n" << _borrowname << "\n" << _borrowdate << "\n" << _returndate << endl;
}

