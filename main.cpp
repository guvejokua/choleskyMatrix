//Kodlayan : Furkan Ali Ünsal | Elektrik-ELektonik Mühendisliði | 150707035
// Sayýsal Analiz Final Projesi

#include <iostream>
#include "hesaplama.h"  // Tüm hesaplamalar bu baþlýkta yapýlacak.
#include <locale.h>
using namespace::std;


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Turkish");
	double **a, **l, *b, *d, *x;
	int i, j, k, n;
	cout << "Matris Boyutunu giriniz: ";
	cin >> n;
	a = new double * [n];                  																  //////////////////////////////////////////////////
	for(i=0; i<n; i++)                   															     //////// Katsayýlar matrisi için yer ayýrma///////
		a[i] = new double [n];            															    //////////////////////////////////////////////////
	
	l = new double * [n];              															       /////////////////////////////////////////////////
	for(i=0; i<n; i++)																				  ////////// l matrisi için yer ayýrma ////////////
		l[i] = new double [n];																		 /////////////////////////////////////////////////
	
	b = new double [n];				   															   // Deðerler matrisi için yer ayýrma
	d = new double [n];																			  //  d matrisi için yer ayýrma
	x = new double [n];				 															 //   x matrisi için yer ayýrma	
	
	
	for(i=0; i<n; i++)																			//////////////////////////////////////////////////
		for(j=0; j<n; j++) {	  															   //////////////////////////////////////////////////
			cout << "[" <<i+1 << "]" << "[" << j+1 << "].elamaný giriniz: ";	              //////////////////////////////////////////////////
			cin >> a[i][j];		 															 /// Katsayýlar matrisinin okunmasý ///////////////
			l[i][j]=0;           															//// l matrisi sýfýrlanýyor //////////////////////
		}                                                                                  //////////////////////////////////////////////////
		
		
	for(i=0; i<n; i++)                                                                    //////////////////////////////////////////////////
		for(j=0; j<n; j++)                                                               //// l matrisi hesaplanýyor //////////////////////
			l[j][i] = hesapL(a, j, i, n);												//////////////////////////////////////////////////
	
	cout << "Deðerler matrisini giriniz: " << endl;
	
	for(i=0; i<n; i++) {																	///////////////////////////////////////////////
		cout << "[" << i+1 << "].elemaný giriniz: ";									   ////Deðer matrisi okunuyor ////////////////////
		cin >> b[i];																	  ///////////////////////////////////////////////
	}																					 ///////////////////////////////////////////////
	
	for(i=0; i<n; i++)                                                                  ///////////////////////////////////////////////
		d[i] = hesapD(l, b, n, i);													   //// D matrisi hesaplanýyor //////////////////
	
	for(i=0; i<n; i++) {															  ////////////////////////////////////////////////
		x[i] = hesapX(l, b, d, n, i);												 ///// X matrisi hesaplanýyor ///////////////////
		cout << "X" << i+1 << " = " << x[i] << endl;								///// ve ekrana yazdýrýlýyor. //////////////////
	}
	
	system("PAUSE");
	return 0;
}
