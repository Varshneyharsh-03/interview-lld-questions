#include <iostream>
#include <vector>
using namespace std;

void printOptions(){
    cout<<"1. Rock"<<endl;
    cout<<"2. Paper"<<endl;
    cout<<"3. Sissors"<<endl;
}

int check(int p1,int p2){
    if(p1==p2) return 0;
    if((p1==0 and p2==2) or (p1==1 and p2==0) or (p1==2 and p2==1)) return 1;
    return -1;
}
int main() {
        int player1 = 1;
        int player2 = 2;

        vector<string> options;
        options.push_back("rock");
        options.push_back("papper");
        options.push_back("sissors");

        int rounds;
        cout<<"Enter the number of rounds in the game :";
        cin>>rounds;
        int sum = 0;
        for(int i=0;i<rounds;i++){
            cout<<"Player1 choose one among them"<<endl;
            printOptions();
            int p1;
            cout<<"Player1 enter your choice :";
            cin>>p1;

            cout<<"Player2 choose one among them"<<endl;
            printOptions();
            int p2;
            cout<<"Player2 enter your choice :";
            cin>>p2;

            sum += check(p1-1,p2-1);

        }

        if(sum>0){
            cout<<"Player1 won by "<<sum<<" points"<<endl;
        }
        else if (sum<0){
            cout<<"Player2 won by "<<(sum*-1)<<" points"<<endl;
        }
        else{
            cout<<"Its a draw"<<endl;
        }
        return 0;
}
