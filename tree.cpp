#include <iostream>

using namespace std;

template <typename T>
struct node {
	node *left;
	node *right;
	node *parent;
	T value;
};

template <typename T>
class tree {
	node<T> *root;
public:
	tree();
	~tree();

	void push(T value);
	void descBypass(node<T>* root);
	void ascBypass(node<T>* root);
	void find();
	node<T>* search(node<T>* root, T value);
	void del(node<T>* root);

	node<T>* getRoot();
};

template<typename T> tree<T>::tree()
{
	root = nullptr;
}

template<typename T> tree<T>::~tree()
{
	del(root);
}

template<typename T> void tree<T>::del(node<T>* root)
{
	if (root != NULL) 
	{
		del(root->left);
		del(root->right);
		delete root;
	}
}

template<typename T> void tree<T>::push(T value) {
	node<T>* newNode = new node<T>; 
	node<T>* current = nullptr;
	node<T>* prev = nullptr;

	newNode->value = value;
	newNode->parent = newNode->left = newNode->right = nullptr;
	current = root;

	while (current != 0)
	{
		prev = current; 
		if (value < current->value)
			current = current->left;
		else
			current = current->right; 
	}


	newNode->parent = prev;
	if (prev == nullptr) 
		root = newNode;
	else
	{
		if (value < prev->value)
			prev->left = newNode;
		else
			prev->right = newNode;
	}
}

template<typename T> void tree<T>::descBypass(node<T> * root)
{
	if( root != nullptr ) 
  {
		cout << root->value << " ";
		descBypass(root->left);
		descBypass(root->right);
	}
}

template<typename T> void tree<T>::ascBypass(node<T>* root)
{
	if( root != nullptr ) 
  {
		ascBypass(root->left);
		ascBypass(root->right);
		cout << root->value << " ";
	}
}

template<typename T> void tree<T>::find()
{
	T value;
	system("cls");
	cout << "Введите значение для поиска: ";
	cin >> value;

	node<T> *res = search(root, value);
	try 
  {
		if (res == nullptr) 
    {
			char *ex = "Такого элемента нет!";
			throw ex;
		}
		else
			cout << endl << "Элемент " << res->value << " найден!" << endl << endl;
	}
	catch( char *ex )
	{
		cout << endl << ex << endl << endl;
	}

	system( "pause" );
}

template<typename T> node<T>* tree<T>::search(node<T>* root, T value)
{
	if( root == nullptr || value == root->value )
		return root;

	if (value < root->value)
		return search(root->left, value);
	else
		return search(root->right, value);
}

template<typename T> node<T>* tree<T>::getRoot()
{
	return root;
}
