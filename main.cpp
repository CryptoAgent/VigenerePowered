#include <iostream>
#include <string>
using namespace std;
#include "VP.h"

string Encrypt(string mess,string key);
string Decrypt(string mess,string key);

int main(){
cout<<"Please enter message\r\n>";
string mess=GetStr();
int len = GetLen(mess);
cout<<"Please enter number of keys\r\n";
int num;
cin>>num;
cout<<"Now enter keys :\r\n";
string keys[num];
for(int i = 0;i<num;i++){
    cin>>keys[i];
}
string encrypted;
for(int i = 0;i<num;i++){
    encrypted = Encrypt(mess,keys[i]);
    mess = encrypted;
}
cout<<"\r\nYour encrypted message is : ";
cout<<encrypted<<endl;
cout<<"Please enter message\r\n>";
mess=GetStr();
len = GetLen(mess);
cout<<"Please enter number of keys\r\n";
num;
cin>>num;
cout<<"Now enter keys :\r\n";
keys[num];
for(int i = 0;i<num;i++){
    cin>>keys[i];
}
string decrypted;
for(int i = 0;i<num;i++){
    decrypted = Decrypt(mess,keys[i]);
    mess = decrypted;
}
cout<<decrypted;
return 0;
}
string Encrypt(string mess,string key){
int len = GetLen(mess);
string enc;
int ind = 0;
while(GetLen(key)<len){
    key+=key[ind];
    ind++;
}
for(int i = 0;i<len;i++){
    char ch1 = mess[i];
    char ch2 = key[i];
    ch1-=97;
    ch2-=97;
    ch1+=ch2;
    ch1%=26;
    ch1+=97;
    enc+=ch1;
}
return enc;
}
string Decrypt(string mess,string key){
int len = GetLen(mess);
int ind = 0;
while(GetLen(key)<len){
    key+=key[ind];
    ind++;
}
string decr;
for(int i = 0;i<len;i++){
    char ch1 = mess[i];
    char ch2 = key[i];
    ch1-=97;
    ch2-=97;
    ch1-=ch2;
    while(ch1<0){
        ch1+=26;
    }
    ch1+=97;
    decr+=ch1;
}
return decr;
}
