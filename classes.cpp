#include <iostream>
using namespace std;

// Represent data by creat my own datatype, with the help of a class. (-> map a blueprint for your datatype)
class Book {
    // only code thats inside the class Book can access whats in private:
    private:
        // if you want to print out the rating in the main function, it doesn't work
        string rating;
    public:
        string title;
        string author;
        int pages;
        // Constructors:
        Book() {
            title = "no title";
            author = "no author";
            pages = -1;
            rating = "NR";
            cout << "Creating Book Object: " << title << endl;
        }
        Book(string aTitle, string aAuthor, int aPages, string aRating) {
            cout << "Creating Book Object: " << aTitle << endl;
            title = aTitle;
            author = aAuthor;
            pages = aPages;
            setRating(aRating);
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
        // get-ers and set-ers:
        // use set functions to set up some rules:
        void setRating(string aRating) {
            if (aRating == "G" || aRating == "PG" || aRating == "PG-13" || aRating == "R" || aRating == "NR") {
                rating = aRating;
            } else {
                clog << "--- You set an invalid rating. ---" << endl;
                rating = "NR";
            }
        }
        // for private variables:
        string getRating() {
            return rating;
        }
};

int main()
{
    // Now we create a book: (create an instance of our class, its an object specified by our class)
    Book book1("Harry Potter", "JK Rowling", 400, "PG-13");
    book1.pages = 500;
    cout << "Now it has " << book1.pages << " pages." << endl;

    // cout << book1.rating << endl;
    // inaccessible, because rating is private:
    // but:
    book1.setRating("Dog");
    cout << book1.getRating() << endl;

    Book book2("My Book", "Ira", 7000, "bla");
    Book book3;

    cout << "Which of our books is long?" << endl;
    Book books[] = {book1, book2, book3};

    for (int i = 0; i < 3; i++) {
        if (books[i].isLongBook()) {
            cout << books[i].title << " is " << books[i].pages << " long." << endl;
        } else {
            cout << books[i].title << " is " << books[i].pages << " short." << endl;
        }
    };

    cout << " ------------------ " << endl;

    // With C++11 you can use a range-based for loop:
    for (auto& book_i : books) {
        if (book_i.isLongBook()) {
            cout << book_i.title << " is " << book_i.pages << " long." << endl;
        } else {
            cout << book_i.title << " is " << book_i.pages << " short." << endl;
        }
    }
    // Here auto automatically deduces the correct type. You could have written Book const& book_i instead.

    return 0;
}