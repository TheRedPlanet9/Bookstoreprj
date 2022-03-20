#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "input.h"
#include "Bookstore.h"

using namespace std;

string Bookstore::Book::ReturnName(){
    return name;
}

Bookstore::Bookstore():Generator(time){
    for (int i = 0; i < 7; i++)
    {
        AddBook();
    }
    
}

int Bookstore::AddBook(){
    
    uniform_int_distribution<int> BookType(0,4);
    
    switch (BookType(Generator))
    {
    case 0:
        books.push_back(Book("Harry Potter", "JK Rowling", 2000, 12.99));
        return 0;
    case 1:
        books.push_back(Book("Percy Jackson", "Rick Riordan", 2012, 15.99));
        return 0;
    case 2:
        books.push_back(Book("To Kill a mockingbird", "Harper Lee", 1960, 9.99));
        return 0;
    case 3:
        books.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925, 23.99));
        return 0;
    case 4:
        books.push_back(Book("A Tour of C++", "Bjarne Stroustrup", 2013, 45.99));
        return 0;
    }
    

}
string Bookstore::BookBoughtCustomer(){
    uniform_int_distribution<int> secondsPassed(0,4);
    sleep(secondsPassed(Generator));
    uniform_int_distribution<int> BuyRate(1,100);
    if(BuyRate(Generator)<=3*books.size()){
        uniform_int_distribution<int> bookNum(0,books.size());
        int NumBook = bookNum(Generator);
        string BookTitle = books[NumBook-1].ReturnName();
        earnings += books[NumBook-1].ReturnPrice();
        books.erase(books.begin()+NumBook);
        return BookTitle;
    }
}
void Bookstore::CrateOfBoooks(){
    if (earnings>=15){
        earnings -= 15;
        uniform_int_distribution<int> BooksInCrate(0,4);
        int numBooks = BooksInCrate(Generator);
        for (int i; i <= numBooks; i++){
            AddBook();
        } 
    }
}
void Bookstore::day(){
    std::chrono::time_point<std::chrono::system_clock> now;
    uniform_real_distribution<float> ThingInDay(0,1);
    bool bookorder = false;
    for (int i = 0; i < 24; i++)
    {
        if (bookorder || ThingInDay(Generator) <= 0.75f){
            BookBoughtCustomer();
            std::cout << "A customer came in!\n";
            cout <<"Our earnings are"<< earnings<< std::endl;
            
        } else {
            std::chrono::time_point<std::chrono::system_clock> now =
        std::chrono::system_clock::now();
            bookorder = true;
        }
        if(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now()-now).count()>=30){
            bookorder = false;
        }
    } 
    
    


    
}
