//
//  sharedPtr.hpp
//  leetcode
//
//  Created by 安博 on 2019/7/29.
//  Copyright © 2019 anbo. All rights reserved.
//

#ifndef sharedPtr_h
#define sharedPtr_h
#include <iostream>
using namespace std;

template<typename T>
class SharedPtr{
private:
    T *ptr;          // 指向实际共享对象
    int *use_count;  //  引用计数，注意此处类型必须为 int*
public:
    
                                       
    SharedPtr(): ptr((T *)0), use_count(0) {}
    
    SharedPtr(const SharedPtr<T> &orig): ptr(orig.ptr), use_count(&(++*orig.use_count)){
        cout<<"copy constructor : "<<*ptr<<"\trefCount = "<<*use_count<<endl;
    }
    
    SharedPtr(T *p): ptr(p), use_count(new int(1)) {
        cout<<"create object : "<<*ptr<<"\trefCount = 1"<<endl;
    }
   
    
    SharedPtr<T>& operator=(const SharedPtr<T> &rhs) {
        if (&rhs != this){
            ++*rhs.use_count;
            if(--*use_count == 0) {
                cout<<"in function operator = . delete "<<*ptr<<endl;
                delete ptr;
                delete use_count;
            }
            ptr = rhs.ptr;
            use_count = rhs.use_count;
            cout<<"in function operator = . "<<*ptr<<"\t_refCount = "<<*use_count<<endl;
            return *this;
        }
        return *this;
    }
    
    T operator*(){
        if (use_count == 0)
                return (T*)0;
        return *ptr;
    }
    T* operator->(){
        if (use_count == 0)
            return 0;
        return ptr;
    }
    
    ~SharedPtr(){
        if(ptr && --*use_count == 0) {
            cout<<*ptr<<"\trefCount = 0. delete the ptr:"<<*ptr<<endl;
            delete ptr;
            delete use_count;
        }
    }
    
//    T* operator+(int i);
//    int operator-(SharedPtr<T>&t2);
//
    int getcount() { return *use_count; };
    
};


#endif /* sharedPtr_h */
