#ifndef FILE_ACTION_H
#define FILE_ACTION_H

#include <string>
#include <iostream>

class FileAction {
private:
    std::string prompt;
    std::string filename;

public:
    std::string user_input(std::string);
    
};

#endif // MURACH_MOVIE_H

