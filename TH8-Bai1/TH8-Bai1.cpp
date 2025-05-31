#include "NhanVien.h"

int main()
{
	int cont;
	CongTy ct;
	do
	{
		cout << "============CHUONG TRINH QUAN LY NHAN VIEN================" << endl;
		cout << "1. Nhap danh sach nhan vien" << endl;
		cout << "2. Xuat danh sanh nhan vien" << endl;
		cout << "3. Tinh tong luong ma cong ty tra cho cac nhan vien" << endl;
		cout << "4. Tim nhan vien san xuat co luong nho nhat" << endl;
		cout << "5. Tim nhan vien van phong co tuoi lon nhat" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "===========================================================" << endl;
		cout << "Lua chon cua ban la: ";
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cin >> ct;
			break;
		case 2:
			cout << ct;
			break;
		case 3:
			cout << "Tong luong phai tra cho nhan vien la: " << NhanVien::getTongLuong() << endl;
			break;
		case 4:
			if (ct.nvSX_luong_min() == NULL) cout << "Khong co nhan vien san xuat nao trong danh sach!" << endl;
			else
			{
				cout << "Thong tin nhan vien nho nhat:" << endl;
				ct.nvSX_luong_min() -> Xuat();
			}
			break;
		case 5:
			if (ct.nvVP_tuoi_max() == NULL) cout << "Khong co nhan vien san xuat nao trong danh sach!" << endl;
			else
			{
				cout << "Thong tin nhan vien nho nhat:" << endl;
				ct.nvVP_tuoi_max()->Xuat();
			}
			break;
		case 0:
			cout << "Thoat chuong trinh!....";
			return 0;
		default:
			cout << "Khong hop le!" << endl;
		}
		cout << "----------------------------------" << endl;
		cout << "Ban co muon tiep tuc khong?" << endl;
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
	cout << "Thoat chuong trinh!...";
	return 0;
}