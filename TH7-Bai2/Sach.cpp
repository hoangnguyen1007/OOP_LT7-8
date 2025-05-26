#include "Sach.h"
long long Sach::thanh_tien = 0;
Sach::Sach() {};
void Sach::Nhap()
{
	cout << "Nhap ma sach: ";
	cin.ignore();
	getline(cin, ma_sach);
	ngay_nhap.Nhap();
	cout << "Nhap so luong: ";
	cin >> so_luong;
	while (cin.fail() || so_luong < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so luong: ";
		cin >> so_luong;
	}
	cout << "Nhap don gia: ";
	cin >> don_gia;
	while (cin.fail() || so_luong < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap don gia: ";
		cin >> don_gia;
	}
	cout << "Nhap nha xuat ban: ";
	cin.ignore();
	getline(cin, nha_xb);
}
void Sach::Xuat() const
{
	cout << "Ma sach: " << ma_sach << endl;
	cout << "Ngay nhap: "; ngay_nhap.Xuat();
	cout << "\nSo luong: " << so_luong << endl;
	cout << "Don gia: " << don_gia << endl;
	cout << "Nha xuat ban: " << nha_xb<<endl;
}
string Sach::getMaSach() const
{
	return ma_sach;
}
NgayThangNam Sach::getNgayNhap() const
{
	return ngay_nhap;
}
int Sach::getSoLuong() const
{
	return so_luong;
}
long long Sach::TinhThanhTien()
{
	return thanh_tien;
}
string Sach::getNhaXB() const
{
	return nha_xb;
}
void Sach::setMaSach(string ma_sach)
{
	this->ma_sach = ma_sach;
}
void Sach::setSoLuong(int so_luong)
{
	this->so_luong = so_luong;
}
void Sach::setNgayNhap(NgayThangNam ngay_nhap)
{
	this->ngay_nhap = ngay_nhap;
}
void Sach::setNhaXB(string nha_xb)
{
	this->nha_xb = nha_xb;
}
void Sach::setDonGia(long long don_gia)
{
	this->don_gia = don_gia;
}
istream& operator>>(istream& is, Sach& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const Sach& x)
{
	x.Xuat();
	return os;
}
long long Sach_GK::thanh_tien_SGK = 0;
Sach_GK::Sach_GK() {};
void Sach_GK::Nhap()
{
	Sach::Nhap();
	cout << "Nhap tinh trang: ";
	cin >> tinh_trang;
	while (cin.fail() || (tinh_trang != "cu" && tinh_trang != "moi"))
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai" << endl;
		cout << "Nhap tinh trang: ";
		cin >> tinh_trang;
	}
	if (tinh_trang == "moi")
	{
		long long tien = so_luong * don_gia;
		thanh_tien_SGK += tien;
		thanh_tien += tien;
	}
	else
	{
		long long tien = (so_luong * don_gia * 0.5);
		thanh_tien_SGK += tien;
		thanh_tien += tien;
	}
}
void Sach_GK::Xuat() const
{
	Sach::Xuat();
	cout << "Tinh trang: " << tinh_trang<<endl;
}
string Sach_GK::getTinhTrang()
{
	return tinh_trang;
}
long long Sach_GK::getThanhTienSGK()
{
	return thanh_tien_SGK;
}
void Sach_GK::setTinhTrang(string tinh_trang)
{
	this->tinh_trang = tinh_trang;
}
bool Sach_GK::tim(string NXB)
{
	if (NXB == nha_xb) return 1;
	else return 0;
}
istream& operator >>(istream& is, Sach_GK& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const Sach_GK& x)
{
	x.Xuat();
	return os;
}
long long Sach_TK::thanh_tien_STK = 0;
long long Sach_TK::don_gia_STK = 0;
int Sach_TK::dem = 0;
Sach_TK::Sach_TK() {}
void Sach_TK::Nhap()
{
	Sach::Nhap();
	don_gia_STK += don_gia;
	dem++;
	cout << "Nhap thue: ";
	cin >> thue;
	long long tien = so_luong * don_gia + thue;
	thanh_tien_STK += tien;
	thanh_tien += tien;

}
void Sach_TK::Xuat() const
{
	Sach::Xuat();
	cout << "Thue: " << thue<<endl;
}
istream& operator>>(istream& is, Sach_TK& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const Sach_TK& x)
{
	x.Xuat();
	return os;
}
double Sach_TK::getThue()
{
	return thue;
}
long long Sach_TK::getThanhTienSTK()
{
	return thanh_tien_STK;
}
void Sach_TK::setThue(double thue)
{
	this->thue = thue;
}
double Sach_TK::tinh_TBC()
{
	return don_gia_STK / dem;
}