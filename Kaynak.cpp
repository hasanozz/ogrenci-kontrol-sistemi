#include <iostream> 
#include <locale.h> //T�rk�e karakterler kullanabilmek i�in ekledi�im k�t�phane
#include <time.h> // time ifadesini kullanabilmek i�in kulland���m k�t�phane
#include <string>
#include <cmath> // matematiksel i�lemler i�in
using namespace std;
const int uye = 30;
float notCevirme(string oku, float notu); // 100'l�k de�erdeki notu harf notuna �evirmek i�in yazd�m. Fonksiyonun i�eri�ini mainin alt�nda girdim
float notKontrol(string s, float min, float max); // notun 0-100 aras�nda olup olmad���n� kontrol eden fonksiyon. Fonksiyonun i�eri�ini mainin alt�nda girdim

struct Tarih
{			// do�um tarihi i�in struct tarih veri tipi olu�turdum
	int gun, ay, yil;
};

struct ogrenci
{		// ��rencilerin isim, soyisim ve puanlar� i�in struct ogrenci veri tipi olu�turdum
	string isim[100], soyisim[100];
	float ogrenciNo[100], kisaSinav1[100], kisaSinav2[100], odev1[100], odev2[100], proje[100], vize[100], final[100], basariNotu[100];
};


int main() {
	srand(time(NULL)); // her �al��t�r�ld���nda ayn� diziyi olu�turmamas� i�in ekledim

	setlocale(LC_ALL, "Turkish"); //T�rk�e karakterleri kullanmak i�in

	string isimler[uye] = { "�zg�r", "Kaan", "Erhan", "Emir", "Emre", "Eser", "Furkan", "G�ray", "F�rat", "Fatih", "Tunahan", "Selin", "Elif", "Ceyda", "Mehmet", "Yunus", "Mert", "Mete", "Merve", "Eren", "Ceren", "Yasemin", "Seda", "S�la", "Melisa", "P�nar", "Ahmet", "G�khan", "O�uz","Ba�ak" };
	string soyisimler[uye] = { "�zdemir", "Selimo�lu", "Aksoy", "Ayd�n", "Akbey", "Kaya", "Balkaya", "Okutay", "Sepetci", "Yalmanc�", "�ak�r", "�ahin", "G�kdemir", "Odaba��", "Y�ld�z", "Girgin", "Balc�ba��", "Ayaz", "Sar�ta�","�i�man", "T�rkmen", "Sar�soy", "G�ken", "Ayd�n", "Kurtulu�", "Ersoy", "Ko�ak", "Y�lmaz","Keskin","Altun���k" };
	ogrenci ogrenciler;
	char secim1, secim2;
	bool kontrol = 1;
	while (kontrol)
	{
		cout << "1.Se�enek: ��renci bilgileri rastgele atans�n.[1]\n2.Se�enek: ��renci bilgileri manuel girilsin.[2]" << endl << " Tercih: ";
		cin >> secim1;

		if (!(secim1 == '1' || secim1 == '2'))
			cout << "Hatal� giri� yapt�n�z. Tekrar Deneyiniz." << endl;
		else
			kontrol = 0;
	}

	if (secim1 == '1') // ��renci bilgilerinin rastgele atanmas�n� isterse bu ko�ul sa�lanacak
	{

		system("cls");		// �nceki men� ekran�n�n silinmesi i�in

		for (int i = 0; i < 100; i++) //random bir �ekilde ��renci bilgilerinin da��t�lmas� i�in for d�ng�s� kulland�m
		{
			int gecici1, gecici2;
			gecici1 = rand() % 30;					      // gecici bir int de�eri tan�mlay�p i�ine rastgele 0-30 aras�nda say� atanmas� i�in yazd�m
			gecici2 = rand() % 30;						  // gecici bir int de�eri tan�mlay�p i�ine rastgele 0-30 aras�nda say� atanmas� i�in yazd�m
			ogrenciler.isim[i] = isimler[gecici1];        // i�ine rastgele say� atanan gecici de�erinin isimler dizisinde kar��l�k gelen isim, ogrenciler struct veri tipindeki isim dizisine girildi
			ogrenciler.soyisim[i] = soyisimler[gecici2];  // i�ine rastgele say� atanan gecici de�erinin soyisimler dizisinde kar��l�k gelen soyisim, ogrenciler struct veri tipindeki soyisim dizisine girildi
			ogrenciler.ogrenciNo[i] = i + 1;			  // 100 ��renciye 1-100 aras�nda ��renci numaras� atand�


			if (i >= 0 && i < 10)
			{						  // ��rencilerin %10'unun notlar�n�n 0-40 aras�nda olmas�n� sa�lar
				ogrenciler.final[i] = rand() % 40;
				ogrenciler.vize[i] = rand() % 40;
				ogrenciler.kisaSinav1[i] = rand() % 40;
				ogrenciler.kisaSinav2[i] = rand() % 40;
				ogrenciler.odev1[i] = rand() % 40;
				ogrenciler.odev2[i] = rand() % 40;
				ogrenciler.proje[i] = rand() % 40;
			}

			else if (i >= 10 && i < 60) {					// ��rencilerin %50'sinin notlar�n�n 40-70 aras�nda olmas�n� sa�lar
				ogrenciler.final[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.vize[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.kisaSinav1[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.kisaSinav2[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.odev1[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.odev2[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.proje[i] = rand() % (70 - 41 + 1) + 41;
			}

			else if (i >= 60 && i < 75) {			     // ��rencilerin %15'inin notlar�n�n 70-80 aras�nda olmas�n� sa�lar
				ogrenciler.final[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.vize[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.kisaSinav1[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.kisaSinav2[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.odev1[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.odev2[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.proje[i] = rand() % (80 - 71 + 1) + 71;
			}

			else if (i >= 75 && i < 100) {				// ��rencilerin %25'inin notlar�n�n 80-100 aras�nda olmas�n� sa�lar
				ogrenciler.final[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.vize[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.kisaSinav1[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.kisaSinav2[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.odev1[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.odev2[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.proje[i] = rand() % (100 - 81 + 1) + 81;
			}
		}

		for (int i = 0; i < 100; i++) // ��rencilerin ba�ar� notlar�n� hesaplamak i�in for d�ng�s� ekledim
		{
			float yil_iciNot = ogrenciler.vize[i] * 0.5
				+ ogrenciler.kisaSinav1[i] * 0.07
				+ ogrenciler.kisaSinav2[i] * 0.07
				+ ogrenciler.odev1[i] * 0.1
				+ ogrenciler.odev2[i] * 0.1
				+ ogrenciler.proje[i] * 0.16;

			ogrenciler.basariNotu[i] = yil_iciNot * 0.55 + ogrenciler.final[i] * 0.45;
		}

		while (1) //kullan�c� ��kmak isteyene kadar men�ye d�nd�rs�n diye sonsuz d�ng� ekledim
		{
			float enYuksek = ogrenciler.basariNotu[0];
			float enDusuk = ogrenciler.basariNotu[0];

			cout << "[1] S�n�f listesi yazd�r�ls�n\n[2] S�n�f�n en y�ksek notu hesaplans�n\n[3] S�n�f�n en d���k notu hesaplans�n\n[4] S�n�f ortalamas� hesaplans�n";
			cout << "\n[5] S�n�f�n standart sapmas� hesaplans�n\n[6] Ba�ar� notu belirli aral�kta olan ��rencileri s�ralamak i�in";
			cout << "\n[7] Ba�ar� notu belirtilen de�erin alt�nda olan ��rencilerin s�ralanmas� i�in\n[8] Ba�ar� notu belirtilen de�erin �st�nde olan ��rencilerin s�ralanmas� i�in";
			cout << "\n[Q] ��k�� yapmak i�in" << endl;

			cin >> secim2;

			if (secim2 == 'Q' || secim2 == 'q') // kullan�c� Q veya q harfini girerse ��k�� yapar
				break;

			else if (secim2 == '1') // kullan�c� 1'e basarsa s�n�f listesini bast�r�r
			{
				system("cls");
				for (int i = 0; i < 100; i++)
				{
					cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " Ba�ar� notu: " << ogrenciler.basariNotu[i] << endl;

					if (i == 19) {			// 20 ��renci bas�ld���nda program durur ve kullan�c�n�n herhangi bir tu�a basmas�n� ister
						system("pause");
						system("cls");
					}
					if (i == 39) {		// 20 ��renci bas�ld���nda program durur ve kullan�c�n�n herhangi bir tu�a basmas�n� ister
						system("pause");
						system("cls");
					}
					if (i == 59) {			// 20 ��renci bas�ld���nda program durur ve kullan�c�n�n herhangi bir tu�a basmas�n� ister
						system("pause");
						system("cls");
					}
					if (i == 79) {			// 20 ��renci bas�ld���nda program durur ve kullan�c�n�n herhangi bir tu�a basmas�n� ister
						system("pause");
						system("cls");
					}
					if (i == 99) {			// 20 ��renci bas�ld���nda program durur ve kullan�c�n�n herhangi bir tu�a basmas�n� ister
						system("pause");
						system("cls");
					}


				}
			}


			else if (secim2 == '2')
			{
				int d; // hangi ��rencinin en y�ksek nota sahip oldu�unu belirtebilmek i�in tan�mlad�m
				system("cls");

				for (int i = 0; i < 100; i++) /*d�ng� basariNotu dizisinin t�m elemanlar�ndan ge�ecek e�er basariNotu[i], enYuksek'ten b�y�kse
											  enYuksek'in yeni de�eri basariNotu[i] olacak. Bu �ekilde en y�ksek ba�ar� notu bulunmu� olunacak*/
				{
					if (ogrenciler.basariNotu[i] > enYuksek)  //d�ng� basariNotu dizi elemanlar� i�inde ge�erken e�er eleman enYuksek de�erinden b�y�kse yeni enYuksek de�eri o eleman olur
					{
						enYuksek = ogrenciler.basariNotu[i];
						d = i;
					}
				}
				cout << "En y�ksek ba�ar� puan, " << enYuksek << " puan ile " << ogrenciler.ogrenciNo[d] << " Nolu " << ogrenciler.isim[d] << " " << ogrenciler.soyisim[d] << " adl� ��renciye aittir. " << endl;
				system("pause");
				system("cls");
			}
			else if (secim2 == '3')  /*D�ng� basariNotu dizisinin t�m elemanlar�ndan ge�ecek e�er basariNotu[i], enuDusuk'ten kucukse enDusuk'un yeni de�eri basariNotu[i] olur*/
			{
				int a = 0;
				system("cls");

				for (int i = 99; i >= 0; i--)
				{
					if (ogrenciler.basariNotu[i] < enDusuk) {	//e�er basariNotu[i], enuDusuk'ten kucukse enDusuk'un yeni de�eri basariNotu[i] olur 
						enDusuk = ogrenciler.basariNotu[i];
						a = i;
					}
				}
				cout << "En d���k ba�ar� puan, " << enDusuk << " puan ile " << ogrenciler.ogrenciNo[a] << " Nolu " << ogrenciler.isim[a] << " " << ogrenciler.soyisim[a] << " adl� ��renciye aittir. " << endl;
				system("pause");
				system("cls");
			}

			else if (secim2 == '4') // S�n�f ortalamas�n� bulmak i�in
			{
				system("cls");
				float ortalama = 0;
				for (int i = 0; i < 100; i++) //i artt�k�a basariNotu'nun yeni de�erini ortalama isimli de�i�kene ekleyecek
					ortalama += ogrenciler.basariNotu[i];

				cout << "S�n�f�n Not ortalamas�: " << ortalama / 100 << endl;
				system("pause");
				system("cls");
			}

			else if (secim2 == '5') // e�er kullan�c� 5 de�erini girerse s�n�f�n standart sapmas�n� hesaplayacak
			{
				system("cls");
				float toplam = 0, ort, islem, sonuc = 0;
				for (int i = 0; i < 100; i++)  // i artt�k�a basariNotu'nun yeni de�erini toplam adl� de�i�kene atayacak
					toplam += ogrenciler.basariNotu[i];
				ort = toplam / 100;

				for (int j = 0; j < 100; j++)   // her ��rencinin basariNotu'nu aritmetik ortalamadan ��kar�p karesini al�nacak ve sonuc adl� de�i�kene ekleyecek
				{
					islem = (ogrenciler.basariNotu[j] - ort) * (ogrenciler.basariNotu[j] - ort);
					sonuc += islem;
				}
				cout << "S�n�f�n standart sapmas�: " << sqrt(sonuc / 99) << endl;   // sonuc ��renci say�s�n�n 1 eksi�ine b�l�n�p karek�k�n� al�nacak
				system("pause");
				system("cls");
			}

			else if (secim2 == '6') // secim2'de 6 de�eri girilirse kullan�c��n belirledi�i 2 say� aras�ndaki notlara sahip ��renciler ekrana bast�r�lacak
			{
				system("cls");
				float sayi1 = 0, sayi2 = 0;
				cout << "Aral���n ba�lang�� de�eri: "; cin >> sayi1;
				cout << "Aral���n biti� de�eri: "; cin >> sayi2;
				system("cls");

				for (int i = 0; i < 100; i++) {
					if (ogrenciler.basariNotu[i] >= sayi1 && ogrenciler.basariNotu[i] <= sayi2)  // d�ng� t�m basariNotlar� dizisini gezecek ve e�er say� kullan�c�n�n belirledi�i aral�ktaysa ekrana bast�racak
						cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
				}
				system("pause");
				system("cls");
			}

			else if (secim2 == '7')  //secim2'de 7 de�eri girilirse kullan�c�n�n belirledi�i say�n�n alt�ndaki notlara sahip ��renciler ekrana bas�lacak
			{
				system("cls");
				float sayi;
				cout << "Hangi de�erin alt�ndaki say�lar� ekrana yaz�ls�n: "; cin >> sayi;

				for (int i = 0; i < 100; i++) {
					if (sayi > ogrenciler.basariNotu[i])  // d�ng� basariNotu dizisini gezecek e�er say� kullan�c�n�n belirledi�i de�erin alt�ndaysa ekrana bast�r�r
						cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
				}
				system("pause");
				system("cls");
			}

			else if (secim2 == '8') // secim2'de 8 de�eri girilirse kullan�c�n�n belirledi�i say�n�n �st�ndeki notlara sahip ��renciler ekrana bas�lacak
			{
				system("cls");
				float sayi3;
				cout << "Hangi de�erin �st�ndeki say�lar ekrana yaz�ls�n: "; cin >> sayi3;

				for (int i = 0; i < 100; i++) {
					if (sayi3 < ogrenciler.basariNotu[i]) // d�ng� basariNotu dizisini gezecek e�er say� kullan�c�n�n belirledi�i de�erin �st�ndeyse ekrana bast�r�r
						cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
				}
				system("pause");
				system("cls");
			}

		}


	}

	else if (secim1 == '2') // kullan�c� secim1'de 2 de�erini girerse 2.Se�enek (��renci bilgilerini kullan�c�n�n kendisi girdi�i se�enek) devreye girecek
	{
		system("cls");
		for (int i = 0; i < 100; i++)
		{

			string isim, soyisim;
			cout << i + 1 << ". ��rencinin Ad�: " << endl;
			cin >> ogrenciler.isim[i];
			cout << i + 1 << ". ��rencinin Soyad�: " << endl;
			cin >> ogrenciler.soyisim[i];


			ogrenciler.ogrenciNo[i] = i + 1;

			while (1) {			// kullan�c� 0-100 aras�nda bir say� girene kadar d�ng�den ��kamaz
				cout << "1.K�sa s�nav notu: ";
				cin >> ogrenciler.kisaSinav1[i];
				if (ogrenciler.kisaSinav1[i] >= 0 && ogrenciler.kisaSinav1[i] <= 100)
					break;
			}
			while (1) {		// kullan�c� 0-100 aras�nda bir say� girene kadar d�ng�den ��kamaz
				cout << "2.K�sa s�nav notu: ";
				cin >> ogrenciler.kisaSinav2[i];
				if (ogrenciler.kisaSinav2[i] >= 0 && ogrenciler.kisaSinav2[i] <= 100)
					break;
			}
			while (1) {		// kullan�c� 0-100 aras�nda bir say� girene kadar d�ng�den ��kamaz
				cout << "Vize notu: ";
				cin >> ogrenciler.vize[i];
				if (ogrenciler.vize[i] >= 0 && ogrenciler.vize[i] <= 100)
					break;
			}
			while (1) {		// kullan�c� 0-100 aras�nda bir say� girene kadar d�ng�den ��kamaz
				cout << "Proje notu: ";
				cin >> ogrenciler.proje[i];
				if (ogrenciler.proje[i] >= 0 && ogrenciler.proje[i] <= 100)
					break;
			}
			while (1) {		// kullan�c� 0-100 aras�nda bir say� girene kadar d�ng�den ��kamaz
				cout << "1.�dev notu: ";
				cin >> ogrenciler.odev1[i];
				if (ogrenciler.odev1[i] >= 0 && ogrenciler.odev1[i] <= 100)
					break;
			}
			while (1) {		// kullan�c� 0-100 aras�nda bir say� girene kadar d�ng�den ��kamaz
				cout << "2.�dev notu: ";
				cin >> ogrenciler.odev2[i];
				if (ogrenciler.odev2[i] >= 0 && ogrenciler.odev2[i] <= 100)
					break;
			}
			while (1) 		// kullan�c� 0-100 aras�nda bir say� girene kadar d�ng�den ��kamaz
				cout << "Final notu: ";
			cin >> ogrenciler.final[i];
			if (ogrenciler.final[i] >= 0 && ogrenciler.final[i] <= 100)
				break;
		}
		system("pause");
		system("cls");
	}
	for (int i = 0; i < 100; i++) // ��rencilerin ba�ar� notlar�n� hesaplamak i�in for d�ng�s� ekledim
	{
		float yil_iciNot = ogrenciler.vize[i] * 0.5
			+ ogrenciler.kisaSinav1[i] * 0.07
			+ ogrenciler.kisaSinav2[i] * 0.07
			+ ogrenciler.odev1[i] * 0.1
			+ ogrenciler.odev2[i] * 0.1
			+ ogrenciler.proje[i] * 0.16;

		ogrenciler.basariNotu[i] = yil_iciNot * 0.55 + ogrenciler.final[i] * 0.45;
	}

	while (1)	//kullan�c� ��kmak isteyene kadar men�ye d�nd�rs�n diye sonsuz d�ng� ekledim
	{
		float enYuksek = ogrenciler.basariNotu[0];
		float enDusuk = ogrenciler.basariNotu[0];

		cout << "[1] S�n�f listesi yazd�r�ls�n\n[2] S�n�f�n en y�ksek notu hesaplans�n\n[3] S�n�f�n en d���k notu hesaplans�n\n[4] S�n�f ortalamas� hesaplans�n";
		cout << "\n[5] S�n�f�n standart sapmas� hesaplans�n\n[6] Ba�ar� notu belirli aral�kta olan ��rencileri s�ralamak i�in";
		cout << "\n[7] Ba�ar� notu belirtilen de�erin alt�nda olan ��rencilerin s�ralanmas� i�in\n[8] Ba�ar� notu belirtilen de�erin �st�nde olan ��rencilerin s�ralanmas� i�in";
		cout << "\n[Q] ��k�� yapmak i�in" << endl;

		cin >> secim2;

		if (secim2 == 'Q' || secim2 == 'q') // kullan�c� q veya Q girerse programdan ��kar
			break;

		else if (secim2 == '1') // kullan�c� secim2de 1 de�erini girerse s�n�f listesini bast�r�r
		{
			system("cls");
			for (int i = 0; i < 100; i++)
			{
				cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " Ba�ar� notu: " << ogrenciler.basariNotu[i] << endl;

				if (i == 19) {		// 20 ��renci bas�ld���nda program durur ve kullan�c�n�n herhangi bir tu�a basmas�n� ister
					system("pause");
					system("cls");
				}
				if (i == 39) {		// 20 ��renci bas�ld���nda program durur ve kullan�c�n�n herhangi bir tu�a basmas�n� ister
					system("pause");
					system("cls");
				}
				if (i == 59) {		// 20 ��renci bas�ld���nda program durur ve kullan�c�n�n herhangi bir tu�a basmas�n� ister
					system("pause");
					system("cls");
				}
				if (i == 79) {		// 20 ��renci bas�ld���nda program durur ve kullan�c�n�n herhangi bir tu�a basmas�n� ister
					system("pause");
					system("cls");
				}
				if (i == 99) {		// 20 ��renci bas�ld���nda program durur ve kullan�c�n�n herhangi bir tu�a basmas�n� ister
					system("pause");
					system("cls");
				}
			}
			system("pause");
			system("cls");
		}


		else if (secim2 == '2') // kullan�c� 2 de�erini girerse en y�ksek nota sahip olan ��renciyi ekrana bast�r�r
		{
			int d; // hangi ��rencinin en y�ksek nota sahip oldu�unu belirtebilmek i�in tan�mlad�m
			system("cls");

			for (int i = 0; i < 100; i++) /*d�ng� basariNotu dizisinin t�m elemanlar�ndan ge�ecek e�er basariNotu[i], enYuksek'ten b�y�kse
										  enYuksek'in yeni de�eri basariNotu[i] olacak. Bu �ekilde en y�ksek ba�ar� notu bulunmu� olunacak*/
			{
				if (ogrenciler.basariNotu[i] > enYuksek) // e�er ogrenciler.basariNotu[i] enYuksek'ten b�y�kse enYuksek'in yeni de�eri ogrenciler.basariNotu[i] olur
				{
					enYuksek = ogrenciler.basariNotu[i];
					d = i;
				}
			}
			cout << "En y�ksek ba�ar� puan, " << enYuksek << " puan ile " << ogrenciler.ogrenciNo[d] << " Nolu " << ogrenciler.isim[d] << " " << ogrenciler.soyisim[d] << " adl� ��renciye aittir. " << endl;
			system("pause");
			system("cls");
		}
		else if (secim2 == '3')  // kullan�c� 3 de�erini girerse en d���k nota sahip olan ��renciyi ekrana bast�r�r
		{
			int a = 0;
			system("cls");

			for (int i = 99; i >= 0; i--)
			{
				if (ogrenciler.basariNotu[i] < enDusuk) { // e�er ogrenciler.basariNotu[i] enDusuk'ten k���kse enDusuk'�n yeni de�eri ogrenciler.basariNotu[i] olur
					enDusuk = ogrenciler.basariNotu[i];
					a = i;
				}
			}
			cout << "En d���k ba�ar� puan, " << enDusuk << " puan ile " << ogrenciler.ogrenciNo[a] << " Nolu " << ogrenciler.isim[a] << " " << ogrenciler.soyisim[a] << " adl� ��renciye aittir. " << endl;
			system("pause");
			system("cls");
		}

		else if (secim2 == '4') // kullan�c� 4 de�erini girerse s�n�f ortalamas�n� ekrana bast�r�r
		{
			system("cls");
			float ortalama = 0;
			for (int i = 0; i < 100; i++) // i artt�k�a basariNotu dizisinin yeni eleman�n� ortalamaya ekler
				ortalama += ogrenciler.basariNotu[i];

			cout << "S�n�f�n Not ortalamas�: " << ortalama / 100 << endl;
			system("pause");
			system("cls");
		}

		else if (secim2 == '5')  // kullan�c� 5 de�erini girerse s�n�f�n standart sapmas�n� ekrana yazd�r�r
		{
			system("cls");
			float toplam = 0, ort, islem, sonuc = 0;
			for (int i = 0; i < 100; i++)  // i artt�k�a basariNotu'nun yeni eleman�n� toplama ekler
				toplam += ogrenciler.basariNotu[i];
			ort = toplam / 100;

			for (int j = 0; j < 100; j++)   // s�rayla her ��reninin notunu s�n�f ortalamas�ndan ��kar�p karesini al�r ve sonuca ekler
			{
				islem = (ogrenciler.basariNotu[j] - ort) * (ogrenciler.basariNotu[j] - ort);
				sonuc += islem;
			}
			cout << "S�n�f�n standart sapmas�: " << sqrt(sonuc / 99) << endl;  // sonucu total ��renci say�n�n bir eksi�ine b�l�p karek�k�n� al�r ve ekrana yazd�r�r
			system("pause");
			system("cls");
		}

		else if (secim2 == '6')  // Kullan�c�n�n belirledi�i 2 de�er aras�ndaki notlara sahip ��rencileri ekrana yazd�r�r
		{
			system("cls");
			float sayi1 = 0, sayi2 = 0;
			cout << "Aral���n ba�lang�� de�eri: "; cin >> sayi1;
			cout << "Aral���n biti� de�eri: "; cin >> sayi2;
			system("cls");

			for (int i = 0; i < 100; i++) {
				if (ogrenciler.basariNotu[i] >= sayi1 && ogrenciler.basariNotu[i] <= sayi2)  // e�er basariNotu'nun i. eleman� kullan�c�n�n belirledi�i aral�ktaysa ekrana yazar
					cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
			}
			system("pause");
			system("cls");
		}

		else if (secim2 == '7') // kullan�c�n�n belirledi�i de�erin alt�ndaki notlara sahip olan ��rencileri ekrana yazd�r�r
		{
			system("cls");
			float sayi;
			cout << "Hangi de�erin alt�ndaki say�lar� ekrana yaz�ls�n: "; cin >> sayi;

			for (int i = 0; i < 100; i++) {
				if (sayi > ogrenciler.basariNotu[i])  // e�er basariNotu'nun i. eleman� kullan�c�n�n girdi�i say�dan d���kse ekrana yazd�r�r
					cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
			}
			system("pause");
			system("cls");
		}

		else if (secim2 == '8') // kullan�c�n�n belirledi�i de�erin �st�ndeki notlara sahip olan ��rencileri ekrana yazd�r�r
		{
			system("cls");
			float sayi3;
			cout << "Hangi de�erin �st�ndeki say�lar ekrana yaz�ls�n: "; cin >> sayi3;

			for (int i = 0; i < 100; i++) {
				if (sayi3 < ogrenciler.basariNotu[i])  // e�er basariNotu'nun i.eleman� kullan�c�n�n belirledi�i say�dan b�y�kse ekrana yazd�r�r
					cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
			}
			system("pause");
			system("cls");
		}

	}


	return 0;
}



float notKontrol(string s, float min, float max) {
	float sayi;

	do {		// kullan�c� min ile max aras�nda de�er girene kadar s'yi ekrana bast�r�p de�er girmesini ister
		cout << s; cin >> sayi;
	} while (!(sayi >= min && sayi <= max));

	return sayi;
}

float notCevirme(string oku, float notu) {
	if (notu >= 90)  //  e�er notu 90'dan b�y�k veya e�itse oku de�i�keni ve AA ekrana yaz�l�r
		cout << oku << "AA";
	else if (notu >= 85)     // e�er notu 85 ile 90 aras�ndaysa oku de�i�keni ve BA ekrana yaz�l�r
		cout << oku << "BA";
	else if (notu >= 80)  // e�er notu 80 ile 90 aral���ndaysa oku de�i�keni ve BB ekrana yaz�l�r
		cout << oku << "BB";
	else if (notu >= 75)    // e�er notu 75 ile 80 aral���ndaysa oku de�i�keni ve CB ekrana yaz�l�r
		cout << oku << "CB";
	else if (notu >= 65)	// e�er notu 65 ile 70 aral���ndaysa oku de�i�keni ve CC ekrana yaz�l�r
		cout << oku << "CC";
	else if (notu >= 58)	// e�er notu 58 ile 65 aral���ndaysa oku de�i�keni ve DC ekrana yaz�l�r
		cout << oku << "DC";
	else if (notu >= 50)	// e�er notu 50 ile 58 aral���ndaysa oku de�i�keni ve DD ekrana yaz�l�r
		cout << oku << "DD";
	else if (notu >= 40)	// e�er notu 40 ile 50 aral���ndaysa oku de�i�keni ve DF ekrana yaz�l�r
		cout << oku << "DF";
	else                    // di�er ko�ullarda (notu 40'�n alt�ndaysa) oku de�i�keni ve FF ekrana yaz�l�r  
		cout << oku << "FF";
	return notu;
}