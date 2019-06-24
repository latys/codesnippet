#ifndef __SmartPoint__
#define __SmartPoint__
template <class T>
class SmartPoint
{
    public:
    SmartPoint(T *d);
    ~SmartPoint();

    SmartPoint(const SmartPoint<T>& sp);
    SmartPoint<T> & operator=(const SmartPoint<T>& sp);
    
    int *ref_count;
    T *data;

};
template<class T>
SmartPoint<T>::SmartPoint(T *d)
{
    ref_count=new int(1);
    data=d;
}

template<class T>
SmartPoint<T>::~SmartPoint()
{
    if(--(*ref_count)==0)
    {
        delete ref_count;
        delete data;
    }
}

template<class T>
SmartPoint<T>::SmartPoint(const SmartPoint<T> & sp)
{
    ref_count=sp.ref_count;
    (*ref_count)++;
    data=sp.data;

  
}

template<class T>
SmartPoint<T> & SmartPoint<T>::operator=(const SmartPoint<T> & sp)
{
    (*sp.ref_count)++;

     if(--(*ref_count)==0)
    {
        delete ref_count;
        delete data;
    }

    ref_count=sp.ref_count;
    
    data=sp.data;

    return *this;
}
#endif