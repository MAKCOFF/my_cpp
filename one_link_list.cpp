//#include <iostream>
//#include <string>
//#include <windows.h>
//#include <fstream>
//
//using namespace std;
//
///* Работа с файлами. Создание, запись, чтение */
//// fstream
//// ifstream - чтение
//// ofsteaam - запись
//
//
///* Создание собственного класса исключений */
//
//class MyException : public exception {
//public:
//    MyException(const char *msg):exception(msg) {
//
//    }
//private:
//};
//
//void Foo(int value) {
//
//    if (value<0){ throw "число меньше 0 !!!"; }
//
//    if (value == 0) { throw exception("число равно 0 !!!"); }
//
//    if (value == 1) { throw MyException("число равно 1 !!!"); }
//
//    cout << "Переменная = " << value << endl;
//}
//
//int main() {
//    SetConsoleOutputCP(CP_UTF8);
//    //setlocale(LC_ALL, "ru");
//
//    try{
//        Foo(1);
//    }
//    catch (MyException &ex){
//        cout << "Блок 1 Мы поймали " << ex.what() << endl;
//    }
//
//
//    return 0;
//}

#include <iostream>
#include <windows.h>

using namespace std;

/* Реализация односвязного списка */

template<typename T>
class List
{
public:
    List();
    ~List();

    //удаление первого элемента в списке
    void pop_front();
    //добавление элемента в конец списка
    void push_back(T data);
    // очистить список
    void clear();
    // получить количество элементов в списке
    int GetSize() { return Size; }
    // перегруженный оператор []
    T& operator[](const int index);
    //добавление элемента в начало списка
    void push_front(T data);
    //добавление элемента в список по указанному индексу
    void insert(T data, int index);
    //удаление элемента в списке по указанному индексу
    void removeAt(int index);
    //удаление последнего элемента в списке
    void pop_back();

private:

    template<typename T>
    class Node {
    public:

        Node* pNext;
        T data;

        Node(T data=T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T> *head;
};

template<typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List(){
    clear();
}

template<typename T>
T& List<T>::operator[](int index){

    int counter = 0;

    Node<T>* current = this->head;

    while (current!=nullptr){

        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::pop_back() {
    removeAt(Size-1);
}

template<typename T>
void List<T>::removeAt(int index) {

    if (index==0){
        pop_front();
    } else{
        Node<T> *previous = this->head;
        for (int i = 0; i < index-1; ++i) {
            previous = previous->pNext;
        }
        Node<T> *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template<typename T>
void List<T>::insert(T data, int index) {

    if (index==0){
        push_front(data);
    } else{
        Node<T> *previous = this->head;
        for (int i = 0; i < index-1; ++i) {
            previous = previous->pNext;
        }
        previous->pNext = new Node<T>(data, previous->pNext);
        Size++;
    }
}

template<typename T>
void List<T>::push_front(T data) {
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::clear() {
    while (Size){
        pop_front();
    }
}

template<typename T>
void List<T>::pop_front(){

    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
void List<T>::push_back(T data){
    if (head == nullptr){
        head = new Node<T>(data);
    }
    else {

        Node<T>* current = this->head;

        while (current->pNext != nullptr){
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    Size++;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);

    List<int> list;

    list.push_front(5);
    list.push_front(7);
    list.push_front(101);


    for (int i = 0; i < list.GetSize(); i++){
        cout << list[i] << endl;
    }
    cout << endl;

    //list.pop_front();
    //list.removeAt(1);
    list.pop_back();

    for (int i = 0; i < list.GetSize(); i++){
        cout << list[i] << endl;
    }


    //list.clear();

    return 0;
}
