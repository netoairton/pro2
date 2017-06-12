#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//#include "listagem.h"
#include "menu.h"


int main(){
	//TipoA a1(1,"a"); // Instancia UM objeto da classe TipoA
	int dia, mes, ano;
	cout<<"_____Controle de estoque e vendas QLeveTudo_____"<<endl
		<<"Digite a data de hoje (dd mm aaaa): ";
	cin>>dia>>mes>>ano;
	/*Base *novo;
	//Base *novo2;
	Bebida *a1= new Bebida();
	a1->setQuantidade(30);
	a1->setAlcool(3.5);
	novo=a1;
	novo->setQuantidade(44);*/
	menu(dia, mes, ano);
	
	/*cout<<endl;
	cout<<*novo<<endl;*/

	/*Salgado *b1= new Salgado();
	novo2=b1;
	cout<<*novo2<<endl;*/
	//novo.setM_prefixo("bbbb");
	//TipoB b1(2,"b"); // Instancia UM objeto da classe TipoB
	//novo.imprime();
	//b1.imprime();

	//list<Base*> lista; // Cria UMA lista (usando STL) genérica usando a classe Base
	
	// Preenche a lista com elementos do TipoA (quando i for par) ou TipoB (quando i for impar)
	/*for(int i=0; i<TOTAL; i++)
	{
		// O metodo push_back() insere um elemento no final da lista (STL)
		(i%2)?lista.push_back(new TipoA(i,"aa")):lista.push_back(new TipoB(i,"bb"));
	}*/

	// Imprime os elementos da lista usando um iterador (STL)
	/*for (list<Base*>::iterator it = lista.begin(); it != lista.end(); ++it)
	{
		// Como cada elemento da lista é um objeto TipoA ou TipoB e ambos respondem ao 
		// metodo imprime()...
		(*it)->imprime();
	}*/

	return 0;
}