#include "Library.h"
#include "Reader.h"

int main()
{
	Library lib;
	int choose;

	do {
		system("cls");
		cout << "***************NHAP XUAT THONG TIN VE SACH**************" << endl;
		cout << "1. Nhap, them sach" << endl;
		cout << "2. Xuat sach" << endl;
		cout << "3. Tim kiem sach theo ID" << endl;
		cout << "4. Tim kiem sach theo ISBN" << endl;
		cout << "5. Tim kiem sach theo ten sach" << endl;
		cout << "*************NHAP XUAT THONG TIN VE DOC GIA*************" << endl;
		cout << "6. Nhap, them doc gia" << endl;
		cout << "7. Xuat doc gia" << endl;
		cout << "8. Tim kiem doc gia theo ID" << endl;
		cout << "9. Tim kiem doc gia theo ho ten" << endl;
		cout << "*********NHAP XUAT THONG TIN VE PHIEU MUON/TRA SACH*********" << endl;
		cout << "10. Nhap, them phieu muon/tra sach" << endl;
		cout << "11. Xuat phieu muon/tra sach" << endl;
		cout << "12. Nhap danh sach doc gia muon qua han va tien phat" << endl;
		cout << "********************************************************" << endl;
		cout << "0. Thoat chuong trinh" << endl;

		cout << "\nChon phuong thuc: ";
		cin >> choose;
		cout << endl;
		switch (choose)
		{
		case 1:
		{
			ofstream outbooks("ListBooks.txt", std::ios_base::app);
			if (!outbooks.fail())
			{
				lib.Input_ExportListBooks(outbooks);
				outbooks.close();
			}
			else
				cout << "Khong mo duoc file";

			system("pause");
			break;
		}
		case 2:
		{
			ifstream inbooks("ListBooks.txt");
			if (!inbooks.fail())
			{
				lib.Output_ImportListBooks(inbooks);
				inbooks.close();
			}
			else
				cout << "Khong mo duoc file";

			system("pause");
			break;
		}
		case 3:
		{
			lib.SearchBookWithID();

			system("pause");
			break;
		}
		case 4:
		{
			lib.SearchBookWithISBN();

			system("pause");
			break;
		}
		case 5:
		{
			lib.SearchBookWithBookName();

			system("pause");
			break;
		}
		case 6:
		{
			ofstream outreaders("ListReaders.txt", std::ios_base::app);
			if (!outreaders.fail())
			{
				lib.Input_ExportListReaders(outreaders);
				outreaders.close();
			}
			else
				cout << "Khong mo duoc file";

			system("pause");
			break;
		}
		case 7:
		{
			ifstream inreaders("ListReaders.txt");
			if (!inreaders.fail())
			{
				lib.Output_ImportListReaders(inreaders);
				inreaders.close();
			}
			else
				cout << "Khong mo duoc file";

			system("pause");
			break;
		}
		case 8:
		{
			lib.SearchReaderWithID();

			system("pause");
			break;
		}
		case 9:
		{
			lib.SearchReaderWithName();

			system("pause");
			break;
		}
		case 10:
		{
			ofstream outcards("ListCards.txt", std::ios_base::app);
			if (!outcards.fail())
			{
				lib.Input_ExportListCards(outcards);
				outcards.close();
			}
			else
				cout << "Khong mo duoc file";

			system("pause");
			break;
		}
		case 11:
		{
			ifstream incards("ListCards.txt");
			if (!incards.fail())
			{
				lib.Output_ImportListCards(incards);
				incards.close();
			}
			else
				cout << "Khong mo duoc file";

			system("pause");
			break;
		}
		case 12:
		{
			ifstream listlates("ListCards.txt");
			if (!listlates.fail())
			{
				lib.Output_ImportListOutOfDate(listlates);
				listlates.close();
			}
			else
				cout << "Khong mo duoc file";

			system("pause");
			break;
		}
		case 0:
		{
			break;
		}
		}
	} while (choose != 0);


	return 0;
}

