#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string Author;
    string Text;
    int Pages;
    int Year;

public:
    Book() : Pages(0), Year(0) {}

    Book(const string &author, const string &text, int pages, int year)
        : Author(author), Text(text), Pages(pages), Year(year) {}

    Book(const Book &obj) = delete;
    Book &operator=(const Book &obj) = delete;

    Book(Book &&obj)
        : Author(move(obj.Author)),
          Text(move(obj.Text)),
          Pages(obj.Pages),
          Year(obj.Year)
    {
        obj.Pages = 0;
        obj.Year = 0;
    }

    Book &operator=(Book &&obj)
    {
        if (this != &obj)
        {
            Author = move(obj.Author);
            Text = move(obj.Text);
            Pages = obj.Pages;
            Year = obj.Year;

            obj.Pages = 0;
            obj.Year = 0;
        }
        return *this;
    }

    void Input()
    {
        cout << "Author: ";
        cin.ignore();
        getline(cin, Author);

        cout << "Text: ";
        getline(cin, Text);

        cout << "Pages: ";
        cin >> Pages;

        cout << "Year: ";
        cin >> Year;
    }

    void Print() const
    {
        cout << "Author: " << (Author.empty() ? "N/A" : Author) << endl;
        cout << "Text: " << (Text.empty() ? "N/A" : Text) << endl;
        cout << "Pages: " << Pages << endl;
        cout << "Year: " << Year << endl;
    }
};

int main()
{
    Book book1;
    book1.Input();
    book1.Print();

    cout << "\nMoving book1 to book2:\n";
    Book book2 = move(book1);
    book2.Print();

    cout << "\nAssigning book2 to book3:\n";
    Book book3;
    book3 = move(book2);
    book3.Print();
}