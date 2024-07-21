#include <iostream>
#include <string>

void main() {
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
}

int encrypt(int n, int e, std::string message) {

}