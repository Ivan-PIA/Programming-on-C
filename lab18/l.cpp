#include <stdio.h>
#include "iostream"
#include "list"
using namespace std;


class train {
    private:
        int number;
       string name;
        float time;

    public:
        train(int num,string nam,float t){
            number=num;
            name=nam;
            time=t;
        }
    void out(){
        cout<<"Номер поезда: "<<number;
        cout<<" Станция: "<<name;
        cout<<" Время прибытия: "<<time<<endl;
    }
    
    void out2(){
        
        cout<<"Поезд: "<<number<<endl;
    }
    
    int get_num(){
    return number;
}

    string get_station(){
        return name;
    }


};

list <train> base;

void out3(){
    for (auto i : base){
        i.out();
    }
}
void out2(string station){
    for (auto i : base) {
        if (i.get_station() == station) {
            i.out2();
            
        }
       
    }

   
}


void out(int l) {
    for (auto i : base) {
        if (i.get_num() == l) {
            i.out();
        
        }
        
        
    }
}

int main(){
    int numb,c=1;
    string s;
    float ti;
    while(c!=0){
        printf("Введите номер поезда:");
        cin>>numb;
        printf("Название станции:");
        (cin>>s).get();
        printf("Время прибытия:");
        cin>>ti;
        base.push_back(train(numb,s,ti));
        cout<< "Продолжить?  1/0 : ";
        cin>>c;
        cout<<endl;
    }
    
    int l,k;
    cout<<"Вывести все данные?1/0";
    cin>>k;
    if(k==1){
        out3();
    }
    
        
    cout<<"Иформация о каком поезде интересна? ";
    cin>>l;
    cout<<endl<<endl;
    
    out(l);
    string station;
    cout<<"Иформация о какой станции требуется? ";
    cin>>station;
    cout<<"До этой станции следует"<<endl;
    out2(station);
}





