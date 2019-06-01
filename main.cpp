#include <bits/stdc++.h>

using namespace std;

vector<int> conv2vect(int i)
{
    int numd = 1;
    vector<int> res;
    int temp = 1;
    while ((i/numd) !=0)
    {
        temp = (i/numd)%10;
        res.push_back(temp);
        numd*=10;
    }

    return res;
}
// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    //https://www.codechef.com/wiki/tutorial-small-factorials
    vector<int> a(200);
    a[0] = 1; //initialize the first index to 1
    int m = 1; //number of used digits in the array
    int i = 1;
    while (i<=n)
    {
        //convert i into a vector of elements first
        //vector<int> iconv = conv2vect(i);
        //mulitply the array with i and update it
        int x = 0;
        int temp = 0;
        for(int ii=0; ii<m; ++ii)
        {
            x = a[ii]*i + temp;
            a[ii] = x%10;
            temp = x/10;
        }
        while(temp!=0)
        {
            m++;
            a[m-1] = temp%10;
            temp = temp/10;
        }
        ++i;
    }
    for(int i=m-1; i>=0; --i)
        cout<<a[i];
    cout<<'\n';
}

// Complete the extraLongFactorials function below.
void extraLongFactorialschk(int n) {
    long double factres=1;
    for(int i=1; i<=n; ++i)
    {
        factres=(long double) factres*i;
    }
    cout << fixed;
    cout<<setprecision(0);
    cout<<factres<<'\n';

}

int main()
{
    int n=25;
    //cin >> n;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<setw(17)<<"Exact: ";
    extraLongFactorialschk(n);
    cout<<setw(17)<<"Using Algorithm: ";
    extraLongFactorials(n);



    return 0;
}
