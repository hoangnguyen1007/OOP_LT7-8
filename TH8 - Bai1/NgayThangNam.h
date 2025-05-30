#pragma once
#include<iostream>
using namespace std;
class NgayThangNam 
{
private:
	int iNgay, iThang, iNam;
public:
	void Nhap();
	void Xuat() const;
	void NgayTiepTheo();
	int SoNgayTrongThang(int thang, int nam); 
	int getNam() const;
};
bool NamNhuan(int nam);