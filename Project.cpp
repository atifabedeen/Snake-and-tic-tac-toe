#include<iostream> 
#include<stdlib.h> 
#include<conio.h> 
#include<Windows.h> 
#include<fstream> 
#include<ctime> 
#include<cstdlib> 
#include<fstream> 
#include<string> 
using namespace std; 
struct tic
{
    char name[20]; 
    int wins;
}tic1; 
tic tic2;

struct snac
{
    char name[20]; 
    int score;
}snac1; 
snac snac2;

int sizesnac()
{
    int counter = 0;
    ifstream fin("leaderboard5.dat", ios::binary); 
    while (fin.read((char*)&snac1, sizeof(snac1)))
        {
            counter++;
        }

    fin.close(); 
    return counter;
}

int sizetic()
{
    int counter= O;
    ifstream fin("leaderboard9.dat", ios :: binary); 
    while (fin.read((char*)&tic1, sizeof(tic1)))
        {
            counter++;
        }

    fin.close(); 
    return counter;
}

void showsnac(int n)
{

    ifstream fin("leaderboard5.dat", ios::binary); 
    int i= 1;
    while (fin.read((char*)&snac1, sizeof(snac1)))
    {
        cout << i <<"."<< snac1.name <<":"<< snac1.score << endl;
        i++;
    }
    fin.close()
}

void showtic(int n)
{

    ifstream fin("leaderboard9.dat ", ios :: binary); 
    int i= 1;
    while (fin.read((char*)&tic1, sizeof(tic1)))
    {
        cout << i <<"."<< tic1.name <<":"<< tic1.wins << endl;
        i++;
    }

fin.close();

}

void arrangesnac(int n)

{

    int pos;
    fstream my("leaderboard5.dat", ios :: binary | ios::in | ios:: out); 
    int i = 0;
    for (int pass= 0; pass< n; pass++)
    {
        my.seekg(0);
        for (i = 0; i < n - pass - 1; i++)
            {
                pos = my.tellg(); 
                my.read((char*)&snac1, sizeof(snac1)); 
                my.read((char*)&snac2, sizeof(snac2)); 
                if (snacl.score < snac2.score)
                    {
                        my.seekg(pos);
                        my.write((char*)&snac2, sizeof(snac2));
                        my.write((char*)&snac1, sizeof(snac1));

                    }

                my.seekg(pos + sizeof(snac1));

            }

    }

    my.close();
}

void arrangetic(int n)

{

    int pos;
    fstream my("leaderboard9.dat", ios ::binary | ios::in  | ios::out); 
    int i = 0;
    for (int pass = 0; pass< n; pass++)
    {   
        my.seekg(0);
        for (i = 0; i < n - pass - 1; i++)
        {
            pos = my.tellg(); my.read((char*)&tic1, sizeof(tic1)); 
            my.read((char*)&tic2, sizeof(tic2)); 
            if (tic1.wins < tic2.wins)
            {
                my.seekg(pos); 
                my.write((char*)&tic2, sizeof(tic2)); my.write((char*)&tic1, sizeof(tic1));
            }
            my.seekg(pos + sizeof(tic1));
        }
    }
        my.close();
}

int check; 
char choice;
//left-1,up-2,down-3,right-4,stop-0 int dir;
int x, y, fruitx, fruity;
char square[9] = { '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9'};
int score;
const int width = 20, height = 20;
bool gameover;
void mark(int player, int box)
{
    if (player== 1)
    {
        square[box] = 'X';
    }
    else
        square[box] = 'O';
}

void display()
{
    cout <<"|";
    for (int i= 0; i<9; i++)
    {
        cout << square[i] <<" "<<"|";
        if (i == 2 || i == 5)   
        {
            cout << "\n" << "---+--+---";
            cout << "\n" << "|";
        }
    }

}

int checkwin()
{
    int result;
    if (square[0] == square[1] && square]1] == square[2])
    {
        if (square[0] == 'X')
            result= 1;
        else
            result= 2;

    }
    else if (square[3] == square[4] && square[4] == square[S])
        {
            if (square[3] == 'X')
                result= 1;
            else
                result= 2;
        }
 
    else if (square[6] == square[7] && square[7] == square[8])
        {
            if (square[G] == 'X')
                result= 1;
            else
                result= 2;

        }

 
    else if (square[0] == square[3] && square[3] == square[6])
        {
            if (square[O] == 'X')
                result= 1;

            else
                result= 2;
        }   
    else if (square[1]== square[4] && square[4] == square[7])
        {
            if (square[!]== 'X')
                result= 1;
            else
                result= 2;

        }

    else if (square[2] == square[5] && square[5] == square[8])
        {
            if (square[2] == 'X')
                result= 1;

            else
                result= 2;

        }

    else if (square[0] == square[4] && square[4] == square[8])
        {
            if(square[0] == 'X')
                result= 1;

            else
                result= 2;
        }

    else if (square[2] == square[4] && square[4] == square[6])
        {
            if (square[2] == 'X')
                result= 1;

            else
                result= 2;

        }
 
    else if (square[0] == square[3] && square[3] == square[6])
        {
            if (square[0] == 'X')
                result= 1;

            else
                result= 2;
        }

    else
        result= 0;

return result;

}

void setup()
{
    gameover = false; 
    x = width/ 2;
    y = height / 2;
    fruitx =rand()% (height - 5); 
    fruity= rand()% (width - 5); 
    dir = O;
}

void draw()
{
    system("cls");
    for (int i= 0; i < width; i++)
    {
        cout << "#";
    }
cout << endl;
for (int i= 0; i < height; i++)
{
for (int j = 0; j < width; j++)
{
    if (j == 0)
    {
        cout << "#";
    }

    else if (j == x && i == y)
    {
        cout << "O";
    }

    else if (j == fruitx && i == fruity)
    {   
        cout << "*";
    }

    else if (j == width - 1)
    {
        cout << "#";
    }

    else
        cout <<"  ";

}

    cout << endl;

}
 
for (int i= 0; i < width; i++)
 {
    cout << "#";
 }
 cout << endl << "score: " << score;
    cout << endl << "rules: \nl)move up using 'w' \n2)move down using 's' \n3)move right using 'd'
    \n4)move left using 'a' \nS)don't touch the walls \n6)get the fruits'*' to win points and press 'x' to exit";
}

void input()
{
    if (_kbhit())
    {
        switch (_getch()) {
            case 'a':dir = 1;
                    break; 
            case 'w':dir = 2;
                    break; 
            case 's':dir = 3;
                    break; 
            case 'd ':dir = 4;
                    break;

            case 'x':gameover = true; 
                    break;
        }

    }

}

void logic()
{
    switch (dir)
    {
        case 1: x--;
                break; 
        case 4: x++;
                break; 
        case 2: y--;
                break; 
        case 3:y++;
            break;

    }

    if (x > width - 2)
    {
        gameover = true;

    }
    if (x < 0)
    {
        gameover = true;
    }

    if (y > height)
    {
        gameover = true;
    }

    if (y < 0)  
    {
        gameover = true;
    }
    if (x == fruitx && y == fruity)
    {
        score+= 10;
        fruitx =rand()% (width - 5); 
        fruity= rand()% (height - 5);
    }

}

void Snake(char ch_1[])
{
    int h;

    char cont, m; 
    snac temp; 
    system("cls");
    cout << "enter level of hardness (10-l00)(smaller the number faster the movement speed)(recommended beginner level- 80): ";
    cin >> h; setup();
    while ( !gameover)
    {
        draw();
        input();
        logic();
        Sleep(h);
    }
    system("cls");
    cout << "your final score is: " <<score<< endl; cout << "Is this your first time playing?";
    cin >> m;
    if (m == 'y' || m == 'Y')
    {
        ofstream fout("Leaderboard5.dat", ios::binary | ios::app); strcpy_s(snac1.name, ch_1);
        snacl.score = score;
        fout.write((char*)&snacl, sizeof(snacl));
    }
    else
    {
        fstream f("leaderboard5.dat", ios::binary | ios::in | ios::out);
         while (f.read((char*)&snac1, sizeof(snac1)))
        {
            if (_strcmpi(snac1.name, ch_1) == 0)
            {
                snacl.score = score; 
                f.write((char*)&snac1, sizeof(snac1));
            }

        }
 
        f.close();
    }
}

void TicTacToeDouble()
{
    int first = 1, second = 2;
    int box, result = 0, flag = 0;

do
{
    for (inti= 1;i < 5; i++)
    {
        system("cls"); 
        display();
        cout << "\n Player" <<first<<" Enter the  Box:"; 
        cin >> box;
        if (square[box - 1] == 'X' || square[box - 1] == 'O')
            {
                cout << "This place has already been used choose another location:"; 
                cin>> box;
            }

        mark(first, box - 1);
        result= checkwin(); 
        if (result== 1)
            {
                system("cls");
                display();
                cout << "\n Congratualtions! player"<<first<<" has Won "; 
                flag= 1;
                break;

            }

        else if (result== 2)
            {
                system("cls");
                display();
                cout << "\n Congratualtions! player"<<second<<" has Won "; 
                flag= 1;
                break;
            }

            system("cls"); 
            display();
            cout <<"\n Player" << second <<"Enter the Box" << endl;
            cin >> box;
            if (square[box - 1] == 'X' || square[box - 1] == 'O')
            {
                cout << "This place has already been used, choose another location:"; 
                cin>>box;
            }
            mark(second, box - 1);
            result= checkwin(); 
            if (result== 1) 
            {
                cout << "\n Congratualtions! player"<<first<<" has Won "; 
                flag= 1;
                break;
            }
            else if (result== 2)
            {
                cout << "\n Congratualtions! player"<< second<<" has Won ";
                flag= 1;
                break;
            }

    }
    if (flag == 0)

    cout << " \n Sorry, The game is a draw";
    cout << "Do you wish to continue?(y/n)"<< endl; 
    cin >> choice;
    } while (choice== 'y' || choice== 'Y');

}

void TicTacToeSingle(char call[])

{

int first= 1, computer= 2; 
int box, result = 0, flag = 0;
 for (int i= 1;i < 5; i++)
{
    system("cls"); display();
    cout << "\n Player" <<first<<" Enter the Box:"; 
    cin >> box;
 
    if (square[box - 1] == 'X' || square[box - 1] == 'O')
    {
        cout << "This place has already been used choose another location:"; 
        cin >> box;
    }

    mark(first, box - 1);
    result= checkwin(); 
    if (result== 1)
    {
        system("cls"); 
        display();
        cout << "\n Congratualtions! player"<< first<<" has Won"; 
        flag= 1;
        break;
    }

    else if (result== 2)
    {
        system("cls"); 
        display();
        cout << "Computer won :("; 
        flag= 1;
        break;
    }

    system("cls"); display();
do {
box = rand() % 10;
} while (square[box] == 'X' || square[box] == 'O'); 
mark(computer, box);
result= checkwin(); 
if (result== 1)
{
    cout << "\n CONGRAGULATIONS! \nYou Won "; 
    flag= 1;
    break;
}
else if (result== 2)
{
    cout << "The computer won :("; 
    flag= 1;
    break;
}

}

    if (flag == 0)

    cout << " \n Sorry, The game is a draw "; 
    char m;
    cout << "Is this your first time playing?"; 
    cin >> m;

    if (m == 'y' 11 m == 'Y')
    {
        ofstream fout("Leaderboard9.dat", ios::binary | ios::app); 
        strcpy_s(tic1.name, call);
 
        tic1.wins = 1;
        fout.write((char*)&tic1, sizeof(tic1));
    }
    else
    {
        fstream f(" leaderboard9.dat ", ios: :binary | ios::in | ios::out); 
        int pos;
        while (f.read((char*)&tic1, sizeof(tic1)))
        {
            pos = f.tellg();
        if (_strcmpi(tic1.name, call) == 0)
        {
            tic1.wins = tic1.wins + 1; f.seekg(pos * sizeof(tic1)); f.write((char*)&tic1, sizeof(tic1) );
        }

        }
    f.close();

    }

}

int main()
{

    char choose; 
    snac snac2; 
    int n, o;
    srand(time(NULL)); 
    int k; 
do
{
    system( "cls");
    cout << "	Main Menu	";
char choice_1;

cout << endl<< "a.Snake"<< endl<<"b.Tic Tac Toe(single player)"<< endl<< "c.Tic Tac Toe(double player) "<< endl << "d.Snake Leaderboard " << endl << " e.Tic Tac Toe Lea derboar d" << endl;
cin >> choice_1; 
switch (choice_1)
{
case 'a' : char name_1[15]; 
          system("cls") ;
          cout << "Enter your name:"; 
          cin >> name_1; 
          Snake(name_1);
            break; 
case 'b':
            char call[15]; 
            system("cls");
            cout << "Enter your name:"; 
            cin >> call; 
            TicTacToeSingle(call); 
            break;
case 'c' :
            system("cls"); 
            TicTacToeDouble(); 
            break;
case 'd': system("cls"); 
          n = sizesnac(); 
          arrangesnac(n); 
          showsnac(n); 
          break;
case 'e':
         system("cls");
          o = sizetic(); 
          arrangetic(o); 
          showtic(o); 
          break;
}

cout << "do you want to continue:"; 
cin >> choose;
} while (choose== 'y' || choose== 'Y');

_getche(); 
return 0;
}


