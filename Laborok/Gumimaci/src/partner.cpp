#include "partner.h"

partner::partner()
{
    //ctor
}

partner::partner(partner& other)
{
    strcpy(lastName, other.getLastName());
    strcpy(firstName, other.getFistName());
    strcpy(taxId, other.getTaxId());
    strcpy(privateKey, other.getPrivateKey());
}
partner::~partner()
{
    //dtor
}
