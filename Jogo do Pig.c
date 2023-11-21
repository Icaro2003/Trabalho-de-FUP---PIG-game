#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Lancar_Dado();
void Lancar_Dado_PC();

int main (){

int Dado_Player;
int Dado_PC;
int resultado_P = 0;
int resultado_PC = 0;
int select;

while(1){
scanf("%d",&select);

switch(select){
case 1:
Lancar_Dado(&Dado_Player);

if(Dado_Player==1){
resultado_P = 0;
printf("Zerou!\n");
Lancar_Dado_PC(&Dado_PC,&resultado_PC);
}
else if(resultado_P<100){
printf("%d\n",Dado_Player);
resultado_P += Dado_Player;
}
else if(resultado_P==100){
printf("Player ganhou!");
}
else if(resultado_PC==100){
printf("Pc ganhou!");
}

break;
}
}





}

Lancar_Dado(int*Dado){

srand(time(NULL));

*Dado = (rand()%10)+1;

if(*Dado>6){
*Dado = 1;
}

}

Lancar_Dado_PC(int*dado_PC, int*result_PC){

while(*result_PC < 20){
srand(time(NULL));

*dado_PC = (rand()%12)+1;
if(*dado_PC>6){
*dado_PC = 1+rand()%(6-1+1);
}
*result_PC += *dado_PC;
 printf("%d\n",*dado_PC);
 if(*dado_PC == 1){
  *result_PC = 0;
  printf("Zerou!\nOtaro");
  break;
 }

}

}


