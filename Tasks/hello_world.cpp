#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!\n";

    /*
    * Run the code with:
    * g++ -std=c++17 -Wall -Wextra -Werror -pedantic .\hello_world.cpp -o hello
    *
    * What do the flags mean:
    * -Wall
    *   This enables all the warnings about constructions that some users consider questionable, and that are easy to
    *   avoid (or modify to prevent the warning), even in conjunction with macros. This also enables some
    *   language-specific warnings described in C++ Dialect Options and Objective-C and Objective-C++ Dialect Options.
    * -Wextra
    *   This enables some extra warning flags that are not enabled by -Wall.
    * -Werror
    *   Make all warnings into errors.
    *-pedantic
    *   Issue all the warnings demanded by strict ISO C and ISO C++; reject all programs that use forbidden extensions,
    *       and some other programs that do not follow ISO C and ISO C++. For ISO C, follows the version of the ISO C
    *       standard specified by any -std option used.
    *   Valid ISO C and ISO C++ programs should compile properly with or without this option (though a rare few require
    *       -ansi or a -std option specifying the required version of ISO C). However, without this option, certain GNU
    *       extensions and traditional C and C++ features are supported as well. With this option, they are rejected.
    *   -Wpedantic does not cause warning messages for use of the alternate keywords whose names begin and end with
    *       ‘__’. This alternate format can also be used to disable warnings for non-ISO ‘__intN’ types, i.e.
    *       ‘__intN__’. Pedantic warnings are also disabled in the expression that follows __extension__. However, only
    *       system header files should use these escape routes; application programs should avoid them. See Alternate
    *       Keywords.
    *   Some users try to use -Wpedantic to check programs for strict ISO C conformance. They soon find that it does not
    *       do quite what they want: it finds some non-ISO practices, but not all—only those for which ISO C requires a
    *       diagnostic, and some others for which diagnostics have been added.
    *   A feature to report any failure to conform to ISO C might be useful in some instances, but would require
    *       considerable additional work and would be quite different from -Wpedantic. We don’t have plans to support
    *       such a feature in the near future.
    *   Where the standard specified with -std represents a GNU extended dialect of C, such as ‘gnu90’ or ‘gnu99’, there
    *   	is a corresponding base standard, the version of ISO C on which the GNU extended dialect is based. Warnings
    *       from -Wpedantic are given where they are required by the base standard. (It does not make sense for such
    *       warnings to be given only for features not in the specified GNU C dialect, since by definition the GNU
    *       dialects of C include all features the compiler supports with the given option, and there would be nothing
    *       to warn about.)
    */

}