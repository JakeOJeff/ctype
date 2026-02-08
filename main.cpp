#include <iostream> // for std::cout
#include <vector>
using namespace std;
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
    
    string fruits[] = {"apple", "banana", "orange"};

    cout << fruits[2] << endl;

    vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);

    cout << numbers.size() << endl;
    cout << numbers[0] << endl;

    for (int num : numbers ) {
        cout << num << " ";
    }

    numbers.pop_back();

    return 0;
}