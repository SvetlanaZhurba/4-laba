#include <iostream>
#include <ctime>
#include <string>
#include "tree.cpp"
#include "arr.h"

using namespace std;

template <typename T>
void mod(T a) {

	int c;
	T value;

	tree<T> ob;

	do 
  {
		system("cls");

		cout << "1 - Добавить элемент в дерево" << endl;
		cout << "2 - Вывести дерево в нисходящем порядке" << endl;
		cout << "3 - Вывести дерево в восходящем порядке" << endl;
		cout << "4 - Поиск элемента" << endl;
		cout << "0 - Выход" << endl;
		cout << "Выберете пункт меню: ";
		cin >> c;

		switch (c) 
    {
		case 1: 
			cout << "Введите элемент: ";
			cin >> value;
			ob.push(value);
			break;

		case 2: 
			system("cls");

			if( ob.getRoot() == nullptr )
				cout << "Дерево пустое" << endl;
			else
			{
				cout << "Дерево в ниcходящем порядке: ";
				ob.descBypass( ob.getRoot() );
			}
			cout << endl;
			system("pause");
			break;

		case 3:
			system("cls");
			if( ob.getRoot() == nullptr )
				cout << "Дерево пустое" << endl;
			else
			{
				cout << "Дерево в восходящем порядке: ";
				ob.ascBypass( ob.getRoot() );
			}
			cout << endl;
			system( "pause" );
			break;

		case 4: 
      ob.find(); 
      break;
		}

	} while( c != 0 );
}

int main() 
{
	setlocale(LC_ALL, "rus");
  int c1, c2;

  do
  {
    system( "cls" );
    cout << "1. Массив\n2. Дерево\n0. Выход\nВаш выбор: ";
    cin >> c1;
    cin.ignore( 1, '\n' );

    if( c1 == 1 )
    {
      srand(time(NULL));

	    int size = rand() % 71 + 30;

	    int* int_mass = new int[size];
	    char* char_mass = new char[size];
	    float* float_mass = new float[size];
	    double* double_mass = new double[size];
	    string* string_mass = new string[size];

	    for (int i = 0; i < size; ++i) 
      {
		    int_mass[i] = rand() % 101;
		    char_mass[i] = rand() % 26 + 65;
		    float_mass[i] = (float)(rand()) / RAND_MAX * 100;
		    double_mass[i] = (double)(rand()) / RAND_MAX * 100;
		    string_mass[i] = rand() % 26 + 65;
	    }
     
	    do
      {
		    system("cls");
		    cout << "Выберите тип массива" << endl << endl;
		    cout << "1 - int" << endl;
		    cout << "2 - char" << endl;
		    cout << "3 - float" << endl;
		    cout << "4 - double" << endl;
		    cout << "5 - string" << endl;
		    cout << "0 - Выход" << endl << endl;
		    cout << "Выберите тип: ";
		    cin >> c2;

		    switch (c2) {
		    case 1: 
          find( int_mass, size ); 
          break;

		    case 2: 
          find( char_mass, size ); 
          break;

		    case 3: 
          find( float_mass, size ); 
          break;

		    case 4: 
          find( double_mass, size ); 
          break;

		    case 5: 
          find( string_mass, size ); 
          break;
		    }

	    } while( c2 != 0 );

	    delete[] int_mass;
	    delete[] char_mass;
	    delete[] float_mass;
	    delete[] double_mass;
	    delete[] string_mass;
    }
    else if( c1 == 2 )
    {
      int c3;
      float c = 1.5;
	    string s;

	    do 
      {
		    system("cls");

		    cout << "1 - Дерево типа int" << endl;
		    cout << "2 - Дерево типа char" << endl;
		    cout << "3 - Дерево типа float" << endl;
		    cout << "4 - Дерево типа double" << endl;
		    cout << "5 - Дерево типа string" << endl;
		    cout << "0 - Выход" << endl;
		    cout << "Выберете пункт меню: ";
		    cin >> c3;

		    switch( c3 ) 
        {
		    case 1: 
          mod(1); 
          break;

		    case 2: 
          mod('a'); 
          break;

		    case 3: 
          mod(c); 
          break;

		    case 4: 
          mod(1.1); 
          break;

		    case 5: 
          mod(s); 
          break;
		    }

	    } while( c3 != 0 );
    }
  } while( c1 != 0 );

	return 0;
}
