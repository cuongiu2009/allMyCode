//#include<iostream>
//#include<fstream>
//#include<string.h>
//#include<string>
//using namespace std;
//
//struct hoaDon {
//	int MaDT, GiaTien;
//	string DATE;
//
//};
//void DisplayPhone(string date) {
//	ifstream f;
//
//	f.open("phones.txt", ios::in);
//	string s;
//	getline(f, s);
//
//	hoaDon pay[8];
//
//	int i = 0;
//	while (!f.eof())
//	{
//		f >> pay[i].MaDT;
//		f >> pay[i].GiaTien;
//		f >> pay[i].DATE;
//		i++;
//	}
//
//	for (int n = 0; n < i; n++)
//	{
//		for (int m = 0; m < i; m++)
//		{
//			if (pay[n].GiaTien > pay[m].GiaTien)
//			{
//				swap(pay[n].GiaTien, pay[m].GiaTien);
//				swap(pay[n].MaDT, pay[m].MaDT);
//				swap(pay[n].DATE, pay[m].DATE);
//			}
//		}
//	}
//	cout << s << endl;
//	for (int k = 0; k < i; k++)
//	{
//		if (pay[k].DATE == date)
//		{
//			cout << pay[k].MaDT << " " << pay[k].GiaTien << " " << pay[k].DATE << endl;
//		}
//	}
//
//}
//int main() {
//	DisplayPhone("08/03/2021");
//	return 0;
//}