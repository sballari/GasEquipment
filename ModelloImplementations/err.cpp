#include "ModelloHeaders/err.h"

Err::Err(std::string i)
{
    info=i;
}
std::string Err::getInfo() const{
    return info;
}
