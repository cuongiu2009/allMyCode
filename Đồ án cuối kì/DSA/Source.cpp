#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;
struct expressions {
	string exp;
};
void inputFile(const char* filename, string*& expression, int& n) {
	ifstream data(filename);
	string N;
	bool A = (bool)getline(data, N);
	n = stoi(N);
	expression = new string[n];
	int i = 0;
	while (!data.eof()) {
		getline(data, expression[i]);
		i++;
	}
	data.close();
}
int prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
string infixToPostfix(string expression) {
	stack<char>st;
	string result;
	char C;
	for (int i = 0; i < expression.length(); ++i) {
		C = expression[i];
		if ((C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z') || (C >= '0' && C <= '9') || (C == '.')) {
			result += C;
		}
		else if (C == '(') {
			st.push('(');
		}
		else if (C == ')') {
			while (!st.empty() && st.top() != '(') {
				char temp = st.top();
				st.pop();
				result += temp;
			}
			st.pop();

		}
		else if (C == ' ') {
			//do nothing
			result += C;
		}
		else {
			while (!st.empty() && prec(expression[i]) <= prec(st.top())) {

				char temp = st.top();
				st.pop();
				result += temp;
			}
			st.push(C);
		}
	}
	while (!st.empty()) {
		char temp = st.top();
		st.pop();
		result += temp;
	}
	return result;
}
void output(const char* filename, string* expression, int n) {
	ofstream fout("output.txt");
	for (int i = 0; i < n; ++i) {
		cout << infixToPostfix(expression[i]) << endl;
	}
	fout.close();
}
int main() {
	int n;
	string* expression = NULL;
	inputFile("input.txt", expression, n);
	output("output.txt", expression, n);
	return 0;
}