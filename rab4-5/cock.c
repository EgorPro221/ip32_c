#include <stdio.h>
typedef union{
    float lemon;
    int lime_pieces;
}lemon_lime;
typedef struct{
    float tequila;
    float cointreau;
    lemon_lime citrus;
}margarita;
int main()
{
    margarita m ={2.0, 1.0, {2}};
    printf("%2.1f порции текилы\n%2.1f порция куантро\n%2.1f порция сока \n", m.tequila,m.cointreau,m.citrus.lemon);
    
    margarita a ={2.0, 1.0, {0.5}};
    printf("%2.1f порции текилы\n%2.1f порция куантро\n%2.1f порция сока\n", a.tequila,a.cointreau,a.citrus.lemon);  
        
    margarita d ={2.0, 1.0, {.lime_pieces=1}};
    printf("%2.1f порции текилы\n%2.1f порция куантро\n%2.1f кусочек лайма\n", d.tequila,d.cointreau,d.citrus.lemon);    
}