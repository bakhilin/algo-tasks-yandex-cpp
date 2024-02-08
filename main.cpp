#include <iostream>

using namespace std;

int main()
{
    int n, count, max_count, first_position, last_position = 0; 
    cin >> n;
    int *din_arr = new int[n];

    for(int i = 0; i < n; i++) cin >> din_arr[i]; 

    for (int i = 0; i < n; i++){        
        ++count;
    	if (din_arr[i] == din_arr[i+1]){
        	if(din_arr[i+1] != din_arr[i+2]){
                if (count > max_count) max_count = count;
            } else {
                if (count > max_count) {
                    max_count = count + 1;
                    last_position = i + 2;
                    first_position = last_position - max_count+1;
                }
                count = 0;
            }
        } else{
            if (count > max_count) {
                max_count = count;
                last_position = i + 1;
                first_position = last_position - max_count + 1;
            }
        }
    }
    
	cout << first_position << " " << last_position;
    return 0;
}

