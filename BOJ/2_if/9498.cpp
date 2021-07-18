#include <iostream>
using namespace std;

int main(){
    int score;
    cin >> score;
    if(score < 0 || score > 100){
        return 0;
    }

    if(score >89 ){
        cout << "A";
    }else if(score > 79){
        cout << "B";
    }else if(score > 69){
        cout << "C";
    }else if(score > 59){
        cout << "D";
    }else{
        cout << "F";
    }
}