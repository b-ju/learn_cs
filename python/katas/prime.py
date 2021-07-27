#!/usr/bin/env python3	
	
def is_prime(n: int) -> bool:
	if int(n)<= 3:
		return n > 1

	if int(n) % 2 == 0:
		print(str(n) + " is divisible by 2")
		return False

	if int(n) % 3 == 0:
		print(str(n) + " is divisible by 3")
		return False

	i = 5
	while i ** 2 <= int(n):
		if int(n) % i == 0:
			print(str(n) + " is divisible by: " + str(i))
			return False
		if int(n) % (i + 2) == 0:
			print(str(n) + " is divisible by: " + str(i+2))
			return False
		i = i + 6
	return True

def main():
	x = input("enter a number:")
	if is_prime(x):
		print(str(x) + "is prime")
	
if __name__== '__main__':
	main()
