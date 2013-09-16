class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(path.size() == 0) return path;
        vector<string> pathes;
        pathes.push_back("/");
        int ind = 1;
        while(ind < path.size() && path[ind] == '/') ++ind;
        while(ind < path.size()) {
            int j = ind + 1;
            while(path[j] != '/') ++j;
            string curPath = path.substr(ind, j - ind);
            if(curPath == "..") {
                if(pathes.size() != 1) pathes.pop_back();
            }
            else if(curPath != ".") pathes.push_back(curPath);
            //update ind
            ind = j;
            while(ind < path.size() && path[ind] == '/') ++ind;
        }
        
        string simplePath = pathes[0];
        for(int i = 1; i < pathes.size(); ++i) {
            simplePath += pathes[i];
            simplePath += '/';
        }
        simplePath.pop_back();
        return simplePath;
    }
};

