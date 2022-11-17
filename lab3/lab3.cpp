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
	TwentyOne(string _genre, int _century) : Books(_century)
	{
		genre = _genre;
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
	Horror(int _counter, int _century, string _genre) : TwentyOne (_genre, _century)
	{
		counter = _counter;
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
	Twenty(string _name, int _century) : Books(_century)
	{
		name = _name;
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
	Classic(string _name, int _century, int _year) : Twenty(_name, _century)
	{
		year = _year;
	}
	~Classic() {
	}
};

class AnyBook : public Classic, public Horror
{
protected:
	int age;
public:
	AnyBook(string _name, int _century, int _year, int _counter, string _genre, int _age) : Classic (_name, _century, _year), Horror(_counter, _century, _genre)
	{
		age = _age;
		century = _century;
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
	AnyBook a("Qwerty", 21, 2016, 80000, "classic", 18);
	a.ShowAnyBook();
}

