## The concept of Hash Tables ##
A hash table (hash map) is a data structure that implements an associative array abstract data type, s structure that can map keys to values. A hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found. During lookup, the key is hashed and the resulting hash indicates where the corresponding value is stored.

The corresponding result in this simple example code:
<div class="language-shell highlighter-rouge"><pre class="highlight"><code class="hljs ruby"><span class="nb">$ ./hash_table                                                                    [8:09:14]
0: California: Sacramento
1: Texas: Austin
2: <NULL>: 
3: <NULL>: 
4: Oregon: Salem
5: New Mexico: Santa Fe
6: Florida: Tallahassee
7: <NULL>: 
-----------------------------

0: <NULL>: 
1: <Dummy>: 
2: <NULL>: 
-----------------------------

The capital of Washington is Olympia
The capital of Florida is Tallahassee
The capital of Texas is Austin
Oregon not found
Size of bucket 0: 0
Size of bucket 1: 1
Size of bucket 2: 1
Size of bucket 3: 1</span></code></pre></div>

## Reference ##
[1] [Wiki: hash table](https://en.wikipedia.org/wiki/Hash_table)

