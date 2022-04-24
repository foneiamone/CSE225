/*
Write a function that checks if a number is prime or not.
If the number is prime the function returns true, otherwise false.
*/

#include <iostream>

using std::cin;
using std::cout;

bool isPrime(int n)
{
    if (n == 2 || n % 2 != 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    (isPrime(num)) ? cout << "Prime." : cout << "Not Prime.";
}