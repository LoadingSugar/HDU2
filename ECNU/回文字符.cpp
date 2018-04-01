#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void dfs(string& s, int startIndex,vector<string> res,vector<vector<string> >& results)
    {
        if (startIndex >= s.length())
        {
            results.push_back(res);
        }
        for (int i = startIndex; i < s.length(); ++i)
        {
            int l = startIndex;
            int r = i;
            while (l <= r && s[l] == s[r]) ++l, --r;
            if (l >= r)
            {
                res.push_back(s.substr(startIndex, i - startIndex + 1));
                dfs(s, i + 1, res, results);
                res.pop_back();
            }
        }
    }

vector< vector<string> > partition(string s) {
        vector<vector<string> > results;
        vector<string> res;
        dfs(s, 0, res, results);
        return results;
}
int main(){
	vector< vector<string> > p;
	p=partition("aaba");
	for(int i=0;i<p.size();i++)
	{
		for(int j=0;j<p[i].size();j++)
		cout<<p[i][j]<<' ';
		cout<<endl;
	}
	return 0;
} 
