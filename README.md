# CP-Stuff
Templates, headers, implementations for competitive programming-related stuff.


# Headers

- fastio.h: Fast I/O with getchar_unlocked() or \_getchar_nolock() depending on which OS it's compiled in.

- ost.hpp:	AVL-based Ordered Set.

  - Insert: Inserts a node into the thing in O(log(n))
	
  - Erase: Deletes something from the thing in O(log(n)) if found
	
  -	Find: returns true when element is found in the thing. O(log(n))
	
  -	Find by Index: (operator []) Array index kind of thing. O(log(n))
	
  -	Order: Finds the number of elements smaller than val in O(log(n))
	
	
# Snippets

- float_compare.cpp: Buggy crappy float comparison thingy, don't use if you don't want a WA lmao


# Templates

- cp_template.cpp: My personal CP template
