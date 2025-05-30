#include "SinhVien.h"

SinhVien::~SinhVien() {};
SinhVien::SinhVien() {};
SinhVien::SinhVien(string mssv, string ho_ten, string dia_chi, int tong_so_tin_chi, double diem_trung_binh) : mssv(mssv), ho_ten(ho_ten), dia_chi(dia_chi), tong_so_tin_chi(tong_so_tin_chi), diem_trung_binh(diem_trung_binh) {};
void SinhVien::Nhap()
{
	cout << "Nhap ma so sinh vien: ";
	cin >> mssv;
	cout << "Nhap ho ten: ";
	cin.ignore();
	getline(cin, ho_ten);
	cout << "Nhap dia chi: ";
	getline(cin, dia_chi);
	cout << "Nhap tong so tin chi: ";
	cin >> tong_so_tin_chi;
	while (cin.fail() || tong_so_tin_chi < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap tong so tin chi: ";
		cin >> tong_so_tin_chi;
	}
	cout << "Nhap diem trung binh: ";
	cin >> diem_trung_binh;
	while (cin.fail() || diem_trung_binh < 0 || diem_trung_binh > 10)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap diem trung binh: ";
		cin >> diem_trung_binh;
	}
}
void SinhVien::Xuat() const
{
	cout << "Ma so sinh vien: " << mssv << endl;
	cout << "Ho va ten: " << ho_ten << endl;
	cout << "Dia chi: " << dia_chi << endl;
	cout << "Tong so tin chi: " << tong_so_tin_chi << endl;
	cout << "Diem trung binh: " << diem_trung_binh << endl;
}
double SinhVien::getDTB() const
{
	return diem_trung_binh;
}
string SinhVien::getMSSV() const
{
	return mssv;
}
string SinhVien::getDiaChi() const
{
	return dia_chi;
}
string SinhVien::getHoTen() const
{
	return ho_ten;
}
int SinhVien::getTSTC() const
{
	return tong_so_tin_chi;
}
svCaoDang::svCaoDang() {};
svCaoDang::svCaoDang(double diem_thi_tot_nghiep) : diem_thi_tot_nghiep(diem_thi_tot_nghiep) {};
bool svCaoDang::totNghiep()
{
	return tong_so_tin_chi >= 120 && diem_trung_binh > 5 && diem_thi_tot_nghiep > 5;
}
double svCaoDang::getDiemTN() const
{
	return diem_thi_tot_nghiep;
}
void svCaoDang::Nhap()
{
	SinhVien::Nhap();
	cout << "Nhap diem thi tot nghiep: ";
	cin >> diem_thi_tot_nghiep;
}
void svCaoDang::Xuat() const
{
	SinhVien::Xuat();
	cout << "Diem thi tot nghiep: " << diem_thi_tot_nghiep<<endl;
}
string svCaoDang::getLoai() const
{
	return "Cao dang";
}
svDaiHoc::svDaiHoc() {};
svDaiHoc::svDaiHoc(string ten_luan_van, double diem_luan_van) : ten_luan_van(ten_luan_van), diem_luan_van(diem_luan_van) {};
string svDaiHoc::getTenLuanVan()
{
	return ten_luan_van;
}
double svDaiHoc::geDiemLuanVan()
{
	return diem_luan_van;
}
void svDaiHoc::Nhap()
{
	SinhVien::Nhap();
	cout << "Nhap ten luan van: ";
	cin.ignore();
	getline(cin, ten_luan_van);
	cout << "Nhap diem luan van: ";
	cin >> diem_luan_van;
}
void svDaiHoc::Xuat() const
{
	SinhVien::Xuat();
	cout << "Ten luan van: " << ten_luan_van << endl;
	cout << "Diem luan van: " << diem_luan_van << endl;
}
string svDaiHoc::getLoai() const
{
	return "Dai hoc";
}
bool svDaiHoc::totNghiep()
{
	return tong_so_tin_chi >= 170 && diem_trung_binh > 5 && diem_luan_van > 5;
}
int DaiHoc::so_SVCD = 0;
int DaiHoc::so_SVDH = 0;
DaiHoc::~DaiHoc()
{
	for (int i = 0; i < sl; i++)
	{
		delete sv[i];
	}
	delete[] sv;
}
DaiHoc::DaiHoc() {
	sl = 0;
	sv = nullptr;
};
void DaiHoc::Nhap()
{
	cout << "Nhap so luong sinh vien: ";
	cin >> sl;
	while (cin.fail() || sl < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so luong sinh vien: ";
		cin >> sl;
	}
	sv = new SinhVien*[sl];
	for (int i = 0; i < sl; i++)
	{
		cout << "Nhap loai sinh vien (1. Cao dang/ 2. Dai hoc): ";
		int k;
		cin >> k;
		if (k == 1)
		{
			sv[i] = new svCaoDang;
			sv[i]->Nhap();
			so_SVCD++;
		}
		else
		{
			sv[i] = new svDaiHoc;
			sv[i]->Nhap();
			so_SVDH++;
		}
	}
}
void DaiHoc::Xuat() const
{
	for (int i = 0; i < sl; i++)
	{
		cout << "-------------------------------" << endl;
		sv[i]->Xuat();
	}
}
istream& operator>>(istream& is, DaiHoc& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const DaiHoc& x)
{
	x.Xuat();
	return os;
}
int DaiHoc::getSoSVDH()
{
	return so_SVDH;
}
int DaiHoc::getSoSVCD()
{
	return so_SVCD;
}
void DaiHoc::dsSVDuDieuKienTN() const
{
	if (sl == 0)
	{
		cout << "Khong co sinh vien nao trong danh sach!" << endl;
		return;
	}
	bool found = false;
	for (int i = 0; i < sl; i++)
	{
		if (sv[i]->totNghiep())
		{
			found = true;
			cout << "------------------------------------" << endl;
			sv[i]->Xuat();
		}
	}
	if (!found) cout << "Khong co sinh vien nao du dieu kien tot nghiep!" << endl;
}
void DaiHoc::dsSVKhongDuDieuKienTN() const
{
	if (sl == 0)
	{
		cout << "Khong co sinh vien nao trong danh sach!" << endl;
		return;
	}
	bool found = false;
	for (int i = 0; i < sl; i++)
	{
		if (!sv[i]->totNghiep())
		{
			found = true;
			cout << "------------------------------------" << endl;
			sv[i]->Xuat();
		}
	}
	if (!found) cout << "Tat ca sinh vien deu du dieu kien tot nghiep!" << endl;
}
SinhVien* DaiHoc::svDH_DTB_max() const
{
	if (sl == 0 || getSoSVDH() == 0)
	{
		return NULL;
	}
	int max = 0;
	int index = 0;
	for (int i = 0; i < sl; i++)
	{
		if (sv[i]->getLoai() == "Dai hoc" && sv[i]->getDTB() > max)
		{
			index = i;
			max = sv[i]->getDTB();
		}
	}
	return sv[index];
}
SinhVien* DaiHoc::svCD_DTB_max() const
{
	if (sl == 0 || getSoSVCD() == 0)
	{
		return NULL;
	}
	int max = 0;
	int index = 0;
	for (int i = 0; i < sl; i++)
	{
		if (sv[i]->getLoai() == "Cao dang" && sv[i]->getDTB() > max)
		{
			index = i;
			max = sv[i]->getDTB();
		}
	}
	return sv[index];
}
int DaiHoc::so_SVDH_khong_TN() const
{
	int dem = 0;
	for (int i = 0; i < sl; i++)
	{
		if (sv[i]->getLoai() == "Dai hoc" && !sv[i]->totNghiep())
		{
			dem++;
		}
	}
	return dem;
}
int DaiHoc::so_SVCD_khong_TN() const
{
	int dem = 0;
	for (int i = 0; i < sl; i++)
	{
		if (sv[i]->getLoai() == "Cao dang" && !sv[i]->totNghiep())
		{
			dem++;
		}
	}
	return dem;
}