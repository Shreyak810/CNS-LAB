import hashlib

def calculate_sha1(text):
    # Create a new SHA-1 hash object
    sha1_hash = hashlib.sha1()
    
    # Update the hash object with the text encoded to bytes
    sha1_hash.update(text.encode('utf-8'))
    
    # Get the hexadecimal digest of the hash
    message_digest = sha1_hash.hexdigest()
    
    return message_digest

# Example usage
text = "Hello, World!"
digest = calculate_sha1(text)

# Display the message digest
print(f"Message Digest (SHA-1) of '{text}': {digest}")
