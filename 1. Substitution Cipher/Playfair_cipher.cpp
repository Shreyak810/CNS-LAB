#include <bits/stdc++.h>
using namespace std;
#define SIZE 30

// Convert all characters of a string to lowercase
void toLowerCase(char plain[], int ps)
{
    for (int i = 0; i < ps; i++)
    {
        if (plain[i] > 64 && plain[i] < 91)
            plain[i] += 32;
    }
}

// Remove all spaces in a string
int removeSpaces(char *plain, int ps)
{
    int count = 0;
    for (int i = 0; i < ps; i++)
        if (plain[i] != ' ')
            plain[count++] = plain[i];
    plain[count] = '\0';
    return count;
}

// Generate the 5x5 key square
void generateKeyTable(char key[], int ks, char keyT[5][5])
{
    int dicty[26] = {0};

    for (int i = 0; i < ks; i++)
    {
        if (key[i] != 'j')
            dicty[key[i] - 97] = 2;
    }
    dicty['j' - 97] = 1;

    int i = 0, j = 0;
    for (int k = 0; k < ks; k++)
    {
        if (dicty[key[k] - 97] == 2)
        {
            dicty[key[k] - 97] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    for (int k = 0; k < 26; k++)
    {
        if (dicty[k] == 0)
        {
            keyT[i][j] = (char)(k + 97);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
}

// Search for the characters of a digraph in the key square and return their position
void search(char keyT[5][5], char a, char b, int arr[])
{
    if (a == 'j')
        a = 'i';
    if (b == 'j')
        b = 'i';

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyT[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyT[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

// Function to find the modulus with 5
int mod5(int a)
{
    return (a < 0) ? (a + 5) % 5 : a % 5;
}

// Function to encrypt the plaintext
void encrypt(char str[], char keyT[5][5], int ps)
{
    int a[4];
    for (int i = 0; i < ps; i += 2)
    {
        search(keyT, str[i], str[i + 1], a);

        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][mod5(a[1] + 1)];
            str[i + 1] = keyT[a[2]][mod5(a[3] + 1)];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[mod5(a[0] + 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

// Function to decrypt the ciphertext
void decrypt(char str[], char keyT[5][5], int ps)
{
    int a[4];
    for (int i = 0; i < ps; i += 2)
    {
        search(keyT, str[i], str[i + 1], a);

        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][mod5(a[1] - 1)];
            str[i + 1] = keyT[a[2]][mod5(a[3] - 1)];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[mod5(a[0] - 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] - 1)][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

// Function to call encryption
void encryptByPlayfairCipher(char str[], char key[])
{
    char keyT[5][5];
    int ps = strlen(str);
    int ks = strlen(key);

    ks = removeSpaces(key, ks);
    toLowerCase(key, ks);

    toLowerCase(str, ps);
    ps = removeSpaces(str, ps);

    if (ps % 2 != 0)
    {
        str[ps++] = 'x'; // Add 'x' to handle odd length
        str[ps] = '\0';
    }

    generateKeyTable(key, ks, keyT);
    encrypt(str, keyT, ps);
}

// Function to call decryption
void decryptByPlayfairCipher(char str[], char key[])
{
    char keyT[5][5];
    int ps = strlen(str);
    int ks = strlen(key);

    ks = removeSpaces(key, ks);
    toLowerCase(key, ks);

    toLowerCase(str, ps);
    ps = removeSpaces(str, ps);

    generateKeyTable(key, ks, keyT);
    decrypt(str, keyT, ps);

    // Remove the padding 'x' if it was added during encryption
    if (ps > 1 && str[ps - 1] == 'x')
    {
        str[ps - 1] = '\0';
    }
}

// Driver code
int main()
{
    char str[SIZE], key[SIZE];

    string text;
    cout << "Enter plaintext : ";
    cin >> text;
    string k;
    cout << "Enter key : ";
    cin >> k;

    // Key
    strcpy(key, k.c_str());
    cout << "Key: " << key << endl;

    // Plaintext to be encrypted
    strcpy(str, text.c_str());
    cout << "Plaintext: " << str << endl;

    // Encrypt using Playfair Cipher
    encryptByPlayfairCipher(str, key);
    cout << "Ciphertext: " << str << endl;

    // Decrypt the ciphertext
    decryptByPlayfairCipher(str, key);
    cout << "Decrypted text: " << str << endl;

    return 0;
}