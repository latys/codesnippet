
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class MinHeap
{
    public:
    int capacity;
    vector<T> data;

    public:
    MinHeap(int len);
    void push(T element);
    void pop();
    void filterUp(int cur);
    void filterDown(int start,int end);

    void print();

};

template <class T> 
MinHeap<T>::MinHeap(int len)
{
    capacity=len;
    data.reserve(len);
}
template <class T> 
void MinHeap<T>::print()
{
    for(auto t:data)
    {
        cout<<t<<endl;
    }
}
template <class T> 
void MinHeap<T>::push(T element)
{
    int size=data.size();
    data.push_back(element);
    filterUp(size);
}

template <class T> 
void MinHeap<T>::pop()
{
    int size=data.size();
    if(size==0)
       return;
    data[0]=data[size-1];
    data.erase(data.end()-1);
    filterDown(0,size-1);
}


template <class T> 
void MinHeap<T>::filterDown(int start,int end)
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

template <class T> 
void MinHeap<T>::filterUp(int cur)
{
   if(cur==0)
     return;
   while(cur>0) 
   {
       T parent=data[(cur-1)/2];
       if (data[cur]<parent)
       {
           data[(cur-1)/2]=data[cur];
           data[cur]=parent;
       }
       cur=(cur-1)/2;
   }
}