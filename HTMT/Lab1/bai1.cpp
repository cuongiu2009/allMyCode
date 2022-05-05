#include <iostream>
using namespace std;
class Ngay {
private:
	int ngay, thang, nam;
public:
	Ngay()
	{
		ngay = 1; nam = 1; thang = 1;
	}
	Ngay(int day, int month, int year)
	{
		if (day <= 0 or month > 12 or year <= 0)
		{
			ngay = 1;
			thang = 1;
			nam = 1;
		}
		else {
			ngay = day;
			thang = month;
			nam = year;
		}
	}
	Ngay(int day)
	{
		int month = 1, year = 1, k = 1;
		for (k = 1; k <= day; k++)
		{
			if (month % 2 == 1 and k > 31)
			{
				k = 1;
				month++;
			}
			else if (month == 2 and k > 28)
			{
				month++;
				k = 1;
			}
			else if (month % 2 == 0 and k > 30)
			{
				k = 1;
				month++;
			}
			else if ((year % 4 == 0 || year % 100 == 0) and month == 2 and k > 29)
			{
				k = 1;
				month++;
			}
			else if ((month == 7 or month == 8) and k > 31)
			{
				k = 1;
				month++;
			}
			else if (month > 12)
			{
				k = 1;
				month = 1;
				year++;
			}
			day--;
		}
		ngay = k;
		thang = month;
		nam = year;
	}

	void xuat() {
		cout << ngay << "/" << thang << "/" << nam << endl;
	}
};
int main()
{
	Ngay n1;
	n1.xuat();
	Ngay n2(02, 10, 2014);
	n2.xuat();
	Ngay n3(-10, 16, 2000);
	n3.xuat();
	Ngay n4(1000);
	n4.xuat();
}