#include "Chuyen_Xe.h"
//Gán giá trị mặc định bằng 0 cho biến tĩnh tính tổng doanh thu các chuyến xe
long long Chuyen_Xe::tong_doanh_thu = 0;
//Hàm constructor mặc định của lớp Chuyến xe
Chuyen_Xe::Chuyen_Xe() {
};
//Hàm constructor có truyền tham số của lớp chuyến xe
Chuyen_Xe::Chuyen_Xe(string MS_chuyen, string ho_tenTX, int so_xe, long long doanh_thu)
{
	this->MS_chuyen = MS_chuyen;
	this->ho_ten_tx = ho_tenTX;
	this->so_xe = so_xe;
	this->doanh_thu = doanh_thu;
	tong_doanh_thu += doanh_thu;
}
//Hàm getter trả về mã số chuyến xe
string Chuyen_Xe::getMS()
{
	return MS_chuyen;
}
//Hàm getter trả về họ tên tài xế
string Chuyen_Xe::getHoTenTX()
{
	return ho_ten_tx;
}
//Hàm getter trả về số xe
int Chuyen_Xe::getSoXe()
{
	return so_xe;
}
//Hàm getter trả về tổng doanh thu của các chuyến xe
long long Chuyen_Xe::TongDoanhThu()
{
	return tong_doanh_thu;
}
//Hàm nhập và kiểm tra dữ liệu đầu vào thông tin chung của các chuyến xe
void Chuyen_Xe::Nhap()
{	
	cout << "Nhap ma so chuyen xe: ";
	cin.ignore();
	getline(cin, MS_chuyen);
	cout << "Nhap ho ten tai xe: ";
	getline(cin, ho_ten_tx);
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap ho ten tai xe: ";
		getline(cin, ho_ten_tx);
	}
	cout << "Nhap so xe: ";
	cin >> so_xe;
	while (cin.fail() || so_xe < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so xe: ";
		cin >> so_xe;
	}
	cout << "Nhap doanh thu: ";
	cin >> doanh_thu;
	while (cin.fail() || so_xe < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap doanh thu: ";
		cin >> doanh_thu;
	}
	tong_doanh_thu += doanh_thu;
}
//Hàm xuất thông tin chung của từng chuyến xe
void Chuyen_Xe::Xuat() const
{
	cout << "Ma so chuyen xe: " << MS_chuyen << endl;
	cout << "Ho ten tai xe: " << ho_ten_tx << endl;
	cout << "So xe: " << so_xe << endl;
	cout << "Doanh thu cua xe: " << doanh_thu << endl;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, Chuyen_Xe& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const Chuyen_Xe& x)
{
	x.Xuat();
	return os;
}
//Định nghĩa giá trị ban đầu của tổng doanh thu ngoại thành bằng 0
long long ChuyenXeNgoaiThanh::TongDoanhThuNgoaiThanh = 0;
//Hàm constructor mặc định của lớp chuyến xe ngoại thành
ChuyenXeNgoaiThanh::ChuyenXeNgoaiThanh() {
	so_tuyen = 0;
	so_km = 0;
};
//Hàm constructor có truyền tham số của lớp chuyến xe ngoại thành
ChuyenXeNgoaiThanh::ChuyenXeNgoaiThanh(string MS_chuyen, string ho_tenTX, int so_xe, long long doanh_thu, int so_tuyen, int so_km) : Chuyen_Xe(MS_chuyen, ho_tenTX, so_xe, doanh_thu), so_tuyen(so_tuyen), so_km(so_km)
{
	TongDoanhThuNgoaiThanh += doanh_thu;
}
//Hàm getter trả về số tuyến của chuyến xe ngoại thành
int ChuyenXeNgoaiThanh::getSoTuyen()
{
	return so_tuyen;
}
//Hàm getter trả về số km của chuyến xe ngoại thành
int ChuyenXeNgoaiThanh::getSoKM()
{
	return so_km;
}
//Hàm getter trả về tổng doanh thu của các chuyến xe ngoại thành
long long ChuyenXeNgoaiThanh::getDoanhThuNgoaiThanh()
{
	return TongDoanhThuNgoaiThanh;
}
//Hàm nhập và kiểm tra dữ liệu đầu vào và tính doanh thu của chuyến xe ngoại thành
void ChuyenXeNgoaiThanh::Nhap()
{
	Chuyen_Xe::Nhap();
	cout << "Nhap so tuyen: ";
	cin >> so_tuyen;
	while (cin.fail() || so_tuyen < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so tuyen: ";
		cin >> so_tuyen;
	}
	cout << "Nhap so km: ";
	cin >> so_km;
	while (cin.fail() || so_tuyen < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so km: ";
		cin >> so_km;
	}
	TongDoanhThuNgoaiThanh += getDoanhThu();
}
//Hàm xuất các thông tin chung và riêng của chuyến xe ngoại thành
void ChuyenXeNgoaiThanh::Xuat() const
{
	Chuyen_Xe::Xuat();
	cout << "So tuyen: " << so_tuyen << endl;
	cout << "So km: " << so_km << endl;
}
//Hàm bạn nạp chồng toán tử nhập bằng cách gọi hàm nhập và trả về luồng nhập
istream& operator>>(istream& is, ChuyenXeNgoaiThanh& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất bằng cách gọi hàm xuất và trả về luồng xuất
ostream& operator<<(ostream& os, const ChuyenXeNgoaiThanh& x)
{
	x.Xuat();
	return os;
}
//Đặt giá trị ban đầu của biến tĩnh tổng doanh thu của các chuyến xe nội thành bằng 0
long long ChuyenXeNoiThanh::TongDoanhThuNoiThanh = 0;
//Hàm constructor mặc định của lớp chuyến xe nội thành
ChuyenXeNoiThanh::ChuyenXeNoiThanh() {
	so_ngay_di = 0;
};
//Hàm constructor có truyền tham số và tính luôn doanh thu của lớp chuyến xe nội thành
ChuyenXeNoiThanh::ChuyenXeNoiThanh(string MS_chuyen, string ho_tenTX, int so_xe, long long doanh_thu, string noi_den, int so_ngay_di) : Chuyen_Xe(MS_chuyen, ho_tenTX, so_xe, doanh_thu), noi_den(noi_den), so_ngay_di(so_ngay_di)
{
	TongDoanhThuNoiThanh += doanh_thu;
}
//Hàm getter trả về nơi đến của chuyến xe nội thành
string ChuyenXeNoiThanh::getNoiDen()
{
	return noi_den;
}
//Hàm getter trả về số ngày đi của chuyến xe nội thành
int ChuyenXeNoiThanh::getSoNgayDi()
{
	return so_ngay_di;
}
//Hàm getter trả về tổng doanh thu của các chuyến xe nội thành
long long ChuyenXeNoiThanh::getDoanhThuNoiThanh()
{
	return TongDoanhThuNoiThanh;
}
//Hàm getter trả về doanh thu của từng chuyến xe
long long Chuyen_Xe::getDoanhThu()
{
	return doanh_thu;
}
//Hàm nhập và kiểm tra dữ liệu đầu vào và tính doanh thu của chuyến xe nội thành ấy
void ChuyenXeNoiThanh::Nhap()
{
	Chuyen_Xe::Nhap();
	cout << "Nhap noi den: ";
	cin.ignore();
	getline(cin, noi_den);
	cout << "Nhap so ngay di: ";
	cin >> so_ngay_di;
	while (cin.fail() || so_ngay_di < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so ngay di: ";
		cin >> so_ngay_di;
	}
	TongDoanhThuNoiThanh += getDoanhThu();
}
//Hàm xuất thông tin chung và riêng của chuyến xe nội thành
void ChuyenXeNoiThanh::Xuat() const
{
	Chuyen_Xe::Xuat();
	cout << "Noi den: " << noi_den<<endl;
	cout << "So ngay di: " << so_ngay_di<<endl;
}
//Hàm bạn nạp chồng toán tử nhập và trả về luồng nhập
istream& operator>>(istream& is, ChuyenXeNoiThanh& x)
{
	x.Nhap();
	return is;
}
//Hàm bạn nạp chồng toán tử xuất và trả về luồng xuất 
ostream& operator<<(ostream& os, const ChuyenXeNoiThanh& x)
{
	x.Xuat();
	return os;
}