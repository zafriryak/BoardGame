
#include<string>
#include<iostream>
#include "Game.h"



/*
 * Zafrir Yakir 203715602
 */


int main(int argc, char* argv[]){
	if (argc < 1)
		exit(0);
	if (argv[1] == std::string("-help")){
		cout << "-n [number] -files[file1 file2 ...]" << endl;
		exit(0);
	}
Game* g=NULL;
	for (int i = 0; i < std::stoi(argv[2]); i++){
		 g=new Game(argv[4+i]);
		//new Game(argv[4+i]);
			//delete g;

	}

	return 0;
}

