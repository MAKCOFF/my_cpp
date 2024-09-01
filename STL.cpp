#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

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

    //*it = 1000;

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

/* STL - List


 * */

int main() {

    SetConsoleOutputCP(CP_UTF8);



    return 0;
}
