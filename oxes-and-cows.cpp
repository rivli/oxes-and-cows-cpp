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

    numberOfDigitsPow = pow(10, numberOfDigits-1);
    srand (time(NULL));
    theNumber = rand() % numberOfDigitsPow + pow(10, numberOfDigits-1);

    string theStringNumber = to_string(theNumber);

    //cout << "theNumber = " + theStringNumber + "\n";

    //for (int i = numberOfDigits - 1; i >= 0; i--) cout << i << " - " << theNumberArray[i] << "\n";
    cout << "\n Okay, I got the number. Now start to guess it. Good luck! \n";

    bool didWin = false;
    int guessNum;
    int attemptsCounter=0;

    while (didWin == false) {
        string theStringNumberCopy = theStringNumber;
        cout << "Your number = ";
        cin >> guessNum;

        string guessedStringNum = to_string(guessNum);


        // First step - check if number have right digits number

        if (guessedStringNum.length() == numberOfDigits) {

            // Second step - check if the users number is even to guessed number

            if (guessedStringNum == theStringNumber) {//win
                didWin = true;
                cout << "Congratulations!! You won!! \n";
                cout << "Attempts - " << attemptsCounter << "\n";
            } else {

                // Here check for oxes and cows

                int oxes = 0, cows = 0;
                // Oxe means that one digit of users number exists on guessed number
                // Cow means that one digit of users number exists on guessed number but stays in a wrong place

                for (int i = 0; i < guessedStringNum.length(); i++) {
                    for (int y = 0; y < theStringNumberCopy.length(); y++) {
                        if (guessedStringNum[i] == theStringNumberCopy[y]) {
                            if (i == y) {
                                oxes++;
                            } else {
                                cows++;
                            }
                            theStringNumberCopy[y] = 'c'; // c - means that we already find this
                            //cout << theStringNumberCopy << "\n";
                        }
                    }
                }

                cout << "There is " << oxes << " oxes and " << cows << " cows. ";
                cout << "Try again \n";

            }

        } else {
            cout << "Digits number not equal. Try Again. ";
        }

        attemptsCounter++;
    }

    return 0;
}