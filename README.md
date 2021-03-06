# CP-Stuff
Templates, headers, implementations for competitive programming-related stuff and weird data structures I use for personal projects.


# Headers
- fastio.h: Fast I/O with getchar_unlocked() or \_getchar_nolock() depending on which OS it's compiled in. (Works in Codeforces)

- ost.hpp:	AVL-based Ordered Set.
  - Insert: Inserts a node into the thing in O(log(n))
  - Erase: Deletes something from the thing in O(log(n)) if found
  -	Find: returns true when element is found in the thing. O(log(n))
  -	Find by Index: (operator []) Array index kind of thing. O(log(n))
  -	Order: Finds the number of elements smaller than val in O(log(n))

# Snippets
- avl.c: AVL Tree

- dijkstra.cpp: Dijkstra's algo for shortest path from s to t

- dinic.cpp: Dinic's maxflow algo (SPOJ fastflow)

- dynamic_memo.cpp: Dynamic Memoization: memoization that keeps memory usage down by discarding less commonly used values, crappy implementation

- edmonds-karp.cpp: Maxflow with Edmonds-Karp algo (LightOJ 1153 - Internet Bandwidth)

- lazy-segtree.cpp: Recursive segment tree with lazy propagation

- lca.cpp: Lowest common ancestor with binary lifting

- matmul.cpp: Matrix multiplication with ikj optimization

- treap.cpp: Normal treap with split kth

- kmp.cpp: Knuth-Morris-Pratt string matching function

- hld.cpp: Heavy-light decomposition (TimusOJ 1553 - Caves and Tunnels)

# Templates

- cp_template.cpp: Daily CP template.
