We can think of a function template as looking like this:

template<typename T>
void f(ParamType param);
  
A call can look like this:
f(expr); // call f with some expression
 
During compilation, compilers use expr to deduce two types: one for T and one for ParamType. These types are frequently different, because ParamType often contains
adornments cvr(const,volatile,reference)
  
The type deduced for T is dependent not just on the type of expr, but also on the form of ParamType. There are three cases:

• ParamType is a pointer or reference type, but not a universal reference. (Universal references are described in Item 24. At this point, all you need to know is that
they exist and that they’re not the same as lvalue references or rvalue references.)
  
• ParamType is a universal reference. 
  
• ParamType is neither a pointer nor a reference.
  
* Argument passed is an array or a function and template parameter is by reference.
  
We therefore have three type deduction scenarios to examine. Each will be based on our general form for templates and calls to it:
  
template<typename T>
void f(ParamType param);
  
f(expr); // deduce T and ParamType from expr
  
  
Case 1: The simplest situation is when ParamType is a reference type or a pointer type, but not a universal reference. In that case, type deduction works like this:
1. If expr’s type is a reference, ignore the reference part.
2. Then pattern-match expr’s type against ParamType to determine T.
  
*** Universal References ***
• If a function template parameter has type T&& for a deduced type T, or if an object is declared using auto&&, the parameter or object is a universal reference.
• If the form of the type declaration isn’t precisely type&&, or if type deduction does not occur, type&& denotes an rvalue reference.
• Universal references correspond to rvalue references if they’re initialized with rvalues. They correspond to lvalue references if they’re initialized with lvalues.
  
Case 2: ParamType is a Universal Reference
  
• If expr is an lvalue, both T and ParamType are deduced to be lvalue references.
• If expr is an rvalue, the “normal” (i.e., Case 1) rules apply.

Case 3: ParamType is Neither a Pointer nor a Reference
1. As before, if expr’s type is a reference, ignore the reference part.
2. If, after ignoring expr’s reference-ness, expr is const, ignore that, too. If it’s
volatile, also ignore that.
  
  
Case 4
Although functions can’t declare parameters that are truly arrays, they can declare parameters that are references to arrays! So if we modify the template f to take its argument by reference, 
  
template<typename T>
void f(T& param); // template with by-reference parameter
  
and we pass an array to it,
const char name[] = "J. P. Briggs";
f(name); // pass array to f
  
the type deduced for T is the actual type of the array! That type includes the size of the array, so in this example, T is deduced to be const char [13], and the type of f’s parameter (a reference to this array) is const char (&)[13].
  
Had template parameter been pass by value, the array argument passed would have decayed to a pointer and case 3 rules would have applied.
