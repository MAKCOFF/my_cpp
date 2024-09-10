#include <iostream>
//#include <list>
//#include <vector>
//#include <forward_list>
//#include <array>
//#include <deque>
//#include <set>
#include <string>
#include <map>
#include <windows.h>

using namespace std;

//typedef std::vector<int> int_vector;

/* Библиотека стандартных шаблонов STL
 * VECTOR

 int main() {

    SetConsoleOutputCP(CP_UTF8);

    //vector<int> myVector = {0,48,484,999};

    // Дополнительный способ инициализации динамического массива (число элементов, чем иниц-ть)
    vector<int> myVector(10,5);

    // Добавляет зарезервированные ячейки для повышения скорости добавления данных (capacity())
    //myVector.reserve(6);

//    myVector.push_back(5);
//    myVector.push_back(44);
//    myVector.push_back(77);

//    myVector[0] = 1000;

    // Метод at() проверяет границы массива и бросает исключение при выходе за границы
//    try {
//        cout << myVector.at(10) << endl;
//    } catch (const std::out_of_range & ex) {
//        cout << ex.what() << endl;
//    }

    //myVector.pop_back();
    //myVector.clear();

    //cout << myVector.size() << endl;

    // Метод проверки, пустой ли массив
    cout << myVector.empty() << endl;



    // Метод capacity() считает реальный размер массива с учетом резервных ячеек
    //cout << myVector.capacity() << endl << endl;

    // Удаляет резервные ячейки
    //myVector.shrink_to_fit();

    cout << myVector.capacity() << endl << endl;

    // Ренициализация массива, оставляет данные в старых ячейках, в новых созданных записывает что передаем в val
    //myVector.resize(12,7);

    for (int i =0; i < myVector.size(); i++) {
        cout << myVector[i] << endl;
    }

    return 0;
}
 * */

/* STL итераторы

int main() {

    SetConsoleOutputCP(CP_UTF8);

    vector<int> myVector = {1,9,44,422,677,78};

    //vector<int>::iterator it;
    // Итератор, указатель на 1й элемент массива vector
    //it = myVector.begin();

    // *it = 1000;

    // арифметика указателя
    //it++;
    //it+=2;
    //it-=2;


//    for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++){
//        cout << *i << endl;
//    }

    // vector<int>::const_iterator - константный итератор, запрещает запись данных по итератору
//    for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); i++){
//        cout << *i << endl;
//    }

    // Реверсивный итератор
//    for (vector<int>::reverse_iterator i = myVector.rbegin(); i != myVector.rend(); i++){
//        cout << *i << endl;
//    }

    vector<int>::iterator it = myVector.begin();

    // Стандартная функция арифметики указателей
    //advance(it,3);
    //cout << *it << endl;

    // Вставка элемента
    //advance(it,3);
    //myVector.insert(it, 999);

    vector<int>::iterator it_erase = myVector.begin();

    // Удаление элемента по итератору
    //myVector.erase(it_erase);

    // Удаление 3х элементов по итератору
    myVector.erase(it_erase, it_erase+3);

    for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++){
        cout << *i << endl;
    }

    return 0;
}
 * */

/* STL - List - двусвязный список

template<typename T>
void PrintList(const list<T> &lst){
    for (auto i = lst.cbegin(); i != lst.cend(); ++i){
        cout << *i << endl;
    }
}

int main() {

    SetConsoleOutputCP(CP_UTF8);

    list<int> myList = {99,99,15,99,64,99,99,979,99};
    //list<int> myList2 = {22,44,61,585,22};
    //myList.push_back(5);
    //myList.push_front(151);

    //myList.sort();
    //myList.pop_back();
    //myList.pop_front();

    //cout << myList.size() << endl;

    //myList.unique();
    //myList.reverse();

    //auto it = myList.begin();

    //++it;

    //advance(it,3);

    //myList.insert(it,111);

    //myList.erase(it);

    //myList.remove(99);

    //myList.assign(3,6545);

    // должна копировать список, но чет не работает
    //myList.assign(myList2.begin(),myList2.begin());

    PrintList(myList);

    //myList.clear();

    return 0;
}
 * */

/* Итераторы STL prefix vs postfix

int main() {

    SetConsoleOutputCP(CP_UTF8);

    list<int>::iterator it;

    it++;

    // Считается что такая форма быстрее
    ++it;

    return 0;
}
*/

/* Цикл for (:) - range-based циклы

int main() {

    SetConsoleOutputCP(CP_UTF8);

//    int arr[] = {5,11,94,99,44};
//
//    // При передаче параметра по ссылке & работает быстрее, не копирует и появляется доступ к данным в массиве
//    for (auto &i: arr) {
//        i = -1;
//        cout << i << endl;
//    }

    list<int> lst = {5,11,94,99,44};

    for (const auto &i: lst) {
        cout << i << endl;
    }

    return 0;
}
*/

/* forward_list -  односвязный список

int main() {

    SetConsoleOutputCP(CP_UTF8);

    forward_list<int> fl = {131,94,494};
    fl.push_front(1);
    fl.push_front(4);

    forward_list<int>::iterator it = fl.begin();

    //fl.insert_after(it,999);
    //fl.erase_after(it);

//    it++;
//    cout << *it << endl;

    for (auto i : fl) {
        cout << i << endl;
    }

    return 0;
}
*/

/* STL - array - статический массив
int main() {

    SetConsoleOutputCP(CP_UTF8);

    array<int, 4> arr = {1,94,77,9};

    //arr.fill(-1);

    //cout << arr.front() << endl;
    //cout << arr.back() << endl;

    for (auto i : arr) {
        cout << i << endl;
    }

    return 0;
}

*/

/* STL - Операторы сравнения

int main() {

    SetConsoleOutputCP(CP_UTF8);

    array<int, 4> arr = {1,94,77, 9};

    array<int, 4> arr2 = {1,94,77};

    bool result = (arr > arr2);

    cout << result << endl;

    return 0;
}
*/

/* STL - deque динамический массив массивов(стандартно по 3 элемента)

int main() {

    SetConsoleOutputCP(CP_UTF8);

    deque<int> dq = {1,9,94};

    //dq.push_back(3);
    //dq[1];

    // итератор произвольного доступа, двигается в обоих направлениях
    //deque<int>::iterator it;

    for (auto i: dq) {
        cout << i << endl;
    }

    return 0;
}
*/

/* STL - SET | MULTISET Ассоциативные контейнеры (бинарное дерево)
    SET
            5
           / \
          1  12
         / \
        -1 4

int main() {

    SetConsoleOutputCP(CP_UTF8);

    // Хранит только уникальные элементы, одинаковые значения не добавляются

    set<int> mySet = {5,1,12,4,-1};

    //set<int> mySet;

    //mySet.insert(5);
    //mySet.insert(1);
    //mySet.insert(12);

    //mySet.insert(4);
    //mySet.insert(-1);

    //mySet.insert(1);
    //mySet.insert(1);

    //for (int i = 0; i < 20; ++i) {
    //    mySet.insert(rand()%10);
    //}

    // возвращает итератор на найденный объект, если не нашел, возвращает пустую ссылку mySet.end()
    //auto it = mySet.find(12);

    //int value;

    //cin >> value;

    //if (mySet.find(value) != mySet.end()){
    //    cout << "Число " << value << " найдено!" << endl;
    //}else{
    //    cout << "Число " << value << " не найдено!" << endl;
    //}

    // myset.erase(элемент) - удаляет переданный элемент. Возвращает логический 0 если: элемент не получилось удалить.
    // Возвращает логическую 1 если: элемент получилось удалить.
    //auto result = mySet.erase(66);

    auto result = mySet.insert(5);

    //cout << result << endl;

    for (auto &item: mySet) {
        cout << item << endl;
    }

    return 0;
}
MULTISET

int main() {

    SetConsoleOutputCP(CP_UTF8);

    // Позволяет хранить одинаковые элементы
    multiset<int> myMultiset = {5,5,1,12,4,-1};

    // mymultiset.lower_bound(значение) - вернет итератор указывающий на самое первое значение которое мы передали.
    //auto it1 = myMultiset.lower_bound(5);

    // mymultiset.upper_bound(значение) - вернет итератор на тот элемент,
    // который идет ПОСЛЕ того значение, которое мы передали, и которое не повторяет переданное значение.
    //auto it2 = myMultiset.upper_bound(5);

    // mymultiset.equale_range(значение) - вернет диапазон значений от .lower_bound до .upper_bound.
    auto a = myMultiset.equal_range(5);

    for (auto &item: myMultiset) {
        cout << item << endl;
    }

    return 0;
}
*/

/* typedef

typedef std::vector<int> int_vector;

int main() {

    SetConsoleOutputCP(CP_UTF8);

    int_vector myVector;

    return 0;
}
*/

/* STL - MAP | MULTIMAP ассоциативные контейнеры, бинарное дерево ключ/значение(словарь)

            3 м
           /   \
          1 т   22 к
            \
            2 н

int main() {

    SetConsoleOutputCP(CP_UTF8);

 MAP - хранит только уникальные ключи

    //std::pair<int, string> p(1,"телефон");

    //cout << p.first << "\t" << p.second << endl;

    map<int, string> myMap;

    myMap.emplace(3,"монитор");

    myMap.insert(make_pair(1, "телефон"));

    myMap.insert(pair<int, string>(2,"ноутбук"));

    myMap.emplace(22,"клавиатура");

    //auto it = myMap.find(3);
    //
    //if (it != myMap.end()){
    //    cout << it->second << endl;
    //}else{
    //    cout << "Ключ не найден!" << endl;
    //}

    //auto res = myMap.emplace(22,"dfsgsd");

    map<string, int> myMap;

    myMap.emplace("Петя", 1313);
    myMap.emplace("Маша", 222);
    myMap.emplace("Миша", 4441);

    myMap["Петя"] = 23;

    cout << myMap["Петя"] << endl;

    // добавляет, если пара с данным ключом не существует
    //myMap["Вася"] = 9797;

    try{
        myMap.at("Вася") = 3;
    }
    catch (const std::exception&ex) {
        cout << ex.what() << endl;
        cout << "Ключ отсутствует в контейнере map" << endl;
    }

    myMap.erase("Петя");

 MULTIMAP - может хранить одинаковые ключи

    multimap<string, int> myMultimap;

    myMultimap.emplace("Петя", 1313);
    myMultimap.emplace("Маша", 222);
    myMultimap.emplace("Миша", 4441);

    myMultimap.emplace("Миша", 223);

    return 0;
}
*/

int main() {

    SetConsoleOutputCP(CP_UTF8);

    

    return 0;
}
