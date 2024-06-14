#include <iostream>
#include <map>

std::string numsToString(const int& number)
{
    std::map<int,std::string> nums = 
    {
        {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"},
        {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"}, {11, "eleven"}, {12, "twelve"},
        {13, "thiteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventen"},
        {18, "eighteen"}, {19, "nineten"}, {20, "twenty"}, {30, "thirty"}, {40, "forty"},
        {50, "fifty"}, {60, "sixty"}, {70, "seventy"}, {80, "eihty"}, {90, "ninety"}
    };


    if (number <= 20)
    {
        return nums[number];
    }
    
    if (number > 20 && number < 100)
    {
        std::string str;
        int ten = number / 10;
        int digit = number % 10;

        str += nums[ten * 10];
        str += " ";
        
        if (digit != 0)
        {
            str += nums[digit];
        }
    
        return str;
    }

    
    if (number > 99 && number < 1000)
    {
        std::string str;

        int hundred = number / 100;
        int ten = number % 100;

        str = str + nums[hundred] + " hundred ";
        
        if (ten <= 20 && ten > 10)
        {
            str = str + nums[ten];
            return str;
        }
        else
        {
            if (ten > 20)
            {
                int digit = ten % 10;
                ten = ten / 10;
                str = str + nums[ten * 10];
                if (digit != 0)
                {
                    str = str  + " " + nums[digit];
                }
                
                return str;
            }
            else
            {
                if (ten != 0)
                {
                    str = str + nums[ten];
                    return str;
                }
            
            }
            return str;
        }
    }


    if (number > 999 && number < 100000)
    {
        std::string str;
        int thousand = number / 1000;
        int hundred = (number % 1000) / 100;
        int ten = (number % 100) / 10;
        int digit = (number % 10);

        if (thousand <= 20)
        {
            str = str + nums[thousand] + " thousand ";
        }
        else
        {
            int ten1 = thousand / 10;
            int digit1 = thousand % 10;

            str += nums[ten1 * 10];
            str += " ";
            
            if (digit1 != 0)
            {
                str += nums[digit1] + " thousand ";
            }

        }
        

        if (hundred != 0)
        {
            str = str + nums[hundred] + " hundred ";
        }

        if (ten != 0)
        {
            if ((ten * 10 + digit) <= 20)
            {
                str = str + nums[(ten * 10 + digit)];
                return str;
            }
            else
            {
                str = str + nums[ten * 10] + " ";
            }
        }
        
        if (digit != 0)
        {
            str = str + nums[digit];
        }
    
        return str;
    }
    
    std::cout<<"The number is out of range."<<std::endl;
    return str;
}


int main()
{
    for (size_t i = 99900; i < 99999; i++)
    {
        std::cout<<numsToString(i)<<std::endl;
    }

    return 0;
}