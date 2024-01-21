//g++ 6_task.cpp -o 6_task
//Metelkin Maksim -> V = (int('M') * int('M')) % 8 -> 1 "Book"

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <string>
using namespace std;

class Book {
public:
    Book(int id, string title, int pageCount, float price) : id(id), title(title), pageCount(pageCount), price(price) {}
    int getId() const { return id; }
    string getTitle() const { return title; }
    int getPageCount() const { return pageCount; }
    float getPrice() const { return price; }

private:
    int id;
    string title;
    int pageCount;
    float price;
};

void addBook(vector<Book>& books) {
    int id;
    string title;
    int pageCount;
    float price;

    cout << "Enter book details:\n";
    if (books.empty()) {
        id = 1;
    } else {
        id = books.back().getId() + 1;
    }

    cout << "Title: ";
    cin.ignore();
    getline(cin, title);

    cout << "Page Count: ";
    cin >> pageCount;

    cout << "Price: ";
    cin >> price;

    Book newBook(id, title, pageCount, price);
    books.push_back(newBook);

    cout << "\nBook added successfully.\n";
}

void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books to display." << endl;
    } else {
        cout << "\nList of books:\n" << endl;
        for (const auto& book : books) {
            cout << "ID: " << book.getId() << ", Title: " << book.getTitle()
                      << ", Page Count: " << book.getPageCount() << ", Price: " << book.getPrice() << endl;
        }
    }
}

int selectSortingCriterion() {
    int choice;
    cout << "Select sorting criterion:\n";
    cout << "1. ID\n";
    cout << "2. Title\n";
    cout << "3. Page Count\n";
    cout << "4. Price\n";
    cout << "Your choice: ";
    cin >> choice;
    return choice;
}

void sortBooks(vector<Book>& books) {
    int criterion = selectSortingCriterion();

    switch (criterion) {
        case 1:
            sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
                return a.getId() < b.getId();
            });
            break;
        case 2:
            sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
                return a.getTitle() < b.getTitle();
            });
            break;
        case 3:
            sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
                return a.getPageCount() < b.getPageCount();
            });
            break;
        case 4:
            sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
                return a.getPrice() < b.getPrice();
            });
            break;
        default:
            cout << "Invalid choice.\n";
            return;
    }

    cout << "Books sorted successfully.\n";
}

void calculateTotalPages(const vector<Book>& books) {
    int totalPageCount = 0;

    for (const Book& book : books) {
        totalPageCount += book.getPageCount();
    }

    cout << "\nTotal number of pages in all books: " << totalPageCount << "\n";
}

void searchBook(const vector<Book>& books) {
    int searchChoice;
    cout << "Choose search parameter:\n";
    cout << "1. ID\n";
    cout << "2. Title\n";
    cout << "3. Page Count\n";
    cout << "4. Price\n";
    cout << "Your choice: ";
    cin >> searchChoice;

    switch (searchChoice) {
        case 1: {
            int targetId;
            cout << "Enter the ID to search for: ";
            cin >> targetId;
            auto it = find_if(books.begin(), books.end(), [targetId](const Book& book) {
                return book.getId() == targetId;
            });
            printSearchResult(*it);
            break;
        }
        case 2: {
            string targetTitle;
            cout << "Enter the title to search for: ";
            cin.ignore();
            getline(cin, targetTitle);
            auto it = find_if(books.begin(), books.end(), [targetTitle](const Book& book) {
                return book.getTitle() == targetTitle;
            });
            printSearchResult(*it);
            break;
        }
        case 3: {
            int targetPageCount;
            cout << "Enter the page count to search for: ";
            cin >> targetPageCount;
            auto it = find_if(books.begin(), books.end(), [targetPageCount](const Book& book) {
                return book.getPageCount() == targetPageCount;
            });
            printSearchResult(*it);
            break;
        }
        case 4: {
            float targetPrice;
            cout << "Enter the price to search for: ";
            cin >> targetPrice;
            auto it = find_if(books.begin(), books.end(), [targetPrice](const Book& book) {
                return book.getPrice() == targetPrice;
            });
            printSearchResult(*it);
            break;
        }
        default:
            cout << "Invalid choice.\n";
    }
}

void printSearchResult(const Book& book) {
    cout << "Book found:\n";
    cout << "ID: " << book.getId() << "\n";
    cout << "Title: " << book.getTitle() << "\n";
    cout << "Page Count: " << book.getPageCount() << "\n";
    cout << "Price: " << book.getPrice() << "\n";
}

void writeToFile(const vector<Book>& books, const string& filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cerr << "Unable to open the file: " << filename << endl;
        return;
    }

    for (const auto& book : books) {
        outFile << book.getId() << ' '
                << book.getTitle() << ' '
                << book.getPageCount() << ' '
                << book.getPrice() << '\n';
    }

    cout << "Books written to file: " << filename << endl;
    outFile.close();
}

void readFromFile(vector<Book>& books, const string& filename) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cerr << "Unable to open the file: " << filename << endl;
        return;
    }

    books.clear();

    int id, pageCount;
    float price;
    string title;

    while (inFile >> id >> title >> pageCount >> price) {
        Book newBook(id, title, pageCount, price);
        books.push_back(newBook);
    }

    cout << "Books read from file: " << filename << endl;
    inFile.close();
}

int main() {
    vector<Book> books;
    int choice;

    do {
        cout << "\n\n1. add book\n";
        cout << "2. display books\n";
        cout << "3. sort books\n";
        cout << "4. calculate pages\n";
        cout << "5. search books\n";
        cout << "6. write to file\n";
        cout << "7. read from file\n";
        cout << "8. exit\n";
        cout << "ur choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                displayBooks(books);
                break;
            case 3:
                sortBooks(books);
                break;
            case 4:
                calculateTotalPages(books);
                break;
            case 5:
                searchBook(books);
                break;
            case 6:
                writeToFile(books, "books.txt");
                break;
            case 7:
                readFromFile(books, "books.txt");
                break;
            case 8: {
                cout << "exiting the program.\n";
                break;
            }
            default: {
                cout << "\ninvalid character: " << choice << endl;
                break;
            }
        }
    } while (choice != 11);

}