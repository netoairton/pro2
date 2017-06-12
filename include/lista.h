/**
 * @file	openarquivo.cpp
 * @brief	Declaracao da classe Listaalunos e seus metodos
 * @author	Airton Neto(netoairton@yahoo.com.br)
 * @since	20/05/2017
 * @date	21/05/2017
 */
#ifndef ALUNOS_H
#define ALUNOS_H

#include<iostream>
using std::cout;
using std::endl;
using std::ios;
#include<string>
using std::string;
#include<fstream>
using std::ifstream;
using std::ofstream;

template<typename T>
class Listaalunos {
    private:
        T dados;
        //Listaalunos<Base> *dados;
        Listaalunos *ant;
        Listaalunos *prox;
    public:
        Listaalunos();
        ~Listaalunos();
        int vazia();
        void Inserir(T produto1);
        void Exibe();
        void Salvar();
};



template<typename T>
Listaalunos<T>::Listaalunos(){
    prox = NULL;
	ant = NULL;
}
template<typename T>
Listaalunos<T>::~Listaalunos(){
    if(prox){
        delete prox;
    }
}
template<typename T>
int Listaalunos<T>::vazia(){
	if(prox == NULL)
		return 1;
	else
		return 0;
}

template<typename T>
void Listaalunos<T>::Inserir(T produto1){
    //Abrir pra armazenar
    Listaalunos *novo = new Listaalunos();
    novo->dados=produto1;
    if(!novo){
	    cout << "Sem memoria disponivel!"<<endl;
		return;
	}

    if(vazia()){
		prox=novo;
		novo->ant=NULL;
		novo->prox=NULL;
	}
    else{
        Listaalunos *tmp = prox;
        while(tmp->prox){
			tmp = tmp->prox;	
        }

        novo->ant = tmp;
		novo->prox=NULL;
		tmp->prox = novo;
    }
}

template<typename T>
void Listaalunos<T>::Exibe(){
    if(vazia()){
        cout << "Lista vazia!"<<endl
							  <<endl;
        return;
    }

    Listaalunos *tmp;
	tmp = prox;
    int ii=0;

	while( tmp != NULL){
        ii++;
        cout<<*tmp->dados
            <<endl;

		tmp = tmp->prox;
	}
	cout << endl;
}
/*template<typename T>
void Listaalunos<T>::Comprar(int d, int m, int m){
    if(vazia()){
        cout << "Lista vazia!"<<endl
							  <<endl;
        return;
    }
    Listaalunos *tmp;
    tmp=prox;
    while(tmp!=NULL){
        tmp.escolhetipo(d, m, a);
        tmp=tmp->prox;
    }
}*/
template<typename T>
void Listaalunos<T>::Salvar(){
    string entry;
    cout<<"Digite o caminho do arquivo: ";
    cin>>entry;
    ofstream saida(entry);
    if(!saida){
        cout<<"O arquivo de entrada nao pode ser aberto."<<endl;
        return;
    }
    saida<<"Tipo;Nome_Produto;Quantidade;Preço;Codigo_Barras;Opcoes_extras;Fornecedor;Cnpj"<<endl;
    if(vazia()){
        cout << "Lista vazia!"<<endl
							  <<endl;
        return;
    }

    Listaalunos *tmp;
	tmp = prox;

	while( tmp != NULL){
        saida<<*tmp->dados
            <<endl;

		tmp = tmp->prox;
	}
	cout << endl;
    saida.close();
}
#endif