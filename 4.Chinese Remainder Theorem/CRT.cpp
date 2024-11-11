#include <iostream>
#include <vector>
using namespace std;

// Function to find the greatest common divisor (GCD)
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find the modular inverse of 'a' with respect to 'm' using the extended Euclidean algorithm
int modInverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclidean algorithm
    while (a > 1)
    {
        q = a / m;
        t = m;

        // m is remainder now, process the same as Euclid's algorithm
        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to find the smallest x that satisfies the system of congruences
int findMinX(vector<int> &num, vector<int> &rem, int k)
{
    // Compute product of all numbers (moduli)
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    int result = 0;

    // Apply the formula to find x
    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main()
{
    int k;
    cout << "Enter the number of equations (value of k): ";
    cin >> k;

    vector<int> num(k), rem(k);

    cout << "Enter the values of remainders a1, a2, ..., ak: ";
    for (int i = 0; i < k; i++)
    {
        cin >> rem[i];
    }

    cout << "Enter the values of moduli m1, m2, ..., mk: ";
    for (int i = 0; i < k; i++)
    {
        cin >> num[i];
    }

    int x = findMinX(num, rem, k);
    cout << "The smallest value of x is: " << x << endl;

    return 0;
}
