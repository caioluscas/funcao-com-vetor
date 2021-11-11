#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include <locale.h>
struct empresa {
	char tipo_servico[20];
	int qhr, vs,ts,x;
};
empresa resp_5;
void preencher(int n, empresa*os){
	for(int i=0;i<n;i++){
		os[i].ts=rand()%2+1;
		os[i].qhr=rand()%106+15;
		
		if(os[i].ts==1){
			sprintf(os[i].tipo_servico,"Reparo\t\t");
			os[i].vs=(os[i].qhr*150)+750;
		}
		else
		if(os[i].ts==2){
			sprintf(os[i].tipo_servico,"Manutenção\t");
			os[i].vs=(os[i].qhr*100)+500;
		}
		os[i].x = rand()%1001+1000;

		}
}
float questao3(int n, empresa*os){
	float totr,totr40=0,p40;
	for(int i=0;i<n;i++){
		if(os[i].ts==1){
			totr++;
			if(os[i].qhr<40){
				totr40++;
			}
		}
}
		p40=(totr40/totr)*100;
		return(p40);
}

float questao4(int n, empresa*os){
	float totr=0,tothrr=0,mr;
	for(int i=0;i<n;i++){
		if(os[i].ts==1){
			totr++;
			tothrr+=os[i].qhr;
		}
	}
	mr=tothrr/totr;
	return(mr);
}         

float questao41(int n, empresa*os){
	float totm=0,tothrm=0,mm;
	for(int i=0;i<n;i++){
		if(os[i].ts==2){
			totm++;
			tothrm+=os[i].qhr;
		}
	}
	mm=tothrm/totm;
	return(mm);
}

float questao42(int n, empresa*os){
	float totg=0,tothrg=0,mg;
	for(int i=0;i<n;i++){
		if(os[i].ts==1 or os[i].ts==2){
			totg++;
			tothrg+=os[i].qhr;
		}
	}
	mg=tothrg/totg;
	return(mg);
}
void maior(int n, empresa*os){
	float maior=0;
	for(int i=0;i<n;i++){
		if(os[i].vs>maior){
			maior=os[i].vs;
			resp_5=os[i];
		}
	}
}
void imprimir(int n, empresa*os, float r3, float r4, float r41, float r42){
	for(int i=0;i<n;i++){
		printf("%d\t%s%d\t%d\n",os[i].x,os[i].tipo_servico,os[i].qhr,os[i].vs);
	}
	printf("O percentual de Serviços com duração menor que 40 Horas: %.2f%%",r3);
	printf("\nA média de Horas das OS’s de manutenção: %.2f",r4);
	printf("\nA média de Horas das OS’s de reparo: %.2f",r41);
	printf("\nA média de Horas das OS’s de geral: %.2f",r42);
		printf("\n%d\t%s%d\t%d\n",resp_5.x,resp_5.tipo_servico,resp_5.qhr,resp_5.vs);
}
void gravar(int n, empresa*os, float r3, float r4, float r41, float r42){
	FILE*pont_arq;
	pont_arq=fopen("arquivo_palavra.txt","w");
	if(pont_arq==NULL){
		printf("ARQUIVO COM ERRO!!!");
	}
	for(int i=0;i<n;i++){
		fprintf(pont_arq,"%d\t%s%d\t%d\n",os[i].x,os[i].tipo_servico,os[i].qhr,os[i].vs);
	}
	fprintf(pont_arq,"O percentual de Serviços com duração menor que 40 Horas: %.2f%%",r3);
	fprintf(pont_arq,"\nA média de Horas das OS’s de manutenção: %.2f",r4);
	fprintf(pont_arq,"\nA média de Horas das OS’s de reparo: %.2f",r41);
	fprintf(pont_arq,"\nA média de Horas das OS’s de geral: %.2f",r42);
		fprintf(pont_arq,"\n%d\t%s%d\t%d\n",resp_5.x,resp_5.tipo_servico,resp_5.qhr,resp_5.vs);
		fclose(pont_arq);
}

main(){
	srand(time(NULL));
	fflush(stdin);
	setlocale(LC_ALL, "Portuguese");
	float resp_3;
	float resp_4;
	float resp_41;
	float resp_42;
	float resp_5;
	empresa os[67];
	preencher(67,os);
	resp_3=questao3(67,os);
	resp_4=questao4(67,os);
	resp_41=questao41(67,os);
	resp_42=questao42(67,os);
	maior(67,os);
	imprimir(67,os,resp_3,resp_4,resp_41,resp_42);
	gravar(67,os,resp_3,resp_4,resp_41,resp_42);
	
}
