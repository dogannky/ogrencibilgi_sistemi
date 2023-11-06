#include<iostream>
#include<cstdlib>
#include<ctime>			// gerekli k�t�phaneler eklendi
#include<locale.h>//t�rk�e y�nlendirme i�in
#include<math.h>//mat k�t�phanleri
#include <iomanip>//setw i�in
using namespace std;

struct ogrenci {
	int vize, odev1, odev2, sinav1, sinav2;
	string ad;								// ogrenci adl� struct olu�turduk burada
	string soyad;
	int yilsonu_notu;
	string harf_notu;
};

int main() {

	setlocale(LC_ALL, "tr_TR");//t�rk�e y�nlendirme i�in 
	srand(time(0)); //rastgele say� fonksiyonu i�in gerekli
	ogrenci ogrenciler;		//yap�m�z� isimlendirdik
	ogrenci liste[150];				// ��renci yap�s�n� depolayan dizi. sabit say� istendi�inden 150 ile s�n�rland�rmak zorundayd�m
	float mevcud;//s�n�f mevcudu
	cout << "l�tfen s�n�f mevcudunu girin 150 den k���k olma ko�uluyla: " << endl;
	cin >> mevcud;
	while (mevcud > 150 || mevcud == 0) {
		cout << "l�tfen girdi�iniz mevcut 150 den az olsun!!!" << endl;
		cout << "l�tfen tekrar girin: ";
		cin >> mevcud;
	}
	double vizeAg, odevAg, kisaAg;
	do {

		cout << "Vize, odev ve kisa sinav agirliklarini yuzde cinsinden giriniz: ";// do while burada a��rl�k oranlar toplam� yanl�� girildi�i takdirde derste ��retti�iniz do while � kulland�m
		cin >> vizeAg >> odevAg >> kisaAg;
	} while ((vizeAg + 2 * odevAg + 2 * kisaAg) != 100);

	// random isim ve soyisimler i�in a�a��dan indeks yoluyla random kimlikler belirlenecek
	string isimler[] = { "ahmet","dogan","yusuf","emre","furkan","sude","ebrar","yusuf","nilay","samet" };
	string soyadlar[] = { "kaya","yilmaz","keles","bastem","okyay","c�nar","ates","demirden","erkan","bingol" };
	for (int i = 0; i < mevcud; i++) {

		liste[i].ad = isimler[rand() % 10];
		liste[i].soyad = soyadlar[rand() % 10];// random fonksiyonu burada 0-9 aras� indeks olu�turuyor bu sayede rondomu kuruyoruz
		//�stte listeye ekliyoruz isim ve soyisimler tabii ki de random bi�iminde

		if (i < mevcud / 5) {
			liste[i].vize = rand() % 21 + 80;
			liste[i].odev1 = rand() % 21 + 80;
			liste[i].odev2 = rand() % 21 + 80;	// vize,odev ve k�sa s�navlar�n random not assign durumlar�
			liste[i].sinav1 = rand() % 21 + 80;
			liste[i].sinav2 = rand() % 21 + 80;
		}
		else if (i >= mevcud / 5 and i < mevcud / 2) {
			liste[i].vize = rand() % 30 + 50;
			liste[i].odev1 = rand() % 30 + 50;
			liste[i].odev2 = rand() % 30 + 50;			// i le yapmam�n sonucu olarak not listesinde en y�ksek puanl� ki�iler en ba�ta															
			liste[i].sinav1 = rand() % 30 + 50;			//	yer al�yor d���kler ise a�a��da. yani s�ralama random de�il ne yaz�k ki :( 
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

	int y�lsonu_notu;

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
		else if (liste[i].yilsonu_notu < 75 and liste[i].yilsonu_notu >= 70) //her s�nav i�in kendi a��rl�k oranlar�yla �arp�p bunu y�lsonu notuna 																				
			liste[i].harf_notu = "CC";											//assign ediyorum bunlar� da struct listeme g�nderiyorum tabii b�ylece
		else if (liste[i].yilsonu_notu < 70 and liste[i].yilsonu_notu >= 58)	// ayn� �ekilde harf notlar�n� da bu �ekilde assign ettim
			liste[i].harf_notu = "DC";
		else if (liste[i].yilsonu_notu < 58 and liste[i].yilsonu_notu >= 50)
			liste[i].harf_notu = "DD";
		else
			liste[i].harf_notu = "FF";


	}
	int toplam = 0;
	double toplamkara_fark = 0; //burada bu de�i�ken her bir y�lsonu notundan ortalama fark�n�n karesini tutuyor
	int a = 0, b = 0;	//en y�ksek ve en d���k alan ��rencinin liste indeksine ula�mam i�in bu iki de�i�ken. a en b�y�k i�in b ise en k���k i�in
	for (int i = 0; i < mevcud; i++) {
		toplam += liste[i].yilsonu_notu;
	}
	double ortalama = toplam / mevcud;	//e�er ki s�n�f mevcudu 0 girilirse runtime da iken hata alacakt�r kod bu y�zden 0 girilmemeli kesinlikle
	for (int i = 0; i < mevcud; i++) {
		toplamkara_fark = pow(liste[i].yilsonu_notu - ortalama, 2) + toplamkara_fark;
	}
	double standart_sapma = sqrt(toplamkara_fark / (mevcud - 1));//standart sapma i�in bu form�l.sqrt karek�k alma fonksiyonu gerekli burada
	int eb = 0, ek = liste[0].yilsonu_notu; //eb ve ek en k���k ve en b�y��� tutan de�i�kenler
	for (int i = 0; i < mevcud; i++) {
		if (liste[i].yilsonu_notu > eb) { // eb burada en b�y�k say�y� tutuyor
			eb = liste[i].yilsonu_notu;
			a = i;

		}
		if (liste[i].yilsonu_notu < ek) {	//ek burada en b�y�k say�y� tutuyor
			ek = liste[i].yilsonu_notu;
			b = i; //burada indeksi bulmaya �al���yorum ��nk� bu indeks i�indeki ��renci profili bize laz�m ,yazd�rma i�lemi yaparken
		}
	}


	cout << "standart sapma degeri=" << "  " << standart_sapma << endl; // buralarda standart sapma gibi spesifik isteklerinizi yazd�r�yoruz
	cout << "s�n�f�n not ortalamas�=" << "  " << ortalama << endl;
	cout << "en d���k notu alan ki�inin ismi,soyismi ve notu" << ek << "   " << liste[b].ad << "  " << liste[b].soyad << endl;
	cout << "en y�ksek notu alan ki�inin ismi,soyismi ve notu " << eb << " " << liste[a].ad << "  "<<liste[a].soyad << endl;

	cout << "**********NOTLAR L�STES�******************" << endl;

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

	cout << "*******************y�l sonu harf notu istatistikleri******************" << endl;
	cout << "AA alan say�s� ve istatistiksel oran�:" << setw(3) << aa << setw(8) << (float)(aa / mevcud)<<endl;
	cout << "BA alan say�s� ve istatistiksel oran�:" << setw(3) << ba << setw(8) << (float)(ba / mevcud)<<endl;
	cout << "BB alan say�s� ve istatistiksel oran�:" << setw(3) << bb << setw(8) << (float)(bb / mevcud)<<endl;
	cout << "CB alan say�s� ve istatistiksel oran�:" << setw(3) << cb << setw(8) << (float)(cb / mevcud)<<endl;
	cout << "CC alan say�s� ve istatistiksel oran�:" << setw(3) << cc << setw(8) << (float)(cc / mevcud)<<endl;
	cout << "DC alan say�s� ve istatistiksel oran�:" << setw(3) << dc << setw(8) << (float)(dc / mevcud)<<endl;
	cout << "DD alan say�s� ve istatistiksel oran�:" << setw(3) << dd << setw(8) << (float)(dd / mevcud)<<endl;
	cout << "FF alan say�s� ve istatistiksel oran�:" << setw(3) << ff << setw(8) << (float)(ff / mevcud)<<endl;




	return 0;
}
// her bir harf notundan ka� ki�i oldu�u ve bunlar�n y�zdesi