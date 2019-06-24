#ifndef QuickSort_
#define QuickSort_
#include "iostream"
#include "BaseSort.h"
class QuickSort:public BaseSort{
    public:
    QuickSort(){

    }

    

    virtual void Sort()
    {
        int a[]={12,10,16,19,30,16,2,4,25};
        quicksort(a,0,8);
        for(int v:a)
        {
            std::cout<<v<<std::endl;
        }
        std::cout<<1234567<<std::endl;
    }

    template<class T> 
    void quicksort1(T data[],int p,int q)
    {
        int k=0;
          if(p<q)
          {
            k= partition(data,p,q);

            quicksort(data,p,k);
            quicksort(data,k+1,q);
       
          }
           
  

    }

    template<typename T>
void quicksort(T *data, int left,int right)
{
	if (left>=right)
	{
		return;
	}
	T base = data[left];
	int i = left;
	int j = right;
	while (left < right)
	{
		while (left < right&&data[right] >= base)
		{

			right--;

		}
		data[left] = data[right];
		while (left < right&&data[left] <= base)
		{

			left++;

		}
		data[right] = data[left];
	}
	data[left] = base;
	quicksort(data, i, left - 1);
	quicksort(data, left + 1, j);
}

    template<class T> 
    int partition(T *data,int p,int q)
    {
        if(n<=1)
          return 0;
         int i=p+1;
         int j=q;
         int base=*(data+p);
         while(i<j){
             while(*(data+i)<base&&i<j)
             {
                i++;
             }
              while(*(data+j)>base&&i<j)
             {
                j--;
             }
             if(i<j)
             {
                T temp=*(data+i);
                *(data+i)=*(data+j);
                *(data+j)=temp;
             }
             else
             {
                 return j;
             }
             
        
             /* code */
         }
         

    }

};

#endif