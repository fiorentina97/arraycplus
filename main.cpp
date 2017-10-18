/* ���� ��� �������. ������������ ������ ������, ��������� �� ��� ���������, ������� ������������ � ����� ��������. */
// https://github.com/fiorentina97/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
using namespace std;

/* ������ ������� �� �����.������ inc count, ������� ����� �������, ����� ��������� ������ ����� */

	
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

/* ����� ������� � ��������� ���� */

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

/* �������� ������� ������ ����������� � ���� �������� */

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

// �������

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
  cout<<"�������� ���� �� ������� ����:\n";
  cout << "1. �������� ������� �� �����\n";
  cout << "2. ������ ������ � �������" << endl;
  cin >> key;
  if (key == 1)
  {
    int *a;
    int *b;
    char str[40];
    cout<<"������� ��� ����� ������� A: \n";
    cin>>str;
    a=inputf(f_arrA,n,str);
    cout<<"������� ��� ����� ������� B: \n";
    cin>>str;
    b=inputf(f_arrB,m,str);
    cout<<"������� ��� ��������� �����:\n";
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
    	cout << "������� ����� ������� �������\n";
    	cin >> n;
    	int *a = new int[n];
  		cout << "������� �������� ������� �������\n";
		input_array(a,n);
		cout << "������� ����� ������� �������\n";
    	cin >> m;
    	int *b = new int[m];
    	cout << "������� �������� ������� �������\n";
		input_array(b,m);
		int k=0;
        int *d = new int[n+m];
        d = intersection(a,b,n,m,k);
        cout << "���������:\n";
		print_array(d,k);		
    }
	else exit(1);	
}
