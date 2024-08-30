#include <iostream>
#include <vector>
#include <windows.h>
#include <limits>
using namespace std;

class Book {
private:
    string title, author;
    int year;

public:
    // Constructor
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    // Getters
    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getYear() { return year; }

    // Function to display book
    void displayBook() {
        cout << "\n      ------------------";
        cout << "\n\n\tTitle: " << title
             << "\n\tAuthor: " << author
             << "\n\tYear: " << year << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    // Function to add book
    void addBook(string title, string author, int year) {
        Book newBook(title, author, year);
        books.push_back(newBook);
    }

    // Function to display all books
    void displayAllBooks() {
        if (books.empty()) {
            cout << "\n\tNo books available." << endl;
            return;
        }
        for (Book i : books) {
            i.displayBook();
        }
    }

    // Function to search a book
    void searchBook(string title) {
        for (Book i : books) {
            if (i.getTitle() == title) {
                cout << "\n\t  Book found.";
                i.displayBook();
                return;
            }
        }
        cout << "\n\t  Book not found." << endl;
    }
};

int main() {
    Library library;
    int choice, year;
    string title, author;
    char backToMenu;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);  // for text color

    do {
        SetConsoleTextAttribute(h, 14);
        cout << "\tMENU\n\n";
        SetConsoleTextAttribute(h, 6);
        cout << "  1 - Add Book\n";
        cout << "  2 - Display All Books\n";
        cout << "  3 - Search Book\n";
        cout << "  4 - Exit\n";

        // Input validation 
        cout << "  Enter choice: ";
        while (!(cin >> choice)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            SetConsoleTextAttribute(h, 12); 
            cout << "\n  Invalid input. Please enter a number: ";
            SetConsoleTextAttribute(h, 6); 
        }

        cin.ignore(); 

        switch (choice) {
        case 1: {
            SetConsoleTextAttribute(h, 14);
            cout << "\n  ---------Adding a Book--------\n";
            cout << "\n  Enter book title: ";
            getline(cin, title);
            cout << "\n  Enter author: ";
            getline(cin, author);
            cout << "\n  Enter year published: ";
            cin >> year;
            cin.ignore(); 
            library.addBook(title, author, year);
            break;
        }
        case 2: {
            SetConsoleTextAttribute(h, 14);
            cout << "\n\t    BOOKS: ";
            library.displayAllBooks();
            break;
        }
        case 3: {
            SetConsoleTextAttribute(h, 14);
            cout << "\n  Enter book title to search: ";
            getline(cin, title);
            library.searchBook(title);
            break;
        }
        case 4: {
            cout << "\n  Exiting program.\n";
            return 0;
        }
        default: {
            SetConsoleTextAttribute(h, 12); 
            cout << "\n  Invalid input." << endl;
            SetConsoleTextAttribute(h, 6); 
            break;
        }
        }
		cout<<endl;
        system("PAUSE");
        system("CLS");

    } while (choice != 4);

    return 0;
}
