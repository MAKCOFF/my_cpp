/* Работа с файлами. Создание, запись, чтение */
// fstream - чтение/сохранение данных
// ifstream - чтение
// ofsteaam - запись

/* Создание, запись
ofstream fout;

// fout.open(path);
fout.open(path,ofstream::app); // добавление данных без затирания

if (!fout.is_open()){
    cout << "Ошибка открытия файла!" << endl;
}else{
    for (int  i =0; i < 5; i++) {
        cout << "Введите число" << endl;
        int a;
        cin >> a;
        fout << a;
        fout << "\n";
    }
}

fout.close();*/

/* Чтение
ifstream fin;
fin.open(path);

if (!fin.is_open()) {
    cout << "Ошибка открытия файла!" << endl;
}
else {
    cout << "Файл открыт!" << endl;

    // По байтам
    //char ch;
    //while (fin.get(ch)){
    //    cout << ch;
    //}

    // Целиком строкой
    string str;
    while (!fin.eof()) {
        str = "";
        getline(fin, str);
        //fin >> str;
        cout << str << endl;
    }
}

fin.close();*/

/*class Point {
public:
    
    Point() { x = y = z = 0; }

    Point(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void Print() { cout << "X: " << x << "\tY: " << y << "\tZ: " << z << endl; }

    int x;
    int y;
    int z;
};
int main() {

    setlocale(LC_ALL, "ru");

    string path = "my_file.txt";

    // Сохранение класса в файл
    Point point(255, 120, 456);
    //point.Print();

    ofstream fout;

    fout.open(path, ofstream::app); // добавление данных без затирания

    if (!fout.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт!" << endl;
        fout.write((char*)&point, sizeof(Point));
    }

    fout.close();

    // Чтение класса из файла
    ifstream fin;
    fin.open(path);

    if (!fin.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт!" << endl;
        Point pnt;
        while (fin.read((char*)&pnt, sizeof(Point))) {
            pnt.Print();
        }
    }

    fin.close();

    return 0;
}
*/

/* fstream - чтение/сохранение данных
int main() {

    setlocale(LC_ALL, "ru");

    string path = "my_file.txt";

    fstream fs;//флаги чтения         записи      добавления
    fs.open(path, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    }else{
        string msg;
        int value;
        cout << "Файл открыт!" << endl;
        cout << "Нажмите 1 для записи сообщения в файл:" << endl;
        cout << "Нажмите 2 для чтения всех сообщений из файла:" << endl;
        cin >> value;
        if (value == 1){
            cout << "Введите ваше сообщение:" << endl;
            SetConsoleCP(1251);
            cin >> msg;
            fs << msg << "\n";
            SetConsoleCP(866);
        }
        if (value == 2) {
            cout << "Чтение данных из файла:" << endl;
            while (!fs.eof()) {
                msg = "";
                fs >> msg;
                cout << msg << endl;
            }
        }
    }
    fs.close();

    return 0;
}
*/

/* перегрузка операторов потокового ввода вывода

class Point {
public:

    Point() { x = y = z = 0; }

    Point(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
private:
    int x;
    int y;
    int z;

    friend ostream& operator << (ostream& os, const Point& point);
    friend istream& operator >> (istream& is, Point& point);
};

ostream& operator << (ostream& os, const Point& point) {

    os << point.x << " " << point.y << " " << point.z;

    return os;
}

istream& operator >> (istream& is, Point& point) {

    is >> point.x >> point.y >> point.z;

    return is;
}

int main() {

    setlocale(LC_ALL, "ru");

    string path = "my_file.txt";

    Point p(212, 7, 44);

    //cout << p;

    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт!" << endl;
        //fs << p << "\n";

        while (true) {
            Point point;
            fs >> point;
            if (fs.eof())            {
                break;
            }
            cout << point << endl;
        }
    }
    fs.close();


    return 0;
}
*/

/* Обработка исключений try, catch
int main() {

    setlocale(LC_ALL, "ru");

    string path = "my_file.tx";

    ifstream fin;
    fin.exceptions(ifstream::badbit | ifstream::failbit);

    try{
        fin.open(path);
        cout << "Файл открыт" << endl;
    }
    catch (const ifstream::failure & ex){
        cout << ex.what() << endl;
        cout << ex.code() << endl;
        cout << "Ошибка открытия файла!" << endl;
    }





    return 0;
}*/

/* throw 
void Foo(int value) {

    if (value<0){ throw exception("число меньше 0!!!"); }

    cout << "Переменная = " << value << endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    try{
        Foo(-55);
    }
    catch (const exception &ex){
        cout << "Мы поймали " << ex.what() << endl;
    }

    return 0;
}
*/

/* Несколько блоков catch
void Foo(int value) {

    if (value<0){ throw "число меньше 0 !!!"; }

    if (value == 0) { throw exception("число равно 0 !!!"); }

    if (value == 1) { throw 1; }

    cout << "Переменная = " << value << endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    try{
        Foo(1);
    }
    catch (const exception &ex){
        cout << "Блок 1 Мы поймали " << ex.what() << endl;
    }
    catch(const char *ex){
        cout << "Блок 2 Мы поймали " << ex << endl;
    }
    catch (...) {
        cout << "Что то пошло не так!" << endl;
    }

    return 0;
}
*/

/* Создание собственного класса исключений
class MyException : public exception {
public:
    MyException(const char *msg, int dataState):exception(msg) {
        this->dataState = dataState;
    }
    int GetDataState() { return dataState; }
private:
    int dataState;
};

void Foo(int value) {

    if (value < 0) { throw exception("число меньше 0 !!!"); }

    if (value == 1) { throw MyException("число равно 1 !!!",value); }

    cout << "Переменная = " << value << endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    try{
        Foo(-1);
    }
    catch (MyException &ex){
        cout << "Блок 1 Мы поймали " << ex.what() << endl;
        cout << "Состояние данных " << ex.GetDataState() << endl;
    }
    catch (exception& ex) {
    cout << "Блок  Мы поймали " << ex.what() << endl;
    }

    return 0;
}
*/ 