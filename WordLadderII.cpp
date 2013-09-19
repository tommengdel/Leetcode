#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    vector<string> oneSol;
    
    vector<vector<string> >sols;
    
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        oneSol.clear(); 
        sols.clear();
        int len = bfs(start, end, dict);
	cout<<"Length: "<<len<<endl;
        if(len == -1) return sols;
        
        dfs(start, end, dict, len - 1);
        return sols;
    }
    
    int bfs(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        queue<int> len;
        unordered_set<string> visited;
        
        q.push(start);len.push(1);
        int curLen = 1;
        visited.insert(start);
        while(!q.empty()) {
            string curStr = q.front(); q.pop(); curLen = len.front(); len.pop();
            string temp = curStr;//Wrong Location

            for(int i = 0; i < temp.size(); ++i) {
		temp = curStr; //Important
                for(char j = 'a'; j <= 'z'; ++j) {
                     if(j == curStr[i]) continue;
                     temp[i] = j; 
                     if(temp == end) return curLen + 1;
                     if(dict.find(temp) != dict.end() && visited.find(temp) == visited.end()) {
                         q.push(temp);
                         len.push(curLen + 1);
                         visited.insert(temp);
                     }
                
                }
            }
            
        }
        return -1;
    }
    
    
    //不设置已访问了（只是可以提高效率而已）
    void dfs(string start, string end, unordered_set<string>&dict, int len) {
        if(len == 0) {
            if(start == end) {
                oneSol.push_back(start);
                sols.push_back(oneSol);
                oneSol.pop_back();
            }
            return;
        }
        
//        string temp = start;
        oneSol.push_back(start);
        for(int i = 0; i < start.size(); ++i) {
	    string temp = start;  // A big mistake I make
            for(char j = 'a'; j <= 'z'; ++j) {
                if(j == start[i]) continue;
                temp[i] = j;
                if(temp == end) { //Important
                    dfs(temp, end, dict, len - 1);
                }
                else if(dict.find(temp) != dict.end()) {
                    dict.erase(temp); //必须加,否则可能出现异常
                    dfs(temp, end, dict, len - 1);
                    dict.insert(temp);
                }
            }
	}
        oneSol.pop_back();
    }
    
};
int main() {
	vector<string> a ={"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim",\
		"ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
	unordered_set<string> dict(a.begin(), a.end());
	
//	dict.insert("hot"); dict.insert("dog"); dict.insert("dot");
	vector<vector<string> > sol =Solution().findLadders("cet", "ism", dict);
	for(int i = 0; i < sol.size(); ++i) {
		cout<<"[";	
		for(int j = 0; j < sol[i].size(); ++j) cout<<sol[i][j]<<" ";
		cout<<"]";
		cout<<endl;
	}
}

//Time Limit Exceeded
