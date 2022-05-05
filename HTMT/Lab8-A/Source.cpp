#include <iostream>
using namespace std;
class Mammal {
protected:
	int itsAge;
public:
	Mammal() :itsAge(1) {
		cout << "Mammal constructor..." << endl;
	}
	virtual~Mammal() {
		cout << "Mammal destructor..." << endl;
	}
	virtual void move() {
		cout << "Mammal moves a step!" << endl;
	}
	virtual void speak() {
		cout << "What does a mammal speak? Mammilian!" << endl;
	}
};
class Dog :public Mammal {
public:
	Dog(){
		cout << "Dog constructor..." << endl;
	}
	~Dog() {
		cout << "Dog destructor..." << endl;
	}
	void speak() {
		cout << "What does a dog say? Woof!" << endl;
	}
};
class Cat :public Mammal {
public:
	Cat() {
		cout << "Cat constructor..." << endl;
	}
	~Cat() {
		cout << "Cat destructor..." << endl;
	}
	void speak() {
		cout << "What does a cat say? Meow!" << endl;
	}
};
class Horse :public Mammal {
public:
	Horse() {
		cout << "Horse constructor..." << endl;
	}
	~Horse() {
		cout << "Horse destructor..." << endl;
	}
	void speak() {
		cout << "What does a horse say? Ney!" << endl;
	}
};
class GuineaPig :public Mammal {
public:
	GuineaPig() {
		cout << "Guinea Pig constructor..." << endl;
	}
	~GuineaPig() {
		cout << "Guinea Pig destructor..." << endl;
	}
	void speak() {
		cout << "What does a Guinea Pig say? Wheep WHEEP!" << endl;
	}
};
int main() {
	Mammal* theArray[5];
	Mammal* ptr;
	int choice;
	for (int i = 0; i < 5; i++) {
		cout << "(1)dog (2)cat (3)horse (4)guinea pig:";
		cin >> choice;
		switch (choice) {
		case 1:ptr = new Dog;
			break;
		case 2:ptr = new Cat;
			break;
		case 3:ptr = new Horse;
			break;
		case 4:ptr = new GuineaPig;
			break;
		default:ptr = new Mammal;
			break;
		}
		theArray[i] = ptr;
	}
	for (int i = 0; i < 5; i++) {
		theArray[i]->speak();
	}
	for (int i = 0; i < 5; i++) {
		delete theArray[i];
	}
	return 0;
}