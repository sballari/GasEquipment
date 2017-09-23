#ifndef ERR_H
#define ERR_H
#include <string>


class Err
{
public:
    Err(std::string i="NO info");
    std::string getInfo() const;
private:
    std::string info;
};

#endif // ERR_H
