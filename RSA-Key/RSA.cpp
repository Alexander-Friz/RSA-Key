#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int encrypt(int n, int e, std::string message) {
	using namespace std;
	map<char, int> char_int_map = {

		{'A', 111},
		{'B', 112},
		{'C', 113},
		{'D', 114},
		{'E', 115},
		{'F', 116},
		{'G', 117},
		{'H', 118},
		{'I', 119},
		{'J', 121},
		{'K', 122},
		{'L', 123},
		{'M', 124},
		{'N', 125},
		{'O', 126},
		{'P', 127},
		{'Q', 128},
		{'R', 129},
		{'S', 131},
		{'T', 132},
		{'U', 133},
		{'V', 134},
		{'W', 135},
		{'X', 136},
		{'Y', 137},
		{'Z', 138}, //English Alphabet

		{'.', 911},
		{',', 912},
		{'!', 913},
		{'?', 914},
		{' ', 915},//Simple Sentence Token

		{'1', 511},
		{'2', 512},
		{'3', 513},
		{'4', 514},
		{'5', 515},
		{'6', 516},
		{'7', 517},
		{'8', 518},
		{'9', 519},
		{'0', 520}

	};

	int length = message.length(); //Mögliches Error Handling mit Fehler Nachricht > 500 Wörter.
	cout <<"Zeichen in der Nachricht: " << length << endl;

	int message_int[500]{}; //Da Variable lenght nicht akzepitert wegen der Speicher allokation hier eine Maximale länge von 500 Zeichen in einer Nachricht.
	transform(message.begin(),message.end(), message.begin(), ::toupper);

	for (int i = 0; i < length; ++i) {
		cout << "Char INT Map an der Stelle "<< i << " " << char_int_map[i];
		int x = char_int_map[message[i]];
		message_int[i] = x;
		cout << "Messageg INT an der Stelle " << i << " " << message_int[i] << endl;
		cout << message[i] << endl;
	}
	
	//Anwendung Algorithmus für Verschlüsselung der INT in der Message INT Liste
	// Quelle: https://norbert-pohlmann.com/glossar-cyber-sicherheit/rsa-verfahren/
	// Schritt 1: Suche nach zwei großen Primzahlen p und q


	// Primzahltest von p und q


	// Berechnung Produkt n = n * q



	// Berechnung Teilerfremde Zahl e = ((p - 1) * (q - 1)


	// => Öffentlicher Schlüssel (e, n)

	// Erweiterter Euklidischer Algorithmus zur berechnung von e * d mod ((p − 1) (q − 1)) = 1

	// =>Privater Schlüssel d
	return 1;

}

int main() {
	using namespace std;
	bool run = false;
	cout << "Encrypt a message. (1)" << endl; //verschlüsseln
	cout << "Decrypt a message. (2)" << endl; //entschlüsseln
	cout << "Quit (3)" << endl;	//beenden
	int x;
	cout << "Please choose an option" << ":" << endl;
	cin >> x;
	cin.ignore();

	switch (x) {
	case 1:
	{
		cout << "Type in the message you want to encrypt." << endl; //verschlüsseln
		std::string message;
		getline(cin, message);
		cout << "Your Message is: " << message << endl;
		encrypt(9, 9, message);
		break;

	}
	case 2:
	{
		cout << "Type in the encrypted message to encrypt it." << endl;


		break;
	}
	case 3:
	{
		cout << "Thanks for using my tool. :D" << endl;
		break;
	}
	default:
	{
		cout << "Invalid option!" << endl;
		cout << "Try again!" << endl; //Funktioniert noch nicht da keine Schleife

	}
	}
	return 0;
}