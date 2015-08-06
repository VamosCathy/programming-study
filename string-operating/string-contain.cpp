#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool stringContain_bit(string &a,string &b){
/*位运算*/
    int hash = 0;
    for (int i = 0; i < a.length();++i)
        hash |= (1 << (a[i] - 'A'));
    for (int i = 0; i < b.length();++i){
        if((hash & (1 << (b[i] - 'A')) == 0)
            return false;
    }
    return true;
}

bool stringContain_sort(string &a,string &b){
/*字符串包含——普通排序法
时间复杂度：排序：O(mlogm + nlogn)
遍历：O(m + n)
*/
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int pa = 0,pb = 0;pb < b.length();){
        while(pa < a.length() && a[pa] < b[pb])
            pa++;
        if(pa >= a.length() || a[pa] > b[pb])
            return false;
        pb++;
    }
    return true;
}

bool stringContain_count(string &a,string &b){
/*线性时间计数法
时间复杂度：O(m + n)
*/
    vector<int> have;
    have.resize(26,0);
    for(int i = 0;i < a.length();i++)
        ++have[a[i] - 'A'];
    for(int i = 0;i < b.length();i++){
        if(have[b[i] - 'A'] == 0)
            return false;
    }
    return true;
}

int main(){
    string a = "abcmedzuv";
    string b = "mav";
    if(stringContain_count(a,b))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
