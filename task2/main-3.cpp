#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

void printSolution(int * arr, int len){
    for(size_t i = 0 ; i < len; ++i) cout << arr[i] << " ";
}

void deleteZooDetails(stack<int> * animals, stack<int> * trapAnimals, stack<int> * notFound){
   animals->pop();
   trapAnimals->pop();
   notFound->pop();
}

int main(int argc, char const *argv[])
{   
    int trapIndex = 0;
    int animalIndex = 0;
    string message;
    stack<int> trapAnimals;
    stack<int> animals;
    stack<int> notFound;
    cin >> message;
    int length = message.length();    
    int length_arr = length / 2;
    int successKeys[length_arr];

    for(size_t i = 0; i < length; ++i){
        if (!islower(message[i])){ 
            trapAnimals.push(trapIndex);
            trapIndex++;
        } else { 
            animalIndex++;
            animals.push(animalIndex);
        }

        if (notFound.empty()||notFound.top()==message[i])notFound.push(message[i]);
        else{ 
            if (toupper(notFound.top())==toupper(message[i]) )
            {
                successKeys[trapAnimals.top()] = animals.top();
                deleteZooDetails(&animals, &trapAnimals, &notFound);
            } else {
            	notFound.push(message[i]);
            }
        }
    }

    if (notFound.empty())
    {
        cout<< "Possible" << endl ;
        printSolution(successKeys, length_arr); 
        return 0;
    } 

    cout << "Impossible";

    return 0;
}


