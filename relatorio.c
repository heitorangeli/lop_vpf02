#include <stdio.h>
#include <windows.h>

#define ml 100
#define mr 50

struct funcionario{
	char nome[50];
	float salario;
	char cargo[100];
};

int main(){
	SetConsoleOutputCP(65001);
	int qtdLinhas = 0;
	float media = 0;
	struct funcionario f[mr];
	FILE *arquivo = fopen("dados.csv", "r");
	if(arquivo == NULL){
		printf("Arquivo não encontrado.\n");
		return 0;
	}
	char linha[ml];
	while(fgets(linha,sizeof(linha),arquivo) != NULL){
		qtdLinhas++;
		if(qtdLinhas > 1){
		sscanf(linha,"%[^,],%[^,],%f", f[qtdLinhas - 2].nome, f[qtdLinhas - 2].cargo, & f[qtdLinhas - 2].salario);
		}
	}
	fclose(arquivo);
	
	printf("Nome\t\t        Salario    \tCargo\n");
	for(int i = 0; i < qtdLinhas - 1; i++){
		printf("%s\t\t%g\t     \t%s\n",f[i].nome, f[i].salario, f[i].cargo);
		media += f[i].salario;
	}
	media = media / (qtdLinhas - 1);
	printf("\nForam analizados %d funcionários.\n", qtdLinhas - 1);
	printf("A média salarial dos funcionários é de %g reais.", media);
}