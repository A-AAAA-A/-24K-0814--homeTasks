#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;




int randomNumberInRange = 0 + (std::rand() % (100 + 1));



int Player1 =1;


void Guess(){
    
    int guess;
    
    if (Player1==1){
            cout<<"Player ones turn"<<endl;
    } else{
        cout<<"Player twos turn"<<endl;
    }
    cout<<"Guess"<<endl;
    cin>>guess;

    if (guess==randomNumberInRange){
        cout<<"Correct Guess!!"<<endl;
        if (Player1==1){
            cout<<"Player 1 wins";
        } else{
            cout<<"Player 2 wins"<<endl;
        };
        return;
    };
    if (guess>randomNumberInRange){
        cout<<"Too high"<<endl;
        if(Player1==1){
            Player1=0;
            cout<<"Player twos turn"<<endl;
        } else{
            Player1=1;
            cout<<"Player ones turn"<<endl;
        }
        Guess();
    }
    if (guess<randomNumberInRange){
        cout<<"Too low"<<endl;
        if(Player1==1){
            Player1=0;
            cout<<"Player twos turn"<<endl;
        } else{
            Player1=1;
            cout<<"Player ones turn"<<endl;
        }
        Guess();
    }



}


int main() {

    Guess();


    return 0;
}
