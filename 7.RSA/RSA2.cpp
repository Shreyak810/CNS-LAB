#include <iostream>
#include <cmath>
using namespace std;

// Calculate φ(n) for a given number n
int phi(int n) {
    int result = n;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

// Calculate gcd(a, b) using the Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Calculate a^b mod m using modular exponentiation
int modpow(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}

int main() {
    int p = 11; // First prime number
    int q = 13; // Second prime number
    int n = p * q;
    int phiN = (p - 1) * (q - 1);

    // Calculate e (public exponent) such that 1 < e < phiN and gcd(e, phiN) = 1
    int e = 2;
    while (e < phiN && gcd(e, phiN) != 1) {
        e++;
    }

    // Calculate d (private exponent) such that (d * e) % phiN = 1
    int d = 1;
    while ((d * e) % phiN != 1) {
        d++;
    }

    // Display public and private keys
    cout << "Public key: {" << e << ", " << n << "}" << endl;
    cout << "Private key: {" << d << ", " << n << "}" << endl;

    // Example message to encrypt and decrypt
    int m = 11;
    int c = modpow(m, e, n);         // Encrypt message
    int decrypted = modpow(c, d, n); // Decrypt message

    // Display results
    cout << "Original message: " << m << endl;
    cout << "Encrypted message: " << c << endl;
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
