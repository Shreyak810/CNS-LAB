#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Function to compute (a^b) % p
long long power(long long a, long long b, long long p) {
    long long result = 1;
    a = a % p;  // Ensure 'a' is in the range [0, p-1]
    
    while (b > 0) {
        // If b is odd, multiply 'a' with the result
        if (b % 2 == 1)
            result = (result * a) % p;

        // Divide b by 2
        b = b / 2;

        // Square 'a'
        a = (a * a) % p;
    }
    return result;
}

// Diffie-Hellman key exchange
void diffie_hellman(long long q, long long alpha) {
    // Both parties choose their private keys (a and b)
    long long a = rand() % (q-2) + 1;  // Alice's private key
    long long b = rand() % (q-2) + 1;  // Bob's private key

    // Calculate public keys (A = alpha^a % q and B = alpha^b % q)
    long long A = power(alpha, a, q);  // Alice's public key
    long long B = power(alpha, b, q);  // Bob's public key

    // Each party computes the shared secret key
    long long shared_secret_alice = power(B, a, q);  // Alice computes the shared secret
    long long shared_secret_bob = power(A, b, q);    // Bob computes the shared secret

    cout << "Alice's Public Key (A): " << A << endl;
    cout << "Bob's Public Key (B): " << B << endl;
    cout << "Alice's Shared Secret: " << shared_secret_alice << endl;
    cout << "Bob's Shared Secret: " << shared_secret_bob << endl;

    // Both shared secrets should match
    if (shared_secret_alice == shared_secret_bob) {
        cout << "Shared secret successfully established!" << endl;
    } else {
        cout << "Error: Shared secrets do not match!" << endl;
    }
}


int main() {
    // Prime number p and generator g
    long long q = 23;  // Example prime number
    long long alpha = 5;   // Example primitive root

    // Perform Diffie-Hellman key exchange
    diffie_hellman(q, alpha);

    return 0;
}
