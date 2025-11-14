//WEL24MX1S4
//Pawel Bakula
//14.11.2025
//Linux Ubuntu,Visual Studio Code 1.97.2
//10.202.131.63 zestaw nr 3 double oraz long
#include <iostream>
#include <string>
#include "Logger.h"
using namespace std;



class Kalkulator{
    public:
    virtual double dzialanie(double a,long b)=0;
    virtual ~Kalkulator() {};
};
class Dodawanie : public Kalkulator{
    double dzialanie(double a,long b) override{
        double wynik=a+b;
        Logger::Get_instancja_logger()->dodaj_historie_log(
            "Dodawanie: " + to_string(a) + " + " + to_string(b) + " = " + to_string(wynik)
        );
        return wynik;
    };
};
class Odejmowanie : public Kalkulator{
    double dzialanie(double a,long b) override{
        double wynik=a-b;
        Logger::Get_instancja_logger()->dodaj_historie_log(
            "Odejmowanie: " + to_string(a) + " - " + to_string(b) + " = " + to_string(wynik)
        );
        return wynik;
    };
};
class Mnozenie  : public Kalkulator{
    double dzialanie(double a,long b) override{
        double wynik=a*b;
        Logger::Get_instancja_logger()->dodaj_historie_log(
            "Mnozenie: " + to_string(a) + " * " + to_string(b) + " = " + to_string(wynik)
        );

        return wynik;
    };
};
class Iloraz : public Kalkulator{
     double dzialanie(double a,long b) override{
        if(b==0){
            Logger::Get_instancja_logger()->dodaj_historie_log(
                "Dzielenie przez zero: " + to_string(a) + " / 0"
            );
            return 0;
            
        }
        double wynik=a/b;
        Logger::Get_instancja_logger()->dodaj_historie_log(
            "Iloraz: " + to_string(a) + " / " + to_string(b) + " = " + to_string(wynik)
        );
        return wynik;
    };
};
class Kreator{
    private:
    Kalkulator* kalkulator;

    public:
    Kreator(char typ){
        switch(typ){
case 'd':
    printf("Wybrano operacje Dodawanie\n");
  
    this->kalkulator = new Dodawanie(); 
    break;
   
case 'o':
    printf("Wybrano operacje Odejmowanie\n");
   
    this->kalkulator = new Odejmowanie(); 
    break;
   
case 'm':
    printf("Wybrano operacje Mnozenie\n");
  
    this->kalkulator = new Mnozenie(); 
    break;
case 'i':
    printf("Wybrano operacje Iloraz\n");

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
    Logger* logger= Logger::Get_instancja_logger();

    Kreator* operacja=new Kreator('d');
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

    cout << "\n===== HISTORIA LOGU =====\n";
    logger->pokaz_historie_log();
    // logger->Get_instancja_logger()->pokaz_historie_log();
    return 0;
};