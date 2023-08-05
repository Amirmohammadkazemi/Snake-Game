//includes
#include <iostream>

//namespaces
using namespace std;

//variable
int w = 60; //width of map
int l = 20; //length of map

//pulling the ground
void map() {

	//top of ground
	for(int i=0; i<w; i++) {
		cout << "#";
	}
	cout << endl;

	//right and left of ground
	for(int i=0; i<l; i++) {
		for(int j=0; j<w; j++) {
			if(j==0 || j==w-1)
				cout << "#";
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

//start function
int main(int argc, char ** argv) {

	map();


	return 0;
}
