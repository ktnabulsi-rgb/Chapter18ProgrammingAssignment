#include <iostream>
#include <string>
#include "DisplayMenu.h"
#include "LinkedList.h"
#include <iomanip>
#include <limits>
#include <string.h>

using namespace std;


int main() {
    int menuChoice; // make a menuchoice var
    DisplayMenu m1; // create new objects
    LinkedList l1;
    int menuCtr = 0;

    // instantiate array to hold valid input names
    string metalNames[] = {"turquoise", "coral", "gold", "copper"};
    int metalNamesLength = sizeof(metalNames) / sizeof(metalNames[0]);
    // make ptr for accessing array values
    string *ptr = metalNames;
    bool validInput = false;

    do {
        if (menuCtr == 0) {
            m1.displayMenuFirstMsg();
            menuCtr++;
        } else {
            // separate menu msgs
            m1.displayMenuAfterMsg();
        }

        // get the user's menu choice
        while (!(cin >> menuChoice)) {
            // validate that the input is a number
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Enter a number only please. " << endl;
        }

        // switch to handle the user's choice.
        string input = "";
        int input2;
        switch (menuChoice) {
            case 1: {
                cout << "Enter bead material: " << endl;
                cin >> input;
                // make input lowerCase to keep everything simple
                m1.toLowerCase(input);
                while (!validInput) {
                    for (int i = 0; i < metalNamesLength; i++) {
                        // loop through metal names array and find the same name as input
                        if (input == *(ptr + i)) {
                            // this means strings are the same
                            validInput = true;
                            break;
                        }
                    }
                    if (validInput == true) {
                        break;
                    }
                    // if input isnt valid print msg and restart
                    cout << input << " is not a metal we carry...try again. " << endl;
                    cin >> input;
                    m1.toLowerCase(input);
                }
                validInput = false;
                l1.appendList(input); // call append method after input is validated
                break;
            }
            case 2: {
                // same logic here
                cout << "Enter bead material: " << endl;
                cin >> input;
                m1.toLowerCase(input);
                while (!validInput) {
                    for (int i = 0; i < metalNamesLength; i++) {
                        if (input == *(ptr + i)) {
                            // this means strings are the same
                            validInput = true;
                            break;
                        }
                    }
                    if (validInput == true) {
                        break;
                    }
                    cout << input << " is not a metal we carry...try again. " << endl;
                    cin >> input;
                    m1.toLowerCase(input);
                }
                validInput = false;
                cout << "Enter Insert Position: " << endl;

                while (!(cin >> input2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Enter a number only please. " << endl;
                }

                //if method returns -1, pos doesnt exist
                if (l1.insertList(input, input2) == -1) {
                    cout << "I am sorry but bead position " << input2 << " does not exist." << endl;
                }
                else {
                    cout << "Thank you - a " << input << " bead has been inserted at position " << input2 << "." << endl;
                }

                break;
            }

            case 3: {
                cout << "What bead position do you wish to delete? " << endl;
                while (!(cin >> input2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Enter a number only please. " << endl;
                }
                if (l1.deleteNode(input2) == -1) {
                    cout << "I am sorry but node (" << input2 << ") does not exist." << endl;
                } else {
                    cout << "Node (" << input2 << ") has been deleted from your list. " << endl;

                }
                break;
            }
            case 4: {
                l1.display();
                break;
            }
            case 5: {
                // no input validation needed here since we are searching
                cout << "Enter color to search for: " << endl;
                cin >> input;
                m1.toLowerCase(input);
                l1.searchList(input);
                break;
            }
            case 6: {
                // print exit statement
                cout << "Exiting..." << endl;
                cout << "Thanks for using the menu system and have a nice day." << endl;
                exit(0);
            }
            default: {
                // handle invalid menu option entries
                cout << "That Is Not A Valid Option, Please Choose An Option From The Numbered Menu Below: "
                     << endl;
                cout << endl;
                break;
            }
        }

    } while (menuChoice != 6); // continue presenting the menu until the user chooses to exit
    return 0;
}