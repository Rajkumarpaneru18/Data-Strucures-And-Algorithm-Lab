/*Find the fibonacci number for given term N*/

#include <iostream>
using namespace std;
long int fibonacci(long int n)
{
    if (n == 1)
    { // base case
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);//recursive call
    }
}

int main()
{
    long int n;
    cout << "Enter any number: " << endl;
    cin >> n;
    cout << "Fibonacci Number Of " << n << " is: " << fibonacci(n);
    return 0;
}