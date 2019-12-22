#include "Library.h"
void Library::Input_ExportListBooks(ofstream& os)
{
	system("cls");
	cout << "NHAP VAO DANH SACH CAC CUON SACH VA LUU VAO FILE" << endl;
	cout << endl;

	Book book;
	book.input();
	listbooks.push_back(book);

	for (int i = 0; i < listbooks.size(); i++)
	{
		listbooks[i].exportToFile(os);
	}
}

void Library::Output_ImportListBooks(ifstream& is)
{
	system("cls");
	cout << "XUAT RA DANH SACH CAC CUON SACH VA DOC TU FILE VAO" << endl;
	cout << endl;

	cout << "\nDanh sach cac cuon sach: " << endl;
	cout << endl;
	for (int i = 0; i < listbooks.size(); i++)
	{
		listbooks[i].output();
		cout << "******************************************" << endl;
	}

	cout << "\nDanh sach cac cuon sach doc tu file ListBooks.txt" << endl;
	cout << endl;
	while (true)
	{
		
		Book temp;

		string bookID, ISBN, bookname, author, publisher;
		double price;

		getline(is, bookID);
		getline(is, ISBN);
		getline(is, bookname);
		getline(is, author);
		getline(is, publisher);
		is >> price;
		is.ignore();
		
		if (is.eof())
			break;

		cout << "Ma sach: " << bookID << endl;
		cout << "Ma ISBN cua sach: " << ISBN << endl;
		cout << "Ten sach: " << bookname << endl;
		cout << "Ten tac gia: " << author << endl;
		cout << "Nha xuat ban: " << publisher << endl;
		cout << "Gia tien: " << price << endl;
		
		cout << "******************************************" << endl;
	}
}

void Library::SearchBookWithID()
{
	system("cls");
	string bookID;
	cout << "Nhap ID sach can tim: ";
	cin.ignore();
	getline(cin, bookID);
	cout << "\nSach tuong ung voi ID vua nhap vao: " << endl;
	for (int i = 0; i < listbooks.size(); i++)
	{
		if (bookID == listbooks[i].Get_bookID())
		{
			listbooks[i].output();
			cout << "******************************************" << endl;
		}
	}

	cout << "\nTim sach trong ListBooks.txt" << endl;
	ifstream searchbook("ListBooks.txt");
	string data;
	if (!searchbook.fail())
	{
		while (true)
		{
			getline(searchbook, data);
			if (data == bookID)
			{
				cout << "SACH CAN TIM CO TRONG DANH SACH" << endl;
				cout << endl;
				break;
			}
			if (searchbook.eof())
			{
				cout << "SACH CAN TIM KHONG CO TRONG DANH SACH" << endl;
				cout << endl;
				break;
			}
		}
		searchbook.close();
	}
	else
		cout << "Khong mo duoc file";
}

void Library::SearchBookWithISBN()
{
	system("cls");
	string ISBN;
	cout << "Nhap ISBN sach can tim: ";
	cin.ignore();
	getline(cin, ISBN);
	cout << "\nSach tuong ung voi ISBN vua nhap vao: " << endl;
	for (int i = 0; i < listbooks.size(); i++)
	{
		if (ISBN == listbooks[i].Get_ISBN())
		{
			listbooks[i].output();
			cout << "******************************************" << endl;
		}
	}

	cout << "\nTim sach trong ListBooks.txt" << endl;
	ifstream searchbook("ListBooks.txt");
	string data;
	if (!searchbook.fail())
	{
		while (true)
		{
			getline(searchbook, data);
			if (data == ISBN)
			{
				cout << "SACH CAN TIM CO TRONG DANH SACH" << endl;
				cout << endl;
				break;
			}
			if (searchbook.eof())
			{
				cout << "SACH CAN TIM KHONG CO TRONG DANH SACH" << endl;
				cout << endl;
				break;
			}
		}
		searchbook.close();
	}
	else
		cout << "Khong mo duoc file";
}

void Library::SearchBookWithBookName()
{
	system("cls");
	string bookname;
	cout << "Nhap ten sach can tim: ";
	cin.ignore();
	getline(cin, bookname);
	cout << "\nSach tuong ung voi ten vua nhap vao: " << endl;
	for (int i = 0; i < listbooks.size(); i++)
	{
		if (bookname == listbooks[i].Get_bookID())
		{
			listbooks[i].output();
			cout << "******************************************" << endl;
		}
	}

	cout << "\nTim sach trong ListBooks.txt" << endl;
	ifstream searchbook("ListBooks.txt");
	string data;
	if (!searchbook.fail())
	{
		while (true)
		{
			getline(searchbook, data);
			if (data == bookname)
			{
				cout << "SACH CAN TIM CO TRONG DANH SACH" << endl;
				cout << endl;
				break;
			}
			if (searchbook.eof())
			{
				cout << "SACH CAN TIM KHONG CO TRONG DANH SACH" << endl;
				cout << endl;
				break;
			}
		}
		searchbook.close();
	}
	else
		cout << "Khong mo duoc file";
}

void Library::Input_ExportListReaders(ofstream& os)
{
	system("cls");
	cout << "NHAP VAO DANH SACH CAC DOC GIA VA LUU VAO FILE" << endl;
	cout << endl;

	Reader reader;
	reader.input();
	listreaders.push_back(reader);

	for (int i = 0; i < listreaders.size(); i++)
	{
		listreaders[i].exportToFile(os);
	}
}

void Library::Output_ImportListReaders(ifstream& is)
{
	system("cls");
	cout << "XUAT RA DANH SACH CAC DOC GIA VA DOC TU FILE VAO" << endl;
	cout << endl;

	cout << "\nDanh sach cac doc gia: " << endl;
	cout << endl;
	for (int i = 0; i < listreaders.size(); i++)
	{
		listreaders[i].output();
		cout << "******************************************" << endl;
	}

	cout << "\nDanh sach cac doc gia doc tu file ListReaders.txt" << endl;
	cout << endl;
	while (true)
	{
		string ID, fullname, address;
		int age;
		Date dateofbirth;

		getline(is, ID);
		getline(is, fullname);
		getline(is, address);
		is >> age;
		is.ignore();
		if (is.eof())
			break;
		inputDateFromFile(is, dateofbirth);
		is.ignore();
		

		cout << "ID cua doc gia: " << ID << endl;
		cout << "Ho ten doc gia: " << fullname << endl;
		cout << "Dia chi: " << address << endl;
		cout << "Tuoi: " << age << endl;
		cout << "Ngay sinh: " << dateofbirth << endl;

		cout << "******************************************" << endl;
	}
}

void Library::SearchReaderWithID()
{
	system("cls");
	string ID;
	cout << "Nhap ID doc gia can tim: ";
	cin.ignore();
	getline(cin, ID);
	cout << "\nDoc gia tuong ung voi ID vua nhap vao: " << endl;
	for (int i = 0; i < listreaders.size(); i++)
	{
		if (ID == listreaders[i].Get_ID())
		{
			listreaders[i].output();
			cout << "******************************************" << endl;
		}
	}

	cout << "\nTim doc gia trong ListReaders.txt" << endl;
	ifstream searchbook("ListReaders.txt");
	string data;
	if (!searchbook.fail())
	{
		while (true)
		{
			getline(searchbook, data);
			if (data == ID)
			{
				cout << "DOC GIA CAN TIM CO TRONG DANH SACH" << endl;
				cout << endl;
				break;
			}
			if (searchbook.eof())
			{
				cout << "DOC GIA CAN TIM KHONG CO TRONG DANH SACH" << endl;
				cout << endl;
				break;
			}
		}
		searchbook.close();
	}
	else
		cout << "Khong mo duoc file";
}

void Library::SearchReaderWithName()
{
	system("cls");
	string fullname;
	cout << "Nhap ho ten doc gia can tim: ";
	cin.ignore();
	getline(cin, fullname);
	cout << "\nDoc gia tuong ung voi ho ten vua nhap vao: " << endl;
	for (int i = 0; i < listreaders.size(); i++)
	{
		if (fullname == listreaders[i].Get_fullname())
		{
			listreaders[i].output();
			cout << "******************************************" << endl;
		}
	}

	cout << "\nTim doc gia trong ListReaders.txt" << endl;
	ifstream searchbook("ListReaders.txt");
	string data;
	if (!searchbook.fail())
	{
		while (true)
		{
			getline(searchbook, data);
			if (data == fullname)
			{
				cout << "DOC GIA CAN TIM CO TRONG DANH SACH" << endl;
				cout << endl;
				break;
			}
			if (searchbook.eof())
			{
				cout << "DOC GIA CAN TIM KHONG CO TRONG DANH SACH" << endl;
				cout << endl;
				break;
			}
		}
		searchbook.close();
	}
	else
		cout << "Khong mo duoc file";
}

void Library::Input_ExportListCards(ofstream& os)
{
	system("cls");
	cout << "NHAP VAO DANH SACH CAC PHIEU MUON SACH VA LUU VAO FILE" << endl;
	cout << endl;

	BookCard card;
	card.input();
	listcards.push_back(card);

	for (int i = 0; i < listcards.size(); i++)
	{
		listcards[i].exportToFile(os);
	}
}

void Library::Output_ImportListCards(ifstream& is)
{
	system("cls");
	cout << "XUAT RA DANH SACH CAC PHIEU MUON VA DOC TU FILE VAO" << endl;
	cout << endl;

	cout << "\nDanh sach cac phieu muon: " << endl;
	cout << endl;
	for (int i = 0; i < listcards.size(); i++)
	{
		listcards[i].output();
		cout << "******************************************" << endl;
	}

	cout << "\nDanh sach cac phieu muon doc tu file ListCards.txt" << endl;
	cout << endl;
	while (true)
	{
		string customerID, customername, borrowID, borrowISBN, borrowname;
		int borrowtype;
		Date borrowdate, returndate;

		getline(is, customerID);
		getline(is, customername);
		is >> borrowtype;
		is.ignore();
		getline(is, borrowID);
		getline(is, borrowISBN);
		getline(is, borrowname);
		if (is.eof())
			break;
		inputDateFromFile(is, borrowdate);
		inputDateFromFile(is, returndate);
		is.ignore();

		

		cout << "ID cua nguoi muon sach: " << customerID << endl;
		cout << "Ho ten nguoi muon sach: " << customername << endl;
		cout << "loai sach muon(1-sach tieng Viet, 2-sach Ngoai van): " << borrowtype << endl;
		cout << "ID cua sach muon: " << borrowID << endl;
		cout << "ISBN cua sach muon: " << borrowISBN << endl;
		cout << "Ten cua sach muon: " << borrowname << endl;
		cout << "Ngay muon sach: " << borrowdate << endl;
		cout << "Ngay tra sach: " << returndate << endl;

		cout << "******************************************" << endl;
	}
}

void Library::Output_ImportListOutOfDate(ifstream& is)
{
	system("cls");
	cout << "Danh sach nhung nguoi muon sach qua han" << endl;
	cout << endl;

	while (true)
	{
		string customerID, customername, borrowID, borrowISBN, borrowname;
		int borrowtype;
		Date borrowdate, returndate;

		getline(is, customerID);
		getline(is, customername);
		is >> borrowtype;
		is.ignore();
		getline(is, borrowID);
		getline(is, borrowISBN);
		getline(is, borrowname);
		if (is.eof())
			break;
		inputDateFromFile(is, borrowdate);
		inputDateFromFile(is, returndate);
		is.ignore();

		if (returndate.countDay(borrowdate) > 7)
		{
			cout << "ID cua nguoi muon sach: " << customerID << endl;
			cout << "Ho ten nguoi muon sach: " << customername << endl;
			cout << "loai sach muon(1-sach tieng Viet, 2-sach Ngoai van): " << borrowtype << endl;
			cout << "ID cua sach muon: " << borrowID << endl;
			cout << "ISBN cua sach muon: " << borrowISBN << endl;
			cout << "Ten cua sach muon: " << borrowname << endl;
			cout << "Ngay muon sach: " << borrowdate << endl;
			cout << "Ngay tra sach: " << returndate << endl;
			if (borrowtype == 1)
				cout << "Sach Tieng Viet. So tien phat: " << 10000 * returndate.countDay(borrowdate) << " dong" << endl;
			if (borrowtype == 2)
				cout << "Sach Ngoai van. So tien phat: " << 20000 * returndate.countDay(borrowdate) << " dong" << endl;
		}
	
		cout << "******************************************" << endl;
	}
}



