class Library {
private:
    Book* books;
    int size;

public:
    Library() {
        books = nullptr;
        size = 0;
    }

    ~Library() {
        delete[] books;
    }

    // Προσθήκη βιβλίου
    void addBook(const Book& b) {
        Book* temp = new Book[size + 1];

        for (int i = 0; i < size; i++) {
            temp[i] = books[i];
        }

        temp[size] = b;

        delete[] books;
        books = temp;
        size++;
    }

    // Εμφάνιση βιβλίων
    void displayBooks() const {
        if (size == 0) {
            cout << "Η βιβλιοθήκη είναι άδεια.\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            books[i].display();
        }
    }

    // Αναζήτηση με ID
    int searchById(int id) const {
        for (int i = 0; i < size; i++) {
            if (books[i].getId() == id)
                return i;
        }
        return -1;
    }

    // Επεξεργασία βιβλίου
    void editBook(int id) {
        int index = searchById(id);

        if (index == -1) {
            cout << "Το βιβλίο δεν βρέθηκε.\n";
            return;
        }

        string newAuthor;
        int newYear;

        cout << "Νέος συγγραφέας: ";
        getline(cin, newAuthor);

        cout << "Νέο έτος: ";
        cin >> newYear;
        cin.ignore();

        books[index].setAuthor(newAuthor);
        books[index].setYear(newYear);

        cout << "Το βιβλίο ενημερώθηκε.\n";
    }

    // Διαγραφή βιβλίου
    void deleteBook(int id) {
        int index = searchById(id);

        if (index == -1) {
            cout << "Το βιβλίο δεν βρέθηκε.\n";
            return;
        }

        Book* temp = new Book[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) {
                temp[j++] = books[i];
            }
        }

        delete[] books;
        books = temp;
        size--;

        cout << "Το βιβλίο διαγράφηκε.\n";
    }

    // Ταξινόμηση βάσει τίτλου
    void sortByTitle() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j].getTitle() > books[j + 1].getTitle()) {
                    swap(books[j], books[j + 1]);
                }
            }
        }
    }

    // Ταξινόμηση βάσει έτους
    void sortByYear() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j].getYear() > books[j + 1].getYear()) {
                    swap(books[j], books[j + 1]);
                }
            }
        }
    }
};
