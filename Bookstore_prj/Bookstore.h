#ifndef Bookstore_h
#define Bookstore_h
#include <string>
#include <chrono>
#include <vector>
#include<random>
#include <termios.h>
#include <sys/ioctl.h>

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
};

class Bookstore{
    
    protected:
    unsigned long long time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::vector<Book> books;
    long double earnings;
    std::random_device rd{};
    
    std::mt19937 Generator;
    
    public:
    Bookstore();
    private:
    int AddBook();
    void BookBoughtCustomer();
    void CrateOfBoooks();
    public:

    void day();

     
    
    
};

// non-blocking getch() for unix systems
static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(1);
}




bool kbhit()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}
char Input(){
    if(kbhit()){
        return getch();
    } else {
        return 0;
    }
}
#endif // Bookstore_h