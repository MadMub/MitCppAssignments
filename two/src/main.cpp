#include <iostream>

// 2
int a = 123;

void f(const int a = 5)
{
  std::cout << a * 2 << std::endl;
}

/*
  this function invokes f(), which receives an integer, doubles and prints it out
  it has a default value assigned for passing nothing to f() will print 10
*/
void Two()
{
  f(1);
  f(a);
  int b = 3;
  f(b);
  int a = 4;
  f(a);
  f();
}
// 2

// 3.1
/*
  The main function invokes printNum() however the function implementation is below,
  to fix move the implementation above main() OR declare printNum() in a header or above main()
*/
// 3.1

// 3.2
/*
  printNum() needs to be defined to accept an integer... I don't see any other fixes
*/
// 3.2

// 3.3
/*
  The usage in main() indicates that doubleNumber() needs to mutate the passed in value.
  To fix switch doubleNumber() to receive a reference to an integer
*/
// 3.3

// 3.4
/*
  Need to return diff within difference()
*/
// 3.4

// 3.5
/*
  sum() was defined to accept 2 integers but was invoked with 3.
  Redefine sum() to accept and add all 3 integers
*/
// 3.5

// 3.6
/*
  need to switch yPtr to *yPtr, assigning it to the last element in the array.
  Because of array allocation, that value is currently initted to 0
*/
const int ARRAY_LEN = 10;

void ThreeSix()
{
  int arr[ARRAY_LEN] = { 10 };
  int *xPtr = arr, *yPtr = arr + ARRAY_LEN -1;
  std::cout << * xPtr << ' ' << * yPtr ;
}
// 3.6

// 4.1
int sum(const int a, const int b)
{
  return a + b;
}

double sum(const double a, const double b)
{
  return a + b;
}

void FourOne()
{
  int three = sum(1, 2);
  std::cout << three << std::endl;
  double threePointEight = sum(1.5, 2.3);
  std::cout << threePointEight << std::endl;
}
// 4.1

// 4.2
/*
  ambiguous invocation as it cannot match if the values should be ints or doubles.
  I imagine if I had only one definition of sum() it might work and perform the type
  conversions?
*/
/*
void FourTwo()
{
  sum(1, 10.0);
}*/
// 4.2

// 4.3
int sum(const int a, const int b, const int c)
{
  return a + b + c;
}

int sum(const int a, const int b, const int c, const int d)
{
  return a + b + c + d;
}
// 4.3

// 4.4
/*
  if I called this sum() it would conflict at compile time as a redefinition of
  the 4 argument sum(). At runtime invocations would cause an ambiguity on either
  sum(a, b) or sum(a, b, c) as the default values would cause the signatures to
  effectively match.
*/
int sumTwoToFour(const int a, const int b, const int c = 0, const int d = 0)
{
  return a + b + c + d;
}
// 4.4

// 4.5
int sumLoop(const int arr[], int length)
{
  int sum = 0;
  for(int i = 0; i < length; i++)
  {
    sum += arr[i];
  }
  return sum;
}

void FourFive()
{
  int arr[] = {1,2,3};
  std::cout << sumLoop(arr, 3) << std::endl;
}
// 4.5

// 4.6
int sumRecursion(const int arr[], int length)
{
  if(length == 0){
    return 0;
  } else {
    return *arr + sumRecursion(arr + 1, length - 1);
  }
}

void FourSix()
{
  int arr[] = {1, 2, 3};
  std::cout << sumRecursion(arr, 3) << std::endl;
}
// 4.6

int main(int argc, char const *argv[])
{
  //Two();
  //ThreeSix();
  //FourOne();
  //FourFive();
  FourSix();
  return 0;
}
