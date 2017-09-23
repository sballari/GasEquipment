#ifndef ERRXML_H
#define ERRXML_H
#include "ModelloHeaders/err.h"


class ErrXML : public Err
{
public:
    ErrXML(std::string info="");
};

#endif // ERRXML_H
