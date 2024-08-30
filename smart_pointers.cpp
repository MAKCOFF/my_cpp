/* Умные указатели

template<class T>
class SmartPointer
{
public:
	SmartPointer(T *ptr){
		this->ptr = ptr;
		cout << "Constructor" << endl;
	}

	~SmartPointer(){
		delete ptr;
		cout << "Destroyer" << endl;
	}

	T& operator*() {
		return *ptr;
	}

private:
	T* ptr;
};

int main() {

	setlocale(LC_ALL, "ru");

	SmartPointer<int> pointer = new int(5);

	*pointer = 65;

	cout << *pointer << endl;

	return 0;
}
*/

/* smart pointers
* auto_ptr
* unique_ptr
* shared_ptr
#include <memory>
	//auto_ptr<int> ap1(new int(5));

	//auto_ptr<int> ap2(ap1);

	//unique_ptr<int> p1(new int(5));

	//unique_ptr<int> p2;

	// Смена указателя, но при этом предидущий указатель теряет данные
	//p2 = move(p1);
	//p2.swap(p1);

	// Берем из умного обычный указатель
	//int* p = p1.get();

	//int* p = new int(5);

	//unique_ptr<int> p1(p);

	// Сбрасывает данные в обоих указателях
	//p1.reset();

	// Делает умный указатель пустым, при этом простой указатель остается
	//p1.release();

	// Может создавать 2 укказателя на одни данные,
	// удаляет данные только при пропадании всех ссылок из области видимости
	shared_ptr<int> p1(new int(5));

	shared_ptr<int> p2(p1);
*/

/* Умные указаетли на массивы 
#include <memory>
int main() {

	setlocale(LC_ALL, "ru");

	int SIZE;
	cin >> SIZE;

	shared_ptr<int[]> ptr(new int[SIZE] {1, 6, 44, 9, 8});

	for (int i = 0; i < SIZE; i++){
		ptr[i] = rand() % 10;
		cout << ptr[i] << endl;
	}

	return 0;
}
*/