import sys

def cipher(message, key):
	message = list(message)
	cryp = ""
	for i in range(len(message)):
		ascii = ord(message[i])
		if message[i].isalpha():
			if message[i].isupper():
				ascii += key #adding key
				while ascii > 90: #if exceeding ASCII, go round # for UPPER
					ascii -= 26
				
			elif message[i].islower():
				ascii += key #adding key
				while ascii > 122: #if exceeding ASCII, go round # for LOWER
					ascii -= 26
		cryp += chr(ascii)
	return cryp


if (len(sys.argv) != 2):
	print("Usage: ./caesar k")
	sys.exit()
	
key = int(sys.argv[1])

message = input("plaintext: ")

print("ciphertext: %s" % cipher(message, key))