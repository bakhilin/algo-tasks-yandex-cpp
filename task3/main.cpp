#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cctype>
#include <algorithm>
using namespace std;

// create maybe method which help us to get element in stack

/*
    когда у нас строчка, где мы присваиваем значение какой-то переменной, мы должны в один стек сохранять переменную,
     а в другой стек сохранять самое значение этой переменной.  Когда у нас строчка, ввида a=b, мы используем наш метод, 
     где ищем в стеке переменную b и её значение. Импользую динамический массив мы сохраняем туда данные которые удалили из стека пока искали нужный нам элемент.
     Если элемент не найден, то возраващаем 0. И когда мы выводим значение переменной, мы также добавляем ее в стек.
*/
void printDataIntOfStack(std::stack<int> numbers) {
    cout << "start-----------" << endl;
    while (!numbers.empty())
    {
        cout << numbers.top() << endl;
        numbers.pop();
    }
    cout << "end-----------" << endl;
}

void printDataStrOfStack(std::stack<std::string> vars) {
    cout << "start-----------" << endl;
    while (!vars.empty())
    {
        cout << vars.top() << endl;
        vars.pop();
    }
    cout << "end-----------" << endl;
}

/*

можно создать промежуточный стек, для хранения данных в скобочках {} если переменная вне скобок не задана, 
возвращаем 0

*/


int getResult(std::stack<int> numbers, std::stack<std::string> vars, string needVar)
{
    int valueOfVar = 0;
    int firstValInStack = 0;
    int *arrValues = new int[numbers.size()];
    string *arrVars = new string[vars.size()];
    
    while(!numbers.empty() && !vars.empty()) {
        int value = numbers.top();
        numbers.pop();

        std::string var = vars.top();
        vars.pop();

        if (var == needVar &&  firstValInStack != 1)
        {
            /* code */
            firstValInStack = 1;
            valueOfVar = value;
        }
        
    }

    // for(size_t i=0; i < numbers.size(); i++) {
    //     arrValues[i] = numbers.top();
    //     numbers.pop();
        
    //     arrVars[i] = vars.top();
    //     vars.pop();


    //     cout << arrVars[i] << " AND " << needVar << endl;

    //     if (arrVars[i] == needVar && firstValInStack != 1)
    //     {
    //         firstValInStack = 1;
    //         valueOfVar = arrValues[i];
    //     }
    // }

    return valueOfVar;
}




int main(int argc, char const *argv[])
{
    string line;
    int count = 0; // считает кол-во переменных, которые изменили в одном блоке
    std::stack<int> tempStack;
    std::stack<int> stackNumbers;
    std::stack<std::string> stackVars;
    std::stack<std::string> needToPrintVars;
    std::stack<string> intermediateStackOfVar; // для промежуточного хранения значений переменных
    std::stack<int> intermediateStackOfNumbers;
    std::ifstream in("input.txt"); // read this file
    
    int keyChecker=0;

    int count_k = 0;
    int line_counter = 0;
    int tempKey = 0;
    if (in.is_open())
    {
        while (getline(in, line))
        {
            line_counter +=1;
            size_t k = 0;
            int t = 0;
            size_t ravno = 0;
            string var1;
            string var2;
            string key;
            int znak = 0;
            for (size_t i = 0; i < line.length(); i++)
            {
                if (line[i] == '{')
                {
                               
                        tempStack.push(count);
                        tempKey = keyChecker;
                        keyChecker += 1;
                        t = 2;
                        
                        count = 0;
                        
                        
                        
                } 
                
                
                if (keyChecker==0)
                {
                        while (!intermediateStackOfNumbers.empty() && !intermediateStackOfVar.empty())
                        {
                            intermediateStackOfNumbers.pop();
                            intermediateStackOfVar.pop();
                        }
                }
               
               
               
                if (line[i] == '=')
                {
                        k = 1;
                        ravno = i;
                } 
                if (k==1)
                {
                        if (line[i] == '-')
                        {
                            znak = 1;
                            i = i+1;
                        }
                        
                        if (isdigit(line[i]))
                        {
                            if (isdigit(line[line.length()-1]))
                            {
                                /* code */
                                 t = 1; // даёт нам понять, что после равно не стоит переменная
                                if(line[i] != '{' && line[i] != '}'){
                                    key += line[i];                       
                                }
                            }
                            
                           
                        } else {
                            if(line[i] != '=' && line[i] != ' ' && line[i] != '{' && line[i] != '}') {
                                var2 += line[i];
                            }
                        }                    
                } 

                if(line[i] == '}') {  
                    int j = 0;
                    
                    tempStack.push(count);
                    keyChecker -= 1;
                    if (tempKey != keyChecker)
                    {
                        int j_1 = tempStack.top();
                        tempStack.pop();
                        int j_2 = tempStack.top();
                        tempStack.pop();
                        j = j_1 +j_2;
                    } else {
                        j = tempStack.top();
                        tempStack.pop();
                    }
                    
                    count = 0;

                    
                    // cout << "key checker:" << keyChecker << endl;
                    t=2;
                    
                    // test part BEGIN
               /*
                    int j_1 = tempStack.top();
                    tempStack.pop();
                    int j_2 = tempStack.top();
                    tempStack.pop();
                    int j = j_1 +j_2;
                */
                    // test part END
                    while (j != 0)
                    {
                        intermediateStackOfNumbers.pop();
                        intermediateStackOfVar.pop();
                        j -=1;   
                    }
                    
                }
                
            }

                if (t==0)
                { 
                    count_k +=1;
                    int res = 0;
                    for (size_t i = 0; i < ravno; i++)
                    {
                        if (line[i] != ' ')
                        {
                            var1 += line[i];
                        }
                    }
                    
                    
                    if (keyChecker!=0)
                    {
                        
                        res = getResult(intermediateStackOfNumbers, intermediateStackOfVar, var2); 
                        
                        if (res==0)
                        {
                            res = getResult(stackNumbers, stackVars, var2);
                        }
                    } else {
                        //cout << "KEY CHECKER 0" << endl;
                        res = getResult(stackNumbers, stackVars, var2);
                    }

                    
                    
                    if (keyChecker!=0)
                    {
                        intermediateStackOfNumbers.push(res);
                        intermediateStackOfVar.push(var1);
                        count +=1;
                    } else {
                        stackNumbers.push(res);
                        stackVars.push(var1);
                    }
                
               
                   
                     cout << res << "\n";                     
                }
            
                if (t == 1)
                {
                    for (size_t i = 0; i < ravno; i++)
                    {
                        if (line[i] != ' ')
                        {
                            var2 += line[i];
                        }
                    }

                    if (znak == 1)
                    {
                        if (keyChecker!=0)
                        {
                            intermediateStackOfNumbers.push(std::stoi(key) * (-1));
                            count +=1;
                        } else {
                            stackNumbers.push(std::stoi(key) * (-1));
                        }
                    } else {
                        if (keyChecker!=0)
                        {
                            intermediateStackOfNumbers.push(std::stoi(key));
                            count +=1;
                        } else {
                            stackNumbers.push(std::stoi(key));
                        }
                    }

                    if (keyChecker!=0)
                    {
                        intermediateStackOfVar.push(var2);
                    } else {
                        stackVars.push(var2);
                    }
                } 
            }
        }
        
        in.close(); // close this file

        //printDataIntOfStack(stackNumbers);
        //printDataStrOfStack(stackVars);

        return 0;
    }


