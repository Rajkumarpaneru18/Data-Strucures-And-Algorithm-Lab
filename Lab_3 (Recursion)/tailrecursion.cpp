/*Use tail recursion to find the factorial and fibonacci number of a given number
'N' */
#include <iostream>
using namespace std;

// tail recursion to find factorial
long int tailfactorial(int n, long int result = 1)
{
    if (n == 0)
    {
        return result;
    }
    return tailfactorial(n - 1, n * result);
}

// tail recursion to find the fibonacci number
long int tailfibonacci(long int n, long int a = 0, long int b = 1)
{
    if (n == 0)
    {
        return a;
    }
    else if (n == 1)
    {
        return b;
    }
    else
    {
        return tailfibonacci(n - 1, b, a + b);
    }
}
int main()
{
    // for factorial
    long int n;
    cout << "Enter any number to find it's factorial : " << endl;
    cin >> n;
    cout << tailfactorial(5) << endl;

    // for fibonacci
    long int m;
    cout << "Enter any number to find it's fibonacci number : " << endl;
    cin >> m;
    cout << tailfibonacci(5);
    return 0;
}