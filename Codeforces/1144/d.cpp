#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<long long int> myVec;
vector<int> vecT, vecI, vecJ;
int solCounter = 0;

int main(void){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        long long int tmp;
        cin >> tmp;
        myVec.push_back(tmp);
    }
    for(int i = 0; i < (int) myVec.size() - 1; i++){
        long long int minusAbs = abs(myVec[i] - myVec[i+1]);
        if(minusAbs == 0) continue;
        else if(myVec[i] - minusAbs == myVec[i+1]){
            // Type 2, i = i, j = i + 1
            solCounter++;
            vecT.push_back(2);
            vecI.push_back(i+1);
            vecJ.push_back(i + 1 + 1);
        }
        else if(myVec[i] + minusAbs == myVec[i+1]){
            // Type 1, i = i, j = i + 1
            solCounter++;
            vecT.push_back(1);
            vecI.push_back(i + 1);
            vecJ.push_back(i + 1 + 1);
        }
        else if(myVec[i+1] - minusAbs == myVec[i]){
            // Type 2, i = i + 1, j = i
            solCounter++;
            vecT.push_back(2);
            vecI.push_back(i + 1 + 1);
            vecJ.push_back(i + 1 - 1);
        }
        else if(myVec[i+1] + minusAbs == myVec[i]){
            // Type 1, i = i + 1, j = i
            solCounter++;
            vecT.push_back(1);
            vecI.push_back(i + 1 + 1);
            vecJ.push_back(i + 1 - 1);
        }
        else{
            continue;
        }
    }
    cout << solCounter << endl;
    for(int i = 0; i < solCounter; i++) cout << vecT[i] << " " << vecI[i] << " " << vecJ[i] << endl;
    return 0;
}
