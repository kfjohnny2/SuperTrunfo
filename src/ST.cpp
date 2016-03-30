#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.
#include <cstring>
#include <cstdio>

#include "ST.h"

using namespace std;

void STCard::displayCard (STCard ex)
{
	cout << ex.m_ID << endl;
	cout << ex.m_nome << endl;
	cout << ex.m_fabricante << endl;
	cout << ex.m_ano << endl;
	cout << ex.m_velocidade_cruz << endl;
	cout << ex.m_autonomia_voo << endl;
	cout << ex.m_comprimento << endl;
	cout << ex.m_envergadura << endl;
}



vector<STCard> STGame::readDeckFromFile(string fileName){
	std::string token;
	std::ifstream file(fileName);
	std::string ID, nome, fabricante;
	int ano, velocidade, autonomia;
	float comprimento, envergadura;
	int cont = 0; // Count the read lines of file
	//STCard card(ID,nome,fabricante,ano,velocidade,autonomia,comprimento,envergadura);
	std::vector<STCard> v_cards;
	while(std::getline(file, token)) {
		if (!token.empty()){
	    std::stringstream line(token);
	    // cout << token << endl;
		    while(line >> token){
	            if(cont == attribute::ID){
					ID = token.c_str();
				}
				if(cont == attribute::NOME){
					nome = token.c_str();
				}
				if(cont == attribute::FABRICANTE){
					fabricante = token.c_str();
				}
				if(cont == attribute::ANO){
					ano = atoi(token.c_str());
				}
				if(cont == attribute::VELOCIDADE){
					velocidade = atoi(token.c_str());
				}
				if(cont == attribute::AUTONOMIA){
					autonomia = atoi(token.c_str());
				}
				if(cont == attribute::COMPRIMENTO){
					comprimento = (float)atoi(token.c_str());
				}
				if(cont == attribute::ENVERGADURA){
					envergadura = (float)atoi(token.c_str());
				}
		    }
	        if(file.unget().get() == '\n') { /* Detection new lines */
	  			cont ++;
		    	//cout << "Nova linha encontrada" << endl;
	        }
	        if(file.eof()){
	        	break;
	        }
		    if (cont > 7){
	          	STCard card(ID, nome, fabricante, ano, velocidade, autonomia, comprimento, envergadura);
	          	// v_cards.insert(v_cards.end(), card);
		    	v_cards.push_back(card);
		    	// cout<< "INSERIU" << endl;
		    	cont = 0;
		    	continue;
		    }
		}
	}
	file.close();
	return v_cards;
}