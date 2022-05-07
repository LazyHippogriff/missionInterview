There are 5 'logical' categories of iterators(hierarchical i.e. the next category in the hierarchy contains all the properties of the elements in the previous level in the hierarchy):

1a) input
1b) output

2) Forward

3) Bidirectional

4) Random



input iterator cannot be written vice versa for output.
input, output and forward iterators can only be incremented forward.
Bidirectional can be incremented or decremented by 1.
Variety of operations possible on random like increment/decrement by n, comparison etc.


Simple Data types -> (Iterator category)
forward_list (forward)
list (Bidirectional)
vector (Random)


Associative Data types  -> Iterator category
set/map/multi-(map/set)  ->  Bidirectional
unordered-(set/map) -> forward


Adapter Data types e.g. queue/stack/priority-queue do not have iterators.



Note: Adapter data types are built using simple data types.


Some useful functions used for iterators:

iterator std::prev(iterator,position)
iterator std::next(iterator,position)
void std::advance(iterator&, position) //The iterator passed to the function is modified


The above functions' time complexity will vary depending on the type of iterator passed in input. e.g. for forward_iterator complexity will be O(n) and for random iterator it will be O(1). For froward iterator, position cannot be negative in std::advance().





