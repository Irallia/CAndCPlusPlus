#include <iostream>
using namespace std;

char c = 'C';              // global scope

int foobar() {
   return 0;
}

int main()
{
   /* different ways of initialisation: */
   [[maybe_unused]] int i;                  // i is undefined
   [[maybe_unused]] int j = 7;
   [[maybe_unused]] int k{3};
   [[maybe_unused]] int l{};                // l is default-initialised to 0

   i = 23;                 // assignment (no initialisation)
   // -> prefer {} especially when using non-arithmetic types

   char grade = 'A';       // function body scope
   string phrase = "Bla blubb";
   [[maybe_unused]] int age = 50;
   [[maybe_unused]] double gpa = 2.3;
   [[maybe_unused]] bool isCorrect = true;  // the smallest unit of memory is 1 byte = 8 bit -> bool uses at least 8 bit.
   [[maybe_unused]] unsigned integral = 5;  // integral >= 0 (es gibt auch unsigned char, short, long, long long)

   /* data type auto */
   [[maybe_unused]] auto m = 7;             // m is of type int (you need to initialize this)
   [[maybe_unused]] auto n{3.3};            // n is type double
   [[maybe_unused]] auto o = foobar();      // o is of whatever type the function foobar() returns

   /* local scope: */
   {
      char e = 'E';
      cout << c << grade << e << "\n";
   }

   /* size */
   [[maybe_unused]] int s = sizeof(int);   // the size of data types depends on the compiler and the operating system

   /* OS and machine independent fixed-width integers from <cstdint> */
   [[maybe_unused]] int8_t a;      // and uint8_t for unsigned integers
   [[maybe_unused]] int16_t b;     // ...
   [[maybe_unused]] int32_t c;
   [[maybe_unused]] int64_t d;
   /* OS independent, but machine dependent "large types"  from <cstddef> */
   [[maybe_unused]] ptrdiff_t f;   // == int32_t or int64_t
   [[maybe_unused]] size_t g;      // == uint32_t || uint64_t
   /* make integrals unsigned if possible!
    * unsigned integral and no other information? → size_t
    * floating point and no other information? → double
    * integral and known range? → fixed-width int*_t / uint*_t
    * avoid int, long, unsigned int, unsigned long
    */
}
