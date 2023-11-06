#include<iostream>
#include<cstdlib>
#include<ctime>			// gerekli kütüphaneler eklendi
#include<locale.h>//türkçe yönlendirme için
#include<math.h>//mat kütüphanleri
#include <iomanip>//setw için
using namespace std;

struct ogrenci {
	int vize, odev1, odev2, sinav1, sinav2;
	string ad;								// ogrenci adlý struct oluþturduk burada
	string soyad;
	int yilsonu_notu;
	string harf_notu;
};

int main() {

	setlocale(LC_ALL, "tr_TR");//türkçe yönlendirme için 
	srand(time(0)); //rastgele sayý fonksiyonu için gerekli
	ogrenci ogrenciler;		//yapýmýzý isimlendirdik
	ogrenci liste[150];				// öðrenci yapýsýný depolayan dizi. sabit sayý istendiðinden 150 ile sýnýrlandýrmak zorundaydým
	float mevcud;//sýnýf mevcudu
	cout << "lütfen sýnýf mevcudunu girin 150 den küçük olma koþuluyla: " << endl;
	cin >> mevcud;
	while (mevcud > 150 || mevcud == 0) {
		cout << "lütfen girdiðiniz mevcut 150 den az olsun!!!" << endl;
		cout << "lütfen tekrar girin: ";
		cin >> mevcud;
	}
	double vizeAg, odevAg, kisaAg;
	do {

		cout << "Vize, odev ve kisa sinav agirliklarini yuzde cinsinden giriniz: ";// do while burada aðýrlýk oranlar toplamý yanlýþ girildiði takdirde derste öðrettiðiniz do while ý kullandým
		cin >> vizeAg >> odevAg >> kisaAg;
	} while ((vizeAg + 2 * odevAg + 2 * kisaAg) != 100);

	// random isim ve soyisimler için aþaðýdan indeks yoluyla random kimlikler belirlenecek
	string isimler[] = { "ahmet","dogan","yusuf","emre","furkan","sude","ebrar","yusuf","nilay","samet" };
	string soyadlar[] = { "kaya","yilmaz","keles","bastem","okyay","cýnar","ates","demirden","erkan","bingol" };
	for (int i = 0; i < mevcud; i++) {

		liste[i].ad = isimler[rand() % 10];
		liste[i].soyad = soyadlar[rand() % 10];// random fonksiyonu burada 0-9 arasý indeks oluþturuyor bu sayede rondomu kuruyoruz
		//üstte listeye ekliyoruz isim ve soyisimler tabii ki de random biçiminde

		if (i < mevcud / 5) {
			liste[i].vize = rand() % 21 + 80;
			liste[i].odev1 = rand() % 21 + 80;
			liste[i].odev2 = rand() % 21 + 80;	// vize,odev ve kýsa sýnavlarýn random not assign durumlarý
			liste[i].sinav1 = rand() % 21 + 80;
			liste[i].sinav2 = rand() % 21 + 80;
		}
		else if (i >= mevcud / 5 and i < mevcud / 2) {
			liste[i].vize = rand() % 30 + 50;
			liste[i].odev1 = rand() % 30 + 50;
			liste[i].odev2 = rand() % 30 + 50;			// i le yapmamýn sonucu olarak not listesinde en yüksek puanlý kiþiler en baþta															
			liste[i].sinav1 = rand() % 30 + 50;			//	yer alýyor düþükler ise aþaðýda. yani sýralama random deðil ne yazýk ki :( 
			liste[i].sinav2 = rand() % 30 + 50;
		}
		else {
			liste[i].vize = rand() % 50;
			liste[i].odev1 = rand() % 50;
			liste[i].odev2 = rand() % 50;
			liste[i].sinav1 = rand() % 50;
			liste[i].sinav2 = rand() % 50;
		}

	}

	int yýlsonu_notu;

	for (int i = 0; i < mevcud; i++) {
		liste[i].yilsonu_notu = liste[i].vize * vizeAg / 100 + liste[i].odev1 * odevAg / 100 + liste[i].odev2 * odevAg / 100 + liste[i].sinav1 * kisaAg / 100 + liste[i].sinav2 * kisaAg / 100;
		if (liste[i].yilsonu_notu >= 90)
			liste[i].harf_notu = "AA";
		else if (liste[i].yilsonu_notu < 90 and liste[i].yilsonu_notu >= 85)
			liste[i].harf_notu = "BA";
		else if (liste[i].yilsonu_notu < 85 and liste[i].yilsonu_notu >= 80)
			liste[i].harf_notu = "BB";
		else if (liste[i].yilsonu_notu < 80 and liste[i].yilsonu_notu >= 75)
			liste[i].harf_notu = "CB";
		else if (liste[i].yilsonu_notu < 75 and liste[i].yilsonu_notu >= 70) //her sýnav için kendi aðýrlýk oranlarýyla çarpýp bunu yýlsonu notuna 																				
			liste[i].harf_notu = "CC";											//assign ediyorum bunlarý da struct listeme gönderiyorum tabii böylece
		else if (liste[i].yilsonu_notu < 70 and liste[i].yilsonu_notu >= 58)	// ayný þekilde harf notlarýný da bu þekilde assign ettim
			liste[i].harf_notu = "DC";
		else if (liste[i].yilsonu_notu < 58 and liste[i].yilsonu_notu >= 50)
			liste[i].harf_notu = "DD";
		else
			liste[i].harf_notu = "FF";


	}
	int toplam = 0;
	double toplamkara_fark = 0; //burada bu deðiþken her bir yýlsonu notundan ortalama farkýnýn karesini tutuyor
	int a = 0, b = 0;	//en yüksek ve en düþük alan öðrencinin liste indeksine ulaþmam için bu iki deðiþken. a en büyük için b ise en küçük için
	for (int i = 0; i < mevcud; i++) {
		toplam += liste[i].yilsonu_notu;
	}
	double ortalama = toplam / mevcud;	//eðer ki sýnýf mevcudu 0 girilirse runtime da iken hata alacaktýr kod bu yüzden 0 girilmemeli kesinlikle
	for (int i = 0; i < mevcud; i++) {
		toplamkara_fark = pow(liste[i].yilsonu_notu - ortalama, 2) + toplamkara_fark;
	}
	double standart_sapma = sqrt(toplamkara_fark / (mevcud - 1));//standart sapma için bu formül.sqrt karekök alma fonksiyonu gerekli burada
	int eb = 0, ek = liste[0].yilsonu_notu; //eb ve ek en küçük ve en büyüðü tutan deðiþkenler
	for (int i = 0; i < mevcud; i++) {
		if (liste[i].yilsonu_notu > eb) { // eb burada en büyük sayýyý tutuyor
			eb = liste[i].yilsonu_notu;
			a = i;

		}
		if (liste[i].yilsonu_notu < ek) {	//ek burada en büyük sayýyý tutuyor
			ek = liste[i].yilsonu_notu;
			b = i; //burada indeksi bulmaya çalýþýyorum çünkü bu indeks içindeki öðrenci profili bize lazým ,yazdýrma iþlemi yaparken
		}
	}


	cout << "standart sapma degeri=" << "  " << standart_sapma << endl; // buralarda standart sapma gibi spesifik isteklerinizi yazdýrýyoruz
	cout << "sýnýfýn not ortalamasý=" << "  " << ortalama << endl;
	cout << "en düþük notu alan kiþinin ismi,soyismi ve notu" << ek << "   " << liste[b].ad << "  " << liste[b].soyad << endl;
	cout << "en yüksek notu alan kiþinin ismi,soyismi ve notu " << eb << " " << liste[a].ad << "  "<<liste[a].soyad << endl;

	cout << "**********NOTLAR LÝSTESÝ******************" << endl;

	for (int i = 0; i < mevcud; i++) {
		cout << " AD SOYAD VE YILSONU NOTU: " << setw(10) << liste[i].ad << " " << setw(10) << liste[i].soyad << setw(8) << " " << liste[i].yilsonu_notu << endl;

	}
	int aa = 0, ba = 0, bb = 0, cb = 0, cc = 0, dc = 0, dd = 0, ff = 0;
	for (int i = 0; i < mevcud; i++) {
		if (liste[i].harf_notu == "AA")
			aa++;
		else if (liste[i].harf_notu == "BA")
			ba++;
		else if (liste[i].harf_notu == "BB")
			bb++;
		else if (liste[i].harf_notu == "CB")
			cb++;
		else if (liste[i].harf_notu == "CC")
			cc++;
		else if (liste[i].harf_notu == "DC")
			dc++;
		else if (liste[i].harf_notu == "DD")
			dd++;
		else
			ff++;
	}

	cout << "*******************yýl sonu harf notu istatistikleri******************" << endl;
	cout << "AA alan sayýsý ve istatistiksel oraný:" << setw(3) << aa << setw(8) << (float)(aa / mevcud)<<endl;
	cout << "BA alan sayýsý ve istatistiksel oraný:" << setw(3) << ba << setw(8) << (float)(ba / mevcud)<<endl;
	cout << "BB alan sayýsý ve istatistiksel oraný:" << setw(3) << bb << setw(8) << (float)(bb / mevcud)<<endl;
	cout << "CB alan sayýsý ve istatistiksel oraný:" << setw(3) << cb << setw(8) << (float)(cb / mevcud)<<endl;
	cout << "CC alan sayýsý ve istatistiksel oraný:" << setw(3) << cc << setw(8) << (float)(cc / mevcud)<<endl;
	cout << "DC alan sayýsý ve istatistiksel oraný:" << setw(3) << dc << setw(8) << (float)(dc / mevcud)<<endl;
	cout << "DD alan sayýsý ve istatistiksel oraný:" << setw(3) << dd << setw(8) << (float)(dd / mevcud)<<endl;
	cout << "FF alan sayýsý ve istatistiksel oraný:" << setw(3) << ff << setw(8) << (float)(ff / mevcud)<<endl;




	return 0;
}
// her bir harf notundan kaç kiþi olduðu ve bunlarýn yüzdesi