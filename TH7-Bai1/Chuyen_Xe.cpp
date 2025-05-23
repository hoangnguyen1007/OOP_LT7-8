#include "Chuyen_Xe.h"
long long Chuyen_Xe::tong_doanh_thu = 0;
Chuyen_Xe::Chuyen_Xe() {};
Chuyen_Xe::Chuyen_Xe(string MS_chuyen, string ho_tenTX, int so_xe, long long doanh_thu)
{
	this->MS_chuyen = MS_chuyen;
	this->ho_ten_tx = ho_tenTX;
	this->so_xe = so_xe;
	this->doanh_thu = doanh_thu;
	tong_doanh_thu += doanh_thu;
}
string Chuyen_Xe::getMS()
{
	return MS_chuyen;
}
string Chuyen_Xe::getHoTenTX()
{
	return ho_ten_tx;
}
int Chuyen_Xe::getSoXe()
{
	return so_xe;
}
long long Chuyen_Xe::TongDoanhThu()
{
	return tong_doanh_thu;
}
void Chuyen_Xe::Nhap()
{	
	cout << "Nhap ma so chuyen xe: ";
	cin.ignore();
	getline(cin, MS_chuyen);
	cout << "Nhap ho ten tai xe: ";
	cin.ignore();
	getline(cin, ho_ten_tx);
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap ho ten tai xe: ";
		getline(cin, ho_ten_tx);
	}
	cout << "Nhap so xe: ";
	cin >> so_xe;
	while (cin.fail() || so_xe < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so xe: ";
		cin >> so_xe;
	}
	cout << "Nhap doanh thu: ";
	cin >> doanh_thu;
	while (cin.fail() || so_xe < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap doanh thu: ";
		cin >> doanh_thu;
	}
	tong_doanh_thu += doanh_thu;
}
void Chuyen_Xe::Xuat() const
{
	cout << "Ma so chuyen xe: " << MS_chuyen << endl;
	cout << "Ho ten tai xe: " << ho_ten_tx << endl;
	cout << "So xe: " << so_xe << endl;
	cout << "Doanh thu cua xe: " << doanh_thu << endl;
}
istream& operator>>(istream& is, Chuyen_Xe& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const Chuyen_Xe& x)
{
	x.Xuat();
	return os;
}
long long ChuyenXeNgoaiThanh::TongDoanhThuNgoaiThanh = 0;
ChuyenXeNgoaiThanh::ChuyenXeNgoaiThanh() {};
ChuyenXeNgoaiThanh::ChuyenXeNgoaiThanh(string MS_chuyen, string ho_tenTX, int so_xe, long long doanh_thu, int so_tuyen, int so_km) : Chuyen_Xe(MS_chuyen, ho_tenTX, so_xe, doanh_thu), so_tuyen(so_tuyen), so_km(so_km)
{
	TongDoanhThuNgoaiThanh += doanh_thu;
}
int ChuyenXeNgoaiThanh::getSoTuyen()
{
	return so_tuyen;
}
int ChuyenXeNgoaiThanh::getSoKM()
{
	return so_km;
}
long long ChuyenXeNgoaiThanh::getDoanhThuNgoaiThanh()
{
	return TongDoanhThuNgoaiThanh;
}
void ChuyenXeNgoaiThanh::Nhap()
{
	Chuyen_Xe::Nhap();
	cout << "Nhap so tuyen: ";
	cin >> so_tuyen;
	while (cin.fail() || so_tuyen < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so tuyen: ";
		cin >> so_tuyen;
	}
	cout << "Nhap so km: ";
	cin >> so_km;
	while (cin.fail() || so_tuyen < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so km: ";
		cin >> so_km;
	}
	TongDoanhThuNgoaiThanh += getDoanhThu();
}
void ChuyenXeNgoaiThanh::Xuat() const
{
	Chuyen_Xe::Xuat();
	cout << "So tuyen: " << so_tuyen << endl;
	cout << "So km: " << so_km << endl;
}
istream& operator>>(istream& is, ChuyenXeNgoaiThanh& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const ChuyenXeNgoaiThanh& x)
{
	x.Xuat();
	return os;
}
long long ChuyenXeNoiThanh::TongDoanhThuNoiThanh = 0;
ChuyenXeNoiThanh::ChuyenXeNoiThanh() {};
ChuyenXeNoiThanh::ChuyenXeNoiThanh(string MS_chuyen, string ho_tenTX, int so_xe, long long doanh_thu, string noi_den, int so_ngay_di) : Chuyen_Xe(MS_chuyen, ho_tenTX, so_xe, doanh_thu), noi_den(noi_den), so_ngay_di(so_ngay_di)
{
	TongDoanhThuNoiThanh += doanh_thu;
}
string ChuyenXeNoiThanh::getNoiDen()
{
	return noi_den;
}
int ChuyenXeNoiThanh::getSoNgayDi()
{
	return so_ngay_di;
}
long long ChuyenXeNoiThanh::getDoanhThuNoiThanh()
{
	return TongDoanhThuNoiThanh;
}
long long Chuyen_Xe::getDoanhThu()
{
	return doanh_thu;
}
void ChuyenXeNoiThanh::Nhap()
{
	Chuyen_Xe::Nhap();
	cout << "Nhap noi den: ";
	cin >> noi_den;
	cout << "Nhap so ngay di: ";
	cin >> so_ngay_di;
	while (cin.fail() || so_ngay_di < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so ngay di: ";
		cin >> so_ngay_di;
	}
	TongDoanhThuNoiThanh += getDoanhThu();
}
void ChuyenXeNoiThanh::Xuat() const
{
	Chuyen_Xe::Xuat();
	cout << "Noi den: " << noi_den;
	cout << "So ngay di: " << so_ngay_di;
}
istream& operator>>(istream& is, ChuyenXeNoiThanh& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const ChuyenXeNoiThanh& x)
{
	x.Xuat();
	return os;
}