#pragma once
#include <iostream>
#include <string>
using namespace std;
class SinhVien
{
protected:
	string mssv, ho_ten, dia_chi;
	int tong_so_tin_chi;
	double diem_trung_binh;
public:
	virtual ~SinhVien();
	SinhVien();
	SinhVien(string, string, string, int, double);
	virtual void Nhap();
	virtual void Xuat() const;
	virtual string getLoai() const = 0;
	virtual bool totNghiep() = 0;
	double getDTB() const;
	string getMSSV() const;
	string getDiaChi() const;
	string getHoTen() const;
	int getTSTC() const;
};
class svCaoDang : public SinhVien
{
private:
	double diem_thi_tot_nghiep;
public:
	svCaoDang();
	svCaoDang(double);
	double getDiemTN() const;
	void Nhap();
	void Xuat() const;
	string getLoai() const;
	bool totNghiep();
};
class svDaiHoc : public SinhVien
{
private:
	string ten_luan_van;
	double diem_luan_van;
public:
	svDaiHoc();
	svDaiHoc(string, double);
	string getTenLuanVan();
	double geDiemLuanVan();
	void Nhap();
	void Xuat() const;
	string getLoai() const;
	bool totNghiep();
};
class DaiHoc
{
private:
	SinhVien** sv;
	int sl;
	static int so_SVDH;
	static int so_SVCD;
public:
	~DaiHoc();
	DaiHoc();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, DaiHoc&);
	friend ostream& operator<<(ostream&, const DaiHoc&);
	static int getSoSVDH();
	static int getSoSVCD();
	void dsSVDuDieuKienTN() const;
	void dsSVKhongDuDieuKienTN() const;
	SinhVien* svDH_DTB_max() const;
	SinhVien* svCD_DTB_max() const;
	int so_SVDH_khong_TN() const;
	int so_SVCD_khong_TN() const;
};