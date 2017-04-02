#include <QCoreApplication>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{

    int arr[] = {1,4,9,16,-1,25};
    int sum = 0;
    try
    {
        for(int i = 0; i < 6; i++)
        {
            if(arr[i] < 0) throw -1;
            sum+=sqrt(arr[i]);
        }
    }

    catch(int)
    {
        cout << "Від'ємне число в масиві!!!" << endl;
    }

}
