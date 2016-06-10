#include "Snake_H.h"

enum menuStates {SNAKE = 1, PROJECT2, PROJECT3, EXIT};  //Variables for menu

void main() {

	//Classes
	snake game;

	//Setting default menu option
	int selection = -1;

	//Creating menu
	while (selection != EXIT) {
		try{
			
			//Clearing screen
			system("cls");

			//Priting menu
			cout << endl << "\t\t\tC++ Group Project"
				<< "\nSnake (1)"
				<< "\n\nProject 2 (2)"
				<< "\n\nProject 3 (3)"
				<< "\n\nExit (4)"
				<< "\n\n\nPlease enter your selection: ";
				cin >> selection;
				cout << endl;

				//Checking for entry error
				if (selection > 4 || selection < 1) {
					throw "Selection Error";
				}

				//Determining selection
				switch (selection){
				case SNAKE:
					game.mainGame();
					break;
				case PROJECT2:
					cout << "PROJECT 2"; //Change code for your project
					system("pause");	 //Change code for your project
					break;
				case PROJECT3:
					cout << "PROJECT 3"; //Change code for your project
					system("pause");     //Change code for your project
					break;
				case EXIT:
					cout << "EXIT";
					system("pause");
					break;
				default:
					break;
				}
		}

		//Printing selection error message
		catch (...){
			cout << "Please select an option from the menu.\n\n";
			system("pause");
		}
	}
}