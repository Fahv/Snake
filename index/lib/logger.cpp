#include "logger.h"

Logger::Logger()
{
    createLog("warn");
    createLog("error");
    createLog("misc");
}

bool Logger::createLog(std::string logType)
{
    std::string fileName;
    fileName ="logs/"+logType+".log";
    std::ofstream myFile;

    myFile.open(fileName.c_str());
    myFile.close();
    return true;
}

bool Logger::writeToLog(std::string toWrite, std::string logType)
{

}
