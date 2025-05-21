#include<iostream>
#include<conio.h>
using namespace std;
class checkprime{
    public :
    int n;
    bool isprime(){
        if(n<=1){
            return false;
        }
            for (int i=2;i<n;i++){
                if (n%i==0){
                    return false;
                }
            }
        return true;
    }
};
int main(){
    i:
    cout<<"Enter a no."<<endl;
    checkprime obj;
    cin>>obj.n;
    if (obj.isprime()){
        cout<<"\nPrime no.";
    }
    else{
        cout<<"\nNot prime.";
    }
    char Continue;
    cout<<"\nWant to continue : (y/n)";
    cin>>Continue;
    if(Continue=='y'){
        goto i;
    }
    else if (Continue=='n'){
        cout<<"Good bye!";
    }
    
    return 0;
}