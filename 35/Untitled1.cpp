#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

bool isvowels(char c)
{
	string vowels="aeiouAEIOU";
	for(char v:vowels)
	{
		if(c==v)
		{
			return true;
		}
	}
	return false;
}



int countvowel(string&word)
{
	int count=0;
	for(char c:word)
	{
		if(isvowels(c))
		{
			count++;
		}
	}
	return count;
}



vector<string>splitword(string text)
{
	vector<string>result;
	string word;
	for(char c:text)
	{
		if(c=='\n'||c=='\t'||c==' ')
		{
		if(!word.empty())
			{
				result.push_back(word);
				word.clear();
			}
		}
		else
		{
			word+=c;
		}
	}
	if(!word.empty())
	{
		result.push_back(word);
	}
	return result;
}

int countword(vector<string>words,string word) {
    int count=0;
    for(string w:words) 
	{
        if(w==word)
            count++;
    }
    return count;
}


void taskA(string text,vector<string>&modifiedtext)
{
	vector<string>words=splitword(text);
	
	for(string& word:words)
	{
		int count=countvowel(word);
		if(count>2)
		{
			modifiedtext.push_back(word+" "+word+" ");
		}
		else
		{
			modifiedtext.push_back(word);
		}
	}
}

bool isInVector(vector<string> vec,string word) 
{
    for (string& w:vec) 
	{
        if(w==word) 
		return true;
    }
    return false;
}

void taskB(string text,vector<int>&topCounts,vector<string>&topwords)
{


    vector<string>words=splitword(text);
    vector<string>uniqueWords;

    for(string word:words) 
	{
        if (!isInVector(uniqueWords,word)) 
		{
            uniqueWords.push_back(word);
        }
    }

	topwords.clear();
	topCounts.clear();


    for(int i=0;i<3;i++) 
	{
        string maxWord="";
        for(string word:uniqueWords) 
		{
            if(word.length()>maxWord.length()&&!isInVector(topwords,word))
			{
                maxWord=word;
            }
        }
        if (!maxWord.empty()) 
		{
            topwords.push_back(maxWord);
            topCounts.push_back(countword(words,maxWord));
        }
    }
}

vector<string> splitsentences(string text) 
{
    vector<string>sentences;
    string sentence;
    for(char ch:text) 
	{
        sentence+=ch;
        if(ch=='.'||ch=='!'||ch=='?') 
		{
            sentences.push_back(sentence);
            sentence.clear();
        }
    }
    if (!sentence.empty())
        sentences.push_back(sentence);
    return sentences;
}

bool compare(string s1,string s2)
{
    if (s1.size()!=s2.size())
        return false;

    for(int i=0;i<s1.size();i++) 
    {
        if(tolower(s1[i])!=tolower(s2[i]))
            return false;
    }
    return true;
}

void taskC(string text,string keyword,vector<string>&foundword)
{
	vector<string>sentences=splitsentences(text);
	for(string&s:sentences)
	{
		vector<string>word=splitword(s);
		for(string&w:word)
		{
			if(compare(w,keyword))
			{
				foundword.push_back(s);
				break;
			}
		}
	}
}

string joinwords(vector<string>words) 
{
    string result;
    for (string word:words) 
    {
        result+=word+" ";
    }
    return result;
}

void taskD(vector<string>taskAResult,vector<string>taskBResult,vector<int>taskBResult1,vector<string>taskCResult) 
{
 	cout<<"Write path to save"<<endl;
 	string path;
 	cin>>path;
 	
 	ofstream fout(path);
 	fout<<"Result a): "<<endl;
 	fout<<joinwords(taskAResult)<<endl;
 	
 	fout<<"Result b): "<<endl;
 	for(int i=0;i<taskBResult.size();i++) 
	{
    fout<<taskBResult[i]<<" – "<<taskBResult1[i]<<endl;
	}

	fout<<"Result c): "<<endl;
 	for(auto line:taskCResult)
 	{
 		fout<<line<<endl;
	}
	fout.close();
	cout<<"Result saved in: "<<path<<endl;
}




void taskE(vector<string>originalwords) {
    ifstream fin("t.txt");

	vector<string>twords;
    string word;
    while(fin>>word) 
	{
        twords.push_back(word);
        if(twords.size()==originalwords.size())
            break;
    }
    fin.close();
    string s1=joinwords(twords);
    string s2=joinwords(originalwords);
    vector<string>combinedwords=twords;
    combinedwords.insert(combinedwords.end(),originalwords.begin(),originalwords.end());
    sort(combinedwords.begin(),combinedwords.end());

    string s3=joinwords(combinedwords);
    
    ofstream fout("z4.txt");
    fout<<"s1: "<<s1<<endl;
    fout<<"s2: "<<s2<<endl;
    fout<<"s3 (vidsortovanni): "<<s3<<endl;
    fout.close();

    cout<<"Result in z4.txt"<<endl;
}

string readfile(string filename) 
{
    ifstream fin(filename);
    string line,result;
    while(getline(fin,line)) 
	{
        result+=line+'\n';
    }
    return result;
}



int main()
{


	string filename="z1.txt"; 
    string text=readfile(filename);
    cout<<text<<endl;

    vector<string>words=splitword(text);
    vector<string>modifiedwords;
    vector<string>topwords;
    vector<int>topcounts;
    vector<string>matchedsentences;
	
	int choice;
    do {
        cout << "Menu"<<endl;
        cout << "1. Double words with >2 golosni(A)"<<endl;
        cout << "2. Znaity 3 naydovshih slova (B)"<<endl;
        cout << "3. Vyvesty rechennya z pevnym slovom (C)"<<endl;
        cout << "4. Vikonaty vse ta zberegty v z2.txt (D)"<<endl;
        cout << "5. Robota z parametrizovanym konstructorom (E)(nema)"<<endl;
        cout << "6. Robota z ryadkamy s1, s2, s3 (F)"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Your choice: "<<endl;
        cin >> choice;
        cin.ignore();

        switch (choice) 
		{
            case 1:
                taskA(text,modifiedwords);
                cout<<"Dublyuvannya vikonano"<<endl;
                break;
            case 2:
                taskB(text,topcounts,topwords);
                cout<<"Znaideno 3 naydovshih slova"<<endl;
                for(int i=0;i<topwords.size();i++)
                    cout<<topwords[i]<<" - "<<topcounts[i]<<endl;
                break;
            case 3: 
			{
                string searchword;
                cout<<"Write slovo dlya poshyky: ";
                getline(cin,searchword);
                matchedsentences.clear();
                taskC(text,searchword,matchedsentences);
                for (auto sentence:matchedsentences)
                    cout<<sentence<<endl;
                break;
            }
            case 4: {
		    	taskD(modifiedwords,topwords,topcounts,matchedsentences);
				break;
            }
            case 5:
                break;
            case 6:
                taskE(words);
                break;
            case 0:
                cout << "End"<<endl;
                break;
            default:
                cout << "Nevirniy vybir"<<endl;
        }
    }while(choice!=0);
	
	return 0;
}
