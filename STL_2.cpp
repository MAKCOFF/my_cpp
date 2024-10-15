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

    //vector<int> v = {9,4,94,6,1,3,7};

    //auto result = find(v.begin(),v.end(),0);
    //
    //if (result == v.end()){
    //    cout << "Is found nothing" << endl;
    //}else{
    //    cout << "Is found!" << endl;
    //}

    //auto result = find_if(v.begin(),v.end(), [](int a){
    //    //return  a % 2 == 0;  // проверка на четность
    //    //return  a % 2 != 0;  // проверка на нечетность
    //    //return  a < 0;
    //    return  a > 0;
    //});
    //
    //if (result == v.end()){
    //    cout << "Is found nothing!" << endl;
    //}else{
    //    cout << "Is found!" << endl;
    //}

    //auto result = find_if_not(v.begin(),v.end(), [](int a){
    //    //return  a % 2 == 0;  // проверка на четность
    //    //return  a % 2 != 0;  // проверка на нечетность
    //    return  a < 0;
    //    //return  a > 0;
    //});
    //
    //if (result == v.end()){
    //    cout << "Is found nothing!" << endl;
    //}else{
    //    cout << "Is found!" << endl;
    //}

    auto  result = find_if(people.begin(),people.end(), [](const Person &p) {
        //return p.name == "Masha";
        //return p.score == 10 && p.name == "Petya";
        return p.score == 11 || p.name == "Sergey";
    });

    if (result == people.end()){
        cout << "Is found nothing!" << endl;
    }else{
        cout << "Is found!" << endl;
    }

    return 0;
}
*/

/* STL Поиск
    std::copy, std::copy_if

 #include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class Person{
public:
    Person(string name, double score, int age){
        this->name = name;
        this->score = score;
        this->age = age;
    }

    bool operator()(const Person &p){
        return p.score > 180;
    }

    string name;
    double score;
    int age;
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    vector<Person> people {
            Person("Vasya", 181, 20),
            Person("Petya", 30, 30),
            Person("Masha", 179, 45),
            Person("Dasha", 200, 22),
            Person("Katya", 198, 25),
            Person("Andrey", 50, 53),
            Person("Sergey", 150, 33),
            Person("Ivan", 129, 31),
            Person("Petya", 10, 42)
    };

    vector<Person> result;

    //copy(people.begin(),people.end(), back_inserter(result));

    copy_if(people.begin(),people.end(), back_inserter(result), [](const Person &p){
        //return p.name == "Ivan";
        //return p.score < 100;
        //return p.age > 25 && p.score > 140;
        return p.age > 25;
    });

    sort(result.begin(),result.end(),[](const Person &p1, const Person &p2){
        return p1.age < p2.age;
    });

    cout << "Всего элементов: \t" << result.size() << endl;
    for (auto i : result) {
        cout << "Имя: " << i.name << "\tбаллы: " << i.score <<"\tвозраст: " << i.age << endl;
    }

    return 0;
}

*/

/* STL Поиск
  Удаление элемента
    std::remove, std::remove_if

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class Person{
public:
    Person(string name, double score, int age){
        this->name = name;
        this->score = score;
        this->age = age;
    }

    bool operator()(const Person &p){
        return p.score > 180;
    }

    string name;
    double score;
    int age;
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    vector<Person> people {
            Person("Vasya", 181, 20),
            Person("Petya", 30, 30),
            Person("Masha", 179, 45),
            Person("Dasha", 200, 22),
            Person("Katya", 198, 25),
            Person("Andrey", 50, 53),
            Person("Sergey", 150, 33),
            Person("Ivan", 129, 31),
            Person("Petya", 10, 42)
    };

    vector<int> v = {5,9,1,46,4,9,4};
    // Возвращает итератор на первый элемент в коллекции для удаления
    auto res = remove(v.begin(),v.end(),9);
    v.erase(res, v.end());


    people.erase(remove_if(people.begin(), people.end(), [](const Person &p){
        return p.score < 150 || p.age > 25;
    }), people.end());

    cout << "Всего элементов:\t" << people.size() << endl;

    for (const auto& i : people) {
        cout << "Имя: " << i.name << "\tбаллы: " << i.score <<"\tвозраст: " << i.age << endl;
    }

    string str = "Текст с несколькими   пробелами!";
    cout << str << endl;

    str.erase(remove(str.begin(),str.end(), ' '), str.end());

    cout << str << endl;


    return 0;
}
*/

/* STL
    Поиск наибольшего элемента

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <windows.h>

using namespace std;



int main() {
    SetConsoleOutputCP(CP_UTF8);

    vector<int> v = {10,1,-55,11,13,58};

    list<int> lst = {4,7,77,-3,44,74};

    const int SIZE = 6;

    int arr[SIZE] = {10,1,-55,11,13,58};

    auto res = max_element(v.begin(), v.end());

    auto result = max_element(lst.begin(), lst.end());

    auto result2 = max_element(arr,arr+SIZE);

    cout << *result2 << endl;

    return 0;
}
*/

/* STL
    Поиск наименьшего элемента и гибридный мин-макс

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <windows.h>

using namespace std;



int main() {
    SetConsoleOutputCP(CP_UTF8);

    vector<int> v = {10,1,-55,11,13,58};

    list<int> lst = {4,7,77,-3,44,74};

    const int SIZE = 6;

    int arr[SIZE] = {10,1,-55,11,13,58};

    //auto result = min_element(arr,arr+SIZE);

    //auto result = min_element(v.begin(),v.end());

    auto result = minmax_element(lst.begin(),lst.end());

    cout << *result.second << "\t" << *result.first << endl;

    return 0;
}
*/

/* STL
    Сумма элементов, произведение, сумма четных элементов и т.д.

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <windows.h>

using namespace std;



int main() {
    SetConsoleOutputCP(CP_UTF8);

    //vector<int> v = {2,3,4};
    int v []= {2,3,4};

    // 3‑й параметр, для суммы - стартовое значение, к которому прибавить результат суммы всех элементов
    //auto result = accumulate(begin(v),end(v), 0);

    // 3-й параметр в 1 для умножения элементов между собой, 4-й параметр ручное определение работы алгоритма
    auto result = accumulate(begin(v),end(v), 0, [](int a, int b){
        //return a * b;

        if (b%2 == 0){
            return a + b;
        }else{
            return a;
        }
    });

    auto result2 = accumulate(next(begin(v)),end(v), to_string(v[0]), [](string a, int b){
        return a + "-" + to_string(b);
    });

    cout << result2 << endl;

    return 0;
}
*/

/* STL
    Сравнить две последовательности - equal и mismatch


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include <windows.h>

using namespace std;



int main() {
    SetConsoleOutputCP(CP_UTF8);



    return 0;
}