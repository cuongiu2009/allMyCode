#include <iostream>
using namespace std;
class ThoiGian {
private:
	int hour, min, second;
public:
	ThoiGian()
	{
		hour = 0; min = 0; second = 0;
	}
	ThoiGian(int sec)
	{
		int phut = 0, gio = 0, k;
		for (k = 0; sec > 0; k++)
		{
			if (k >= 60)
			{
				k = 0;
				phut++;
			}
			else if (phut >= 60)
			{
				phut = 1;
				gio++;
			}
			sec--;
		}
		second = k;
		min = phut;
		hour = gio;
	}
	ThoiGian(int m, int sec)
	{
		int newSec = m * 60 + sec;
		int gio = 0, phut = 0, giay = newSec;
		for (int i = 1; newSec != 0; i++)
		{
			if (i >= 60)
			{
				phut++;
				i = 1;
			}
			else if (phut >= 60)
			{
				phut = 0;
				gio++;
				i = 1;
			}
			newSec--;
		}
		if (sec == 60)
		{
			second = 0;
			min = phut + 1;
			hour = gio;
		}
		else {
			second = sec;
			min = phut;
			hour = gio;
		}
	}
	ThoiGian(int h, int m, int sec)
	{
		int gio = 0, phut = 0, giay = sec;
		for (phut; phut < m; phut++)
		{
			if (phut >= 60)
			{
				gio++;
				m = m - phut;
				phut = 0;
			}
		}
		hour = gio;
		min = phut;
		second = sec;
	}
	ThoiGian operator+(const ThoiGian&);
	ThoiGian operator+(const int&);
	void Xuat()
	{
		cout << hour << ":" << min << ":" << second << endl;
	}
};
ThoiGian ThoiGian::operator+(const ThoiGian& t)
{
	ThoiGian res = *this;
	res.hour += t.hour;
	res.hour += (res.min + t.min) / 60;
	res.hour += (res.second + t.second) / 3600;
	res.hour %= 24;

	res.min += t.min;
	res.min = (res.second + t.second) / 60;
	res.min %= 60;

	res.second += t.second;
	res.second %= 60;
	return res;
}
ThoiGian ThoiGian::operator+(const int& giay)
{
	ThoiGian t(giay);
}
int main()
{
	ThoiGian tg1;
	tg1.Xuat();
	ThoiGian tg2(1212);
	tg2.Xuat();
	ThoiGian tg3(125, 45);
	tg3.Xuat();
	ThoiGian tg4(12, 239, -78);
	tg4.Xuat();
}