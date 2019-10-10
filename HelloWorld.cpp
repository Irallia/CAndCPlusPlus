#include <iostream>
#include <iomanip>

using namespace std;    // std: standard library

/* Every function needs to return at least 0. The main function is the only function which returns 0 automaticaly. */
int main()
{
   /*
   * Many people claim that std::cout is way better than printf.
   * Difference: std::cout is C++, and printf is C. Both printf and std::cout have their advantages.
   *
   * More Information: https://stackoverflow.com/questions/2872543/printf-vs-cout-in-c
   */

   int id = 2;
   string errors[4] = {"bla", "test", "echo", "hallo"};

   cout << "Hallo Welt!\n";   // std::endl is less efficient than '\n'.
   cout << "Error " << id << ": " << errors[id] << ".\n";
   cout << "0x" << hex << setfill('0') << setw(4) << 0x424 << '\n';

   /*
   * + std::cout is extensible. (However, people rarely would want to extend ostream.)
   * - Syntax is longer (but less problems?)
   * + Not having to remember/look-up specific integer type syntax.
   */

   printf("Hello world!\n");
   printf("Error %d: %s.\n", id, errors[id]);
   printf("0x%04x\n", 0x424);
   /*
   * + (printf is extensible too, but such extension is not mentioned in the C standard (so you would have to use
   *     non-standard features - but not even common non-standard feature exists), and such extensions are one letter
   *     (so it's easy to conflict with an already-existing format))
   * + Syntax is shorter (The tables are available at http://en.cppreference.com/w/cpp/io/c/fprintf
   *     and http://en.cppreference.com/w/cpp/types/integer.)
   * - You can't print the NUL byte, \0
   */
}