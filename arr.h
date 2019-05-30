template<typename T>
void find(T* arr, int size) {
	T value;
	int i;
	bool flag = false;

	cout << "Массив: ";

	for( i = 0; i < size; ++i )
		cout << arr[i] << " ";

	try 
  {
		cout << endl << endl << "Введите значение: ";
		cin >> value;

		for( i = 0; i < size; ++i) 
    {
			if( arr[i] == value ) 
			{
				flag = true;
				break;
			}
		}

		if( !flag )
		{
			char *ex = "Такого элемента нет в массиве";
			throw ex;
		}

		cout << endl << "Элемент " << value << " находится под индексом " << i << endl << endl;
		system("pause");
	}
	catch( char *ex ) 
  {
		cout << endl << ex << endl << endl;
		system( "pause" );
	}
}
