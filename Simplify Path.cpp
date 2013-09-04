class Solution 
{
public:
	vector<string> split(string& str, const char* c)
	{
		char *cstr, *p;
		vector<string> res;
		cstr = new char[str.size()+1];
		strcpy(cstr, str.c_str());
		p = strtok(cstr, c);
		while (p != NULL)
		{
			res.push_back(p);
			p = strtok(NULL, c);
		}
		return res;
	}
	
    string simplifyPath(string path) 
	{
		char *ch = "/";
		string result = "";
        vector<string> res = split(path, ch);
		if (res.empty())
			return "/";
		vector<string> s;// stack
		for (int i = 0; i < res.size(); ++ i)
		{
			if (res[i] == ".") {
				// current path
				continue;
			} else if (res[i] == "..") {
				// upwards 
				if (!s.empty())
					s.pop_back();
			} else {
				s.push_back(res[i]);
			}
		}
		if (s.empty())
			return "/";
		for (int i = 0; i < s.size(); ++ i)
		{
			result += "/";
			result += s[i];
		}
        return result;
    }
};

/* or
class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> pathes;
        string seg = "";
        for(int i = 0; i <= path.size(); ++i) {
            if(i == path.size() || path[i] == '/') {
                if(seg == "..") {
                    if(pathes.size() > 0) {
                        pathes.pop_back();
                    } else {
                        //return "/";//error, in the test set, this case just ignore
                    }
                } else if(seg == ".") {
                    //do nothing
                } else if(seg.size() > 0) {
                    pathes.push_back(seg);
                }
                seg = "";
            } else {
                seg += path[i];
            }
        }
        string ret="/";
        for(int i = 0; i < pathes.size(); ++i) {
            if(i>0) ret += "/";
            ret += pathes[i];
        }
        return ret;
    }
};

*/