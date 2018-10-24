#include <stdio.h>
#include <stdlib.h>

char matriz[12][13];
int inicioLinha;
int inicioColuna;
int fimLinha; 
int fimColuna;


void lerMapa(){
	FILE* f;
	f = fopen("mapa.txt", "r");

	if (f == 0){
		exit(1);
	}

	for (int i = 0; i < 12; ++i){
		fscanf(f, "%s", matriz[i]);
	}

	fclose(f);
}

void imprimeMapa(){
	for (int i = 0; i < 12; ++i){
		printf("%s\n", matriz[i]);
	}
}

void achaInicio(){
	for (int i = 0; i < 12; ++i){
		if (matriz[i][0] == '.'){
			matriz[i][0] = 'X';
			inicioLinha = i;
			inicioColuna = 0;
			return;
		}
	}
}

void achaFim(){
	for (int i = 0; i < 12; ++i){
		if (matriz[i][11] == '.'){
			fimLinha = i;
			fimColuna = 11;
			return;
		}
	}
}

void move(){
	if (matriz[inicioLinha][inicioColuna-1] == '.'){
		matriz[inicioLinha][inicioColuna-1] = 'x';
		inicioColuna--;
	}else if (matriz[inicioLinha][inicioColuna+1] == '.'){
		matriz[inicioLinha][inicioColuna+1] = 'x';
		inicioColuna++;
	}else if (matriz[inicioLinha+1][inicioColuna] == '.'){
		matriz[inicioLinha+1][inicioColuna] = 'x';
		inicioLinha++;
	}else if (matriz[inicioLinha-1][inicioColuna] == '.'){
		matriz[inicioLinha-1][inicioColuna] = 'x';
		inicioLinha--;	
	}else if (matriz[inicioLinha][inicioColuna+1] == 'x'){
		matriz[inicioLinha][inicioColuna+1] = '.';
		inicioColuna++;
	}else if (matriz[inicioLinha-1][inicioColuna] == 'x'){
		matriz[inicioLinha-1][inicioColuna] = '.';
		inicioLinha--;
	}else if (matriz[inicioLinha+1][inicioColuna] == 'x'){
		matriz[inicioLinha+1][inicioColuna] = '.';
		inicioLinha++;	
	}else if (matriz[inicioLinha][inicioColuna-1] == 'x'){
		matriz[inicioLinha][inicioColuna-1] = '.';
		inicioColuna--;
	}
}

int chegouFim(){
	return inicioLinha == fimLinha && inicioColuna == fimColuna;
}

int main(){
	lerMapa();
	achaInicio();
	achaFim();

	printf("Jogo do Labirinto\n");
	for (int i = 0; i < 1000000000; ++i){}
	
	system("cls");
	while(!chegouFim()){
		imprimeMapa();
		move();
		for (int i = 0; i < 100000000; ++i){}
		system("cls");	
	}
	imprimeMapa();
	printf("Parabéns!!! Você chegou ao fim do jogo.\n");
	
}