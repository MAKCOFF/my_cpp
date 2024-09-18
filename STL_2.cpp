/* STL Алгоритмы сортировки | Бинарный предикат | Лямбда функции
 * SORT

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

// Предикат
//bool my_pred(int a, int b){
//    return a > b;
//}

class Person{
public:
    Person(string name, double score){
        this->name = name;
        this->score = score;
    }

    bool operator()(const Person &p){
        return p.score > 180;
    }

    string name;
    double score;
};

int main(){
    SetConsoleOutputCP(CP_UTF8);

//    vector<int> v = {9,4,94,6,1,3,7};
//                                        // лямбда функция предиката по убыванию
//    sort(v.begin(), v.end(), [](int a, int b){return a > b;} );

//    const int SIZE = 7;
//    int arr[SIZE] = {9,4,94,6,1,3,7};
//
//    sort(arr, arr + SIZE, [](int a, int b){return a > b;} );

    vector<Person> people {
        Person("Vasya", 181),
        Person("Petya", 30),
        Person("Masha", 179),
        Person("Dasha", 200),
        Person("Katya", 198),
        Person("Andrey", 50),
        Person("Sergey", 150),
        Person("Ivan", 129),
        Person("Petya", 10)
    };

//    sort(people.begin(), people.end(), [](const Person &p1, const Person &p2){
//        return p1.name < p2.name;
//    });

    sort(people.begin(), people.end(), [](const Person &p1, const Person &p2){
        return p1.score > p2.score;
    });

    for (const auto& i : people) {
        cout << "Имя:\t" << i.name << "\tбаллы:\t" << i.score << endl;
    }

    return 0;
}
*/

/* STL Алгоритмы, поиск

 std::find, std::find_if, std::find_if_not


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class Person{
public:
    Person(string name, double score){
        this->name = name;
        this->score = score;
    }

    bool operator()(const Person &p){
        return p.score > 180;
    }

    string name;
    double score;
};

int main(){
    SetConsoleOutputCP(CP_UTF8);

    vector<Person> people {
        Person("Vasya", 181),
        Person("Petya", 30),
        Person("Masha", 179),
        Person("Dasha", 200),
        Person("Katya", 198),
        Person("Andrey", 50),
        Person("Sergey", 150),
        Person("Ivan", 129),
        Person("Petya", 10)
    };


    for (const auto& i : people) {
        cout << "Имя:\t" << i.name << "\tбаллы:\t" << i.score << endl;
    }

    return 0;
}

