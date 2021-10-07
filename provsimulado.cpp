#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

struct ordem{
	char ramo[20],origem[20],ativo[5],raminho[10],porte[20];
	int r,ori,nf,ac,at,ra,po;
};
void preencher(int n, ordem*cod){
	for(int i=265;i<n;i++){
		cod[i].r=rand()%3+1;
		cod[i].ra=rand()%3+1;
		cod[i].ori=rand()%2;
		cod[i].nf=rand()%100+1;
		cod[i].ac=rand()%21+2000;
		cod[i].at=rand()%2;
		
		
		if(cod[i].r==1)
		sprintf(cod[i].ramo,"Industrial");
		else
		if(cod[i].r==2)
		sprintf(cod[i].ramo,"Comercial");
		else
		if(cod[i].r==3)
		sprintf(cod[i].ramo,"Servicos");
		
		
		if(cod[i].ra==1)
		sprintf(cod[i].raminho,"IND");
		if(cod[i].ra==2)
		sprintf(cod[i].raminho,"COM");
		if(cod[i].ra==3)
		sprintf(cod[i].raminho,"SER");
		
		
		if(cod[i].ori==0)
		sprintf(cod[i].origem,"Macae");
		if(cod[i].ori==1)
		sprintf(cod[i].origem,"Regiao");
		
		if(cod[i].at==0)
		sprintf(cod[i].ativo,"Sim");
		else
		sprintf(cod[i].ativo,"Nao");
	}
}

void tipo_empresa(int n, ordem*cod){
	for(int i=265;i<n;i++){
		if(cod[i].r==1){
			if(cod[i].nf<=19){
				sprintf(cod[i].porte,"MEI");
			}														
		else{
			sprintf(cod[i].porte,"EPP"); 
		}
	}
		else{
			if(cod[i].nf<10)
			sprintf(cod[i].porte,"MEI");
		}
			if(cod[i].nf>=10 && cod[i].nf<50){
			sprintf(cod[i].porte,"EPP");
			}
				if(cod[i].nf>49){
				sprintf(cod[i].porte,"EMP");
		}
		 

	}
}
void imprimir(int n, ordem*cod){
	for(int i=265;i<n;i++){
			printf("%d%s\t%s\t%s\t%d\t%d\t%s\t%s\n",i,cod[i].raminho,cod[i].ramo,cod[i].origem,cod[i].nf,cod[i].ac,cod[i].ativo,cod[i].porte);
		}
}


main(){
	srand(time(NULL));
	printf("CODIGO RAMO NºFUN PORTE ORIGEM ANOCRI ATIVO ANOENC\n");
	ordem cod[444];
	preencher (444,cod);
	tipo_empresa(444,cod);
	imprimir (444,cod);
	
}












