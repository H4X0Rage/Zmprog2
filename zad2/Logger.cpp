#include "Logger.h"
#include <stdio.h>
#include <iostream>


using namespace std;

Logger* Logger::instancja = nullptr;

Logger* Logger::Get_instancja_logger(){
    if(instancja == nullptr){
        instancja=new Logger();
    }
    return instancja;
}
void Logger::dodaj_historie_log( const string& wpis){
    historia.push_back(wpis);
}
void Logger::pokaz_historie_log(){
    printf("Wyświetlenie historii:");
    if(historia.empty()){
        printf("Wyczyszczona historia");
    }
    else{
        for(int i=0; i<historia.size(); i++)
        {
        cout<<historia[i]<<endl;
        }
    }

}
void Logger::czysc_historie_log(){
    historia.clear();
    printf("Wyczyszczona historia");
}
Logger::~Logger() = default;