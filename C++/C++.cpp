#include<iostream>
#include<conio.h>
using namespace std;
int width=100; //arz
int length=20; //tool
int x=length/2,y=width/2;

enum m_new{
	stop=0,Left,Right,Up,Down
};
m_new dir;

/* Ground function */
void ground(){
    //print top of ground
    for(int k=0;k<width;k++){
        cout<<"#";
    }
    cout<<endl;
    //print left & right of ground
    for(int i=0;i<length;i++){
	    	for(int j=0;j<width;j++){
	    		if(j==0 || j==width-1){
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
    y++;
	break;

case Down:
    y--;
	break;

case Left:
    x--;
	break;
	
case Right:
    x++;
	break;			
}	
}

/* Main function */
int main(int argc, char** argv){
	ground();
	move();
    return 0;
}