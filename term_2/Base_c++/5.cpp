 #include <iostream>

 struct Book
 {
 std::string title;
 int pages;
 float price;
 };

bool isExpensive(const Book& b)
{
    return b.price > 1000;
}


 main()
 {
    Book B = {"a" , 300 , 999};
    std::cout <<isExpensive(B)<< std::endl;


    return 0;
 }