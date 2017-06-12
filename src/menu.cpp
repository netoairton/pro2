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

void menu(int d, int m, int a){ 
    int opcao= -1;
    Base *novo;
    Listaalunos<Base*> lista;
    do{
        cout<<"(1)Adicionar produtos"<<endl
            <<"(2)Imprimir produtos"<<endl
            <<"(3)Comprar produtos"<<endl
            <<"(4)Salvar em arquivo"<<endl
            <<"(0)Sair"<<endl
            <<"Digite a opcao desejada: ";
        cin>>opcao;
        switch(opcao){
            case 1:{
                string entry;
                cout<<"Digite o caminho do arquivo: ";
                cin>>entry;
                int tamanho= aberturaarquivo(entry);
                ifstream entrada(entry);
                if(!entrada){
                    cout<<"O arquivo de entrada nao pode ser aberto."<<endl;
                    return;
                }

                string null;
                string stipo/*, snome, squantidade, spreco, scb, salcool, sfornecedor, scnpj*/;
                getline(entrada, null); //descartando o cabeçalho

                for(int i=0; i<tamanho; i++){
                    getline(entrada, stipo, ';');
                    cout<<"//"<<stipo<<"//"<<endl;
                    if (stipo=="Bebida"){
                        Bebida *a1= new Bebida();
                        a1->setTipo(stipo);
                        entrada>>*a1;
	                    novo=a1;
                        lista.Inserir(novo);
                    }
                    else if(stipo=="Salgado"){
                        Salgado *a2= new Salgado();
                        a2->setTipo(stipo);
                        entrada>>*a2;
	                    novo=a2;
                        lista.Inserir(novo);
                    }
                    else if(stipo=="Fruta"){
                        Fruta *a3= new Fruta();
                        a3->setTipo(stipo);
                        entrada>>*a3;
	                    novo=a3;
                        lista.Inserir(novo);
                    }
                    else if(stipo=="Doce"){
                        Doce *a4= new Doce();
                        a4->setTipo(stipo);
                        entrada>>*a4;
	                    novo=a4;
                        lista.Inserir(novo);
                    }
                    else if(stipo=="CD"){
                        CD *a5= new CD();
                        a5->setTipo(stipo);
                        entrada>>*a5;
	                    novo=a5;
                        lista.Inserir(novo);
                    }
                    else if(stipo=="DVD"){
                        DVD *a6= new DVD();
                        a6->setTipo(stipo);
                        entrada>>*a6;
	                    novo=a6;
                        lista.Inserir(novo);
                    }
                    else if(stipo=="Livro"){
                        Livro *a7= new Livro();
                        a7->setTipo(stipo);
                        entrada>>*a7;
	                    novo=a7;
                        lista.Inserir(novo);
                    }
                    else{
                        cout<<"TIPO INVALIDO!"<<endl;
                    }
                }
                entrada.close();
                break;
            }
            case 2:{
                cout<<endl;
                lista.Exibe();
                break;
            }
            case 3:{
                //Compra(lista, d, m, a);
                break;
            }
            case 4:{
                lista.Salvar();
                break;
            }
        }
    } while(opcao!=0);
    return;
}