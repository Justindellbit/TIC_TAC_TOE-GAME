#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void afficherTableJeu(char T[3][3] );
int index_case(int, char* ,char* );
int valide(char T[3][3],int );
int Round_initial(char tab[3][3],char* ,char* );
int valide_mvt(char tab[3][3],int,char* ,char* );
int victoire(char tab[3][3], int,int,char* ,char*);
void RoundPropre(char tab[3][3],char* ,char* );

int main()
{
	DWORD f=1000, d1=500,d3=2000;
    char J1[25] ;char J2[25];
	printf("joueur 1 joue avec x et joueur 2 joue avec o et c\'est le joueur 1 qui commence\n les cases sont numerotes de 1 -->9  bien sur la lecture se fait par ligne \n\n\n ");
	printf("entrer nom joueur du 1\n ");gets(J1);printf("entrer nom joueur du 2\n ");gets(J2);
	char V[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	int tour;
	afficherTableJeu(V);
    tour=Round_initial(V,	J1,J2);
    if(tour==6) RoundPropre(V,J1,J2);
    Beep(f,d1);	Beep(f,d1);	Beep(f,d3);
	return 0;
}


void afficherTableJeu(char T[3][3])
{
	printf("\t\t%c | %C | %c |\n\t\t-----------\n\t\t%c | %C | %c |\n\t\t-----------\n\t\t%c | %C | %c |\n",T[0][0],T[0][1],T[0][2],T[1][0],T[1][1],T[1][2],T[2][0],T[2][1],T[2][2]);
}
int index_case(int tour ,char* joueur1,char* joueur2)
{
	int indice;
	char* joueur=(tour%2==0)?joueur1:joueur2;
	printf(" %s : saisir l\'indice de la case \n\n",joueur);
	scanf("%d" ,&indice );
	return indice ;
}
int valide(char T[3][3],int ind)
{
	int ligne=(ind-1)/3, colonne=(ind-1)%3;
	if((T[ligne][colonne]=='x' || T[ligne][colonne]=='o') || (ind<1 || ind>9 ))
	return -1;
	return 0;
}
int victoire(char tab[3][3], int tour,int pos,char* joueur1,char* joueur2)
{
	int val=0;
	char* joueur =(tour%2==0)?joueur1:joueur2;
	char a=tab[0][0],b=tab[0][1],c=tab[0][2],d=tab[1][0],e=tab[1][1],f=tab[1][2],g=tab[2][0],h=tab[2][1],i=tab[2][2];
	switch(pos)
		{
			case 1:
				if((a==b && a==c)||(a==d &&a==g)||(a==e && a==i))
				{ val=1;
				printf(" BOUM BOUNM Victoire %s\n",joueur);}break;
			case 2:
				if((a==b&&a==c)||(b==e && b==h))
				{val=1;
				printf(" BOUM BOUNM Victoire %s\n",joueur);}break;
			case 3:
			  if((a==b && a==c)||(c==f && c==i)||(c==e && c==g))
				{val=1;
				printf(" BOUM BOUNM Victoire %s\n",joueur);}break;
			case 4:
			  if((d==e && d==f)||(a==d && a==g))
				{val=1;
				printf(" BOUM BOUNM Victoire %s\n",joueur);}break;
			case 5:
			  if((d==e && d==f)||(b==e && b==h)||(c==e && c==g)||(a==e && a==i))
				{val=1;
				printf("BOUM BOUNM Victoire %s\n",joueur);}break;	
			case 6:
			  if((d==e && d==f)||(c==f && c==i))
				{val=1;
				printf("\a\a\a BOUM BOUNM Victoire %s\n",joueur1);}break;
			case 7:
			if((g==h && g==i)||(a==d && a==g)||(c==e && c==g))
				{val=1;
				printf(" BOUM BOUNM Victoire %s\n",joueur);}break;
			case 8:
				if((g==h && g==i)||(b==e && b==h))
				{val=1;
				printf("\a\a\a BOUM BOUNM Victoire %s\n",joueur);}break;
			case 9:
				if((g==h && g==i)||(c==f && c==i)||(a==e && a==i))
				{val=1;
				printf("BOUM BOUNM Victoire %s\n",joueur);}break;
		}
	return val;
}

int Round_initial(char tab[3][3],char* joueur1,char* joueur2)
{
		int ind;
	int tour =0;
	while(tour<6)
	{
	int i=0;
		do
		{
			if (i>0) printf("ERREUR:saisi non valide\n");
			ind =index_case(tour,joueur1,joueur2);
			while(getchar()!='\n');
			i++;
		}while(valide(tab,ind)==-1);
	
		tab[(ind-1)/3][(ind-1)%3]=(tour%2==0)?'x':'o';
		afficherTableJeu(tab);
		if(victoire(tab,tour,ind,joueur1,joueur2)) break;
		tour++;
	}
	return tour;
}


int valide_mvt(char tab[3][3],int tour,char* joueur1,char* joueur2)
{ 
	int i=0;
	char val=(tour%2==0)?'x':'o';
	int ind_dep=0,ind_arr=0;
	int residu=0;
	char val_case_dep;
	do
	{
		if(i>0) printf("ERREUR: deplacement invalide\n");
		printf("saisir l\'indice de la case de depart\n");
		ind_dep=index_case(tour,joueur1,joueur2);
		printf("saisir l\'indice de la case de destination ou d\'arrive%c\n",130);
		ind_arr=index_case(tour, joueur1, joueur2);
		val_case_dep=tab[(ind_dep-1)/3][(ind_dep-1)%3];
		switch(ind_dep)
		{
			case 1:
				residu=(ind_arr==2 || ind_arr==4)?0:-1;
				break;
			case 2:
				residu=(15%ind_arr!=0)?-1:0;
				break;
			case 3:
				residu=(ind_arr==2 || ind_arr==6)?0:-1;
				break;
			case 4:
			  residu=(35%ind_arr!=0)?-1:0;
				break;	
			case 6:
				residu=(ind_arr==3 || ind_arr==5 || ind_arr==9)?0:-1;
				break;
			case 7:
				residu=(ind_arr==4 || ind_arr==8)?0:-1;
				break;
			case 8:
				residu=(ind_arr==7 || ind_arr==5 || ind_arr==9)?0:-1;
				break;
			case 9:
				residu=(ind_arr==8 || ind_arr==6)?0:-1;
				break;
		}
		i++;
	}while(val!=val_case_dep || valide(tab,ind_arr)==-1 || residu==-1 );
   	tab[(ind_arr-1)/3][(ind_arr-1)%3]=(tour%2==0)?'x':'o';
   	switch(ind_dep)
		{
			case 1:
				tab[(ind_dep-1)/3][(ind_dep-1)%3]='1';break;
			case 2:
				tab[(ind_dep-1)/3][(ind_dep-1)%3]='2';break;
			case 3:
			  tab[(ind_dep-1)/3][(ind_dep-1)%3]='3';break;
			case 4:
			  tab[(ind_dep-1)/3][(ind_dep-1)%3]='4';break;
			case 5:
			  tab[(ind_dep-1)/3][(ind_dep-1)%3]='5';break;	
			case 6:
			   tab[(ind_dep-1)/3][(ind_dep-1)%3]='6';break;
			case 7:
				tab[(ind_dep-1)/3][(ind_dep-1)%3]='7';break;
			case 8:
				tab[(ind_dep-1)/3][(ind_dep-1)%3]='8';break;
			case 9:
				tab[(ind_dep-1)/3][(ind_dep-1)%3]='9';break;
		}
	return ind_arr;
}

void RoundPropre(char tab[3][3],char* joueur1,char* joueur2)
{
	int tour=0;
	int pos=0;
	while(tour<100)
	{
		pos=valide_mvt(tab,tour,joueur1,joueur2);
		afficherTableJeu(tab);
		if(victoire(tab,tour,pos,joueur1,joueur2)) break;
		tour++;
	}
}

