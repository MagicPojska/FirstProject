#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct klijenti {
	string ime;
	string prezime;
	string zaposlen;
	float radniStaz = 0;
	long double kredit = 0;
	int brojGodina = 0;
	int dan = 0;
	int mjesec = 0;
	int godina = 0;
	long long int jmbg = 0;

	string imePrvogZiranta;
	string prezimePrvogZiranta;
	string zaposlenostPrvogZiranta;
	float radniStazPrvogZiranta = 0;

	string imeDrugogZiranta;
	string prezimeDrugogZiranta;
	string zaposlenostDrugogZiranta;
	float radniStazDrugogZiranta = 0;
};
struct zaUpisPodatakaIzDatoteke {
	string ime;
	string prezime;
	long long int jmbg = 0;
	long double kredit = 0;
	long double ukupnoZaVratiti = 0;
	int brojRata = 0;
	int dan = 0;
	int mjesec = 0;
	int godina = 0;
	string imePrvogZiranta;
	string prezimePrvogZiranta;
	string imeDrugogZiranta;
	string prezimeDrugogZiranta;
};

/*--------------------------------------------------Prototipi funkcija--------------------------------------------------*/

void login();
string unosPasswordaSaAsteriksom(string password, int ch);
zaUpisPodatakaIzDatoteke uplataRatePrepis(zaUpisPodatakaIzDatoteke pretraga[], zaUpisPodatakaIzDatoteke prepis[]);
int ispisMenijaINavigacijaKrozMeni(zaUpisPodatakaIzDatoteke pretraga[], zaUpisPodatakaIzDatoteke prepis[]);
void informacije();
void kredit(klijenti klijent[]);
void uplataRate(zaUpisPodatakaIzDatoteke pretraga[], zaUpisPodatakaIzDatoteke prepis[]);
double kalkulator(klijenti klijent[]);
void kalkulatorprovjera();
int brojKlijenata(zaUpisPodatakaIzDatoteke pretraga[]);
void pretragaKlijenata(zaUpisPodatakaIzDatoteke pretraga[]);
void loading();
void gotoxy();

/*--------------------------------------------------Prototipi funkcija--------------------------------------------------*/


/*--------------------------------------------------MAIN FUNKCIJA--------------------------------------------------*/
int main() {
	login();
	zaUpisPodatakaIzDatoteke pretraga[30];
	zaUpisPodatakaIzDatoteke prepis[30];
	(void)uplataRatePrepis(pretraga, prepis);
	ispisMenijaINavigacijaKrozMeni(pretraga, prepis);
	return 0;
	}
/*--------------------------------------------------MAIN FUNKCIJA--------------------------------------------------*/

/*--------------------------------------------------TIJELA FUNKCIJA--------------------------------------------------*/
void login() {
	system("cls");
	int i = 0;
	int j = 0;
	string username;
	string password;
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "\t\t\t\t\t* >-> Unos pristupnih podataka <-< *" << endl;
	cout << "\t\t\t\t\t************************************" << endl;
	cout << endl;
	do {
		cout << "\t\t\t\t\tUnesite username: ";
		username.clear();
		cin >> username;
		if (username != "ishaksmajic" && username != "magicpojska" && username != "adinvrbic") {
			username.clear();
			cin.ignore();
			cout << "\t\t\t\t\tUnijeli ste nepostojeci username!" << endl;
			i++;
			if (i == 3) {
				cout << "\n\t\t\tUnijeli ste previse puta pogresan username, program ce se sada iskljuciti...";
				loading();
				exit(0);
			}
		}
	} while (username != "ishaksmajic" && username != "magicpojska" && username != "adinvrbic");


	int ch = 0;
	cout << "\t\t\t\t\tUnesite password: ";
	password = unosPasswordaSaAsteriksom(password, ch);
	cout << endl;
	cout << endl;

	while (j < 2) {
		if (username == "ishaksmajic" && password == "edge") {
			username.clear();
			cin.ignore();
			loading();
			break;
		}
		else if (username == "ishaksmajic" && password != "edge") {
			cout << "\t\t\t\t\tPogresna sifra!" << endl;
			cout << "\t\t\t\t\tPokusajte ponovo: ";
			password = unosPasswordaSaAsteriksom(password, ch);
			j++;
			cout << endl;
			if (username == "ishaksmajic" && password == "edge") {
				username.clear();
				cin.ignore();
				loading();
				break;
			}
		}
		else if (username == "adinvrbic" && password == "urgot123") {
			username.clear();
			cin.ignore();
			loading();
			break;
		}
		else if (username == "adinvrbic" && password != "urgot123") {
			cout << "\t\t\t\t\tPogresna sifra, pokusajte ponovo: ";
			password = unosPasswordaSaAsteriksom(password, ch);
			j++;

			cout << endl;
			if (username == "adinvrbic" && password == "urgot123") {
				username.clear();
				cin.ignore();
				loading();
				break;
			}
		}
		else if (username == "magicpojska" && password == "yasuomain") {
			username.clear();
			cin.ignore();
			loading();
			break;
		}
		else if (username == "magicpojska" && password != "yasuomain") {
			cout << "\t\t\t\t\tPogresna sifra, pokusajte ponovo: ";
			password = unosPasswordaSaAsteriksom(password, ch);
			j++;
			if (username == "magicpojska" && password == "yasuomain") {
				username.clear();
				cin.ignore();
				loading();
				break;
			}
			cout << endl;
		}
		if (j == 2) {
			cout << "\t\t\tUnijeli ste previse puta pogresnu sifru, program ce se sada iskljuciti...";
			loading();
			exit(0);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

string unosPasswordaSaAsteriksom(string password, int ch) {
	password.clear();
	while (ch = _getch()) {
		if (ch != 13) {
			cout << "*";
		}
		password += ch;
		if (ch == 13) {
			break;
		}
	}
	password.erase(password.length() - 1);
	return password;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

zaUpisPodatakaIzDatoteke uplataRatePrepis(zaUpisPodatakaIzDatoteke pretraga[], zaUpisPodatakaIzDatoteke prepis[]) {
	int brojKorisnika = brojKlijenata(pretraga);
	int i = 0;
	for (i = 0; i < brojKorisnika; i++) {
		prepis[i].ime = pretraga[i].ime;
		prepis[i].prezime = pretraga[i].prezime;
		prepis[i].jmbg = pretraga[i].jmbg;
		prepis[i].kredit = pretraga[i].kredit;
		prepis[i].ukupnoZaVratiti = pretraga[i].ukupnoZaVratiti;
		prepis[i].brojRata = pretraga[i].brojRata;
		prepis[i].dan = pretraga[i].dan;
		prepis[i].mjesec = pretraga[i].mjesec;
		prepis[i].godina = pretraga[i].godina;
	}
	return prepis[i];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int ispisMenijaINavigacijaKrozMeni(zaUpisPodatakaIzDatoteke pretraga[], zaUpisPodatakaIzDatoteke prepis[]) {
	int pointer = 0;
	klijenti klijent[1];
	string Menu[7] = { "Informacije", "Podizanje kredita", "Uplata rate" , "Kalkulator za provjeru", "Provjera stanja kredita kod zeljenog klijenta", "Izlaz", "Logout" };

	while (true) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t\t\t\t\t\t   MENU " << endl << endl;
		cout << "\t\t\t  * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
		for (int i = 0; i < 7; i++) {
			if (i == pointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				if (i == 3) {
					cout << "\t\t\t  *  " << Menu[i] << "\t\t\t\t" << "*" << endl;
				}
				else if (i == 4) {
					cout << "\t\t\t  *  " << Menu[i] << "\t" << "*" << endl;
				}
				else if (i == 5) {
					cout << "\t\t\t  *  " << Menu[i] << "\t\t\t\t\t\t" << "*" << endl;
				}
				else if (i == 6) {
					cout << "\t\t\t  *  " << Menu[i] << "\t\t\t\t\t\t" << "*" << endl;
				}
				else {
					cout << "\t\t\t  *  " << Menu[i] << "\t\t\t\t\t" << "*" << endl;
				}
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				if (i == 3) {
					cout << "\t\t\t  *  " << Menu[i] << "\t\t\t\t" << "*" << endl;
				}
				else if (i == 4) {
					cout << "\t\t\t  *  " << Menu[i] << "\t" << "*" << endl;
				}
				else if (i == 5) {
					cout << "\t\t\t  *  " << Menu[i] << "\t\t\t\t\t\t" << "*" << endl;
				}
				else if (i == 6) {
					cout << "\t\t\t  *  " << Menu[i] << "\t\t\t\t\t\t" << "*" << endl;
				}
				else {
					cout << "\t\t\t  *  " << Menu[i] << "\t\t\t\t\t" << "*" << endl;
				}
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t\t\t  * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
		cout << endl;
		cout << "\t\t\tOdaberite opciju pomocu strelica na tastaturi i tipke SPACE " << endl;

		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0) {
				Sleep(80);
				pointer -= 1;
				if (pointer == -1) {
					pointer = 6;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0) {
				Sleep(80);
				pointer += 1;
				if (pointer == 7) {
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_SPACE) != 0) {
				Sleep(80);
				switch (pointer) {
				case 0:
					informacije();
					break;
				case 1:
					kredit(klijent);
					break;
				case 2:
					uplataRate(pretraga, prepis);
					break;
				case 3:
					kalkulatorprovjera();
					break;
				case 4:
					brojKlijenata(pretraga);
					pretragaKlijenata(pretraga);
					break;
				case 5:
					return 0;
					break;
				case 6:
					login();
					break;
				}
				break;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void informacije() {
	cout << "*********************************************************************************************************************" << endl;
	cout << endl;
	cout << "\tNasa banka Vam pruza :" << endl;
	cout << "\t- Potrosacki kredit." << endl;
	cout << "\t- Stambeni kredit." << endl;
	cout << "\tZa veci rok otplate, kamatna stopa (EKS) se povecava." << endl;
	cout << "\tZa nove klijente bez naknade za obradu kredita." << endl;
	cout << "\tUkoliko na vrijeme ne vratite odredjene rate kredita, taj iznos ce biti naplacen od Vasih jemaca/ziranata." << endl;
	cout << "\tKamatna stopa se mijenja u zavisnosti visine iznosa, npr :" << endl;
	cout << "\tZa iznos manji od 10.000, kamatna stopa iznosi 0,07. " << endl;
	cout << "\tZa iznos veci od 10.000, a manji od 30.000 kamatna stopa iznosi 0,06. " << endl;
	cout << "\tZa iznos veci od 30.000 , a manji od 60.000 kamatna stopa iznosi 0,05. " << endl;
	cout << "\tZa iznose vece od 60.000, kamatna stopa iznosi 0,04. " << endl;
	cout << "\tMoguca je isplata u valutama : konvertibilna marka, euro, kuna." << endl;
	cout << "\tPri podizanju potrosackog kredita ne zaboravite da ste prije potpisivanja ugovora zasticeni pravilima \n\tEU-a i da vam se njima u slucaju potrebe jamci mogucnost povlacenja iz ugovornog odnosa." << endl;
	cout << "\tPo dolasku u poslovnicu, bankar ce:" << endl;
	cout << "\t- Ocijeniti Vasu preliminarnu mogucnosti za odobrenje kredita(procjena kreditne sposobnosti)" << endl;
	cout << "\t- Uruciti Informaciju o uvjetima kredita sa pratecim Otplatnim planom " << endl;
	cout << "\t- Uruciti popis dokumentacije koju je potrebno prikupiti za nastavak obrade kredita" << endl;
	cout << "\tUkoliko su Vam uvjeti kredita prihvatljivi, mozete podnijeti zahtjev za kredit." << endl;
	cout << endl;
	cout << "\tPritisnite ENTER za vracanje u MENI" << endl;
	cout << "*********************************************************************************************************************" << endl;
	(void)getchar();
	(void)getchar();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void kredit(klijenti klijent[]) {
	ofstream blagajnik("informacijeOKlijentuBlagajnika.txt", ios::app);
	if (blagajnik.fail()) {									//U slucaju da ima problema sa trenutnom datotekom treba zavrsiti program odma i ispsati odgovarajucu poruku
		cout << "Ne postojeca datoteka";
		exit(1);
	}
	ofstream backup("backup.txt", ios::app);
	if (backup.fail()) {									//U slucaju da ima problema sa trenutnom datotekom treba zavrsiti program odma i ispsati odgovarajucu poruku
		cout << "Ne postojeca datoteka";
		exit(1);
	}
	system("cls");
	for (int i = 0; i < 1; i++) {

		/*--------------------------------Klijent koji podize kredit--------------------------------*/

		cout << "\t\t\tSada cemo Vam postaviti par pitanja da provjerimo da li ste kreditno sposobni..." << endl;
		cout << endl;
		cout << "\t\t\tUnesite Vase ime: ";
		cin >> klijent[i].ime;
		cout << "\t\t\tUnesite Vase prezime: ";
		cin >> klijent[i].prezime;
		cout << "\t\t\tDa li ste zaposleni? ";
		cin >> klijent[i].zaposlen;
		if (klijent[i].zaposlen == "Ne") {
			cout << "\t\t\tIzvinjavamo se ali niste kreditno sposobni" << endl;
			i++;
			cout << "\t\t\tNeka pristupi sljedeci klijent" << endl;
			cout << "\t\t\tPritisnite ENTER za nastavak" << endl;
			(void)getchar();
			(void)getchar();
			break;
		}
		cout << "\t\t\tKoliko godina radnog staza imate ? ";
		cin >> klijent[i].radniStaz;
		if (klijent[i].radniStaz < 2) {
			cout << "\t\t\tIzvinjavamo se ali niste kreditno sposobni da podignete kredit." << endl;
			cout << "\t\t\tHvala na razumijevanju" << endl;
			i++;
			cout << "\t\t\tMolimo neka pristupi sljedeci klijent" << endl;
			cout << "\t\t\tPritisnite ENTER za nastavak" << endl;
			(void)getchar();
			(void)getchar();
			break;
		}
		cout << "\t\t\tUnesite vas maticni broj: ";
		cin >> klijent[i].jmbg;
		cout << "\t\t\tUnesite danasnji datum" << endl;
		cout << "\t\t\tDan: ";
		cin >> klijent[i].dan;
		cout << "\t\t\tMjesec: ";
		cin >> klijent[i].mjesec;
		cout << "\t\t\tGodina: ";
		cin >> klijent[i].godina;
		cout << "\t\t\tMolimo pricekajte par trenutaka dok provjerimo Vase podatke...";
		Sleep(3000);
		cout << endl;
		cout << endl;
		cout << "\t\t\tKreditno ste sposobni, sada unesite iznos kredita koji zelite podici: ";
		cin >> klijent[i].kredit;
		cout << "\t\t\tUnesite broj godina na koliko zelite vracati kredit: ";
		cin >> klijent[i].brojGodina;
		cout << endl;

		/*-----------------------------------------------------------------Ziranti------------------------------------------------------------------------------------------*/
		system("cls");
		cout << "\t\t\tSada nam trebaju informacije o zirantima." << endl;
		char odluka = ' ';
		do {
			system("cls");
			cout << "\t\t\tUnesite ime prvog ziranta: ";
			cin >> klijent[i].imePrvogZiranta;
			cout << "\t\t\tUnesite prezime prvog ziranta: ";
			cin >> klijent[i].prezimePrvogZiranta;
			cout << "\t\t\tDa li je prvi zirant zaposlen? ";
			cin >> klijent[i].zaposlenostPrvogZiranta;
			if (klijent[i].zaposlenostPrvogZiranta == "Ne") {
				cout << "\t\t\tIzvinjavamo se ali niste kreditno sposobni da budete zirant." << endl;
				cout << "\t\t\tDa li zelite unijeti novog ziranta? Ako ne zelite upisite 'N' i vratiti cemo vas na pocetni meni" << endl;
				cout << "\t\t\t[Y]-za da [N]-za ne: ";
				cin >> odluka;
				if (odluka == 'N' || odluka == 'n') {
					break;
				}
			}
			cout << "\t\t\tUnesite koliko godina radnog staza ima prvi zirant: ";
			cin >> klijent[i].radniStazPrvogZiranta;
			if (klijent[i].radniStazPrvogZiranta < 2) {
				cout << "\t\t\tIzvinjavamo se ali niste kreditno sposobni da budete zirant." << endl;
				cout << "\t\t\tDa li zelite unijeti novog ziranta? Ako ne zelite upisite 'N' i vratiti cemo vas na pocetni meni" << endl;
				cout << "\t\t\t[Y]-za da [N]-za ne: ";
				cin >> odluka;
				if (odluka == 'N' || odluka == 'n') {
					break;
				}
			}
		} while (klijent[i].radniStazPrvogZiranta < 2 || klijent[i].zaposlenostPrvogZiranta == "Ne");
		if (odluka == 'N' || odluka == 'n') {
			break;
		}

		if (klijent[i].kredit >= 20000) {
			do {
				system("cls");
				cout << "\t\t\tUnesite ime drugog ziranta: ";
				cin >> klijent[i].imeDrugogZiranta;
				cout << "\t\t\tUnesite prezime drugog ziranta: ";
				cin >> klijent[i].prezimeDrugogZiranta;
				cout << "\t\t\tDa li je drugi zirant zaposlen? ";
				cin >> klijent[i].zaposlenostDrugogZiranta;
				if (klijent[i].zaposlenostDrugogZiranta == "Ne") {
					cout << "\t\t\tIzvinjavamo se ali niste kreditno sposobni da budete zirant." << endl;
					cout << "\t\t\tDa li zelite unijeti novog ziranta? Ako ne zelite upisite 'N' i vratiti cemo vas na pocetni meni" << endl;
					cout << "\t\t\t[Y]-za da [N]-za ne: ";
					cin >> odluka;
					if (odluka == 'N' || odluka == 'n') {
						break;
					}
				}
				cout << "\t\t\tUnesite koliko godina radnog staza ima drugi zirant: ";
				cin >> klijent[i].radniStazDrugogZiranta;
				if (klijent[i].radniStazDrugogZiranta < 2) {
					cout << "\t\t\tIzvinjavamo se ali niste kreditno sposobni da budete zirant." << endl;
					cout << "\t\t\tDa li zelite unijeti novog ziranta? Ako ne zelite upisite 'N' i vratiti cemo vas na pocetni meni" << endl;
					cout << "\t\t\t[Y]-za da [N]-za ne: ";
					cin >> odluka;
					if (odluka == 'N' || odluka == 'n') {
						break;
					}
				}
			} while (klijent[i].radniStazDrugogZiranta < 2 || klijent[i].zaposlenostDrugogZiranta == "Ne");
		}
		if (odluka == 'N' || odluka == 'n') {
			break;
		}

		cout << endl;
		double ukupnoZaVratiti = kalkulator(klijent);
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t\tCestitamo, uspjesno ste podigli kredit i postali ste klijent nase banke. " << endl;
		cout << "\t\t\tHvala Vam na ukazanom povjerenju!" << endl;
		cout << endl;
		cout << "\t\t\tMolimo pricekajte par trenutaka da Vas vratimo na pocetnu stranicu...";
		int brojRata = klijent[i].brojGodina * 12;
		blagajnik << "Ime klijenta: " << klijent[i].ime << endl << "Prezime klijenta: " << klijent[i].prezime << endl << "JMBG klijenta: " << klijent[i].jmbg << endl;
		blagajnik << "Da li je klijent zaposlen: " << klijent[i].zaposlen << endl << "Klijent ima " << klijent[i].radniStaz << " godina radnog staza " << endl;
		blagajnik << "Iznos kredita: " << klijent[i].kredit << endl << "Klijent ce vratiti ukupno: " << ukupnoZaVratiti << " KM" << " na: " << brojRata << " rata" << endl;
		blagajnik << "Dan podizanja kredita: " << klijent[i].dan << "." << klijent[i].mjesec << "." << klijent[i].godina << endl;
		blagajnik << "Ime 1. ziranta: " << klijent[i].imePrvogZiranta << endl << "Prezime 1. ziranta: " << klijent[i].prezimePrvogZiranta << endl;
		blagajnik << "Da li je 1. zirant zaposlen: " << klijent[i].zaposlenostPrvogZiranta << endl << "Radni staz 1. ziranta: " << klijent[i].radniStazPrvogZiranta << endl;
		if (klijent[i].kredit > 20000) {
			blagajnik << "Ime 2. ziranta: " << klijent[i].imeDrugogZiranta << endl << "Prezime 2. ziranta: " << klijent[i].prezimeDrugogZiranta << endl;
			blagajnik << "Da li je 2. zirant zaposlen: " << klijent[i].zaposlenostDrugogZiranta << endl << "Radni staz 2. klijenta: " << klijent[i].radniStazDrugogZiranta << endl;
		}
		blagajnik << endl;

		/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/

		backup << klijent[i].ime << " " << klijent[i].prezime << " " << klijent[i].jmbg << " " << klijent[i].kredit << " " << brojRata << " " << ukupnoZaVratiti << " ";
		backup << klijent[i].dan << " " << klijent[i].mjesec << " " << klijent[i].godina << " ";
		backup << klijent[i].imePrvogZiranta << " " << klijent[i].prezimePrvogZiranta << " ";
		if (klijent[i].kredit > 20000) {
			backup << klijent[i].imeDrugogZiranta << " " << klijent[i].prezimeDrugogZiranta;
		}
		backup << endl;
		/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/

		Sleep(5000);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void uplataRate(zaUpisPodatakaIzDatoteke pretraga[], zaUpisPodatakaIzDatoteke prepis[]) {
	system("cls");
	string ime, prezime, odluka;
	long long int jmbg;
	int dan, mjesec, godina;
	int brojDana = 0, brojDanaUplata = 0;
	int j = 0, brojZiranata = 1;
	int brojKorisnika = brojKlijenata(pretraga);

	cout << "\t\t\t\tUnesite ime klijenta: ";
	cin >> ime;
	cout << "\t\t\t\tUnesite prezime klijenta: ";
	cin >> prezime;
	cout << "\t\t\t\tUnesite JMBG klijenta: ";
	cin >> jmbg;
	cout << endl;


	for (int i = 0; i < brojKorisnika; i++) {
		if (prepis[i].ime == ime && prepis[i].prezime == prezime && prepis[i].jmbg == jmbg) {
			brojDana = prepis[i].dan + (prepis[i].mjesec * 30);
			system("cls");
			cout << "\t\t\t\tIme i prezime klijenta: " << prepis[i].ime << " " << prepis[i].prezime << endl;
			cout << "\t\t\t\tKolicina novca koju je podigao: " << prepis[i].kredit << "KM" << endl;
			cout << "\t\t\t\tUkupno mora vratiti: " << prepis[i].ukupnoZaVratiti << "KM na " << prepis[i].brojRata << " rata/rate" << endl;
			cout << "\t\t\t\tKredit je podignut " << pretraga[i].dan << "." << pretraga[i].mjesec << "." << pretraga[i].godina << endl << endl;
			if (pretraga[i].dan != prepis[i].dan || pretraga[i].mjesec != prepis[i].mjesec)	{
				cout << "\t\t\t\tZadnja rata je uplacena: " << prepis[i].dan << "." << prepis[i].mjesec << "." << prepis[i].godina << endl;
			}
			cout << "\t\t\t\tDa li zelite uplatiti ratu? ";
			cin >> odluka;

			if (odluka == "Da"){
				cout << "\t\t\t\tUnesite danasnji datum" << endl;
				cout << "\t\t\t\tDan: ";
				cin >> dan;
				cout << "\t\t\t\tMjesec: ";
				cin >> mjesec;
				cout << "\t\t\t\tGodina: ";
				cin	>> godina;
			
				brojDanaUplata = dan + (mjesec * 30);
				brojDanaUplata = brojDanaUplata - brojDana;

				if (brojDanaUplata <= 90 && brojDanaUplata > 0){
					prepis[i].ukupnoZaVratiti = prepis[i].ukupnoZaVratiti - (prepis[i].ukupnoZaVratiti / prepis[i].brojRata);
					prepis[i].brojRata = prepis[i].brojRata - 1;
					cout << "\t\t\t\tUplatili ste ratu. Preostalo vam je da platite " << prepis[i].ukupnoZaVratiti << "KM" << endl;
					cout << "\t\t\t\tTakoder vam je preostalo jos " << prepis[i].brojRata << " rata/rate" << endl;
					prepis[i].dan = dan;
					prepis[i].mjesec = mjesec;
					break;
				}
				else if (brojDanaUplata > 90) {
					cout << "\t\t\t\tNiste tri mjeseca uplatili ratu." << endl;
					cout << "\t\t\t\tRatu smo uzeli od vaseg ziranta." << endl;
					cout << "\t\t\t\tPreostalo vam je da platite " << prepis[i].ukupnoZaVratiti << "KM" << endl;
					cout << "\t\t\t\tTakoder vam je preostalo jos " << prepis[i].brojRata << " rata/rate" << endl;
					prepis[i].dan = dan;
					prepis[i].mjesec = mjesec;
					break;
				}
				else {
					cout << "\t\t\t\tPogresan datum!" << endl;
					break;
				}
			}
			else {
				break;
			}
			break;
		}

		j++;
		if (j == brojKorisnika) {
			cout << "\t\t\t\tUnijeli ste nepostojeceg klijenta!" << endl;
		}
	}

	cout << "\n\t\t\t\tPritisnite ENTER za povratak u meni...." << endl;
	(void)getchar();
	(void)getchar();
	loading();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

double kalkulator(klijenti klijent[]) {
	int i = 0;
	long double ukupno = 0, kamatnaStopa = 0, mjesecnaRata = 0;

	if (klijent[i].kredit <= 10000) {
		kamatnaStopa = 0.07;
	}
	else if (klijent[i].kredit > 10000 && klijent[i].kredit <= 30000) {
		kamatnaStopa = 0.06;
	}
	else if (klijent[i].kredit > 30000 && klijent[i].kredit <= 60000) {
		kamatnaStopa = 0.05;
	}
	else if (klijent[i].kredit > 60000) {
		kamatnaStopa = 0.04;
	}

	ukupno = klijent[i].kredit + (klijent[i].kredit * kamatnaStopa * klijent[i].brojGodina);
	mjesecnaRata = ukupno / ((__int64)klijent[i].brojGodina * 12);

	cout << "\t\t\tUkupno ce te vratiti: " << ukupno << endl;
	cout << "\t\t\tMjesecna rata je: " << mjesecnaRata << endl;

	return ukupno;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void kalkulatorprovjera() {
	system("cls");
	cout << "\t\t\t\t\t-- KALKULATOR ZA PROVJERU --" << endl;
	cout << "\n\t\t\t\tPostovani..." << endl;
	cout << endl;
	cout << "\t\t\t\tOvdje mozete provjeriti, prije nego ga podignete," << endl << "\t\t\t\tiznos kredita sa uracunatom kamatom." << endl;

	double ukupan, kamatnaStopa = 0, mjesecnaRata;
	double iznos;

	int godine = 0;
	char odgovor1;

	do {
		cout << "\t\t\t\tUnesite iznos koji zelite provjeriti : ";
		cin >> iznos;
		/*-----------------REKURZIJA-----------------*/
		if (iznos < 0){
			kalkulatorprovjera();
			break;
		}
		cout << "\t\t\t\tUnesite na koliko godina zelite provjeriti iznos koji bi morali vratiti : ";
		cin >> godine;
		if (iznos < 10000) {
			kamatnaStopa = 0.07;
		}
		else if (iznos >= 10000 && iznos < 30000) {
			kamatnaStopa = 0.06;
		}
		else if (iznos >= 30000 && iznos < 60000) {
			kamatnaStopa = 0.05;
		}
		else if (iznos >= 60000) {
			kamatnaStopa = 0.04;
		}

		ukupan = iznos + (iznos * kamatnaStopa * godine);
		mjesecnaRata = ukupan / ((__int64)godine * 12);

		cout << endl;
		cout << "\t\t\t\tUkupan iznos koji bi morali vratiti: " << ukupan << endl;
		cout << "\t\t\t\tVasa mjeseca rata bi iznosila: " << mjesecnaRata << endl;
		cout << "\t\t\t\tDa li zelite provjeriti drugi iznos ?" << endl;
		cout << "\t\t\t\t[Y] za da, [N] za ne: ";
		cin >> odgovor1;
		system("cls");
	} while (odgovor1 == 'y' || odgovor1 == 'Y');
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int brojKlijenata(zaUpisPodatakaIzDatoteke pretraga[]) {
	ifstream backup("backup.txt");
	if (backup.fail()) {									//U slucaju da ima problema sa trenutnom datotekom treba zavrsiti program odma i ispsati odgovarajucu poruku
		cout << "Ne postojeca datoteka";
		exit(1);
	}
	int i = 0;
	while (backup >> pretraga[i].ime >> pretraga[i].prezime >> pretraga[i].jmbg >> pretraga[i].kredit >> pretraga[i].brojRata >> pretraga[i].ukupnoZaVratiti >> pretraga[i].dan >> pretraga[i].mjesec >> pretraga[i].godina >> pretraga[i].imePrvogZiranta >> pretraga[i].prezimePrvogZiranta) {
		if (pretraga[i].kredit > 20000) {
			backup >> pretraga[i].imeDrugogZiranta >> pretraga[i].prezimeDrugogZiranta;
		}
		i++;
	}
	backup.close();
	return i;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void pretragaKlijenata(zaUpisPodatakaIzDatoteke pretraga[]) {
	system("cls");
	string ime, prezime;
	long long int jmbg;
	
	cout << "\t\t\t\tUnesite ime klijenta: ";
	cin >> ime;
	cout << "\t\t\t\tUnesite prezime klijenta: ";
	cin >> prezime;
	cout << "\t\t\t\tUnesite JMBG klijenta: ";
	cin >> jmbg;

	int j = 0, brojZiranata = 1;
	int brojKorisnika = brojKlijenata(pretraga);
	for (int i = 0; i < brojKorisnika; i++) {
		if (pretraga[i].ime == ime && pretraga[i].prezime == prezime && pretraga[i].jmbg == jmbg) {
			system("cls");
			cout << "\t\t\t\tIme i prezime klijenta: " << pretraga[i].ime << " " << pretraga[i].prezime << endl;
			cout << "\t\t\t\tKolicina novca koju je podigao: " << pretraga[i].kredit << "KM" << endl;
			cout << "\t\t\t\tUkupno mora vratiti: " << pretraga[i].ukupnoZaVratiti << "KM na " << pretraga[i].brojRata << " rata/rate" << endl;
			cout << "\t\t\t\tKredit je podignut " << pretraga[i].dan << "." << pretraga[i].mjesec << "." << pretraga[i].godina << endl;
			if (pretraga[i].kredit > 20000) {
				brojZiranata = 2;
			}
			cout << "\t\t\t\tKlijent ima " << brojZiranata << " ziranta:" << endl;
			cout << "\t\t\t\t" << pretraga[i].imePrvogZiranta << " " << pretraga[i].prezimePrvogZiranta << endl;
			if (pretraga[i].kredit > 20000) {
				cout << "\t\t\t\t" << pretraga[i].imeDrugogZiranta << " " << pretraga[i].prezimeDrugogZiranta << endl;
			}
			break;
		}

		j++;
		if (j == brojKorisnika) {
			cout << "\t\t\t\tUnijeli ste nepostojeceg klijenta!" << endl;
		}
	}

	cout << "\n\t\t\t\tPritisnite ENTER za povratak u meni...." << endl;
	(void)getchar();
	(void)getchar();
	loading();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void gotoxy(int x, int y) {
	COORD d;
	d.X = x;
	d.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}
void loading() {
	unsigned char a = 219;
	gotoxy(52, 15);
	cout << "Loading...\n";
	gotoxy(42, 17);
	for (int r = 1; r <= 30; r++) {
		for (int q = 0; q <= 80000000; q++);
		cout << a;
	}
	cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
