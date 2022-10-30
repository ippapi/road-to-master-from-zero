using namespace std;
int finalMove(int x, int y, int *arr1, int *arr2){
    int a=0,b=0,q;
    int c=caculate(x, arr1),d=caculate(y, arr2);
    show(x, arr1);
    show(y, arr2);
    if(x=2 && c==21 && (arr1[0]>10 || arr1[1]>10)){
        a=0;
    }else if(x=2 && c==21){
        a=1;
    }else if(x>=5 && c<=21){
        a=3;
    }else if(x<5 && c<=21){
        a=4;
    }else{
        a=5;
    }
    if(y=2 && d==21 && (arr2[0]>10 || arr2[1]>10)){
        b=0;
    }else if(y=2 && d==21){
        b=1;
    }else if(y>=5 && d<=21){
        b=3;
    }else if(y<5 && d<=21){
        b=4;
    }else{
        b=5;
    }
    if(a<b){
        cout<<"agh, you win..."<<endl;
        cout<<"Take it!"<<endl;
        q=0;
    }else if(a==b && a<4){
        cout<<"DRAW"<<endl;
        cout<<"Take your money back!"<<endl;
        q=2;
    }else if(a==b && a==5){
        cout<<"DRAW"<<endl;
        cout<<"You got your money. Let's duel again!"<<endl;
        q=2;
    }else if(a==b && a==4){
        if(d==c){
            cout<<"DRAW"<<endl;
            cout<<"Don't be a cunt, 1/2 bet is mine!"<<endl;
            q=2;
        }else if(c>d){
            cout<<"You win, for now!"<<endl;
            cout<<"Here is your money!"<<endl;
            q=0;
        }else{
            cout<<"Nah, nice try. But i am better!"<<endl;
            cout<<"Give me your money!"<<endl;
            q=1;
        }
    }else{
        cout<<"YOU ARE POWERLESS!"<<endl;
        cout<<"Ahh, fresh money!"<<endl;
        q=1;
    }
    return q;
}
