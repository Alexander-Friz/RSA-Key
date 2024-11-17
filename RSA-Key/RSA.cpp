#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <locale>
#include <sstream>
#include <random>
#include <ctime>

using namespace std;

//größter gemeinsamer Teiler
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//Euklidischer Algorithmus
long long mod_inverse(long long e, long long phi) {
    long long t = 0, newt = 1;
    long long r = phi, newr = e;

    while (newr != 0) {
        long long quotient = r / newr;
        long long temp = t;
        t = newt;
        newt = temp - quotient * newt;

        temp = r;
        r = newr;
        newr = temp - quotient * newr;
    }

    if (r > 1) return -1; //Kein inverse Elemente
    if (t < 0) t += phi;
    return t;
}

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

//Berechnung von Primzahlen Sieb Eratosthenes
vector<long long> generate_primes(long long limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (long long i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<long long> primes;
    for (long long i = 2; i <= limit; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}

//Auswahl zwei zufällige Primzahlen
pair<long long, long long> select_random_primes(const vector<long long>& primes) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, static_cast<int>(primes.size()) - 1);

    long long p = primes[dis(gen)];
    long long q = primes[dis(gen)];
    while (p == q) {
        q = primes[dis(gen)];
    }
    return { p, q };
}

//Zeichen zu Zahlen-Mapping
map<wchar_t, int> char_int_map = {
    {L'A', 111}, {L'B', 112}, {L'C', 113}, {L'D', 114}, {L'E', 115},
    {L'F', 116}, {L'G', 117}, {L'H', 118}, {L'I', 119}, {L'J', 121},
    {L'K', 122}, {L'L', 123}, {L'M', 124}, {L'N', 125}, {L'O', 126},
    {L'P', 127}, {L'Q', 128}, {L'R', 129}, {L'S', 131}, {L'T', 132},
    {L'U', 133}, {L'V', 134}, {L'W', 135}, {L'X', 136}, {L'Y', 137},
    {L'Z', 138}, {L'a', 211}, {L'b', 212}, {L'c', 213}, {L'd', 214},
    {L'e', 215}, {L'f', 216}, {L'g', 217}, {L'h', 218}, {L'i', 219},
    {L'j', 221}, {L'k', 222}, {L'l', 223}, {L'm', 224}, {L'n', 225},
    {L'o', 226}, {L'p', 227}, {L'q', 228}, {L'r', 229}, {L's', 231},
    {L't', 232}, {L'u', 233}, {L'v', 234}, {L'w', 235}, {L'x', 236},
    {L'y', 237}, {L'z', 238}, {L' ', 915}, {L'.', 911}, {L',', 912}
};

//Umkehr-Mapping
map<int, wchar_t> int_char_map;
void initialize_int_char_map() {
    for (auto& pair : char_int_map) {
        int_char_map[pair.second] = pair.first;
    }
}

int main() {
    locale::global(locale(""));
    initialize_int_char_map();

    long long prime_limit = 1000; //Grenze der Primzahlen
    vector<long long> primes = generate_primes(prime_limit);

    while (true) {
        wcout << L"\nBitte wählen Sie eine Option:\n";
        wcout << L"1. Nachricht verschlüsseln\n";
        wcout << L"2. Nachricht entschlüsseln\n";
        wcout << L"3. Beenden\n";
        wcout << L"Eingabe: ";

        int option;
        wcin >> option;
        wcin.ignore(numeric_limits<streamsize>::max(), '\n'); //Eingabepuffer leeren

        if (option == 1) {
            pair<long long, long long> primes_pair = select_random_primes(primes);
            long long p = primes_pair.first;
            long long q = primes_pair.second;

            long long n = p * q;
            long long phi = (p - 1) * (q - 1);

            long long e;
            do {
                e = primes[rand() % primes.size()];
            } while (gcd(e, phi) != 1);

            long long d = mod_inverse(e, phi);

            wcout << L"Generierte Primzahlen: p = " << p << L", q = " << q << endl;
            wcout << L"Modulus n: " << n << endl;

            wcout << L"Geben Sie die Nachricht ein, die Sie verschlüsseln möchten:\n";
            wstring message;
            getline(wcin, message);

            vector<long long> encrypted_message;
            for (wchar_t ch : message) {
                if (char_int_map.find(ch) != char_int_map.end()) {
                    encrypted_message.push_back(mod_exp(char_int_map[ch], e, n));
                }
            }

            wcout << L"Verschlüsselte Nachricht: ";
            for (auto val : encrypted_message) wcout << val << L" ";
            wcout << endl;

            wcout << L"Öffentlicher Schlüssel (e,n): (" << e << L", " << n << L")\n";
            wcout << L"Privater Schlüssel (d): " << d << endl;

        }
        else if (option == 2) {
            long long e, n, d;
            wcout << L"Geben Sie e, n und d ein:\n";
            wcin >> e >> n >> d;
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');

            wcout << L"Geben Sie die verschlüsselte Nachricht ein (Zahlen mit Leerzeichen getrennt):\n";
            wstring line;
            getline(wcin, line);
            wstringstream ss(line);
            vector<long long> encrypted_message;
            long long num;
            while (ss >> num) {
                encrypted_message.push_back(num);
            }

            wcout << L"Entschlüsselte Nachricht: ";
            for (auto val : encrypted_message) {
                long long decrypted = mod_exp(val, d, n);
                if (int_char_map.find(decrypted) != int_char_map.end()) {
                    wcout << int_char_map[decrypted];
                }
            }
            wcout << endl;

        }
        else if (option == 3) {
            wcout << L"Programm beendet.\n";
            break;
        }
        else {
            wcout << L"Ungültige Option! Bitte erneut versuchen.\n";
        }
    }
    return 0;
}
