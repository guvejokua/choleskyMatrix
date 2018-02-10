#include <math.h>
#include <iostream>
using namespace::std;

double hesapL(double **A, int j, int i, int n) {   //l[j][i] ile lkk ve lki hesaplamak i�in kullan�lan algoritma
	double **a = A;                               // Gelen a matrisi ile bu fonksiyon i�aret�isi ile bu fonksiyonda tan�mlad���m�z a matrisi e�le�tiriliyor.
	double gecici=0, toplam=0;					// Gerekli de�i�kenler
	int z, e;
	
	if( j == i ) {							 // l[k][k] denklemi ve ayn� indisli olan l de�erlerinin hesaplanmas�
		for(e=0; e<j; e++) {                 // Form�ldeki toplam sembol�n�n yap�lmas�
			gecici = hesapL(a, j, e, n);
			gecici = pow(gecici, 2);
			toplam = toplam + gecici;       //Toplam sembol�nden elde edilecek sonu� "toplam" de�i�kenine aktar�l�yor.
		}
		
		
		toplam = a[j][i] - toplam;         // Ard�ndan form�ldeki di�er i�lemler yap�l�yor.
		toplam = sqrt(toplam);
		return toplam;
	}
	else if( j != i ) {                    // l[k][i] form�l� ile lki bi�imindeki fonksiyonun tan�t�lmas�
		for(z = 0; z < i; z++) {           // Form�lde kullan�lan toplam sembol� 
			gecici = hesapL(a, i, z, n) * hesapL(a, j, z, n);
			toplam = gecici + toplam;      // Toplam sembol�nden elde edilecek sonu� "toplam" de�i�kenine aktar�l�yor.
		}
		
		toplam = a[j][i] - toplam;
		toplam = toplam / hesapL(a, i, i, n);
		return toplam;
	}
	
	
	
}

double hesapD(double **L, double *B,  int n, int i) {        // d[i] hesaplanmas� i�in kullan�lan form�l
	double **l = L;											// Matris i�aret�ileri e�le�tiriliyor
	double *b = B;
	double toplam=0, gecici;
	int j;
	if(i == 0) {                                           // d[0] i�in kullan�lan form�l
		toplam = b[0] / l[0][0];
		return toplam;
 	}
 	else if(i != 0){                                       // �ndis 0 olmad���nda kullan�lan form�l
	 		for(j=0; j<i; j++) {                           //Form�ldeki toplam sembol�n�
			gecici = l[i][j] * hesapD(l, b, n, j);
			toplam = toplam + gecici;
		}
		toplam = b[i] - toplam;
		toplam = toplam / l[i][i];
		return toplam;
	}
	
}

double hesapX(double **L, double *B, double *D, int n, int i) {    // x[i] k�klerinin hesaplanmas� i�in kullan�lan fonksiyon
	double **l = L;                                               //Matris i�aret�ileri e�le�tiriliyor
	double *b = B;
	double *d = D;
	int j;
	double gecici, toplam=0;
	if(i == (n-1)) {                                           //x[n] i�in kullan�lan form�l 
		return (d[n-1] / l[n-1][n-1]);
	}
	else if( i != (n-1)){	                                 // i != n durumunda kullan�lacak form�l
		for(j=i+1; j<=n-1; j++) {								//Form�ldeki toplam sembol�
			gecici = l[j][i] * hesapX(l, b, d, n, j);
			toplam = toplam + gecici;                            //Toplam sembol�nden gelecek sonu� hesaplan�yor
		}
		toplam = d[i] - toplam;
		toplam = toplam / l[i][i];
		return toplam;
	}
	
}


// Biti�
