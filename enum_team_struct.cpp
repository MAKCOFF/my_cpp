/* enum

class PC {
public:
	enum PCState {
		OFF,
		ON,
		SLEEP
	};

	PCState GetState() const { return State; }
	void SetState(PCState State) {
		this->State = State;
	}

private:
	PCState State;
};

enum Speed {
	MIN = 150,
	RECOMEND = 600,
	MAX = 800
};

int main() {

	setlocale(LC_ALL, "ru");

	PC pc;
	pc.SetState(PC::PCState::ON);

	switch (pc.GetState())
	{
	case PC::PCState::OFF:
		cout << "ПК выключен!" << endl;
		break;
	case PC::PCState::ON:
		cout << "ПК включен!" << endl;
		break;
	case PC::PCState::SLEEP:
		cout << "ПК спит!" << endl;
		break;
	}

	Speed sp = Speed::MAX;
	cout << sp << endl;

	return 0;
}
*/

/* namespace - пространство имен
namespace firstNS {

	void Foo() {
		cout << "Foo firstNS" << endl;
	}
}

namespace secondNS {
	void Foo() {
		cout << "Foo secondNS" << endl;
	}
}

int main() {

	setlocale(LC_ALL, "ru");

	firstNS::Foo();
	secondNS::Foo();

	return 0;
}
*/

/* Шаблоны классов

class Point {
public:

	Point() { x = y = z = 0; }

	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	int x;
	int y;
	int z;
};

template<class T1, class T2>
class MyClass
{
public:
	MyClass(T1 value, T2 value2) {
		this->value = value;
		this->value2 = value2;
	}

	void DataTypeSize() {
		cout << "value " << sizeof(value) << endl;
		cout << "value2 " << sizeof(value2) << endl;
	}

private:
	T1 value;
	T2 value2;
};

int main() {

	setlocale(LC_ALL, "ru");

	int a = 5;
	Point p;

	MyClass<Point, int> c(p, a);
	c.DataTypeSize();

	return 0;
}
*/

/* Наследование шаблонов

class Point {
public:

	Point() { x = y = z = 0; }

	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	int x;
	int y;
	int z;
};

template<class T>
class TypeSize
{
public:
	TypeSize(T value) {
		this->value = value;
	}

	void DataTypeSize() {
		cout << "value " << sizeof(value) << endl;
	}

protected:
	T value;
};

template<class T>
class TypeInfo: public TypeSize<T>
{
public:
	TypeInfo(T value) : TypeSize<T>(value) {
	}

	void ShowTypeName() { cout << "Название типа " << typeid(T).name() << endl; }
private:

};

int main() {

	setlocale(LC_ALL, "ru");

	//int a = 2;

	Point a;

	TypeInfo<Point> c(a);

	c.ShowTypeName();
	c.DataTypeSize();

	return 0;
}
*/

/* Специализация шаблонов классов

template <class T>
class Printer {
public:
	void Print(T value) { cout << value << endl;	}
};

template<>
class Printer<string> {
public:
	void Print(string str) {
		cout << "___" << str << "___" << endl;
	}
};

int main() {

	setlocale(LC_ALL, "ru");

	Printer<int> a;
	a.Print(65);

	Printer<string> p;
	p.Print("Hello world!!!");


	return 0;
}
*/

/* Структуры, struct

class MyClass {
	int a = 10;
public:
	void Print() { cout << a << endl; }
};

class MyClass2 : public MyClass
{

};

struct MyStruct {
	void Print() { cout << a << endl; }
private:
	int a = 22;
};

struct MyStruct2 : MyStruct {
};

int main() {

	setlocale(LC_ALL, "ru");

	MyClass mc;
	MyStruct ms;

	MyStruct2 ms2;

	mc.Print();
	ms2.Print();

	return 0;
}
*/ 