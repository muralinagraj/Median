#include <iostream>
#include <fstream>
#include <vector>
#include <initializer_list>  
#include <algorithm>


double median(std::vector<double> vec, int size)
{
    
  std::sort(vec.begin(), vec.end());

  double median;

  if (size % 2 != 0)
     median = static_cast<double> (vec[size / 2]);
  else
     median = static_cast<double>((vec[(size - 1) / 2] + vec[size / 2]) / 2.0);

 //  std::cout << "Median is = " << median ;


  return median;
  
}


int main(int argc, char * argv[])
{
    std::fstream myfile("sample.txt", std::ios_base::in);
    std::vector<double> values{};
    double input;
    while (myfile >> input)
    {
        if((input > -70) && (input < +2.08E9))
            values.push_back(input);
        else
            std::cout << "Error: Value is not in the specified range \n";            
                
    }

    // Sorting the values;
    std::sort(values.begin(), values.end());
    
    // Displaying sorted values
    for (double i : values)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';
  
 
    int size = values.size();

    // Find the median
    auto medianValue = median(values,size);
   
    std::cout << "Median is " << medianValue << '\n' ;

    myfile.close();
    return 0;
}
