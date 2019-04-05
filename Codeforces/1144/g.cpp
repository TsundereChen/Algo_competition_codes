#include <iostream>
#define MAX_N 200005

using namespace std;

int myArr[MAX_N];
int result[MAX_N];

int main(void){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> myArr[i];
        result[i] = -1;
    }
    int curIncrease = -1;
    int curDecrease = 999999;
    for(int i = 0; i < N; i++){
        if(myArr[i] > curIncrease){
            result[i] = 0;
            curIncrease = myArr[i];
        }
        else{
            if(myArr[i] >= curDecrease){
                cout << "NO" << endl;
                return 0;
            }
            else{
                result[i] = 1;
                curDecrease = myArr[i];
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < N - 1; i++){
        cout << result[i] << " ";
    }
    cout << result[N-1] << endl;
    return 0;
}
