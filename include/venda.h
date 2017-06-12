#ifndef VENDA_H
#define VENDA_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include<fstream>
using std::ifstream;
using std::ofstream;
#include <cstdlib> //Usado somente para as funções atoi e atof
#include "listagem.h"
#include "menu.h"
#include "lista.h"
#include "openarquivo.h"
void compra(Listaalunos<Base*> original, int d, int m, int a);

#endif