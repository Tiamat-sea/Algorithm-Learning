#include <iostream>
using namespace std;

bool isMatch(char a, char b) {
    if((a + 2 == b) || (a - 2 ==b) || (a + 1 == b) || (a - 1 == b)) {
        return true;
    }
    return false;
}

int main(){
    char test[6]={'{','}','[',']','(',')'};
    cout<<isMatch(test[4],test[3]);

//    for(int i = 0; i < 6; i++) {
//        printf("%d",test[i]);
//        cout<<endl;
//    }
}