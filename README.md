# Time stamp based key value store
## ABSTRACT:
The given project is based on the problem of the Timestamp key-value
store using KD Trees. A key-value store, or key-value database, is a type of
data storage software program that stores data as a set of unique
identifiers, each of which has an associated value. One of the currently
available solutions to this problem is the usage of unordered_maps.
Unordered_maps is an associated container that stores elements formed
by the combination of a key-value and a mapped value. One of the major
issues faced is space complexity and during worst cases, the time
complexity can go up to O(n). This can occur in all the operations such as
insertion, searching and deletion. This becomes an issue as certain
processes with a large number of data points take a lot of time to
complete which can affect the applications throughput, and reduce the
performance of the application. One way to reduce this complexity is by
structuring the data points so that the required data can be retrieved as
quickly as possible. One of the limitations of building structures to hold
data is the inability to store a list of data in a single node and involving all
the elements from this list for traversal. One way to overcome this difficulty
is by using KD trees. A K-D Tree(also called as K-Dimensional Tree) is a
binary search tree where data in each node is a K-Dimensional point in
space. In short, it is a space partitioning data structure for organizing
points in a K-Dimensional space. Here, we are not using KD tree operations
in the traditional sense. The modification used here will be described in the
data structure definition portion. The metrics used here for the evaluation
of performance are time complexity, space complexity, number of
recursion calls, ability to access past transactions and the flexibility
demands for data storage.
## INTRODUCTION:
A key–value database, sometimes known as a dictionary or hash table, is a
data storage paradigm for storing, retrieving, and maintaining associative
arrays, and a data structure more often known as a dictionary or hash
table today. Dictionaries are made up of a collection of objects, or records,
each of which has a number of fields holding data. These records are
saved and retrieved using a key that is used to locate data inside the
database and uniquely identifies the record.
In comparison to relational databases (RDB), key–value databases operate
in a totally different way. RDBs specify the database's data structure as a
sequence of tables with fields that have well-defined data types. By
exposing data types to the database software, it may do a variety of
optimizations. Key–value systems, on the other hand, handle data as a
single opaque collection with several fields for each entry. This provides
more flexibility and adheres more closely to current notions such as
object-oriented programming. Because optional values are not
represented by placeholders or input parameters as they are in most
RDBs, key–value databases can store the same database with significantly
less memory, resulting in significant performance advantages in certain
workloads.
Since hash maps are used here, there are some potential disadvantages.
There is a really good chance for collision when two distinct keys generate
the same hashcode value which can seriously affect the performance of
the application. Occasionally, hash maps require resizing when the
original size of hash maps buckets are full. Resizing takes O(n) time as the
elements from the previous hash maps or hash table are now moved to a
bigger hash map or hash table.
The regular key-value store has the difficulty of accessing past
transactions. Hence the inclusion of a timestamp for every transaction
along with the key and value will help the programmer and the user to
access past transactions. This can again be implemented by using the
regular hash maps or even a simple two dimensional array. But these data
structures will still have the above said problems which can possibly affect
the performance of the application.
Hence in order to store a list of data and to access them easily without the
performance being affected, we have a modified KD tree (one for each key)
that could store the value as well as the timestamp of transaction in a
node. The pointer to all these KD tree roots that represent a key can be
stored in a hash map.
This KD tree works similar to the general KD tree with the exception of
searching. The searching algorithm has been modified so that we get the
value for a given key and timestamp with an unknown value.

## DATA STRUCTURE 1 - K DIMENSIONAL TREE ( K = 2 HERE) :
A k-d tree (short for k-dimensional tree) is a space-partitioning data
structure for organizing points in a k-dimensional space. k-d trees are a
useful data structure for several applications, such as searches involving a
multidimensional search key (e.g. range searches and nearest neighbor
searches) and creating point clouds. k-d trees are a special case of binary
space partitioning trees.
Here the dimension of the tree is 2. Hence each node takes 2 values. One is
the value and the other is the timestamp. Each key has a respective KD
tree and the pointer pointing to the root of the KD tree is stored in the
corresponding bucket of the hash map. Since this hash map is storing only
the key value, hence collision does not take place.
The root would have an x-aligned plane, the root’s children would both
have y-aligned planes, the root’s grandchildren would all have x-aligned
planes, and the root’s great-grandchildren would all have y-aligned planes
and so on.
Insertion and deletion are similar to a general KD tree. The difference
comes during searching. Our goal here is to find the value for a given key
and timestamp. Hence if we are in the y-aligned plane, then we search
depending on whether the timestamp to be searched is greater than or
lesser than or equal to the current timestamp and traverse accordingly.
On the other hand, if they are present on the x-aligned plane, then we
need to perform a search operation on both the left and right subtree.
Since the timestamp for a given transaction is stored in the given method,
accessing past transactions is possible. Also collisions do not take place
as time is a unique quantity. Also the search operations may have a better
complexity for large numbers of data points.

## DATA STRUCTURE 2 - HASHMAPS:
Hash maps is another data structure that can be used to solve this
problem. unordered_map is an associated container that stores elements
formed by the combination of key-value and a mapped value. The key
value is used to uniquely identify the element and the mapped value is the
content associated with the key. Both key and value can be of any type
predefined or user-defined.
Internally unordered_map is implemented using Hash Table, the key
provided to map are hashed into indices of a hash table that is why the
performance of data structure depends on hash function a lot but on an
average, the cost of search, insert and delete from the hash table is O(1). In
the worst case, its time complexity can go from O(1) to O(n2), especially for
big prime numbers.
Suppose we have to make a timestamp based key-value store class called
TimeMap, that supports two operations. <br>
● set(string key, string value, int timestamp): This will store the key and <br>
value, along with the given timestamp
● get(string key, int timestamp): This will return a value such that
set(key, value, timestamp_prev) was called previously, with
timestamp_prev <= timestamp. <br>
Now if there are multiple such values, it must return the value where the
timestamp_prev value is largest. If there are no such values, it returns the
empty string (""). So if we call the functions like below −
set("foo","bar",1), get("foo",1), get("foo",3), set("foo","bar2",4), set("foo",4), set("foo",5),
then the outputs will be: [null, “bar”, “bar”, null, “bar2”, “bar2]
To solve this, we will follow these steps −
<br>● Define a map m <br>
● The set() method will be like <br>
○ insert (timestamp, value) into m[key] <br>
● The get() method will work as follows <br>
○ ret := an empty string <br>
○ v := m[key] <br>
○ low := 0 and high := size of v – 1 <br>
○ while low <= high <br>
■ mid := low + (high – low) / 2 <br>
■ if key of v[mid] <= timestamp, then <br>
■ ret := value of v[mid] and set low := mid + 1 <br>
■ otherwise high := mid – 1 <br>
○ return ret <br>

## DATA STRUCTURE 3 - ARRAYS :
An array is a collection of items stored at contiguous memory locations.
The idea is to store multiple items of the same type together. This makes it
easier to calculate the position of each element by simply adding an offset
to a base value, i.e., the memory location of the first element of the array
(generally denoted by the name of the array). The base value is index 0 and
the difference between the two indexes is the offset.
For simplicity, we can think of an array as a fleet of stairs where on each
step is placed a value (let’s say one of your friends). Here, you can identify
the location of any of your friends by simply knowing the count of the step
they are on.
Arrays are yet another data structure that can be used to solve the above
given problem. Here, we use a two dimensional array, each array
representing a key. Array[i][0] gives the value stored and Array[i][1] gives the
timestamp of the transaction (i ranges from 0 to n-1 where n is the number
of transactions made). One of the main disadvantages in this method is
that values and timestamps are not stored in any fixed mechanism,
whereas they are stored in the order of arrival. Hence searching can have
a higher complexity. Also arrays have limited size as their sizes are fixed.
This can be solved by using dynamic arrays such as vectors.

## CONCLUSION :
Timestamp based key-value stores play a really important role in database
management as this also allows the user and the programmer to access
past transactions. Though Hashmaps might seem to be an optimal
solution, it has its own cons which can be solved by using KD trees as these
have better time complexities and do not have memory limit concerns
