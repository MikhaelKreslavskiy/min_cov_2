
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int max(vector<vector<int>>& vct, int t, int gran)
{
    long long max = gran;
    int f;
    for (long long i = 0; i < vct.size(); i++)
    {

       /// cout << vct[i][0] << " " << vct[i][1] << endl;
        if ((vct[i][0] <= gran) && (vct[i][1] >= gran))
        {
            /// cout<<max<<endl;
            if (vct[i][1] > max)
            {
                max = vct[i][1];
                ///  cout<<max<<endl;
                f = i;
            }
        }
    }
    if (max == gran) return -1;
    ///cout<<f<<endl;
    return f;

}

/*
void sort(long long size, vector<vector<int>>& vct)
{
    int tmpX, tmpY;

    for (long long i = 0; i < size; i++)
    {
        for (long long j = (size - 1); j >= i + 1; j--)
        {
            if (vct[j][1] < vct[j - 1][1])
            {
                tmpX = vct[j][0];
                vct[j][0] = vct[j - 1][0];
                vct[j - 1][0] = tmpX;

                tmpY = vct[j][1];
                vct[j][1] = vct[j - 1][1];
                vct[j - 1][1] = tmpY;


            }
        }
    }
}
*/


void qsortRecursive(vector<vector<int>>& vct, long long size) {
    //Указатели в начало и в конец массива
    int i = 0;
    long long j = size - 1;

    //Центральный элемент массива
    long long mid = vct[size / 2][1];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (vct[i][1] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (vct[j][1] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmpX = vct[i][0];
            vct[i][0] = vct[j][0];
            vct[j][0] = tmpX;

            int tmpY = vct[i][1];
            vct[i][1] = vct[j][1];
            vct[j][1] = tmpY;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        qsortRecursive(vct, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(vct, size - i);
    }
}
int main()
{
    int m;
    cin >> m;

    vector <vector<int>> vct;
    int i = 0;
    /// long long j=0;

    while (1)
    {
        vector<int >a;
        int r, l;

        cin >> r >> l;
        if ((r == 0) && (l == 0))
        {
            break;
        }

        if ((r >= m) || (l <= 0)) continue;
        a.push_back(r);
        a.push_back(l);

        vct.push_back(a);
    }

    /// cout<<vct.size();

    long long size = vct.size();
    if (vct.size() == 0) cout << "No solution" << endl;
    else{

        qsortRecursive(vct, size);
    /*
     cout<<"Sorted"<<endl;

      for(long long i=0; i<vct.size(); i++)
     {
        cout<<vct[i][0]<<" "<<vct[i][1]<<endl;
     }
     */
     //// if(vct[vct.size()-1][1]<=0)
        ///cout<<"No solution"<<endl;

        ///else{
    long long t = 0;
    int gran = 0;
    ///int count=0;
    vector<vector<int>> vct_copy;
    while ((t <= vct.size() - 1) && (gran < m))
    {
        ///if((vct[t][0]<=gran)&&((vct[t][1]>gran)&&(vct[t+1][1]<vct[t][1])))
        ///{s
        t = max(vct, t, gran);
        /// cout<<t<<endl;
        if (t == -1) break;
        gran = vct[t][1];
        vct_copy.push_back(vct[t]);
        /// t++;
     ///}
    }

    if (vct_copy.empty())
    {
        cout << "No solution" << endl;
    }
    else
    {
       /// cout << "Solution" << endl;
        if (vct_copy[vct_copy.size() - 1][1] < m) cout << "No solution" << endl;
        else
        {
            cout << vct_copy.size() << endl;

            for (long long i = 0; i < vct_copy.size(); i++)
            {
                cout << vct_copy[i][0] << " " << vct_copy[i][1] << endl;
            }
        }
    }

      }
}