#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> // Needed for transform
using namespace std;

class Book {
private:
    static int nextBookID;
    int bookID;
    string title;
    string author;
    bool isBorrowed;

public:
    Book(const string &title, const string &author) : title(title), author(author), isBorrowed(false) {
        bookID = nextBookID++;
    }

    virtual void displayDetails() const {
        cout << "Book ID: " << bookID << "\nTitle: " << title << "\nAuthor: " << author << "\nStatus: " 
             << (isBorrowed ? "Borrowed" : "Available") << endl;
    }

    virtual string getType() const = 0;

    int getBookID() const {
        return bookID;
    }

    bool getBorrowStatus() const {
        return isBorrowed;
    }

    void borrowBook() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << "Book borrowed successfully!" << endl;
        } else {
            cout << "Book is already borrowed!" << endl;
        }
    }

    void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << "Book returned successfully!" << endl;
        } else {
            cout << "Book is not borrowed!" << endl;
        }
    }
};

int Book::nextBookID = 1001;

class FictionBook : public Book {
public:
    FictionBook(const string &title, const string &author) : Book(title, author) {}

    void displayDetails() const override {
        Book::displayDetails();
        cout << "Genre: Fiction" << endl;
    }

    string getType() const override {
        return "Fiction";
    }
};

class NonFictionBook : public Book {
public:
    NonFictionBook(const string &title, const string &author) : Book(title, author) {}

    void displayDetails() const override {
        Book::displayDetails();
        cout << "Genre: Non-Fiction" << endl;
    }

    string getType() const override {
        return "Non-Fiction";
    }
};

class Library {
private:
    vector<Book*> books;

public:
    void addBook() {
        string title, author, type;
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
        cout << "Enter Book Type (Fiction/Non-Fiction): ";
        cin >> type;

        // Convert the type to lowercase
        transform(type.begin(), type.end(), type.begin(), ::tolower);

        Book* newBook = nullptr;
        if (type == "fiction") {
            newBook = new FictionBook(title, author);
        } else if (type == "non-fiction") {
            newBook = new NonFictionBook(title, author);
        } else {
            cout << "Invalid book type!" << endl;
            return;
        }

        books.push_back(newBook);
        cout << "Book added successfully!" << endl;
    }

    void removeBook(int bookID) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->getBookID() == bookID) {
                delete *it;
                books.erase(it);
                cout << "Book removed successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void borrowBook(int bookID) {
        for (Book* book : books) {
            if (book->getBookID() == bookID) {
                book->borrowBook();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void returnBook(int bookID) {
        for (Book* book : books) {
            if (book->getBookID() == bookID) {
                book->returnBook();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void displayAllBooks() const {
        cout << "Library Book List\n----------------------------\n";
        for (const Book* book : books) {
            book->displayDetails();
            cout << "----------------------------\n";
        }
    }

    ~Library() {
        for (Book* book : books) {
            delete book;
        }
    }
};

int main() {
    Library library;
    int choice, bookID;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Remove Book\n3. Borrow Book\n4. Return Book\n5. Display All Books\n6. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                cout << "Enter Book ID to remove: ";
                cin >> bookID;
                library.removeBook(bookID);
                break;
            case 3:
                cout << "Enter Book ID to borrow: ";
                cin >> bookID;
                library.borrowBook(bookID);
                break;
            case 4:
                cout << "Enter Book ID to return: ";
                cin >> bookID;
                library.returnBook(bookID);
                break;
            case 5:
                library.displayAllBooks();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    }
}
