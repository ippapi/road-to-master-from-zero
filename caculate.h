using namespace std;
int caculate(int x, int *arr){
    int aCount=0;
    int sum=0;
    int max=0;
    for(int i=0;i<x;i++){
        if(arr[i]>=10){
            sum+=10;
        }else if(arr[i]==1){
            aCount++;
        }else{
            sum+=arr[i];
        }
    }
    if(sum+aCount>21){
        return 22;
    }else{
        for(int i=0;i<=aCount;i++){
            for(int j=0;j<=aCount-i;j++){
                int k=aCount-i-j;
                int a=sum+i+10*j+11*k;
                if(a>max && a<=21){
                    max=a;
                }
            }
        }
        return max;
    }
}
