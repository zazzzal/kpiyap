#include <iostream>
#include <string>

using namespace std;

class Detail
{	
private:
		int mass;
public:
		int id;
		string name;
		Detail(int a, string s)
		{
			id = a;
			name = s;
		}
		friend class Control;
	    void Print()
		{
			cout << "id: " << id << " Name: " << name << " weigth: " << mass << endl;
		}
};

class Control
{
public:
	void setmass(Detail& Detail, int a)
	{
		Detail.mass = a;
	}
};

int main()
{
	int n = 0;
	Control a;
	Detail first(111, "Pan");
	cout << "Enter weight of " << first.name << " (id : " << first.id << ") : ";
	cin >> n;
	a.setmass(first, n);
	cout << endl;
	Detail second(123, "Pot");
	cout << "Enter weight of " << second.name << " (id : " << second.id<<") : ";
	cin >> n;
	a.setmass(second, n);
	cout << endl;
	first.Print();
	second.Print();
}