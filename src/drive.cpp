#include <iostream>
#include <string.h>

#include "ST.h"

using namespace std;
int main(int argc, char const *argv[])
{
    string fileName;
    cout << "RODOU" << endl;
    STGame E;

    if(argc > 1){
        fileName = argv[1];
    }else{
        cout << "Digite o nome do arquivo de apostas a ser lido" << endl;
        return -1;
    }
    enum attribute {ID, NOME, FABRICANTE, ANO, VELOCIDADE, AUTONOMIA, COMPRIMENTO, ENVERGADURA};
    // _ID, string nome, string fabricante, int ano, int velocidade,int autonomia, float comprimento, float envergadura
    //STCard cards("A1", "Boeing 737-2C3/Adv", "Cruzeiro - Brazil", 1967, 927, 4260, 30.53, 28.35);
    //cout << cards.getAttribute(STCard::ANO);
    //cards.displayCard(cards);
 //    std::vector<STCard> v_cards;
    // v_cards = E.readDeckFromFile(fileName);
 //    for (int i = 0; i < v_cards.size(); ++i)
 //    {
 //        E.dealCards(1);
 //        // v_cards[i].displayCard(v_cards[i]);
 //    }
    E.run(fileName);
	return EXIT_SUCCESS;
}
