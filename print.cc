#include "print.h"
#include <ncurses.h>
#include <iostream>
#include <unistd.h>

using namespace std;

char start[17][46]={
"____________@@@1@@_________@@@@@@@___________",
"_________@@@111@@___________@@111@@@@________",
"______@@@@1111@@@____________@@@1111@@@1_____",
"_____@@@1111@@@@_____________@@@@11111@@@____",
"___@@@11@1@1@@@@___@@____@@__@@@@@1@1@1@@@1__",
"__@@@11@1@11@@@@@__@@@@@@@@__@@@@@1@1@@11@@1_",
"_@@@11@@1@11@@@@@@__@@@@@@_@@@@@@@1@@1@@1@@@_",
"@@@@1@@11@@1@@@@@@@@@@@@@@@@@@@@@@1@@1@@@1@@@",
"@@@11@@11@@1@@@@@@@@@@@@@@@@@@@@@1@@@1@@@1@@@",
"@@@1@@@@1@@@1@@@@@@@@@@@@@@@@@@@11@@@1@@@11@@",
"_@@11@@@1@@@@1@@@@@@@@@@@@@@@@@@1@@@1@@@@1@@@",
"_@@1@@@@1@@@@@@@@@@@@@@@@@@@@@@@@@@1@@@@1@@@1",
"__@@1@@@@@@@@__@@@@@@@@@@@@@@@__@@@@@@@@1@@@_",
"___@@1@@@_@@_______@@@@@@@@______@@@@@@@@@@__",
"____@@@@____________@@@@@@___________@@@@____",
"______@@@__________@@@__@@@__________@@______",
"_______@@@_________@______@_________@@@______"
};

void printstart(){
 for (int i = 0; i < 17; i ++){
	 for(int j = 0; j < 46; j++){
		 printw ("%c",start[i][j]);
	 }
	 printw ("\n");
 }
}

void printauthor(){
	clear();
printw (" _______   _______      _______. __    _______ .__   __.  _______  _______  \n");
printw ("|       \\ |   ____|    /       ||  |  /  _____||  \\ |  | |   ____||       \\ \n ");
printw ("|  .--.  ||  |__      |   (----`|  | |  |  __  |   \\|  | |  |__   |  .--.  | \n"); 
printw ("|  |  |  ||   __|      \\   \\    |  | |  | |_ | |  . `  | |   __|  |  |  |  | \n"); 
printw ("|  '--'  ||  |____ .----)   |   |  | |  |__| | |  |\\   | |  |____ |  '--'  |\n"); 
printw ("|_______/ |_______||_______/    |__|  \\______| |__| \\__| |_______||_______/ \n");

printw ("  _             \n");
printw (" | |            \n");
printw (" | |__    _   _ \n");
printw (" | '_ \\  | | | |\n");
printw (" | |_) | | |_| |\n");
printw ( " |_.__/   \\__, |\n"); 
printw ( "           __/ |\n");
printw ( "          |___/ \n");

printw ( ".--.--.--..-----..-----..--.--..--.--.     /__\\  ( \\( )(  _ \\ \n");
printw ( "|  |  |  ||  -__||     ||  |  ||  |  |    /(__)\\  )  (  )(_) )  \n");
printw ( "|________||_____||__|__||___  ||_____|   (__)(__)(_)\\_)(____/   \n");
printw ("                        |_____|       \n"); 


printw ( "|  |--..-----.|  |--..---.-..-----.\n");
printw ( "|    < |  -__||     ||  _  ||     |\n");
printw ( "|__|__||_____||__|__||___._||__|__|\n");
}


void printselect(){
	clear();
	printw ( "Type command to select a race\n");
	printw ( "s: Shade\n");
	printw ( "d: drow\n");
	printw ( "v: vampire\n");
	printw ( "t: troll\n");
	printw ( "g: goblin\n");
}


void printwin(){
	//clear();
printw ( "                                                      o88                oo \n");
printw ( "oooo   oooo   ooooooo   oooo  oooo     oooo  o  oooo  oooo  oo oooooo   8888\n");
printw ( "888   888  888     888  888   888      888 888 888    888   888   888  8888 \n");
printw ( "  888 888   888     888  888   888       888888888     888   888   888   88 \n");
printw ( "    8888      88ooo88     888o88 8o       88   88     o888o o888o o888o  oo \n");
printw ( " o8o888                                                                     \n");
}


void printlose(){
	/*printw ("░░░░░░░░░░░░░░░░░░░▒▓▓█████████████▓▓▒░░░░░░░░░░░░░░░░░░░░░░\n");
	printw ("░░░░░░░░░░░░░░▒████▓▓▒▒░▒▒▒░▒▒▒▒▒▒▓▓████▓▒░░░░░░░░░░░░░░░░░░\n");
	printw ("░░░░░░░░░░░▒███▓░░░░░░░░░░░░░░░░░░░░░░▒███████▓▓▒░░░░░░░░░░░\n");
	printw ("░░░░░░░░░▒██▓░░░░▒▒███▓▓▒░░░░░░░░░░░░░▓▓▒▒▒▒▒▓██████▓░░░░░░░\n");
	printw ("░░░░░░░▒██▓░░░▓███▓▒░░░░░░░░▒▒▒▒▒▒▒▒▒▒░░░░░░▒▓▓███▓████▒▒░░░\n");
	printw ("░░░░░░██▓░░▒▓██▓░░▒▓██████▓░░░░░░░▒░░░░░░▒██▓▒░░░▓███▒▓▒░░░░\n");
	printw ("░░░░░██░░▓███▒░░▒██▒░░░░▒▒██▓░░░░░░░░░░░██▒░░░░▒████▒█░░░░░░\n");
	printw ("░░░░██░▒▓▒▓▓░░░██░░░░░░░░░░░█▓░░░░░░░░░██░░░░░░▒███░░█▒░░░░░\n");
	printw ("░░░▓█░░░░░░░░░██░░░░░░░░░░░░▓█░░░░░░░░██░░░░░░░░░░░░░█▒░░░░░\n");
	printw ("░░░█▓░░░░░░░░░█▒░░████░░░░░░░█▒░░░░░░░██░░░░░░░░░░░░███░░░░░\n");
	printw ("░░▒█░░░░░░░▒▓▒█▓░▓████▓░░░░░▒█░░░░░░░░▒█▒░░░░░░░░░░██░█▒░░░░\n");
	printw ("░░██░░░░░▒▓▒▓▒██▒▒▓▓▓░░░░░░░██░░░░░░░░░▒████▓███████▓░█▒░░░░\n");
	printw ("░░█▓░░░░░▒░░░▒░▒██▓▒░░░░░▒██▓░░░░░░░░░░░░░░██▓░░░░░░▒██▓░░░░\n");
	printw ("░░█░░░░░░░░░▓▒░░░░▒▓██████▓░░░░░░░░░░░░░░▒██░░░▓█▓▓▒░░░██░░░\n");
	printw ("░▒█░░░░░░░░░░░░░░░░░░░░░░░░░░▓▒▓▒▒▒▒▒▓▓▓▓██░░▓█▓░▒▒██▒░░██░░\n");
	printw ("░▓█░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▓▓▒░░██░░██▓░▒░▒░██░░▒█░░\n");
	printw ("░██░░░░░░░░░░░░░░░░░░░░░░░▒▓▒▒▒▒▒▒▒▒░░░██░░▓█░█▓░█▒█▓█▓░░█░░\n");
	printw ("░██░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒░▒▒░░▓█▓░░██░█▒▒█▒█▒▓█░░█░░\n");
	printw ("░██░░░░░░░░░░░░░░░░░░░░░░░░▒░░░░░░░░░░▓█░░░█▒░░░░▒▒░░▒█░▓█░░\n");
	printw ("░▒█░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒░░█▒░░█▒░░░░░░░░▓█░█▓░░\n");
	printw ("░░█▓░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓█░░█▒░░░░░░░░█░▒█░░░\n");
	printw ("░░▓█░░▒░░▒▒░░▒░░░░░░░░░░░░░░░░░░░░░░░░░░█░░█▒░░░░░░░█▓░█▓░░░\n");
	printw ("░░░█▒░░▒░░▒░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░█░░█▒░░░░░░▓█░░█░░░░\n");
	printw ("░░░██░░░▒░▒░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░█░░█▒░░░░░░██░░█░░░░\n");
	printw ("░░░░█▓░░░▒░▒░░░░▒▒░░░░░▒▒▒▒▒▒░░░░░░░░░░▒█░▒█░░░░░░░█▒░░█▓░░░\n");
	printw ("░░░░▓█░░░░▒▒░░░░░▒▒░░░░░░▒▒▒▓▓▓▒░░░░░░░██░██░░░░░░░██░░▓█░░░\n");
	printw ("░░░░░██░░░▒░▒░░░░░▒░░░░░░░░▒░▒▒▓█▒░░░░▒█░░█▓▒▓▓▓▒░░▓█░░░█▒░░\n");
	printw ("░░░░░▒█▒░░░▒▒▒░░░░▒░░░░░░░░░░▒▒▒░▒▓░░░██░▒█░░░░▒▓▓░░██░░█▒░░\n");
	printw ("░░░░░░▒█▒░░░▒░▒░░░▒░░░░░░▒▒▒░░░░▒▒░░░▒█░░██░░░░░░░█░▒█░░█▒░░\n");
	printw ("░░░░░░░▓█░░░▒░▒░░░░▒▒░░░░▓▒▒▓▓▓▒░░▓▒░██░░██▒▒▒▒▓▒▓▓███░░█▒░░\n");
	printw ("░░░░░░░░██░░░▒░▒░░░░░▒▒░░░░░░░░▓█▓░░░█▓░░██░▓█░█░█░░█▒░░█▒░░\n");
	printw ("░░░░░░░░░██░░░░▒▒░░░░░░▒▒░░░░░░░░▒█▓░█▓░░▓█▒▒█▒█░█▒██░░▒█░░░\n");
	printw ("░░░░░░░░░░██▒░░░░▒░░░▒░░░▒▒░░░░░░░░▒▓██░░░██░░░░▒▒██░░░██░░░\n");
	printw ("░░░░░░░░░░░▓██░░░░░░░░▒▒░░░▒░░░░░░░░░▓█░░░░▓███▓▓██░░░██░░░░\n");
	printw ("░░░░░░░░░░░░░▓██▒░░░░░░▒▒▒▒▒░░░░░░░░░░██░░░░░░▒▒▒░░░░██░░░░░\n");
	printw ("░░░░░░░░░░░░░░░▓███▒░░░░░░░▒▒▒▒▒▒▒▒░░░░▓██▒░░░░░░░▒███░░░░░░\n");
	printw ("░░░░░░░░░░░░░░░░░▒▓███▓▒░░░░░░░▒░░▒▒▒▒░░░▒██▓██████▓░░░░░░░░\n");
	printw ("░░░░░░░░░░░░░░░░░░░░░▒████▓▒▒░░░░░░░░░░░░░░░▓██▒░░░░░░░░░░░░\n");
	printw ("░░░░░░░░░░░░░░░░░░░░░░░░░▒▓████▓░░░░░░░▓█████▒░░░░░░░░░░░░░░\n");
	printw ("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒█████████▒░░░░░░░░░░░░░░░░░░░\n");
	printw ("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░░░░░░░░░░░░░░░░░░░░░░░\n");*/

	printw (",---.,---.,-.-.,---.    ,---..    ,,---.,---.\n");
	printw ( "|   |,---|| | ||---'    |   | \\  / |---'|    \n");
	printw ( "`---|`---^` ' '`---'    `---'  `'  `---'`    \n");
	printw ( "`---'          \n");
	printw ("q: quit\n");  
    printw ("r: restart\n");
}


void printcommands(){
	clear();
printw ("_____________________________________\n");
printw ("|Commands:                          |\n");
printw ("|l :list all commands               |\n");
printw ("|                                   |\n");
printw ("|move player:ea/so/we/no/ne/se/sw/nw|\n");
printw ("|                                   |\n");
printw ("|q: quit the game                   |\n");
printw ("|                                   |\n");
printw ("|r: restart                         |\n");
printw ("|___________________________________|\n");
}

