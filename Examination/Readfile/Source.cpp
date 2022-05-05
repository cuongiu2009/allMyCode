//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//using namespace std;
//struct Data
//{
//	string student;
//	double toan, van;
//};
//void docFile(ifstream& f)
//{
//	f.open("text.txt", ios::in);
//	string s, so1, so2, so3, ten;
//	getline(f, s);
//	while (!f.eof())
//	{
//		f >> ten;
//		f >> so1;
//		f >> so2;
//		f >> so3;
//	}
//	f.close();
//	cout << ten << endl;
//	cout << stof(so1) << endl;
//	cout << stof(so2) << endl;
//	cout << stof(so3) << endl;
//}
//int main()
//{
//	ifstream f;
//	f.open("text.txt", ios::in);
//	string s;
//	getline(f, s);
//	Data hs[10];
//	int i = 0;
//	while (!f.eof())
//	{
//		getline(f, hs[i].student,';');
//		f >> hs[i].toan;
//		getline(f, s, ';');
//		f >> hs[i].van;
//		i++;
//	}
//	f.close();
//	ofstream ff;
//	ff.open("data.txt", ios::out);
//	int m = 0;
//	for (m = 0; m < i; m++)
//	{
//		ff << hs[m].student << endl;
//		ff << hs[m].toan + hs[m].van;
//	}
//	ff.close();
//	return 0;
//}
