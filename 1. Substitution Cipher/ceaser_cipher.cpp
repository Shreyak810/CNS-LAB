#include <iostream>
using namespace std;

// Function to encrypt the plaintext
string encrypt(string text, int s)
{
    string result = "";

    // Traverse the text
    for (int i = 0; i < text.length(); i++)
    {
        // Encrypt uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);

        // Encrypt lowercase letters
        else if (islower(text[i]))
            result += char(int(text[i] + s - 97) % 26 + 97);
        else
            result += text[i]; // Leave non-alphabet characters as is
    }

    return result;
}

// Function to decrypt the ciphertext
string decrypt(string text, int s)
{
    string result = "";

    // Traverse the text
    for (int i = 0; i < text.length(); i++)
    {
        // Decrypt uppercase letters
        if (isupper(text[i]))
            result += char((int(text[i] - s - 65) + 26) % 26 + 65);

        // Decrypt lowercase letters
        else if (islower(text[i]))
            result += char((int(text[i] - s - 97) + 26) % 26 + 97);
        else
            result += text[i]; // Leave non-alphabet characters as is
    }

    return result;
}

// Driver program to test the above functions
int main()
{
    string text;
    cout << "Enter plaintext : ";
    cin >> text;
    int s;
    cout << "Enter shift key : ";
    cin >> s;

    // Encrypt the text
    string encrypted = encrypt(text, s);
    cout << "Text: " << text << endl;
    cout << "Shift: " << s << endl;
    cout << "Encrypted: " << encrypted << endl;

    // Decrypt the text
    string decrypted = decrypt(encrypted, s);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
