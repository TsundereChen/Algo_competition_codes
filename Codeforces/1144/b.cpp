#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Arr;

int main(void){
    int N;
    cin >> N;
    int counter = 0;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        Arr.push_back(tmp);
        if(tmp % 2) counter++;
        else counter--;
    }
    if(counter == 0 || counter == 1 || counter == -1) cout << "0" << endl;
    else{
        int result = 0;
        sort(Arr.begin(), Arr.end());
        if(counter > 0){
            counter--;
            for(int i = 0; i < (int)Arr.size(); i++){
                if(counter == 0) break;
                if(Arr[i] % 2){
                    result += Arr[i];
                    counter--;
                }
            }
        }
        else{
            counter++;
            for(int i = 0; i < (int)Arr.size(); i++){
                if(counter == 0) break;
                if(Arr[i] % 2 == 0){
                    result += Arr[i];
                    counter++;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
