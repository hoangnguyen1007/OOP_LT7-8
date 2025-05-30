#pragma once
#include <iostream>
#include <string>
#include "NgayThangNam.h"
using namespace std;
class NhanVien
{
protected:
	string ho_ten;
	NgayThangNam ngay_sinh;
	long long luong = 0;
	static long long tong_luong;
public:
	virtual ~NhanVien();
	NhanVien();
	NhanVien(string, NgayThangNam);
	virtual void Nhap();
	virtual void Xuat() const;
	string getHoTen() const;
	NgayThangNam getNgaySinh() const;
	long long getLuong() const;
	static long long getTongLuong();
	virtual string getLoai() const = 0;
};
class nvVanPhong : public NhanVien
{
private:
	long long luong_can_ban;
	int so_san_pham;
public:
	nvVanPhong();
	nvVanPhong(long long, int);
	void Nhap();
	void Xuat() const;
	long long getLuongCanBan() const;
	int getSoSanPham() const;
	string getLoai() const;
};
class nvSanXuat : public NhanVien
{
private:
	int so_ngay_lam_viec;
public:
	nvSanXuat();
	nvSanXuat(int);
	void Nhap();
	void Xuat() const;
	int getSoNgayLamViec() const;
	string getLoai() const;
};

class CongTy
{
private:
	NhanVien** ct;
	int sl;
	static int so_NVVP;
	static int so_NVSX;
public:
	CongTy();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, CongTy&);
	friend ostream& operator<<(ostream&, const CongTy&);
	NhanVien* nvSX_luong_min();
	NhanVien* nvVP_tuoi_max();
	static int getSoNVVP();
	static int getSoNVSX();
};
