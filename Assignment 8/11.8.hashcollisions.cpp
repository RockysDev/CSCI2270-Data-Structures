Hash Collisions 11/8

Linear probing disadvantage
    - clustering slows down search time. O(1) -> O(N)

Quadratic probing
    Instead of looking at adjacent, skip over by i^2 indices
    h(x) -> !0
    h(x) + 1^2 ... or + 2^2
    Can have secondary clustering
        this is better than primary clustering

Open addressing
    double hashing
        h1(x) + i * h2(x)
    hash key()
    (hash(key) + 1* h2(key)) % m

    2nd function must
        Never evaluate to 0 (can;t increment 0)
        make sure that all cells can be probed

    Popular second hash function
        h2(key) = r - (key%r)
        where r is prim number smaller than size of table n

chaining
    creats linked list stacking on top of hash.

heaps
    A list where each element has a key, in position k
    the element at position k is as large as key in element at position 2k+1 and 2k+2
        partially ordered
        not a sorted structure
        it is complete
    eg complete binary serach tree 
    min heap (min value at top) vs max heap (max value at top)