//includes
#include <iostream>

//namespaces
using namespace std;

//pulling the ground
void ground() {
	int l = 20;
	int w = 40;

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

	ground();


	return 0;
}
