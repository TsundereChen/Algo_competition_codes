#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 200005
using namespace std;
vector<int> myVec;
vector<int> appeared;

int Appeared[MAX_N] = { 0 };

int main(void){
    int N;
    int abort = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        myVec.push_back(tmp);
    }
    sort(myVec.begin(), myVec.end());
    for(int i = 0; i < N; i++){
        if(Appeared[myVec[i]] == 0){
            appeared.push_back(myVec[i]);
            Appeared[myVec[i]] = 1;
        }
        else{
            Appeared[myVec[i]]++;
            if(Appeared[myVec[i]] > 2){
                abort = 1;
                break;
            }
        }
    }
    if(abort){
        cout << "NO" << endl;
        return 0;
    }
    vector<int> increaseVec, decreaseVec;
    for(int i = 0; i < (int)appeared.size(); i++){
        if(Appeared[appeared[i]] == 2){
            increaseVec.push_back(appeared[i]);
            decreaseVec.push_back(appeared[i]);
        }
        else{
            increaseVec.push_back(appeared[i]);
        }
    }
    cout << "YES" << endl;
    cout << increaseVec.size() << endl;
    for(int i = 0; i < (int)increaseVec.size(); i++) cout << increaseVec[i] << " ";
    cout << endl;
    cout << decreaseVec.size() << endl;
    for(int i = decreaseVec.size() - 1; i >= 0; i--) cout << decreaseVec[i] << " ";
    cout << endl;
    return 0;
}
