#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(void) {
    int i,j,x, aleatorio, condicao, maxLinha, maxColum, intervaloAleatorio, numTotal, maior, menor, lMaior, lMenor,Total;
	int sorteio[5000][6];
	int listQDN[59]; //QDN Quantidade de Numero
	int listSUP[59]; //Lista Suporte

	maxLinha = 5000;
	maxColum = 6;
	intervaloAleatorio = 60;
	condicao = 1;
  	srand( (unsigned)time(NULL) );

	
	printf("TRABALHO DOS ALUNOS:/n");
	printf("THIAGO KIM NAKAMURA                 RA:3018200068/n");
	printf("MATHEUS DA FONSECA SOBRAL           RA:3018201165/n");
	printf("CAIO FELLIPE DA SILVA BARROS        RA:3018200619/n");
    printf("HENRIQUE DECARLI TAVARES            RA:3018201113/n");
    printf("VANESSA CAMBUY PEREIRA              RA:3019113022/n");
    printf("THAIS NUNES CARLOS                  RA:3018200367/n");
    printf("RAQUEL MASSAROPE                    RA:/n");
    
    
	printf("\n\n1) Gerando os sorteios aleatorios cada um com 6 numeros unicos:\n");
  	printf("Pressione qualquer tecla para continuar.\n\n");
  	getch();
  
	for( i = 0; i < maxLinha; i++ ){
		printf("%05d  --  ",i+1);
		for( j = 0; j < maxColum; j++ ){

			aleatorio=1+(rand() % intervaloAleatorio);
			
			for( x = j+1; x > -1; x--){
				if( aleatorio == sorteio[i][x]){
					aleatorio = 1 + (rand() % intervaloAleatorio);
					x = j;
				}
			}	
			sorteio[i][j] = aleatorio;
  			printf("%02d ", sorteio[i][j]);
		} 
		printf("\n");  
	}

	
	printf("\n\n2.a) Quantidade de vezes que cada numero saiu nos sorteios: \n\n");
	printf("Pressione qualquer tecla para continuar.\n\n");
	getch();
	
	numTotal =0;
	
	for(x=1;x<=60;x++){
		for( i = 0; i < maxLinha; i++ ){
			for( j = 0; j < maxColum; j++ ){
				if(sorteio[i][j] == x){
					numTotal = numTotal+1;
				}
			}
		}
		
		printf("Numero %02d = %02d\n",x,numTotal);
		listQDN[x-1]=numTotal;
		numTotal = 0;
	}	

	printf("\n\n2.b) 15 duplas que mais sairam nos sorteios: \n\n");
	printf("Pressione qualquer tecla para continuar.\n\n");
	getch();
	
	for(x=0;x<=59;x++){
	listSUP[x] = listQDN[x];
	}
	
	maior=0;
	menor=0;
	
	for(x=1;x<=15;x++){
		for(i=0;i<=59;i++){
			if(listSUP[i]>maior && lMaior != i){
				maior = listSUP[i];
				lMaior = i;
				i=0;
			}
			else{
				if(listSUP[i]>menor && lMaior != i){
				menor = listSUP[i];
				lMenor = i;
				i=0;
				}
			}
		}
		listSUP[lMaior] = 0;
		listSUP[lMenor] = 0;
		Total = maior + menor;
		printf("\nDupla %02d - Numeros %02d,%02d = %02d vezes\n",x,lMaior+1, lMenor+1,Total);
		maior=0;
		menor=0;
	}
	
	
	printf("\n\n2.c) 15 numeros unicos que mais sairam nos sorteios: \n\n");
	printf("Pressione qualquer tecla para continuar.\n\n");
	getch();
	
	for(x=0;x<=59;x++){
	listSUP[x] = listQDN[x];
	}
	
	maior=0;
	
	for(x=1;x<=15;x++){
		for(i=0;i<=59;i++){
			if(listSUP[i]>maior){
				maior = listSUP[i];
				lMaior = i;
			}
		}
		listSUP[lMaior] = 0;
		printf("\n%02d - Numero %02d = %02d vezes\n",x,lMaior+1, maior);
		maior=0;
	}
	
	
	printf("\n\n2.d) Listando a quantidade de jogadas desde a ultima vez que o numero foi sorteado:\n");
  	printf("Pressione qualquer tecla para continuar.\n\n");
  	getch();
  
  	condicao = 0;
  	numTotal = 0;
  	
  	for(x=1;x<=60;x++){
	  	for( i = 0; i < maxLinha; i++ ){	
			for( j = 0; j < maxColum; j++ ){
				if(sorteio[i][j] == x){
					condicao = 1;
				}
			} 
			if(condicao == 1){
				numTotal = 0;
				condicao = 0;
			}
			else{
				numTotal++;
			}
			
		}
		printf("Numero %02d, nao sai a %02d sorteios seguidos\n",x,numTotal);
		numTotal = 0;
		condicao = 0;
	}
	
  	printf("\n\n3) Simular uma jogada para 3 usuarios diferentes:\n");
  	printf("Pressione qualquer tecla para continuar.\n\n");
  	getch();
  	
  	int tamanho;
  	
	//apostador 1
  	char nome1[50];
  	char cpf1[20];
  	int aposta1[5];
  	
  	condicao = 0;
  	
  	printf("\n\n------------- PRIMEIRO APOSTADOR -------------\n");
  	printf("\nDigite o nome do primeiro apostador:\n");
  	fflush(stdin);
	gets(nome1);
  	while(condicao == 0){
	    printf("\n\nDigite o CPF primeiro apostador, sem pontos ou tracos:\n");
  		scanf("%s", cpf1);
  		tamanho = strlen(cpf1);
		if(tamanho == 11){
			condicao = 1;
			printf("CPF registrado com SUCESSO !!!\n");
		}
		else{
		printf("CPF INVALIDO !!!\n");	
		}
	}
  
  	printf("\n\n-------- VAMOS AS APOSTAS, NUMEROS TEM QUE SER DE 0 A 60 SEM REPETIR --------\n");
  	printf("BOA SORTE !!!\n");
  	
	for(x=0;x<=5;x++){
	  	printf("\nDigite o numero %d\n", x+1);
		scanf("%d", &aposta1[x]);
		if(aposta1[x] >=1 && aposta1[x] <=60){
			for( i = 0; i <= x; i++){
				if(aposta1[x] == aposta1[i-1]){
					printf("NUMERO INVALIDO !!!\n");
					printf("NAO PODE SER REPETIDO\n");
					x--;
					i=-1;
				}
			}				
		}
		else{
			printf("NUMERO INVALIDO !!!\n");
			printf("TEM QUE SER ENTRE 1 E 60\n");
			x--;
		}
  	}
  	
	
		
	//apostador 2
  	char nome2[50];
  	char cpf2[20];
  	int aposta2[5];
  	
  	condicao = 0;
  	
  	printf("\n\n------------- SEGUNDO APOSTADOR -------------\n");
  	printf("\nDigite o nome do segundo apostador:\n");
  	fflush(stdin);
	gets(nome2);
  	while(condicao == 0){
	    printf("\n\nDigite o CPF segundo apostador, sem pontos ou tracos:\n");
  		scanf("%s", cpf2);
  		tamanho = strlen(cpf2);
		if(tamanho == 11){
			condicao = 1;
			printf("CPF registrado com SUCESSO !!!\n");
		}
		else{
		printf("CPF INVALIDO !!!\n");	
		}
	}
	
	printf("\n\n-------- VAMOS AS APOSTAS, NUMEROS TEM QUE SER DE 0 A 60 SEM REPETIR --------\n");
  	printf("BOA SORTE !!!\n");  
	for(x=0;x<=5;x++){
	  	printf("\nDigite o numero %d\n", x+1);
		scanf("%d", &aposta2[x]);
		if(aposta2[x] >=1 && aposta2[x] <=60){
			for( i = 0; i <= x; i++){
				if(aposta2[x] == aposta2[i-1]){
					printf("NUMERO INVALIDO !!!\n");
					printf("NAO PODE SER REPETIDO\n");
					x--;
					i=-1;
				}
			}				
		}
		else{
			printf("NUMERO INVALIDO !!!\n");
			printf("TEM QUE SER ENTRE 1 E 60\n");
			x--;
		}
  	}

  	
  	
	//apostador 3
  	char nome3[50];
  	char cpf3[20];
  	int aposta3[5];
  	
  	condicao = 0;
  	
  	printf("\n\n------------- TERCEIRO APOSTADOR -------------\n");
  	printf("\nDigite o nome do terceiro apostador:\n");
  	fflush(stdin);
	gets(nome3);
  	while(condicao == 0){
	    printf("\n\nDigite o CPF terceiro apostador, sem pontos ou tracos:\n");
  		scanf("%s", cpf3);
  		tamanho = strlen(cpf3);
		if(tamanho == 11){
			condicao = 1;
			printf("CPF registrado com SUCESSO !!!\n");
		}
		else{
		printf("CPF INVALIDO !!!\n");	
		}
	}
  
  	printf("\n\n-------- VAMOS AS APOSTAS, NUMEROS TEM QUE SER DE 0 A 60 SEM REPETIR --------\n");
  	printf("BOA SORTE !!!\n");
	for(x=0;x<=5;x++){
	  	printf("\nDigite o numero %d\n", x+1);
		scanf("%d", &aposta3[x]);
		if(aposta3[x] >=1 && aposta3[x] <=60){
			for( i = 0; i <= x; i++){
				if(aposta3[x] == aposta3[i-1]){
					printf("NUMERO INVALIDO !!!\n");
					printf("NAO PODE SER REPETIDO\n");
					x--;
					i=-1;
				}
			}				
		}
		else{
			printf("NUMERO INVALIDO !!!\n");
			printf("TEM QUE SER ENTRE 1 E 60\n");
			x--;
		}
  	}
  	
  	
  	printf("\n\n4) Indicando quantos numeros cada usuario acertou:\n");
  	printf("Pressione qualquer tecla para continuar.\n\n");
  	getch();
  	
  	int linha;
  	
  	//apostador 1
  	linha = 0;
  	maior = 0;
  	menor = 0;
  	for( i = 0; i < maxLinha; i++ ){
		for( j = 0; j < maxColum; j++ ){
			for(x=0; x<6; x++){
				if(sorteio[i][j] == aposta1[x]){
					menor++;
				}
			}			
		}
		if(menor>maior){
			maior = menor;
			linha = i+1;
			
		}
		menor = 0; 
	}
	
	printf("\n\nPARABENS %s, VOCE ACERTOU %02d NUMEROS! SORTEIO [%02d]\n", nome1, maior, linha);
	
  	
  	//apostador 2
  	linha = 0;
  	maior = 0;
  	menor = 0;
  	for( i = 0; i < maxLinha; i++ ){
		for( j = 0; j < maxColum; j++ ){
			for(x=0; x<6; x++){
				if(sorteio[i][j] == aposta2[x]){
					menor++;
				}
			}			
		}
		if(menor>maior){
			maior = menor;
			linha = i+1;
			
		}
		menor = 0; 
	}
	
	printf("\n\nPARABENS %s, VOCE ACERTOU %02d NUMEROS! SORTEIO [%02d]\n", nome2, maior, linha);
	
  	
  	//apostador 3
  	linha = 0;
  	maior = 0;
  	menor = 0;
  	for( i = 0; i < maxLinha; i++ ){
		for( j = 0; j < maxColum; j++ ){
			for(x=0; x<6; x++){
				if(sorteio[i][j] == aposta3[x]){
					menor++;
				}
			}			
		}
		if(menor>maior){
			maior = menor;
			linha = i+1;
			
		}
		menor = 0; 
	}
	
	printf("\n\nPARABENS %s, VOCE ACERTOU %02d NUMEROS! SORTEIO [%02d]\n", nome3, maior, linha);
	
  	
	return 0;
}

