#ifndef LEETCODE_VECTOR_OUTPUT_H
#define LEETCODE_VECTOR_OUTPUT_H

#endif //LEETCODE_VECTOR_OUTPUT_H

#include<bits/stdc++.h>
using namespace std;

namespace py_pr{
    template<typename T>
    inline ostream& out_put(ostream& o,const T & x){
        return o<<x;
    }
    inline ostream& out_put(ostream& o,const string& x){
        return o<<"\""<<x<<"\"";
    }
    inline ostream& out_put(ostream& o,const char* & x){
        return o<<"\""<<x<<"\"";
    }
    inline ostream& out_put(ostream& o,const char & x){
        return o<<"\""<<x<<"\"";
    }
    template<typename T1,typename T2>
    inline ostream& out_put(ostream& o,const pair<T1,T2> & x){
        out_put(o,x.first);
        o<<": ";
        out_put(o,x.second);
        return o;
    }

}

template<typename T>
ostream& operator<<(ostream &o,vector<T> &x){
    o<<"[";
    for(auto i=x.begin();i<x.end();++i){
        //可以直接for(auto i:x)，但是我不知道怎么特判第一个来控制","
        if(i!=x.begin()) o<<", ";
        py_pr::out_put(o,*i);
    }
    o<<"]"<<endl;
    return o;
}

template<typename T1,typename T2>
ostream& operator<<(ostream &o,map<T1,T2> &x){
    o<<"{";
    //类似python的格式
    for(auto i=x.begin();i!=x.end();++i){
        if(i!=x.begin()) o<<", ";
        py_pr::out_put(o,*i);
    }
    o<<"}"<<endl;
    return o;
}

void showTwoVector(vector<vector<int>> x) {
    int row = x.size();
    int col = x[1].size();
    cout << "[";
    for (int i = 0; i < row; i++) {
        cout << "[";
        for (int j = 0; j < col; j++) {
            if (j + 1 == col) {
                cout << x[i][j];
            }
            else{
                cout << x[i][j] << ",";
            }
        }
        if (i + 1 == row) {
            cout << "]";
        }
        else {
            cout << "],";
        }
    }
    cout << "]";
}