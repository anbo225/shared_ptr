//
//  main.cpp
//  Test for c++ shared pointer
//
//  Created by 安博 on 2019/7/24.
//  Copyright © 2019 anbo. All rights reserved.
//

#include <string>
#include "sharedPtr.hpp"

using namespace std;

int main()
{
    SharedPtr<string> pstr(new string("first object"));
    SharedPtr<string> pstr2(pstr);
    SharedPtr<string> pstr3(new string("second object"));
    pstr3 = pstr2;
    
    return 0;
}
