import socket
import random

# Function to perform modular exponentiation
def modular_exponentiation(base, exp, mod):
    result = 1
    base = base % mod
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        exp = exp >> 1
        base = (base * base) % mod
    return result

# Client code for Bob
def diffie_hellman_client():
    # Publicly known values
    p = 23  # Prime number
    g = 5   # Primitive root

    # Bob's private and public key
    private_key_b = random.randint(1, p-1)
    public_key_b = modular_exponentiation(g, private_key_b, p)
    print(f"Bob's Public Key: {public_key_b}")

    # Connect to Alice's server
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('localhost', 8080))

    # Receive Alice's public key
    public_key_a = int(client.recv(1024).decode())
    print(f"Received Alice's Public Key: {public_key_a}")

    # Send Bob's public key to Alice
    client.send(str(public_key_b).encode())

    # Calculate shared secret
    shared_secret_b = modular_exponentiation(public_key_a, private_key_b, p)
    print(f"Bob's Calculated Shared Secret: {shared_secret_b}")

    client.close()

if __name__ == "__main__":
    diffie_hellman_client()
