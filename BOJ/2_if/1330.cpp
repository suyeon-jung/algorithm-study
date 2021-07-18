#include <iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    if(a > b){
        cout << ">";
    }else if(a < b){
        cout << "<";
    }else {
        cout << "==";
    }

    // 삼항연산자 활용
    cout << (a < b ? "<" : a < b ? ">" : "==");
}