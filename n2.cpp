#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <locale.h>	
struct familia{
	char tipo_cidadao[20],beneficiario[20];
	int tc,bnf,tm,r;
	float rp;
	char qt3[10];
};
float prm,pac,pn;
void preencher(int n, familia*x){
	for(int i=0;i<n;i++){
		x[i].tm=rand()%6+1;
		x[i].tc=rand()%4;
		x[i].bnf=rand()%4+1;
		x[i].r=rand()%3550+450;
		
	if(x[i].tc==0){
		sprintf(x[i].tipo_cidadao,"CLT");
	}
	if(x[i].tc==1){
		sprintf(x[i].tipo_cidadao,"ConPS");
	}
	if(x[i].tc==2){
		sprintf(x[i].tipo_cidadao,"TrInf");
	}
	if(x[i].tc==3){
		sprintf(x[i].tipo_cidadao,"MEI");
	}
	
	if(x[i].bnf==1){
		sprintf(x[i].beneficiario,"1"); //Bolsa família
	}
	if(x[i].bnf==2){
		sprintf(x[i].beneficiario,"2");//Seguro Desemprego
	}
	if(x[i].bnf==3){
		sprintf(x[i].beneficiario,"3");//bnfpre / rendtrib
	}
	if(x[i].bnf==4){
		sprintf(x[i].beneficiario,"4");//nenhum
	}
}
}

void imprime(int n, familia*x){
	for(int i=0;i<n;i++){
			printf("%d\t%d\t%s\t%s\t  %d\t%.0f\t%s\n",i+1001,x[i].tm,x[i].tipo_cidadao,x[i].beneficiario,x[i].r,x[i].rp,x[i].qt3);
	}
	printf("Percentual de Solicitantes com renda familiar acima de meio salário mínimo por pessoa: %.2f%%\n",prm);
	printf("Percentual de solicitações aceitas com o Bolsa Família: %.2f%%\n",pac);
	printf("Percentual de solicitações Negadas por já estarem recebendo outros benefícios %.2f%%",pn);
	
}
	
void renda_pessoa(int n, familia*x){
	for(int i=0;i<n;i++){
		x[i].rp=x[i].r/x[i].tm;
		}
}
	
void q3(int n, familia*x){
	for(int i=0;i<n;i++){
		if(x[i].rp>522.5 or x[i].r>=3135 or x[i].bnf==2 or x[i].bnf==3 ){
			sprintf(x[i].qt3,"Nao aceito");
		}
		else
		if(x[i].r<=522.5 or x[i].rp<=3135 or x[i].tc==2 or x[i].tc==1 or x[i].tc==3 ){
			sprintf(x[i].qt3,"Aceito");
		}
	}
}

void q4(int n, familia*x){
	float crp=0;
	for(int i=0;i<n;i++){
		if(x[i].rp>522.5){
			crp++;
		}
	}
	prm=(crp/75)*100;
}

void q5(int n, familia*x){
	float totnegado=0,totn=0,totac=0,totaceito=0;
	for(int i=0;i<n;i++){
		if(x[i].rp>522.5 or x[i].r>=3135 or x[i].bnf==2 or x[i].bnf==3 ){
			totn++;
			if(x[i].bnf==2 or x[i].bnf==3){
				totnegado++;
			}
		}
		if(x[i].r<=522.5 or x[i].rp<=3135 or x[i].tc==2 or x[i].tc==1 or x[i].tc==3 ){
			totac++;
			if(x[i].bnf==1){
				totaceito++;
			}
		}
	}
	pac=(totaceito/totac)*100;
	pn=(totnegado/totn)*100;
}
/*
void gravacao(int n, familia*x){
	FILE*arqptr; //abrindo um prototipo
	//abrindo arquivo
	arqptr=fopen("Arqn2.txt","w"); //gravo o arquivo
	//Se nao abrir o arquivo retornar printf
	if(arqptr==NULL){
		printf("ERRO NO ARQUIVO\n");
		printf("SAINDO DO PROGRAMA");
		system("pause");
		exit(1);//abortar programa
	}
	int i;
	//fprintf é uma f#unção utilizada para imprimir cadeia de caracteres formatadas em um fluxo.
	for(int i=0;i<n;i++){
			fprintf(arqtr,"%d\t%d\t%s\t%s\t  %d\t%.0f\t%s\n",i+1001,x[i].tm,x[i].tipo_cidadao,x[i].beneficiario,x[i].r,x[i].rp,x[i].qt3);
	}
	fprintf(arqtr,"Percentual de Solicitantes com renda familiar acima de meio salário mínimo por pessoa: %.2f%%\n",prm);
	fprintf(arqtr,"Percentual de solicitações aceitas com o Bolsa Família: %.2f%%\n",pac);
	fprintf(arqtr,"Percentual de solicitações Negadas por já estarem recebendo outros benefícios %.2f%%",pn);
	fclose(arqptr);
}*/

main(){
	srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    printf("Código  Membros Tipo \tBenefício Renda Renda/p\tSituação da solicitação\n");
    familia x[75];
    preencher(75,x);
    renda_pessoa(75,x);
    q3(75,x);
    q4(75,x);
    q5(74,x);
    imprime(75,x);
    gravacao(75,x);
}
