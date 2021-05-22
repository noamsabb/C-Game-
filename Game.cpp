//
// Created by Noam Sabban on 30/12/2019.
//

#include "Game.h"
#include <iostream>
#include<string>
#include <zconf.h>
//#include <windows.h>


#define ROUND 4

using namespace std;
Game::Game()
{

    this->_tab = new NumSet* [2];
    this->_tab[0]= new NumSet;
    this->_tab[1]= new NumSet;

}

Game::~Game()
{
    delete [] this->_tab;
}

int Game::tirage()
{
    int tirage = (rand() %10 +1);
    return tirage;
}

int Game::findCard(int player, int num)
{
    if(this->_tab[player - 1]->find(num) != -1)
        return this->_tab[player - 1]->find(num);
    else
        return -1;
}

void Game::print(int player)
{
    cout << this->_tab[player - 1]->getName() << "'s hand: ";

    cout<<*_tab[player - 1];
}

void Game::chooseWinner()
{
    int again;
    if(this->_tab[0]->average() > this->_tab[1]->average())
        cout << this->_tab[0]->getName() << "(P1) won with average of: " << this->_tab[0]->average() << endl;
    else
        cout << this->_tab[1]->getName() << "(P2) won with average of: " << this->_tab[1]->average() << endl;


    this->_tab[0]->refreshList();
    this->_tab[1]->refreshList();

    cout<< "Press any Number to Game Menu ";
    cin>>again;
    cout<<endl;

}

void Game::gameMenu() {
    int choice;
    while(1) {

        cout << "---------- Welcome to the Game ----------" << endl << endl;
        cout << "1)Player VS Player" << endl;
        cout << "2)Player VS Computer" << endl;
        cout << "3)Computer VS Computer" << endl;
        cout << "4)Exit" << endl;
        cout << endl << "Your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {

            case (1):
                this->playerVsPlayer();
                break;

            case (2):
                this->playerVsComp();
                break;

            case (3):
                this->compVsComp();
                break;

            case (4):
                return;
                break;
            default:
                cout << "Wrong choice, please try again" << endl;
        }
    }

}

void Game::playerVsPlayer() {

    cout<<"Player VS Player"<<endl;
    //set Name
    string name;
    cout << "Player1 enter your name: ";
    cin>>name;
    this->_tab[0]->setName(name);

    cout << "Player2 enter your name: ";
    cin>>name;
    this->_tab[1]->setName(name);
    cout<<endl;

    //Start Rounds
    int prop1 = 0, prop2 = 0;
    int indexProp1 = 0;
    int indexProp2 = 0;

    for (int i = 0; i < ROUND; ++i) {
        cout << "*****   ROUND " << i + 1 << "   *****" << endl;

        this->print(1);
        this->print(2);

        int tirage = this->tirage();
        cout << endl << "The card proposed is: " << tirage << endl;


        if ((i % 2) == 0) {
            cout << this->_tab[0]->getName() << "(P1) proposition: ";
            cin >> prop1;

            indexProp1 = findCard(1, prop1);
            while (indexProp1 == -1) {
                cout << this->_tab[0]->getName() << "(P1) proposition out of range: ";
                cin >> prop1;
                indexProp1 = findCard(1, prop1);
            }

            cout << this->_tab[1]->getName() << "(P2) proposition: ";
            cin >> prop2;
            cout << endl;

            indexProp2 = findCard(2, prop2);
            while (indexProp2 == -1) {
                cout << this->_tab[1]->getName() << "(P2) proposition out of range: ";
                cin >> prop2;
                cout << endl;
                indexProp2 = findCard(2, prop2);
            }
        } else {
            cout << this->_tab[1]->getName() << "(P2) proposition: ";
            cin >> prop2;

            indexProp2 = findCard(2, prop2);
            while (indexProp2 == -1) {
                cout << this->_tab[1]->getName() << "(P2) proposition out of range: ";
                cin >> prop2;
                indexProp2 = findCard(2, prop2);
            }

            cout << this->_tab[0]->getName() << "(P1) proposition: ";
            cin >> prop1;
            cout << endl;

            indexProp1 = findCard(1, prop1);
            while (indexProp1 == -1) {
                cout << this->_tab[0]->getName() << "(P1) proposition out of range: ";
                cin >> prop1;
                cout << endl;
                indexProp1 = findCard(1, prop1);
            }
        }


        if (prop1 > prop2) {
            this->_tab[0]->replace(indexProp1, tirage);
            this->_tab[1]->reduce(indexProp2);
        }

        if (prop1 < prop2) {
            this->_tab[1]->replace(indexProp2, tirage);
            this->_tab[0]->reduce(indexProp1);
        }

        if(prop1 == prop2)
        {
            if(this->_tab[0]->max() > this->_tab[1]->max())
            {
                this->_tab[0]->replace(indexProp1, tirage);
                this->_tab[1]->reduce(indexProp2);
            }
            if(this->_tab[1]->max()>this->_tab[0]->max())
            {
                this->_tab[1]->replace(indexProp2, tirage);
                this->_tab[0]->reduce(indexProp1);
            }
            if(this->_tab[0]->max() == this->_tab[1]->max())
                cout << "No one wins this turn." << endl;
        }
    }

    cout << "Final hands:" << endl;
    this->print(1);
    this->print(2);
    cout << endl;
    this->chooseWinner();
}

void Game::playerVsComp()
{
    cout<<"Player VS Computer"<<endl;

    //set Name
    string name;
    cout << "Player enter your name: ";
    cin>>name;
    cout<<endl;
    this->_tab[0]->setName(name);


    this->_tab[1]->setName("Computer");

    //Start Rounds
    int prop1 = 0, prop2 = 0;
    int indexProp1 = 0;
    int indexProp2 = 0;

    for (int i = 0; i < ROUND; ++i)
    {
        cout << "*****   ROUND " << i + 1 << "   *****" << endl;

        this->print(1);
        this->print(2);

        int tirage = this->tirage();
        cout << endl << "The card proposed is: " << tirage << endl;


        if ((i % 2) == 0) {
            cout << this->_tab[0]->getName() << "(P1) proposition: ";
            cin >> prop1;

            indexProp1 = findCard(1, prop1);
            while (indexProp1 == -1) {
                cout << this->_tab[0]->getName() << "(P1) proposition out of range: ";
                cin >> prop1;
                indexProp1 = findCard(1, prop1);
            }
            int num= (rand() %10 +1);
            if ((num %2)==0)
            {
                prop2=this->_tab[1]->max();
                indexProp2 = findCard(2, prop2);
                cout << "Computer proposition: "<<prop2<<endl;
            } else
            {
                prop2=this->_tab[1]->min();
                indexProp2 = findCard(2, prop2);
                cout << "Computer proposition: "<<prop2<<endl;
            }

/*        prop2 = this->_tab[1]->max();
        indexProp2 = findCard(2, prop2);
        cout << "Computer proposition: "<<prop2;*/
            cout << endl<<endl;

        } else {
            /*prop2 = this->_tab[1]->max();
            indexProp2 = findCard(2, prop2);
            cout << "Computer proposition: "<< prop2<<endl;*/


            int num= (rand() %10 +1);
            if ((num %2)==0)
            {
                prop2=this->_tab[1]->max();
                indexProp2 = findCard(2, prop2);
                cout << "Computer proposition: "<<prop2<<endl;
            } else
            {
                prop2=this->_tab[1]->min();
                indexProp2 = findCard(2, prop2);
                cout << "Computer proposition: "<<prop2<<endl;
            }


            cout << this->_tab[0]->getName() << "(P1) proposition: ";
            cin >> prop1;
            cout << endl;

            indexProp1 = findCard(1, prop1);
            while (indexProp1 == -1) {
                cout << this->_tab[0]->getName() << "(P1) proposition out of range: ";
                cin >> prop1;
                cout << endl;
                indexProp1 = findCard(1, prop1);
            }
        }


        if (prop1 > prop2) {
            this->_tab[0]->replace(indexProp1, tirage);
            this->_tab[1]->reduce(indexProp2);
        }

        if (prop1 < prop2) {
            this->_tab[1]->replace(indexProp2, tirage);
            this->_tab[0]->reduce(indexProp1);
        }

        if(prop1 == prop2)
        {
            if(this->_tab[0]->max() > this->_tab[1]->max())
            {
                this->_tab[0]->replace(indexProp1, tirage);
                this->_tab[1]->reduce(indexProp2);
            }
            if(this->_tab[1]->max()>this->_tab[0]->max())
            {
                this->_tab[1]->replace(indexProp2, tirage);
                this->_tab[0]->reduce(indexProp1);
            }
            if(this->_tab[0]->max() == this->_tab[1]->max())
                cout << "No one wins this turn." << endl;
        }
    }

    cout << "Final hands:" << endl;
    this->print(1);
    this->print(2);
    cout << endl;
    this->chooseWinner();
}

void Game::compVsComp()
{
//Set Names
    this->_tab[0]->setName("Computer1");
    this->_tab[1]->setName("Computer2");

    //Start Rounds
    int prop1 = 0, prop2 = 0;
    int indexProp1 = 0;
    int indexProp2 = 0;
    cout<<"Computer VS Computer"<<endl;

    for (int i = 0; i < ROUND; ++i)
    {
        sleep(3);
        cout << "*****   ROUND " << i + 1 << "   *****" << endl;

        this->print(1);
        this->print(2);

        int tirage = this->tirage();
        cout << endl << "The card proposed is: " << tirage << endl;


        if ((i % 2) == 0) {

            int num= (rand() %10 +1);
            if ((num %2)==0)
            {
                prop1=this->_tab[0]->max();
                indexProp1 = findCard(1, prop1);
                cout << "Computer1 proposition: "<<prop1<<endl;
            } else
            {
                prop1=this->_tab[0]->min();
                indexProp1 = findCard(1, prop1);
                cout << "Computer1 proposition: "<<prop1<<endl;
            }

            num= (rand() %10 +1);
            if ((num %2)==0)
            {
                prop2 = this->_tab[1]->max();
                indexProp2 = findCard(2, prop2);
                cout << "Computer2 proposition: "<<prop2;
                cout << endl<<endl;
            } else
            {
                prop2 = this->_tab[1]->min();
                indexProp2 = findCard(2, prop2);
                cout << "Computer2 proposition: "<<prop2;
                cout << endl<<endl;
            }


        } else {

            int num= (rand() %10 +1);
            if ((num %2)==0)
            {
                prop2 = this->_tab[1]->max();
                indexProp2 = findCard(2, prop2);
                cout << "Computer2 proposition: "<<prop2;
                cout << endl;
            } else
            {
                prop2 = this->_tab[1]->min();
                indexProp2 = findCard(2, prop2);
                cout << "Computer2 proposition: "<<prop2;
                cout << endl;
            }

            num= (rand() %10 +1);
            if ((num %2)==0)
            {
                prop1=this->_tab[0]->max();
                indexProp1 = findCard(1, prop1);
                cout << "Computer1 proposition: "<<prop1<<endl<<endl;
            } else
            {
                prop1=this->_tab[0]->min();
                indexProp1 = findCard(1, prop1);
                cout << "Computer1 proposition: "<<prop1<<endl<<endl;
            }


        }


        if (prop1 > prop2) {
            this->_tab[0]->replace(indexProp1, tirage);
            this->_tab[1]->reduce(indexProp2);
        }

        if (prop1 < prop2) {
            this->_tab[1]->replace(indexProp2, tirage);
            this->_tab[0]->reduce(indexProp1);
        }

        if(prop1 == prop2)
        {
            if(this->_tab[0]->max() > this->_tab[1]->max())
            {
                this->_tab[0]->replace(indexProp1, tirage);
                this->_tab[1]->reduce(indexProp2);
            }
            if(this->_tab[1]->max()>this->_tab[0]->max())
            {
                this->_tab[1]->replace(indexProp2, tirage);
                this->_tab[0]->reduce(indexProp1);
            }
            if(this->_tab[0]->max() == this->_tab[1]->max())
                cout << "No one wins this turn." << endl;
        }
    }

    cout<< "Final hands:" << endl;
    this->print(1);
    this->print(2);
    cout << endl;
    this->chooseWinner();
}




