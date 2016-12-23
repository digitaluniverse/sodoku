#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string input;
    system("sh start.sh");
    cout << ": " ;
    cin >> input;
    while (true){
        if (input=="quit"){
            system("sh stop.sh");
            break;
        }
        else{}
    }
    
    
    return 0;
}