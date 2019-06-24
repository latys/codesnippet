#include "BaseSort.h"
#include <iostream>
class insertSort:public BaseSort
{
private:
    /* data */
public:
    insertSort(/* args */);
    ~insertSort();

    template <class T>
   void  insert_sort(T data[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j>=1;j--)
            {
                if(data[j]>data[j-1])
                {
                    break;
                }
                else
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

insertSort::insertSort(/* args */)
{
}

insertSort::~insertSort()
{
}

void insertSort::Sort()
{
    int a[]={12,10,16,19,30,6,2,4,25,2,3,10};
        insert_sort(a,12);
        for(int v:a)
        {
            std::cout<<v<<std::endl;
        }
        std::cout<<1234567<<std::endl;
}
