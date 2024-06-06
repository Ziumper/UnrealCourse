#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Unit {
public:
    Unit();
    Unit(const string& title, const string& author,
        const string& publicationDate,
        const string& ISBN,
        const string& summary,
        const vector<string>& subjects)
        : m_title(title), m_author(author), m_publicationDate(publicationDate), m_ISBN(ISBN), m_summary(summary), m_subjects(subjects)
    {};

    string GetISBN() { return m_ISBN; }
    void Print();
protected:
    string m_title;
    string m_author;
    string m_publicationDate;
    string m_ISBN;
    string m_summary;
    vector<string> m_subjects;
};


class Library
{
public:
    void Add(Unit& unit);
    void Add();
    void Delete();
    void Borrow();
    void Return();
    void Print();
private:
    map<string, Unit> m_books;
    map<string, Unit> m_borrowedBooks;
};

enum class Action: char
{
    Add,
    Delete,
    Borrow,
    Return,
    Print,
    Exit,
};


int main()
{
    cout << "Hello library v1.0!\n";

    Library library;

    vector<string> subjects1 = { "Fiction", "Adventure" };
    Unit book1("The Hobbit", "J.R.R. Tolkien", "1937", "978-0547928227", "A fantasy novel about a hobbit's adventure.", subjects1);

    vector<string> subjects2 = { "Science", "Non-fiction" };
    Unit book2("A Brief History of Time", "Stephen Hawking", "1988", "978-0553380163", "A popular-science book on cosmology.", subjects2);

    vector<string> subjects3 = { "Fantasy", "Magic" };
    Unit book3("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "1997", "978-0747532699", "A young wizard's journey begins.", subjects3);

    vector<string> subjects4 = { "Historical Fiction" };
    Unit book4("War and Peace", "Leo Tolstoy", "1869", "978-0199232765", "A novel about the French invasion of Russia.", subjects4);

    vector<string> subjects5 = { "Dystopian", "Science Fiction" };
    Unit book5("1984", "George Orwell", "1949", "978-0451524935", "A novel about a dystopian future.", subjects5);

    vector<string> subjects6 = { "Romance" };
    Unit book6("Pride and Prejudice", "Jane Austen", "1813", "978-1503290563", "A classic novel about love and social standing.", subjects6);

    vector<string> subjects7 = { "Philosophy" };
    Unit book7("The Republic", "Plato", "380 BC", "978-0140455113", "A Socratic dialogue concerning justice.", subjects7);

    vector<string> subjects8 = { "Fantasy", "Epic" };
    Unit book8("The Lord of the Rings", "J.R.R. Tolkien", "1954", "978-0618640157", "An epic fantasy trilogy.", subjects8);

    vector<string> subjects9 = { "Science Fiction" };
    Unit book9("Dune", "Frank Herbert", "1965", "978-0441013593", "A science fiction novel set in a distant future.", subjects9);

    vector<string> subjects10 = { "Mystery", "Thriller" };
    Unit book10("The Da Vinci Code", "Dan Brown", "2003", "978-0307474278", "A mystery thriller novel.", subjects10);

    vector<string> subjects11 = { "Fantasy", "Young Adult" };
    Unit book11("Percy Jackson & the Olympians: The Lightning Thief", "Rick Riordan", "2005", "978-0786838653", "A young adult fantasy novel.", subjects11);

    vector<string> subjects12 = { "Historical Fiction" };
    Unit book12("The Book Thief", "Markus Zusak", "2005", "978-0375842207", "A historical novel set in Nazi Germany.", subjects12);

    vector<string> subjects13 = { "Fantasy", "Adventure" };
    Unit book13("The Name of the Wind", "Patrick Rothfuss", "2007", "978-0756404741", "A fantasy novel about a young wizard.", subjects13);

    vector<string> subjects14 = { "Biography" };
    Unit book14("Steve Jobs", "Walter Isaacson", "2011", "978-1451648539", "A biography of Steve Jobs.", subjects14);

    vector<string> subjects15 = { "Horror", "Thriller" };
    Unit book15("The Shining", "Stephen King", "1977", "978-0307743657", "A horror novel set in a haunted hotel.", subjects15);

    library.Add(book1);
    library.Add(book2);
    library.Add(book3);
    library.Add(book4);
    library.Add(book5);
    library.Add(book6);
    library.Add(book7);
    library.Add(book8);
    library.Add(book9);
    library.Add(book10);
    library.Add(book11);
    library.Add(book12);
    library.Add(book13);
    library.Add(book14);
    library.Add(book15);


    Action action = Action::Add;
    while (action != Action::Exit)
    {
        cout << "What would you like to do?" << endl;
        cout << "1. Add book to library" << endl;
        cout << "2. Delete book from library" << endl;
        cout << "3. Borrow book from library" << endl;
        cout << "4. Return book to library" << endl;
        cout << "5. Print books in library and borrowed books" << endl;
        cout << "6. Exit the hello library v1.0" << endl;
        int inputAction = 0;
        cin >> inputAction;

        action = (Action)(inputAction - 1);
        switch (action)
        {
        case Action::Add:
            library.Add();
            break;
        case Action::Exit:
            break;
        case Action::Delete:
            library.Delete();
            break;
        case Action::Borrow:
            library.Borrow();
            break;
        case Action::Print:
            library.Print();
            break;
        case Action::Return:
            library.Return();
            break;
        default:
            break;
        }
    }
}

void Library::Add(Unit& unit)
{
    m_books.emplace(unit.GetISBN(), unit);
}

void Library::Add()
{
    Unit unit;
    m_books.emplace(unit.GetISBN(), unit);
}

void Library::Delete()
{
    cout << "Provide ISBN of libary unit to delete" << endl;
    string isbn;
    cin >> isbn;

    auto result = m_books.find(isbn);
    if (result != m_books.end())
    {
        m_books.erase(result);
        cout << "Library unit with provided ISBN " << isbn << " has been deleted" << endl;
    }
    else 
    {
        cout << "Libary not found" << endl;
    }
}

void Library::Borrow()
{
    cout << "Provide ISBN of Library unit to borrow" << endl;
    string isbn;
    cin >> isbn;

    auto result = m_books.find(isbn);
    if (result != m_books.end())
    {
        m_borrowedBooks.emplace(isbn, result->second);
        m_books.erase(result);
        cout << "Books has been borrowed" << endl;
    }
    else 
    {
        cout << "Book has been not found in library" << endl;
    }
}

void Library::Return()
{
    cout << "Provide ISBN of Library unit to return" << endl;
    string isbn;
    cin >> isbn;

    auto result = m_borrowedBooks.find(isbn);
    if (result != m_borrowedBooks.end())
    {
        m_books.emplace(isbn, result->second);
        m_borrowedBooks.erase(result);
    }
    else {
        cout << "Book not found in borrowed books" << endl;
    }
}

void Library::Print()
{
    if (m_books.size() > 0)
    {
        cout << "Here goes your hello library books" << endl;

        for (auto& unit : m_books) {
            unit.second.Print();
        }
    }
    
    cout << endl;
    
    if (m_borrowedBooks.size() > 0)
    {
        cout << "Here goes your hello borrowed books" << endl;
        for (auto& unit : m_borrowedBooks)
        {
            unit.second.Print();
        }
    }
}

Unit::Unit()
{

    cout << "Provide information about the library unit" << endl;
    cin.ignore();
    cout << "Provide title: " << endl;
    getline(cin, m_title);

    cout << "Provide author: " << endl;
    getline(cin, m_author);

    cout << "Provide publication date: " << endl;
    getline(cin, m_publicationDate);

    cout << "Provide ISBN: " << endl;
    getline(cin, m_ISBN);

    cout << "Provide summary: " << endl;
    getline(cin, m_summary);

    cout << "How many subjects would you like to add?" << endl;
    int size = 0;
    cin >> size;
    cin.ignore();

    m_subjects.reserve(size);
    for (int i = 0; i < size; i++)
    {
        string subject;
        cout << "Provide subject number " << i + 1 << ": " << endl;
        getline(cin, subject);
        m_subjects.push_back(subject);
    }

    cout << "Book has been created successfully" << endl;
}

void Unit::Print()
{
    cout << "======================================================================" << endl;
    cout << "Title: " << m_title << ", Author: " << m_author << ", Publication date: " << m_publicationDate << endl;
    cout << "ISBN: " << m_ISBN << ", summary: " << m_summary << "Subject keys: ";
    for (auto& subject : m_subjects)
    {
        cout << subject << ", ";
    }

    cout << endl;
}

