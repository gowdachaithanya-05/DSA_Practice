// C++ program to illustrate how create a simple class and
// object
#include <iostream>
#include <string>

using namespace std;

// Define a class named 'Person'
class Person {
public:
    // Data members
    string name;
    int age;

    // Member function to introduce the person
    void introduce()
    {
        cout << "Hi, my name is " << name << " and I am "
             << age << " years old." << endl;
    }
};

int main()
{
    // Create an object of the Person class
    int n;
    cout << "enter n : ";
    cin >> n;
    Person *person = new Person[n];  
    for(int i = 0; i<n; i++){
        cout << "enter the name and age of person "<< i+1 <<" : " <<endl;
        cin>> person[i].name >> person[i].age;
    }

   for (int i = 0 ; i<n; i++){
    person[i].introduce();
   }

   

    return 0;
}
