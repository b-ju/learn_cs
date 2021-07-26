def move_zeros(l):
	for x in l:
		if int(x) == 0:
			l.remove(x)
			l.append(0)
	return l

def main():
	print(move_zeros([1,0,1,2,0,1,3]))
	
if __name__== '__main__':
	main()
