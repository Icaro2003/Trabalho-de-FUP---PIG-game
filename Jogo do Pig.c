#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
int Dado_Player;
int Dado_PC;
}Dado;

typedef struct {
int Resultado_Player;
int Resultado_PC;
}Resultado;

void Lancar_Dado();
void Lancar_Dado_PC();

int main (){
Dado dado;
Resultado resultado;
int select;

while(1){
        
scanf("%d",&select);
system("cls");
switch(select){
case 1:
Lancar_Dado(&dado);

if(dado.Dado_Player==1){
resultado.Resultado_Player = 0;
printf("Zerou!\n");
Lancar_Dado_PC(&dado,&resultado);
}
else if(resultado.Resultado_PC<100){
resultado.Resultado_PC += dado.Dado_Player;
}
else if(resultado.Resultado_Player==100){
printf("Player ganhou!");
}
else if(resultado.Resultado_PC==100){
printf("Pc ganhou!");
}

break;
}
}





}

Lancar_Dado(Dado Pont){

srand(time(NULL));

Pont.Dado_Player = (rand()%10)+1;

if(Pont.Dado_Player>6){
printf("| * |\n");
Pont.Dado_Player = 1;
}else if(Pont.Dado_Player==2){
printf("| * * |\n");
}else if(Pont.Dado_Player==3){
printf("| * * * |\n");
}else if(Pont.Dado_Player==4){
printf("| * * * * |\n");
}else if(Pont.Dado_Player==5){
printf("| * * * * * |\n");
}else if(Pont.Dado_Player==6){
printf("| * * * * * * |\n");
}

}

Lancar_Dado_PC(Dado PC1, Resultado PC2){

while(PC2.Resultado_PC < 20){
srand(time(NULL));

PC1.Dado_PC = (rand()%12)+1;
if(PC1.Dado_PC>6){
PC1.Dado_PC = 1+rand()%(6-1+1);
}
PC2.Resultado_PC += PC1.Dado_PC;


if(PC1.Dado_PC == 1){
  PC2.Resultado_PC = 0;
  printf("| * |\n");
  break;
}

}

}


