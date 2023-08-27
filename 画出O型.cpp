#include <iostream>
using namespace std;

int main() {
    int n = 3;
    // cin >> n;

    int size = 5*n;
    int dot_num = n;
    int revert_dot_num = 1;
    bool revert = false;
    for(int i = 0; i< size; i++){
        for(int j = 0; j < size; j++){
            if(i < n){
                if(j < dot_num || j > 5*n - dot_num - 1)
                    cout << ".";
                else
                    cout << "*";
            }
            
            if(i >= n && i < 2*n){
                if(j < n || j > 4*n - 1)
                    cout << "*";
                else
                    cout << "o";
            }

            if(i >= 2*n && i < 3*n){
                if(j < n || j > 4*n - 1)
                    cout << "*";
                else if(j < 2*n || j >= 3*n )
                    cout << "o";
                else
                    cout << ".";
            }

            if(i >= 3*n && i < 4*n){
                if(j < n || j > 4*n - 1)
                    cout << "*";
                else
                    cout << "o";
            }
            if(i >= 4*n){
                revert = true;
                if(j < revert_dot_num || j > 5*n - revert_dot_num - 1)
                    cout << ".";
                else
                    cout << "*";
            }
            
        }    

        if(dot_num > 0 && !revert)
            dot_num--;
        
        if(revert)
            revert_dot_num++;

        cout << endl;
    }
    return 0;
}