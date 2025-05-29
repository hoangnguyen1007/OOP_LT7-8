#include "NhanVien.h"

int main()
{
	CongTy ct;
	int choose;
	int cont;
	string s1;
	string s;
	do
	{
		cout << "===============CHUONG TRINH QUAN LY NHAN VIEN==================" << endl;
		cout << "1. Nhap danh sach nhan vien" << endl;
		cout << "2. Xuat nhan vien" << endl;
		cout << "3. Liet ke cac NVBC co he so luong tu 3.5" << endl;
		cout << "4. So luong NVHD co so ngay cong la 26" << endl;
		cout << "5. Tinh tong tien luong phong ke toan" << endl;
		cout << "6. Tinh tien luong trung binh cua NVBC" << endl;
		cout << "7. Kiem tra NVHD khong di lam ngay nao" << endl;
		cout << "8. Tim NVBC co he so luong cao nhat" << endl;
		cout << "9. Sap xep danh sach nhan vien tang dan theo ma so" << endl;
		cout << "10. Them mot nhan vien moi" << endl;
		cout << "11. Xoa mot nhan vien theo ma so" << endl;
		cout << "12. Tim kiem nhan vien" << endl;
		cout << "================================================================" << endl;
		cout << "Lua chon cua ban la: ";
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
			ct.NVBC_HSL();
			break;
		case 4:
			cout << "So luong NVHD co so ngay cong la 26 la: " << ct.SoNvhdCo26NgayCong()<<endl;
			break;
		case 5:
			cout << "Tong tien luong cua phong ke toan la: " << ct.TongLuongPhongKeToan() << endl;
			break;
		case 6:
			cout << "Luong trung binh cua cac NVBC la: " << ct.Luong_TB_NVBC()<<endl;
			break;
		case 7:
			if (ct.NvhdKhongDiLam()) cout << "Co nhan vien hop dong khong di lam ngay nao" << endl;
			else cout << "Khong co nhan vien hop dong khong di lam ngay nao" << endl;
			break;
		case 8:
			if (CongTy::getSoNVBC() == 0) cout << "Khong co nhan vien bien che nao trong danh sach!" << endl;
			else
			{
				cout << "Nhan vien bien che co he so luong cao nhat la: " << ct.NvbcHeSoLuongMax();
			}
			break;
		case 9:
			ct.sort_theo_ma_so();
			cout << "Da sap xep danh sach nhan vien" << endl;
			cout << "Danh sach nhan vien sau khi sap xep" << endl;
			cout << ct;
			break;
		case 10:
			ct.ThemNV();
			break;
			cout << "Da them thanh cong!" << endl;
			break;
		case 11:
			cout << "Nhap ma so nhan vien ban muon xoa: ";
			cin >> s;
			if (!ct.Xoa(s)) cout << "Khong tim thay ma so nhan vien tuong ung!" << endl;
			else cout << "Da xoa thanh cong!" << endl;
			break;
		case 12:
			cout << "Nhap tu khoa ban muon tim kiem: ";		
			cin.ignore();
			getline(cin, s1);
			ct.Tim(s1);
			break;
		case 0:
			cout << "Thoat chuong trinh!....";
			return 0;
		default:
			cout << "Khong co thao tac hop le!" << endl;
		}
		cout << "--------------------------------------------" << endl;
		cout << "Ban co muon tiep tuc khong ?" << endl;
		cout << "1. Co" << endl;
		cout << "0. Khong" << endl;
		cin >> cont;
		while (cin.fail() || (cont != 0 && cont != 1))
		{
			cin.clear();
			cin.ignore();
			cout << "Khong hop le! Vui long nhap lai: ";
			cin >> cont;
		}
		system("cls");
	} while (cont == 1);
	cout << "Dang thoat chuong trinh!....";
}