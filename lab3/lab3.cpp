#include <iostream>
#include <string>

using namespace std;

class Books
{
protected:
	int	century;
public:
	Books(){
	}
	Books(int _century)
	{
		century = _century;
	}
	~Books(){
	}
};

class TwentyOne : public virtual Books
{
protected:
	string genre;
public:
	TwentyOne() {
	}
	TwentyOne(string _genre, int _century)
	{
		genre = _genre;
		century = _century;
	}
	~TwentyOne(){
	}
};


class Horror : public TwentyOne
{
protected:
	int counter;
public:
	Horror() {
	}
	Horror(int _counter, int _century, string _genre)
	{
		counter = _counter;
		century = _century;
		genre = _genre;
	}
	~Horror() {
	}
};

class Twenty : public virtual Books
{
protected:
	string name;
public:
	Twenty() {
	}
	Twenty(string _name, int _century) 
	{
		name = _name;
		century = _century;
	}
	~Twenty() {
	}
};

class Classic : public Twenty
{
protected:
	int year;
public:
	Classic() {
	}
	Classic(string _name, int _century, int _year)
	{
		year = _year;
		name = _name;
		century = _century;
	}
	~Classic() {
	}
};

class AnyBook : public Classic, public Horror
{
protected:
	int age;
public:
	AnyBook(string _name, int _century, int _year, int _counter, string _genre, int _age)
	{
		century = _century;
		year = _year;
		genre = _genre;
		age = _age;
		name = _name;
		counter = _counter;
	}
	~AnyBook() {
	}
	void ShowAnyBook()
	{
		cout << "Century: " << century << endl;
		cout << "Year: " << year << endl;
		cout << "Genre: " << genre << endl;
		cout << "Name: " << name << endl;
		cout << "Counter: " << counter << endl;
		cout << "Age of readers: " << age << endl;

	}
};

int main()
{
	AnyBook a("Qwerty", 21, 2016, 80000, "Classic", 18);
	a.ShowAnyBook();
}

