import hashlib

# Input text
text = input("Enter Your Messgage Here : ")
print(f"Inputed Message : {text}")

# Create a SHA-1 hash object
sha1_hash = hashlib.sha1()

# Update the hash object with the text (encoded to bytes)
sha1_hash.update(text.encode())

# Get the hexadecimal representation of the digest
digest = sha1_hash.hexdigest()

print("SHA-1 Digest:", digest)
