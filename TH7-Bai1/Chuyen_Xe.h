#pragma once
#include <iostream>
#include <string>
using namespace std;
class Chuyen_Xe
{
private:
	string MS_chuyen, ho_ten_tx;
	int so_xe;
	long long doanh_thu;
	static long long tong_doanh_thu;
public:
	Chuyen_Xe();
	Chuyen_Xe(string, string, int, long long);
	string getMS();
	string getHoTenTX();
	int getSoXe();
	long long getDoanhThu();
	static long long TongDoanhThu();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, Chuyen_Xe&);
	friend ostream& operator<<(ostream&, const Chuyen_Xe&);
};
class ChuyenXeNgoaiThanh : public Chuyen_Xe
{
private:
	int so_tuyen, so_km;
	static long long TongDoanhThuNgoaiThanh;
public:
	ChuyenXeNgoaiThanh();
	ChuyenXeNgoaiThanh(string MS_chuyen, string ho_tenTX, int so_xe, long long doanh_thu, int so_tuyen, int so_km);
	int getSoTuyen();
	int getSoKM();
	static long long getDoanhThuNgoaiThanh();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, ChuyenXeNgoaiThanh&);
	friend ostream& operator<<(ostream&, const ChuyenXeNgoaiThanh&);
};
class ChuyenXeNoiThanh : public Chuyen_Xe
{
private:
	string noi_den;
	int so_ngay_di;
	static long long TongDoanhThuNoiThanh;
public:
	ChuyenXeNoiThanh();
	ChuyenXeNoiThanh(string, string, int, long long, string, int);
	string getNoiDen();
	int getSoNgayDi();
	static long long getDoanhThuNoiThanh();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, ChuyenXeNoiThanh&);
	friend ostream& operator<<(ostream&, const ChuyenXeNoiThanh&);
};
