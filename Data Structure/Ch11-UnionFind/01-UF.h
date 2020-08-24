#ifndef UF_H__
#define UF_H__

class UF{
    virtual int getSize() = 0;
    virtual bool isConnected(int p, int q) = 0;
    virtual void unionElements(int p, int q) = 0;
};

#endif