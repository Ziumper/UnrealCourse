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
    ComplexNumber(float _real, float _imaginary) : real(_real), imaginary(_imaginary) {};
    ComplexNumber(const ComplexNumber& other) { real = other.real; imaginary = other.imaginary; }
    ~ComplexNumber() {}
    
    ComplexNumber operator+(const ComplexNumber& other)
    {
        ComplexNumber result;
        result.real = real + other.real;
        result.imaginary = imaginary + other.imaginary;

        return result;
    }

    ComplexNumber& operator=(const ComplexNumber& other)
    {
        real = other.real;
        imaginary = other.imaginary;

        return *this;
    }

    //(a + bi)*(x + yi) = ax + ayi + bix + biyi =
    // (ax + by*(-1)) + (ayi+ bix)
    ComplexNumber operator*(const ComplexNumber& other)
    {
        float ax = real * other.real;
        float ayi = real * other.imaginary;

        float bix = imaginary * other.real;

        float by = imaginary * other.imaginary * (-1);
      
        ComplexNumber number;
        number.real = ax + by;
        number.imaginary = ayi + bix;

        return number;
    }

    //mnożenie licznika i mianownika przez sprzężenie
    //liczby zespolonej
    ComplexNumber operator/(const ComplexNumber& other)
    {
        ComplexNumber coupling(other.real, other.imaginary * (-1));
        
        ComplexNumber numerator = coupling * *this;
        ComplexNumber denominator =  coupling * other;

        ComplexNumber number;
        number.real = numerator.real / denominator.real;
        number.imaginary = numerator.imaginary / denominator.real;

        return number;
    }

    ComplexNumber operator-(const ComplexNumber& other)
    {
        ComplexNumber number;
        number.real = real - other.real;
        number.imaginary = imaginary - other.imaginary;

        return number;
    }


    void Print() 
    {
        if (real != 0) {
            cout << real;
        }
        
        if (imaginary > 0 && real != 0) {
            cout << '+';
        }
        else if (imaginary == -1) {
            cout << '-';
        }
        
        if (imaginary != -1 && imaginary != 1 && imaginary != 0) {
            cout << imaginary;
        }
        
        if (imaginary != 0) {
            cout << 'i';
        }
    }

private:
    float real = 0;
    float imaginary = 0;
};

void TestOperation(char operationSign, ComplexNumber number1, ComplexNumber number2) {

    cout << "(";
    number1.Print();
    cout << ")";

    cout << operationSign; 

    cout << "(";
    number2.Print();
    cout << ")";

    cout << '=';

    ComplexNumber numberResult;
    switch (operationSign)
    {
        case '+':
            numberResult = number1 + number2;
            break;
        case '-':
            numberResult = number1 - number2;
            break;
        case '/':
            numberResult = number1 / number2;
            break;
        case '*':
            numberResult = number1 * number2;
            break;
        default:
            numberResult = number1;
            break;
    }
    
    numberResult.Print();

    cout << endl;
}

int main()
{
    ComplexNumber number1(2, 3);
    ComplexNumber number2(3, -2);

    
    cout << "Testing print" << endl;
    number1.Print();
    cout << endl << "=====" << endl;
    number2.Print();
    cout << endl << "=====" << endl;

    ComplexNumber copy(number1);
    cout << "Testing copy of number1" << endl;
    cout << "original:"; number1.Print();
    cout << endl << "copy:"; copy.Print(); cout << endl;

    TestOperation('*', number2, ComplexNumber(3,2)); //test sprzężenia = 13

    TestOperation('+', number1, number2);
    TestOperation('-', number1, number2);
    TestOperation('*', number1, number2);
    TestOperation('/', number1, number2); 
    TestOperation('/', ComplexNumber(1, 8), ComplexNumber(2, 3)); //2+i

}

