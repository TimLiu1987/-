#include <iostream>
#include <string>
using namespace std;

int main(int argc, _TCHAR* argv[])

{int type=4,money=3000;

int card[52]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52}; 

char* scard[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

char* kind[4]={"黑桃","紅心","方塊","梅花"};

//char* fcard[52];

int j=0,i=0,k=0;

int temp=0;

char name[10];

srand((unsigned)time(NULL));

for(i = 0; i < 100; i++)

{

j = rand() % 52;

k = rand() % 52;

swap(card[j],card[k])

}