#include "Game.h"
#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <zconf.h>


using namespace std;

void Game::menu() {
    int choice;
    while (1) {
        cout << "---------- Welcome to the Game ----------" << endl;
        cout << "1) Player VS Player" << endl;
        cout << "2) Player VS Computer" << endl;
        cout << "3) Computer VS Computer" << endl;
        cout << "4) Exit" << endl;
        cout <<endl<< "Your choice : ";
        cin >> choice;
        cout<<endl;
        switch (choice) {
            case 1:this->playerVSplayer();
                break;
            case 2:this->playerVScomp();
                break;
            case 3:this->compVScomp();
                break;
            case 4:
                return;
                break;
            default:
                cout << "Wrong choice, plese try again" << endl;

        }
    }
}
void Game::playerVScomp() {
    int c1, c2 = 0;
    int b;
    cout << "PLAYER VS. COMPUTER" << endl;
    cout << "Player, enter your name : ";
    string t;
    cin >> t;
    this->_p1.setName(t);
    this->_p2.setName("COMPUTER");
    cout<<endl;
    for (int i = 0; i < 4; i++) {
        cout << "*****   ROUND " << i + 1 << "   *****" << endl;
        cout << "Player: " << this->_p1;     /*opeateur qui imprime */
        cout << "Computer: " << this->_p2;
        b = rand() % 10 + 1;
        cout<<endl;
        cout << "The card to be replaced is : " << b << endl;
        if ((i % 2) == 0) {                                                   /*si homme commence ordi selon getcart*/
            cout << this->_p1.getName() << " (player), enter your card : ";
            cin >> c1;
            if (this->strategy == 1) {
                c2 = this->_p2.getcart1(b, c1);
            }
            else if (this->strategy == 2) {
                c2 = this->_p2.getcart2();
            }
            cout << this->_p2.getName() << " choose " << c2 << endl;
        }
        else {                                                                /* si ordi commence selon sa valeur max*/
            c2 = this->_p2.maximum();
            cout << this->_p2.getName() << " choose " << c2 << endl;
            cout << this->_p1.getName() << " (player), enter your card : ";
            cin >> c1;
        }
        if (c1 > c2) {
            this->_p1.replace((_p1.getindex(c1)), b);
            this->_p2.removeone(c2);
        }
        else if (c1 < c2) {
            this->_p2.replace((_p2.getindex(c2)), b);
            this->_p1.removeone(c1);
        }
        else {
            if (this->_p1.maximum() > this->_p2.maximum()) {
                this->_p1.replace((_p1.getindex(c1)), b);
                this->_p2.removeone(c2);
            }
            else if (this->_p1.maximum() < this->_p2.maximum()) {
                this->_p2.replace((_p1.getindex(c2)), b);
                this->_p1.removeone(c1);
            }
            else {
                cout << "No one wins this turn - try again." << endl;
            }
        }

    }

    cout << this->_p1;
    cout << this->_p2;
    this->winner();
    cout << "GAME OVER" << endl;
}

void Game::playerVSplayer() {
    int c1, c2;
    int b;
    cout << "PLAYER VS. PLAYER" << endl;

    cout << "Player 1, enter your name : ";
    string t;
    cin >> t;
    this->_p1.setName(t);
    cout << "Player 2, enter your name : ";
    cin >> t;
    this->_p2.setName(t);
    cout<<endl;
    for (int i = 0; i < 4; i++) {
        cout << "*****   ROUND " << i + 1 << "   *****" << endl;
        cout << "Player1: "<< this->_p1;
        cout << "Player2: " << this->_p2;

        /*this->_p1.printHand();
        this->_p2.printHand();*/
        b = rand() % 10 + 1;
        cout <<endl<<"The card to be replaced is : " << b << endl;
        if ((i % 2) == 0) {
            cout << this->_p1.getName() << " (player 1), enter your card : ";
            cin >> c1;
            cout << this->_p2.getName() << " (player 2), enter your card : ";
            cin >> c2;
        }
        else {
            cout << this->_p2.getName() << " (player 2), enter your card : ";
            cin >> c2;
            cout << this->_p1.getName() << " (player 1), enter your card : ";
            cin >> c1;
        }
        if (c1 > c2) {
            this->_p1.replace((_p1.getindex(c1)), b);
            this->_p2.removeone(c2);
        }
        else if (c1 < c2) {
            this->_p2.replace((_p2.getindex(c2)), b);
            this->_p1.removeone(c1);
        }
        else {
            if (this->_p1.maximum() > this->_p2.maximum()) {
                this->_p1.replace((_p1.getindex(c1)), b);
                this->_p2.removeone(c2);
            }
            else if (this->_p1.maximum() < this->_p2.maximum()) {
                this->_p2.replace((_p1.getindex(c2)), b);
                this->_p1.removeone(c1);
            }
            else {
                cout << "No one wins this turn - try again." << endl;
            }
        }
    }


    cout << this->_p1;
    cout << this->_p2;
    this->winner();
    cout << "GAME OVER" << endl;
}


void Game::compVScomp() {
    int c1, c2;
    int b;
    cout << "COMPUTER VS. COMPUTER" << endl;
    this->_p1.setName("COMPUTER1");
    this->_p2.setName("COMPUTER2");
    cout<<endl;
    for (int i = 0; i < 4; i++) {
        cout << "*****   ROUND " << i + 1 << "   *****" << endl;
        cout << "Computer1: "<<this->_p1;
        cout << "Computer2: "<<this->_p2;
        b = rand() % 10 + 1;
        cout << "The card to be replaced is : " << b << endl;
        sleep(1);
        if ((i % 2) == 0) {
            c1 = this->_p1.getcart2();
            sleep(1);
            cout << this->_p1.getName() << " choose " << c1 << endl;
            sleep(1);
            c2 = this->_p2.getcart1(b,c1);
            sleep(1);
            cout << this->_p2.getName() << " choose " << c2 << endl;
            sleep(1);
        }
        else {
            c2 = this->_p2.getcart2();
            cout << this->_p2.getName() << " choose " << c2 << endl;
            c1 = this->_p1.getcart1(b,c2);
            cout << this->_p1.getName() << " choose " << c1 << endl;
        }
        if (c1 > c2) {
            this->_p1.replace((_p1.getindex(c1)), b);
            this->_p2.removeone(c2);
        }
        else if (c1 < c2) {
            this->_p2.replace((_p2.getindex(c2)), b);
            this->_p1.removeone(c1);
        }
        else {
            if (this->_p1.maximum() > this->_p2.maximum()) {
                this->_p1.replace((_p1.getindex(c1)), b);
                this->_p2.removeone(c2);
            }
            else if (this->_p1.maximum() < this->_p2.maximum()) {
                this->_p2.replace((_p1.getindex(c2)), b);
                this->_p1.removeone(c1);
            }
            else {
                cout << "No one wins this turn - try again." << endl;
            }
        }
    }
    cout << this->_p1;
    cout << this->_p2;
    this->winner();
    cout << "GAME OVER" << endl;
    sleep(1000);
}

void Game::winner() {
    cout << this->_p1.getName() << " average is : " << this->_p1.average() << endl;
    cout << this->_p2.getName() << " average is : " << this->_p2.average() << endl;
    if (this->_p1.average() > this->_p2.average())
        cout << "The winner is : " << this->_p1.getName() << endl;
    else if (this->_p1.average() < this->_p2.average())
        cout << "The winner is : " << this->_p2.getName() << endl;
}
