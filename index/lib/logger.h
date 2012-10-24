#include <iostream>
#include <fstream>
#include <string>

class Logger
{

    public:
        Logger();

        bool writeToLog(std::string toWrite,std::string logType);

        bool createLog(std::string logType);

};
