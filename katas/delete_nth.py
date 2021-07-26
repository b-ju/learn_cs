from collections import Counter

def delete_nth(arr, most):
	counts = Counter(arr)
	arr.reverse()
	for num in counts:
		if counts[num] > most:
			for i in range(0, counts[num] - most):
				arr.remove(num)
	arr.reverse();
	return arr

def delete_nth_bp(order, max_e):
    ans = []
    for o in order:
        if ans.count(o) < max_e: ans.append(o)
    return ans

def main():
	print(delete_nth_bp([1,1,2,2,3,3,3,4,1,1],1))

	print(delete_nth_bp([1,1,2,2,3,3,3,4,1,1],2) , " should equal [1,1,2,2,3,3,4]")

	print(delete_nth_bp([1,1,1],0) , " should equal[ ]")
if __name__ == '__main__':
	main()
