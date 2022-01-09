// INKI 515 - zadacha 46 Hristijan Spirovski
#include <iostream> 
#include <sstream> 
#include <cstring>
#include <cctype>
#include <iomanip>
#include <math.h>
using namespace std;

void kodirajne(int broj)
{
    bool flag = true;
    char text[300];
    cin.ignore();
    cout << " Vnesete string sto treba da se kodira: ";
    cin.getline(text, 300);
    string s(text);
    cout << endl;
    cout << endl;

    for (int i = 0; i < s.size(); i++) {
        if ((isalpha(s[i])) || (isspace(s[i])) || (ispunct(s[i])))
        {
            s[i] = s[i] + broj;

        }
        else
        {
            cout << "Stringot treba da sodzri bukvi, prazni mesta i intepukciski znaci!";
            flag = false;
            break;
        }

    }
    if (flag)
    {
        cout << "Kodiraniot tekst e: ";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
        }
    }

}

void dekodirajne(int broj)
{
    char text[300];
    cin.ignore();
    cout << "Vnesete string sto treba da se dekodira: ";
    cin.getline(text, 300);
    string s(text);
    cout << endl;
    cout << s.size();
    cout << endl;

    for (int i = 0; i < s.size(); i++)
    {
        s[i] = s[i] - broj;
    }

    cout << "Dekodiraniot tekst e: ";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
}

int main()
{
    int broj, pom = 0, max = 0, n1,proverka;
    char text[300];
    int i, odberiOpcija;
    
    cout << setfill('*') << setw(100) << "*" << endl;
    cout << setfill(' ') << setw(64) << "Kodirajne & Dekodirajne na string" << endl;
    cout << setfill('*') << setw(100) << "*" << endl;
    cout << "Vnesi pozitiven broj koj ke se koristi za kodirajne & dekodirajne, no da nema poveke od 6 cifri:" << endl;
    cin >> broj;

    while (broj != 0)
    {
        n1 = broj % 10;
        pom++;
        broj = broj / 10;

        if (n1 > max)
            max = n1;

    }

    if (pom > 6)
    {
        cout << "Brojot treba da ima max 6 cifri!" << endl;
        return 1;
    }

    int brojZaKD = abs(pom - max);

    cout << "Odberete dali sakate da kodirate ili dekodirate " << endl;
    cout << "Za kodirajne pritisnete 1" << endl;
    cout << "Za dekodirajne pritisnete 2" << endl;
    cin >> odberiOpcija;

    switch (odberiOpcija)
    {
    case 1: kodirajne(brojZaKD);
        break;
    case 2: dekodirajne(brojZaKD);
        break;
    default: cout << "Odberete vrednost 1 ili 2";
    }
       cout << endl;
    cout << "Dali stringot sto go (de)kodiravte sakate da go (de)kodirate?" << endl;
    cout << "1 -> KODIRAJNE" << endl;
    cout << "2 -> DEKODIRAJNE" << endl;
    cin >> proverka;
    if (proverka == 1)
    {
        cout << endl;
        kodirajne(brojZaKD);
    }
    else if (proverka==2)
    { 
        cout << endl;
        dekodirajne(brojZaKD);
    }
    cout << endl;
    system("Pause");
    return 0;
}
