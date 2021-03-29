#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;
int width=40; //arz
int length=20; //tool
int x=length/2,y=width/2;
bool gamestatus=false;


enum m_new{
	stop=0,Left,Right,Up,Down
};
m_new dir;

/* Ground function */
void ground(){
	system("cls");
    //print top of ground
    for(int k=0;k<width;k++){
        cout<<"#";
    }
    cout<<endl;
    //print left & right of ground
    for(int i=0;i<length;i++){
	    	for(int j=0;j<width;j++){
	    		if(j==0 || j==width-2){
    		    cout<<"#";
			}
			if(i==x && j==y){
				cout<<"O";
			}
			else{
				cout<<" ";
			}
			}
			cout<<endl;
	}
	//print bottom of ground
	for(int k=0;k<width;k++){
        cout<<"#";
    }
    
}
/* Move function */
void move(){
	if(_kbhit()){
		switch (_getch()){
			case 'w':
			dir=Up;
			break;

			case 's':
			dir=Down;
			break;

			case 'a':
			dir=Left;
			break;

			case 'd':
			dir=Right;
			break;
		}
	}
switch (dir)
{
case Up:
    x--;
	break;

case Down:
    x++;
	break;

case Left:
    y--;
	break;
	
case Right:
    y++;
	break;

default:
    break;				
}	
}

void control_m(){
	/* If head of snake = length or width, game will be end.
	if(x>length || x<-1 || y>width-2 || y<0){
		gamestatus=true;
	}*/
	
	if(x==width+1){
		x=0;
	}
	else if(x==-1){
		x=width+1;
	}
	else if(y==length-2){
		y=0;
	}
	else if(y==0){
		y=length-2;
	}
}

void sleep(int sleep){
	Sleep(sleep);
}

/* Main function */
int main(int argc, char** argv){
	while (gamestatus)
	{
	ground();
	move();
	sleep(100);
	control_m();
	cout<<"x:"<<x<<" y:"<<y;
	}
	
    return 0;
}