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

# Server code for Alice
def diffie_hellman_server():
    # Publicly known values
    p = 23  # Prime number
    g = 5   # Primitive root

    # Alice's private and public key
    private_key_a = random.randint(1, p-1)
    public_key_a = modular_exponentiation(g, private_key_a, p)
    print(f"Alice's Public Key: {public_key_a}")

    # Set up server to communicate with Bob
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('localhost', 8080))
    server.listen(1)
    print("Waiting for Bob to connect...")

    conn, addr = server.accept()
    print(f"Connected to Bob: {addr}")

    # Send Alice's public key to Bob
    conn.send(str(public_key_a).encode())

    # Receive Bob's public key
    public_key_b = int(conn.recv(1024).decode())
    print(f"Received Bob's Public Key: {public_key_b}")

    # Calculate shared secret
    shared_secret_a = modular_exponentiation(public_key_b, private_key_a, p)
    print(f"Alice's Calculated Shared Secret: {shared_secret_a}")

    conn.close()

if __name__ == "__main__":
    diffie_hellman_server()
