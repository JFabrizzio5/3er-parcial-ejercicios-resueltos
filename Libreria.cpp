#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    int year;
};

struct BorrowRecord {
    string borrower;
    string isbn;
    string borrowDate;
    string returnDate;
};

void addBook(vector<Book>& books, const Book& book) {
    books.push_back(book);
}

void listBooks(const vector<Book>& books) {
    for (vector<Book>::const_iterator it = books.begin(); it != books.end(); ++it) {
        cout << "Title: " << it->title << ", Author: " << it->author
             << ", ISBN: " << it->isbn << ", Year: " << it->year << endl;
    }
}

void findBookByTitle(const vector<Book>& books, const string& title) {
    for (vector<Book>::const_iterator it = books.begin(); it != books.end(); ++it) {
        if (it->title == title) {
            cout << "Found book - Title: " << it->title << ", Author: " << it->author
                 << ", ISBN: " << it->isbn << ", Year: " << it->year << endl;
            return;
        }
    }
    cout << "Book not found" << endl;
}

void removeBookByISBN(vector<Book>& books, const string& isbn) {
    for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
        if (it->isbn == isbn) {
            books.erase(it);
            cout << "Book with ISBN " << isbn << " removed" << endl;
            return;
        }
    }
    cout << "Book not found" << endl;
}

void addBorrowRecord(vector<BorrowRecord>& records, const BorrowRecord& record) {
    records.push_back(record);
}

void listBorrowRecords(const vector<BorrowRecord>& records) {
    for (vector<BorrowRecord>::const_iterator it = records.begin(); it != records.end(); ++it) {
        cout << "Borrower: " << it->borrower << ", ISBN: " << it->isbn
             << ", Borrow Date: " << it->borrowDate << ", Return Date: " << it->returnDate << endl;
    }
}

int main() {
    vector<Book> books;
    vector<BorrowRecord> borrowRecords;

    Book book1 = {"The Catcher in the Rye", "J.D. Salinger", "978-0-316-76948-0", 1951};
    Book book2 = {"1984", "George Orwell", "978-0-452-28423-4", 1949};

    addBook(books, book1);
    addBook(books, book2);

    cout << "Listing all books:" << endl;
    listBooks(books);

    BorrowRecord record1 = {"John Doe", "978-0-316-76948-0", "2023-06-01", "2023-06-15"};
    addBorrowRecord(borrowRecords, record1);

    cout << "\nListing all borrow records:" << endl;
    listBorrowRecords(borrowRecords);

    cout << "\nSearching for book titled '1984':" << endl;
    findBookByTitle(books, "1984");

    cout << "\nRemoving book with ISBN '978-0-452-28423-4':" << endl;
    removeBookByISBN(books, "978-0-452-28423-4");

    cout << "\nListing all books after removal:" << endl;
    listBooks(books);

    return 0;
}

