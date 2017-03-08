#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


void randomizeVector( std::vector<bool>* myVector, int sizeToGo)
{

    for (int i=0; i < sizeToGo; i++)
    {
        myVector->push_back( std::rand()<  (RAND_MAX/2));
    }
}

void displayVector( std::vector<bool>* myVector, int sizeToGo)
{
    int counter= 0;
    for (myVector->const_iterator i = myVector->begin(); i != myVector->end(); ++i)
    {
        std::cout << *i ;
        counter++;
        if (counter > sizeToGo)
        {
            counter=0;
            std::cout << endl ;
        }
    }

}

//Player of Games

//Observer --Closeness Score

//GameString

//Replay

int main()
{

    std::vector<bool> TestArray;
    randomizeVector(&TestArray,64);
    displayVector(&TestArray,16)

    cout << "Hello world!" << endl;
    return 0;
}
