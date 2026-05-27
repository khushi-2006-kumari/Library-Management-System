#include<bits/stdc++.h>
using namespace std;

class Library {
private:
    string library_name;
    vector<string> list_of_books;
    map<string, string> lend_record;

public:
    Library(vector<string> books, string name) {
        list_of_books = books;
        library_name = name;
    }

    void display_books() {
        cout << "Books available:" << endl;
        for (string book : list_of_books) {
            cout << "- " << book << endl;
        }
    }

    void add_book() {
        string book;
        cout << "Enter book name to add: ";
        cin.ignore();
        getline(cin, book);
        list_of_books.push_back(book);
        cout << "Book added!" << endl;
    }

    void lend_book() {
        string book, name;
        cout << "Enter book name to lend: ";
        cin.ignore();
        getline(cin, book);

        auto it = find(list_of_books.begin(), 
                      list_of_books.end(), book);

        if (it != list_of_books.end()) {
            cout << "Enter your name: ";
            getline(cin, name);
            list_of_books.erase(it);
            lend_record[book] = name;
            cout << "Book lent!" << endl;
        } else {
            if (lend_record.count(book)) {
                cout << "Book is with: " 
                     << lend_record[book] << endl;
            } else {
                cout << "Book not found!" << endl;
            }
        }
    }

    void return_book() {
        string book;
        cout << "Enter book name to return: ";
        cin.ignore();
        getline(cin, book);

        if (lend_record.count(book)) {
            list_of_books.push_back(book);
            lend_record.erase(book);
            cout << "Book returned!" << endl;
        } else {
            cout << "Invalid input!" << endl;
        }
    }
};

int main() {
    vector<string> books = {
        "The Stranger", "Wings of Fire", 
        "Never Lie", "Dune", "The Plague"
    };
    Library Om_Library(books, "Om Library");

    while (true) {
        cout << "\nWelcome to Om Library!" << endl;
        cout << "1. Display  2. Return  ";
        cout << "3. Add  4. Lend  5. Exit" << endl;
        
        int choice;
        cin >> choice;

        if (choice == 5) break;
        else if (choice == 1) Om_Library.display_books();
        else if (choice == 2) Om_Library.return_book();
        else if (choice == 3) Om_Library.add_book();
        else if (choice == 4) Om_Library.lend_book();
    }
    return 0;
}
