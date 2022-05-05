#include <iostream>
using namespace std;
class NgayThang {
private:
	int day, month, year;
public:
	NgayThang()
	{
		day = 1; month = 1; year = 1;
	}
	NgayThang(int d, int m, int y)
	{
		if (d < 1) d = 1;
		else if (d > 31) d = 31;

		if (m < 1) m = 1;
		else if (m > 12) m = 12;

		if (y < 0) y = 1;
		day = d;
		month = m;
		year = y;
	}
	int d()
	{
		return day;
	}
	int m()
	{
		return month;
	}
	int y()
	{
		return year;
	}
};
class SinhVien {
private:
	string name, mssv;
	int ngay, thang, nam;
	double DLT = 0, DTH = 0;
public:
	SinhVien()
	{
		mssv = "0";
		name = "Khong co";
		DTH = 0;
		DLT = 0;
		ngay = 1;
		thang = 1;
		nam = 1;
	}
	SinhVien(string MSSV)
	{
		mssv = MSSV;
	}
	SinhVien(string number, string ten, double LT, double TH,int d,int m,int y)
	{
		mssv = number;
		name = ten;
		DTH = TH;
		DLT = LT;
		ngay = d;
		thang = m;
		nam = y;
	}
	SinhVien(string number, string ten, double LT, double TH)
	{
		mssv = number;
		name = ten;
		DTH = TH;
		DLT = LT;
	}
	SinhVien(string number, string ten, double LT, double TH, NgayThang ngayThang)
	{
		mssv = number;
		name = ten;
		DTH = TH;
		DLT = LT;
		ngay = ngayThang.d();
		thang = ngayThang.m();
		nam = ngayThang.y();
	}
	void xuat()
	{
		cout << mssv << "," << name << "," << DLT << "," << DTH << "," << ngay << "," << thang << "," << nam;
	}
};
int main()
{
	SinhVien sv1;
	sv1.xuat();
	SinhVien sv2("13630001");
	sv2.xuat();
	SinhVien sv3("1362002", "Nguyen Van A", 7, 8.5);
	sv3.xuat();
	SinhVien sv4("1362002", "Nguyen Van A", 7, 8.5, 12, 3, 1992);
	sv4.xuat();
}