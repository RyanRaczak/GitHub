#include "Snake_H.h"

void snake::startUp() {
	gameOver = false;			 // Boolean to end game
	tailPrint = false;			 // Boolean to tell if tail was printed
	direction = gameInput::STOP; // the direction of the snake
	sHEADx = WIDTH / 2;			 // x position of the snake head
	sHEADy = HEIGHT / 2;		 // y position of the snake head
	score = 0;					 // players score
	sTAILx[100];				 // x position of the snake tail
	sTAILy[100];				 // y position of the snake tail
	lTAIL = 0;					 // will hold the length value of the tail
	prevTailx = 0;				 // will hold previous x position of tail
	prevTaily = 0;				 // will hold previous y position of tail
	prevTail2x = 0;				 // temporary hold for x tail
	prevTail2y = 0;				 // temporary hold for y tail
	prevTailx = sTAILx[0];		 // Initializing x tail
	prevTaily = sTAILy[0];		 // Initializing y tail
	fruitSpawn();				 // Calling fruit spawn function
}

void snake::print() {
	
	//Clearing screen for new print
	system("cls");

	//Printing Score and Player name
	cout << "Score: " << score << "\tHigh Score: " << hScore << endl;

	//Printing top wall
	for (int i = 0; i < WIDTH + 2; i++) {
		cout << "*";
	}

	//Ending top wall line
	cout << endl;

	//Printing Side walls
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {

			//Printing left wall
			if (w == 0) {
				cout << "*";
			}

			//PLAYABLE AREA
			//Print snake head
			if (h == sHEADy && w == sHEADx) {
				cout << "O";
			}

			//Print fruit
			else if (h == fPOSy && w == fPOSx) {
				cout << "+";
			}

			//Printing Tail & empty space
			else {
				
				//Printing Tail
				tailPrint = false;
				for (int i = 0; i < lTAIL; i++) {
					if (sTAILx[i] == w && sTAILy[i] == h) {
						cout << "o";
						tailPrint = true;
					}
				}

				//If tail was not printed, print empty space
				if (!tailPrint) {
					cout << " ";
				}
			}

			//Print right wall
			if (w == WIDTH - 1) {
				cout << "*";
			}
		}

		//Ending wall line
		cout << endl;
	}

	//Printing bottom wall
	for (int i = 0; i < WIDTH + 2; i++) {
		cout << "*";
	}

	//Ending bottom wall line
	cout << endl;

	//Control and player name
	cout << "Player: " << pName << "\n\n"
		 << "Controls: A=left, D=right, W=up, S=down, X=Restart";
}

void snake::getInput() {

	//Checking if key is pressed
	if (_kbhit()) {

		//Checking which character is pressed
		switch (_getch())
		{
		case 'a':
			direction = gameInput::LEFT;		// 'a' will be left
			break;
		case 'd':
			direction = gameInput::RIGHT;		// 'd' will be right
			break;
		case 'w':
			direction = gameInput::UP;			// 'w' will be up
			break;
		case 's':
			direction = gameInput::DOWN;		// 's' will be down
			break;
		case 'x':
			startUp();					// 'x' will exit the game
			break;
		default:
			break;
		}
	}
}

void snake::gameLogic() {

	//Setting up tail
	prevTailx = sTAILx[0];
	prevTaily = sTAILy[0];
	sTAILx[0] = sHEADx;
	sTAILy[0] = sHEADy;

	//Creating tail
	for (int i = 1; i < lTAIL; i++) {
		prevTail2x = sTAILx[i];
		prevTail2y = sTAILy[i];
		sTAILx[i] = prevTailx;
		sTAILy[i] = prevTaily;
		prevTailx = prevTail2x;
		prevTaily = prevTail2y;
	}

	//Chaning direction of the snake
	switch (direction)
	{
	case snake::gameInput::LEFT:
		sHEADx--;
		break;
	case snake::gameInput::RIGHT:
		sHEADx++;
		break;
	case snake::gameInput::UP:
		sHEADy--;
		break;
	case snake::gameInput::DOWN:
		sHEADy++;
		break;
	default:
		break;
	}

	//Making hitting walls end the game
	if (sHEADx > WIDTH || sHEADx < 0 || sHEADy > HEIGHT || sHEADy < 0) {
		gameOver = true;
	}

	//Making hitting tail end the game
	for (int i = 0; i < lTAIL; i++) {
		if (sTAILx[i] == sHEADx && sTAILy[i] == sHEADy) {
			gameOver = true;
		}
	}

	//Checking if snake head has touched fruit
	if (sHEADx == fPOSx && sHEADy == fPOSy) {
		score += 100;
		if (score > hScore) {
			hScore = score;
		}
		fruitSpawn();
		lTAIL++;
	}
}

void snake::fruitSpawn() {

	//Randomly placing fruit
	fPOSx = rand() % WIDTH;
	fPOSy = rand() % HEIGHT;
}

void snake::mainGame() {

	//Starting game
	startUp();

	//Getting player name
	bool nameChk = false;
	while (!nameChk) {
		try {
			system("cls");
			cout << "\t\tSNAKE"
				<< "\n\n\tWelcome to the game Snake.\n"
				<< "\nTo play simply collect the fruit 'x' and don't"
				<< "\n\thit the walls or your tail!"
				<< "\n\nControls: A = left, D = right, W = up, S = down, X = Restart"
				<< "\n\nPlease enter a player name(Max 10): ";
			cin >> pName;
			if (pName.length() <= 10) {
				nameChk = true;
			}
			else {
				throw "Name too long or short";
			}
		}
		catch (...) {
			cout << "\n\nPlease adhere to length limits.\n\n";
			system("pause");
		}
	}

	//Play again check
	bool playAgain = true;
	while (playAgain) {

		//Looping game
		while (!gameOver) {
			print();
			getInput();
			gameLogic();
			Sleep(100);
		}

		//Checking for play again
		bool entryChk = false;
		while (!entryChk) {

			//Clearing Screen
			system("cls");

			//Printing message
			cout << "\n\n\n\t\tYou have died!\n\t\tPlay again???\n\t\t(Y/N): ";
			cin >> death;

			//Checking for correct input
			if (toupper(death) == 'Y' || toupper(death) == 'N') {
				entryChk = true;

				//Resetting game
				startUp();

				//playAgain is deafult true, only changes to false if no is selected
				if (toupper(death) == 'N') {
					playAgain = false;
				}
			}

			//Error message for incorrect input
			else {
				cout << "Please enter Y or N";
				system("pause");
			}
		}	
	}
}

snake::snake() {

	//Default constructor
	gameOver = false;			 // Boolean to end game
	tailPrint = false;			 // Boolean to tell if tail was printed
	death = 'Y';				 // Holds players deicison to play again after gameover
	direction = gameInput::STOP; // the direction of the snake
	pName = "CPU";				 // the players name
	sHEADx = WIDTH / 2;			 // x position of the snake head
	sHEADy = HEIGHT / 2;		 // y position of the snake head
	score = 0;					 // players score
	hScore = 0;					 // Holds players High Score for remainder of application
	sTAILx[100];				 // x position of the snake tail
	sTAILy[100];				 // y position of the snake tail
	lTAIL = 0;					 // will hold the length value of the tail
	prevTailx = 0;				 // will hold previous x position of tail
	prevTaily = 0;				 // will hold previous y position of tail
	prevTail2x = 0;				 // temporary hold for x tail
	prevTail2y = 0;				 // temporary hold for y tail
	prevTailx = sTAILx[0];		 // Initializing x tail
	prevTaily = sTAILy[0];		 // Initializing y tail
}