#include <iostream> // for std::cout
#include <cmath>
#include <vector>
#include <string>
#include <math.h>


using namespace std;

int add(int a, int b);

int add(int a, int b) {
    return a + b;
}

double add(double a, double b){
    return a + b;
}

double calculateDistance(int x1, int y1, int x2, int y2){
    return sqrt( pow(y2 - y1,2) + pow(x2 - x1, 2) ) ;
}

void incrementByValue(int x) {
    x = x + 1; // Increments copy x
}

void incrementByReference(int& x) {
    x = x + 1 ;// Increment reference aka the original 
}
int main()
{
    // int age = 25;
    // double price = 19.99;
    // char grade = 'A';
    // bool isStudent = true;
    // std::string name = "Alice";
    // char names[] = "Alice";


    // cout << "Enter your name " << names << " " << name <<endl <<"\n";
    // cin >> name;
    // cout  << "Enter your age"<<"\n";
    // cin >> age;

    // cout << "Hello " << name << ", you look amazing for " << age ;

    // for (int i = 1; i <= 5; i++){
    //     cout << i << " ";
    // }
    
    // string fruits[] = {"apple", "banana", "orange"};

    // cout << fruits[2] << endl;

    // vector<int> numbers;
    // numbers.push_back(10);
    // numbers.push_back(20);

    // cout << numbers.size() << endl;
    // cout << numbers[0] << endl;

    // for (int num : numbers ) {
    //     cout << num << " ";
    // }

    // numbers.pop_back();

    // string greeting = "Hello";
    // string name = "World";

    // string message = greeting + " " + name + "!";

    // cout << message.length() << endl;
    // cout << message[0] << endl;

    // cout << message.substr(0, 5);
    // cout << message.find("World");
    // cout << message.replace(6, 5, "C++");

    // string fullName;

    // getline(cin, fullName);

    // if (fullName.length() > 0) {
    //     cout << fullName;
    // }
    
    // int num = 3;

    // cout << calculateDistance(0, 0, 20, 20) << endl;
    // cout << add(4, 3) << endl;
    // cout << add(3.2, 2.3)<< endl;
    
    // incrementByValue(num);

    // cout << num << endl;

    int value = 30;
    int * ptr = &value;

    cout << "Value: " << value << endl; // 30
    cout << "Address: " << &value << endl; // address of where 30 is stored
    cout << "Pointer: " << ptr << endl; // address 
    cout << "Dereferenced: " << *ptr << endl; // 30

    value = 25; 
    cout << "Value: " << value << endl;

    *ptr = 20;
    cout << "Dereferenced Pointer Value: " << *ptr << endl;
    return 0;
}
