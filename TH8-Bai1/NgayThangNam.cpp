#include "NgayThangNam.h"
#include<iostream>
using namespace std;
//Ham nhan vao so nguyen nam, tinh toan xem nam do co phai nam nhuan khong
bool NamNhuan(int nam)
{
	if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) return 1;
	return 0;
}
int NgayThangNam::getNam() const
{
	return iNam;
}
//Ham nhan vao so nguyen thang va nam, tra ve so ngay co trong thang nam do
int NgayThangNam::SoNgayTrongThang(int iThang, int iNam)
{
	switch (iThang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (NamNhuan(iNam)) return 29;
		else return 28;
		break;
	default:
		return -1;
	}
}
//Ham nhap va kiem tra dieu kien nhap
void NgayThangNam::Nhap()
{
	cout << "Nhap ngay thang nam: ";
    cin >> iNgay >> iThang >> iNam;
	while (cin.fail() || iNgay < 0 || iNgay > 31 || iThang < 0 || iThang > 12 || iNam < 0 || iNgay > SoNgayTrongThang(iThang, iNam))
	{
		cin.clear();
		cin.ignore();
		cout << "Nhap ngay thang nam: ";
		cin >> iNgay >> iThang >> iNam;
	}
}
//Ham xuat ngay thang nam
void NgayThangNam::Xuat() const
{
	if (iNgay < 10) cout << 0;
	cout << iNgay << "/";
	if (iThang < 10) cout << 0;
	cout << iThang << "/" << iNam;
}
//Ham tinh toan ngay tiep theo dung chuan logic
void NgayThangNam::NgayTiepTheo()
{
	this->iNgay++;
	if (this->iNgay > SoNgayTrongThang(this->iThang, this->iNam))
	{
		this->iNgay = 1;
		this->iThang++;
		if (this->iThang > 12)
		{
			this->iThang = 1;
			this->iNam++;
		}
	}
}