#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 105

int p[MAX_N];
int s[MAX_N];
int target[MAX_N];
int main(void){
    int n, m, k;
    cin >> n >> m >> k;
    memset(p, 0, sizeof(p));
    memset(s, 0, sizeof(s));
    memset(target, 0, sizeof(target));
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < k; i++) cin >> target[i];
    int result = 0;
    for(int i = 0; i < k; i++){
        int flag = 0;
        int current_value  = p[target[i] - 1];
        int current_school = s[target[i] - 1];
        for(int j = 0; j < n; j++){
            if(s[j] == current_school){
                if(p[j] > current_value){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1) result++;
    }
    cout << result << "\n";
    return 0;
}
