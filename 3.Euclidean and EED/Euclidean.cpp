#include <bits/stdc++.h>
using namespace std;

// Function to return
// gcd of a and b
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

// Driver Code
int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // Function call
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
         << endl;
}
