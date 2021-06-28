#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "otel.h"
using namespace std;   


otel::otel(){
	
	toplam=0;
	sayac1=0;
	sayac2=0;
	
	oda_isletmesi();
}

void otel::oda_isletmesi(){
	
	int secim;
	
	do{
	
	cout<<"\n\t\t--HOSGELDINIZ------\n"<<endl;
	cout<<"\t\t1- Oda Rezervasyonu"<<endl;
	cout<<"\t\t2- Oda Bosaltma"<<endl;
	cout<<"\t\t3- Dolu Oda Sayisi"<<endl;
	cout<<"\t\t4- Yatak Odasi Sayisi"<<endl;
	cout<<"\t\t5- Seminer Odasi Raporu"<<endl;
	cout<<"\t\t6- Gunluk Toplam Gelir"<<endl;
	cout<<"\t\t7- Cikis Yap...\n"<<endl;
	
	cout<<"Seciminizi giriniz..."<<endl; cin>>secim;
	
	
	switch(secim){
		
		case 1:
			oda_rezervasyonu();
		break;
		
		case 2:
		    oda_bosaltma();
		break;
		
		case 3:
		    musterilerin_sayisi();
		break;
		
		case 4:
		    yatak_odasi_raporu();
		break;
		
		case 5:
		    seminer_odasi_raporu();
		break;
							
		case 6:
			gelir(); 
		break;
		
		case 7:
			exit(1);
		break;
			
		default: 
		    cout<<"Gecersiz islem..."<<endl<<"Dogru bir numara giriniz..."<<endl;  
	  }
   }while(secim!=7);
	
}
void otel::oda_rezervasyonu(){
	
	string ad,soyad;
	int secim2,xgun;
	
	cout<<"\n\t\t--Lutfen oda tipii seciniz: \n"<<endl;
	cout<<"\t\t1- Tek kisilik oda (40tl)"<<endl;
	cout<<"\t\t2- Cift kisilik oda (60tl)"<<endl;
	cout<<"\t\t3- Seminer odasi (100tl)"<<endl;
	
	cin>>secim2;
	
    switch(secim2){
    	
    	case 1:
    		
			for(int i=6; i<16; i++){
            
	            if(odalar[i]!=dolu){
	            	
	            cout<<"Adiniz: "<<endl; cin>>ad;
				cout<<"Soyadiniz: "<<endl; cin>>soyad;	
	            cout<<"Kac gun kalacaksiniz? "; cin>>xgun;
			    toplam+=xgun*40;
				sayac2++;
				
				musteri_adi[i]= new string;
				*musteri_adi[i]= ad;
				soyadi[i]= new string;
				*soyadi[i]= soyad;	
				odalar[i]=dolu;
						cout<<"\nIslem tamamlandi..\n Oda numaraniz: "<<i<<"\n\n\n\n"<<endl;
				break;	
				}
		    
    		
    		if(i==16)
			  cout<<"Maalesef butun tek kisilik odalar dolu..\n"<<endl; }
			break;
			
		case 2:
		
			for(int j=16; j<46; j++){
				
				if(odalar[j]!=dolu){
					
					cout<<"Adiniz: "<<endl; cin>>ad;
					cout<<"Soyadiniz: "<<endl; cin>>soyad;	
		            cout<<"Kac gun kalacaksiniz? "; cin>>xgun;
				    toplam+=xgun*60;
					sayac2++;
					
					musteri_adi[j]= new string;
					*musteri_adi[j]= ad;
					soyadi[j]= new string;
					*soyadi[j]= soyad;	
					odalar[j]=dolu;
						cout<<"\nIslem tamamlandi..\n Oda numaraniz: "<<j<<"\n\n\n\n"<<endl;
					break;
				}	
			
			if(j==46)
				  cout<<"Maalesef butun cift kisilik odalar dolu.\n"<<endl; }
				break;
				
		case 3:
		
			for(int k=1; k<6; k++){
				
				if(odalar[k]!=dolu){
						
						cout<<"Adiniz: "<<endl; cin>>ad;
						cout<<"Soyadiniz: "<<endl; cin>>soyad;	
			            cout<<"Kac gun kalacaksiniz? "; cin>>xgun;
					    toplam+=xgun*100;
						sayac1++;
						
						musteri_adi[k]= new string;
						*musteri_adi[k]= ad;
						soyadi[k]= new string;
						*soyadi[k]= soyad;	
						odalar[k]=dolu;
					cout<<"\nIslem tamamlandi...\nOda numarasi: "<<k<<"\n\n\n\n";
							
						break;
					}	
			   
		       if(k==6)
				  cout<<"Butun seminer odalari dolu. \n"<<endl; }
				break;
		
		default: 
		    cout<<"Lutfen dogru bir secim yapiniz..."<<endl;			
		    
		}	
}

void otel::oda_bosaltma(){
	
	cout<<"Bosaltmak istediginiz oda numarasini giriniz.."; 
	int num; cin>>num;
	
	if(odalar[num]==dolu){
		
		if(num>0 && num<6){
		
		delete musteri_adi[num];
		delete soyadi[num];
		sayac1--;
		odalar[num]=bos;
		cout<<"Oda silindi! "<<endl;
	    }
		else if(num>5 && num<46){
	    
		delete musteri_adi[num];
		delete soyadi[num];
		sayac2--;
		odalar[num]=bos;
		cout<<"Oda silindi! "<<endl;
		}
		
	}else	cout<<"\n\nLutfen oda numarasini dogru giriniz...\n\n\n"<<endl;
	
	
}

void otel::musterilerin_sayisi(){
	cout<<endl<<"Dolu oda sayisi= "<<sayac1+sayac2;
}

void otel::yatak_odasi_raporu(){
	
	if(sayac2==0){
		cout<<"Butun odalar bos..."<<endl;
	}else{
		
		cout<<"\n\n\nOda Numarasi  Musteri adi  Musteri Soyadi  "<<endl;
		cout<<"================================================="<<endl;
		for(int i=6; i<46; i++){
			if(odalar[i]==dolu)
				cout<<i<<"\t\t"<<*musteri_adi[i]<<"\t\t"<<*soyadi[i]<<"\n\n\n\n";
			
		}
		
	}
	otel();
}

void otel::seminer_odasi_raporu(){


	if(sayac1!=6){
			
			for(int i=1; i<6; i++)
				if(odalar[i]==dolu)
					cout<<"Oda numarasi: "<<i<<endl;
				
			
		}
	else cout<<"Butun seminer odalari dolu.."<<endl;	

}

void otel::gelir(){
	
	
	ofstream dosya("gelir.txt");
	
    dosya<<"\n------------------\n";
	dosya<<"Toplam gelir:"<<toplam<<"\n\n\t\t Tarih 28.06.20021"<<endl;
	dosya<<"-------------------\n";
	dosya.close();
	
	ifstream dosyaoku("gelir.txt");
	string metin;
	while(getline(dosyaoku,metin)){
        cout<<metin<<endl;
    }
	
}

int main(){
	
	otel x;
	
	return 0;
}





















