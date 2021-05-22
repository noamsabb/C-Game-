//
// Created by Noam Sabban on 24/12/2019.
//

#include <cstdlib>
#include <iostream>
#include "NumSet.h"




using namespace std;

//Constructor
NumSet::NumSet()
{

    //this->_NumList = new int [5];
    for (int i = 0; i <5 ; ++i)
    {
        this->_NumList[i] = (rand() %10 +1);
    }
    sort(this->_NumList, this->_NumList+5 );
    this->_max = this->_NumList[4];
    this->_min = this->_NumList[0];
    this->_average = this->average();
    this->_playerName = "None";

}

//Copy Constructor
NumSet::NumSet(const NumSet &other)
{
    //this->_NumList = new int [5];
    for (int i = 0; i <5 ; ++i)
    {
        this->_NumList[i]= other._NumList[i];
    }
    this->_max = this->_NumList[4];
    this->_min = this->_NumList[0];
    this->_average = this->average();
}

//Destructor
/*NumSet::~NumSet()
{
delete [] this->_NumList;
}*/


int NumSet::max()
{
    return this->_max;
}

int NumSet::min()
{
    this->_min = this->_NumList[freeCells()];
    return this->_min;
}


float NumSet::average()
{
    float average =0;
    float sum = 0.0;
    int freeCells = this->freeCells();
    for (int i = freeCells; i <5 ; ++i)
    {
        sum += this->_NumList[i];
    }
    average = sum/5;

    return average;
}


int NumSet::freeCells()
{
    int compt = 0;
    for (int i = 0; i <5 ; ++i)
    {
        if (this->_NumList[i] == 0)
            compt++;
    }
    return compt;
}


void NumSet::replace(int index, int num)
{
    this->_NumList[index] = num;
    this->update();

}


void NumSet::update()
{
    sort(this->_NumList, this->_NumList+5 );
    this->_max = this->_NumList[4];
    this->_min = this->_NumList[0];

}


void NumSet::insert(int num)
{
    if (this->freeCells() != 0)
        for (int i = 0; i <5 ; ++i)
        {
            if (this->_NumList[i] == 0)
            {
                this->_NumList[i] = num;
                this->update();
                return;
            }
        }
}


int NumSet::biggerThan(int num)
{
    int compt =0;

    for (int i = 0; i < 5 ; ++i)
    {
        if (this->_NumList[i] >= num)
            compt++;
    }

    return compt;
}


int NumSet::smallerThan(int num)
{
    int compt =0;

    for (int i = 0; i < 5 ; ++i)
    {
        if (this->_NumList[i] < num)
            compt++;
    }

    return compt;
}


void NumSet::Del(int num)
{
    this->_NumList[num] = 0;
    this->update();
}


int NumSet::find(int num)
{
    for (int i = 0; i <5 ; ++i)
    {
        if(this->_NumList[i] == num)
            return i;
    }
    return -1;
}

void NumSet::reduce(int index)
{
    this->_NumList[index]--;
    this->update();
}

void NumSet::setName(string playerName)
{
    this->_playerName = playerName;
}

string NumSet::getName() const
{
    return this->_playerName;
}

void NumSet::refreshList()
{
    for (int i = 0; i <5 ; ++i)
    {
        this->_NumList[i] = (rand() %10 +1);
    }
    this->update();
}

