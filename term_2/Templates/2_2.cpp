 #include <iostream>


std::string operator*(int n, std::string s)
{
    std::string res;

    for(int i = 0 ; i < n ; i++)
    {
        res += s;
    }

    return res;
}


 template<typename T>
 T triple(const T& x)
 {
 return 3*x;
 }
 int main()
 {
 int a = 10;
 std::cout << triple(a) << std::endl; // Сработает, напечатает 30
 std::string b = "Cat";
 std::cout << triple(b) << std::endl; // Ошибка, нельзя число 3 умножать на std::string
 // Нужно чтобы напечаталось CatCatCat
 }