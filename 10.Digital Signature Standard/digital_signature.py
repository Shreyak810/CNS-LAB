from cryptography.hazmat.primitives.asymmetric import dsa
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import utils
from cryptography.hazmat.primitives import serialization

# Step 1: Key Generation
def generate_keys():
    # Generate a private key for signing
    private_key = dsa.generate_private_key(key_size=2048)

    # Derive the public key for verification
    public_key = private_key.public_key()

    return private_key, public_key

# Step 2: Signature Generation
def sign_message(private_key, message):
    # Hash the message and create a signature
    signature = private_key.sign(
        message,
        hashes.SHA256()
    )
    return signature

# Step 3: Signature Verification
def verify_signature(public_key, message, signature):
    try:
        # Verify the signature
        public_key.verify(
            signature,
            message,
            hashes.SHA256()
        )
        return True
    except Exception as e:
        return False

if __name__ == "__main__":
    # Message to be signed
    message = b"This is a secure message."

    # Key generation
    private_key, public_key = generate_keys()

    # Display the keys
    print(f"Private Key: {private_key}")
    print(f"Public Key: {public_key}")

    # Signing the message
    signature = sign_message(private_key, message)
    print(f"Generated Signature: {signature.hex()}")

    # Verifying the signature
    is_valid = verify_signature(public_key, message, signature)

    if is_valid:
        print("The signature is valid.")
    else:
        print("The signature is NOT valid.")
