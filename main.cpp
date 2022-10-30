#include "caculate.h"
#include "show.h"
#include "letDual.h"
#include <ctime>
#include <cstdlib>
int main(){
    int yourMoney=100;
    int pCard[12];
    int bCard[12];
    srand(time(NULL));
    loop:
        loop1:
        cout<<"You got "<<yourMoney<<", how much you gonna bet for?"<<endl;
        int betMoney;
        cin>>betMoney;
        if(betMoney>yourMoney){
            cout<<"Nah, you are not that rich, are u stupid or something?"<<endl;
            goto loop1;
        }
        for(int i=0;i<12;i++){
            pCard[i]=rand()%13+1;
        }
        for(int i=0;i<12;i++){
            bCard[i]=rand()%13+1;
        }
        int numP=2,numB=2;
        bool p=0,b=0;
        int countBullRep=0;
        show(numP, pCard);
        while(!p){
            string pAnswer;
            cout<<"Hit or stay?(h/s)"<<endl;
            cin>>pAnswer;
            if(pAnswer=="h" || pAnswer=="H" || pAnswer=="Hit" || pAnswer=="hit"){
                numP++;
                show(numP, pCard);
                if(numP==7){
                    cout<<"You got what you want, don't you? Just stoppp!"<<endl;
                }else if(numP==9){
                    cout<<"By caculating the chaos, I think you have brusted. Just stop, my potential is just another level, higher than any creature have existed!"<<endl;
                }else if(numP>=11){
                    cout<<"Get away! Inferior creature"<<endl;
                    return 0;
                }    
            }else if(pAnswer=="s" || pAnswer=="S" || pAnswer=="Stay" || pAnswer=="stay"){
                p=1;
            }else{
                countBullRep++;
                if(countBullRep<=3){
                    cout<<"Nah, just answer me!"<<endl;
                }else if(countBullRep>3 && countBullRep<=6){
                    cout<<"Answer, hit or stay?? JUST HIT H OR S, I DON'T HAVE TIME FOR THIS SILLY JOKE..."<<endl;
                }else if(countBullRep>6 && countBullRep<10){
                    cout<<"I am getting serious! Here is a tip: Don't mess with me!"<<endl;
                }else{
                    cout<<"Ah, fine, do whatever you want. I'm out!"<<endl;
                    return 0;
                }
            }
        }
        while(!b){
            int a=caculate(numB, bCard);
            if(a>=18 && a<=21){
                b=1;
            }else if(a<=15){
                numB++;
            }else if(numP>5 && a>16){
                b=1;
            }else if(numB==2 && a==21){
                b=1;
            }else if(numP==5 && a<=16 && numB==4){
                numB++;
            }else if(a>21){
                b=1;
            }else if(numP<5 && a<=17 && a>15 && numP>2){
                if(rand()%1){
                    numB++;
                }else{
                    b=1;
                }
            }
        }
        if(p==1 && b==1){
            int a=finalMove(numP, numB,pCard,bCard);
            if(a==0){
                yourMoney+=betMoney;
            }else if(a==1){
                yourMoney-=betMoney;
            }else{
            }
            string c;
            cout<<"You got "<<yourMoney<<endl;
            cout<<"Try again.Do you dare?(y/n)"<<endl;
            cin>>c;
            if(c=="y" || c=="Y" || c=="yes" || c=="Yes"){
                goto loop;
            }else{
                return 0;
            }
        }
    if(yourMoney<=0){
    cout<<"You have run out of money. Get out of here!"<<endl;
    return 0;
    }
}   