#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void)
{
    int gelirvergi_oran1=0,gelirvergi_oran2=0,gelirvergi_oran3=0,gelirvergi_oran4=0;
    int n=1,enyuksek_kisi=0,enyuksek_topbrut=0,evli_olan=0,evli_olmayan=0,esi_calisan=0,uctenbuyuk_cocuk=0;
	int i=0;
	float toplam_net=0,engelli_calisan=0,cocugu_olan=0;
    char medeni,e,es,secim;
    double tc[n];
    char ad[100][60];
    int ikiyuzluk[n],yuzluk[n],ellitl[n],yirmitl[n],ontl[n],bestl[n],birtl[n],ellikrs[n],yirmibeskrs[n],onkrs[n],beskrs[n],birkrs[n];
    float esitlik[n],cocuk_net[n],es_para[n],engel_der[n],cocuk_kucuk[n],cocuk_buyuk[n],cocuk_sayi[n],engellilik_para[n];
    float asgari[n],top_brut[n],aylik_net[n],vergi_kesinti[n],banknot[n];
    system("color c");
    do{
    printf("TC kimlik numaranizi giriniz : ");
    scanf("%lf",&tc[n]);
    fflush(stdin);
    printf("Adinizi ve soyadinizi giriniz : ");
    fflush(stdin);
    gets(ad[n]);
    fflush(stdin);
    do{
    printf("Aylik brut ucretinizi giriniz(min:1777.50) : ");
    scanf("%f",&asgari[n]);
    }while(asgari[n]<1777.50);
    do{
    printf("Medeni Durumunuzu Giriniz(e/E/b/B) : ");
    scanf("%s",&medeni);
    }while(medeni!='e'&&medeni!='E'&&medeni!='b'&&medeni!='B');
    if(medeni=='e'||medeni=='E')
    {
        evli_olan++;
        do{
        printf("Esiniz Calisiyor mu?(e/E/h/H) : ");
        scanf("%s",&es);
        }while(es!='e'&&es!='E'&&es!='h'&&es!='H');
        if(es=='h'||es=='H')
        {
            es_para[n]=220;
        }
        else if(es=='e'||es=='E')
            esi_calisan++;
    }
    else
    {
        evli_olmayan++;
        es_para[n]=0;
    }
    printf("Bakmakla yukumlu oldugunuz cocuk sayisi : ");
    scanf("%f",&cocuk_net[n]);
    if(cocuk_net[n]>0)
    {
        printf("Cocuklarinizin kaci 6 ve daha kucuk yastadir : ");
        do{scanf("%f",&cocuk_sayi[n]);
        }while(cocuk_sayi[n]>cocuk_net[n]);
        cocuk_kucuk[n]=cocuk_sayi[n]*25;
        cocuk_buyuk[n]=(cocuk_net[n]-cocuk_sayi[n])*45;
        if(cocuk_net[n]>3)
        {
            uctenbuyuk_cocuk++;
        }
    cocugu_olan++;
    }
    else if(cocuk_net[n]==0)
    {
        cocuk_buyuk[n]=0;
        cocuk_kucuk[n]=0;
    }
    printf("Engelli olup olmadiginiz(e/E/h/H) : ");
    do{
    scanf("%s",&e);
    }while(e!='e'&&e!='E'&&e!='h'&&e!='H');
    if(e=='e'||e=='E')
        {
            engelli_calisan++;
    printf("engellilik dereceniz : \n");
    do{
        scanf("%f",&engel_der[n]);
    }while(1>engel_der[n]||engel_der[n]>100);

    if(engel_der[n]>=40&&engel_der[n]<60)
    {
        engellilik_para[n]=210;
    }
    else if(engel_der[n]>=60&&engel_der[n]<80)
	{
        engellilik_para[n]=470;

    }
    else if(engel_der[n]>=80&&engel_der[n]<100)
    {
        engellilik_para[n]=900;
    }
        }
        else
        {
            engellilik_para[n]=0;
            engel_der[n]=0;
        }
       top_brut[n]=es_para[n]+asgari[n]+cocuk_buyuk[n]+cocuk_kucuk[n];
       if(n>=2)
       {
           if(top_brut[n-1]<top_brut[n])
           {
                enyuksek_topbrut=n;
           }

       }else if(n==1)
       {
           enyuksek_topbrut=1;
       }
       esitlik[n]=top_brut[n]-engellilik_para[n];
    if(esitlik[n]<2000)
    {
        vergi_kesinti[n]=(esitlik[n])*15/100;
        aylik_net[n]=top_brut[n]-vergi_kesinti[n];
        gelirvergi_oran1++;
    }
   else if(esitlik[n]>=2000&&esitlik[n]<5000)
    {
        vergi_kesinti[n]=(esitlik[n])*20/100;
             aylik_net[n]=top_brut[n]-vergi_kesinti[n];
             gelirvergi_oran2++;
    }
    else if(esitlik[n]>=5000&&esitlik[n]<10000)
    {
        vergi_kesinti[n]=(esitlik[n])*27/100;
             aylik_net[n]=top_brut[n]-vergi_kesinti[n];
             gelirvergi_oran3++;
    }
    else if(esitlik[n]>=10000)
    {
        vergi_kesinti[n]=(esitlik[n])*35/100;
             aylik_net[n]=top_brut[n]-vergi_kesinti[n];
             gelirvergi_oran4++;
    }
    if(n>=2)
       {
           if(aylik_net[n-1]<aylik_net[n])
           {
                enyuksek_kisi=n;
           }
       }
       else if(n==1)
       {
           enyuksek_kisi=1;
       }
    banknot[n]=aylik_net[n];
    ikiyuzluk[n]=banknot[n]/200;
    banknot[n]-=ikiyuzluk[n]*200;
    yuzluk[n]=banknot[n]/100;
    banknot[n]-=yuzluk[n]*100;
    ellitl[n]=banknot[n]/50;
    banknot[n]-=ellitl[n]*50;
    yirmitl[n]=banknot[n]/20;
    banknot[n]-=yirmitl[n]*20;
    ontl[n]=banknot[n]/10;
    banknot[n]-=ontl[n]*10;
    bestl[n]=banknot[n]/5;
    banknot[n]-=bestl[n]*5;
    birtl[n]=banknot[n]/1;
    banknot[n]-=birtl[n]*1;
    ellikrs[n]=banknot[n]/(0.50);
    banknot[n]-=ellikrs[n]*(0.50);
    yirmibeskrs[n]=banknot[n]/(0.25);
    banknot[n]-=yirmibeskrs[n]*(0.25);
    onkrs[n]=banknot[n]/(0.10);
    banknot[n]-=onkrs[n]*(0.10);
    beskrs[n]=banknot[n]/(0.05);
    banknot[n]-=beskrs[n]*(0.05);
    birkrs[n]=banknot[n]/(0.0099999);
    printf("TC Kimlik numaraniz : %.0lf \n",tc[n]);
    printf("Adi ve Soyadi : %s\n",ad[n]);
    printf("Aylik brut ucret : %.2f\n",asgari[n]);
    printf("Es icin aile yardimi odenegi : %.2f\n",es_para[n]);
    printf("Cocuk icin aile yardimi odenegi : %.2f\n",cocuk_buyuk[n]+cocuk_kucuk[n]);
    printf("Aylik toplam brut ucret : %.2f\n",top_brut[n]);
    printf("Gelir vergisi kesintisi : %.2f\n",vergi_kesinti[n]);
    printf("Engelli Vergi indirimi : %.2f\n",engellilik_para[n]);
    printf("Engelli derecesi : %.2f\n",engel_der[n]);
    printf("Aylik net ucret : %.2f\n",aylik_net[n]);
    printf("200 TL = %d 100TL = %d 50TL = %d 20TL = %d 10TL = %d 5TL = %d \n1TL = %d 50KRS = %d 25KRS = %d 10KRS = %d 5KRS = %d 1KRS = %d \n",ikiyuzluk[n],yuzluk[n],ellitl[n],yirmitl[n],ontl[n],bestl[n],birtl[n],ellikrs[n],yirmibeskrs[n],onkrs[n],beskrs[n],birkrs[n]);
    getch();

    printf("Baska bir hesaplama yapmak istermisiniz(e/E/h/H) : ");
    do{
    scanf("%c",&secim);
        }while(secim!='e'&&secim!='E'&&secim!='h'&&secim!='H');
        n++;
        printf("\n\n\n\n\n\n\n\n\n\n");
   }

   while(secim!='h'&&secim!='H');

float toplam_vergi=0,toplam_brut=0,yuzde[4],ortalama_cocuk=0,yuzde_eslericalisan=0,yuzde_cocug=0;
	for(i=0;i<n;i++)
	{
		toplam_net+=aylik_net[i];
		toplam_vergi+=vergi_kesinti[i];
        toplam_brut+=top_brut[i];
        ortalama_cocuk+=cocuk_net[i];
	}
    banknot[n]=toplam_net;
    ikiyuzluk[n]=banknot[n]/200;
    banknot[n]-=ikiyuzluk[n]*200;
    yuzluk[n]=banknot[n]/100;
    banknot[n]-=yuzluk[n]*100;
    ellitl[n]=banknot[n]/50;
    banknot[n]-=ellitl[n]*50;
    yirmitl[n]=banknot[n]/20;
    banknot[n]-=yirmitl[n]*20;
    ontl[n]=banknot[n]/10;
    banknot[n]-=ontl[n]*10;
    bestl[n]=banknot[n]/5;
    banknot[n]-=bestl[n]*5;
    birtl[n]=banknot[n]/1;
    banknot[n]-=birtl[n]*1;
    ellikrs[n]=banknot[n]/(0.50);
    banknot[n]-=ellikrs[n]*(0.50);
    yirmibeskrs[n]=banknot[n]/(0.25);
    banknot[n]-=yirmibeskrs[n]*(0.25);
    onkrs[n]=banknot[n]/(0.10);
    banknot[n]-=onkrs[n]*(0.10);
    beskrs[n]=banknot[n]/(0.05);
    banknot[n]-=beskrs[n]*(0.05);
    birkrs[n]=banknot[n]/(0.001);
    if(evli_olan!=0)
    {
    yuzde_eslericalisan=(float)((esi_calisan*100)/(evli_olan));
    }
    else
    {
        yuzde_eslericalisan=0;
    }
    if(cocugu_olan!=0)
    {
        yuzde_cocug=(float)(ortalama_cocuk/cocugu_olan);
    }
    else
    {
            yuzde_cocug=0;
    }
    yuzde[0]=(gelirvergi_oran1*100)/(n-1);
    yuzde[1]=(gelirvergi_oran2*100)/(n-1);
    yuzde[2]=(gelirvergi_oran3*100)/(n-1);
    yuzde[3]=(gelirvergi_oran4*100)/(n-1);
	printf("Tum calisanlara bir ayda odenen aylik toplam ne ucret : %.2f\n",toplam_net);
	printf("Tum calisanlarin bir ayda odedigi aylik toplam devlet vergisi kesintisi : %.2f\n",toplam_vergi);
	printf("Tum calisanlarin aylik toplam brut ucretlerinin ortalamasi : %.2f\n Tum calisanlarin aylik toplam net ucretlerinin ortalamasi : %.2f\n",toplam_brut/(n-1),toplam_net/(n-1));
	printf("200 TL = %d 100TL = %d 50TL = %d 20TL = %d 10TL = %d 5TL = %d\n1TL = %d 50KRS = %d 25KRS = %d 10KRS = %d 5KRS = %d 1KRS = %d \n",ikiyuzluk[n],yuzluk[n],ellitl[n],yirmitl[n],ontl[n],bestl[n],birtl[n],ellikrs[n],yirmibeskrs[n],onkrs[n],beskrs[n],birkrs[n]);
    printf("15'lik gelir vergisi orani icin %d kisi yuzdesi ise %.2f  dir.\n",gelirvergi_oran1,yuzde[0]);
    printf("20'lik gelir vergisi orani icin %d kisi yuzdesi ise %.2f  dir.\n",gelirvergi_oran2,yuzde[1]);
    printf("27'lik gelir vergisi orani icin %d kisi yuzdesi ise %.2f  dir.\n",gelirvergi_oran3,yuzde[2]);
    printf("35'lik gelir vergisi orani icin %d kisi yuzdesi ise %.2f  dir.\n",gelirvergi_oran4,yuzde[3]);
    printf("\nAylik toplam brut ucreti en yuksek olan calisanin bilgileri : \n");
    printf("TC Kimlik numaraniz : %.0lf \n",tc[enyuksek_topbrut]);
    printf("Adi ve Soyadi : %s\n",ad[enyuksek_topbrut]);
    printf("Gelir vergisi kesintisi : %.2f\n",vergi_kesinti[enyuksek_topbrut]);
    printf("Aylik toplam brut ucret : %.2f\n",top_brut[enyuksek_topbrut]);
    printf("Aylik net ucret : %.2f\n",aylik_net[enyuksek_topbrut]);
    printf("\nAylik net ucreti en yuksek olan calisanin bilgileri : \n");
    printf("TC Kimlik numaraniz : %.0lf \n",tc[enyuksek_kisi]);
    printf("Adi ve Soyadi : %s\n",ad[enyuksek_kisi]);
    printf("Gelir vergisi kesintisi : %.2f\n",vergi_kesinti[enyuksek_kisi]);
    printf("Aylik toplam brut ucret : %.2f\n",top_brut[enyuksek_kisi]);
    printf("Aylik net ucret : %.2f\n",aylik_net[enyuksek_kisi]);
    printf("Tum calisanlarin icindeki evli olanlarin yuzdesi : %d\n",(evli_olan*100)/(n-1));
    printf("Tum calisanlarin icindeki evli olmayanlarin yuzdesi : %d\n",(evli_olmayan*100)/(n-1));
    printf("Evli olan calisanlarin icinde esleri calisanlarin yuzdesi : %.2f\n",yuzde_eslericalisan);
    printf("Calisanlarin bakmakla hukumlu olduklari cocuk sayisinin ortalamasi : %.2f\n",yuzde_cocug);
    printf("Bakmakla yukumlu oldugu cocuk sayisi 3'ten fazla olan calisanlari sayisi : %d\n",uctenbuyuk_cocuk);
    printf("Engelli calisanlarin sayisi : %.2f\n",engelli_calisan);
    printf("Engelli calisanlarin tum calisanlar icindeki yuzdesi : %.2f\n",(engelli_calisan*100)/(n-1));
    return 0;
}
