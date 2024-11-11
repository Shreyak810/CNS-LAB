from Crypto.Cipher import DES
from secrets import token_bytes

# Function to generate a random key for DES encryption
def generate_key():
    return token_bytes(8)  # DES uses 8-byte (64-bit) keys

# Function to pad the text to a multiple of 8 bytes (since DES works on 64-bit blocks)
def pad(text):
    while len(text) % 8 != 0:
        text += ' '
    return text

# Encrypt function
def encrypt(message, key):
    cipher = DES.new(key, DES.MODE_ECB)  # Using ECB mode for simplicity
    padded_text = pad(message)
    encrypted_text = cipher.encrypt(padded_text.encode('utf-8'))
    return encrypted_text

# Decrypt function
def decrypt(encrypted_message, key):
    cipher = DES.new(key, DES.MODE_ECB)  # Using ECB mode for simplicity
    decrypted_text = cipher.decrypt(encrypted_message).decode('utf-8').rstrip()
    return decrypted_text

# Example usage
if __name__ == "__main__":
    # Generate a key
    key = generate_key()

    # Message to be encrypted
    # Take input from the user
    #message = input("Enter the message to encrypt: ")
    message = "DES Sample Text"

    # Encrypt the message
    encrypted_message = encrypt(message, key)
    print(f"Encrypted Message: {encrypted_message}")

    # Decrypt the message
    decrypted_message = decrypt(encrypted_message, key)
    print(f"Decrypted Message: {decrypted_message}")
