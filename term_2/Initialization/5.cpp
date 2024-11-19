#include <iostream>
#include <string>



int sum(std::string& s)
{
    if (s[0] != '[' || s[s.size()-1] != ']')
    {
        throw std::invalid_argument("Invalid format");
    }

    std::string num = s.substr(1, s.size() - 2);
    int sum = 0;
    int a = 0;

    while(a < num.size())
    {
        int b = num.find(',' , a);
        if (b == std::string::npos) 
        {
            b = num.size();
        }

        std::string str = num.substr(a, b - a);

        int space = str.find_first_not_of(' ');
       
        if (space == std::string::npos) 
        {
            throw std::invalid_argument("Invalid format");
        }
        str = str.substr(space, b - space + 1);

        if (!str.empty() && (std::isdigit(str[0]) || str[0] == '-' || str[0] == '+')) 
        {
            for (size_t i = 1; i < str.size(); ++i) 
            {
                if (!std::isdigit(str[i])) 
                {
                    throw std::invalid_argument("Invalid format");
                }
            }
        } 
        else 
        {
            throw std::invalid_argument("Invalid format");
        }

        sum += std::stoi(str);

        a = b + 1;

    }

    return sum;
}



int main()
{
try {
        std::string input = "[4, 8, 15, -a16, , 42]";
        int result = sum(input);
        std::cout << result << std::endl;
    } 
    catch (const std::invalid_argument& e) 
    {
        std::cerr <<e.what() << std::endl;
    }

    return 0;
}