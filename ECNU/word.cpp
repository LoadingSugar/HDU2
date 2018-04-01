#include < iostream > 
#include < string > 
#include < vector > 
#include < algorithm > 
using namespace std;
int cmp(string s, string d) {
    return s.size() > d.size();
}
void getResult(string s) {
    int len = s.size();
    vector < string > svec;
    for (int i = 0; i < len; i++) {
        int j = 0;
        char word[100] = {0};
        while (isalpha(s[i])) {
            word[j++] = s[i];
            i++;
        }
        word[j] = '\0';
        svec.push_back(word);
    }
    sort(svec.begin(), svec.end(), cmp);
    for (int i = 0; i < svec.size(); i++) {
        for (int j = i + 1; j < svec.size(); j++) {
            if (svec[i] == svec[j]) svec[j] = "\0";
        }
    }

    for (int i = 0; i < svec.size(); i++) {
        if (svec[i] != "\0") cout << svec[i] << " ";
    }

}

int main() {
    string s;
    getline(cin, s);
    getResult(s);
    return 0;
}
