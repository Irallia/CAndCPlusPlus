#include <iostream>
using namespace std;

// Represent data by creat my own datatype, with the help of a class. (-> map a blueprint for your datatype)
class Book {
    public:
        string title;
        string author;
        int pages;
        // Constructors:
        Book() {
            title = "no title";
            author = "no author";
            pages = -1;
            cout << "Creating Book Object: " << title;
        }
        Book(string aTitle, string aAuthor, int aPages) {
            cout << "Creating Book Object: " << aTitle;
            title = aTitle;
            author = aAuthor;
            pages = aPages;
            cout << " with " << pages << " Pages." << endl;
        }
        // Class functions:
        bool isLongBook() {
            if (pages >= 1000)
            {
                return true;
            }
            return false;
        }
};

int main()
{
    // Now we create a book: (create an instance of our class, its an object specified by our class)
    Book book1("Harry Potter", "JK Rowling", 400);
    book1.pages = 500;

    cout << "Now it has " << book1.pages << " pages." << endl;

    Book book2("My Book", "Ira", 7000);
    Book book3;

    return 0;
}