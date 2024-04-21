#ifndef EQUIPMENT_H
#define EQUIPMENT_H


class Equipment
{
public:
    Equipment() : price(0), serialNumber(0) {}
    Equipment(unsigned serialNumber_, unsigned price_) {price = price_; serialNumber = serialNumber_;}
    virtual ~Equipment() {}

    void setSerialNumber(unsigned sN) {serialNumber = sN;};
    unsigned getSerialNumber() const {return serialNumber;}

    void setPrice(unsigned price_) {price = price_;}
    unsigned getPrice() const {return price;}

    virtual void print() const {}; //lehet nem virtual
protected:
    unsigned serialNumber;
    unsigned price;
private:
};

#endif // EQUIPMENT_H
