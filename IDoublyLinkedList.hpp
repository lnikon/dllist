#pragma once

template <class T>
class IDLList 
{
  public:
    virtual ~IDLList() {}

    virtual bool        empty() const                           = 0;
    virtual int size() const                            = 0;
    virtual const T&    getValue(int pos)               = 0;
    virtual void        insert(int pos, const T& item)  = 0;
    virtual void        clear()                                 = 0; 
};
