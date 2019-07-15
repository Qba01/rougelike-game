#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int hp;
int dmg;
int plecak;
int exp;
string imie;
int x=0, a=0 ,b=0, c=0;
int wynik;
//string mapa;
bool gameOver;
const int width = 10;
const int height = 10;

char tab[width][height];
char tab1[20][54];
char tab2[30][74];

void mapa()
{
    int ruch=0;
    system("cls");

    cout << "Dojdz do konca w ciagu: " << 10-ruch << " ruchach\n\n";
    ruch++;
    cout << endl << endl;

    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
    {

      cout << tab[x][y];
      if(tab[x][y+1]=='@')
      {
       HANDLE hOut;
        hOut = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

      }
      else
        {
            HANDLE hOut;
        hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        }
    }
    cout << endl;
  }
}

void winorlose()
{
    int xp, yp, xl, yl, xw, yw;

  for(int x=0; x < width; x++){
  	for(int y=0; y < height; y++){
  		if(tab[x][y]=='@')
		  xp=x;
		  yp=y;
	  }
  }
  for(int x=0; x < width; x++){
  	for(int y=0; y < height; y++){
  		if(tab[x][y]=='L'){
		  xl=x;
		  yl=y;
  		}
	  }
  }
  if((xp==9)&&(yp==5))
  {
      gameOver=true;
  }
    for(int x=0; x < width; x++){
  	for(int y=0; y < height; y++){
  		if(tab[x][y]=='W')
		  xw=x;
		  yw=y;
	  }
  }
}

void sterowanie()
{
    char c1, c2;

    switch(_getch())
  {
  	case 'w':
  	case 'W':
  		  for(int x=0; x < width; x++){
  			for(int y=0; y < height; y++){
  				if(tab[x][y]=='@'){
  				//	cout << "rzad: " << i+1 << endl << "kolumna: " << j+1 << endl;
  				if(x >= 0 && y >= 0&& x < width && y < height){
                    if((tab[x-1][y]=='#')&&(tab[x-1][y]=='L'))
                            break;
                            else
                            {
                            swap(tab[x][y],tab[x-1][y]);
                            }
                    }
                }
  			}
  		  }
  		break;
  	case 's':
  	case 'S':
  		  for(int x=0; x < width; x++){
  			for(int y=0; y < height; y++){
  				if(tab[x][y]=='@'){
  				//	cout << "rzad: " << i+1 << endl << "kolumna: " << j+1 << endl;
  				if(x >= 0 && y >= 0&& x < width && y < height){
  				if(tab[x+1][y]=='#')
                            break;
                            else
                            {
                                /*
                                x1 ,y1, x2, y2;
                                x1=x;
                                y1=y;
                                x2=x;
                                y2=y+1;
                                */
                                c1 = tab[x+1][y];
                                c2 = tab[x][y];
                                tab[x+1][y] = c1;
                                tab[x][y] = c2;
                    }

  					swap(tab[x][y],tab[x+1][y]);
				  }
  				}
	 		}
  		}
  		break;
  	case 'a':
  	case 'A':
  		  for(int x=0; x < width; x++){
  			for(int y=0; y < height; y++){
  				if(tab[x][y]=='@'){
  				//	cout << "rzad: " << i+1 << endl << "kolumna: " << j+1 << endl;
  				if(x >= 0 && y >= 0&& x < width && y < height)
                    if((tab[x][y-1]=='#')&&(tab[x][y-1]=='L'))
                            break;
                            else
                            {
                            swap(tab[x][y],tab[x][y-1]);
                            }
				  }
	 		}
  		}
  		break;
  	case 'd':
  	case 'D':
  		  for(int x=0; x < width; x++){
  			for(int y=0; y < height; y++){
  				if(tab[x][y]=='@'){
  				//	cout << "rzad: " << i+1 << endl << "kolumna: " << j+1 << endl;
  				if(x >= 0 && y >= 0&& x < width && y < height){
                        if(tab[x][y+1]=='#')
                            break;
                            else
                            {
                                /*
                                x1 ,y1, x2, y2;
                                x1=x;
                                y1=y;
                                x2=x;
                                y2=y+1;
                                */
                                c1 = tab[x][y+1];
                                c2 = tab[x][y];
                                tab[x][y+1] = c1;
                                tab[x][y] = c2;
                    }
  				}

  					swap(tab[x][y],tab[x][y+1]);
				  }

	 		}
  		}
  		break;
    default:
        break;
  }
}

void tittle()
{
HANDLE hOut;
hOut = GetStdHandle( STD_OUTPUT_HANDLE );
SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
cout << "    #   #      #    #      ###### #    # #   #   #  ###### ####\n";
cout << "    #   #     # #   #      #      # #  # #   #   #  #    # #   #\n";
cout << "    #   #    #   #  #      ###### #  # # #   #   #  #    # #    #\n";
cout << "     # #    ######  #      #      #   ##  # # # #   #    # #   #\n";
cout << "      #    #      # ###### ###### #    #   #   #    ###### ####\n\n";
SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}



void error()
{
            cout << "Cos nie dziala\n";
        Sleep(3000);
        cout << "Cos poszlo nie tak\n";
        Sleep(3000);
        cout << "Twoj zapis zostal utracony\n";
        Sleep(3000);
        cout << "JOKE!\n";
}

int main()
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
setlocale (LC_ALL, "");
ifstream czyt;
ofstream zap;
int ruch=0;

  ifstream plik;
  plik.open("mapa0.txt");
  for(int x = 0; x < width; x++) {
    for(int y = 0; y < height; y++)
      plik >> tab[x][y];

  }

tittle();
Sleep(2500);
gameOver=false;


do
{

    //int y=98;
  //  wynik = (char)y;
   // cout << wynik;
    system( "cls" );
    tittle();

    cout << "1: Nowa gra\n";
    cout << "2: Wczytaj gre\n";
    cout << "3: Ustawienia\n";
    cout << "4: Dost�pne mapy:\n";
    cout << "5: Wyjdz\n";
    cin >> x;

    switch(x)
    {

    case 1:

        system( "cls" );
        cout << "Nowa gra\n";
        cout << "Imie bohatera/bohaterki\n";

        cin >> imie;
                                                                    //Statystyki postaci
        cout << "Chcesz przydzielic losowo punkty statystyk?\n";
        cout << "[1] Tak(ta funkcja jest wciaz niedostepna)\n";
        cout << "[2] Nie\n";
        cin >> c;
        if(c==1)
        {
                                                                            //losowe rozdzielanie pkt
        }
        else
        {
        for(int i=15;i>0;i--)
        {
                                        //rozdawanie pkt i zapis
            system("cls");
         cout << "Masz " << i << " pkt do rozdzielenia miedzy statystykami\n";
         cout << "[1] Zycie: " << hp << endl;
         cout << "[2] Sila: " << dmg << endl;
         cin >> b;
         if(b==1)
            hp+=1;
         else
            dmg+=1;

                zap.open("boh.txt");
                zap << "imie " << imie << endl <<"dmg " << dmg << endl << "hp " << hp << endl << "exp " << exp << endl << "plecak " << plecak << endl;
                zap << imie << endl << dmg << endl <<  hp << endl << exp << endl << plecak << endl;

                zap.close();
        }
        }

        cout << "imie " << imie << endl << "dmg " << dmg << endl << "hp " << hp << endl << "exp " << exp << endl << "plecak " << plecak << endl; //sprawdzenie czy dziala :v
        //wyswietlanie mapy

      //  czyt.open("level1.txt");

      for(int i=3;i>0;i--)
      {
          system("cls");
          cout << "Gra zacznie si� za: " << i << endl;
          Sleep(400);
      }
      do
      {


        mapa();
        sterowanie();
        winorlose();

            if(ruch>9)
            {
                gameOver=true;
            }
            else
                ruch++;
        }
      while(!gameOver);
     //  cout << mapa;
       czyt.close();
       plik.close();
       cout << endl << ruch << endl;
       system("PAUSE");


        break;

    case 2:
        system( "cls" );
        cout << "Wczytaj gre\n";

                                                    //funkcja/procedura wczytaj
        {
            string imie;
            int hp;
            int dmg;
            int plecak;
            int exp;

            czyt.open("boh.txt");

            if (!czyt)
                {
                cout << "\nBLAD OTWARCIA!\n";
                system ("Pause");
                return 1;
                }
            czyt >> imie >> dmg >> hp >> exp >> plecak;
            cout << "imie " << imie << endl << "dmg " << dmg << endl << "hp " << hp << endl << "exp " << exp << endl << "plecak " << plecak << endl;

            czyt.close();
            plik.close();
            system ("Pause");
            return 0;
        }
        break;

    case 3:
        system("cls");
        cout << "Ustawienia\n";
        cout << "Praca nad ustawieniami w toku\n";
        cout << "Prosz� o cierpliwo��\n";
        cout << "Mia�a by� �adna muzyka, ale pianista ma wa�ny koncert ;C\n";
               Beep(280,5000);

        break;

    case 4:
        system("cls");
        cout << "Dost�pne mapy:\n";



plik.open("level1.txt");
  for(int x = 0; x < 20; x++) {
    for(int y = 0; y < 54; y++)
      plik >> tab[x][y];
  }

    cout << endl << endl;

    for(int x = 0; x < 20; x++)
    {
        for(int y = 0; y < 54; y++)
    {
      cout << tab1[x][y];
    }
    cout << endl;
  }
  system("PAUSE");
plik.close();
system("cls");
  plik.open("maporg.txt");
  for(int x = 0; x < 30; x++) {
    for(int y = 0; y < 74; y++)
      plik >> tab[x][y];

  }

   for(int x = 0; x < 30 ; x++)
    {
        for(int y = 0; y < 74 ; y++)
    {

      cout << tab2[x][y];
    }
    cout << endl;
  }
  system("PAUSE");
plik.close();


        break;


    case 5:
        system("cls");
        cout << "Wyjdz\n";
        system("PAUSE");
        cout << "Czy chcesz zapisac stan gry?\n";
        system("PAUSE");
        error();
        cout << "Wcisnij 0 aby wyjsc bez zapisywania\n";
        cin >> a;

        if(a!=0)
        {
            //zapisywanie gry
                zap.open("boh.txt");
                //zap << "imie " << imie << endl <<"dmg " << dmg << endl << "hp " << hp << endl << "exp " << exp << endl << "plecak " << plecak << endl;
                zap << imie << endl << dmg << endl <<  hp << endl << exp << endl << plecak << endl;

                zap.close();
        }
        else
        return 0;

    }
}
while(x!=0);
getch();
    return 0;
}




