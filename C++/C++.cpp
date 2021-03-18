#include<iostream>
using namespace std;

void ground(){
    	int width=100; //arz
    int length=20; //tool
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

int main(){
	ground();
    return 0;
}
