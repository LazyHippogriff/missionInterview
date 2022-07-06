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
  
  
  
*** Understanding auto type deduction ***
  
When a variable is declared using auto, auto plays the role of T in the template, and the type specifier for the variable acts as ParamType. This is easier to show than to describe, so consider this example:
auto x = 27;
Here, the type specifier for x is simply auto by itself. 
  
On the other hand, in this declaration,
const auto cx = x;
the type specifier is const auto. 
  
And here,
const auto& rx = x;
the type specifier is const auto&. To deduce types for x, cx, and rx in these examples,
compilers act as if there were a template for each declaration as well as a call to
that template with the corresponding initializing expression.
  
Exception case between auto and template

If the corresponding template is passed the same initializer, type deduction fails, and the code is rejected.
auto x = { 11, 23, 9 }; // x's type is std::initializer_list<int>

template<typename T> // template with parameter
void f(T param); // declaration equivalent to x's declaration

f({ 11, 23, 9 }); // error! can't deduce type for T
  
However, if you specify in the template that param is a std::initializer_list<T> for some unknown T, template type deduction will deduce what T is:

template<typename T>
void f(std::initializer_list<T> initList);
f({ 11, 23, 9 }); // T deduced as int, and initList's
// type is std::initializer_list<int>
  
  
* 'auto' in function return type will use template rules.
  
So a function with an auto return type that returns a braced initializer won’t compile:
auto createInitList()
{
return { 1, 2, 3 }; // error: can't deduce type or { 1, 2, 3 }
} 

The same is true when auto is used in a parameter type specification in a C++14 lambda
  
  
*** Understand decltype ***
  
C++14 supports decltype(auto), which, like auto, deduces a type from its initializer, but it performs the type deduction using the decltype rules.
  
Applying decltype to a name yields the declared type for that name. Names are lvalue expressions, but that doesn’t affect decltype’s behavior. For lvalue expressions
more complicated than names, however, decltype ensures that the type reported is always an lvalue reference. That is, if an lvalue expression other than a name has type T, decltype reports that type as T&. There is an implication of this behavior that is worth being aware of, however. 
In
int x = 0;
x is the name of a variable, so decltype(x) is int. But wrapping the name x in parentheses—“(x)”—yields an expression more complicated than a name. Being a
name, x is an lvalue, and C++ defines the expression (x) to be an lvalue, too. decltype((x)) is therefore int&. Putting parentheses around a name can change
the type that decltype reports for it!
  

  
  
*** Method to check type ***
Suppose, for example, we’d like to see the types that were deduced for x and y in the
previous example. We first declare a class template that we don’t define. Something
like this does nicely:
template<typename T> // declaration only for TD;
class TD; // TD == "Type Displayer"
Attempts to instantiate this template will elicit an error message, because there’s no
template definition to instantiate. To see the types for x and y, just try to instantiate
TD with their types:
TD<decltype(x)> xType; // elicit errors containing
TD<decltype(y)> yType; // x's and y's types
  
  
*** Note about closures ***
“The distinction between a lambda and the corresponding closure is precisely equivalent to the distinction between a class and an instance of the class. A class exists only in source code; it doesn’t exist at runtime. What exists at runtime are objects of the class type. Closures are to lambdas as objects are to classes. This should not be a surprise, because each lambda expression causes a unique class to be generated (during compilation) and also causes an object of that class type–a closure–to be created (at runtime).”

** Good article about perfect forwarding **
https://eli.thegreenplace.net/2014/perfect-forwarding-and-universal-references-in-c
