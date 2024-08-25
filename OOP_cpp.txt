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

