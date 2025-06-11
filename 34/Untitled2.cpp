#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int size=3;

class Matrix 
{
private:
    int data[size][size];
public:
    Matrix() 
	{
        for (int i=0;i<size;i++)
            for (int j=0;j<size;j++)
                data[i][j]=0;
    }

    void fillrandom(int minval, int maxval) 
	{
        for (int i=0;i<size;i++)
            for (int j=0;j<size;j++)
                data[i][j]=minval+rand()%(maxval-minval+1);
    }

    void display() const 
	{
        for (int i=0;i<size;i++) 
		{
            for (int j=0;j<size;j++)
                cout<<data[i][j]<<" ";
            cout<<endl;
        }
    }

    friend Matrix operator+(const Matrix& a, const Matrix& b);
    friend Matrix operator-(const Matrix& a, const Matrix& b);
    friend Matrix operator*(const Matrix& a, const Matrix& b);    
    friend bool operator==(const Matrix& a, const Matrix& b);    
};

Matrix operator+(const Matrix& a, const Matrix& b) 
{
    Matrix result;
    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++)
            result.data[i][j]=a.data[i][j]+b.data[i][j];
    return result;
}

Matrix operator-(const Matrix& a, const Matrix& b) 
{
    Matrix result;
    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++)
            result.data[i][j]=a.data[i][j]-b.data[i][j];
    return result;
}

Matrix operator*(const Matrix& a, const Matrix& b) 
{
    Matrix result;
    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++)
            result.data[i][j]=a.data[i][j]*b.data[i][j];
    return result;
}

bool operator==(const Matrix& a, const Matrix& b) 
{
    Matrix result;
    for (int i=0;i<size;i++)
	{
        for (int j=0;j<size;j++)
		{
			if(a.data[i][j]!=b.data[i][j])
			{
				return false;
			}
		}
	}
return true;
}
int main() 
{
    srand(time(NULL));

    Matrix m1,m2;
    int min,max;
    cout<<"Write min max for 1 matrix"<<endl;
    cin>>min>>max;
    m1.fillrandom(min,max);
	
	min=0;
	max=0;
	cout<<"Write min max for 2 matrix"<<endl;
    cin>>min>>max;
    m2.fillrandom(min,max);
	
    cout<<endl<<"Matrix 1:"<<endl;
    m1.display();
	
    cout<<endl<<"Matrix 2:"<<endl;
    m2.display();
    
    cout<<endl<<"If matrix =="<<endl;
	
	if(m1==m2)
	{
		cout<<"Matrix odnakovi"<<endl;
	}
	else
	{
		cout<<"Ne odnakovi "<<endl;
	}
	
    Matrix sum=m1+m2;
    Matrix diff=m1-m2;
    Matrix mnozh=m1*m2;

    cout<<endl<<"Sum matrix"<<endl;
    sum.display();

	cout<<endl<<"Mnozhennya "<<endl;
	mnozh.display();
	
    cout<<endl<<"Riznitsya"<<endl;
    diff.display();
    

    return 0;
}