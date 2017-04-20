#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "conwaysgame.h"

using namespace std;
typedef unsigned char byte;


//Player of Games

//Observer --Closeness Score

//GameString
int bitWiseEqual(byte A, byte B)
{
    int retCounter= 0;
    for (int i=0; i<8; i++)
    {
        byte testA=(A &(1<<i));
        byte testB=(B&(1<<i));
        if(testA == testB) retCounter++;
    }
    return retCounter;
}
//Replay
class game
{
public:
    game(int startSize)
    {
        data.resize(startSize);
    }

    bool isEmpty()
    {
        for(int i=0; i < data.size(); i++)
        {
            if (data[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

    //Compares for equality bitwise
    float compare( game* other)
    {
        float totalsize=data.size()*8;
        float equalBits =0 ;
        float unequalBits =0;

        for(int i=0; i < data.size(); i++)
        {
        int bitsEqual= bitWiseEqual(other->data.at(i),data.at(i));
        equalBits+=bitsEqual;
        unequalBits+=(8-bitsEqual);
        }
    return equalBits/totalsize;
    }

    std::vector<byte> data;
};


class libraryGame
{
    libraryGame(game* startOfGame)
    {
        this->snapshotsPowTwoTo128.push_back(*startOfGame);
    }

public:
    int gameID;
    std::vector<game> snapshotsPowTwoTo128;
};

class encodedData
{
public:
    int gameID;
    int cycles;
    byte Operation;
    byte Negated;
};

class encodedGames
{
public:
    std::vector<encodedData> toString;
};

void itterateOverGame()
{

}

void playerOfGames(game* dataToEncode, std::vector<libraryGame>* playedGames)
{

    game localCopy =*dataToEncode;
    //while the gameboard is not empty
    while(localCopy.isEmpty()== false)
    {
    float bestOption=1.0;
    encodedData* bestGame;
        //go brute force over the library, apply and/or/xor with negation
    for (auto game : *playedGames ){

    }

    }


}

void initLibrary(std::vector<libraryGame>* playedGames){

}


void randomizeData( std::vector<byte>* testData, int range)
{
    for (auto  it: *testData)
    {
        it= rand() %range;
    }
}

void displayData( std::vector<byte>* testData, int line)
{
    int index = 0;
    while (index < testData*.size()){


    }
    for (auto  it: *testData)
    {
        it= rand() %range;
    }
}


void intiatedGameLibrary(std::vector<libraryGame>* pLibraryGame)
{
    for (int i=1; i<128; i++)
    {


    }
}

int main()
{
    std::vector<libraryGame> playedGames;
    game* testData= new game(256);
    initLibrary(&playedGames);
    randomizeData(&(*testData).data,256);

    //take the testdata

    //encode the testdata

    //restore the data from the encoded games



    return 0;
}
