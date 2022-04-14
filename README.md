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

