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

//The coordinates of the snake's head
int x = w/2;
int y = l/2;

enum mNew {
	stop=0, RIGHT, LEFT, UP, DOWN
};

mNew dir;

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
			else
				cout << " ";
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
}

//
void Sleep(int speed) {
	//sleep(speed);
	usleep(100000);
}

//start function
int main(int argc, char ** argv) {

	while(true) {
		map();
		move();
		Sleep(1);
	}

	return 0;
}
