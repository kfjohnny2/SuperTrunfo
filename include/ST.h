#include<iostream>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.
#include <cstring>
#include <cstdio>
using namespace std;

enum attribute {ID, NOME, FABRICANTE, ANO, VELOCIDADE, AUTONOMIA, COMPRIMENTO, ENVERGADURA};

class STCard {

    public:
        STCard (string _ID, string nome, string fabricante, int ano, int velocidade,int autonomia, float comprimento,float envergadura)
        {
            this-> m_ID = _ID;
            this-> m_nome = nome;
            this->m_fabricante = fabricante;
            this->m_ano = ano;
            this->m_velocidade_cruz = velocidade;
            this-> m_autonomia_voo = autonomia;
            this->m_comprimento = comprimento;
            this->m_envergadura = envergadura;
        }
        //template <typename A>
        string getAttribute(attribute _a)
        {
            std::stringstream valor;
            std::string Resultado;
            switch (_a){
                case attribute::ID:
                    valor << m_ID;
                    Resultado = valor.str();
                    return Resultado;
                case attribute::NOME:
                    valor << m_nome;
                    Resultado = valor.str();
                    return Resultado;
                case attribute::FABRICANTE:
                    valor << m_fabricante;
                    Resultado = valor.str();
                    return Resultado;
                case attribute::ANO:
                    valor << m_ano;
                    Resultado = valor.str();
                    return Resultado;
                case attribute::VELOCIDADE:
                    valor << m_velocidade_cruz;
                    Resultado = valor.str();
                    return Resultado;
                case attribute::AUTONOMIA:
                    valor << m_autonomia_voo;
                    Resultado = valor.str();
                    return Resultado;
                case attribute::COMPRIMENTO:
                    valor << m_comprimento;
                    Resultado = valor.str();
                    return Resultado;
                case attribute::ENVERGADURA:
                   valor << m_envergadura;
                    Resultado = valor.str();
                    return Resultado;
            }
        }
        void displayCard (STCard ex);

    private:

        std::string m_ID;
        std::string m_nome;
        std::string m_fabricante;
        int m_ano;
        int m_velocidade_cruz;
        int m_autonomia_voo;
        float  m_comprimento;
        float m_envergadura;

};

class STPlayer
{
public:
    STPlayer (string nome)
    {
        this->m_nome = nome;
    }
    std::string getName() const
    {
        return m_nome;
    }
    STCard popCard ()
    {
        return cartas[cartas.size() - 1];
        cartas.pop_back();
    }
    attribute chooseRandomAttrib () const
    {
    	int v1 = rand()%(7-4 + 1) + 4;
     // int v1 = rand() % 8;
             switch (v1){
             case attribute::VELOCIDADE:
             	 return attribute::VELOCIDADE;
                 break;
             case attribute::AUTONOMIA:
             	 return attribute::AUTONOMIA;
                 break;
             case attribute::COMPRIMENTO:
                 return attribute::COMPRIMENTO;
                 break;
             case attribute::ENVERGADURA:
                 return attribute::ENVERGADURA;
                 break;
         }
    }
    // int chooseRandomAttrib () const
    // {
    //     int v1 = rand() % 8;
    //     getAttribute()
    // }
 //    void quickSort(vector<STCard>& v, int left, int right, int at) {
 //      int i = left, j = right;
 //      STCard tmp;
 //      int pivot = atoi((v[(left + right) / 2].getAttribute(at)).c_str());
 //      /* partition */
 //      while (i <= j) {
 //            while (atoi((v[i].getAttribute(at)).c_str()) < pivot)
 //                  i++;
 //            while (atoi((v[j].getAttribute(at)).c_str()) > pivot)
 //                  j--;
 //            if (i <= j) {
 //                  tmp = v[i];
 //                  v[i] = v[j];
 //                  v[j] = tmp;
 //                  i++;
 //                  j--;
 //            }
 //      };
 //      /* recursion */
 //      if (left < j)
 //            quickSort(v, left, j, at);
 //      if (i < right)
 //            quickSort(v, i, right, at);

	// }
 //   	STCard chooseCardAI(attribute attrib)
 //    {
 //    /*	std::string ID = "TRUNFO", nome = "TRUNFO", fabricante = "TRUNFO";
	// 	int ano = 2050, velocidade = 10000, autonomia = 100000;
	// 	float comprimento = 100, envergadura = 1000;
	// 	STCard trunfo (ID, nome, fabricante, ano, velocidade, autonomia, comprimento,envergadura);*/
 //    	cartas.quickSort(cartas, 0 , cartas.size()-1, attrib);
 //    	return cartas[size()-1];

 //    }


    void  addCard (STCard b)
    {
        cartas.push_back(b);
    }
    void displayCard ()
    {
        int t = cartas.size() -1;
        for (int i = 0; i < t; i++)
        {
           cout <<  cartas[i].getAttribute(attribute::ID) << endl;
           cout <<  cartas[i].getAttribute(attribute::NOME) << endl;
           cout <<  cartas[i].getAttribute(attribute::FABRICANTE) << endl;
           cout <<  cartas[i].getAttribute(attribute::ANO) << endl;
           cout <<  cartas[i].getAttribute(attribute::VELOCIDADE) << endl;
           cout <<  cartas[i].getAttribute(attribute::AUTONOMIA) << endl;
           cout <<  cartas[i].getAttribute(attribute::COMPRIMENTO) << endl;
           cout <<  cartas[i].getAttribute(attribute::ENVERGADURA) << endl;
        }
    }
    int nCards()
    {
        int sz = cartas.size();
        return sz;
    }
    std::vector<STCard> getCardsPlayer(STPlayer _player){
        return _player.cartas;
    }
private:
    std::vector <STCard> cartas;
    std::string m_nome;
};

class STGame
{

public:

    vector <STCard> readDeckFromFile(string fileName);
    void addPlayer (STPlayer j, std::vector<STPlayer>& _jogadores){
        _jogadores.push_back(j);
    }
    void dealCards(int k)
    {
       int qtd, vez;
       for (int i = 0; i < (m_cards.size()); i++)
       {
           vez = rand() % (jogadores.size()-1);
           if(jogadores[vez].nCards() <= k)
           jogadores[vez].addCard(m_cards[i]);

       }
    }

    void displayDeck()
    {
        for (int i = 0; i < m_cards.size(); ++i)
        {
            m_cards[i].displayCard(m_cards[i]);
        }
    }

    void displayPlayers()
    {
        for (int i = 0; i<jogadores.size() ; i++){
            if (jogadores[i].nCards()>0){
                cout << jogadores[i].getName();
            }
        }
    }

    void run(string fileName)
    {
        bool a = true;
        int cont;
        attribute maior;
        int sizeCardsPlayer1, sizeCardsPlayer2;
        STPlayer player1("Irena");
        STPlayer player2("Johnny");
        STGame game;
        m_cards = game.readDeckFromFile(fileName); // AQUI ELE VAI LER O ARQUIVO E RETORNAR UM VECTOR COM AS CARTAS
        game.dealCards(2);
        game.addPlayer(player1, jogadores);
        game.addPlayer(player2, jogadores);
        cout << jogadores.size() << endl;
        int vez = rand() % (jogadores.size()-1);
        maior = jogadores[vez].chooseRandomAttrib();
        std::vector<STCard> v_cardsPlayer1, v_cardsPlayer2;
        while (a){
            for (int i = 0; i<jogadores.size() -1; i++ ){
            	v_cardsPlayer1 = jogadores[i].getCardsPlayer(jogadores[i]);
        cout << "LEEEEU" << endl;
            	sizeCardsPlayer1 = v_cardsPlayer1.size();
                for (int j = i; j<jogadores.size()-1;j++){
                    v_cardsPlayer2 = jogadores[j].getCardsPlayer(jogadores[j]);
                    sizeCardsPlayer2 = v_cardsPlayer2.size();
                    if ((jogadores[i].nCards() > 0) && (jogadores[j].nCards() >0)){
                            // void displayCardOnTable(jogadores);
                            if (atof(v_cardsPlayer1[sizeCardsPlayer1-1].getAttribute(maior).c_str()) > atof(v_cardsPlayer2[sizeCardsPlayer2-1].getAttribute(maior).c_str())){ // AGORA O ERRO É PQ "maior" NÃO É UM MEMBRO DE STCard
                                jogadores[i].addCard(jogadores[i].popCard()); // PORQUE POPCARD RETORNA A ÚLTIMA CARTA DO DECK E ADD CARTA RECEBE UMA CARTA, sacou?
                                // jogadores[i].chooseRandomAttrib(maior);
                            }else if (atof(v_cardsPlayer1[sizeCardsPlayer1-1].getAttribute(maior).c_str()) < atof(v_cardsPlayer2[sizeCardsPlayer2-1].getAttribute(maior).c_str())){
                                jogadores[j].addCard(jogadores[i].popCard());
                                // jogadores[j].chooseRandomAttrib(maior);
                            }
                    }
                }
                displayStatusRound(cont,jogadores, maior );
	            if (jogadores[i].nCards() == 0){
	                swap(jogadores[i],jogadores[sizeCardsPlayer1-1]);
	                jogadores[i].popCard();
	            }

	            }
            }
            cont++;
    }
    void displayStatusRound(int rodada, vector <STPlayer> jogadores, attribute _t){
        cout << "Rodada: " << rodada << endl;
        for (int i = 0; i<jogadores.size() - 1; i++){
            cout << "Jogador : " << jogadores[i].getName() << endl;
            jogadores[i].displayCard();
        }
        cout << "Atributo da rodada: " << _t;
    }
    vector <STCard> displayCardOnTable(vector <STPlayer> jogadores){
        vector <STCard> Cartas_mesa;
        for (int i = 0; i<jogadores.size() - 1; i++){
			Cartas_mesa.push_back((jogadores[i].getCardsPlayer(jogadores[i]))[(jogadores[i].getCardsPlayer(jogadores[i])).size()-1]);
        }
        return Cartas_mesa;
    }
    string winner(string fileName){
        run (fileName);
            if (jogadores.size() == 1){
                    return jogadores[0].getName();

                }

    }
private:
    vector <STPlayer> jogadores;
    std::vector<STCard> m_cards;
};