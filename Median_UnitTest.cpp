#include "Median.h"
#include "gtest/gtest.h"


TEST(MedianTest, Test1)
{

std::vector<double> values{10,20,30,40,50,60};
int size= values.size();
double expected_median=((values[(size - 1) / 2] + values[size / 2]) / 2.0);   //expected median is 35
EXPECT_EQ(expected_median,median(values,size));   
}

TEST(MedianTest, Test2)
{

std::vector<double> values{10,20,30,40,50,60,70};
int size= values.size();
double expected_median=(values[size / 2]);   //expected median is 40
EXPECT_EQ(expected_median,median(values,size));   
}




