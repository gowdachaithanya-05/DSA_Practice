#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int euclid(int m, int n);
int recursive(int m, int n);
int middle_school(int m, int n);
int consecutive_integer(int m, int n);
int rem = 0, res = 0;

int main()
{
    int m, n;
    clock_t start, end;
    double cpu_time_used;
    cout << "Enter the first number: ";
    cin >> m;
    cout << "Enter the second number: ";

    cin >> n;
        cout << fixed << setprecision(6);

    if(n != 0 && m != 0)
    {
        start = clock();
        res = euclid(m, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        cout << "1. Euclidean Method \n GCD = " << res << ", Runtime: " << cpu_time_used << " seconds\n";

        start = clock();
        res = recursive(m, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        cout << "2. Recursive Method \n GCD = " << res << ", Runtime: " << cpu_time_used << " seconds\n";

        start = clock();
        res = middle_school(m, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        cout << "3. Middle School Method \n GCD = " << res << ", Runtime: " << cpu_time_used << " seconds\n";

        start = clock();
        res = consecutive_integer(m, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        cout << "4. Consecutive Integer Method \n GCD = " << res << ", Runtime: " << cpu_time_used << " seconds\n";
    }
    else
        cout << "Invalid inputs!\n";
    return 0;
}

int euclid(int m, int n)
{
    while(n != 0)
    {
        rem = m % n;
        m = n;
        n = rem;
    }    
    return m;
}

int recursive(int m, int n)
{
    rem = m % n;
    if(rem == 0)
        return n;
    else
        return recursive(n, rem);
}

int middle_school(int m, int n)
{
    int gcd = 1;

    int min = (m < n) ? m : n;

    for (int i = 2; i <= min; ++i)
    {
        while (m % i == 0 && n % i == 0)
        {
            gcd *= i;
            m /= i;
            n /= i;
        }
    }

    return gcd;
}

int consecutive_integer(int m, int n)
{
    int min = (m < n) ? m : n;
    while(min != 0)
    {
        if(m % min == 0)
        {
            if(n % min == 0)
                return min;
            else
                min--;
        }
        else
            min--;
    }
    return 1;
}
