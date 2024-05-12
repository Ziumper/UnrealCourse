// LiczbyZespolone.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
/*
● Napisz klasę reprezentującą liczbę zespoloną
● Klasa powinna zawierać:
○ Konstruktory: domyślny, parametryczny i kopiujący
○ Destruktor
○ Przeładowane operatory: +, -, *, /, =
○ metodę Print() służącą do wyświetlania liczby
● W funkcji main() przeprowadź testy zaimplementowanych operacji
*/

#include <iostream>
using namespace std;

class ComplexNumber
{
public:
    ComplexNumber() {};
    ComplexNumber(float _x, float _y, int _i = 1) : x(_x), y(_y), i(_i) {};
    ComplexNumber(const ComplexNumber& other) { x = other.x; y = other.y; }
    ~ComplexNumber() {}
    
    ComplexNumber operator+(const ComplexNumber& other)
    {
        ComplexNumber result;
        result.x = x + other.x;
        result.y = y + other.y;

        return result;
    }

    ComplexNumber& operator=(const ComplexNumber& other)
    {
        x = other.x;
        y = other.y;
        i = other.i;

        return *this;
    }

    ComplexNumber& operator*(const ComplexNumber& other)
    {
        x = x*other.x;
        y = y*other.y;
        i = other.i;

        return *this;
    }

    ComplexNumber& operator/(const ComplexNumber& other)
    {
        x = other.x;
        y = other.y;

        return *this;
    }

    ComplexNumber& operator-(const ComplexNumber& other)
    {
        x = x * other.x;
        y = y * other.y;
        i = other.i;

        return *this;
    }


    void Print() 
    {
        cout << x;

        if (y > 0) {
            cout << '+';
        }
        
        cout << y << 'i';
    }

private:
    float x = 0;
    float y = 0;
    int i = 1;

    void SimplifyImaginary() 
    {

    }
};

int main()
{
    cout << "Test print" << endl;
    ComplexNumber number(2, 1);
    number.Print();
    cout << endl << "=====" << endl;

    cout << "Test print z minusem" << endl;
    number = ComplexNumber(2, -3);
    number.Print();
    cout << endl << "=====" << endl;
    

    cout << "Test print imaginary pow number" << endl;
    number = ComplexNumber(2, -3, 5);
    number.Print();
    cout << endl << "=====" << endl;

    //dodawanie
    cout << "Test dodawania: ";
    ComplexNumber complex(2, 1);
    ComplexNumber complex2(3, 4);
    complex.Print();
    cout << " + ";
    complex2.Print();
    cout << " = ";
    number = ComplexNumber(2, 1) + ComplexNumber(3, 4);
    number.Print();
    cout << endl << "=====" << endl;

    //dodawanie z różnymi i
    cout << "Test dodawania z roznymi i: ";
    ComplexNumber complex(2, 1);
    ComplexNumber complex2(3, 4);
    complex.Print();
    cout << " + ";
    complex2.Print();
    cout << " = ";
    number = ComplexNumber(2, 1,2) + ComplexNumber(3, 4,5);
    number.Print();
    cout << endl << "=====" << endl;
    
    //odejmowanie
    number = ComplexNumber(2, 1) - ComplexNumber(3, 4);
    number.Print();
    cout << endl << "=====" << endl;

    //mnożenie
    number = ComplexNumber(2, 1) * ComplexNumber(3, 4);
    number.Print();
    cout << endl << "=====" << endl;

    //dzielenie
    number = ComplexNumber(2, 1) / ComplexNumber(3, 4);
    number.Print();
    cout << endl << "=====" << endl;


}

