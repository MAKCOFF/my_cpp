/*int main(void) {
	//int a = 5;
	//int* pa = &a;
	const int SIZE = 5;
	//cout << pa << endl;

	int* pa{ new int{5} };
	cout <<"pa=\t"<< pa << endl;
	delete pa;
	pa = nullptr;

	int arr[SIZE]{ 5,10,22,44,11 };

	cout << *(arr+1) << endl;
}*/

/* Препроцессор, указатель на функцию
#include <iostream>
#include <string>
#define DEBUG 2

using namespace std;

string GetDataFromDB() {
	return "Data from DB";
}

string GetDataFromServer() {
	return "Data from Server";
}

int func(int a) {
	return a * 2;
}

void ShowInfo(string (*func)() ) {
	cout << func() << endl;
}

int main(void) {

	int (*ptrfunc)(int a);

	ptrfunc = func;

#if DEBUG == 1

	cout << ptrfunc(5) << endl;

#elif DEBUG == 2

	ShowInfo(GetDataFromDB);
	ShowInfo(GetDataFromServer);

#endif // DEBUG

}*/

/* Работа со строками

#include <iostream>
#include <string>

using namespace std;

int main(void) {

	setlocale(LC_ALL, "ru");

	char symbol = 'q';

	char arrstr[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; // \0 - терминирующий ноль, в конце любой строки
	char str[] = "Hello";

	int len = strlen(str);

	const char* str1 = "Hello";

	const char* strarr[] = { "Hello", "world", "Test"};

	void foo(const char* str) {

		cout << strlen(str) << endl;
	}

	foo(str1);

	for (int i = 0; i < 3; i++)
	{
		cout << strarr[i] << endl;
	}

	// Вывод таблицы ASCII
	for (int i = 0; i < 256; i++)
	{
		cout << "code =  " << i << "\t" << "char = " << (char)i << endl;
	}

	string str1 = "Привет";
	string str2 = "мир";
	string str3 = "Привет";
	string result;
	bool x = false;

	result = str1 + " " + str2 +"!";

	if (str1 == str3){
		x = true;
	};

	if (x) {cout << result << endl;}

}
*/

/* Приведение типов
double a = 33.33;

int b = a;

cout << (bool)a << endl;
cout << (int)a << endl;
cout << (char)a << endl;
cout << b << endl;
*/

/* Работа с ООП */

#include <iostream>
#include <string>

using namespace std;

namespace my {

	class Human {

	public:
		/* Конструктор 1 */
		Human() {//(int v_age, string v_name) {
			this->age = 0;
			this->name = "";
			if (this->SIZE > 0) { this->data = new int[this->SIZE] {}; }
			cout << "Call creator 1 " << this << endl;
		}

		/* Конструктор 2 */
		Human(int age, string name, int SIZE) {
			this->age = age;
			this->name = name;
			this->SIZE = SIZE;
			if (this->SIZE > 0) { this->data = new int[this->SIZE] {}; }
			for (int i = 0; i < SIZE; i++)
			{
				this->data[i] = i + 1;
				//cout << this->data[i] << " ";
				//if (i == SIZE-1) { cout << endl; }
			}
			cout << "Call creator 2 " << this << endl;
		}

		/* Конструктор копирования */
		Human(const Human& other) {
			this->SIZE = other.SIZE;
			this->data = new int[other.SIZE];
			this->age = other.age;
			this->name = other.name;
			for (int i = 0; i < other.SIZE; i++) {
				this->data[i] = other.data[i];
				//cout << this->data[i] << " ";
				//if (i == this->SIZE - 1) { cout << endl; }
			}
			cout << "Call copy creator " << this << endl;
		}

		/* Сеттер */
		void SetField(int age, string name) {
			this->age = age;
			this->name = name;
		}

		void GetInfoConsole() {
			cout << name << "\t" << age << endl << endl;
			if (this->SIZE > 0) {
				for (int i = 0; i < this->SIZE; i++) {
					this->data[i] = i + 1;
					cout << this->data[i] << " ";
					if (i == this->SIZE - 1) { cout << endl; }
				}
			}
		}

		/* Перегрузка оператора = */
		/* Возвращает ссылку на объект класса */
		Human & operator = (const Human& other) {

			cout << "Call operator = " << this << endl;

			this->SIZE = other.SIZE;
			if (this->data != nullptr) {
				delete[] this->data;
			}
			this->data = new int[other.SIZE];
			this->age = other.age;
			this->name = other.name;
			for (int i = 0; i < other.SIZE; i++) {
				this->data[i] = other.data[i];
			}

			return *this;
		}

		/* Перегрузка операторов ==, != */

		bool operator == (const Human & other) {

			return this->age == other.age && this->name == other.name;
		}

		bool operator != (const Human& other) {

			return !(this->age == other.age && this->name == other.name);
		}

		/* Перегрузка оператора + */
		Human operator + (const Human& other) {
			
			Human temp;
			temp.age = this->age + other.age;
			return temp;
		}

		/* Перегрузка инкремента и декремента */
		Human& operator ++() {
			
			this->age++;

			return *this;
		}
		/* Возникает ошибка */
		Human& operator ++(int value) {

			Human temp(*this);
			this->age++;

			return temp;
		}

		/* Деструктор */
		~Human() {

			delete[] this->data;
			this->data = nullptr;
			cout << "Call destroyer " << this << endl;
		}

	private:
		int age;
		string name;
		int* data = nullptr;
		int SIZE = 0;
	};
};

//using namespace my;

/* Прототип класса, для определения */
class Test;

/* Перегрузка оператора [] */
class TestClass {
public:
	/* Возвращает ссылку на объект массива класса */
	int& operator[](int index) {

		return arr[index];
	}

private:
	int arr[5]{ 5,44,4,987,69 };

	/* Дружественная функция. Позволяет работать с полями класса снаружи этого класса */
	friend void change_arr(TestClass& value, Test& testvalue);
};

class Test {

private:
	int data = 0;
	friend void change_arr(TestClass& value, Test& testvalue);

public:
	int & GetInfo() {
		return data;
	}
};

/* Дружественная функция. Не является частью класса, лишь может работать с полями нескольких классов */
void change_arr(TestClass& value, Test& testvalue) {
	value.arr[1] = -1;
	testvalue.data = 5;
}

class MyClass
{
public:	

	void printmassage();

private:

};


void MyClass::printmassage(){
	cout << "Hello!" << endl;
}

/* Дружественные методы */

//class Apple;
//class Chel;
//
//class Chel {
//public:
//	void TakeApple(Apple& apple);
//
//	void EatApple(Apple& apple) {		
//	}
//};
//
//class Apple
//{
//public:
//	Apple(int wheight, string color) {
//		this->wheight = wheight;
//		this->color = color;
//	};
//	friend void Chel::TakeApple(Apple& apple);
//
//private:
//	int wheight;
//	string color;
//};
//
//void Chel::TakeApple(Apple& apple) {
//	cout << "TakeApple " << "weight = " << apple.wheight << " color = " << apple.color << endl;
//}

/* Дружественные классы */

class Apple;
class Chel;

class Chel {
public:

	void TakeApple(Apple& apple);

	void EatApple(Apple& apple) {
		
	}
};

class Apple {

	/* дружественный класс */
	friend Chel;

public:
	
	Apple(int wheight, string color) {

		this->wheight = wheight;
		this->color = color;
		count++;
		id = count;
	};

	int GetId() {
		return id;
	}

	/* Статический метод класса. Работает только со статическими переменными класса. */
	static int GetCount() {
		return count;
	}

	static void ChangeColor(Apple& apple, string color) {
		apple.color = color;
	}

	void ChangeColorNoStatic(string color) {
		this->color = color;
	}
	
private:
	int wheight;
	string color;
	int id;
	/* Счетчик экземпляров классов */
	static int count;
};

/* Инициализация статической переменной, производится вне класса */
int Apple::count = 0;

/* Определение метода снаружи класса */
void Chel::TakeApple(Apple& apple) {
	cout << " Вес = " << apple.wheight << " цвет = " << apple.color << endl;
}

/* Вложенный класс */

/*class Image {

public:
	
	void GetImageInfo() {
		for (int i = 0; i < length; i++) {
			
			cout << "#" << i+1 << " " << pixels[i].GetInfo() << endl;
		}
	}

	class Pixel {

	public:

		Pixel(int r, int g, int b) {

			this->r = r;
			this->g = g;
			this->b = b;
		}

		string GetInfo() {

			return "Pixel: r= " + to_string(r) + " g= " + to_string(g) + " b= " + to_string(b);
		}

	private:
		int r;
		int g;
		int b;
	};

	Pixel pixels[5]{
		Pixel(0,4,64),
		Pixel(4,14,10),
		Pixel(111,4,24),
		Pixel(244,244,14),
		Pixel(111,179,64)
	};

private:

	static const int length = 5;

};*/

/* Масив объектов класса */

/*class Pixel {

public:

	Pixel() {

		r = g = b = 0;
	}

	Pixel(int r, int g, int b) {

		this->r = r;
		this->g = g;
		this->b = b;
	}

	string GetInfo() {

		return "Pixel: r= " + to_string(r) + " g= " + to_string(g) + " b= " + to_string(b);
	}

private:
	int r;
	int g;
	int b;
};

Pixel pixels[5]{
	Pixel(0,4,64),
	Pixel(4,14,10),
	Pixel(111,4,24),
	Pixel(244,244,14),
	Pixel(111,179,64)
};*/

/* Агрегация и композиция классов */
//
/*class Cap {
public:
	string GetColor() {
		return color;
	}
private:
	string color = "красного";
};

class Model {
public:
	void InspectModel() {
		cout << "Кепка " << cap.GetColor() << " цвета." << endl;
	}
private:
	Cap cap;
};

class Human1 {

public:
	void think() {
		
		brain.think();
	}

	void InspectCap() {
		cout << "Моя кепка " << cap.GetColor() << " цвета." << endl;
	}

private:
	class Brain {
	
	public:
		void think() {
			cout << "Я думаю!" << endl;
		}
	};

	Brain brain;
	Cap cap;
};*/

/* Наследование классов */

class Human {
private:
	string name;
public:
	string GetName() {
		return name;
	}

	void SetName(string name) {
		this->name = name;
	}
};

class Student : public Human {
public:	
	string group;
	void learn() {
		cout << "Я учусь!" << endl;
	}
};

class ExtramuralStudent : public Student {
public:
	void learn() {
		cout << "Я бываю в универе реже обычного студента!" << endl;
	}
};

class Professor : public Human {
public:
	string subject;
};

/* Модификаторы доступа при наследовании */

/*class A {
public:
	string msgOne = "Сообщение один";
private:
	string msgTwo = "Сообщение два";
protected:
	string msgThree = "Сообщение три";
};

class B : public A {
public:
	void PrintMsg() {
		cout << msgThree << endl;
	}
};*/

/* Порядок вызова конструкторов при наследовании

class A {
public:
	A() {
		cout << "Вызвался конструктор класса A" << endl;
	}
	
	~A() {
		cout << "Вызвался деструктор класса A" << endl;
	}
};

class B : public A {
public:
	B() {
		cout << "Вызвался конструктор класса B" << endl;
	}
	
	~B() {
		cout << "Вызвался деструктор класса B" << endl;
	}
};

class C : public B {
public:
	C() {
		cout << "Вызвался конструктор класса C" << endl;
	}

	~C() {
		cout << "Вызвался деструктор класса C" << endl;
	}
};*/

/* Вызов конструктора базового класса
class A {
public:
	A() {
		msg = "Message";
	}

	A(string msg) {
		this->msg = msg;
	}

	void PrintMsg() {
		cout << msg << endl;
	}

private:
	string msg;
};

class B : public A {
public:
	B():A("New message") {
	}
};
 int main() {

	//setlocale(LC_ALL,"ru");
	//B b;
	//b.PrintMsg();
	//system("pause");

	return 0;
}
 */

 /*
  * Полиморфизм
  * Виртуальные функции
  * Абстрактные классы
  * Чисто виртуальные функции
  * virtual
  * override


 // Абстрактный класс
 class Weapon {
 public:
	 virtual void Shoot() = 0;
	 void Foo(){
		 cout << "Foo()" << endl;
	 }
 };

 class Gun : public Weapon {
 public:
	 void Shoot() override {
		 cout << "Shoot from gun" << endl;
	 }
 };

 class SubMachineGun : public Gun {
	 void Shoot() override {
		 cout << "Shoot from machineGun" << endl;
	 }
 };

 class Bazooka : public Weapon {
	 void Shoot() override {
		 cout << "Shoot from bazooka" << endl;
	 }
 };

 class Knife : public Weapon{
 public:
	 void Shoot() override{
		 cout << "Knife" << endl;
	 }
 };

 class Player {
 public:
	 void Shoot(Weapon *weapon){
		 weapon->Shoot();
	 }
 };
 int main() {

	 Gun gun;
	 SubMachineGun machineGun;
	 Bazooka bazooka;
	 Knife knife;

	 //Gun *weapon = &gun;
	 //Gun *weapon = &machineGun;

	 //weapon->Shoot();

	 Player player;
	 player.Shoot(&bazooka);
	 knife.Foo();

	 return 0;
 }
  */

  /* Виртуальный деструктор

  class A{
  public:
	  A() {
		  cout << "New HEAP resources class A" << endl;
	  }

	  virtual ~A() {
		  cout << "Deleted HEAP resources class A" << endl;
	  }
  };

  class B : public A{
  public:
	  B() {
		  cout << "New HEAP resources class B" << endl;
	  }

	  ~B() override {
		  cout << "Deleted HEAP resources class B" << endl;
	  }
  };*/

  /* Чисто виртуальный деструктор. Используется для вызова деструктора класса родителя
  class A{
  public:
	  A() {

	  }

	  virtual ~A() = 0;
  };
  // обязательно объявить вне класса
  A::~A() {};

  class B : public A{
  public:
	  B() {
	  }

	  ~B() override {

	  }
  };
  int main() {

	  A *b_ptr = new B;
	  delete b_ptr;

	  return 0;
   }
  */

  /* Делегирующий конструктор
  class Human{
  public:
	  Human(string Name){
		  this->Name = Name + "!";
		  this->Age =0;
		  this->Weight = 0;
	  }

	  Human(string Name, int Age): Human(Name) {
		  this->Age = Age;
	  }

	  Human(string Name, int Age, int Weight): Human(Name, Age) {
		  this->Weight = Weight;
	  }

	  string Name;
	  int Age;
	  int Weight;
  };
  int main() {

	  Human human("Aristarh", 30, 70);

	  return 0;
  }
  */

  /* Вызов виртуального метода базового класса
  class Msg{
  public:
	  Msg(string msg){
		  this->msg = msg;
	  }

	  virtual string GetMsg(){
		  return msg;
	  }
  private:
	  string msg;
  };

  class BraketsMsg : public Msg {
  public:
	  BraketsMsg(string msg): Msg(msg){
	  }
	  string GetMsg() override{  // Явное указание метода базового класса
		  return "[" + ::Msg::GetMsg() + "]";
	  }
  };

  class Printer{
  public:
	  void Print(Msg *msg){
		  cout << msg->GetMsg() << endl;
	  }
  };

  int main() {

	  setlocale(LC_ALL,"ru");

	  BraketsMsg m("Hello!");

	  Printer p;
	  p.Print(&m);

	  return 0;
  }
  */

  /* Множественное наследование
   * Порядок вызова конструкторов и деструкторов при множественном наследовании
   * Проблема одинаковых методов в классах

  class Car{
  public:
	  string str = "Field car";

	  Car(){
		  cout << "Call creator Car" << endl;
	  }

	  void Drive() {cout << "I drive!" << endl;}

	  void Use() {cout << "I drive!" << endl;}

	  ~Car(){
		  cout << "Call destroyer Car" << endl;
	  }
  };

  class AirPlain{
  public:
	  string str2 = "Field plain";

	  AirPlain(){
		  cout << "Call creator AirPlain" << endl;
	  }

	  void Fly(){cout << "I fly!" << endl;}

	  void Use(){cout << "I fly!" << endl;}

	  ~AirPlain(){
		  cout << "Call destroyer AirPlain" << endl;
	  }
  };

  class FlyingCar : public Car, public AirPlain{
  public:
	  FlyingCar(){
		  cout << "Call creator FlyingCar" << endl;
	  }
	  ~FlyingCar(){
		  cout << "Call destroyer FlyingCar" << endl;
	  }
  };

  int main() {

	  setlocale(LC_ALL,"ru");

	  FlyingCar fc;
	  //fc.Drive();
	  //fc.Fly();

	  //Car *ptrC = &fc;
	  //AirPlain *ptrA = &fc;

	  //((Car)fc).Use();
	  //((AirPlain)fc).Use();

	  fc.Car::Use();
	  fc.AirPlain::Use();

	  return 0;
  }
  */

  /* Интерфейсы

  class IBicycle{
  public:
	  virtual void TwistTheWheel() =0;
	  virtual void Ride() = 0;
  };

  class SimpleBicycle : public IBicycle{
  public:
	  void TwistTheWheel() override {
		  cout << "метод TwistTheWheel() SimpleBicycle" << endl;
	  }
	  void Ride() override{
		  cout << "метод Ride() SimpleBicycle" << endl;
	  }
  };

  class SportBicycle : public IBicycle{
  public:
	  void TwistTheWheel() override {
		  cout << "метод TwistTheWheel() SportBicycle" << endl;
	  }
	  void Ride() override{
		  cout << "метод Ride() SportBicycle" << endl;
	  }
  };

  class Human{
  public:
	  void RideOn(IBicycle & bicycle) {
		  cout << "Крутим руль" << endl;
		  bicycle.TwistTheWheel();
		  cout << "Поехали" << endl;
		  bicycle.Ride();
	  }
  };

  int main() {

	  SetConsoleOutputCP(CP_UTF8);

	  SimpleBicycle sb;
	  SportBicycle spb;

	  Human human;
	  human.RideOn(sb);
	  human.RideOn(spb);

	  return 0;
  }
  */

  /* Ромбовидное наследование
   * Виртуальное наследование

  class Component {
  public:
	  Component(string companyName) {
		  cout << "Конструктор Component" << endl;
		  this->companyName = companyName;
	  }
	  string companyName;
  };

  class GPU : public Component{
  public:
	  GPU(string companyName) : Component(companyName) {
		  cout << "Конструктор GPU" << endl;
	  }
  };

  class Memory : public Component{
  public:
	  Memory(string companyName) : Component(companyName) {
		  cout << "Конструктор Memory" << endl;
	  }
  };

  class GraphicCard : public GPU, public Memory {
  public:
	  GraphicCard(string GPUCompanyName, string MemoryCompanyName) : Memory(GPUCompanyName),
																	 GPU(MemoryCompanyName) {
		  cout << "Конструктор GraphicCard" << endl;
	  }
  };

  class Character {
  public:
	  Character() {
		  cout << "Конструктор Character" << endl;
	  }
	  int HP;
  };

  class Elf : public virtual Character{
  public:
	  Elf() {
		  cout << "Конструктор Elf" << endl;
	  }
  };

  class Warrior : public virtual Character{
  public:
	  Warrior() {
		  cout << "Конструктор Warrior" << endl;
	  }
  };

  class ElfWarrior : public Elf, public Warrior {
  public:
	  ElfWarrior() {
		  cout << "Конструктор ElfWarrior" << endl;
	  }
  };

  int main() {

	  SetConsoleOutputCP(CP_UTF8);

	  GraphicCard gc("AMD", "Samsung");

	  ElfWarrior ew;

	  return 0;
  }*/




int main() {

	setlocale(LC_ALL, "ru");

	/*Human man;
	Human gerl(22, "Tanya", 20);

	man.SetField(20, "Ivan");
	man.GetInfoConsole();

	Human gerl2(gerl);

	gerl.GetInfoConsole();
	gerl2.GetInfoConsole();

	//man = gerl = gerl2;
	//man.GetInfoConsole();

	bool result = man == gerl;
	result = man != gerl;

	gerl2 = man + gerl;

	++man;
	man.GetInfoConsole();

	//Human gerl3 = gerl++;
	//gerl3.GetInfoConsole();

	TestClass a;
	Test b;

	cout << a[1] << endl;
	a[1] = 100;
	cout << a[1] << endl;
	cout << a.operator[](2) << endl;

	change_arr(a, b);
	cout << a[1] << endl << b.GetInfo() << endl;

	MyClass c;
	c.printmassage();*/

	//Apple apple(150, "Красное");
	//apple.ChangeColor(apple, "Желтое");

	/* Статический - работает с любым объектом передавемого класса */
	//Apple::ChangeColor(apple, "Желтое");

	/* Обычный метод - работает с определенным объектом класса */
	//apple.ChangeColorNoStatic("Зеленое");

	//Apple apple2(100, "Желтое");
	//Apple apple3(120, "Зеленое");

	//cout << apple.GetId() << endl;
	//cout << apple2.GetId() << endl;
	//cout << apple3.GetId() << endl;

	//cout << apple.GetCount() << endl;
	//cout << Apple::GetCount() << endl;

	//Chel human;
	//human.TakeApple(apple);

	//Image img;
	//img.GetImageInfo();

	//Image::Pixel pixel(22, 33, 44);
	//cout << pixel.GetInfo() << endl;

	//const int LENGTH = 5;
	//Pixel arr[LENGTH];
	//arr[0] = Pixel(11, 159, 222);
	//cout << arr[0].GetInfo() << endl;
	//
	//int LENGTH = 5;
	//Pixel* arr = new Pixel[LENGTH];
	//arr[0] = Pixel(11, 159, 222);
	//cout << arr[0].GetInfo() << endl;
	//delete[]arr;
	/*
	Human1 human;

	human.think();
	human.InspectCap();

	Model model;
	model.InspectModel();*/

	/*Student st;
	st.learn();
	st.SetName("Аристарх");
	cout << st.GetName() << endl;
		
	ExtramuralStudent est;
	est.learn();
	est.SetName("Евлампий");
	cout << est.GetName() << endl;*/


				
	return 0;
}
