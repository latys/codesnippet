#include "BaseSort.h"
#include <iostream>

class MergeSort:public BaseSort
{
private:
    /* data */
public:
    MergeSort(/* args */);
    ~MergeSort();

    template <class T>
    void merge(T data[],T temp[],int left,int right,int end)
    {
        int index=left;
        int lpos=left;
        int cpos=right;

        while(left<cpos&&right<=end)
        {
            if (data[left]<data[right])
            {
                temp[index]=data[left];
                left++;
            }
            else
            {
                temp[index]=data[right];
                right++;
            }
            index++;
            
        }
        while (left<cpos)
        {
            temp[index]=data[left];
            left++;
            index++;

        }

        while (right<=end)
        {
            temp[index]=data[right];
            right++;
            index++;
            
        }

        for (int i = lpos; i < end+1; i++)
        {
            data[i]=temp[i];
        }
        
        
    }

    template <class T>
    void Merge_Sort(T data[],int len)
    {
        T *temp=new T[len];
        MSort(data,temp,0,len-1);
        delete []temp;
    }

    template <class T>
    void MSort(T data[],T temp[],int left,int right)
    {
       
        if (left<right)
        {
            MSort(data,temp,left,(right+left)/2);
            MSort(data,temp,(right+left)/2+1,right);
            merge(data,temp,left,(right+left)/2+1,right);
        }
        

    }
    virtual void Sort();
};

MergeSort::MergeSort(/* args */)
{
}

MergeSort::~MergeSort()
{
}

void MergeSort::Sort()
{
     int a[]={12,10,16,19,30,6,2,4,25};
        Merge_Sort(a,9);
        for(int v:a)
        {
            std::cout<<v<<std::endl;
        }
        std::cout<<1234567<<std::endl;
}
