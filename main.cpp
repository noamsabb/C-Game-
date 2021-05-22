#include "Game.h"

int main() {


    cout<< "Operators check"<<endl;
    NumSet N1;
    cout<<"N1: "<<N1;
    int  verif[5] = {1,2,3};
    N1 = verif;
    cout <<"N1= {1,2,3}: "<<N1;

    ++N1;
    cout<<"N1++: "<<N1;
    --N1;
    --N1;
    --N1;

    cout<<"N1-- -- -- : "<<N1;

    NumSet N2;
    cout<<"N2: "<<N2;
    N2=N1;
    cout<<"N2=N1: "<<N2;

    N2+=1;
    N2+=5;
    cout<<"N2+=1 +=5: "<<N2;

cout<<endl;

    Game myGame(1);
    myGame.menu();
    return 0;
}
