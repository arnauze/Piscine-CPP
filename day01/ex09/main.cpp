# include "Logger.hpp"

int             main(void) {
    Logger      l("file");
    
    l.log("console", "Hey console");
    l.log("file", "Hey file");

    return (0);
}