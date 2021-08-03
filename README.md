# Solidify! 

2.5 years into a Software Engineering degree, I realized I am starting to forget
important concepts. This is due to lack of repitition and a lack of organization
of my knowledge. This repository is an attempt to remedy these issues and build
a better understanding of some hard topics.

# Reading List
- [ ] Clean Code: A Handbook of Agile Software Craftsmanship - Martin
- [ ] Operation System Concepts - 10th Edition
- [ ] Algorithm Design - Kleiberg, Tardos
- [X] Introduction To Computing Systems: From Bits And Gates To C And Beyond - 2nd Edition
- [X] Computer Security: Principles and Practice - 3rd Edition
- [X] A First Course in Linear Algebra - Kuttler
- [X] C++ Primer - 5th Edition

# Data Structures
**Arrays**
- [X] Watch
  - https://www.coursera.org/lecture/data-structures/arrays-OsBSF
  - https://archive.org/details/ucberkeley_webcast_Wp8oiO_CZZE
  - https://www.coursera.org/lecture/data-structures/dynamic-arrays-EwbnV
  - https://www.youtube.com/watch?v=1jtrQqYpt7g
 - [X] Implement a vector
   - [X] Practice coding using arrays and pointers, and pointer math to jump to an index instead of using indexing.
   - [X] New raw data array with allocated memory
        *can allocate int array under the hood, just not use its features
        *start with 16, or if starting number is greater, use power of 2 - 16, 32, 64, 128
   - [X] size() - number of items
   - [X] capacity() - number of items it can hold
   - [X] is_empty()
   - [X] at(index) - returns item at given index, blows up if index out of bounds
   - [X] push(item)
   - [X] insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
   - [X] prepend(item) - can use insert above at index 0
   - [X] pop() - remove from end, return value
   - [X] delete(index) - delete item at index, shifting all trailing elements left
   - [X] remove(item) - looks for value and removes index holding it (even if in multiple places)
   - [X] find(item) - looks for value and returns first index with that value, -1 if not found
   - [X] resize(new_capacity) // private function
        *when you reach capacity, resize to double the size
        *when popping an item, if size is 1/4 of capacity, resize to half
    - [X] Time
        *O(1) to add/remove at end (amortized for allocations for more space), index, or update
        *O(n) to insert/remove elsewhere
    - [X] Space
        *contiguous in memory, so proximity helps performance
        *space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)
* Linked List
    - [X] Watch
	- https://www.coursera.org/lecture/data-structures/singly-linked-lists-kHhgK
	- https://archive.org/details/ucberkeley_webcast_htzJdKoEmO0
	- https://archive.org/details/ucberkeley_webcast_-c4I3gFYe3w
	- https://www.youtube.com/watch?v=QN6FPiD0Gzo
	- https://www.coursera.org/lecture/data-structures-optimizing-performance/in-the-real-world-lists-vs-arrays-QUaUd
	- [Why linked lists are slower than vectors(cache misses)](https://www.youtube.com/watch?v=YQs6IC-vgmo)
	- https://www.eskimo.com/~scs/cclass/int/sx8.html
    - [X] Implement
* Stack
    - [ ] Watch
    - [ ] Implement
        
* Queue
    - [ ] Watch
    - [ ] Implement
        
* Hash Table
    - [ ] Watch
    - [ ] Implement
      
      
