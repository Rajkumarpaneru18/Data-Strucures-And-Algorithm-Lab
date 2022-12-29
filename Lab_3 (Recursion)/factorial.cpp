/*Program to find the factorial of a number using recursion */
#include <iostream>
using namespace std;

long int factorial(long int n)
{
    if (n == 0)
    { // base case
        return 1;
    }
    else
    {
        return n * factorial(n - 1); // recursive call
    }
}
int main()
{
    long int n;
    cout << "Enter any integer :" << endl;
    cin >> n;
    cout << "The factorial of " << n << " is: " << factorial(n);
    return 0;
}