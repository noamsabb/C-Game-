//
// Created by Noam Sabban on 24/12/2019.
//

#ifndef UNTITLED_NUMSET_H
#define UNTITLED_NUMSET_H
#define SIZE 5

#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<ctime>

#define LISTSIZE 5

using namespace std;
class NumSet {

private:
    int _NumList[LISTSIZE];
    int _max;
    int _min;
    float _average;
    string _playerName;

public:
    NumSet();
    //~NumSet();
    NumSet(const NumSet& other);

    int min();
    int max();
    float average();

    void insert(int num);
    int freeCells();
    void replace(int index, int num);
    int biggerThan(int num);
    int smallerThan(int num);
    void Del(int num);

    void refreshList();
    void setName(string playerName);
    string getName()const;
    void update();
    int find(int num);
    void reduce(int index);



//OPERATORS


    NumSet& operator+= (int num) {
        for (int i = 0; i <5 ; ++i)
        {
            if (this->_NumList[i] == 0)
            {
                this->_NumList[i] = num;
                this->update();
                break;
            }
        }
        return (*this);
    }


    NumSet& operator+=(NumSet& other)
    {
        for (int i = 0; i <5 ; ++i)
        {
            this->_NumList[i] += other._NumList[i];
            if (this->_NumList[i] >10)
                this->_NumList[i] = 10;
        }
        this->update();
        return(*this);
    }


    NumSet& operator++(int)
    {
        for (int i = 0; i <5 ; ++i)
        {
            if(this->_NumList[i]<10)
                this->_NumList[i]++;
        }
        this->update();
        return (*this);
    }


    NumSet& operator--(int)
    {
        for (int i = 0; i <5 ; ++i)
        {
            if(this->_NumList[i]>0)
                this->_NumList[i]--;
        }
        this->update();
        return (*this);
    }


    bool operator==(NumSet& other)
    {
        for (int i = 0; i <5 ; ++i)
        {
            if (this->_NumList[i] != other._NumList[i])
                return false;
        }
        return true;
    }


    NumSet& operator= (const int list[SIZE])
    {
        for (int i = 0; i < 5 ; ++i)
        {
            this->_NumList[i] = list[i];
            if (this->_NumList[i] >10)
                this->_NumList[i]=10;
            if (this->_NumList[i]<0)
                this->_NumList[i] =0;
        }
        this->update();
        return (*this);
    }


    NumSet& operator= (NumSet& other)
    {
        for (int i = 0; i <5 ; ++i)
        {
            this->_NumList[i]= other._NumList[i];
        }
        this->update();
        return (*this);
    }

    friend ostream& operator<<(ostream& out, const NumSet& n) {
        for (int i = 0; i < 4; i++) {
            if (n._NumList[i] != 0) {
                out << n._NumList[i] << ", ";
            }
        }
        out << n._NumList[4]<< endl;

        return out;
    }

};


#endif //UNTITLED_NUMSET_H
