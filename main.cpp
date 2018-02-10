//Kodlayan : Furkan Ali �nsal | Elektrik-ELektonik M�hendisli�i | 150707035
// Say�sal Analiz Final Projesi

#include <iostream>
#include "hesaplama.h"  // T�m hesaplamalar bu ba�l�kta yap�lacak.
#include <locale.h>
using namespace::std;


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Turkish");
	double **a, **l, *b, *d, *x;
	int i, j, k, n;
	cout << "Matris Boyutunu giriniz: ";
	cin >> n;
	a = new double * [n];                  																  //////////////////////////////////////////////////
	for(i=0; i<n; i++)                   															     //////// Katsay�lar matrisi i�in yer ay�rma///////
		a[i] = new double [n];            															    //////////////////////////////////////////////////
	
	l = new double * [n];              															       /////////////////////////////////////////////////
	for(i=0; i<n; i++)																				  ////////// l matrisi i�in yer ay�rma ////////////
		l[i] = new double [n];																		 /////////////////////////////////////////////////
	
	b = new double [n];				   															   // De�erler matrisi i�in yer ay�rma
	d = new double [n];																			  //  d matrisi i�in yer ay�rma
	x = new double [n];				 															 //   x matrisi i�in yer ay�rma	
	
	
	for(i=0; i<n; i++)																			//////////////////////////////////////////////////
		for(j=0; j<n; j++) {	  															   //////////////////////////////////////////////////
			cout << "[" <<i+1 << "]" << "[" << j+1 << "].elaman� giriniz: ";	              //////////////////////////////////////////////////
			cin >> a[i][j];		 															 /// Katsay�lar matrisinin okunmas� ///////////////
			l[i][j]=0;           															//// l matrisi s�f�rlan�yor //////////////////////
		}                                                                                  //////////////////////////////////////////////////
		
		
	for(i=0; i<n; i++)                                                                    //////////////////////////////////////////////////
		for(j=0; j<n; j++)                                                               //// l matrisi hesaplan�yor //////////////////////
			l[j][i] = hesapL(a, j, i, n);												//////////////////////////////////////////////////
	
	cout << "De�erler matrisini giriniz: " << endl;
	
	for(i=0; i<n; i++) {																	///////////////////////////////////////////////
		cout << "[" << i+1 << "].eleman� giriniz: ";									   ////De�er matrisi okunuyor ////////////////////
		cin >> b[i];																	  ///////////////////////////////////////////////
	}																					 ///////////////////////////////////////////////
	
	for(i=0; i<n; i++)                                                                  ///////////////////////////////////////////////
		d[i] = hesapD(l, b, n, i);													   //// D matrisi hesaplan�yor //////////////////
	
	for(i=0; i<n; i++) {															  ////////////////////////////////////////////////
		x[i] = hesapX(l, b, d, n, i);												 ///// X matrisi hesaplan�yor ///////////////////
		cout << "X" << i+1 << " = " << x[i] << endl;								///// ve ekrana yazd�r�l�yor. //////////////////
	}
	
	system("PAUSE");
	return 0;
}
