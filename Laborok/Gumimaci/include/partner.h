#ifndef PARTNER_H
#define PARTNER_H
#include <cstdlib>
#include <cstring>

class partner
{
    public:
        partner();
        partner(partner& other);
        ~partner();
        void setLastName(const char str[20]) {strcpy(lastName, str);}
        void setFirstName(const char str[20]) {strcpy(firstName, str);}
        void setTaxId(const char id[10]) {strcpy(taxId, id);}
        void setPartner(const partner& other) {contact(other);}
        void getLastName () const {return lastName;}  //lehet szar
        void getFistName () const {return firstName;}
        void getTaxId () const {return taxId;}
        void getPrivateKey() const {return privateKey;}
        //meg kell irni ezt a partner cuccot

    private:
        char lastName[20];
        char firstName[20];
        char taxId[10];
        char privateKey[2001];
        partner& contact;
};

#endif // PARTNER_H

/*
------------------------------------
|            Partner              |
------------------------------------
| - lastName: char[20]           |
| - firstName: char[20]          |
| - taxId: char[10]              |
| - privateKey: char[2001]       |
| - contact: Partner*            |
------------------------------------
| + generatePrivateKey(): void  |
| + printData(): void            |
------------------------------------
*/
