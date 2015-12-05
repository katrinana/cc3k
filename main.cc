#include <iostream>
#include <string>
#include "print.h"
#include "random.h"
#include "player.h"
#include "object.h"
#include "floor.h"
#include "drow.h"
#include "goblin.h"
#include "shade.h"
#include "vampire.h"
#include "troll.h"
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <cstdlib>  

using namespace std;


int main(){
	initscr();
	
	//bool end = false;
	//bool win = false;
	srand(time(0));
	bool raceset = false;
	bool gameover = false;
	
	string action = "";
	Player* p = NULL;
	
	char** map=NULL;
	//string garbage;
	char command;
	
	map = mapinit(); // inilize map
	
	printstart();
	printw("enter anything to continue!\n");
	command = getch();
	//clear();
	printauthor();
	printw("enter anything to continue!\n");
	//clear();
	command = getch();
	printcommands();
	printw("enter anything to continue!\n");
	//clear();
	command = getch();
	printselect();
	command = getch();
	
	while(true){
		bool vaild = false;
		action = "";
			
		while (raceset == false){// select race
			if (p != NULL) p = NULL;
			if (cin.eof()) break;
			
			if (command == 'q'){
				gameover = true;
				break;
			}if(command == 'd'){
				raceset = true;
				p = new Drow(map);
			}if(command == 'g'){
				raceset = true;
				p = new Goblin(map);
			}if(command == 's'){
				raceset = true;
				p = new Shade(map);
			}if(command == 't'){
				raceset = true;
				p = new Troll(map);
			}if(command == 'v'){
				raceset = true;
				p = new Vampire(map);
			}if(raceset){
				clear();
				//system("clear");
				p->Display("Player character has spawned");
			}else{
					command = getch();
				}	
		}
		if (gameover) break;
		command = getch();
		if(p!=NULL && p->islose()){
			clear();
			printlose();
			p->printscore();
			cout<<endl;
			
		}if(p!= NULL && p->iswon()){
			clear();
			printwin();
			p->printscore();
			cout<<endl;
		
		}if(!p->islose() && !p->iswon()){
			if(command=='w'){
				action=p->move("no");
				vaild=true;
			}else if(command=='s'){
				action=p->move("so");
				vaild=true;
			}else if(command=='d'){
				action=p->move("ea");
				vaild=true;
			}else if(command=='a'){
				action=p->move("we");
				vaild=true;
				}
		}if(command=='l'){
			clear();
			printcommands();
		}if(command=='r'){
			raceset = false;
			p=NULL;
			clear();
			printselect();
		}if(command == 'q'){
			break;
			//print action
		
		} if(vaild){
			clear();
			//action = action + p->Enemymove();
			p->Display(action);
		}	
	}
	//delete p;
 	endwin();
}