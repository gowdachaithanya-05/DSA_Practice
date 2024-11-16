#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    // int a,b,c;

    // cout <<"Enter a\n";
    // cin >> a;
    // cout <<"Enter b\n";
    // cin >>b;
    // c=a+b;
    // cout << "sum is: \n"<<c;
    // cout<< "\nglobal c value\n"<<::c;
    // float x=15;
    // float & y=x;
    // cout <<x<<endl;
    // cout<<y<<endl;
//  const int a= 34,b=3896,c=908;
//  cout << "value of a is: " <<setw(5)<<a<<endl;
//  cout << "value of a is: " <<setw(5)<<b<<endl;
//  cout << "value of a is: " <<setw(5)<<c<<endl;
//   cout << "value of a is" <<a<<endl;
//     cout << "value of a is" <<b<<endl;
//       cout << "value of a is" <<c<<endl;
//
// int a;
// cout<< "enter the age\n";
// cin>> a;
// if(a<18){
//     cout<<"no";

// }
// else if (a>=18)
// {
//     cout<<"yes";
// }
int age;
cout<<"age\n";
cin>>age;
switch (age)
{
case 19:
    /* code */
    cout<<"u r 19";
    break;
    case 21:
    /* code */
    cout<<"u r 21";
    break;

default:
cout<< "wrong selection";
    break;
}

return 0;
}