#include <iostream>
#include <string> 
#include "upDate.h"



using namespace std;
int upDate :: count = 0;
int Greg2Julian(int *dptr){
  int I = dptr[2];
  int J = dptr[0];
  int K = dptr[1];
  int JD = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
  
  return JD;       
};

void Julian2Greg(int JD, int *dptr){
  int L= JD+68569;
  int N= 4*L/146097;
  L= L-(146097*N+3)/4;
  int I= 4000*(L+1)/1461001;
  L= L-1461*I/4+31;
  int J= 80*L/2447;
  int K= L-2447*J/80;
  L= J/11;
  J= J+2-12*L;
  I= 100*(N-49)+I+L;

 
  dptr[0] = J;//month
  dptr[1] = K;//day
  dptr[2] = I;//year

};


upDate :: upDate(){
  dptr = new int[3];
  dptr[0] = 5;
  dptr[1] = 11;
  dptr[2] = 1959;
  count++;
};


upDate :: upDate(int m, int d, int y){
  dptr = new int[3];
  dptr[0] = m;
  dptr[1] = d;
  dptr[2] = y;
  count++;
};

upDate :: upDate(int j){
  dptr = new int[3];
  Julian2Greg(j, dptr);
  count++;
};

upDate :: ~upDate(){
  //get from lab
  delete[] dptr;
  count--;
};
upDate :: upDate(const upDate &C){
  dptr = new int[3];
  dptr[0] = C.dptr[0];
  dptr[1] = C.dptr[1];
  dptr[2] = C.dptr[2];
  count++;
};


int upDate :: julian(){
  return Greg2Julian(dptr);
};

void upDate :: setDate(int m, int d, int y){
  dptr[0] = m;
  dptr[1] = d;
  dptr[2] = y;
};

int upDate :: getMonth() const {
  return dptr[0];
};
int upDate :: getYear() const {
  return dptr[2];
};
int upDate :: getDay()const{
  return dptr[1];
};
upDate upDate:: operator=(upDate C){
dptr[0] = C.dptr[0];
dptr[1] = C.dptr[1];
dptr[2] = C.dptr[2];
return C;
};
// upDate upDate:: operator=(int *p[]){
//   *fullDate = *p;
//   *M = *fullDate[0];
//   *D = *fullDate[1];
//   *Y = *fullDate[2];
//   return *this;
// };
bool upDate :: operator==(upDate C){
  return(dptr[0] == C.dptr[0] & dptr[1] == C.dptr[1] && dptr[2] == C.dptr[2]);
};
// upDate operator-(int n, upDate C){
//   upDate temp = C;
//   Julian2Greg((Greg2Julian(C.dptr) - n), C.dptr);
//   return C;
// };
upDate operator-(upDate C, int n){
  Julian2Greg((Greg2Julian(C.dptr) - n), C.dptr);
  return C;
};

int operator-(upDate C, upDate E){
  if (Greg2Julian(C.dptr) > Greg2Julian(E.dptr)){
    return(Greg2Julian(C.dptr)-Greg2Julian(E.dptr));
  }
  else{
    return(Greg2Julian(E.dptr)-Greg2Julian(C.dptr));
  }
};

upDate upDate :: operator+(int n){
  upDate temp = *this;
  Julian2Greg((Greg2Julian(temp.dptr) + n), temp.dptr);
  return temp;
  
};
upDate operator+(int n, upDate C){
  return C+n;
};

upDate upDate :: operator+=(int n){
  upDate temp = *this;
  Julian2Greg((Greg2Julian(temp.dptr) + n), temp.dptr);
  return temp;

};
upDate upDate :: operator-=(int n){
  upDate temp = *this;
  Julian2Greg((Greg2Julian(temp.dptr) - n), temp.dptr);
  return temp;

};
upDate upDate :: operator++(){
  Julian2Greg((Greg2Julian(this->dptr) + 1), this->dptr);
  return *this;
};
upDate upDate :: operator++(int n){
  Julian2Greg((Greg2Julian(this->dptr) + 1), this->dptr);
  return *this;
};
upDate upDate :: operator--(){
  Julian2Greg((Greg2Julian(this->dptr) - 1), this->dptr);
  return *this;
};
upDate upDate :: operator--(int n){
  Julian2Greg((Greg2Julian(this->dptr) - 1), this->dptr);
  return *this;
};
bool upDate :: operator<(upDate C){
  return (Greg2Julian(dptr) < Greg2Julian(C.dptr));
};
bool upDate :: operator>(upDate C){
return (Greg2Julian(dptr) > Greg2Julian(C.dptr));
};

istream& operator>>(istream& input, upDate &C){
  int Month, Day, Year;
  char seperator;
  input>>Month;
  input.get(seperator);
  input>>Day;
  input.get(seperator);
  input>>Year;
  C.dptr[0] = Month;
  C.dptr[1] = Day;
  C.dptr[2] = Year;
  return input;
};
ostream &operator<<(ostream &output, const upDate &C){
  
  output << C.getMonth() << "/" << C.getDay() << "/" << C.getYear();
  return output;
};

int upDate :: GetDateCount(){
  return count;
};












