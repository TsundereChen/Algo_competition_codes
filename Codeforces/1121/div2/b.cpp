#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 1005
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    vector<int> combinations;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            combinations.push_back(v[i] + v[j]);
        }
    }
    sort(combinations.begin(), combinations.end());
    int curr_value;
    int counter = 0;
    int result = 0;
    int flag = 0;
    for(unsigned long i = 0; i < (combinations.size() - 1); i++){
        if(flag == 0){
            if(combinations[i] == combinations[i+1]){
                flag = 1;
                curr_value = combinations[i];
                counter = 1;
            }
        }
        else{
            if(curr_value == combinations[i+1]){
                counter++;
            }
            else{
                flag = 0;
                if(counter > result) result = counter;
            }
        }
    }
    cout << (result+1) << "\n";
    return 0;
}
