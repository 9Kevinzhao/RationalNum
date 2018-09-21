/*create the strucuture for a rational number
*  value: type float: the quotient of two ints
*  numerator: type int: the top
*  denominator: type int: the bottom
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct RationalNum {
    int numerator;
    int denominator;
    double value;
};

//function for adding rational numbers
struct RationalNum add(struct RationalNum a, struct RationalNum b){
    //store values in temporary variables
    //do math
    //create a new struct
    //return the new struct
    int num=a.numerator*b.denominator+b.numerator*a.denominator;
    int deno=a.denominator*b.denominator;
    double value=num/deno;
    struct RationalNum c = {num,deno,value};
    return c;
    printf("%f\n",value );
}

//function for subtracting rational numbers
struct RationalNum subtract(struct RationalNum a, struct RationalNum b){
  int num=a.numerator*b.denominator-b.numerator*a.denominator;
  int deno=a.denominator*b.denominator;
  double value=num/deno;
  struct RationalNum c = {num,deno,value};
  return c;
}

//function for multiplying rational numbers
struct RationalNum multiply(struct RationalNum a, struct RationalNum b ){
  int num=a.numerator*b.numerator;
  int deno=a.denominator*b.denominator;
  double value=num/deno;
  struct RationalNum c = {num,deno,value};
  return c;
}

//function for dividing rational numbers
//cannot divide by zero
struct RationalNum divide(struct RationalNum a, struct RationalNum b ){
  if(b.value==0){

  }
  int num=a.numerator*b.denominator;
  int deno=a.denominator*b.numerator;
  double value=num/deno;
  struct RationalNum c = {num,deno,value};
  return c;
}
//simple simplify
struct RationalNum simplify(struct RationalNum a, struct RationalNum b ){

  int num=a.numerator/b.numerator;
  int deno=a.denominator/b.denominator;
  double value=num/deno;
  struct RationalNum c = {num,deno,value};
  printf("simplify is now %i/ %i\n",c.numerator,c.denominator);
  return c;
}

//function for adding rational numbers
struct RationalNum reduce(struct RationalNum a){
//  int limit =0;
int factor=1;
boo flag=true;
      if(a.numerator>a.denominator){
        for(int i=2;i<=a.denominator;i++){
          printf("i is now %i\n",i);
          if(a.numerator % i==0 && a.denominator % i==0){
            struct RationalNum h={i,i,0};
            return reduce(simplify(a,h));
          }
        }
      }
      else{
        for(int i=2;i<=a.numerator;i++){
          printf("i is now %i %i\n",i,a.numerator);
          if(a.numerator % i==0 && a.denominator % i==0){
            struct RationalNum h={i,i,0};
            return reduce(simplify(a,h));
          }
        }
      }


}

int main(){
  struct RationalNum c = {24,12,0.75};
  struct RationalNum d = {4,2,2};
  struct RationalNum result = multiply(c,d);

  printf("\n%d",result.numerator);
  printf("\n--");
  printf("\n%d", result.denominator);
  printf("\n--after reduced");
  struct RationalNum reduced = reduce(c);
  printf("\n--");
  printf("\n%d",reduced.numerator);
  printf("\n--");
  printf("\n%d", reduced.denominator);

}
