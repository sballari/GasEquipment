#ifndef DATA_H
#define DATA_H
#include <iostream>
#include "time.h"
#include <QDate>

class Data{
    friend std::ostream& operator << (std::ostream&, const Data&);
private:
    unsigned int giorno, mese, anno;

    static bool Bisestile (unsigned int);
public:
    Data(unsigned int =1, unsigned int =1, unsigned int = 2000);
    Data(const QDate &);
    Data(std::string d);

    static unsigned int GiorniMese (unsigned int, unsigned int);
    bool operator >= (const Data&) const;
    static Data Oggi();
    //convertitori
    operator std::string () const;
    operator QString () const;
    operator QDate() const;



    int getAnno() const;
    int getMese() const;
    int getGiorno() const;

};

std::ostream& operator << (std::ostream&, const Data&);

#endif // DATA_H
