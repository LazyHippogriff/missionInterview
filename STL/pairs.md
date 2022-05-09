'==' returns true only when both members of pairs of both operands are same
'>' and '<' will compare only the first member of each of the pair. So if you create a vector of pairs and then sorting will be done on the basis of first member of the pair.

This above fact can be useful for the following problem i.e.

Given 2 arrays, one integer and another char we have to print the second array sorted as per the values in the first array. e.g.

Input:

int array-> [3,5,1,4,2]
char array-> [t,u,a,m,b]

output:
[a,b,t,m,u]

