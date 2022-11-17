#include <iostream>
#include <string>

using namespace std;

class Books
{
protected:
	int	pages;
	int readPages;
public:
	Books(int _pages, int _readPages)
	{
		pages = _pages;
		readPages = _readPages;
	}
	virtual void ShowInfo() = 0;
	virtual int NotReadPages() = 0;
	virtual ~Books() {}
};

class TwentyOne : public Books
{
protected:
	int notRead21;
public:
	TwentyOne(int _notRead21, int _pages, int _readPages) : Books(_pages, _readPages)
	{
		notRead21 = _notRead21;
	}
	int NotReadPages() override
	{
		return notRead21 = pages - readPages;
	}
	virtual void ShowInfo()
	{
		cout << "Quantity of pages 21th: " << pages << endl;
		cout << "Quantity of read pages: " << readPages << endl;
	}
	virtual ~TwentyOne() {
	}
};


class Horror : public TwentyOne
{
protected:
	int notReadHorror;
public:
	Horror(int _notReadHorror, int _notRead21, int _pages, int _readPages) : TwentyOne (_notRead21, _pages, _readPages)
	{
		notReadHorror = _notReadHorror;
	}
	int NotReadPages() override
	{
		return notReadHorror = pages - readPages - notRead21;
	}
	virtual void ShowInfo()
	{
		cout << "Quantity of pages Horror books: " << pages << endl;
		cout << "Quantity of read pages 21th: " << notRead21 << endl;
		cout << "Quantity of read pages: " << readPages << endl;
	}
	virtual ~Horror() {
	}
};

class Twenty : public Books
{
protected:
	int notRead20;
public:
	Twenty(int _notRead20, int _pages, int _readPages) : Books(_pages, _readPages)
	{
		notRead20 = _notRead20;
	}
	int NotReadPages() override
	{
		return notRead20 = pages - readPages;
	}
	virtual void ShowInfo()
	{
		cout << "Quantity of pages 20th: " << pages << endl;
		cout << "Quantity of read pages: " << readPages << endl;
	}
	virtual ~Twenty() {
	}
};

int main()
{
	Books** book = new Books * [3];
	book[0] = new TwentyOne(0, 15000, 3500);
	book[1] = new Twenty(0, 20, 10);
	book[2] = new Horror(0, 1100, 4000, 2000);

	for (int i = 0; i < 3; i++) {
		book[i]->ShowInfo();
		cout << "Not read pages: " << book[i]->NotReadPages() << endl << endl;
	}
	return 0;
}

