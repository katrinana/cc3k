#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <fstream>

extern char map[25][80];

int randomgenerate(int range);

double damage(double def, double atk);

std::string damage_string(double damage);

char** mapinit();
