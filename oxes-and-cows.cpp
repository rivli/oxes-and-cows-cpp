#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class MyNumber
{
private:
    int number, digitsNumber;
public:
    MyNumber(int Number);
    int* asArray();
    int getDigitsNumber();
    bool lengthIs(int length);
    ~MyNumber();
};

MyNumber::MyNumber(int Number)
{
    number = Number;
    int i = 0;
    while(Number > 0) {
        Number /= 10;
        i++;
    }
    digitsNumber = i;
};

int* MyNumber::asArray()
{
    int i = digitsNumber - 1;
    int Number = number, arrayNum[digitsNumber];
    while(Number > 0) {
        arrayNum[i] = Number % 10;
        Number /= 10;
        i--;
    }
    return arrayNum;
}

bool MyNumber::lengthIs(int length)
{
    return length == digitsNumber;
}

int MyNumber::getDigitsNumber() {
    return digitsNumber;
}

MyNumber::~MyNumber()
{
}

int main() {
    int numberOfDigits = 4, numberOfDigitsPow, numOfTryings = 0, i, theNumber;
    cout << "Choose the level - number of digits! = ";
    cin >> numberOfDigits;
    int theNumberArray[numberOfDigits];

    numberOfDigitsPow = pow(10, numberOfDigits);
    theNumber = rand() % numberOfDigitsPow;

    cout << "theNumber = " << theNumber << "\n";

    int Number = theNumber;
    i = numberOfDigits - 1;
    while(Number > 0) {
        theNumberArray[i] = Number % 10;
        Number /= 10;
        i--;
    }

    //for (int i = numberOfDigits - 1; i >= 0; i--) cout << i << " - " << theNumberArray[i] << "\n";
    cout << "\n Okay, I got the number. Now start to guess it. Good luck! \n";

    bool didWin = false;
    int guessNum;

    while (didWin == false) {
        cout << "Your number = ";
        cin >> guessNum;
        MyNumber guessedNumber(guessNum);


        // First step - check if number have right digits number

        if (guessedNumber.getDigitsNumber() == numberOfDigits) {

            // Second step - check if the users number is even to guessed number

            if (guessNum == theNumber) {//win
                didWin = true;
                cout << "Congratulations!! You won!! \n";
            } else {

                // Here check for oxes and cows
                int* guessedNumberArray;
                guessedNumberArray = guessedNumber.asArray();
                for (int i = guessedNumber.getDigitsNumber() - 1; i >= 0; i--) cout << i << " - " << guessedNumberArray[i] << "\n";

                cout << "Try again \n";

            }

        } else {
            cout << "Digits number not equal. Try Again. \n";
        }
    }

    return 0;
}