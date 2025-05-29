#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class NhanVien
{
protected:
	string msnv, ho_ten, phong_ban;
public:
	virtual ~NhanVien();
	NhanVien();
	NhanVien(string, string, string);
	virtual void Nhap();
	virtual void Xuat() const;
	friend istream& operator>>(istream&, NhanVien&);
	friend ostream& operator<<(ostream&, const NhanVien&);
	string getMSNV();
	string getHoTen();
	string getPhongBan();
	virtual string getLoai() const = 0;
	virtual long long tinhTienLuong() const = 0;
};

class nvBienChe : public NhanVien
{
private:
	double he_so_luong, he_so_phu_cap;
public:
	nvBienChe();
	nvBienChe(double, double);
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, nvBienChe&);
	friend ostream& operator<<(ostream&, const nvBienChe&);
	long long tinhTienLuong() const;
	double getHeSoLuong() const;
	double getHeSoPhuCap() const;
	string getLoai() const;
};

class nvHopDong : public NhanVien
{
private:
	long long tien_cong;
	int so_ngay_cong;
	double he_so_vuot_gio;
public:
	nvHopDong();
	nvHopDong(long long, int, double);
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, nvHopDong&);
	friend ostream& operator<<(ostream&, const nvHopDong&);
	long long getTienCong() const;
	int getSoNgayCong() const;
	double getHeSoVuotGio() const;
	string getLoai() const;
	long long tinhTienLuong() const;
};

class CongTy
{
private:
	vector<NhanVien*> nv;
	static int so_NVBC;
	static int so_NVHD;
public:
	~CongTy();
	CongTy();
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, CongTy&);
	friend ostream& operator<<(ostream&, const CongTy&);
	void ThemNV();
	void NVBC_HSL();
	int SoNvhdCo26NgayCong();
	long long TongLuongPhongKeToan();
	double Luong_TB_NVBC();
	bool NvhdKhongDiLam();
	NhanVien* NvbcHeSoLuongMax();
	void sort_theo_ma_so();
	bool Xoa(string);
	void Tim(string);	
	static int getSoNVBC();
	static int getSoNVHD();
};
