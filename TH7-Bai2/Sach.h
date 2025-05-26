#pragma once
#include <iostream>
#include <string>
#include "NgayThangNam.h"
using namespace std;
class Sach
{
protected:
	string ma_sach;
	NgayThangNam ngay_nhap;
	int so_luong;
	long long don_gia;
	string nha_xb;
	static long long thanh_tien;
public:
	Sach();
	void Nhap();
	void Xuat() const;
	string getMaSach() const;
	NgayThangNam getNgayNhap() const;
	int getSoLuong() const;
	static long long TinhThanhTien();
	string getNhaXB() const;
	void setMaSach(string ma_sach);
	void setSoLuong(int so_luong);
	void setNgayNhap(NgayThangNam ngay_nhap);
	void setNhaXB(string nha_xb);
	void setDonGia(long long don_gia);
	friend istream& operator>>(istream&, Sach&);
	friend ostream& operator<<(ostream&, const Sach&);
};
class Sach_GK : public Sach
{
private:
	string tinh_trang;
	static long long thanh_tien_SGK;
public:
	Sach_GK();
	void Nhap();
	void Xuat() const;
	string getTinhTrang();
	static long long getThanhTienSGK();
	bool tim(string NXB);
	void setTinhTrang(string tinh_trang);
	friend istream& operator >>(istream&, Sach_GK&);
	friend ostream& operator<<(ostream&, const Sach_GK&);
};
class Sach_TK : public Sach
{
private:
	double thue;
	static long long don_gia_STK;
	static int dem;
	static long long thanh_tien_STK;
public:
	Sach_TK();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, Sach_TK&);
	friend ostream& operator<<(ostream&, const Sach_TK&);
	static double tinh_TBC();
	double getThue();
	static long long getThanhTienSTK();
	void setThue(double thue);
};