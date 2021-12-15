#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
struct prog{
	char tipo_servico[20],urgente[20], tipo_ser[20], mesao[20];
	int ts,tservi, urg, vs, x, hr, mes; 
	float valor;
};
void preencher (int n, prog*cod){
	for(int i=0; i<n; i++){
		cod[i].x = i +1527;
		cod[i].ts = rand()%2;
		cod[i].mes = 0+i;
		cod[i].hr = rand()%91+10;
		cod[i].urg = rand()%2;
		
		if(cod[i].ts==0){
		sprintf(cod[i].tipo_ser,"M");
		sprintf(cod[i].tipo_servico,"Manutenção    ");
		cod[i].vs = cod[i].hr * 120 + 500;
			if(cod[i].urg==0){
				cod[i].vs = (((cod[i].hr * 120 + 500 )*0.3) ) +cod[i].vs;
			
			}
		}
		if(cod[i].ts==1){
		sprintf(cod[i].tipo_ser,"R");
		sprintf(cod[i].tipo_servico,"Reparo    ");
		cod[i].vs = cod[i].hr * 170 + 500;
		if(cod[i].urg==0){
				cod[i].vs = (((cod[i].hr * 170 + 500 )*0.3) ) +cod[i].vs;
			}
		}
		
		if(cod[i].urg==0){
		sprintf(cod[i].urgente,"SIM");
		}
		if(cod[i].urg==1){
		sprintf(cod[i].urgente,"NAO");
		}
		
		if(cod[i].mes<=41){
		sprintf(cod[i].mesao,"Agosto      ");
		}
		if(cod[i].mes>41 && cod[i].mes<=90){
		sprintf(cod[i].mesao,"Setembro");
		}
		if(cod[i].mes>=91){
		sprintf(cod[i].mesao,"Outubro");
		}
		
		
	}
}

void imprimir(int n, prog*cod, int r3, float r4, float r41, float r42, float r5 , float r6){
	for(int i=0; i<n; i++){
		printf("OS%d%s \t%s \t%s \t%d \t%s \t%d\n",cod[i].x,cod[i].tipo_ser,cod[i].mesao,cod[i].tipo_servico,cod[i].hr,cod[i].urgente,cod[i].vs);
	}
	printf("\n MAIOR\n");
	printf("OS%d%s \t%s \t%s \t%d \t%s \t%d\n",cod[r3].x,cod[r3].tipo_ser,cod[r3].mesao,cod[r3].tipo_servico,cod[r3].hr,cod[r3].urgente,cod[r3].vs);
	printf("A média de Horas das OS’s manutenção: %.2f\n",r4);
	printf("A média de Horas das OS’s reparo: %.2f\n",r41);
	printf("A média de Horas das OS’s geral: %.2f\n",r42);
	printf("O percentual de OS´s de reparo com duração menor que 50 Horas: %.2f%%\n",r5);
	printf("O percentual de OS’s que eram urgentes com duração maior que 80 horas: %.2f%%\n", r6);
}
int maior(int n,prog*cod){
	float maior=0;
	int r3 = 0;
	for(int i=0;i<n;i++){
		if(cod[i].vs>maior){
			maior=cod[i].vs;
			r3=i;
		}
	}
	
	return(r3);
}
float questao_4(int n, prog*cod ){
	float totm=0,tothr=0,mhm;
	for(int i=0; i<n; i++){
		if(cod[i].ts==0){
			totm++;
			tothr+=cod[i].hr;
		}
	}
	mhm=tothr/totm;
	return(mhm);
} 

float questao_41(int n, prog*cod ){
	float totr=0,tothr=0,mhr;
	for(int i=0; i<n; i++){
		if(cod[i].ts==1){
			totr++;
			tothr+=cod[i].hr;
		}
	}
	mhr=tothr/totr;
	return(mhr);
}


float questao_42(int n, prog*cod ){
	float totrm=0,tothrm=0,mhrm;
	for(int i=0; i<n; i++){
		if(cod[i].ts==1 or cod[i].ts==0){
			totrm++;
			tothrm+=cod[i].hr;
		}
	}
	mhrm=tothrm/totrm;
	return(mhrm);
}

float questao_5(int n, prog*cod ){
	float tot50=0,p,mhrm;
	for(int i=0; i<n; i++){
		if(cod[i].hr<50){
			if(cod[i].ts==1){
				tot50++;
			}
		}
	}
	p=(tot50/133)*100;
	return(p);
}

float questao_6(int n, prog*cod ){
	float tot80=0,p80,mhrm;
	for(int i=0; i<n; i++){
		if(cod[i].hr>80){
			if(cod[i].urg==0){
				tot80++;
			}
		}
	}
	p80=(tot80/133)*100;
	return(p80);
}

void gravar(int n, prog*cod, int r3, float r4, float r41, float r42, float r5, float r6){
	FILE*pont_arq;
	pont_arq=fopen("PROG FINAL.txt","w");
	if(pont_arq==NULL){
		printf("ARQUIVO COM ERRO!!!");
	}
	for(int i=0;i<n;i++){
	fprintf(pont_arq,"OS%d%s \t%s \t%s \t%d \t%s \t%d\n",cod[i].x,cod[i].tipo_ser,cod[i].mesao,cod[i].tipo_servico,cod[i].hr,cod[i].urgente,cod[i].vs);
	}
	fprintf(pont_arq,"\n MAIOR\n");
	fprintf(pont_arq,"OS%d%s \t%s \t%s \t%d \t%s \t%d\n",cod[r3].x,cod[r3].tipo_ser,cod[r3].mesao,cod[r3].tipo_servico,cod[r3].hr,cod[r3].urgente,cod[r3].vs);
	fprintf(pont_arq,"A média de Horas das OS’s manutenção: %.2f\n",r4);
	fprintf(pont_arq,"A média de Horas das OS’s reparo: %.2f\n",r41);
	fprintf(pont_arq,"A média de Horas das OS’s geral: %.2f\n",r42);
	fprintf(pont_arq,"O percentual de OS´s de reparo com duração menor que 50 Horas: %.2f%%\n",r5);
	fprintf(pont_arq,"O percentual de OS’s que eram urgentes com duração maior que 80 horas: %.2f%%\n", r6);
	fclose(pont_arq);
}

main(){
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	printf("Código          Mês             Tipo            Horas   Urgente Valor\n");
	int r3;
	float r4;
	float r41;
	float r42;
	float r5;
	float r6;
	prog cod[133];
	preencher(133,cod);
	r3=maior(133, cod);
	r4 = questao_4(133, cod);
	r41 = questao_41(133, cod);
	r42 = questao_42(133, cod);
	r5 = questao_5(133, cod);
	r6 = questao_6(133, cod);
	imprimir(133,cod, r3, r4, r41, r42,r5, r6);
	gravar(105,cod, r3, r4, r41, r42, r5, r6);
}
