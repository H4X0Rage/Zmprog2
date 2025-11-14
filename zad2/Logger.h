#include <string>
#include <vector>
using namespace std;


class Logger {
    
    private:
    static Logger* instancja;
    vector<string> historia;
    Logger()=default;

    public:
    Logger(const Logger& obj) = delete;
    void operator=(const Logger &) = delete;
    static Logger *Get_instancja_logger();
    void dodaj_historie_log( const string& wpis);
    void pokaz_historie_log();
    void czysc_historie_log();
    ~Logger();


};