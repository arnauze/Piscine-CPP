#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <ctime>
# include <iomanip>

class Logger
{
    private:
        void            logToConsole(std::string message);
        void            logToFile(std::string message);
        std::string      makeLogEntry(std::string message);
        std::string    _file;

    public:
        void            log(std::string const & dest, std::string const & message);
        void            send(void);
        void            callLogToFile(std::string message);
        void            callLogToConsole(std::string message);
        Logger(std::string filename);
        ~Logger(void);
};

#endif