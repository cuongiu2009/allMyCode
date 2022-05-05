#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
#include <cstdlib>

using namespace std;

class SoNguyen
{
private:
    int v;
public:
    SoNguyen();
    SoNguyen(const int&);

    int getValue() const;

    SoNguyen operator+(const SoNguyen&) const;

    bool operator<(const SoNguyen&) const;
    bool operator>(const SoNguyen&) const;

    friend ostream& operator<<(ostream&, const SoNguyen&);
    friend istream& operator>>(istream&, SoNguyen&);
};

SoNguyen::SoNguyen() : v(0) {}

SoNguyen::SoNguyen(const int& val) : v(val) {}

int SoNguyen::getValue() const
{
    return v;
}

SoNguyen SoNguyen::operator+(const SoNguyen& other) const
{
    SoNguyen kq;
    kq.v = v + other.v;
    return kq;
}

bool SoNguyen::operator<(const SoNguyen& other) const
{
    return this->v < other.v;
}

bool SoNguyen::operator>(const SoNguyen& other) const
{
    return this->v > other.v;
}

ostream& operator<<(ostream& os, const SoNguyen& sn)
{
    os << sn.v;
    return os;
}

istream& operator>>(istream& is, SoNguyen& sn)
{
    is >> sn.v;
    return is;
}

vector<SoNguyen> taoMang()
{
    SoNguyen n;

    do
    {
        cout << "n = ";
        cin >> n;
    } while (n.getValue() < 1 || n.getValue() > 50);

    vector<SoNguyen> a(n.getValue());

    for (SoNguyen i = 0; i < n; i = i + 1)
        a[i.getValue()] = rand() % 1000;

    return a;
}

void inMang(const vector<SoNguyen>& a)
{
    for (SoNguyen i = 0; i < a.size(); i = i + 1)
        cout << a[i.getValue()] << " ";
    cout << endl;
}

SoNguyen timMin(const vector<SoNguyen>& a)
{
    SoNguyen minValue = INT_MAX;

    for (SoNguyen i = 0; i < a.size(); i = i + 1)
    {
        if (a[i.getValue()] < minValue)
            minValue = a[i.getValue()];
    }

    return minValue;
}

int main()
{
    srand(time(NULL));
    vector<SoNguyen> a = taoMang();
    inMang(a);
    cout << "min = " << timMin(a) << endl;

    return 0;
}