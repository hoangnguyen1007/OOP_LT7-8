#include "Chuyen_Xe.h"

int main()
{
	ChuyenXeNgoaiThanh ng1, ng2;
	ChuyenXeNoiThanh n1, n2;
	cout << "Nhap chuyen xe ngoai thanh thu nhat: " << endl;
	cin >> ng1;
	cout << "Nhap chuyen xe ngoai thanh thu hai: " << endl;
	cin >> ng2;
	cout << "Nhap chuyen xe noi thanh thu nhat: " << endl;
	cin >> n1;
	cout << "Nhap chuyen xe noi thanh thu hai: " << endl;
	cin >> n2;
	cout << "=====================================" << endl;
	cout << "---------------Chuyen xe ngoai thanh:------------------" << endl;
	cout << ng1;
	cout << "-------------------------------------------" << endl;
	cout<< ng2;
	cout << "-Tong doanh thu xe ngoai thanh: " << ChuyenXeNgoaiThanh::getDoanhThuNgoaiThanh() << endl;
	cout << "---------------Chuyen xe noi thanh:------------------" << endl;
	cout << n1;
	cout << "-------------------------------------------" << endl;
	cout << n2;
	cout << "-Tong doanh thu xe noi thanh la: " << ChuyenXeNoiThanh::getDoanhThuNoiThanh() << endl;
	cout << "-Tong doanh thu cac chuyen trong va ngoai thanh la: " << Chuyen_Xe::TongDoanhThu();
}