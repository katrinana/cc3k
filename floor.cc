#include "floor.h"
#include "random.h"
#include "potion.h"
#include "ba.h"
#include "bd.h"
#include "cell.h"
#include "dragon.h"
#include "dwarf.h"
#include "elf.h"
#include "halfing.h"
#include "human.h"
#include "merchant.h"
#include "object.h"
#include "orcs.h"
#include "ph.h"
#include "rh.h"
#include "treasure.h"
#include "enemy.h"
#include "wa.h"
#include "wd.h"
#include "player.h"
#include <unistd.h>
#include<ncurses.h>
#include<stdlib.h> 
using namespace std;


Floor::Floor(Player* p,int l, char** maps){
	maxenemy = 20;
	maxpotion = 10;
	maxtreasure = 10;
	level = l;
	numenemy = 0;
	numpotion = 0;
	numtreasure = 0;
	numdragon = 0;
	maxwidth = 25;
	maxheight = 80;
	play = p;
	
	for(int i = 0; i < maxenemy; i++){
		enemy[i] = NULL;
	}
	for(int i = 0; i < maxpotion; i++){
		potion[i] = NULL;
	}
	for(int i = 0; i < maxtreasure; i++){
		treasure[i] = NULL;
	}
	
	//build the whole map(cells)
	cells = new Cell * [maxwidth];
	for(int i = 0; i < maxwidth; i++){
		cells[i] = new Cell [maxheight];
	}
	
	//set content of cells
	for(int i = 0; i < maxwidth; i++){
		for(int j = 0; j < maxheight; j++){
			cells[i][j] = Cell(i, j, maps[i][j]);
		}
	}		

	//set player
	int chamber, r, c;
	chamber = randomgenerate(5);
	r = randomgenerate(25) - 1;
	c = randomgenerate(79) - 1;
	while(cells[r][c].getState() != '.' || cells[r][c].getChamber() != chamber){
		r = randomgenerate(25) - 1;
		c = randomgenerate(79) - 1;
	}
	playerchamber = chamber;
	p->setcoord(r, c);
	cells[r][c].renewState('@');
	
	//set stair
	chamber = randomgenerate(5);
	r = randomgenerate(25) - 1;
	c = randomgenerate(79) - 1;
	while (chamber == playerchamber){
		chamber = randomgenerate(5);
	}
	while(cells[r][c].getState() != '.' || cells[r][c].getChamber() != chamber){
		r = randomgenerate(25) - 1;
		c = randomgenerate(79) - 1;
	}
	cells[r][c].renewState('\\');	
	
	
	generateenemy();
	generatetreasure();
	generatepotion();
}


Treasure* Floor::getTreasure(int numt) {
	return treasure[numt];
}

Dragon* Floor::getDDragon(int numd) {
	return dragon[numd];
}

Enemy* Floor::getEnemy(int nume) {
	return enemy[nume];
}

Potion* Floor::getPotion(int nump) {
	return potion[nump];
}

Cell& Floor::getCell(int r, int c){
	return cells[r][c];
}


void Floor::generateenemy(){
	int proenemy, r,c,chamber;
	for(int i = 0; i < 20; i++){
		proenemy = randomgenerate(18);		
		chamber = randomgenerate(5);
		r = randomgenerate(25) - 1;
		c = randomgenerate(79) - 1;
		while (cells[r][c].getState() != '.' || cells[r][c].getChamber() != chamber){
			r = randomgenerate(25) - 1;
			c = randomgenerate(79) - 1;
		}
		if(proenemy <= 4){
			enemy[i] = cells[r][c].setEnemy('H');
		}else if(proenemy <= 7 && proenemy > 4){
			enemy[i] = cells[r][c].setEnemy('D');
		}else if(proenemy <= 12 && proenemy > 7){
			enemy[i] = cells[r][c].setEnemy('L');
		}else if(proenemy <=14 && proenemy > 12){
			enemy[i] = cells[r][c].setEnemy('E');
		}else if(proenemy <= 16 && proenemy > 14){
			enemy[i] = cells[r][c].setEnemy('O');
		}else{
			enemy[i] = cells[r][c].setEnemy('M');	
		}
		numenemy++;
	}
}

void Floor::generatetreasure(){
	int protreasure, r,c,chamber;
	for(int i = 0; i < maxtreasure; i++){
		protreasure= randomgenerate(8);
		chamber = randomgenerate(5);
		r = randomgenerate(25) - 1;
		c = randomgenerate(79) - 1;
		while (cells[r][c].getState() != '.' || cells[r][c].getChamber() != chamber){
			r = randomgenerate(25) - 1;
			c = randomgenerate(79) - 1;
		}
		if (protreasure <= 5){
			treasure[i] = cells[r][c].setTreasure("normal");
		}if(protreasure <= 7){
			treasure[i] = cells[r][c].setTreasure("small");
			
			
		}if (protreasure == 8){ // dragon and dragon hoard generate
			while ((cells[r][c].getState() !='.' || cells[r][c].getChamber() != chamber) ||
				!(cells[r+1][c].getState()=='.' || cells[r-1][c].getState()=='.' || cells[r][c+1].getState()=='.' 
			|| cells[r][c-1].getState()=='.' || cells[r+1][c+1].getState()=='.' || cells[r-1][c-1].getState()=='.' || 
			cells[r-1][c+1].getState()=='.' || cells[r+1][c-1].getState()=='.')){
				r = randomgenerate(25) - 1;
				c = randomgenerate(79) - 1;
				}
				
				int nr = r;
				int nc = c;
				if(cells[r+1][c].getState() == '.'){
					nr = r+1;
				}else if(cells[r-1][c].getState()=='.'){
					nr = r-1;
				}else if(cells[r][c+1].getState()=='.'){
					nc = c+1;
				}else if(cells[r][c-1].getState()=='.'){
					nc = c-1;
				}else if(cells[r+1][c+1].getState()=='.'){
					nr = r+1;
					nc = c+1;
				}else if(cells[r-1][c-1].getState()=='.'){
					nr = r-1;
					nc = c-1;
				}else if(cells[r-1][c+1].getState()=='.'){
					nr = r-1;
					nc = c+1;
				}else{
					nr = r+1;
					nc = c-1;
				}
				Dragon *d = new Dragon;
				cells[nr][nc].placeDragon(d); // genreate dargon
				treasure[i] = cells[r][c].setDragonhoard(d); // generate treature
				dragon[i] = d;
				numdragon++;
		}
		numtreasure++;
	}
}

void Floor::generatepotion(){
	int pro, r, c, chamber;
	for(int i = 0; i < maxpotion; i++){
		pro = randomgenerate(6);
		chamber = randomgenerate(5);
		r = randomgenerate(25) - 1;
		c = randomgenerate(79) - 1;
		while (cells[r][c].getState() != '.' || cells[r][c].getChamber() != chamber){
			r = randomgenerate(25) - 1;
			c = randomgenerate(79) - 1;
		}
		if(pro == 1){
			potion[i] = cells[r][c].setPotion("RH");
		}if(pro == 2){
			potion[i] = cells[r][c].setPotion("BA");
		}if(pro == 3){
			potion[i] = cells[r][c].setPotion("BD");
		}if(pro == 4){
			potion[i] = cells[r][c].setPotion("PH");
		}if(pro == 5){
			potion[i] = cells[r][c].setPotion("WA");
		}if (pro == 6){
			potion[i] = cells[r][c].setPotion("WD");
		}
		numpotion++;
	}
}

void Floor::notify(int prec, int prev, int r, int c){
	char** map = mapinit();
	
	char pre = map[prec][prev];
	//cout << pre << endl;
	//if (pre == '#' || pre == '+'){
		cells[prec][prev].renewState(pre);
		//cells[prec][prev].removePlayer();
		//}
	/*else {
		cells[prec][prev].renewState('.');
		//cells[prec][prev].removePlayer();
	}*/
	
	cells[r][c].renewState('@');
	//cells[r][c].setPlayer(p);
}

string Floor::enemymove(){
	string action = "";
	int miss = 0;
	for(int i = 0; i < 20; i++){
		if(enemy[i]->isDeath()) {continue;}
		double di = damage(play->getDef(), enemy[i]->getAtk());
		string ds = damage_string(di);
		
		int er, ec, mr, mc, newr, newc;
		er = enemy[i]->getRow();
		ec = enemy[i]->getCol();
		mr = randomgenerate(3) - 2;
		mc = randomgenerate(3) - 2;
		newr = er + mr;
		newc = ec + mc;
		while(cells[newr][newc].getState() != '.' || (mr == 0 && mc == 0)){
			mr = randomgenerate(3) - 2;
			mc = randomgenerate(3) - 2;
			newr = er + mr;
			newc = ec + mc;
		}
		char name = enemy[i]->getname();
		
		miss = randomgenerate(2);
		
		if(cells[er-1][ec].getState()=='@' || cells[er+1][ec].getState()=='@' || cells[er][ec-1].getState()=='@' ||cells[er][ec+1].getState()=='@' ||
		cells[er-1][ec-1].getState()=='@' || cells[er-1][ec+1].getState()=='@' || cells[er+1][ec-1].getState()=='@' || cells[er+1][ec+1].getState()=='@'){
				if(name == 'E' && play->Getch()!='d'){
					if(miss==1){
						double temdi = di * 2; 
						string temds = damage_string(temdi);
						action =action + enemy[i]->getFullname() + " deals " + temds + " to PC.";
						play->changehp(temdi);
					}if(miss==2){
						action =action + enemy[i]->getFullname() + " miss. ";
					}
				
				} else if(name == 'O' && play->Getch()=='g'){
					if(miss==1){
						double temdi = di * 1.5;
						string temds = damage_string(temdi);
						action =action + enemy[i]->getFullname() + " deals " + temds + " to PC. ";
						play->changehp(temdi);
					}if(miss==2){
						action =action + enemy[i]->getFullname() + " miss. ";
					}
				}else if(name == 'M' && enemy[i]->gethostile() == false){
					action = "";
				}else{
					if(miss==1){
						string temds = damage_string(di);
						action =action + enemy[i]->getFullname() + " deals " + temds + " to PC. ";
						play->changehp(di);
					}if(miss==2){
						action =action + enemy[i]->getFullname() + " miss. ";
					}
				}
			}else{
				Object *ob = cells[er][ec].getObject();
				cells[er][ec].renewState('.');
				cells[er][ec].changeObject(NULL);
				cells[newr][newc].changeObject(ob);
				cells[newr][newc].renewState(name);
				enemy[i]->changeCoord(newr, newc);
			}
		}
	
	for(int j=0; j<10; j++){
		if(dragon[j] == NULL){continue;}
		if(dragon[j]->isDeath()){continue;}
		int dr = dragon[j]->getRow();
		//cout << "dargon row is : " << dr<<endl;
		int dc = dragon[j]->getCol();
		//cout << "dargon column is : " << dc <<endl;
		
		
		
		if(cells[dr-1][dc].getState()=='@' || cells[dr+1][dc].getState()=='@' || cells[dr][dc-1].getState()=='@' ||cells[dr][dc+1].getState()=='@' ||
		cells[dr-1][dc-1].getState()=='@' || cells[dr-1][dc+1].getState()=='@' || cells[dr+1][dc-1].getState()=='@' || cells[dr+1][dc+1].getState()=='@'){
			//cout << "player is near dragon" << endl;
			if(miss==1){
				double d = damage(play->getDef(), 20);
				string s = damage_string(d);
				action =action + "Dargon  deals " + s + " to PC. ";
				play->changehp(d);
			}if(miss==2){
				action = action + "Dragon miss. ";
			}
		}
	}
	return action;
}




void Floor::hostile(){
	for(int i = 1; i<20; i++){
		if(enemy[i]->getname() == 'M'){
			enemy[i]->changehostile();
		}
	}
}

void Floor::printmap(string a){
	for(int i=0; i<maxwidth; i++){
		for(int j=0; j<(maxheight); j++){
			printw("%c", cells[i][j].getState());
		}
		printw("\n");
	}
	char *str1=new char[play->getFullname().size()+1];
	str1[play->getFullname().size()]=0;
	strcpy(str1,play->getFullname().c_str());
	
	printw("Race: %s",str1);
	
	printw("Gold: %d\n", play->getgold());
	if(play->getHP() < 0){
		printw("HP: 0\n");
	}else{
		printw("HP: %lf\n", play->getHP());
	}
	printw("Atk: %lf\n", play->getAtk());
	printw("Def: %lf\n", play->getDef());
	
	char *str=new char[a.size()+1];
	str[a.size()]=0;
	strcpy(str,a.c_str());
	printw("Action: %s", str);
}

Floor::~Floor(){
	for (int i =0; i < numenemy; i++){
		delete enemy[i];
	}
	for (int i = 0; i < numtreasure; i++){
		delete treasure[i];
	}
	for (int i = 0; i < numdragon; i++){
		delete dragon[i];
	}
	for (int i = 0; i < numpotion; i ++){
		delete potion[i];
	}
	for (int i = 0; i < 25; i++){
		delete[] cells[i];
	}
	delete[] cells;
}
