#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static int ncr=0,ncrb=0,ncma=0,ncta=0,nctb=0,nct=0,ntnb=0,ntn=0,ncm=0,nlrb=0,nmea=0,nmeb=0,nme=0,nlro=0,nerb=0,ner=0,nle=0,ngs=0,nbhb=0,nbh=0;
void calccab(int *a,int *b,int *c);
void calcbar(int *a,int *b);
void calplacan(int *a,int *b,int *c,int *d,int *e,int *f,int *g,int *h,int *i,int *j,int *k,int *l,int *m,int *n,int *o,int *p,int *q,int *r,int *s,int *t,int *u);
int main()
{
	system("color 0a");
	int copper,copperbar,cable,c,cc,n,randmax=140,x;
	cc=0;
	printf("Enter The Number Of Copper In Stock:");
	scanf("%d",&copper);
	printf("Enter The Number Of Copper Bar In Stock:");
	scanf("%d",&copperbar);
	printf("Enter The Number Of Cable in Stock:");
	scanf("%d",&cable);
	system("cls");
	while(0==0)
	{
		printf("\n||MENU||\n1.Mine Copper\n2.Create Copper Bar\n3.Create Cable\n4.Calculate Raw Material Needed\n5.Display Inventory\n6.Exit\nEnter Your Choice: ");
		scanf("%d",&c);
		system("cls");
		switch (c)
		{
			case 1:
				x=(rand()%randmax);
				printf("\n%d Copper Mined\n",x);
				copper=copper+x;
				break;
			case 2:
				if (copper>+800)
				{
					copper-=800;
					copperbar++;
					printf("Copper Produced Succesfully\n");
				}
				else
				{
					printf("Not Enough Copper\n");
				}
				break;
			case 3:
				if (copperbar>=2)
				{
					copperbar-=2;
					cable++;
					printf("Copper Bar Produced Succesfully\n");
				}
				else
				{
					printf("Not Enough Copper Bar\n");
				}
				break;
			case 4:
				printf("\n1.Copper Bar\n2.Cable\n3.Plasma Cannon\nEnter Choice: ");
				scanf("%d",&cc);
				printf("Enter The Amount You Want To Create:");
				scanf("%d",&n);
				system("cls");
				if (cc==1)
				{
					calcbar(&ncr,&n);
					printf("Required Items\n\tCopper Ore: %d\n",ncr);
				}
				else if(cc==2)
				{
					calccab(&ncrb,&n,&ncr);
					printf("Required Items\n\tCopper Ore: %d\n\tCopper Bar: %d\n",ncr,ncrb);
				}
				else if(cc==3)
				{
					calplacan(&ncma,&ncta,&nctb,&nct,&ntnb,&ntn,&ncm,&nlrb,&nmea,&nmeb,&nme,&ncrb,&ncr,&nlro,&nerb,&ner,&nle,&ngs,&nbhb,&nbh,&n);/*a=cerall b=coball c=cobbar d=cob e=tinbar f=tin g=cer h=lasbla i=manall j=manbar k=man l=copbar m=cop n=lasopt o=einbar p=ein q=len r=gla s=BisBar t=Bis u=noofprod*/
					printf("Required Items\n\tCerithium alloy: %d\n\tCobalt Alloy: %d\n\tCobalt Bar: %d\n\tCobalt: %d\n\tTin Bar: %d\n\tTin: %d\n\tCerithium: %d\n\tLaser Blaster: %d\n\tManganese Alloy: %d\n\tManganese Bar: %d\n\tManganese: %d\n\tCopper Bar: %d\n\tCopper: %d\n\tLaser Optic: %d\n\tEinherger Bar: %d\n\tEinherger: %d\n\tLense: %d\n\tGlass: %d\n\tBismuth Bar: %d\n\tBismuth: %d\n",ncma,ncta,nctb,nct,ntnb,ntn,ncm,nlrb,nmea,nmeb,nme,ncrb,ncr,nlro,nerb,ner,nle,ngs,nbhb,nbh);
				}
				else
				{
					printf("Enter Invalid Choice:\n");
				}
				break;
			case 5:
				printf("Inventory:\n\tCopper Ore: %d\n\tCopper Bar: %d\n\tCable: %d\n",copper,copperbar,cable);
				break;
			case 6:
				printf("Adios Amigo....");
				exit(0);
			default:
				printf("lol,You Entered an Invalid Choice");
				break;
		}
	}
	return 0;
}

void calcbar(int *a,int *b) /*a=ore,b=noofprod*/
{
	*a=*a+(*b*800);
}

void calccab(int *a,int *b,int *c) /*a=CopBar,b=noofprod,c=CopOre*/
{
	*a=*a+(+*b*2);
	calcbar(&(*c),&(*a));
}

void calmanall(int *a,int *b,int *c,int *d,int *e)/*a=mangbar b=mang c=copbar d=cop e=noofprod*/
{
	*a=*a+*e;
	calcbar(&(*b),&(*a));
	*c=*c+(*e*8);
	calcbar(&(*d),&(*c));
}

void calcoball(int *a,int *b,int *c,int *d,int *e)/*a=cobbar b=cob c=tinbar d=tin e=noofprod*/
{
	*a=*a+(*e*12);
	calcbar(&(*b),&(*a));
	*c=*c+(*e*24);
	calcbar(&(*d),&(*c));
}

void calcerall(int *a,int *b,int *c,int *d,int *e,int *f,int *g)/*a=coball b=cobbar c=cob d=tinbar e=tin f=cer g=noofprod*/
{
	*a=*a+*g;
	calcoball(&(*b),&(*c),&(*d),&(*e),&(*a));
	calcbar(&(*f),&(*g));
}

void calgla(int *a,int *b,int *c) /*a=BisBar b=Bis c=noofprod*/
{
	*a=*a+(*c*10);
	calcbar(&(*b),&(*a));
}

void callen(int *a,int *b,int *c,int *d,int *e,int *f)/*a=gla b=BisBar c=Bis d=manbar e=man f=noofprod*/
{
	*a=*a+*f;
	calgla(&(*b),&(*c),&(*a));
	*d=*d+(*f*5);
	calcbar(&(*e),&(*d));
}

void callasopt(int *a,int *b,int *c,int *d,int *e,int *f,int *g,int *h,int *i,int *j,int *k)/*a=einbar b=ein c=tinbar d=tin e=len f=gla g=BisBar h=Bis i=manbar j=man k=noofprod*/
{
	*a=*a+(*k*10);
	*c=*c+(*k*10);
	calcbar(&(*b),&(*a));
	calcbar(&(*d),&(*c));
	*e=*e+*k;
	callen(&(*f),&(*g),&(*h),&(*i),&(*j),&(*e));
}

void callasbla(int *a,int *b,int *c,int *d,int *e,int *f,int *g,int *h,int *i,int *j,int *k,int *l,int *m,int *n,int *o)/*a=manall b=manbar c=man d=copbar e=cop f=lasopt g=einbar h=ein i=tinbar j=tin k=len l=gla m=BisBar n=Bis o=noofprod*/
{
	*a=*a+(*o*5);
	*f=*f+(*o*2);
	*k=*k+(*o*5);
	calmanall(&(*b),&(*c),&(*d),&(*e),&(*a));
	callasopt(&(*g),&(*h),&(*i),&(*j),&(*k),&(*l),&(*m),&(*n),&(*b),&(*c),&(*f));
}

void calplacan(int *a,int *b,int *c,int *d,int *e,int *f,int *g,int *h,int *i,int *j,int *k,int *l,int *m,int *n,int *o,int *p,int *q,int *r,int *s,int *t,int *u)/*a=cerall b=coball c=cobbar d=cob e=tinbar f=tin g=cer h=lasbla i=manall j=manbar k=man l=copbar m=cop n=lasopt o=einbar p=ein q=len r=gla s=BisBar t=Bis u=noofprod*/
{
	*a=*a+(*u*15);
	*h=*h+(*u*5);
	calcerall(&(*b),&(*c),&(*d),&(*e),&(*f),&(*g),&(*a));
	callasbla(&(*i),&(*j),&(*k),&(*l),&(*m),&(*n),&(*o),&(*p),&(*e),&(*f),&(*q),&(*r),&(*s),&(*t),&(*h));
}
