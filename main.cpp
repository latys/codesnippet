#include <iostream>
#include "SortFactory.h"
#include "BaseSort.h"
#include "SmartPoint.h"
#include "Priority_queue.h"
#include "ThreadPool.h"
int main() {
    std::cout << "Hello Easy C++ project!" << std::endl;
    
    {
        ThreadPool pool(10);
        _sleep(10);
        for (size_t i = 0; i < 50; i++)
        {
            pool.addTask([&i](){std::cout<<"work thread"<<std::endl;});
            _sleep(10);
        }
    }

    


    SortFactory fac;
//     BaseSort *sort= fac.CreatSort("quick sort");
//     sort->Sort();

    std::cout<<"heap sort-------------"<<endl;
     BaseSort *sort=fac.CreatSort("quick_sort");
    sort->Sort();
    std::cout<<"heap sort end-------------"<<endl;
     // Test Constructor and Assignment Operator Overloaded
     SmartPoint<int> p1(new int(0));
     p1 = p1;
     // Test Copy Constructor
     SmartPoint<int> p2(p1);
     std::cout<<*p2.ref_count<<std::endl;
     // Test Assignment Operator Overloaded
     SmartPoint<int> p3(new int(1));
     p3 = p1;

     std::cout<<*p3.ref_count<<std::endl;


     MinHeap<int> heap(20);
     heap.push(3);
     heap.push(5);
     heap.push(6);
     heap.push(2);
     heap.push(1);
     std::cout<<"-------------"<<endl;
     heap.print();
     std::cout<<"-------------"<<endl;
     heap.pop();
     heap.print();
     std::cout<<"-------------"<<endl;
     heap.pop();
     heap.print();
     system("pause");
     return 0;

}