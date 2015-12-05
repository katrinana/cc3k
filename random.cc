#include "random.h"
using namespace std;

int randomgenerate(int range){
	//srand(time());
	int i = (rand()%range) + 1;
	return i;
}


double damage(double def, double atk){
	int d;
	d = ceil((100/(100+def)*1.0) * atk);
	return d;
}

string damage_string(double damage){
	stringstream ss;
	string result;
	
	ss << damage;
	result = ss.str();
	
	return result;	
}

char** mapinit(){
	char** m;
	
	ifstream in("map.txt");
	string line;
	
	m = new char*[25];
	for(int i = 0; i< 25; i++){
		m[i] = new char[79];
	}
	
	for(int i=0; i<25; i++){
		getline(in, line);
		for(int j=0; j<79; j++){
			m[i][j] = line[j];
		}
	}
	return m;
	
	/*for(int i = 0; i< 25; i++){
		for(int j = 0; j<79; j++){
			cout << m[i][j];
		}
		cout << endl;
	}*/
}

