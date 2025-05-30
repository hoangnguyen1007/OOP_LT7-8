#include "NhanVien.h"
long long NhanVien::tong_luong = 0;
NhanVien::~NhanVien() {};
NhanVien::NhanVien() {};
NhanVien::NhanVien(string ho_ten, NgayThangNam ngay_sinh) : ho_ten(ho_ten), ngay_sinh(ngay_sinh) {};
void NhanVien::Nhap()
{
	cout << "Nhap ho ten: ";
	cin.ignore();
	getline(cin, ho_ten);
	cout << "Nhap ngay sinh: "<<endl;
	ngay_sinh.Nhap();
}
void NhanVien::Xuat() const
{
	cout << "Ho ten: " << ho_ten<<endl;
	cout << "Ngay sinh: ";  
	ngay_sinh.Xuat();
	cout << endl;
}
string NhanVien::getHoTen() const
{
	return ho_ten;
}
NgayThangNam NhanVien::getNgaySinh() const
{
	return ngay_sinh;
}
long long NhanVien::getLuong() const
{
	return luong;
}
long long NhanVien::getTongLuong()
{
	return tong_luong;
}
nvVanPhong::nvVanPhong() {};
nvVanPhong::nvVanPhong(long long luong_can_ban, int so_san_pham) : luong_can_ban(luong_can_ban), so_san_pham(so_san_pham) {};
void nvVanPhong::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap luong can ban: ";
	cin >> luong_can_ban;
	while (cin.fail() || luong_can_ban < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap luong can ban: ";
		cin >> luong_can_ban;
	}
	cout << "Nhap so san pham: ";
	cin >> so_san_pham;
	while (cin.fail() || so_san_pham < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so san pham: ";
		cin >> so_san_pham;
	}
	luong = luong_can_ban + so_san_pham * 5000;
	tong_luong += luong;
}
void nvVanPhong::Xuat() const
{
	NhanVien::Xuat();
	cout << "Luong: " << luong << endl;
}
long long nvVanPhong::getLuongCanBan() const
{
	return luong_can_ban;
}
int nvVanPhong::getSoSanPham() const
{
	return so_san_pham;
}
string nvVanPhong::getLoai() const
{
	return "Van phong";
}
nvSanXuat::nvSanXuat() {};
nvSanXuat::nvSanXuat(int so_ngay_cong) : so_ngay_lam_viec(so_ngay_cong) {};
void nvSanXuat::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap so ngay lam viec: ";
	cin >> so_ngay_lam_viec;
	while (cin.fail() || so_ngay_lam_viec < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so ngay lam viec: ";
		cin >> so_ngay_lam_viec;
	}
	luong = so_ngay_lam_viec * 100000;
	tong_luong += luong;
}
void nvSanXuat::Xuat() const
{
	NhanVien::Xuat();
	cout << "Luong: " << luong << endl;
}
int nvSanXuat::getSoNgayLamViec() const
{
	return so_ngay_lam_viec;
}
string nvSanXuat::getLoai() const
{
	return "San xuat";
}
int CongTy::so_NVSX = 0;
int CongTy::so_NVVP = 0;
CongTy::~CongTy()
{
	for (int i = 0; i < sl; i++)
	{
		delete ct[i];
	}
	delete ct;
}
CongTy::CongTy() {};
void CongTy::Nhap()
{
	cout << "Nhap so luong nhan vien: ";
	cin >> sl;
	while (cin.fail() || sl < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so luong nhan vien: ";
		cin >> sl;
	}
	ct = new NhanVien * [sl];
	for (int i = 0; i < sl; i++)
	{
		cout << "=====Nhap nhan vien thu "<<i + 1<<"=====" << endl;
		cout << "Nhap loai nhan vien (1. Van phong / 2. San xuat): ";
		int k;
		cin >> k;
		if (k == 1)
		{
			so_NVSX++;
			ct[i] = new nvVanPhong;
			ct[i]->Nhap();
		}
		else
		{
			so_NVVP++;
			ct[i] = new nvSanXuat;
			ct[i]->Nhap();
		}
	}
}
void CongTy::Xuat() const
{
	for (int i = 0; i < sl; i++)
	{
		cout << "-------------------------------------" << endl;
		ct[i]->Xuat();
	}
}
istream& operator>>(istream& is, CongTy& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const CongTy& x)
{
	x.Xuat();
	return os;
}
int CongTy::getSoNVVP()
{
	return so_NVVP;
}
int CongTy::getSoNVSX()
{
	return so_NVSX;
}
NhanVien* CongTy::nvSX_luong_min()
{
	if (getSoNVSX() == 0) return NULL;
	int minl = INT16_MAX;
	int index = 0;
	for (int i = 0; i < sl; i++)
	{
		if (ct[i]->getLuong() < minl && ct[i]->getLoai() == "San xuat")
		{
			index = i;
		}
	}
	return ct[index];
}
NhanVien* CongTy::nvVP_tuoi_max()
{
	if (getSoNVVP() == 0) return NULL;
	int tMax = 0;
	int index = 0;
	for (int i = 0; i < sl; i++)
	{
		if (2025 - ct[i]->getNgaySinh().getNam() > tMax && ct[i]->getLoai() == "Van phong")
		{
			index = i;
		}
	}
	return ct[index];
}