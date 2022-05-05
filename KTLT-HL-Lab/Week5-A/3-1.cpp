#include <iostream>
using namespace std;
struct fraction {
	int tu = 0, mau = 1;
};
void input(fraction *fr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "nhap tu:";
		cin >> fr[i].tu;
		cout << "nhap mau:";
		cin >> fr[i].mau;
	}
}
void output(fraction *fr, int n) {
	for (int i = 0; i < n; i++) {
		cout << fr[i].tu << "/" << fr[i].mau << endl;
	}
}
int numberOfNeg(fraction* fr, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (fr[i].tu < 0 || fr[i].mau < 0)
			count++;
	}
	return count;
}

int numberOfPos(fraction* fr, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if ((fr[i].tu > 0 && fr[i].mau > 0) || (fr[i].tu < 0 && fr[i].mau < 0))
			count++;
	}
	return count;
}

fraction * NegArr(fraction* fr, int n, int&k) {
	k = numberOfNeg(fr, n);
	fraction* neg = new fraction[k];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (fr[i].tu < 0 || fr[i].mau < 0) {
			neg[index] = fr[i];
			index++;
		}
	}
	return neg;
}
float sumPos(fraction* fr, int k) {
	float sum = 0;
	for (int i = 0; i < k; i++) {
		sum += (1.0 * fr[i].tu / fr[i].mau);
	}
	return sum;
}
fraction* PosArr(fraction* fr, int n,int &k) {
	k = numberOfPos(fr, n);
	fraction* pos = new fraction[numberOfPos(fr, n)];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if ((fr[i].tu > 0 && fr[i].mau > 0) || (fr[i].tu < 0 && fr[i].mau < 0)) {
			pos[index] = fr[i];
			index++;
		}
	}
	return pos;
}
int main() {
	fraction *fr = new fraction[3];
	int k = 0, m = 0;
	input(fr, 3);
	fraction* negArr = NegArr(fr, 3, k);
	output(negArr, k);
	fraction* posArr = PosArr(fr, 3, m);
	cout << sumPos(posArr, m);
	return 0;
}