#include <math.h>
#include <iostream>
using namespace::std;

double hesapL(double **A, int j, int i, int n) {   //l[j][i] ile lkk ve lki hesaplamak için kullanýlan algoritma
	double **a = A;                               // Gelen a matrisi ile bu fonksiyon iþaretçisi ile bu fonksiyonda tanýmladýðýmýz a matrisi eþleþtiriliyor.
	double gecici=0, toplam=0;					// Gerekli deðiþkenler
	int z, e;
	
	if( j == i ) {							 // l[k][k] denklemi ve ayný indisli olan l deðerlerinin hesaplanmasý
		for(e=0; e<j; e++) {                 // Formüldeki toplam sembolünün yapýlmasý
			gecici = hesapL(a, j, e, n);
			gecici = pow(gecici, 2);
			toplam = toplam + gecici;       //Toplam sembolünden elde edilecek sonuç "toplam" deðiþkenine aktarýlýyor.
		}
		
		
		toplam = a[j][i] - toplam;         // Ardýndan formüldeki diðer iþlemler yapýlýyor.
		toplam = sqrt(toplam);
		return toplam;
	}
	else if( j != i ) {                    // l[k][i] formülü ile lki biçimindeki fonksiyonun tanýtýlmasý
		for(z = 0; z < i; z++) {           // Formülde kullanýlan toplam sembolü 
			gecici = hesapL(a, i, z, n) * hesapL(a, j, z, n);
			toplam = gecici + toplam;      // Toplam sembolünden elde edilecek sonuç "toplam" deðiþkenine aktarýlýyor.
		}
		
		toplam = a[j][i] - toplam;
		toplam = toplam / hesapL(a, i, i, n);
		return toplam;
	}
	
	
	
}

double hesapD(double **L, double *B,  int n, int i) {        // d[i] hesaplanmasý için kullanýlan formül
	double **l = L;											// Matris iþaretçileri eþleþtiriliyor
	double *b = B;
	double toplam=0, gecici;
	int j;
	if(i == 0) {                                           // d[0] için kullanýlan formül
		toplam = b[0] / l[0][0];
		return toplam;
 	}
 	else if(i != 0){                                       // Ýndis 0 olmadýðýnda kullanýlan formül
	 		for(j=0; j<i; j++) {                           //Formüldeki toplam sembolünü
			gecici = l[i][j] * hesapD(l, b, n, j);
			toplam = toplam + gecici;
		}
		toplam = b[i] - toplam;
		toplam = toplam / l[i][i];
		return toplam;
	}
	
}

double hesapX(double **L, double *B, double *D, int n, int i) {    // x[i] köklerinin hesaplanmasý için kullanýlan fonksiyon
	double **l = L;                                               //Matris iþaretçileri eþleþtiriliyor
	double *b = B;
	double *d = D;
	int j;
	double gecici, toplam=0;
	if(i == (n-1)) {                                           //x[n] için kullanýlan formül 
		return (d[n-1] / l[n-1][n-1]);
	}
	else if( i != (n-1)){	                                 // i != n durumunda kullanýlacak formül
		for(j=i+1; j<=n-1; j++) {								//Formüldeki toplam sembolü
			gecici = l[j][i] * hesapX(l, b, d, n, j);
			toplam = toplam + gecici;                            //Toplam sembolünden gelecek sonuç hesaplanýyor
		}
		toplam = d[i] - toplam;
		toplam = toplam / l[i][i];
		return toplam;
	}
	
}


// Bitiþ
