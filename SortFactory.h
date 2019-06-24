#ifndef SortFactory_
#define SortFactory_
#include "BaseSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "insertSort.h"
#include "bubbleSort.h"
#include "MergeSort.h"
#include "string"
class SortFactory{
    public:
    BaseSort *pSort=nullptr;
    public:
    SortFactory(){

    }

    virtual BaseSort *CreatSort(std::string sort_name)
    {
        if (pSort!=nullptr) {
            delete pSort;
            /* code */
        }
        else
        {
            if(sort_name.compare("heap_sort")==0)
            {
                pSort=new heapsort();
            }
            else if(sort_name.compare("insert_sort")==0)
            {
                pSort=new insertSort();
            }
            else if(sort_name.compare("bubble_sort")==0)
            {
                pSort=new bubbleSort();
            }
            else if(sort_name.compare("merge_sort")==0)
            {
                pSort=new MergeSort();
            }
            else
            {
               pSort=new QuickSort();
            }
            
            /* code */
            
        }
        return pSort;
        
    }

};

#endif