#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include <locale.h>
struct diagnostico{
	char setor[20];
	char setorzinho[4];
	char tipo[20];
	char sexo[20];
	char retorno[10];
	int x,st,sx,nota,id,re,tp;
};
diagnostico r6;
void preencher(int n, diagnostico*cod){
	for(int i=0;i<n;i++){
		cod[i].x=rand()%100+1001;
		cod[i].st=rand()%3;
		cod[i].id=rand()%53+18;
		cod[i].sx=rand()%2;
		cod[i].nota=rand()%101;
		cod[i].re=rand()%3;
		cod[i].tp=rand()%2;
		
		
		if(cod[i].st==0){
			sprintf(cod[i].setorzinho,"RPL");
			sprintf(cod[i].setor,"Radiologia");
		}
		if(cod[i].st==1){
		sprintf(cod[i].setorzinho,"UTR");
		sprintf(cod[i].setor,"Ultrassom");
		}
		if(cod[i].st==2){
		sprintf(cod[i].setorzinho,"TOM");
		sprintf(cod[i].setor,"Tomografia");
		}
		if(cod[i].tp==0){
		sprintf(cod[i].tipo,"Plano     ");
		}
		if(cod[i].tp==1){
		sprintf(cod[i].tipo,"Particular");
		}
		if(cod[i].sx==0){
		sprintf(cod[i].sexo,"Masculino");
		}
		if(cod[i].sx==1){
		sprintf(cod[i].sexo,"Feminino");
		}
		if(cod[i].re==0){
		sprintf(cod[i].retorno,"Sim");
		}
		if(cod[i].re==1){
		sprintf(cod[i].retorno,"Talvez");
		}
		if(cod[i].re==2){
		sprintf(cod[i].retorno,"Nao");
		}
	}
}
void imprimir(int n, diagnostico*cod, float r3, float r4,float r5){
	for(int i=0;i<n;i++){
		printf("%d%s\t%s\t%s\t%d\t%s\t%d\t%s\n",cod[i].x,cod[i].setorzinho,cod[i].setor,cod[i].tipo,cod[i].id,cod[i].sexo,cod[i].nota,cod[i].retorno);
	}
	printf("Percentual clientes do setor de Radiologia que deu notas maiores que 70: %.2f%%\n",r3);
	printf("A média das notas dadas pelos clientes Particulares: %.0f\n",r4);
	printf("O percentual de clientes do tipo Plano que indicaram que retornariam Não: %.2f%%\n",r5);
	printf(" ------------------dados do atendimento que teve a menor nota-------------------------\n");
	printf("%d%s\t%s\t%s\t%d\t%s\t%d\t%s\n",r6.x,r6.setorzinho,r6.setor,r6.tipo,r6.id,r6.sexo,r6.nota,r6.retorno);
}
void gravar(int n,diagnostico*cod){
	FILE*pont_arq;
	pont_arq=fopen("diagnostico.txt","w");
	if(pont_arq==NULL){
		printf("ARQUIVO COM ERRO!!!");
	}
	for(int i=0;i<n;i++){
		fprintf(pont_arq,"%d%s\t%s\t%s\t%d\t%s\t%d\t%s\n",cod[i].x,cod[i].setorzinho,cod[i].setor,cod[i].tipo,cod[i].id,cod[i].sexo,cod[i].nota,cod[i].retorno);
	}
	fclose(pont_arq);
}

float questao_3(int n,diagnostico*cod){
	float totrad=0,totnt70=0,p70;
	for(int i=0;i<n;i++){
		if(cod[i].st==0){
			totrad++;
			if(cod[i].nota>70){
				totnt70++;
			}
		}
	}
	p70=(totnt70/totrad)*100;
	return(p70);
}
float questao_4(int n,diagnostico*cod){
	float mp, totp=0,np;
	for(int i=0;i<n;i++){
		if(cod[i].tp==1){
			totp++;
			np+=cod[i].nota;
		}
	}
	mp=np/totp;
	return(mp);
}
float questao_5(int n,diagnostico*cod){
	float totp=0, totn=0, pn;
	for(int i=0;i<n;i++){
		if(cod[i].tp==0){
			totp++;
			if(cod[i].re==2){
				totn++;
			}
		}
	}
	pn=(totn/totp)*100;
	return(pn);
}
void menor(int n,diagnostico*cod){
	float menor=0;
	for(int i=0;i<n;i++){
		if(cod[i].nota<menor){
			menor=cod[i].nota;
			r6=cod[i];
		}
	}
}
void gravar2(int n,diagnostico*cod, float r3, float r4,float r5){
	FILE*pont_arq;
	pont_arq=fopen("diagnostico codigo todo.txt","w");
	if(pont_arq==NULL){
		printf("ARQUIVO COM ERRO!!!");
	}
	for(int i=0;i<n;i++){
		fprintf(pont_arq,"%d%s\t%s\t%s\t%d\t%s\t%d\t%s\n",cod[i].x,cod[i].setorzinho,cod[i].setor,cod[i].tipo,cod[i].id,cod[i].sexo,cod[i].nota,cod[i].retorno);
	}
	fprintf(pont_arq,"Percentual clientes do setor de Radiologia que deu notas maiores que 70: %.2f%%\n",r3);
	fprintf(pont_arq,"A média das notas dadas pelos clientes Particulares: %.0f\n",r4);
	fprintf(pont_arq,"O percentual de clientes do tipo Plano que indicaram que retornariam Não: %.2f%%\n",r5);
	fprintf(pont_arq," ------------------dados do atendimento que teve a menor nota-------------------------\n");
	fprintf(pont_arq,"%d%s\t%s\t%s\t%d\t%s\t%d\t%s\n",r6.x,r6.setorzinho,r6.setor,r6.tipo,r6.id,r6.sexo,r6.nota,r6.retorno);
	fclose(pont_arq);
}
main(){
	srand(time(NULL));
	fflush(stdin);
	setlocale(LC_ALL, "Portuguese");
	printf("Código  Setor \t\tTipo \t\tIdade \tSexo \t\tNota \tRetornaria\n");
	float r3;
	float r4;
	float r5;
	float r6;
	diagnostico cod[128];
	preencher(128,cod);
	r3=questao_3(128,cod);
	r4=questao_4(128,cod);
	r5=questao_5(128,cod);
	menor(128,cod);
	imprimir(128,cod,r3,r4,r5);
	gravar(128,cod);
	gravar2(128,cod,r3,r4,r5);
}
