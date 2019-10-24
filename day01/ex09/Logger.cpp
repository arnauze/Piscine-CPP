# include "Logger.hpp"

typedef struct {
    std::string             name;
    void                    (Logger::*func)(std::string message);
}       log_t;

Logger::Logger( std::string filename ) : _file(filename){ return ; }
Logger::~Logger(void) { return; }

void                        Logger::logToConsole(std::string message) {
    std::cout << this->makeLogEntry(message) << std::endl;
    return ;
}

void                        Logger::logToFile(std::string message) {
    std::ofstream   f(this->_file, std::ios::out | std::ios::app);
    f << this->makeLogEntry(message) << std::endl;
}

void                        Logger::callLogToFile(std::string message) {
    this->logToFile(message);
}

void                        Logger::callLogToConsole(std::string message) {
    this->logToConsole(message);
}

std::string                 Logger::makeLogEntry(std::string message) {
    std::string timestamp;
	time_t rawtime;

	time (&rawtime);
	timestamp = std::string(ctime(&rawtime));
	timestamp.erase(timestamp.length() - 1, 1);

	return ("[" + timestamp + "] : " + message);
}

void                        Logger::log(std::string const & dest, std::string const & message) {
    log_t                   types[2] = {
        {"console", &Logger::callLogToConsole},
        {"file", &Logger::callLogToFile}
    };
    int                     i;

    i = -1;
    while (++i < 2) {
        if (dest == types[i].name)
            (*this.*types[i].func)(message);
    }

}
