/**------------------------------------------
    Program 1: ASCII Flowers
    Prompt for the number of flower layers and display

    Course: CS 141, Fall 2023
    System: Linux_x86_64 and G++
    Author: George Maratos and David Hayes
 ---------------------------------------------**/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // display the prompt to the user
    cout << "Program 1: ASCII Flowers\n"
         << "Choose from the following options:\n"
         << "   1. Display the HELLO graphic\n"
         << "   2. Display The Flower\n"
         << "   3. Exit the program\n"
         << "Your choice -> ";

    // read in the user's choice
    int menu_option;
    cin >> menu_option;

    // handle option to quit
    if (menu_option == 3) {
        exit(0);
    }

    // handle the HELLO graphic choice
    if (menu_option == 1) {
        char frame;
        cout << "Enter your frame character: ";
        cin >> frame;
        //top border
        cout << endl;
        for (int i=0; i<2; i++) {
            cout << setfill(frame) << setw(36) << ' ' << endl;
        }
        //message
        cout << setfill(frame) << setw(3) << right << " "
             << "** ** ***** **    **    *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** **    **    *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** **    **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "***** ***** **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "***** ***** **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** **    **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** ***** ***** *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** ***** ***** *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << right;
        //bottom border
        for (int i=0; i<2; i++) {
            cout << setfill(frame) << setw(36) << " " << endl;
        }
    }

    // handle the floral pattern TODO for students
    if (menu_option == 2) {
      
      // All variables set-up:
      int stage;
      int length;
      int pistil_space;
      int petal_space;
      string flower;
      string dash = "---";
      string pistil = "{@}";
      string petal = "{:}";
      string petal1;
      string petal2;
      string stem;
      string stem1 = "|/";
      string stem2 = "\\|";
      
      // Input set-up:
      cout << "Enter number of sections: " << endl;
      cin >> stage;
      
      // Calculations set-up:
      length = 3 + stage * 2; // Explain: 3 is the length of "pistil" ({@}), "stage" is the number which is the same number of ':' added to each side of '@' between the brackets in the largest "pistil" created, which is also the longest line of code in the program. In other words, the length of this line should become the maximum length of the code.
      petal_space = (length - petal.length()) / 2; // Explain: From the maximum length we have found, we can calculate the length of spaces it needs before the code to keep it in the center of the line it is on.
      dash.insert(0,stage,' '); // Explain: The length of spaces it needs for "dash" (---) results from the same calculation as mentioned, but since the length of "dash" is the same as the length of "pistil" as 3, it returns to be the "stage" itself.
      
      // Flower set-up
      for (int i = 0; i < stage; i++){
        
        cout << dash << endl;
        
        // Petal 1 set-up:
        // Explain: This loop helps create a pyramid of "petal" on top of "pistil".
        for (int j = 1; j <= i; j++){
          string K = petal;
          for (int k = 0; k < j; k++){
            petal1 = K.insert(1,2,':');
            petal1.insert(0,(petal_space - j),' ');
          }
          cout << petal1 << endl;
        }

        // Pistil set-up:
        flower = pistil.insert((2+i),1,':').insert((1+i),1,':'); // Explain: As the "flower" expands, 1 ':' is added to the right of '@', and 1 ':' is added to the right of the left bracket.
        flower.insert(0,((length - pistil.length()) / 2),' ');
        cout << flower << endl;

        // Petal 2 set-up:
        // Explain: This loop create an inverse pyramid of "petal" at the bottom of "pistil".
        for (int l = i; l >= 1; l--){
          string M = petal;
          for (int m = l; m > 0; m--){
            petal2 = M.insert(1,2,':');
            petal2.insert(0,(petal_space - l),' ');
          }
          cout << petal2 << endl;
        }  
      }

      cout << dash << endl;

      // Stem set-up:
      // Explain: This loop and if-statement structure help add the suitable selection between "stem1" and "stem2", and the spaces before it for each condition meets (whether it is even or odd).
      for (int n = 0; n < stage; n++){
        if (n%2 == 0){
          string O;
          O.insert(0,(stage + 1),' ');
          stem += O + stem1 + '\n' + O + '|' + '\n';
        } else{
          string P;
          P.insert(0,stage,' ');
          stem += P + stem2 + '\n' + P + ' ' + '|' + '\n';
        }
      }
      cout << stem << endl;  
    }
    return 0;
}