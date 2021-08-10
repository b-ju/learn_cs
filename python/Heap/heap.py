import sys
import math
# Author: Ben Jurenka
# Assignment to implement a min heap.

db = False
swap_count = 0
heapify_call_count = 0


def reset_counts():
    global swap_count
    swap_count = 0
    global heapify_call_count
    heapify_call_count = 0

    
def swap(A, i, j):
    global swap_count
    swap_count += 1
    A[i], A[j] = A[j], A[i]

    
def count_heapify():
    global heapify_call_count
    heapify_call_count += 1

    
def current_counts():
    return {'swap_count': swap_count, 'heapify_call_count': heapify_call_count}


def readNums(filename):
    """Reads a text file containing whitespace separated numbers.
    Returns a list of those numbers."""
    with open(filename) as f:
        lst = [int(x) for line in f for x in line.strip().split() if x]
        if db:
            print("List read from file {}: {}".format(filename, lst))
        return lst

    
def parent(i):
    return (i - 1) // 2


def left(i):
    return 2 * i + 1


def right(i):
    return left(i) + 1

def heapify(A, i, n=None):

    count_heapify() # This MUST be the first line of the heapify function, don't change it.
    if n is None:
        n = len(A)
    if not(i < n):
        # if asked to heapify an element not below n (the conceptual size of the heap), just return
        # because no work is required
        return

    leftChild = left(i)
    rightChild = right(i)

    if leftChild < n and A[leftChild] < A[i]:
        indexSmallestNode = leftChild
    else:
        indexSmallestNode = i
    
    if rightChild < n and A[rightChild] < A[indexSmallestNode]:
        indexSmallestNode = rightChild

    if indexSmallestNode is not i:
        swap(A, i, indexSmallestNode)
        heapify(A, indexSmallestNode)


def buildHeap(A):

    for i in reversed(range(0, len(A) // 2)):
        heapify(A, i)


def heapExtractMin(A):

    rootIndex = 0
    minNode = A[rootIndex]
    A[rootIndex] = A[len(A)-1]
    A.pop()
    heapify(A, rootIndex)
    return minNode


def heapInsert(A, v):

    A.append(v)
    vIndex = len(A) - 1
    parentIndex = parent(vIndex)

    while A[parentIndex] > v :
        swap(A, parentIndex, vIndex)
        vIndex = parentIndex
        if vIndex == 0:
            return
        else:
            parentIndex = parent(vIndex)


def printCompleteTree(A):
    """ A handy function provided to you, so you can see a
    complete tree in its proper shape."""
    
    height = int(math.log(len(A), 2))
    width = len(str(max(A)))
    for i in range(height + 1):
        print(width * (2 ** (height - i) - 1) * " ", end="")
        for j in range(2 ** i):
            idx = 2 ** i - 1 + j
            if idx >= len(A):
                print()
                break
            if j == 2 ** i - 1:
                print("{:^{width}}".format(A[idx], width=width))
            else:
                print("{:^{width}}".format(A[idx], width=width),
                      width * (2 ** (height - i + 1) - 1) * " ", sep='', end='')
    print()


def shuffled_list(length, seed):
    A = list(range(10, length + 10))
    import random
    r = random.Random(seed) # pseudo random, so it is repeatable
    r.shuffle(A)
    return A


def report_counts_on_basic_ops(A, loop_extracts=1, loop_inserts=1):
    original_len = len(A)
    print("\nREPORT on list of len: {}".format(original_len))
    reset_counts()
    buildHeap(A)
    print("buildHeap(A):           \t", current_counts())

    reset_counts()
    m = heapExtractMin(A)
    print("heapExtractMin(A) => {}:\t".format(m), current_counts())

    reset_counts()
    heapInsert(A, m)
    print("heapInsert(A, {}):       \t".format(m), current_counts())

    for i in range(loop_extracts):
        reset_counts()
        m = heapExtractMin(A)
        print("heapExtractMin(A) => {}:\t".format(m), current_counts())

    import random
    r = random.Random(0)
    for i in range(loop_inserts):
        reset_counts()
        new_number = r.randrange(0, original_len // 8)
        heapInsert(A, new_number)
        print("heapInsert(A, {}):       \t".format(new_number), current_counts())


def main():
    global db
    if len(sys.argv) > 2:
        db = True
    
    A = shuffled_list(20, 0)
    print("Complete Tree size 20:")
    printCompleteTree(A)
    buildHeap(A)
    print("Heap size 20:")
    printCompleteTree(A)

    A = shuffled_list(20, 0)
    report_counts_on_basic_ops(A)

    A = shuffled_list(30, 0)
    report_counts_on_basic_ops(A)

    A = shuffled_list(400, 0)
    report_counts_on_basic_ops(A)
    
    A = shuffled_list(10000, 0)
    report_counts_on_basic_ops(A)

    A = shuffled_list(100000, 0)
    report_counts_on_basic_ops(A, 3, 3)

if __name__ == "__main__":
    main()
