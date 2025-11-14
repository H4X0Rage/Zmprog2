//WEL24MX1S4
//Pawel Bakula
//14.11.2025
//Linux Ubuntu,Visual Studio Code 1.97.2
//10.202.131.63 zestaw nr 3 double oraz long
#include <iostream>
#include <string>
using namespace std;


class Kalkulator{
    public:
    virtual double dzialanie(double a,long b)=0;
    virtual ~Kalkulator() {};
};
class Dodawanie : public Kalkulator{
    double dzialanie(double a,long b) override{
        return a+b;
    };
};
class Odejmowanie : public Kalkulator{
    double dzialanie(double a,long b) override{
        return a-b;
    };
};
class Mnozenie  : public Kalkulator{
    double dzialanie(double a,long b) override{
        return a*b;
    };
};
class Iloraz : public Kalkulator{
     double dzialanie(double a,long b) override{
        if(b==0){
            return 0;
        }
        return a/b;
    };
};
class Kreator{
    private:
    Kalkulator* kalkulator;

    public:
    Kreator(char typ){
        switch(typ){
case 'd':
    printf("wybrano operacje dodawanie\n");
    this->kalkulator = new Dodawanie(); 
    break;
   
case 'o':
    this->kalkulator = new Odejmowanie(); 
    break;
   
case 'm':
    this->kalkulator = new Mnozenie(); 
    break;
case 'i':
    this->kalkulator = new Iloraz(); 
    break;
default:
    cout<<"Błędna operacja"<<endl;
    nullptr;
    throw -1;
    break;
}
    }
    ~Kreator(){
        delete this->kalkulator;
    };
    Kalkulator* getKalkulator(){
        return this->kalkulator;
    };
};
int main(){
    double a=1.5;
    long b=2;
    

    Kreator* operacja=new Kreator('y');
    Kalkulator* operacjaDod = operacja->getKalkulator();
    cout<<"Wynik dodawania a+b="<<operacjaDod->dzialanie(a,b)<<endl;
    delete operacja;
    operacja=nullptr;


    Kreator* operacja1=new Kreator('o');
    Kalkulator* operacjaOd = operacja1->getKalkulator();
    cout<<"Wynik odejmowania a-b="<<operacjaOd->dzialanie(a,b)<<endl;
    delete operacja1;
    operacja1=nullptr;

    Kreator* operacja2=new Kreator('m');
    Kalkulator* operacjaMnozenie = operacja2->getKalkulator();
    cout<<"Wynik mnozenia a*b="<<operacjaMnozenie->dzialanie(a,b)<<endl;
    delete operacja2;
    operacja2=nullptr;

    Kreator* operacja3=new Kreator('i');
    Kalkulator* operacjaIloraz = operacja3->getKalkulator();
    cout<<"Wynik ilorazu a/b="<<operacjaIloraz->dzialanie(a,b)<<endl;


    //dzielenie przez zero
    b=0;
    
    cout<<"Wynik ilorazu a/b="<<operacjaIloraz->dzialanie(a,b)<<endl;
    delete operacja3;
    operacja3=nullptr;

    return 0;
};