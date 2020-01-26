#include <iostream>
#include <string>
using namespace std;

string s;
int fuc(int x, int y){
    
    for(int i=1; i<s.size(); i++){
        x --;
        y ++;
        if(x<0 || y>=s.size()) return i-1;
        if(s[x] != s[y]) return i-1;
    }
    return 0;
}
int solution(string S)
{
    s = S;
    int anw=0;
    
    int num;
    for(int i=0; i<s.size(); i++){
        num = fuc(i,i); 
        num = num*2+1;
        if(anw < num) anw = num;
        if(i!=0 && s[i-1]==s[i]){
            num = fuc(i-1, i);
            num = num*2+2;
            if(anw < num) anw = num;
        }
    }
    return anw;
}
