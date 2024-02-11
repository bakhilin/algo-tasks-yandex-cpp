#include <iostream>
#include <cstring>
#include <stack>



int main(int argc, char const *argv[])
{
    bool flag = true;
    int trapCount, animalsCount;
    std::string message;
    std::cin >> message;

	if(message.length()==1) {flag==false;std::cout << "Impossible";return 0;}


    if (message.length()==2)
    {
        if ((islower(message[0]) && islower(message[1])) ||(isupper(message[0]) && isupper(message[1])))
        {
            std::cout << "Impossible"; 
            return 0;
        }
    }

    for(size_t i = 0; i < message.length(); i++) {
        if((isupper(message[i]) && islower(message[i+1])) || (islower(message[i]) && isupper)) {

        }
    }
    

     for (size_t i = 0; i < message.length()/2; i++){ 
        if(isalpha(message[message.length()-i-1])) {
            	if(toupper(message[i]) != toupper(message[message.length()-i-1])){                                               
                	flag=false;
            	}
        } else {
            flag = false;
        }
    }
    
    if (flag){
        std::cout << "Possible\n";
        for (size_t i = (message.length()/2); i > 0; i--) std::cout << i << " ";
    } else std::cout << "Impossible";
    
    return 0;
}
