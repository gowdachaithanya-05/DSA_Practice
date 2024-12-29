//first method
#include <iostream>
using namespace std;
int gcd(int m, int n){
    int rem = 0;
    while(n>0){
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}
 
int main() {
    // Write C++ code here
    int m, n ;
    cin >> m >> n;
    int res = gcd(m,n);
    cout << "The gcd is : "<< res;
    return 0;
}


//2. second method
#include <iostream>
using namespace std;
int gcd(int n1, int n2){
   int gcd = 1;
   for(int i=1 ; i< min(n1,n2); i++){
    if(n1 % i ==0 && n2%i==0){
        gcd =i;
    }
   }
   return gcd;
}
 
int main() {
    // Write C++ code here
    int m, n ;
    cin >> m >> n;
    int res = gcd(m,n);
    cout << "The gcd is : "<< res;
    return 0;
}