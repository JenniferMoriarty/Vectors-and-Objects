#include<iostream>
#include<Windows.h>
#include<vector> //don't forget the library!
using namespace std;

class baby {
private:
	string name;
	bool DirtyDiaper;
	float age;
	char gender;
	int hunger;
public:
	baby();
	baby(string n);
	void changeDiaper();
	void feed();
	void printInfo();
};

//---------------------------------------------------------------------------------------------------------
int main() {

	vector<baby*> nursery;		//a vector of baby POINTERS		 
	vector<baby*>::iterator iter;

	//instantiate one baby, default constructor
	baby b1 = baby();
	//push baby into nursery
	nursery.push_back(&b1);

	//instantiate another baby, parameterized constructor
	baby b2 = baby("Mossy");
	nursery.push_back(&b2);

	//print the babies
	for (iter = nursery.begin(); iter != nursery.end(); ++iter)
		(*iter)->printInfo();

	system("pause");

	//instantiate ALL THE BABIES
	for (int i = 0; i < 20; i++) {
		baby* b3 = new baby();//default constructor
		nursery.push_back(b3);
	}

	//EVEN MORE BABIES!!!
	for (int i = 0; i <5; i++) {
		baby* b4 = new baby("kyle");//paramaterized constructor
		nursery.push_back(b4);
	}

	for (iter = nursery.begin(); iter != nursery.end(); ++iter)
		(*iter)->printInfo(); //in a graphical program this could draw instead

	//if you're done with your objects before the program ends, you should deallocate the memory using "del"

}//end of main!-------------------------------------------------------------------------------------------------

//default constructor
baby::baby() {
	name = "Simon";
	DirtyDiaper = false;
	age = 0;
}

//paramaterized constructor 
baby::baby(string n) {
	name = n;
	age = 0;
	DirtyDiaper = false;
}

void baby::printInfo() {
	cout << "I'm a baby and my name is " << name << endl;
	cout << "I am " << age << " months old and my diaper is ";
	if (!DirtyDiaper) cout << " full." << endl;
	else cout << " empty." << endl;
}
