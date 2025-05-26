#include "Sach.h"
using namespace std;

int main()
{
	Sach_GK gk[3];
	Sach_TK tk[3];
	cout << "----Nhap thong tin cac sach giao khoa----" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Nhap thong tin sach giao khoa thu " << i + 1 << ":" << endl;
		cin>>gk[i];
	}
	cout << "----Nhap thong tin cac sach tham khao----" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Nhap thong tin sach tham khao thu " << i + 1 << ":" << endl;
		cin >> tk[i];
	}
	cout << "=====Thong tin cac sach giao khoa=====" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Thong tin sach tham khao thu " << i + 1 << ":" << endl;
		cout << gk[i];
		cout << "--------------------------------------" << endl;
	}
	cout << "=====Thong tin cac sach tham khao=====" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Thong tin sach tham khao thu " << i + 1 << ":" << endl;
		cout << tk[i];
		cout << "--------------------------------------" << endl;
	}
	cout << "TONG THANH TIEN SACH GIAO KHOA: " << Sach_GK::getThanhTienSGK()<<endl;
	cout << "TONG THANH TIEN SACH THAM KHAO: " << Sach_TK::getThanhTienSTK() << endl;
	cout << "TRUNG BINH CONG CAC DON GIA SACH THAM KHAO: " << Sach_TK::tinh_TBC() << endl;
	cout << "-----TIM SACH GIAO KHOA------" << endl;
	cout << "Nhap nha xuat ban can tim: ";
	string s;
	cin.ignore();
	getline(cin, s);
	bool found = false;
	for (int i = 0; i < 3; i++)
	{
		if (gk[i].tim(s))
		{
			cout << gk[i];
			found = true;
		}
	}
	if (!found) cout << "Khong tim thay!";
}