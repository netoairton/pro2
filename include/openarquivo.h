/**
 * @file	openarquivo.h
 * @brief	Declaracao do prototipo da funcao que calcula o numero de linhas em um arquivo
 * @author	Airton Neto(netoairton@yahoo.com.br)
 * @since	20/05/2017
 * @date	21/05/2017
 */
#ifndef OPENFILE1_H
#define OPENFILE1_H

#include<fstream>
using std::ifstream;
using std::ofstream;
#include<string>
using std::string;
/**
 * @brief Funcao que conta o numero de linhas no arquivo a ser aberto
 * @param Arquivo String com o nome do arquivo
 */
int aberturaarquivo(string Arquivo);
#endif