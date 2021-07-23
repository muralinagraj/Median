#include <iostream>
#include <fstream>
#include <vector>
#include <initializer_list>  
#include <algorithm>


double median(std::vector<double> vec)
{
    
  auto size = vec.size();
  if (size % 2 != 0)
     return(static_cast<double> (vec[size / 2]));
  else
     return(static_cast<double>((vec[(size - 1) / 2] + vec[size / 2]) / 2.0));
  
}

int main(int argc, char * argv[])
{
    std::fstream myfile(argv[1], std::ios_base::in);
    
    if( !myfile ) 
    {
        std::cout << "Error opening input file \n ";
        exit(1) ;
    }

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
  
    // Find the median
    auto medianValue = median(values);
   
    std::cout << "Median is " << medianValue << '\n' ;

    myfile.close();
    return 0;
}

