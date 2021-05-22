//Noam Sabban 329897391
//Sarah Bitton 336443338


#include <iostream>
#include "NumSet.h"
#include "Game.h"

using namespace std;

int main() {
    srand( (int) time(0));

    cout<< "Operators check"<<endl;
    NumSet N1;
    cout<<"N1: "<<N1;
    int  verif[5] = {1,2,3};
    N1 = verif;
    cout <<"N1= {1,2,3}: "<<N1;

    N1++;
    cout<<"N1++: "<<N1;
    N1--;

    cout<<"N1--: "<<N1;

    NumSet N2;
    cout<<"N2"<<N2;
    N2=N1;
    cout<<"N2=N1: "<<N2;

    N2+=1;
    N2+=5;
    cout<<"N2+=1 +=5: "<<N2;

    cout<<endl;
//START GAME
    Game G1;
    G1.gameMenu();


    return 0;
}
