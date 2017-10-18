/* Даны два массива. Сформировать третий массив, состоящий из тех элементов, которые присутствуют в обоих массивах. */
// https://github.com/fiorentina97/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
using namespace std;

/* Чтение массива из файла.Делаем inc count, узнавая длину массива, затем добавляем только числа */

	
int *inputf(ifstream &f,int &count,char s[40])
{
 f.open (s);
 if (!f)
    {
        cout << "File not found\n";
        system("pause");
    }
int a;
int i = 0;
 	do
	{
		if(f >> a)
		{
			count++;
		}
		else
		{
			f.clear();
			f.ignore(1, ' ');
		}
	}
	while(!f.eof());
	
	f.seekg(0);
	int *arr = new int[count];
	while (!f.eof() && i < count)
	{
		if(f >> a)
		{
			arr[i] = a;
			i++;
			
		}
		else
		{
                                  
			f.clear();

			f.ignore(1, ' ');
		}	
	}
 f.clear(); 
 f.seekg(0);
 f.close();
 return arr;
}

/* Вывод массива в текстовый файл */

void outputvf(ofstream &f,int *mas, int &count, char s[40])
{
 int i;
 
 f.open(s);
 
 if (f.fail()) 
    {
	  cout<<"Corrupted file\n";
      exit(1);
    }
  for(i=0;i<count;i++)
   {
    	f << mas[i] << " ";
   }

 f.close();
}

/* Основная функция поиска пересечений в двух массивах */

int *intersection(int *a,int *b,int &n,int &m,int &k)
{
int *d = new int[n+m];
bool check;
for (int i=0; i<n; i++)
        {
            for (int j=0; j<m, not check; j++)
            {
                if (a[i]==b[j])
                {
               	 d[k]=a[i];
               	 k++;
               	 check = true;
                }
                
            }
            check = false;
        }
        return d;
}

// КОНСОЛЬ

void input_array(int *arr,int x) 
{  
  for (int i=0; i<x; i++)
    {
        cin >> arr[i];
    }
}

void print_array(int *arr,int x) {
	for (int i=0; i<x; i++)
    {
        cout << arr[i] << " ";
    }
}


int main()
{ 
  setlocale(LC_ALL,"Russian");
  ifstream f_arrA,f_arrB;
  ofstream fout;	
  int n = 0,m = 0,key;
  cout<<"Выберите один из пунктов меню:\n";
  cout << "1. Добавить массивы из файла\n";
  cout << "2. Ввести массив в консоли" << endl;
  cin >> key;
  if (key == 1)
  {
    int *a;
    int *b;
    char str[40];
    cout<<"Введите имя файла массива A: \n";
    cin>>str;
    a=inputf(f_arrA,n,str);
    cout<<"Введите имя файла массива B: \n";
    cin>>str;
    b=inputf(f_arrB,m,str);
    cout<<"Введите имя выходного файла:\n";
    cin>>str;
  
  //result
   int k=0;
        int *d = new int[n+m];
       /* for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (a[i]==b[j])
                {
                d[k]=a[i];
                k++;
                }
            }
        } */
        d = intersection(a,b,n,m,k);
        outputvf(fout,d,k,str);
    	cout << "Success!";
    }
    else if (key == 2)
    {
    	cout << "Введите длину первого массива\n";
    	cin >> n;
    	int *a = new int[n];
  		cout << "Введите элементы первого массива\n";
		input_array(a,n);
		cout << "Введите длину второго массива\n";
    	cin >> m;
    	int *b = new int[m];
    	cout << "Введите элементы второго массива\n";
		input_array(b,m);
		int k=0;
        int *d = new int[n+m];
        d = intersection(a,b,n,m,k);
        cout << "Результат:\n";
		print_array(d,k);		
    }
	else exit(1);	
}
