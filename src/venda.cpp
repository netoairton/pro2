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
#include "venda.h"

void compra(Listaalunos<Base*> original, int d, int m, int a){
    Listaalunos<Base*> compras;
    cout<<"Qual produto deseja adicionar a lista de compras:"<<endl;
    original.Comprar(d, m, a);
}