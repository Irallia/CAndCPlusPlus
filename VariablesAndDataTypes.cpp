#include <iostream>
using namespace std;

char c = 'C';              // global scope

foobar() {
   return 0;
}

int main()
{
   /* different ways of initialisation: */
   int i;                  // i is undefined
   int j = 7;
   int k{3};
   int l{};                // l is default-initialised to 0

   i = 23;                 // assignment (no initialisation)
   // -> prefer {} especially when using non-arithmetic types

   char grade = 'A';       // function body scope
   string phrase = "Bla blubb";
   int age = 50;
   double gpa = 2.3;
   bool isCorrect = true;
   unsigned integral = 5;  // integral >= 0 (es gibt auch unsigned char, short, long, long long)

   /* data type auto */
   auto m = 7;             // m is of type int (you need to initialize this)
   auto n{3.3};            // n is type double
   auto o = foobar();      // o is of whatever type the function foobar() returns

   /* local scope: */
   {
      char e = 'E';
      cout << c << grade << e << "\n";
   }

   /* size */
   sizeof(int);   // the size of data types depends on the compiler and the operating system
   /* OS and machine independent fixed-width integers from <cstdint> */
   int8_t a;      // and uint8_t for unsigned integers
   int16_t b;     // ...
   int32_t c;
   int64_t d;
   /* OS independent, but machine dependent "large types"  from <cstddef> */
   ptrdiff_t f;   // == int32_t or int64_t
   size_t g;      // == uint32_t || uint64_t
   // avoid int, long, unsigned int, ... in case you know the size
   // the smallest unit of memory is 1 byte = 8 bit -> bool uses at least 8 bit.
}
