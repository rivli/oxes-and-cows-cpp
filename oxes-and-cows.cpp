#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>
#include <string>

using namespace std;

int main() {
    int numberOfDigits = 4, numberOfDigitsPow, numOfTryings = 0, i, theNumber;
    cout << "Choose the level - number of digits! = ";
    cin >> numberOfDigits;

    numberOfDigitsPow = pow(10, numberOfDigits);
    srand (time(NULL));
    theNumber = rand() % numberOfDigitsPow;

    string theStringNumber = to_string(theNumber);

    cout << "theNumber = " + theStringNumber + "\n";

    //for (int i = numberOfDigits - 1; i >= 0; i--) cout << i << " - " << theNumberArray[i] << "\n";
    cout << "\n Okay, I got the number. Now start to guess it. Good luck! \n";

    bool didWin = false;
    int guessNum;

    while (didWin == false) {
        cout << "Your number = ";
        cin >> guessNum;

        string guessedStringNum = to_string(guessNum);


        // First step - check if number have right digits number

        if (guessedStringNum.length() == numberOfDigits) {

            // Second step - check if the users number is even to guessed number

            if (guessedStringNum == theStringNumber) {//win
                didWin = true;
                cout << "Congratulations!! You won!! \n";
            } else {

                // Here check for oxes and cows
                // for (int i = guessedStringNum.length() - 1; i >= 0; i--) cout << i << " - " << guessedStringNum[i] << "\n";

                cout << "Try again \n";

            }

        } else {
            cout << "Digits number not equal. Try Again. \n";
        }
    }

    return 0;
}