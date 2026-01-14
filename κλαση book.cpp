#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    int id;

public:
    Book() {
        title = "";
        author = "";
        year = 0;
        id = 0;
    }

    Book(string t, string a, int y, int i) {
        title = t;
        author = a;
        year = y;
        id = i;
    }

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    int getId() const { return id; }

    // Setters
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setYear(int y) { year = y; }

    void display() const {
        cout << "ID: " << id
             << ", Τίτλος: " << title
             << ", Συγγραφέας: " << author
             << ", Έτος: " << year << endl;
    }
};
