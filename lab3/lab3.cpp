#include <iostream>
#include <string>

using namespace std;

class Books
{
protected:
	string	publication;
public:
	Books(){
	}
	Books(string _publication)
	{
		publication  = _publication;
	}
	~Books(){
	}
};

class American : public virtual Books
{
protected:
	string genre;
public:
	American() {
	}
	American(string _genre, string _publication) : Books(_publication)
	{
		genre = _genre;
	}
	~American(){
	}
};


class Horror : public American
{
protected:
	int counter;
public:
	Horror() {
	}
	Horror(int _counter, string _publication, string _genre) : American(_genre, _publication)
	{
		counter = _counter;
	}
	~Horror() {
	}
};

class Russish : public virtual Books
{
protected:
	string name;
public:
	Russish() {
	}
	Russish(string _name, string _publication) : Books(_publication)
	{
		name = _name;
	}
	~Russish() {
	}
};

class Classic : public Russish
{
protected:
	int year;
public:
	Classic() {
	}
	Classic(string _name, string _publication, int _year) : Russish(_name, _publication)
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
	AnyBook(string _name, string _publication, int _year, int _counter, string _genre, int _age) : Classic (_name, _publication, _year), Horror(_counter, _publication, _genre)
	{
		age = _age;
		publication = _publication;
	}
	~AnyBook() {
	}
	void ShowAnyBook()
	{
		cout << "Publication: " << publication << endl;
		cout << "Year: " << year << endl;
		cout << "Genre: " << genre << endl;
		cout << "Name: " << name << endl;
		cout << "Counter: " << counter << endl;
		cout << "Age of readers: " << age << endl;

	}
};

int main()
{
	AnyBook a("Qwerty", "Russia-american", 2016, 80000, "classic", 18);
	a.ShowAnyBook();
}

