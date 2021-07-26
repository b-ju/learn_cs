import sys

def mult35sum(num):
	return sum(x for x in range(num) if x % 3 == 0 or x % 5 == 0)

def main():
	try:
		print(mult35sum(int(sys.argv[1])))
	except:
		print("did not enter a number in arg 1")
		
if __name__ == '__main__':
	main()
