#include "NhanVien.h"
NhanVien::~NhanVien() {};
NhanVien::NhanVien() {};
NhanVien::NhanVien(string msnv, string ho_ten, string phong_ban) : msnv(msnv), ho_ten(ho_ten), phong_ban(phong_ban) {};
void NhanVien::Nhap()
{
	cout << "Nhap ma so nhan vien: ";
	cin >> msnv;
	cout << "Nhap ho ten nhan vien: ";
	cin.ignore();
	getline(cin, ho_ten);
	cout << "Nhap phong ban: ";
	getline(cin, phong_ban);
}
void NhanVien::Xuat() const
{
	cout << "Ma so nhan vien: " << msnv << endl;
	cout << "Ho ten nhan vien: " << ho_ten << endl;
	cout << "Phong ban: " << phong_ban << endl;
}
istream& operator>>(istream& is, NhanVien& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const NhanVien& x)
{
	x.Xuat();
	return os;
}
string NhanVien::getMSNV()
{
	return msnv;
}
string NhanVien::getHoTen()
{
	return ho_ten;
}
string NhanVien::getPhongBan()
{
	return phong_ban;
}
string nvBienChe::getLoai() const
{
	return "Bien che";
}
nvBienChe::nvBienChe() {};
nvBienChe::nvBienChe(double he_so_luong, double he_so_phu_cap) : he_so_luong(he_so_luong), he_so_phu_cap(he_so_phu_cap) {};
void nvBienChe::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap he so luong: ";
	cin >> he_so_luong;
	while (cin.fail() || he_so_luong < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap he so luong: ";
		cin >> he_so_luong;
	}
	cout << "Nhap he so phu cap: ";
	cin >> he_so_phu_cap;
	while (cin.fail() || he_so_phu_cap < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap he so phu cap: ";
		cin >> he_so_phu_cap;
	}
}
long long nvBienChe::tinhTienLuong() const
{
	return (1 + he_so_luong + he_so_phu_cap) * 1000;
}
void nvBienChe::Xuat() const
{
	NhanVien::Xuat();
	cout << "Tien luong: " << tinhTienLuong()<<endl;
}
istream& operator>>(istream& is, nvBienChe& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const nvBienChe& x)
{
	x.Xuat();
	return os;
}
double nvBienChe::getHeSoLuong() const
{
	return he_so_luong;
}
double nvBienChe::getHeSoPhuCap() const
{
	return he_so_phu_cap;
}
string nvHopDong::getLoai() const
{
	return "Hop dong";
}
nvHopDong::nvHopDong() {};
nvHopDong::nvHopDong(long long tien_cong, int so_ngay_cong, double he_so_vuot_gio) : tien_cong(tien_cong), so_ngay_cong(so_ngay_cong), he_so_vuot_gio(he_so_vuot_gio) {};
void nvHopDong::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap tien cong: ";
	cin >> tien_cong;
	while (cin.fail() || tien_cong < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap tien cong: ";
		cin >> tien_cong;
	}
	cout << "Nhap so ngay cong: ";
	cin >> so_ngay_cong;
	while (cin.fail() || so_ngay_cong < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so ngay cong: ";
		cin >> so_ngay_cong;
	}
	cout << "Nhap he so vuot gio: ";
	cin >> he_so_vuot_gio;
	while (cin.fail() || he_so_vuot_gio < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap he so vuot gio: ";
		cin >> he_so_vuot_gio;
	}
}
void nvHopDong::Xuat() const
{
	NhanVien::Xuat();
	cout << "Tien luong: " << tinhTienLuong()<<endl;
}
istream& operator>>(istream& is, nvHopDong& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const nvHopDong& x)
{
	x.Xuat();
	return os;
}
long long nvHopDong::getTienCong() const
{
	return tien_cong;
}
int nvHopDong::getSoNgayCong() const
{
	return so_ngay_cong;
}
double nvHopDong::getHeSoVuotGio() const
{
	return he_so_vuot_gio;
}
long long nvHopDong::tinhTienLuong() const
{
	return tien_cong * so_ngay_cong * (1 + he_so_vuot_gio);
}
int CongTy::so_NVBC = 0;
int CongTy::so_NVHD = 0;
CongTy::~CongTy()
{
	for (auto a : nv)
	{
		delete a;
	}
	nv.clear();
}
CongTy::CongTy() {};
void CongTy::Nhap()
{
	cout << "Nhap so nhan vien: ";
	int sl;
	cin >> sl;
	for (int i = 0; i < sl; i++)
	{
		cout << "====Nhap nhan vien thu "<<i + 1 << "====" << endl;
		cout << "Nhap loai nhan vien (1. Bien che/ 2. Hop dong): ";
		int k;
		cin >> k;
		NhanVien* n;
		if (k == 1)
		{
			so_NVBC++;
			n = new nvBienChe;
		}
		else
		{
			so_NVHD++;
			n = new nvHopDong;
		}
		n->Nhap();
		nv.push_back(n);
	}
}
void CongTy::Xuat() const
{
	for (auto a : nv)
	{
		cout << "---------------------------------" << endl;
		a->Xuat();
	}
}
istream& operator>>(istream& is, CongTy& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const CongTy& x)
{
	x.Xuat();
	return os;
}
void CongTy::ThemNV()
{
	cout << "Nhap thong tin nhan vien moi: "<<endl;
	cout << "Nhap loai nhan vien (1. Bien che/ 2. Hop dong):";
	int k;
	cin >> k;
	NhanVien* n;
	if (k == 1)
	{
		n = new nvBienChe;
	}
	else
	{
		n = new nvHopDong;
	}
	n->Nhap();
	nv.push_back(n);
}
void CongTy::NVBC_HSL()
{
	bool found = false;
	for (auto a : nv)
	{
		if (a->getLoai() == "Bien che")
		{
			nvBienChe *bc = (nvBienChe*)a;
			if (bc->getHeSoLuong() >= 3.5)
			{
				found = true;
				cout << "-------------------------------" << endl;
				a->Xuat();
			}
		}
	}
	if (!found) cout << "Khong nhan vien bien che nao co he so luong tren 3.5" << endl;
}
int CongTy::SoNvhdCo26NgayCong()
{
	int dem = 0;
	for (auto a : nv)
	{
		if (a->getLoai() == "Hop dong")
		{
			nvHopDong* hd = (nvHopDong*)a;
			if (hd->getSoNgayCong() == 26)
			{
				dem++;
			}
		}
	}
	return dem;
}
long long CongTy::TongLuongPhongKeToan()
{
	long long res = 0;
	for (auto a : nv)
	{
		if (a->getPhongBan() == "Ke toan")
		{
			res += a->tinhTienLuong();
		}
	}
	return res;
}
double CongTy::Luong_TB_NVBC()
{
	long long sum = 0;
	int dem = 0;
	for (auto a : nv)
	{
		if (a->getLoai() == "Bien che")
		{
			sum += a->tinhTienLuong();
			dem++;
		}
	}
	return (dem == 0) ? 0 : sum / dem;
}
bool CongTy::NvhdKhongDiLam()
{
	for (auto a : nv)
	{
		if (a->getLoai() == "Hop dong")
		{
			nvHopDong* hd = (nvHopDong*)a;
			if (hd->getSoNgayCong() == 0) return 1;
		}
	}
	return 0;
}
NhanVien* CongTy::NvbcHeSoLuongMax()
{
	double maxhsl = 0;
	for (auto a : nv)
	{
		if (a->getLoai() == "Bien che")
		{
			nvBienChe* bc = (nvBienChe*)a;
			maxhsl = max(maxhsl, bc->getHeSoLuong());
		}
	}
	for (auto a : nv)
	{
		if (a->getLoai() == "Bien che")
		{
			nvBienChe* bc = (nvBienChe*)a;
			if (bc->getHeSoLuong() == maxhsl) return bc;
		}
	}
}
bool cmp(NhanVien* a, NhanVien* b)
{
	return a->getMSNV() < b->getMSNV();
}
void CongTy::sort_theo_ma_so()
{
	sort(nv.begin(), nv.end(), cmp);
}
bool check_str(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i])) return 0;
	}
	return 1;
}
bool CongTy::Xoa(string s)
{
	bool found = false;
	for (auto it = nv.begin(); it != nv.end(); ++it)
	{
		if ((*it)->getMSNV() == s)
		{
			delete* it;       
			nv.erase(it);               
			return 1;
		}
	}
	return 0;
}
void CongTy::Tim(string s)
{
	bool found = false;
	for (auto a : nv)
	{
		if (a->getMSNV() == s)
		{
			cout << "---------------------------------" << endl;
			a->Xuat();
			found = true;
			continue;
		}
		if (a->getHoTen() == s)
		{
			cout << "---------------------------------" << endl;
			a->Xuat();
			found = true;
			continue;
		}
		if (a->getPhongBan() == s)
		{
			cout << "---------------------------------" << endl;
			a->Xuat();
			found = true;
			continue;
		}
		if (check_str(s))
		{
			if (stoll(s) == a->tinhTienLuong())
			{
				cout << "---------------------------------" << endl;
				a->Xuat();
				found = true;
				continue;
			}
		}
	}
	if (!found) cout << "Khong tim thay!" << endl;
}
int CongTy::getSoNVBC()
{
	return so_NVBC;
}
int CongTy::getSoNVHD()
{
	return so_NVHD;
}