#ifndef COMPUTER_H
#define COMPUTER_H

class Computer
{
private:
    static unsigned nextId;
    unsigned id;
    unsigned clockSpeed;

public:
    Computer();
    Computer(const Computer&);
    unsigned getClockSpeed() const {return clockSpeed;}
    void print() const;
    friend void friendlyPrint(const Computer&);
};

void friendlyPrint(const Computer&);

#endif // COMPUTER_H
