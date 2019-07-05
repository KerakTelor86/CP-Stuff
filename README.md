# CP-Stuff
Shitty templates, buggy headers, useless snippets, and other worthless competitive programming stuff I wrote.

Basically pbds.hpp is like the only thing worth a damn in this entire repo.


# Headers

- fastio.h: Basically just use this when scanf and/or printf TLEs.




- pbds.hpp:

	Insert: Inserts a node into the thing in O(log(n))
	
	Erase: Deletes something from the thing in O(log(n)) if found
	
	Find: returns true when element is found in the thing. O(log(n))
	
	Find by Index: (operator []) Array index kind of thing. O(log(n))
	
	Order: Finds the number of elements smaller than val in O(log(n))

	Logarithmic time for life.
	
	
# Snippets

- float_compare.cpp: Buggy crappy float comparison thingy, don't use if you don't want a WA lmao


# Templates

- cp_template.cpp: My personal template for CP. Buggy, would probably cause lots of WAs and RTEs lmao, use if you don't care.
