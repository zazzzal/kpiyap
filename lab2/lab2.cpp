#include <iostream>
#include <iterator>
#include <locale>

using namespace std;

class LengthDescription
{
private:
	int length;
public:
	LengthDescription()
	{
		length = 0;
	}
	LengthDescription(int length)
	{
		this->length = length;
	}
	void Show()
	{
		cout << length << endl;
	}
};

class Array
{
private:
	int* arr;
	int length;
public:
	Array()
	{
		length = 1;
		arr = new int;
		arr[0] = 0;
	}
	Array(int length)
	{
		this->length = length;
		arr = new int[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = i + 1;
		}
	}
	Array(int length, int k)
	{
		this->length = length;
		arr = new int[length];
		for (int i = 0; i < this->length; i++)
		{
			arr[i] = i + 1 + k;
		}
	}
	Array(const Array& Arr)
	{
		arr = Arr.arr;
		length = Arr.length;
	}
	Array(int* arr, int length)
	{
		this->arr = arr;
		this->length = length;
	}
	void ShowArr() {
		this->length = length;
		cout << "массив: ";
		for (int i = 0; i < this->length; i++)
		{
			cout << arr[i] << "i ";
		}
		cout << endl;
	}
	Array& operator=(const Array& temp)//+++
	{
		arr = temp.arr;
		length = temp.length;
		return *this;
	}
	int operator[](int index)
	{
		index--;
		return arr[index];
	}
	Array& operator()(int a)//+++
	{
		for (int i = 0; i < length; i++)
		{
			arr[i] = a;
		}
		return *this;
	}
	Array& operator++()//+++
	{
		for (int i = 0; i < length; i++)
		{
			++arr[i];
		}
		return *this;
	}
	Array& operator++(int)//+++
	{
		for (int i = 0; i < length; i++)
		{
			arr[i]++;
		}
		return *this;
	}
	bool operator== (Array& temp)//+++
	{
		if (length != temp.length)
		{
			return false;
		}
		else 
		{
			for (int i = 0; i < length; i++)
			{
				if (arr[i] != temp.arr[i])
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
	}
	Array operator+(Array& temp)//+++
	{
		int min = 0, max = 0;
		if (this->length >= temp.length)
		{
			max = this->length;
			min = temp.length;
			Array sum(arr, length);
			for (int i = 0; i < min; i++)
			{
				sum.arr[i] += temp.arr[i];
			}
		return sum;
		}
		else
		{
			min = this->length;
			max = temp.length;
			
			Array sum(temp.arr, temp.length);
		for (int i = 0; i < min; i++)
		{
			sum.arr[i] += this->arr[i];
		}
		return sum;
		}
	}
	friend Array operator-- (Array& temp, int);//+++
	friend Array operator-- (Array& temp);//+++
	friend Array operator- (Array& tempL, Array& tempR);
	friend bool operator> (Array& tempL, Array& tempR);//+++
	friend ostream& operator<<(ostream& out,Array& temp);//+++

	operator int()//+++
	{
		int max = 10e-9;
		for (int i = 0; i < length; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		return max;
	}

	operator LengthDescription()//+++
	{
		return LengthDescription(length);
	}
};
Array operator -(Array& left, Array& right)
{
	int lengthL = left.length;
	int lengthR = right.length;
	Array itog = lengthL;
	int i = 0;
	while (lengthL-- && lengthR--)
	{
		itog.arr[i] = left.arr[i] - right.arr[i++];
	}
	return itog;
}

Array operator--(Array& temp)
{
	for (int i = 0; i < temp.length; i++)
	{
		--temp.arr[i];
	}
	return temp;
}

Array operator--(Array& temp, int)
{
	for (int i = 0; i < temp.length; i++)
	{
		temp.arr[i]--;
	}
	return temp;
}

ostream& operator<<(ostream& out,Array& temp)
{
	for (int i = 0; i < temp.length; i++) {
		out << temp.arr[i] << "i ";
	}
	cout << endl;
	return out;
}

bool operator> (Array& tempL, Array& tempR)
{
	int k = 0;
	if (tempL.length > tempR.length)
	{
		return true;
	}
	else
	{
		if (tempL.length == tempR.length)
		{
			for (int i = 0; i < tempR.length; i++)
			{
				if (tempL.arr[i] >= tempR.arr[i])
				{
					k++;
				}
			}
			if (k==tempL.length)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int n = 0, k = 0;
	cout << "Введите длину первого массива:";
	cin >> n;
	Array a1(n);
	a1.ShowArr();
	cout << endl;
	cout << "Введите длину второго массива:";
	cin >> k;
	Array a2(k, 7);
	a2.ShowArr();
	cout << endl;
	cout<<"Оператор =\n" << "Третий ";
	Array a3(4);
	a3.ShowArr();
	cout << endl;
	cout << "Опертор [] для второго элемента третьего массива\n";
	cout << a3[2] << "i" << endl;
	cout << endl;
	cout << "Опертор () инициализирует третий массив шестерками\n";
	a3(6);
	a3.ShowArr();
	cout << endl;
	cout << "Опертор ++ увеличивает все значения третьего массива\n";
	a3++;
	a3.ShowArr();
	cout << endl;
	cout << "Опертор ++ увеличивает все значения третьего массива\n";
	++a3;
	a3.ShowArr();
	cout << endl;
	cout << "Оператор == (сравниваем 1 и 2 массив)" << endl;
	if (a1 == a2)
	{
		cout << "Массивы равны";
	}
	else
	{
		cout << "Массивы не равны\n";
	}
	cout << endl;
	cout << "Опертор -- уменьшает все значения третьего массива\n";
	--a3;
	a3.ShowArr();
	cout << endl;
	cout << "Опертор -- уменьшает все значения третьего массива\n";
	a3--;
	a3.ShowArr();
	cout << endl;
	cout << "Опертор << (то же, что и метод ShowArr)\n";
	cout << a3;
	cout << endl;
	cout << "Опертор > (сравниваем 1 и 2 массив)\n";
	if (a1 > a2)
	{
		cout << "Массив 1 больше";
	}
	else
	{
		cout << "Массив 1 меньше\n";
	}
	cout << endl;
	cout << "Опертор преобразвания во встроенный тип int\n";
	int max = a2;
	cout << max << "i \n";
	cout << endl;
	cout << "Опертор преобразвания во пользовательский тип int\n";
	LengthDescription ld = a2;
	ld.Show();
	cout << endl;
	cout << "Опертор + для массивов \n";
	Array a5,  a6(5, 6), a7(8, 3);
	a5 = a6 - a7;
	a6.ShowArr();
	a7.ShowArr();
	cout << endl;
	Array a4 = a6 + a7;
	a4.ShowArr();
	cout << endl;
	cout << "Опертор - для тех же массивов\n";
	a5.ShowArr();
	return 0;
}