

#include <ctime>
#include <string>

#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include "include/Image.hpp"

void test(){
    std::cout << "coucou" << std::endl;
    int number = 0;
    std::cin >> number;
}

void mean() {
    std::cout << "entre 5 nombre" << std::endl;
    int sum = 0;
    int a = 0;
    for(int i = 0; i < 5; i++){
        std::cin >> a;
        sum += a;
    }
    std::cout << "Mean: " << sum / 5 << std::endl;
}

void echangeA_B(){
    int A = 0;
    int B = 0;
    std::cout << "type A and B" << std::endl;
    std::cin >> A >> B;
    std::cout << "A:" << A << " B: " << B << std::endl;
    int C = A;
    A = B;
    B = C;
    std::cout << "A:" << A << " B: " << B << std::endl;
}

void bornes(){
    int number = 0;
    std::cout << "type number" << std::endl;
    std::cin >> number;
    if(number >= 10 && number <= 20){
        std::cout << "win" << std::endl;
    } else {
        std::cout << "lose" << std::endl;
    }
}

void strings(){
    try
    {
        std::string name = "name";
        std::cout << name.at(556) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "error captured" << std::endl;
    }
}

void tab(){
    int size = 10;
    int tab[size];
    int a = 0;
    for(int i = 0; i < 10; i++){
        int number = 0;
        std::cin >> number;
        tab[i] = number;
        if(number >= 10)
            a++;
    }
    std::cout << "nb entier >= 10: " << a << std::endl; 

    int V = 0; std::cin >> V; bool found = false;
    for(int i = 0; i < size; i++) {
        if(tab[i] == V){
            found = true;
        }
    }
    if(found)
        std::cout << "V:" << V << " is in the tab" << std::endl;
    else
        std::cout << "V:" << V << " is NOT in the tab" << std::endl;
}

void removeFromTab(){
    //ex4 tab

    int tab[6] = {1, 2, 3, 4, 5, 6};
    int V = 0;
    std::cin >> V;

    for(int i = 0; i < 6; i++){
        if(tab[i] == V){
            int index = i;
            while(index < 5){
                tab[index] = tab[index + 1];
                index ++;
            }
            tab[index] = 0;
            break;
        }
       
        // std::cout << i << std::endl;
    }

    for (int i = 0; i < 6; i++) {
        std::cout << tab[i] << " ";  // Print each element
    }
}

void biggestElementTab(){
    int tab[7] = {1, 2, 3, 4, 12, 5, 6};
    int index = 0;
    for(int i = 0; i < 6; i++) {
        if(tab[i + 1] >= tab[index])
            index = i + 1;
    }
    std::cout << "biggest at index: " << index << std::endl;
}

void displayTab(int tab[], int size){
    std::cout << "{";
    for(int i = 0; i < size; i++){
        std::cout << tab[i] << " ";
    }
    std::cout << "}" << std::endl;
}

void insertAndDecale(){
    int tab[10];
    for(int i = 0; i < 10; i++){
        std::cin >> tab[i];
    }
    std::cout << "Enter V:" <<std::endl;
    int V;
    std::cin >> V;
    std::cout << "Enter index between 0 and 9: " << std::endl;
    int index;
    std::cin >> index;

    int current_index = 9;
    while(current_index != index){
        tab[current_index] = tab[current_index - 1];
        current_index--;
    }
    tab[index] = V;
    displayTab(tab, 10);
}

int* createTab(int size){
    int* array = new int[size];
    for(int i = 0; i < 10; i++){
        std::cin >> array[i];
    }
    return array;
}

void analyseTab(){
    int * array = createTab(10);

    bool croissant = true;
    bool decroissant = true;
    bool constant = true;

    for(int i = 0; i < 10 - 1; i++){
        int value = array[i];
        if(array[i + 1] > array[i] && decroissant == true){
            decroissant = false;
            constant = false;
        } else if(array[i + 1] < array[i] && croissant == true){
            croissant = false;
            constant = false;
        } 
    }
    if(constant){
        std::cout << "array constant" << std::endl;
    } else if(croissant || decroissant){
        std::cout << (croissant ? "croissant": "decroissant") << std::endl;
    } else {
        std::cout << "array random" << std::endl;
    }

    delete[] array;
}

class Base {
    public:
      virtual void print() {
         std::cout << "Base Function" << std::endl;
     }
    
 };
 
 class Derived : public Base {
    public:
     void print() override {
         std::cout << "Derived Function" << std::endl;
     }
 };

 void testVirtual(){
    // https://www.programiz.com/cpp-programming/virtual-functions
    Derived derived1;

    // pointer of Base type that points to derived1
    Base* base1 = &derived1;
    Base* bas = new Base();
    

    // calls member function of Derived class
    base1->print();
    bas->print();
    // derived1.Base::print();
    delete bas;
 }


// forward declaration
class ClassB;

class ClassA {
    
    public:
        // constructor to initialize numA to 12
        ClassA() : numA(12) {}
        
    private:
        int numA;
        
         // friend function declaration
         friend int add(ClassA, ClassB);
};

class ClassB {

    public:
        // constructor to initialize numB to 1
        ClassB() : numB(1) {}
    
    private:
        int numB;
 
        // friend function declaration
        friend int add(ClassA, ClassB);
};

// access members of both classes
int add(ClassA objectA, ClassB objectB) {
    return (objectA.numA + objectB.numB);
}

void testFriend(){
    ClassA objectA;
    ClassB objectB;
    std::cout << "Sum: " << add(objectA, objectB) << std::endl;
}

class Complex {
    private:
        float real;
        float img;

    public:
         // constructor to initialize real and img to 0
         Complex() : real(0), img(0) {}
         Complex(float real, float img) : real(real), img(img){}

       // overload the + operator
         friend Complex operator + (const Complex& obj1, const Complex& obj2) {
            //this function has access to attributes of obj1 and obj2
             Complex temp;
              temp.real = obj1.real + obj2.real;
              temp.img = obj1.img + obj2.img;
              return temp;
    }
            friend Complex operator - (const Complex& obj1, const Complex& obj2) {
                Complex temp;
                temp.real = obj1.real - obj2.real;
                temp.img = obj1.img - obj2.img;
                return temp;
            }

    void display() {
        if (img < 0)
            std::cout << "Output Complex number: " << real << img << "i" << std::endl;
      else
           std::cout << "Output Complex number: " << real << "+" << img << "i" << std::endl;
    }
};

class Count {
    private:
        int value;
    public:
        Count() : value(5)
        {}
        void operator ++(){
            ++value;
            
        }
        void display(){
            std::cout << "Value: " << value << std::endl;
        }
};

void testOperatorOverloading(){
    Complex c1(1.0f, 2.0f);
    Complex c2(1.0f, 3.0f);

    // calls the overloaded + operator
    Complex result = c1 + c2;
    result.display();
    Complex result2 = c1 - c2;
    result2.display();

    Count count;
    ++count;
    count.display();

}

// base class
class Animal {
    public:
         /*virtual*/void info() {
            std::cout << "I am an animal." << std::endl;
        }
        //pure virtual function, implementation depends on derived classes
        virtual void move() = 0;
    };
    
    // derived class 1
    class Dog : public Animal {
    public:
        void bark() {
            std::cout << "I am a Dog. Woof woof." << std::endl;
        }
        void info() /*override*/{
            std::cout << "Info dog" << std::endl;
        }
        void move() override {
            std::cout << "dog moves" << std::endl;
        }
    };
    
    // derived class 2
    class Cat : public Animal {
    public:
        void meow() {
            std::cout << "I am a Cat. Meow." << std::endl;
        }
        void move() override {
            std::cout << "Cat moves" << std::endl;
        }
    };

void testHierarchicalInheritance(){
     // create object of Dog class
     Dog dog1;
     std::cout << "Dog Class:" << std::endl;
     dog1.info();  // parent Class function
     dog1.bark();
     dog1.move();

     // create object of Cat class
     Cat cat1;
     std::cout << "\nCat Class:" << std::endl;
     cat1.info();  // parent Class function
     cat1.meow();
     cat1.move();

     Dog dog2;
     Animal* animal = &dog2;
     animal->info(); //add virtual to display info dog
}

std::vector<int> fusionVector(const std::vector<int> & vec1, const std::vector<int>& vec2) {
    std::vector<int> mergedVector;
    int i = 0, j = 0;
    while(i < vec1.size() && j < vec2.size()) {
        if(vec1.at(i) < vec2.at(j)){
            mergedVector.push_back(vec1.at(i));  
                i++;
            
        } else {
            mergedVector.push_back(vec2.at(j));
                j++;
            
        }
        std::cout << i <<std::endl;
        std::cout << j <<std::endl;
        std::cout << std::endl;
    }
    // for (int num : mergedVector) std::cout << num << " ";
    // std::cout << std::endl;
   
   
        while(j < vec2.size()){
            mergedVector.push_back(vec2.at(j));
            j++;
        
        }
        while(i < vec1.size()){
            mergedVector.push_back(vec1.at(i));
            i++;
        }
    
    return mergedVector;
    }

// void splitVectorTest(){
//     std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7,9, 10};
//     int index_middle = vec.size() / 2;

//     std::vector<int> left(vec.begin(), vec.begin() + index_middle);
//     std::vector<int> right(vec.begin() + index_middle, vec.end());

//         // Print results
//         std::cout << "First part: ";
//         for (int num : left) std::cout << num << " ";
//         std::cout << "\nSecond part: ";
//         for (int num : right) std::cout << num << " ";
// }

std::vector<int> trifusion(std::vector<int>& vec){
    if(vec.size() == 1)
        return vec;
    //split
    int index_middle = vec.size() / 2;

    std::vector<int> left(vec.begin(), vec.begin() + index_middle);
  
    std::vector<int> right(vec.begin() + index_middle, vec.end());
   

    return fusionVector(trifusion(left), trifusion(right));
}

void testFusion(){
    // https://qkzk.xyz/docs/nsi/cours_terminale/algorithmique/diviser_pour_regner/tri_fusion/
    std::vector<int> vec1 = {1, 2 , 6, 10};
    std::vector<int> vec2 = {4, 8};

    for (int num : fusionVector(vec1, vec2)) std::cout << num << " ";
    std::cout << std::endl;
}

void testTriFusion(){
    std::vector<int> v = {1, 5 ,6, 1, 5, 4, 5, 6, 8};
    for (int num : trifusion(v)) std::cout << num << " ";
    std::cout << std::endl;
}

struct Person
{
    std::string Name;
    short Age;
};

void testRefValue()
{
   // Declare a Person object.
   Person myFriend;

   // Declare a reference to the Person object.
   Person& rFriend = myFriend;

   // Set the fields of the Person object.
   // Updating either variable changes the same object.
   myFriend.Name = "Bill";
   rFriend.Age = 40;

   // Print the fields of the Person object to the console.
   std::cout << rFriend.Name << " is " << myFriend.Age << std::endl;
}

void f(){
    // l'espace pour la variable statique n'est alloué qu'une seule fois, un seul count dans tout program
    static int count = 0;
    // The value will be updated and carried over
      // to the next function call
      count++;
      std::cout << count << " " << std::endl;
}

//take lvalue, lvalue reference
void PrintName(const std::string& name){
    std::cout << "[lvalue] " << name << std::endl;
}

//take rvalue, rvalue reference
void PrintName(const std::string&& name){
    std::cout << "[rvalue] " << name << std::endl;
}

void testRLValue(){
    //i lvalue, 2 rvalue (temporary value stored into i)
    int i = 2;
    //a lvalue, i lvalue
    int a = i;

    //lvalue
    std::string firstName = "Toto";
    std::string lastName  = "seraf";

    //firstName + lastName: rvalue (temporary value stored into fullName)
    //fullname: lvalue
    std::string fullName = firstName + lastName;

    PrintName(fullName);
    PrintName(firstName + lastName);
}

void testFile(){
    // Create and open a text file
    std::ofstream MyFile("filename.txt");
  
    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!" << std::endl;
    MyFile << "hello";
  
    // Close the file
    MyFile.close();

    // Create a text string, which is used to output the text file
    std::string myText;

    // Read from the text file
    std::ifstream MyReadFile("filename.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
      // Output the text from the file
      std::cout << myText << std::endl;
    }

    // Close the file
    MyReadFile.close(); 
}

template<typename T>
struct myStruct
{
    T a; //public by default
    myStruct(T val) : a(val)
    {}

    T getValue() const {
        return a;
    }

    T getValue(int b) { //surcharge de method/function
        return a + b;
    }

};

void testStruct(){

    myStruct<double> s(5.8);
    std::cout << "a: "<< s.getValue() << std::endl;
}

// Class template
template <class T, class U>
class Numbers {
   private:
    // Variables of type T and U
    T num1;
    U num2;
    

   public:
    Numbers(T n, U m) : num1(n), num2(m) {}   // constructor
    const static int a = 4;

    T getNum1() {
        return num1;
    }
    U getNum2() {
        return num2;
    }

};

void testTemplate(){
    Numbers<float, int> numbers(50.2, 3);
    std::cout << "num1 float: " << numbers.getNum1() << ", num2 int: " << numbers.getNum2()<< std::endl;
    std::cout << "static variable a: " << numbers.a << std::endl;
}

// Declare an abstract base class with a pure virtual destructor.
// It's the simplest possible abstract class.
class base
{
public:
    base() {}
    // To define the virtual destructor outside the class:
    virtual ~base() = 0;
    // Microsoft-specific extension to define it inline:
//  virtual ~base() = 0 {};
};

base::~base() {} // required if not using Microsoft extension

class derived : public base
{
public:
    derived() {}
    ~derived() {}
};

class A { 
    public: 
        A() 
        { std::cout << " Le constructeur de la classe A est appelé." << std::endl;  }
        ~A() 
        { std::cout << " Le destructor de la classe A est appelé." << std::endl;  }
        
   }; 
     
   class B { 
    public: 
        B() 
        { std::cout << " Le constructeur de la classe B est appelé." << std::endl;  } 
        ~B() 
        { std::cout << " Le destructor de la classe B est appelé." << std::endl;  } 
   }; 
     
   class C: public A, public B { 
      public: 
        C() 
        {  std::cout << " Le constructeur de la classe C est appelé." << std::endl;  } 
        ~C() 
        {  std::cout << " Le destructor de la classe C est appelé." << std::endl;  } 
   }; 
     
void testConstDest(){
    C c;
}

void testImage(){
    // https://www.youtube.com/watch?v=028GNYC32Rg

    Image test("test.jpg");
    // test.write("new.png");
    // Image copy = test;
    // for(int i = 0; i < copy.w*copy.channels; ++i) { //first row to white
    //     copy.data[i] = 255;
    // }
    // copy.write("copy.png");
    // Image blank(100, 100, 3);
    // blank.write("blank.jpg");

    // Image gray_avg = test;
    // gray_avg.grayscale_avg();
    // gray_avg.write("gray_avg.png");

    // Image gray_lum = test;
    // gray_avg.grayscale_lum();
    // gray_avg.write("gray_lum.png");

    test.colorMask(0,1,1);
    test.write("blue.png");
}

// Classe abstraite
class Forme {
    public:
        virtual double aire() const = 0; // Méthode virtuelle pure
        virtual void afficher() const { //virtual car si redefinie, va chercher la derniere version dans arbre
            std::cout << "Aire : " << aire() << std::endl;
        }
        // Destructeur virtuel pour appeler le destructeur des class derivés (si allocation memoire dans class derivées par ex, pour free)
        virtual ~Forme() { std::cout << "Destructeur forme" << std::endl; } 
    };

class Cercle : public Forme {
    private:
        double rayon;
    public:
        Cercle(double r) : rayon(r) {}
        ~Cercle() {std::cout << "Destructior Cercle" << std::endl; }
        double aire() const override {
            return 3.14 * rayon * rayon;
        }
        void afficher() const override { //redefinition
            std::cout << "Cercle - ";
            Forme::afficher();
        }
};

class Rectangle : public Forme {
private:
    double largeur, hauteur;
public:
    Rectangle(double l, double h) : largeur(l), hauteur(h) {}
    double aire() const override {
        return largeur * hauteur;
    }
};

//#pragma once permet au .h de ne pas etre inclu 2x par exemple lors d'heritages
void testForme() {
    Forme* f1 = new Cercle(5.0);      // Polymorphisme : un Cercle sous forme de Forme*
    Forme* f2 = new Rectangle(4.0, 6.0);

    f1->afficher();
    f2->afficher(); //"afficher" pas redefinie dans Rectangle

    delete f1;
    delete f2;
}

class Message {
    public:
        void afficher() const {
            std::cout << "Bonjour depuis le message partagé !" << std::endl;
        }
};

void testShared_ptr() {
    // Creation d'un shared_ptr, objet qui va être partagé sans faire de copies
    std::shared_ptr<Message> ptr1 = std::make_shared<Message>();
    
    //Utilisation pointer
    ptr1->afficher();

    //Creation d'un autre shared_ptr qui partage la même instance
    std::shared_ptr<Message> ptr2 = ptr1;

    std::cout << "Nombre de références : " << ptr1.use_count() << std::endl;

    //Les 2 pointers pointent vers le même objet
    ptr2->afficher();

}

int main(){
    // https://cpp.developpez.com/tutoriels/exercice-corriges-ihm-debutant/#LIV-A
    // Entity* e = new Entity();
    // https://www.tpointtech.com/virtual-function-in-java
    // https://www.programiz.com/cpp-programming/multilevel-multiple-inheritance
    // https://wiki.sfeir.com/carriere/recrutement/evaluation-algo/exemple_exercices_algo/
    // https://waytolearnx.com/2022/06/top-50-questions-dentretien-en-langage-cpp-partie-4.html
    
    testShared_ptr();
    return 0;
}

//exception
//lvalue, rvalue ?
//lvalue: have some storage back in them
//rvalue: temporary value stored into lvalue


//Inquietutde (que je ne trouve pas de travail) => volonté de tout controler
//DIfficile de remettre en question sa position (meme si louable souvent) et volonté de toujours avoir raison 
//Pense indéniablement que ma priorité devrait etre celle qu'elle pense (trouver un travail),
//ce n'est pas faux mais anéanti toute importance de mes autres activités (c'est du loisir et c'est tout)
//"Je ne travail soit disant plus autant qu'avant", etc... (Trad: je ne fais plus autant qu'elle voudrait que je fasse dans tel activité pour la rassurer suffisament)
//Créer du conflit et de la confusion et fit culpabiliser(tu n'es pas si malheureux, tu te donnes pas assez ...) un peu et réduit ma clarté pour construire mon projet.
//L'intention est bonne mais la manière de faire est maladroite malheureusement.
//Comprendre le mécanisme permet de prendre de la distance (pour ne pas agir dans la crainte de l'autre par exemple et d'acheter la paix) et de faire les choses plus lucidement, 
//L'impact sur le bien-être ensemble est non négligeable.
//anxiety et s'emballe facilement
//ecrire aussi ds carnet notes telephone