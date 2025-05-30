#include "SinhVien.h"

int main()
{
	DaiHoc dh;
	int cont;
	do
	{
		cout << "=============CHUONG TRINH QUAN LY SINH VIEN================" << endl;
		cout << "1. Nhap danh sach sinh vien" << endl;
		cout << "2. Xuat danh sach sinh vien" << endl;
		cout << "3. Xuat danh sach sinh vien du dieu kien tot nghiep" << endl;
		cout << "4. Xuat danh sach sinh vien khong du dieu kien tot nghiep" << endl;
		cout << "5. Tim sinh vien dai hoc co diem trung binh cao nhat" << endl;
		cout << "6. Tim sinh vien cao dang co diem trung binh cao nhat" << endl;
		cout << "7. So sinh vien dai hoc khong du dieu kien tot nghiep" << endl;
		cout << "8. So sinh vien cao dang khong du dieu kien tot nghiep" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "===========================================================" << endl;
		cout << "Lua chon cua ban la: ";
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cin >> dh;
			break;
		case 2:
			cout << dh;
			break;
		case 3:
			dh.dsSVDuDieuKienTN();
			break;
		case 4:
			dh.dsSVKhongDuDieuKienTN();
			break;
		case 5:
			if (dh.svDH_DTB_max() == NULL) cout << "Khong co sinh vien dai hoc nao trong danh sach!" << endl;
			else
			{
				cout << "Sinh vien dai hoc co diem trung binh cao nhat la: " << endl;
				dh.svDH_DTB_max()->Xuat();
			}
			break;
		case 6:
			if (dh.svCD_DTB_max() == NULL) cout << "Khong co sinh vien cao dang nao trong danh sach!" << endl;
			else
			{
				cout << "Sinh vien cao dang co diem trung binh cao nhat la: " << endl;
				dh.svCD_DTB_max()->Xuat();
			}
			break;
		case 7:
			cout << "So sinh vien dai hoc khong du dieu kien tot nghiep la: " << dh.so_SVDH_khong_TN() << endl;
			break;
		case 8:
			cout << "So sinh vien cao dang khong du dieu kien tot nghiep la: " << dh.so_SVCD_khong_TN() << endl;
			break;
		case 0:
			cout << "Thoat chuong trinh!..." << endl;
			return 0;
		default:
			cout << "Khong hop le!" << endl;
		}
		cout << "----------------------------------------" << endl;
		cout << "Ban co muon tiep tuc khong ?" << endl;
		cout << "1. Co" << endl;
		cout << "0. Khong" << endl;
		cout << "Lua chon cua ban la: ";
		cin >> cont;
		while (cin.fail() || (cont != 0 && cont != 1))
		{
			cin.clear();
			cin.ignore();
			cout << "Khong hop le! Vui long nhap lai!" << endl;
			cout << "Lua chon cua ban la: ";
			cin >> cont;
		}
		system("cls");
	} while (cont == 1);
	cout << "Dang thoat chuong trinh!..." << endl;
}