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
        bool RandomNeighbor();
        void Print();
};

int main(){
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

bool NQueen::RandomNeighbor(){
    srand(time(0));
    int copy_array[20];
    bool flag=false;

    for(int x=0;x<200;x++){
        for(int x=0;x<20;x++){copy_array[x]=array[x];}
        copy_array[rand()%19]=rand()%19;
        int compute_conf=Conflict(copy_array);
        if(compute_conf<current_conflict){
            for(int x=0;x<20;x++){array[x]=copy_array[x];}
            current_conflict=compute_conf;
            flag=true;
            return flag;
        }
    }
    return flag;
}

void NQueen::Solve(){
    bool result=RandomNeighbor();
    while(result!=false){result=RandomNeighbor();}
}

void NQueen::Print(){
    cout<<"Current Conflict Is "<<current_conflict<<endl;
    for(int x=0;x<20;x++){
        cout<<array[x]<<"  ";
    }
    cout<<endl;
}