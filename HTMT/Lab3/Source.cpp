//#include <iostream>
//#include <cmath>
//using namespace std;
//
//class HocSinh
//{
//public:
//	HocSinh();
//	void DatHoTen(string name)
//	{
//		HoTen = name;
//	}
//	void GanDiem(double a, double b, double c)
//	{
//		Toan = abs(a);
//		Van = abs(b);
//		Anh = abs(c);
//		DTB = (abs(a) * 1.0 + abs(b) * 1.0 + abs(c) * 1.0) / 3;
//		if (sHSDiemTBCaoNhat.DTB < DTB)
//		{
//			sHSDiemTBCaoNhat = *this;
//		}
//	}
//	HocSinh(string name, double a, double b, double c);
//	friend ostream& operator<<(ostream& os, const HocSinh& as);
//	static HocSinh HSDiemTBCaoNhat();
//	~HocSinh();
//
//private:
//	string HoTen;
//	double Toan, Van, Anh, DTB;
//	static int MSSV;
//	int MSSV1;
//	static HocSinh sHSDiemTBCaoNhat;
//};
//HocSinh HocSinh::HSDiemTBCaoNhat()
//{
//	return sHSDiemTBCaoNhat;
//}
//HocSinh::HocSinh()
//{
//	HoTen = "";
//	Toan = Van = Anh = 0;
//	MSSV++;
//	MSSV1 = MSSV;
//}
//HocSinh::HocSinh(string name, double a, double b, double c)
//{
//
//	HoTen = name;
//	Toan = abs(a);
//	Van = abs(b);
//	Anh = abs(c);
//	DTB = (abs(a) * 1.0 + abs(b) * 1.0 + abs(c) * 1.0) / 3;
//	MSSV++;
//	MSSV1 = MSSV;
//	if (sHSDiemTBCaoNhat.DTB < DTB)
//	{
//		sHSDiemTBCaoNhat = *this;
//	}
//}
//HocSinh::~HocSinh()
//{
//}
//ostream& operator<<(ostream& os, const HocSinh& as)
//{
//	os << "HS: " << as.HoTen << ", " << as.MSSV1 << ", " << as.DTB << endl;
//	return os;
//}
//int HocSinh::MSSV = 1363000;
//HocSinh HocSinh::sHSDiemTBCaoNhat = HocSinh();
//int main() {
//	HocSinh hs1;
//	hs1.DatHoTen("Nguyen Van A");
//	hs1.GanDiem(7, 8, 10);
//	HocSinh hs2("Tran Thi B", 5, 8, 4.5);
//	HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
//	HocSinh hs4("Le Van D", 7.5, 9, -10);
//	cout << hs1 << endl << hs2 << endl << hs3 << endl << hs4 << endl << endl;
//	cout << "Hoc sinh co diem TB cao nhat: " << endl;
//	cout << HocSinh::HSDiemTBCaoNhat() << endl;;
//}