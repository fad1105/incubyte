#include<bits/stdc++.h>

using namespace std;

template<typename T>
void print(vector<T> v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << ", ";
    cout<<endl;
}

int giveSum(string s, char c)
{
    int sum=0;
    vector <string> tokens;
    vector<int> negatives;
    stringstream check1(s);

    string intermediate;
    
    while(getline(check1, intermediate, c))
    {
            tokens.push_back(intermediate);
    }
    
    for(int i=1;i<tokens.size();i++)
    {
        if(stoi(tokens[i])>=0)
            sum+= stoi(tokens[i]);
        else
        {
            negatives.push_back(stoi(tokens[i]));
        }
    }

    if(negatives.size()!=0)
    {
        sum=-1;
        cout<<"Negatives not allowed ! : ";
        print(negatives);
    }
    return sum;
}

int Add(string s)
{
    regex r1("(//[;,]\n)((-)?([0-9]+)([;,]))*(-)?([0-9]+)");
    regex r2("(((-)?[0-9]+)([,\n]))*(-)?([0-9]+)");
    
    if ( regex_match(s,r1) )
    {
        return giveSum(s,s[2]);
    }
    else if(regex_match(s,r2))
    {
        int sum=0;
        vector<string> temp;
        vector <string> tokens;
        vector<int> negatives;
        stringstream check1(s);
    
        string intermediate;
        
        while(getline(check1, intermediate, '\n'))
        {
            temp.push_back(intermediate);
        }

        for(int i = 0; i < temp.size(); i++)
        {
            stringstream check2(temp[i]);
            string intermediate2;
            while(getline(check2, intermediate2, ','))
            {
                tokens.push_back(intermediate2);
            }
        }
        
        for(int i=0;i<tokens.size();i++)
        {
            if(stoi(tokens[i])>=0)
                sum+= stoi(tokens[i]);
            else
            {
                negatives.push_back(stoi(tokens[i]));
            }
        }

        if(negatives.size()!=0)
        {
            sum=-1;
            cout<<"Negatives not allowed !\n";
            print(negatives);
        }

        return sum;
    }
    else
    {
        cout<<"Invalid !\n";
        return -1;
    }
}

int main()
{
    string s1,s2;
    int ans=0;
    getline(cin, s1);

    if(s1[0]=='/' && s1[1]=='/')
    {
        getline(cin, s2);
        ans=Add(s1+"\n"+s2);
    }
    else
    {
        string line;

        while (getline(cin, line))
        {
            if (line.empty()) {
                break;
            }
            s1+="\n"+line;
        }
        if(s1!="")
            ans=Add(s1);
    }

    if(ans!=-1)
        cout<<"Sum = "<<ans<<endl;
    return 0;
}