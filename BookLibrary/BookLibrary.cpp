#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Unit {
private:
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
    void Add();
    void Delete();
    void Borrow();
    void Return();
};

enum class Action: char
{
    Add,
    Exit,
    Delete,
    Borrow,
    Return,

    SIZE
};


int main()
{
    cout << "Hello library v1.0!\n";

    Library library;
    Action action = Action::Add;
    while (action != Action::Exit)
    {
        cout << "What would you like to do?" << endl;
        int inputAction = 0;
        cin >> inputAction;

        action = (Action)inputAction;
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
        case Action::Return:
            library.Return();
            break;
        case Action::SIZE:
            break;
        default:
            break;
        }
    }
}

void Library::Add()
{
}

void Library::Delete()
{
}

void Library::Borrow()
{
}

void Library::Return()
{
}
