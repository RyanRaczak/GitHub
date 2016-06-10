#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

class snake {

	//Variables for movement
	enum class gameInput {
		STOP, LEFT, RIGHT, UP, DOWN
	};
	const int WIDTH = 30;  //Width of play area
	const int HEIGHT = 30; //Height of play area

public:

	void startUp();      // Setup startup variables for the game.
	void print();		 // determines where to draw the the game
	void getInput();	 // determines what directions user is inputing
	void gameLogic();	 // decides if the game is over, continuing, where fruit appears, etc
	void fruitSpawn();	 // Randomly spawns fruit for the snake
	void mainGame();     // serving as a "MAIN.CPP"
	snake();			 // default constructor

private:
	bool gameOver;		 // Boolean to end game
	bool tailPrint;		 // Boolean to tell if tail was printed
	char death;			 // Will hold decision to play again
	int sHEADx;			 // x position of the snake head
	int sHEADy;		     // y position of the snake head
	int sTAILx[100];	 // x position of the snake tail
	int sTAILy[100];	 // y position of the snake tail
	int lTAIL;			 // will hold the length value of the tail
	int prevTailx;		 // will hold previous x position of tail
	int prevTaily;		 // will hold previous y position of tail
	int prevTail2x;		 // temporary hold for x tail
	int prevTail2y;		 // temporary hold for y tail
	int fPOSx;		     // x position of the fruit
	int fPOSy;           // y position of the fruit
	int score;           // players score
	int hScore;			 // players high score
	gameInput direction; // the direction of the snake
	string pName;		 // Will hold the players name
};