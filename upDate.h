#ifndef UPDATE_H
#define UPDATE_H
#include <iostream>

using namespace std;

class upDate {

  private:
    int *dptr;
    static int count;
    
  public:
    
    upDate();
    upDate(int M, int D, int Y);
    upDate(int j);
    upDate(const upDate&);
    ~upDate();
    
    void setDate(int M, int Y, int D);
    int getMonth()const;
    int getDay()const;
    int getYear()const;
    int julian();
    string getMonthName();
    

    upDate operator=(upDate C);
    upDate operator=(int *p[]);
    bool operator==(upDate C);
    upDate operator+(int n);    
    upDate operator-=(int n);
    upDate operator+=(int n);
    upDate operator++();
    upDate operator++(int n);
    upDate operator--();
    upDate operator--(int n);
    bool operator<(upDate C);
    bool operator>(upDate C);
    friend ostream &operator << (ostream &out, const upDate &C);
    friend istream &operator >> (istream &input, upDate &C);
    friend int operator-(upDate C, upDate E);
    // friend upDate operator-(int n, upDate C);
    friend upDate operator-(upDate C, int n);
    friend upDate operator+(int n, upDate C);
    static int GetDateCount();
};
#endif 