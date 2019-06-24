#include "BaseSort.h"
#include <iostream>

class heapsort:public BaseSort
{

public:
heapsort()
{

}
~heapsort()
{

}

    virtual void Sort()
    {
        int a[]={12,10,16,19,30,6,2,4,25,16,19,6};
        HeapSort(a,12);
        for(int v:a)
        {
            std::cout<<v<<std::endl;
        }
        std::cout<<1234567<<std::endl;
    }

    template <class T>
void HeapSort(T data[],int len)
{
    buildHeap(data,len);
    std::cout<<"---build heap-----"<<std::endl;
    for(int i=0;i<len;i++)
    {
        std::cout<<data[i]<<std::endl;
    }
    std::cout<<"---build heap-----"<<std::endl;

    for(int i=0;i<len;i++)
    {
        T temp=data[0];
        data[0]=data[len-i-1];
        data[len-i-1]=temp;
        filterDown(data,0,len-i-2);
    }
}

template <class T>
void buildHeap(T data[],int len)
{
    for(int i=len/2;i>=0;i--)
    {
        filterDown(data,i,len-1);
    }

}

template <class T> 
void filterDown(T data[],int start,int end)
{
   int cur=start;
   int left=2*start+1;
   T tmp=data[cur];
   while(left<=end)
   {
       if (left<end&&data[left]>data[left+1])
       {
           left++;
       }
       if(tmp<data[left])
          return;
       else
       {
           data[cur]=data[left];
           data[left]=tmp;
           cur=left;
           left=2*left+1;
       }

   }
   
}
};

