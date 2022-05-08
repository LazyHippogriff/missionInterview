• “Invisible” proxy types can cause auto to deduce the “wrong” type for an initializing expression.
 
• The explicitly typed initializer idiom forces auto to deduce the type you want it to have.
auto var = static_cast<var_type>(some_var);


 
Braced-initializer don't allow narrowing conversions(long to int etc.)
• Braced initialization is the most widely usable initialization syntax, it prevents narrowing conversions, and it’s immune to C++’s most vexing parse.
• During constructor overload resolution, braced initializers are matched to std::initializer_list parameters "if at all possible", even if other constructors
offer seemingly better matches.
• An example of where the choice between parentheses and braces can make a significant difference is creating a std::vector<numeric type> with two arguments.
std::vector<int> v1(10, 20); // use non-std::initializer_list ctor: create 10-element std::vector, all elements have value of 20
std::vector<int> v2{10, 20}; // use std::initializer_list ctor: create 2-element std::vector, element values are 10 and 20
  
• Prefer nullptr to 0 and NULL.
  // three overloads of f
  void f(int); 
void f(bool);
void f(void*);
  
f(0); // calls f(int), not f(void*)
f(NULL); // might not compile, but typically calls f(int). Never calls f(void*). NULL is always has an integral type.
  
* Prefer alias declarations to typedefs.   
// FP is a synonym for a pointer to a function taking an int and a const std::string& and returning nothing
typedef void (*FP)(int, const std::string&); 
  
// same meaning as above
using FP = void (*)(int, const std::string&); // alias declaration
  
• C++98-style enums are now known as unscoped enums.
• Enumerators of scoped enums are visible only within the enum. They convert to other types only with a cast.
• Both scoped and unscoped enums support specification of the underlying type. The default underlying type for scoped enums is int. Unscoped enums have no
default underlying type.
• Scoped enums may always be forward-declared. Unscoped enums may be forward-declared only if their declaration specifies an underlying type.
  
* Prefer deleted functions to private undefined ones.
* By convention, deleted functions are declared public, not private.
An important advantage of deleted functions is that any function may be deleted(including non-member functions and template instantiations), while only member functions may be private. This may be useful in cases where we need to restrict certain argument conversions while calling a function e.g.
  
  #include <iostream>


void func(long a) {
  std::cout<<"a->"<<a<<std::endl;
}

void func(int a) = delete;


int main() {
  int x = 42; //This will give compilation errors.
  func(x);

}
  
  
  
* Declare overriding functions override.

For overriding to occur, several requirements must be met:
• The base class function must be virtual.
• The base and derived function names must be identical (except in the case of destructors).
• The parameter types of the base and derived functions must be identical.
• The constness of the base and derived functions must be identical.
• The return types and exception specifications of the base and derived functions must be compatible.
• The functions’ reference qualifiers must be identical.
  
* Member function reference qualifiers are one of C++11’s less-publicized features
  class Widget {
public:
…
void doWork() &; // this version of doWork applies only when *this is an lvalue
  
void doWork() &&; // this version of doWork applies only when *this is an rvalue
};
  
Widget makeWidget(); // factory function (returns rvalue)
Widget w; // normal object (an lvalue)
…
w.doWork(); // calls Widget::doWork for lvalues (i.e., Widget::doWork &)
  
makeWidget().doWork(); // calls Widget::doWork for rvalues (i.e., Widget::doWork &&)
   
if a virtual function in a base class has a reference qualifier, derived class overrides of that function must have exactly the same reference qualifier. If they don’t, the declared functions will still exist in the derived class, but they won’t override anything in the base class.
  
C++11 introduces two contextual keywords, override and final. These keywords have the characteristic that they are reserved, but only in certain contexts. In the case of override, it has a reserved meaning only when it occurs at the end of a member function declaration.
