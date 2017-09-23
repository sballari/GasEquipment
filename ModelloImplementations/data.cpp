#include "ModelloHeaders/data.h"
#include <sstream>
#include <time.h>
#include "ModelloHeaders/funzioni.h"

unsigned int Data::GiorniMese (unsigned int ms, unsigned int an){
    if (ms==1 || ms==3 || ms==5 || ms==7 || ms==8 || ms==10 || ms==12)
        return 31;

    if (ms==4 || ms==6 || ms==9 || ms==11)
        return 30;

    if (ms==2){
        if (Bisestile (an)){return 29;}
        else return 28;
    }
    return 0;

}

Data::Data(unsigned int g, unsigned int m, unsigned int a):giorno(g), mese(m), anno(a){

    if (mese<=12){
        if (giorno==0 || giorno> GiorniMese(mese, anno))
            {giorno=1; mese=1; anno=2000;}
    }
    else {giorno=1; mese=1; anno=2000;}
}

bool Data::Bisestile(unsigned int anno){
    if (!(anno%4)){
        if (!(anno%100)){
            if (!(anno%400)) return true;
            else return false;
        }
        return true;
    }
    else return false;
}

std::ostream& operator << (std::ostream& canale, const Data& ogg){
    return canale<<ogg.giorno<<"/"<<ogg.mese<<"/"<<ogg.anno;
}


bool Data::operator >= (const Data& cp) const{
    if(anno>cp.anno) return true;
    if (anno==cp.anno) {
        if (mese>cp.mese) return true;
        if (mese==cp.mese) {
            if (giorno>=cp.giorno) return true;
            else return false;
        }
        return false;
    }
    return false;
}

Data Data::Oggi(){
    time_t timer;
    time(&timer);
    tm* ora = localtime(&timer);
    return Data(ora->tm_mday,(ora->tm_mon)+1,1900+(ora->tm_year));
}

int Data::getAnno() const {return anno;}
int Data::getMese() const {return mese;}
int Data::getGiorno() const {return giorno;}

Data::Data(const QDate & a):giorno(a.day()),mese(a.month()),anno(a.year()){}

Data::operator QDate() const{
    QDate I(anno, mese, giorno);
    return I;
}

Data::operator std::string ()const{
    std::string I;
    I+=ToString(giorno);
    I+="/";
    I+=ToString(mese);
    I+="/";
    I+=ToString(anno);
    return I;

}

Data::Data(std::string d){
    std::string g,m,a;
    std::string::const_iterator it = d.begin();
    for (;it<d.end() && (*it)!='/';it++){
        g=g+(*it);
    }
    it++;
    for (;it<d.end() && (*it)!='/';it++){
        m=m+(*it);
    }
    it++;
    for (;it<d.end() && (*it)!='/';it++){
        a=a+(*it);
    }

    giorno=std::atoi(g.c_str());
    mese=std::atoi(m.c_str());
    anno=std::atoi(a.c_str());
    if (mese<=12){
        if (giorno==0 || giorno> GiorniMese(mese, anno))
            {giorno=1; mese=1; anno=2000;}
    }
    else {giorno=1; mese=1; anno=2000;}



}

 Data::operator QString () const{
    std::string I = this->operator std::string();
    return QString::fromStdString(I);

}


