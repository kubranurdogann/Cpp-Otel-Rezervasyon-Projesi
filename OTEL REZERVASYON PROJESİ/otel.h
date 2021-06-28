#ifndef OTEL_H
#define OTEL_H
#include <string>
using namespace std; 

class  otel{
	
	
	string *musteri_adi[100],*soyadi[100];
	int toplam,sayac1,sayac2;
	
	enum statu{
		bos,dolu
	}odalar[45];
	
	public:
		
		otel();
		void oda_isletmesi();
		void oda_rezervasyonu();
		void oda_bosaltma();
		void musterilerin_sayisi();
		void yatak_odasi_raporu();
		void seminer_odasi_raporu();
		void gelir();

};

#endif

