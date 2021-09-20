#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class EightQueen{
    public:
        int *array;int current_conflict;
    public:
        EightQueen(int arr[]){array=arr;current_conflict=Conflict(array);}
        int Conflict(int []);
        void Solve();
        bool RandomNeighbor();
};

int main(){
    int array[8]={3,5,1,6,7,2,0,4};
    EightQueen obj(array);
    obj.Solve();
    cout<<obj.current_conflict<<endl;
}

int EightQueen::Conflict(int array[]){
    int confl=0;
    for(int x=0;x<8;x++){
        for(int i=0;i<8;i++){
            if(x==i){continue;}
            if(array[x]==array[i]){confl+=1;}
            if(abs(array[x]-array[i])==abs(x-i)){confl+=1;}
        }
    }
    return confl/2;
}

bool EightQueen::RandomNeighbor(){
    srand(time(0));
    int copy_array[8];
    bool flag=false;

    for(int x=0;x<100;x++){
        for(int x=0;x<8;x++){copy_array[x]=array[x];}
        copy_array[rand()%7]=rand()%7;
        int compute_conf=Conflict(copy_array);
        if(compute_conf<current_conflict){
            for(int x=0;x<8;x++){array[x]=copy_array[x];}
            current_conflict=compute_conf;
            flag=true;
            return flag;
        }
    }
    return flag;
}

void EightQueen::Solve(){
    bool result=RandomNeighbor();
    while(result!=false){result=RandomNeighbor();}
    for(int x=0;x<8;x++){
        cout<<array[x]<<"\t";
    }
}