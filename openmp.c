#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <omp.h>

void chequearrespuesta(char *celda,char *rescorr,int *cantomi,int *cantcorr,int *cantincorr);

int main(int argc,char *argv[]){

FILE *punteroarchivo;
FILE *punteroarchivonuevo;

char rutaentrada[200];
char rutasalida[200];

printf("Ingrese la ruta del archivo de entrada(ej:/home/usuario/prueba.csv): ");
scanf("%s",rutaentrada);

printf("Ingrese la ruta del archivo de salida(ej:/home/usuario/resultados.csv): ");
scanf("%s",rutasalida);

punteroarchivo = fopen(rutaentrada,"r");
punteroarchivonuevo = fopen(rutasalida,"w");

fputs("\"Identificador de estudiante\";\"Preguntas correctas\";\"Preguntas incorrectas\";\"Preguntas omitidas\";\"Puntaje\";\"Nota\";\n",punteroarchivonuevo);

if(punteroarchivo == NULL)
{
	printf("Problema al abrir el archivo\n");
	exit(0);
}

int flag=0;
int i;

char linea[200];

char idestudiante[40];
char preg1[15];
char preg2[15];
char preg3[15];
char preg4[15];
char preg5[15];
char preg6[15];
char preg7[15];
char preg8[15];
char preg9[15];
char preg10[15];
char preg11[15];
char preg12[15];

char respreg1[5]="\"A\"";
char respreg2[5]="\"E\"";
char respreg3[5]="\"C\"";
char respreg4[5]="\"B\"";
char respreg5[5]="\"B\"";
char respreg6[5]="\"D\"";
char respreg7[5]="\"A\"";
char respreg8[5]="\"B\"";
char respreg9[5]="\"E\"";
char respreg10[5]="\"C\"";
char respreg11[5]="\"B\"";
char respreg12[5]="\"D\"";

int cantcorrecta,cantincorrecta,cantomitida;
float nota,puntaje;

while(fgets(linea,200,punteroarchivo)!= NULL)
{
	char *parte;
	char palabra[120];
	cantcorrecta=0;
	cantincorrecta=0;
	cantomitida=0;
	puntaje=0;
	nota=0.0;

	parte= strtok(linea,";");

	if (flag==0){
		flag+=1;
	}
	else{
			for(i=1;i<14;i++){
				if(i == 1){
				strcpy(idestudiante, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 2){
				strcpy(preg1, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 3){
				strcpy(preg2, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 4){
				strcpy(preg3, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 5){
				strcpy(preg4, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 6){
				strcpy(preg5, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 7){
				strcpy(preg6, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 8){
				strcpy(preg7, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 9){
				strcpy(preg8, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 10){
				strcpy(preg9, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 11){
				strcpy(preg10, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 12){
				strcpy(preg11, parte);
				parte = strtok(NULL,";");
				}
				else if(i == 13){
				strcpy(preg12, parte);
				parte = strtok(NULL,";");
				}
			}
			#pragma omp parallel
			{
			#pragma omp sections
				{
			#pragma omp section
			{
			chequearrespuesta(preg1,respreg1,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta1: %d\n ",omp_get_thread_num());
			}
			 #pragma omp section
			 {
			chequearrespuesta(preg2,respreg2,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta2: %d\n ",omp_get_thread_num());
			}
			 #pragma omp section
			 {
			chequearrespuesta(preg3,respreg3,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta3: %d\n ",omp_get_thread_num());
			}
			 #pragma omp section
			 {
			chequearrespuesta(preg4,respreg4,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta4: %d\n ",omp_get_thread_num());
			}
			 #pragma omp section
			 {
			chequearrespuesta(preg5,respreg5,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta5: %d\n ",omp_get_thread_num());
			}
			 #pragma omp section
			 {
			chequearrespuesta(preg6,respreg6,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta6: %d\n ",omp_get_thread_num());
			}
			#pragma omp section
			{
			chequearrespuesta(preg7,respreg7,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta7: %d\n ",omp_get_thread_num());
			}
			#pragma omp section
			{
			chequearrespuesta(preg8,respreg8,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta8: %d\n ",omp_get_thread_num());
			}
			 #pragma omp section
			 {
			chequearrespuesta(preg9,respreg9,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta9: %d\n ",omp_get_thread_num());
			}
			#pragma omp section
			{
			chequearrespuesta(preg10,respreg10,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta10: %d\n ",omp_get_thread_num());
			}
			#pragma omp section
			{
			chequearrespuesta(preg11,respreg11,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta11: %d\n ",omp_get_thread_num());
			}
			 #pragma omp section
			 {
			chequearrespuesta(preg12,respreg12,&cantomitida,&cantcorrecta,&cantincorrecta);
			printf("numero del thread respuesta12: %d\n ",omp_get_thread_num());
			}
				}
			}
		//printf("cantidad correcta: %d\n",cantcorrecta);
		puntaje=((cantcorrecta*0.5)-(cantincorrecta*0.12));
		nota=1.0 + puntaje;
			
		sprintf(palabra,"%s;\"%d\";\"%d\";\"%d\";\"%f\";\"%0.1f\";\n",idestudiante,cantcorrecta,cantincorrecta,cantomitida,puntaje,nota);	
		fputs(palabra,punteroarchivonuevo);
		}
}
printf("Integrantes: Julio Aceituno, André Vigneau\n");
fclose(punteroarchivo);
fclose(punteroarchivonuevo);

return 0;
	
}

void chequearrespuesta(char *celda,char *rescorr,int *cantomi,int *cantcorr,int *cantincorr){

	if(strcmp(celda,rescorr)==0){
		#pragma omp atomic update
		*cantcorr+=1;
		}	
	else if (strcmp(celda,"\"-\"")==0){
		#pragma omp atomic update
		*cantomi+=1;
		}
	else{
		#pragma omp atomic update
		*cantincorr+=1;
		}	
}
