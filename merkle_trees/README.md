# Merkle Trees

Merkle Trees are hash-based trees that provides a summarizing root hash that verifies its contents.


```
[Leaf 1]    [Leaf 2]    [Leaf 3]    [Leaf 4]

     [Hash(1,2)]             [Hash(3,4)]

            [Hash(h(1,2),h(3,4)]
```

Collaborating system nodes can use the root hash to ensure the integrity of their data.

By following hashs starting from the root hash, these systems can communicate to figure out which leaves are corrupted.

The main benefits of Merkle Trees is that differences between data sets are easy to pin-point, and require minimal communication.

Uses:

[Cassandra](http://distributeddatastore.blogspot.com/2013/07/cassandra-using-merkle-trees-to-detect.html)
