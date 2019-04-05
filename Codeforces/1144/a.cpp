#include <iostream>
#include <string>
using namespace std;

bool Arr[27];

int main(void){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string inputData;
        int flag = 1;
        cin >> inputData;
        for(int i = 0; i < 27; i++) Arr[i] = false;
        for(int i = 0; i < (int)inputData.length(); i++){
            if(Arr[inputData[i] - 0x60] == false){ Arr[inputData[i] - 0x60] = true;}
            else{
                flag = 0;
                break;
            }
        }
        int continuousCounter = 0;
        for(int i = 1; i < 27; i++){
            if(Arr[i] == true){
                continuousCounter++;
            }
            else{
                if(continuousCounter == (int) inputData.length()) break;
                else{
                    if(continuousCounter != 0){
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
