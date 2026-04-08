from pgpy.constants import PubKeyAlgorithm, KeyFlags, HashAlgorithm, SymmetricKeyAlgorithm, CompressionAlgorithm
from pgpy import PGPKey, PGPUID, PGPMessage
import warnings
warnings.filterwarnings("ignore")


print("Creating Alice keypair...")
alice_key = PGPKey.new(PubKeyAlgorithm.RSAEncryptOrSign, 2048)
alice_uid = PGPUID.new("Alice")
alice_key.add_uid(
    alice_uid,
    usage={KeyFlags.Sign, KeyFlags.EncryptCommunications},
    hashes=[HashAlgorithm.SHA256],
    ciphers=[SymmetricKeyAlgorithm.AES256],
    compression=[CompressionAlgorithm.ZLIB]
)

print("Creating Bob keypair...")
bob_key = PGPKey.new(PubKeyAlgorithm.RSAEncryptOrSign, 2048)
bob_uid = PGPUID.new("Bob")
bob_key.add_uid(
    bob_uid,
    usage={KeyFlags.Sign, KeyFlags.EncryptCommunications},
    hashes=[HashAlgorithm.SHA256],
    ciphers=[SymmetricKeyAlgorithm.AES256],
    compression=[CompressionAlgorithm.ZLIB]
)

alice_pub = alice_key.pubkey
bob_pub = bob_key.pubkey

print("Enter message to send to Bob:")
user_message = input()

msg = PGPMessage.new(user_message)

print("Alice signing message...")
signature = alice_key.sign(msg)
msg |= signature

print("Alice encrypting message to Bob...")
cipher = bob_pub.encrypt(msg)

print("Ciphertext:")
print(cipher)

print("Bob decrypting message...")
plain = bob_key.decrypt(cipher)

print("Decrypted message:")
print(plain.message)

print("Bob verifying Alice signature...")
verify = alice_pub.verify(plain)
print("Signature verified:", verify)
