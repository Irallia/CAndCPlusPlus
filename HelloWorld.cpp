#include <iostream>
#include <iomanip>

int main()
{
   /*
   * Many people claim that std::cout is way better than printf.
   * Difference: std::cout is C++, and printf is C. Both printf and std::cout have their advantages.
   *
   * More Information: https://stackoverflow.com/questions/2872543/printf-vs-cout-in-c
   */

   int id = 2;
   std::string errors[4] = {"bla", "test", "echo", "hallo"};

   std::cout << "Hallo Welt!\n";
   std::cout << "Error " << id << ": " << errors[id] << "." << std::endl;
   std::cout << "0x" << std::hex << std::setfill('0') << std::setw(4) << 0x424 << std::endl;

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