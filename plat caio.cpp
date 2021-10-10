#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include <locale.h>
struct plataforma{
    char tipo_plataforma[17],tipo_plataforminha[5],campo[10];
    int tp,tform,af,ca,hc,hp;
	int qtdhrs;
	float coef,prod;
};
float mhpss,pmarlim,mprodronc;
plataforma respq_3;
void preencher(int n, plataforma*cod){
    for(int i=0;i<n;i++){
        cod[i].tp=rand()%3+1;
        cod[i].tform=rand()%3+1;
        cod[i].af=rand()%20+2000;
        cod[i].ca=rand()%3+1;
        cod[i].hc=rand()%2;
        cod[i].hp=rand()%3601;
        cod[i].prod=rand()%1501+1000;

    if(cod[i].tform==1){
    	sprintf(cod[i].tipo_plataforminha,"%dFX%.2d",i+101,cod[i].af-2000);
	}
    if(cod[i].tform==2){
    	sprintf(cod[i].tipo_plataforminha,"%dNS%.2d",i+101,cod[i].af-2000);
	}
    if(cod[i].tform==3){
    	sprintf(cod[i].tipo_plataforminha,"%dSS%.2d",i+101,cod[i].af-2000);
	}
    if(cod[i].tp==1){
    	sprintf(cod[i].tipo_plataforma,"Fixa            ");
	}
    if(cod[i].tp==2){
    	sprintf(cod[i].tipo_plataforma,"Navio Sonda     ");
	}
    if(cod[i].tp==3){
    	sprintf(cod[i].tipo_plataforma,"Semi Submersivel");
	}
    if(cod[i].ca==1){
    	sprintf(cod[i].campo,"\tMarlim  ");
	}
    if(cod[i].ca==2){
    	sprintf(cod[i].campo,"\tAlbacora");
	}
    if(cod[i].ca==3){
    	sprintf(cod[i].campo,"\tRoncador");
	}
    if(cod[i].hc==0)cod[i].qtdhrs=8760;
    if(cod[i].hc==1)cod[i].qtdhrs=17520;
    cod[i].coef=(cod[i].prod/(cod[i].qtdhrs-cod[i].hp))*1000;
    }
}

void imprime(int n, plataforma*cod, float r4, float r41, float malb, float mmarlim, float mronc){          //\t
    for(int i=0;i<n;i++){
        printf("%s\t%s\t%d\t%d\t%d\t%.0f\t%.2f\n",cod[i].tipo_plataforminha,cod[i].tipo_plataforma,cod[i].af,cod[i].qtdhrs,cod[i].hp,cod[i].prod,cod[i].coef);
    }
    printf("QUESTAO 2\n");
    printf("A média de Horas paradas das Plataformas do tipo Semi Submersivel: %.2f\n",mhpss);
    printf("QUESTAO 3\n");
    printf("%s\t%s\t%d\t%s\t%d\t%d\t%.0f\t%.2f\n",respq_3.tipo_plataforminha,respq_3.tipo_plataforma,respq_3.af,respq_3.campo,respq_3.qtdhrs,respq_3.hp,respq_3.prod,respq_3.coef);
    printf("QUESTAO 4\n");
	 printf("O percentual de Plataformas dos Campos de marlim menor que 800 de hp: %.2f%%",r4);
	 printf("\nO percentual de Plataformas dos Campos de Roncador menor que 800 de hp: %.2f%%",r41);
	 printf("\nQUESTAO 5");
	 printf("\nA média de produção das plataformas de Marlim: %.2f",mmarlim);
    printf("\nA média de produção das plataformas de Albacora: %.2f",malb);
    printf("\nA média de produção das plataformas de Roncador: %.2f",mronc);
    
}

void media_hp(int n, plataforma*cod){
	float tothpsem=0,totsem=0;
	for(int i=0;i<n;i++){
		if(cod[i].tp==3){
			totsem++;
			tothpsem+=cod[i].hp;
		}
	}
	mhpss=tothpsem/totsem;
}

void questao_3(int n, plataforma*cod){
	float maior=0;
	for(int i=0;i<n;i++){
		if(cod[i].coef>maior){
			maior=cod[i].coef;
			respq_3=cod[i];
		}
	}
}

float questao_4 (int n, plataforma*cod){
	float totm, totmmenor=0,permar;
	for(int i=0;i<n;i++){
		if(cod[i].ca==1){
			totm++;
			if(cod[i].hp<800){
				totmmenor++;
			}
		}
		
	}
	permar=(totmmenor/totm)*100;
	return(permar);
}

float questao_41 (int n, plataforma*cod){
	float totronc,totroncmenor=0, perronc;
	for(int i=0;i<n;i++){
		if(cod[i].ca==3){
			totronc++;
			if(cod[i].hp<800){
				totroncmenor++;
			}
		}
	}
	perronc=(totroncmenor/totronc)*100;
	return(perronc);
}

float media_marlim(int n, plataforma*cod){
	float totmarlim=0,totprod=0, mmarlim;
	for(int i=0;i<n;i++){
		if(cod[i].ca==1){
			totmarlim++;
			totprod+=cod[i].prod;
		}
	}
	mmarlim=totprod/totmarlim;
	return(mmarlim);
}

float media_albacora(int n, plataforma*cod){
	float totalb=0,totprod=0, malb;
	for(int i=0;i<n;i++){
		if(cod[i].ca==2){
			totalb++;
			totprod+=cod[i].prod;
		}
	}
	malb=totprod/totalb;
	return(malb);
}

float media_roncador(int n, plataforma*cod){
	float totronc=0,totprod=0, mronc;
	for(int i=0;i<n;i++){
		if(cod[i].ca==3){
			totronc++;
			totprod+=cod[i].prod;
		}
	}
	mronc=totprod/totronc;
	return(mronc);
}
main(){
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    printf("Cod.    Tipo            Campo                   Ano.    HC      HP      Prod    Coeficiente\n");
    fflush(stdin);
    float resp_4;
    float resp_41;
    float resp_alb;
    float resp_marlim;
    float resp_ronc;
    plataforma cod[12];
    preencher(12, cod);
    media_hp(12, cod);
    questao_3(12,cod);
    resp_4=questao_4(12,cod);
    resp_41= questao_41(12, cod);
    resp_alb = media_albacora(12, cod);
    resp_marlim = media_marlim(12, cod);
    resp_ronc = media_roncador(12,cod);
    imprime(12, cod, resp_4, resp_41,resp_alb,resp_marlim,resp_ronc);
    
}
