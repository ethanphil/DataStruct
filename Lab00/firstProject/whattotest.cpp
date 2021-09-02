// whattotest.cpp

#include "whattotest.h"
#include <iostream>
 
WidgetWithArrays::WidgetWithArrays() : m_count(0)
{
    
}

 
void WidgetWithArrays::storeInteger(int a)
{
    //TODO:
    if (m_count == 100)
    {
        std::cout << "Array is already full" << std::endl;
        return;
    } else
    {
        m_array[m_count] = a;
        m_count ++;
    }
}

int WidgetWithArrays::sum()
{
    int retVal = 0;
    //TODO:
    for (int i = 0; i < m_count; i++)
    {
        retVal += m_array[i];
    }
    
    
    return retVal;
}
 

WidgetWithVector::WidgetWithVector()
{


}

void WidgetWithVector::storeInteger(int a)
{
    m_vector.push_back(a);

}

int WidgetWithVector::sum()
{
    int retVal = 0;

    for(int n : m_vector)
    {
        retVal = retVal +n;
    }


    return retVal;
}
 


