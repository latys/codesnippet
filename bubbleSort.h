#include "BaseSort.h"
#include <iostream>

class bubbleSort:public BaseSort
{
private:
    /* data */
public:
    bubbleSort(/* args */);
    ~bubbleSort();

    template <class T>
    void bubble_sort(T data[],int len)
    {
        for (size_t i = 0; i < len-1; i++)
        {
            for(int j=1;j<len-1-i;j++)
            {
                 if (data[j-1]>data[j])
                 {
                    T temp=data[j];
                    data[j]=data[j-1];
                    data[j-1]=temp;
                 }
                 
               
            }
        }
        
    }
    virtual void Sort();
};

bubbleSort::bubbleSort(/* args */)
{
}

bubbleSort::~bubbleSort()
{
}

void bubbleSort::Sort()
{
    int a[]={12,10,16,19,30,6,2,4,25,2,3,30};
        bubble_sort(a,12);
        for(int v:a)
        {
            std::cout<<v<<std::endl;
        }
        std::cout<<1234567<<std::endl;
}
