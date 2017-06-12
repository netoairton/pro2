#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <cstdlib> //Usado somente para as funções atoi e atof
#include<fstream>
using std::ifstream;
using std::ofstream;

class Base
{
private:
	virtual std::ostream& print(std::ostream&) const = 0;
	virtual std::istream& read(std::istream&)= 0;
protected:
	string tipo;
	string nome;
	int quantidade;
	float preco;
	string cb; //codigo de barras
	string fornecedor;
	string cnpj;
public:
	Base();
	string getTipo();
    void setTipo(string t);
	string getNome();
    void setNome(string n);
	int getQuantidade();
    void setQuantidade(int q);
	float getPreco();
    void setPreco(float p);
	string getCb();
    void setCb(string c);
	string getFornecedor();
    void setFornecedor(string f);
	string getCnpj();
    void setCnpj(string a);
	friend std::ostream& operator << (std::ostream& os, const Base& b) {
		return b.print(os);
	}
	friend std::istream& operator >> (std::istream& is, Base& bb) {
		return bb.read(is);
	}
};
Base::Base(){
	tipo="";
	nome="";
	quantidade=0;
	preco=0;
	cb="";
	fornecedor="";
	cnpj="";
}
string Base::getTipo(){
    return tipo;
}
void Base::setTipo(string t){
    tipo=t;
}
string Base::getNome(){
    return nome;
}
void Base::setNome(string n){
    nome=n;
}
int Base::getQuantidade(){
    return quantidade;
}
void Base::setQuantidade(int q){
    quantidade=q;
}
float Base::getPreco(){
    return preco;
}
void Base::setPreco(float p){
    preco=p;
}
string Base::getCb(){
    return cb;
}
void Base::setCb(string c){
    cb=c;
}
string Base::getFornecedor(){
    return fornecedor;
}
void Base::setFornecedor(string f){
    fornecedor=f;
}
string Base::getCnpj(){
    return cnpj;
}
void Base::setCnpj(string a){
    cnpj=a;
}
class Vencimento
{
private:
protected:
	int dia;
	int mes;
	int ano;
public:
	Vencimento();
	int getDia();
    void setDia(int d);
	int getMes();
    void setMes(int m);
	int getAno();
    void setAno(int a);
};
Vencimento::Vencimento(){
	dia=0;
	mes=0;
	ano=0;
}
int Vencimento::getDia(){
    return dia;
}
void Vencimento::setDia(int d){
    dia=d;
}
int Vencimento::getMes(){
    return mes;
}
void Vencimento::setMes(int m){
    mes=m;
}
int Vencimento::getAno(){
    return ano;
}
void Vencimento::setAno(int a){
    ano=a;
}
class Bebida: public Base, public Vencimento
{
private:
	float alcool;
	float acucar;
	std::ostream& print(std::ostream& os) const {
		return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Porcentagem de Alcool: "<<alcool<<"%	Açúcar: "<<acucar<<"mg"<<endl
				  <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<<endl
				  <<"Validade: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
	}
	std::istream& read(std::istream& is) {
		string copiaquantidade, copiapreco, copiaalcool, copiaacucar, copiadia, copiames, copiaano;
		getline(is, nome, ';');
		getline(is, copiaquantidade, ';');
		quantidade=atoi(copiaquantidade.c_str());
		getline(is, copiapreco, ';');
		preco=atof(copiapreco.c_str());
		getline(is, cb, ';');
		getline(is, copiaalcool, ';');
		alcool=atof(copiaalcool.c_str());
		getline(is, copiaacucar, ';');
		acucar=atof(copiaacucar.c_str());
		getline(is, fornecedor, ';');
		getline(is, cnpj, ';');
		getline(is, copiadia, '/');
		dia=atoi(copiadia.c_str());
		getline(is, copiames, '/');
		mes=atoi(copiames.c_str());
		getline(is, copiaano);
		ano=atoi(copiaano.c_str());
		return is;
	}
public:
	Bebida();
	string getTipo();
    void setTipo(string t);
	string getNome();
    void setNome(string n);
	int getQuantidade();
    void setQuantidade(int q);
	float getPreco();
    void setPreco(float p);
	string getCb();
    void setCb(string c);
	string getFornecedor();
    void setFornecedor(string f);
	string getCnpj();
    void setCnpj(string a);
	float getAlcool();
    void setAlcool(float o);
	float getAcucar();
    void setAcucar(float s);
	int getDia();
    void setDia(int d);
	int getMes();
    void setMes(int m);
	int getAno();
    void setAno(int a);
	//void escolhetipo(int d, int m, int a);
};
Bebida::Bebida(){
	tipo="Bebida";
	nome="";
	quantidade=0;
	preco=0;
	cb="";
	fornecedor="";
	cnpj="";
	alcool=0;
	acucar=0;
	dia=0;
	mes=0;
	ano=0;
}
string Bebida::getTipo(){
    return tipo;
}
void Bebida::setTipo(string t){
    tipo=t;
}
string Bebida::getNome(){
    return nome;
}
void Bebida::setNome(string n){
    nome=n;
}
int Bebida::getQuantidade(){
    return quantidade;
}
void Bebida::setQuantidade(int q){
    quantidade=q;
}
float Bebida::getPreco(){
    return preco;
}
void Bebida::setPreco(float p){
    preco=p;
}
string Bebida::getCb(){
    return cb;
}
void Bebida::setCb(string c){
    cb=c;
}
string Bebida::getFornecedor(){
    return fornecedor;
}
void Bebida::setFornecedor(string f){
    fornecedor=f;
}
string Bebida::getCnpj(){
    return cnpj;
}
void Bebida::setCnpj(string a){
    cnpj=a;
}
float Bebida::getAlcool(){
    return alcool;
}
void Bebida::setAlcool(float o){
    alcool=o;
}
float Bebida::getAcucar(){
    return acucar;
}
void Bebida::setAcucar(float s){
    acucar=s;
}
int Bebida::getDia(){
    return dia;
}
void Bebida::setDia(int d){
    dia=d;
}
int Bebida::getMes(){
    return mes;
}
void Bebida::setMes(int m){
    mes=m;
}
int Bebida::getAno(){
    return ano;
}
void Bebida::setAno(int a){
    ano=a;
}
/*void Bebida::escolhetipo(int d, int m, int a){
	if(ano=>a){
		if(mes=>m){
			if(dia=>d){
				cout<<tipo<<endl;
			}
		}
	}
}*/
class Salgado: public Base, public Vencimento
{
private:
	float sodio;
	bool gluten;
	bool lactose;
	std::ostream& print(std::ostream& os) const {
		if(gluten==1 && lactose==1){
			return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Sodio: "<<sodio<<"mg, Contem Gluten e Lactose"<<endl
			      <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl
				  <<"Validade: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
		}
		if(gluten==0 && lactose==1){
			return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Sodio: "<<sodio<<"mg, Nao contem Gluten, Contem Lactose"<<endl
			      <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl
				  <<"Validade: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
		}
		if(gluten==1 && lactose==0){
			return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Sodio: "<<sodio<<"mg, Contem Gluten, Nao contem Lactose"<<endl
			      <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl
				  <<"Validade: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
		}
		else{
			return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Sodio: "<<sodio<<"mg, Nao Contem Gluten nem Lactose"<<endl
			      <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl
				  <<"Validade: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
		}
		
	}
	std::istream& read(std::istream& is) /*const*/ {
		string copiaquantidade, copiapreco, copiasodio, copiagluten, copialactose, copiadia, copiames, copiaano;
		getline(is, nome, ';');
		getline(is, copiaquantidade, ';');
		quantidade=atoi(copiaquantidade.c_str());
		getline(is, copiapreco, ';');
		preco=atof(copiapreco.c_str());
		getline(is, cb, ';');
		getline(is, copiasodio, ';');
		sodio=atof(copiasodio.c_str());
		getline(is, copiagluten, ';');
		if(copiagluten=="1"){
			gluten=1;
		}
		if(copiagluten=="0"){
			gluten=0;
		}
		getline(is, copialactose, ';');
		if(copialactose=="1"){
			lactose=1;
		}
		if(copialactose=="0"){
			lactose=0;
		}
		getline(is, fornecedor, ';');
		getline(is, cnpj, ';');
		getline(is, copiadia, '/');
		dia=atoi(copiadia.c_str());
		getline(is, copiames, '/');
		mes=atoi(copiames.c_str());
		getline(is, copiaano);
		ano=atoi(copiaano.c_str());
		return is;
	}
public:
	Salgado(/*int vCodigo, string vPrefixo*/);
	string getTipo();
    void setTipo(string t);
	string getNome();
    void setNome(string n);
	int getQuantidade();
    void setQuantidade(int q);
	float getPreco();
    void setPreco(float p);
	string getCb();
    void setCb(string c);
	string getFornecedor();
    void setFornecedor(string f);
	string getCnpj();
    void setCnpj(string a);
	float getSodio();
    void setSodio(float o);
	bool getGluten();
    void setGluten(bool x);
	bool getLactose();
    void setLactose(bool y);
	int getDia();
    void setDia(int d);
	int getMes();
    void setMes(int m);
	int getAno();
    void setAno(int a);
	//void escolhetipo(int d, int m, int a);
};
Salgado::Salgado(){
	tipo="Salgado";
	nome="";
	quantidade=0;
	preco=0;
	cb="";
	fornecedor="";
	cnpj="";
	sodio=0;
	gluten=0;
	lactose=0;
	dia=0;
	mes=0;
	ano=0;
}
string Salgado::getTipo(){
    return tipo;
}
void Salgado::setTipo(string t){
    tipo=t;
}
string Salgado::getNome(){
    return nome;
}
void Salgado::setNome(string n){
    nome=n;
}
int Salgado::getQuantidade(){
    return quantidade;
}
void Salgado::setQuantidade(int q){
    quantidade=q;
}
float Salgado::getPreco(){
    return preco;
}
void Salgado::setPreco(float p){
    preco=p;
}
string Salgado::getCb(){
    return cb;
}
void Salgado::setCb(string c){
    cb=c;
}
string Salgado::getFornecedor(){
    return fornecedor;
}
void Salgado::setFornecedor(string f){
    fornecedor=f;
}
string Salgado::getCnpj(){
    return cnpj;
}
void Salgado::setCnpj(string a){
    cnpj=a;
}
float Salgado::getSodio(){
    return sodio;
}
void Salgado::setSodio(float o){
    sodio=o;
}
bool Salgado::getGluten(){
	return gluten;
}
void Salgado::setGluten(bool x){
	gluten=x;
}
bool Salgado::getLactose(){
	return lactose;
}
void Salgado::setLactose(bool y){
	lactose=y;
}
int Salgado::getDia(){
    return dia;
}
void Salgado::setDia(int d){
    dia=d;
}
int Salgado::getMes(){
    return mes;
}
void Salgado::setMes(int m){
    mes=m;
}
int Salgado::getAno(){
    return ano;
}
void Salgado::setAno(int a){
    ano=a;
}
/*void Salgado::escolhetipo(int d, int m, int a){
	if(ano=>a){
		if(mes=>m){
			if(dia=>d){
				cout<<tipo<<endl;
			}
		}
	}
}*/
class Fruta: public Base, public Vencimento
{
private:
	int lote;
	string datalote;
	std::ostream& print(std::ostream& os) const {
		return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Lote: nº"<<lote<<"	Produzido em: "<<datalote<<endl
				  <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl
				  <<"Validade: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
	}
	std::istream& read(std::istream& is) {
		string copiaquantidade, copiapreco, copialote, copiadia, copiames, copiaano;
		getline(is, nome, ';');
		getline(is, copiaquantidade, ';');
		quantidade=atoi(copiaquantidade.c_str());
		getline(is, copiapreco, ';');
		preco=atof(copiapreco.c_str());
		getline(is, cb, ';');
		getline(is, copialote, ';');
		lote=atoi(copialote.c_str());
		getline(is, datalote, ';');
		getline(is, fornecedor, ';');
		getline(is, cnpj, ';');
		getline(is, copiadia, '/');
		dia=atoi(copiadia.c_str());
		getline(is, copiames, '/');
		mes=atoi(copiames.c_str());
		getline(is, copiaano);
		ano=atoi(copiaano.c_str());
		return is;
	}
public:
	Fruta();
	string getTipo();
    void setTipo(string t);
	string getNome();
    void setNome(string n);
	int getQuantidade();
    void setQuantidade(int q);
	float getPreco();
    void setPreco(float p);
	string getCb();
    void setCb(string c);
	string getFornecedor();
    void setFornecedor(string f);
	string getCnpj();
    void setCnpj(string a);
	int getLote();
    void setLote(int l);
	string getDatalote();
    void setDatalote(string d);
	int getDia();
    void setDia(int d);
	int getMes();
    void setMes(int m);
	int getAno();
    void setAno(int a);
	//void escolhetipo(int d, int m, int a);
};
Fruta::Fruta(){
	tipo="Fruta";
	nome="";
	quantidade=0;
	preco=0;
	cb="";
	fornecedor="";
	cnpj="";
	lote=0;
	datalote="";
	dia=0;
	mes=0;
	ano=0;
}
string Fruta::getTipo(){
    return tipo;
}
void Fruta::setTipo(string t){
    tipo=t;
}
string Fruta::getNome(){
    return nome;
}
void Fruta::setNome(string n){
    nome=n;
}
int Fruta::getQuantidade(){
    return quantidade;
}
void Fruta::setQuantidade(int q){
    quantidade=q;
}
float Fruta::getPreco(){
    return preco;
}
void Fruta::setPreco(float p){
    preco=p;
}
string Fruta::getCb(){
    return cb;
}
void Fruta::setCb(string c){
    cb=c;
}
string Fruta::getFornecedor(){
    return fornecedor;
}
void Fruta::setFornecedor(string f){
    fornecedor=f;
}
string Fruta::getCnpj(){
    return cnpj;
}
void Fruta::setCnpj(string a){
    cnpj=a;
}
int Fruta::getLote(){
    return lote;
}
void Fruta::setLote(int l){
    lote=l;
}
string Fruta::getDatalote(){
    return datalote;
}
void Fruta::setDatalote(string d){
    datalote=d;
}
int Fruta::getDia(){
    return dia;
}
void Fruta::setDia(int d){
    dia=d;
}
int Fruta::getMes(){
    return mes;
}
void Fruta::setMes(int m){
    mes=m;
}
int Fruta::getAno(){
    return ano;
}
void Fruta::setAno(int a){
    ano=a;
}
/*void Fruta::escolhetipo(int d, int m, int a){
	if(ano=>a){
		if(mes=>m){
			if(dia=>d){
				cout<<tipo<<endl;
			}
		}
	}
}*/
class Doce: public Base, public Vencimento
{
private:
	float acucar;
	bool gluten;
	bool lactose;
	std::ostream& print(std::ostream& os) const {
		if(gluten==1 && lactose==1){
			return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Açúcar: "<<acucar<<"mg, Contem Gluten e Lactose"<<endl
			      <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl
				  <<"Validade: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
		}
		if(gluten==0 && lactose==1){
			return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Açúcar: "<<acucar<<"mg, Nao contem Gluten, Contem Lactose"<<endl
			      <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl
				  <<"Validade: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
		}
		if(gluten==1 && lactose==0){
			return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Açúcar: "<<acucar<<"mg, Contem Gluten, Nao contem Lactose"<<endl
			      <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl
				  <<"Validade: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
		}
		else{
			return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Açúcar: "<<acucar<<"mg, Nao Contem Gluten nem Lactose"<<endl
			      <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl
				  <<"Validade: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
		}
	}
	std::istream& read(std::istream& is) /*const*/ {
		string copiaquantidade, copiapreco, copiaacucar, copiagluten, copialactose, copiadia, copiames, copiaano;
		getline(is, nome, ';');
		getline(is, copiaquantidade, ';');
		quantidade=atoi(copiaquantidade.c_str());
		getline(is, copiapreco, ';');
		preco=atof(copiapreco.c_str());
		getline(is, cb, ';');
		getline(is, copiaacucar, ';');
		acucar=atof(copiaacucar.c_str());
		getline(is, copiagluten, ';');
		if(copiagluten=="1"){
			gluten=1;
		}
		if(copiagluten=="0"){
			gluten=0;
		}
		getline(is, copialactose, ';');
		if(copialactose=="1"){
			lactose=1;
		}
		if(copialactose=="0"){
			lactose=0;
		}
		getline(is, fornecedor, ';');
		getline(is, cnpj, ';');
		getline(is, copiadia, '/');
		dia=atoi(copiadia.c_str());
		getline(is, copiames, '/');
		mes=atoi(copiames.c_str());
		getline(is, copiaano);
		ano=atoi(copiaano.c_str());
		return is;
	}
public:
	Doce();
	string getTipo();
    void setTipo(string t);
	string getNome();
    void setNome(string n);
	int getQuantidade();
    void setQuantidade(int q);
	float getPreco();
    void setPreco(float p);
	string getCb();
    void setCb(string c);
	string getFornecedor();
    void setFornecedor(string f);
	string getCnpj();
    void setCnpj(string a);
	float getAcucar();
    void setAcucar(float s);
	bool getGluten();
    void setGluten(bool x);
	bool getLactose();
    void setLactose(bool y);
	int getDia();
    void setDia(int d);
	int getMes();
    void setMes(int m);
	int getAno();
    void setAno(int a);
	//void escolhetipo(int d, int m, int a);
};
Doce::Doce(){
	tipo="Doce";
	nome="";
	quantidade=0;
	preco=0;
	cb="";
	fornecedor="";
	cnpj="";
	acucar=0;
	gluten=0;
	lactose=0;
	dia=0;
	mes=0;
	ano=0;
}
string Doce::getTipo(){
    return tipo;
}
void Doce::setTipo(string t){
    tipo=t;
}
string Doce::getNome(){
    return nome;
}
void Doce::setNome(string n){
    nome=n;
}
int Doce::getQuantidade(){
    return quantidade;
}
void Doce::setQuantidade(int q){
    quantidade=q;
}
float Doce::getPreco(){
    return preco;
}
void Doce::setPreco(float p){
    preco=p;
}
string Doce::getCb(){
    return cb;
}
void Doce::setCb(string c){
    cb=c;
}
string Doce::getFornecedor(){
    return fornecedor;
}
void Doce::setFornecedor(string f){
    fornecedor=f;
}
string Doce::getCnpj(){
    return cnpj;
}
void Doce::setCnpj(string a){
    cnpj=a;
}
float Doce::getAcucar(){
    return acucar;
}
void Doce::setAcucar(float s){
    acucar=s;
}
bool Doce::getGluten(){
	return gluten;
}
void Doce::setGluten(bool x){
	gluten=x;
}
bool Doce::getLactose(){
	return lactose;
}
void Doce::setLactose(bool y){
	lactose=y;
}
int Doce::getDia(){
    return dia;
}
void Doce::setDia(int d){
    dia=d;
}
int Doce::getMes(){
    return mes;
}
void Doce::setMes(int m){
    mes=m;
}
int Doce::getAno(){
    return ano;
}
void Doce::setAno(int a){
    ano=a;
}
/*void Doce::escolhetipo(int d, int m, int a){
	if(ano=>a){
		if(mes=>m){
			if(dia=>d){
				cout<<tipo<<endl;
			}
		}
	}
}*/
class CD: public Base
{
private:
	string estilo;
	string artista;
	std::ostream& print(std::ostream& os) const {
		return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Estilo: "<<estilo<<"	Artista: "<<artista<<endl
				  <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl;
	}
	std::istream& read(std::istream& is) {
		string copiaquantidade, copiapreco;
		getline(is, nome, ';');
		getline(is, copiaquantidade, ';');
		quantidade=atoi(copiaquantidade.c_str());
		getline(is, copiapreco, ';');
		preco=atof(copiapreco.c_str());
		getline(is, cb, ';');
		getline(is, estilo, ';');
		getline(is, artista, ';');
		getline(is, fornecedor, ';');
		getline(is, cnpj);
		return is;
	}
public:
	CD();
	string getTipo();
    void setTipo(string t);
	string getNome();
    void setNome(string n);
	int getQuantidade();
    void setQuantidade(int q);
	float getPreco();
    void setPreco(float p);
	string getCb();
    void setCb(string c);
	string getFornecedor();
    void setFornecedor(string f);
	string getCnpj();
    void setCnpj(string a);
	string getEstilo();
    void setEstilo(string e);
	string getArtista();
    void setArtista(string a);
	int getDia();
    void setDia(int d);
	int getMes();
    void setMes(int m);
	int getAno();
    void setAno(int a);
	//void escolhetipo(int d, int m, int a);
};
CD::CD(){
	tipo="CD";
	nome="";
	quantidade=0;
	preco=0;
	cb="";
	fornecedor="";
	cnpj="";
	estilo="";
	artista="";
}
string CD::getTipo(){
    return tipo;
}
void CD::setTipo(string t){
    tipo=t;
}
string CD::getNome(){
    return nome;
}
void CD::setNome(string n){
    nome=n;
}
int CD::getQuantidade(){
    return quantidade;
}
void CD::setQuantidade(int q){
    quantidade=q;
}
float CD::getPreco(){
    return preco;
}
void CD::setPreco(float p){
    preco=p;
}
string CD::getCb(){
    return cb;
}
void CD::setCb(string c){
    cb=c;
}
string CD::getFornecedor(){
    return fornecedor;
}
void CD::setFornecedor(string f){
    fornecedor=f;
}
string CD::getCnpj(){
    return cnpj;
}
void CD::setCnpj(string a){
    cnpj=a;
}
string CD::getEstilo(){
    return estilo;
}
void CD::setEstilo(string e){
    estilo=e;
}
string CD::getArtista(){
    return artista;
}
void CD::setArtista(string a){
    artista=a;
}
/*void CD::escolhetipo(int d, int m, int a){
	if(ano=>a){
		if(mes=>m){
			if(dia=>d){
				cout<<tipo<<endl;
			}
		}
	}
}*/
class DVD: public Base
{
private:
	string genero;
	int duracao;
	std::ostream& print(std::ostream& os) const {
		return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Genero: "<<genero<<"	Duração: "<<duracao<<"min"<<endl
				  <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl;
	}
	std::istream& read(std::istream& is) {
		string copiaquantidade, copiapreco, copiaduracao;
		getline(is, nome, ';');
		getline(is, copiaquantidade, ';');
		quantidade=atoi(copiaquantidade.c_str());
		getline(is, copiapreco, ';');
		preco=atof(copiapreco.c_str());
		getline(is, cb, ';');
		getline(is, genero, ';');
		getline(is, copiaduracao, ';');
		duracao=atoi(copiaduracao.c_str());
		getline(is, fornecedor, ';');
		getline(is, cnpj);
		return is;
	}
public:
	DVD();
	string getTipo();
    void setTipo(string t);
	string getNome();
    void setNome(string n);
	int getQuantidade();
    void setQuantidade(int q);
	float getPreco();
    void setPreco(float p);
	string getCb();
    void setCb(string c);
	string getFornecedor();
    void setFornecedor(string f);
	string getCnpj();
    void setCnpj(string a);
	string getGenero();
    void setGenero(string g);
	int getDuracao();
    void setDuracao(int d);
	//void escolhetipo(int d, int m, int a);
};
DVD::DVD(){
	tipo="DVD";
	nome="";
	quantidade=0;
	preco=0;
	cb="";
	fornecedor="";
	cnpj="";
	genero="";
	duracao=0;
}
string DVD::getTipo(){
    return tipo;
}
void DVD::setTipo(string t){
    tipo=t;
}
string DVD::getNome(){
    return nome;
}
void DVD::setNome(string n){
    nome=n;
}
int DVD::getQuantidade(){
    return quantidade;
}
void DVD::setQuantidade(int q){
    quantidade=q;
}
float DVD::getPreco(){
    return preco;
}
void DVD::setPreco(float p){
    preco=p;
}
string DVD::getCb(){
    return cb;
}
void DVD::setCb(string c){
    cb=c;
}
string DVD::getFornecedor(){
    return fornecedor;
}
void DVD::setFornecedor(string f){
    fornecedor=f;
}
string DVD::getCnpj(){
    return cnpj;
}
void DVD::setCnpj(string a){
    cnpj=a;
}
string DVD::getGenero(){
    return genero;
}
void DVD::setGenero(string g){
    genero=g;
}
int DVD::getDuracao(){
    return duracao;
}
void DVD::setDuracao(int d){
    duracao=d;
}
/*void DVD::escolhetipo(int d, int m, int a){
	if(ano=>a){
		if(mes=>m){
			if(dia=>d){
				cout<<tipo<<endl;
			}
		}
	}
}*/
class Livro: public Base
{
private:
	string autor;
	string editora;
	int anopublicacao;
	std::ostream& print(std::ostream& os) const {
		return os <<"Tipo: "<<tipo<< "   Nome: " <<nome<<"   Quantidade: "<< quantidade<<" unidades"<<endl
				  <<"Preco unitario: R$" << preco <<"   Codigo de Barras: "<<cb<<endl
				  <<"Autor: "<<autor<<"	Editora: "<<editora<<"	Ano: "<<anopublicacao<<endl
				  <<"Fornecedor: "<<fornecedor<<"   Cnpj do fornecedor: "<<cnpj<< endl;
	}
	std::istream& read(std::istream& is) {
		string copiaquantidade, copiapreco, copiaano;
		getline(is, nome, ';');
		getline(is, copiaquantidade, ';');
		quantidade=atoi(copiaquantidade.c_str());
		getline(is, copiapreco, ';');
		preco=atof(copiapreco.c_str());
		getline(is, cb, ';');
		getline(is, autor, ';');
		getline(is, editora, ';');
		getline(is, copiaano, ';');
		anopublicacao=atoi(copiaano.c_str());
		getline(is, fornecedor, ';');
		getline(is, cnpj);
		return is;
	}
public:
	Livro();
	string getTipo();
    void setTipo(string t);
	string getNome();
    void setNome(string n);
	int getQuantidade();
    void setQuantidade(int q);
	float getPreco();
    void setPreco(float p);
	string getCb();
    void setCb(string c);
	string getFornecedor();
    void setFornecedor(string f);
	string getCnpj();
    void setCnpj(string a);
	string getAutor();
    void setAutor(string a);
	string getEditora();
    void setEditora(string e);
	int getAnopublicacao();
    void setAnopublicacao(int y);
	//void escolhetipo(int d, int m, int a);
};
Livro::Livro(){
	tipo="Livro";
	nome="";
	quantidade=0;
	preco=0;
	cb="";
	fornecedor="";
	cnpj="";
	autor="";
	editora="";
	anopublicacao=0;
}
string Livro::getTipo(){
    return tipo;
}
void Livro::setTipo(string t){
    tipo=t;
}
string Livro::getNome(){
    return nome;
}
void Livro::setNome(string n){
    nome=n;
}
int Livro::getQuantidade(){
    return quantidade;
}
void Livro::setQuantidade(int q){
    quantidade=q;
}
float Livro::getPreco(){
    return preco;
}
void Livro::setPreco(float p){
    preco=p;
}
string Livro::getCb(){
    return cb;
}
void Livro::setCb(string c){
    cb=c;
}
string Livro::getFornecedor(){
    return fornecedor;
}
void Livro::setFornecedor(string f){
    fornecedor=f;
}
string Livro::getCnpj(){
    return cnpj;
}
void Livro::setCnpj(string a){
    cnpj=a;
}
string Livro::getAutor(){
    return autor;
}
void Livro::setAutor(string a){
    autor=a;
}
string Livro::getEditora(){
    return editora;
}
void Livro::setEditora(string e){
    editora=e;
}
int Livro::getAnopublicacao(){
    return anopublicacao;
}
void Livro::setAnopublicacao(int y){
    anopublicacao=y;
}
/*void Livro::escolhetipo(int d, int m, int a){
	if(ano=>a){
		if(mes=>m){
			if(dia=>d){
				cout<<tipo<<endl;
			}
		}
	}
}*/