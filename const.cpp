#include <iostream>
#include <string>

/* Const in a class: */
class Entity {
    private:
        int m_X;
        int* m_Y;           // == int m_X, *m_Y;
                            // int* m_X, m_Y; =>! int* m_Y;
        mutable int var;    // debugging variable which is needed to be changed.
    public:
        // Constructor:
        Entity(int x) {}
        // Get-er and Set-er:
        int getX() const {  // write const after a method name (only works in a class)
            // m_X = 2;     // You promise that you not modify variables of the class.
            var = 2;        // car can be changed because its mutable.
            return m_X;
        }
        int getX() {        // You can have two versions of your function.
            return m_X;     // The printEntity() function will use the const version.
        }
        void setX(int x) {  // -> You use const for get-er but not for set-er functions.
            m_X = x;
        }
        const int* const getY() const { // You're returning a pointer that can not be modified,
            return m_Y;                 // the contents of the pointer can not be modified
        }                               // and this function promises not to modify the actual Entity class.
};

void printEntity(const Entity& e) {     // const reference (&), because you don't want to copy my object.
    // e = Entity();                    // You can not modify this object.
    std::cout << e.getX() << std::endl; // If you remove the const from the getX() function,
                                        // because the function does not guarantee that it don't touch the object.
}

int main()
{
    Entity e(4);

    int a = 1;
    a = 2;                  // modify the variable
    const int MAX_AGE = 90; // declare a constant instead of a variable variable
    // MAX_AGE = 95;        // then you're not allowed to do this
    printf("Hallo");        // The string is automaticaly a const char[], because its not a variable.

    int* b = new int;
    *b = 3;                 // dereference b to a value
    std::cout << *b << std::endl;
    b = &a;                 // reassign the actual pointer to another value
    std::cout << *b << std::endl;

    b = (int*)&MAX_AGE;     // reassign the actual pointer to a const (by cast it to a normal int pointer)
    /* This breaks the const promise, what you normally should not do, and what could crash */
    std::cout << *b << std::endl;

    /*
    * Add const in the front of a pointer means ...
    */
    const int* c = new int; // same as
    int const* c = new int; // ... you can't change the contents of that pointer.
    // *c = 4;              // But reading and dereferenceing ect is still okay:
    c = (int*)&MAX_AGE;
    std::cout << *c << std::endl;
    /* -> You can't change the data at the memory address but you can change the pointer. */

    /*
    * Add const after the pointer means ...
    */
    int* const d = new int; // ... you can change the contents of that pointer, but
    *d = 5;                 // ... you cant reassign the pointer:
    // d = (int*)&MAX_AGE;  //or
    // d = nullptr;
    std::cout << *d << std::endl;
    /* -> You can't change the memory address but you can change the data. */

    /*
    * Add const in front and after the pointer means ...
    */
    const int* const d = new int;   // ... you can't change the contents of that pointer, and
    // *d = 5;                      // ... you cant reassign the pointer:
    // d = (int*)&MAX_AGE;          //or
    // d = nullptr;
    std::cout << *d << std::endl;
    /* -> You can't change the memory address and you can't change the data. */

    /* const and constexpr: */
    size_t i = 5;
    size_t const j = 3;
    size_t constexpr k = 4;

    size_t const l = j + 4;         // may be computed at run-time
    size_t const m = i + 4;         // computed at run-time

    size_t constexpr n = k + 4;     // computed at compile time
    // size_t constexpr o = i + 4;  // not possible, because i is not constexpr

    size_t const p = foobar();      // works if foobar() returns size_t
    size_t constexpr q = foobar();  // only works if foobar() is constexpr
}