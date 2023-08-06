//includes
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<unistd.h>   

//namespaces
using namespace std;

//variable
int w = 60; //width of map
int l = 20; //length of map
int rowX[100];
int rowY[100];
int adding = 2;

bool gameOver = false;
//The coordinates of the snake's head
int x = w/2;
int y = l/2;

//make random fruit x y
int fruit_x = rand() % 58;
int fruit_y = rand() % 18;

enum mNew {
	stop=0, RIGHT, LEFT, UP, DOWN
};

mNew dir;

//make snake body
void snakeBody() {
	rowX[0] = x;
	rowY[0] = y;
	int _rowX = rowX[0];
	int _rowY = rowY[0];
	
	for(int i=0; i<adding; i++) {
		int longX = rowX[i]; //x of snake body length
		int longY = rowY[i]; //y of snake body length
		rowX[i] = _rowX;
		rowY[i] = _rowY;
		_rowX = longX;
		_rowY = longY;
	}
}

//pulling the ground
void map() {
	system("clear"); //clear consol
	
	//top of ground
	for(int i=0; i<w; i++) {
		cout << "#";
	}
	cout << endl;

	//right and left of ground
	for(int i=0; i<l; i++) {
		for(int j=0; j<w; j++) {
			if(j==0 || j==w-2)
				cout << "#";
			if(i==y && j==x)
				cout << "O";
			else if(j==fruit_x && i==fruit_y) //draw random fruit
				cout << "F";
			else {
				bool print = false;
				for(int k=0; k<adding; k++) {
					if(rowX[k]==j && rowY[k]==i){
						cout << "o";
						print = true;
					}
				}
				if(!print)
					cout << " ";
			}
		}
		cout << endl;
	}

	//bottom of ground
	for(int i=0; i<w; i++) {
		cout << "#";
	}
	cout << endl;
}

//move function
void move() {

	if(_kbhit()) {
		switch(getch()){
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
		}
	}

	switch(dir) {
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		default:
			break;
	}

	//Loss in case of collision with edges
	//if(x>w-1 || x==-1 || y>l || y==-2)
	//	gameOver = true;
	
	//loss in case of body collision
	//for(int i=0; i<adding; i++) {
	//	if(rowX[i]==x && rowY[i]==y) {
	//		gameOver = true;
	//	}
	//}

	if(x>w-3) //if it exits from the right, it enters from the left
		x = 0;
	else if(x==-1) //if it exits from the left, it enters from the right
		x = w-3;
	else if(y>l-1) //if it exits from the bottom, it enters from the top
		y = 0;
	else if(y==-2) //if it exits from the bottom, it enters from the bottom
		y = l-1;

}

//
void Sleep(int speed) {
	//sleep(speed);
	usleep(100000);
}

//fruit
void fruit() {
		if(x==fruit_x && y==fruit_y) {
		fruit_x = rand() % 58;
		fruit_y = rand() % 18;	
		adding++;
	}
}

//start function
int main(int argc, char ** argv) {

	 while(!gameOver) {
	 	map();
		move();
		cout << "Score: "<< adding-2 << endl;
		fruit();
		snakeBody();
		Sleep(1);
	}

	return 0;
}
