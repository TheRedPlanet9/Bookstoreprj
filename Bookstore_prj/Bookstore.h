#ifndef Bookstore_h
#define Bookstore_h
#include <string>
#include <chrono>
#include <vector>
#include<random>



class Bookstore{
    
    protected:
    class Book{
    protected:
    std::string name;
    int publish_year;
    std::string author;
    double price;
    public:
    Book(std::string bname, std::string bauthor, int bpyear, double bprice) : 
    name(bname), author(bauthor), publish_year(bpyear), price(bprice) {};
    long double ReturnPrice(){return price;}
    string ReturnName();
    };

    unsigned long long time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::vector<Book> books;
    long double earnings;
    
    
    std::mt19937 Generator;
    
    public:
    Bookstore();
    private:
    int AddBook();
    string BookBoughtCustomer();
    void CrateOfBoooks();
    public:

    void day();

     
    
    
};


#endif // Bookstore_h