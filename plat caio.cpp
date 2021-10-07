#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
struct plataforma{
    char tipo_plataforma[17],tipo_plataforminha[5],campo[10],horas_contra[10];
    int tp,tform,af,ca,hc,hp,prod,coef;
};
float mhp,pmarlim,mprodronc;
void preencher(int n, plataforma*cod){
    for(int i=101;i<n;i++){
        cod[i].tp=rand()%3+1;
        cod[i].tform=rand()%3+1;
        cod[i].af=rand()%20+2000;
        cod[i].ca=rand()%3+1;
        cod[i].hc=rand()%2;
        cod[i].hp=rand()%3601;
        cod[i].prod=rand()%1501+1000;

        if(cod[i].tform==1)
    sprintf(cod[i].tipo_plataforminha,"FX");
    else
    if(cod[i].tform==2)
    sprintf(cod[i].tipo_plataforminha,"NS");
    else
    if(cod[i].tform==3)
    sprintf(cod[i].tipo_plataforminha,"SS");

    if(cod[i].tp==1)
    sprintf(cod[i].tipo_plataforma,"Fixa            ");
    else
    if(cod[i].tp==2)
    sprintf(cod[i].tipo_plataforma,"Navio Sonda     ");
    else
    if(cod[i].tp==3)
    sprintf(cod[i].tipo_plataforma,"Semi Submersivel");

    if(cod[i].ca==1)
    sprintf(cod[i].campo,"Marlim  ");
    else
    if(cod[i].ca==2)
    sprintf(cod[i].campo,"Albacora");
    else
    if(cod[i].ca==3)
    sprintf(cod[i].campo,"Roncador");

    if(cod[i].hc==0)
    sprintf(cod[i].horas_contra,"8760");
    else
    if(cod[i].hc==1)
    sprintf(cod[i].horas_contra,"17520");
    }
}

void imprime(int n, plataforma*cod){          //\t
    for(int i=101;i<n;i++){
        printf("%d%s\t%s\t%d\t%s\t%s\t%d\t%d\n",i+1,cod[i].tipo_plataforminha,cod[i].tipo_plataforma,cod[i].af,cod[i].campo,cod[i].horas_contra,cod[i].hp,cod[i].prod);
    }
    printf("A média de Horas paradas das Plataformas do tipo Semi Submersivel: %f",mhp);
     printf("\nO percentual de Plataformas dos Campos de marlim: %.2f%%",pmarlim);
     printf("\nA media de producao das plataformas de Marlim %.2f%%",mprodronc);
}

void media_hp(int n, plataforma*cod){
	float tothp=0,totsem=0;
	for(int i=101;i<n;i++){
		if(cod[i].hp>=0){
			tothp++;
			if(cod[i].tp==3){
				totsem++;
			}
		}
	}
	mhp=tothp/totsem;
}

/*void maior_qt3(int n, plataforma*cod){
	for(int i=101;i<n;i++){
		
	}
}

void qt3(int rq3, int n, plataforma*cod){
	for(int i=101;i<n;i++){
		printf("%d%s\t%s\t%d\t%s\t%s\t%d\t%d\n",i+1,cod[rq3].tipo_plataforminha,cod[rq3].tipo_plataforma,cod[rq3].af,cod[rq3].campo,cod[rq3].horas_contra,cod[rq3].hp,cod[rq3].prod);
	}
}
*/

void percentual(int n, plataforma*cod){
	float totmarlim=0,tothpmarlim=0;
	for(int i=101;i<n;i++){
		if (cod[i].ca==1){
			totmarlim++;
			if (cod[i].hp<800){
				tothpmarlim++;
			}
		}
	}
	pmarlim=(tothpmarlim/totmarlim)*100;
}
void media_producao(int n, plataforma*cod){
	float totprod=0, totmarlim=0;
	for(int i=101;i<n;i++){
		
		if(cod[i].prod>=1000 && cod[i].prod<=2500){
			totprod++;
			if(cod[i].ca==1){
				totmarlim++;
			}
		}
	}
mprodronc=(totmarlim/totprod)*100;
}

main(){
    srand(time(NULL));
    printf("Cod. Tipo Ano. Campo HC HP Prod Coeficiente\n");
    plataforma cod[112];
    preencher(112, cod);
    media_hp(112, cod);
    //maior_qt3(112,cod);
    //qt3 maior_qt3(112,cod);    TENTEI FAZER A MAIOR FUNCAO MAIS NAO LEMBRO COMO Q FAZ O RESTO
    percentual(112, cod);
    media_producao(112, cod);
    imprime(112, cod);
    //Nao consegui fzr tudo devido ao tempo :c
}
