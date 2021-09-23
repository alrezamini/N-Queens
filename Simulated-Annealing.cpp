#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class NQueen{
    private:
        int *array;int current_conflict;
    public:
        NQueen(int arr[]){array=arr;current_conflict=Conflict(array);}
        int Conflict(int []);
        void Solve();
        void RandomNeighbor(int);
        void Print();
};

int main(){
    srand(time(0));
    int array[20]={19,5,1,5,7,2,15,4,6,16,13,15,11,6,17,12,10,4,16,1};
    NQueen obj(array);
    obj.Solve();
    obj.Print();
}

int NQueen::Conflict(int array[]){
    int confl=0;
    for(int x=0;x<20;x++){
        for(int i=x+1;i<20;i++){
            if(array[x]==array[i]){confl+=1;}
            if(abs(array[x]-array[i])==abs(x-i)){confl+=1;}
        }
    }
    return confl;
}

void NQueen::RandomNeighbor(int temperature){
    int copy_array[20];
    for(int x=0;x<20;x++){copy_array[x]=array[x];}

    copy_array[rand()%19]=rand()%19;
    int compute_conf=Conflict(copy_array);
    float minus=current_conflict-compute_conf;
    float rnd=(float)rand()/RAND_MAX;
    float delta=minus/temperature;
    if(minus>=0){
        for(int x=0;x<20;x++){array[x]=copy_array[x];}
        current_conflict=compute_conf;
    }
    else{
        if(delta>=rnd&&delta<=1){
            for(int x=0;x<20;x++){array[x]=copy_array[x];}
            current_conflict=compute_conf;
        }
    }
}

void NQueen::Solve(){
    for(int temperature=999;temperature>=0;temperature--){
        RandomNeighbor(temperature);
    }
}

void NQueen::Print(){
    cout<<"Current Conflict Is "<<current_conflict<<endl;
    for(int x=0;x<20;x++){
        cout<<array[x]<<"  ";
    }
    cout<<endl;
}