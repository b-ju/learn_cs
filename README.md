# Solidify! 

2.5 years into a Software Engineering degree, I realized I am starting to forget
important concepts. This is due to lack of repitition and a lack of organization
of my knowledge. This repository is an attempt to remedy these issues and build
a better understanding of some hard topics.

# Data Structures
* Arrays
[] Watch
  *https://www.coursera.org/lecture/data-structures/arrays-OsBSF
  *https://archive.org/details/ucberkeley_webcast_Wp8oiO_CZZE
  *https://www.coursera.org/lecture/data-structures/dynamic-arrays-EwbnV
  *https://www.youtube.com/watch?v=1jtrQqYpt7g
 []implement a vector
   []Practice coding using arrays and pointers, and pointer math to jump to an index instead of using indexing.
   []New raw data array with allocated memory
        *can allocate int array under the hood, just not use its features
        *start with 16, or if starting number is greater, use power of 2 - 16, 32, 64, 128
   []size() - number of items
   []capacity() - number of items it can hold
   []is_empty()
   []at(index) - returns item at given index, blows up if index out of bounds
   []push(item)
   []insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
   []prepend(item) - can use insert above at index 0
   []pop() - remove from end, return value
   []delete(index) - delete item at index, shifting all trailing elements left
   []remove(item) - looks for value and removes index holding it (even if in multiple places)
   []find(item) - looks for value and returns first index with that value, -1 if not found
   []resize(new_capacity) // private function
        *when you reach capacity, resize to double the size
        *when popping an item, if size is 1/4 of capacity, resize to half
    []Time
        *O(1) to add/remove at end (amortized for allocations for more space), index, or update
        *O(n) to insert/remove elsewhere
    []Space
        *contiguous in memory, so proximity helps performance
        *space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)
        
* Stack
    []Watch
      *
      *
      *
    []Implement
        
* Queue
    []Watch
      *
      *
      *
    []Implement
        
* Hash Table
    []Watch
      *
      *
      *
    []Implement
      
      
