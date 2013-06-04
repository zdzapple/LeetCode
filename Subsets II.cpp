class Solution 
{
public:
    vector<vector<int> > subsetsWithDup1(vector<int> &S) 
	{   
        vector<int> path;
        vector<vector<int> > result;

        sort(S.begin(), S.end());
        sub(S, 0, path, result);
        return result;
    }

    void sub(vector<int> &s, int begin, vector<int> &path, vector<vector<int> > &result) 
	{
        result.push_back(path);

        for (int i = begin; i < s.size(); ++ i) 
		{
            if (i != begin && s[i] == s[i - 1]) continue;

            path.push_back(s[i]);
            sub(s, i + 1, path, result);
            path.pop_back();
        }
    }
	// http://blog.unieagle.net/2012/10/27/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Asubsets-ii/
	 vector<vector<int> > subsetsWithDup(vector<int> &S) {
         vector<vector<int> > result;
        if(S.size() < 1)
            return result;
        sort(S.begin(),S.end());
        vector<bool> pres(S.size(),false);
        //pres[0] = true;//first
        while(true) {
            //1.output current
            {
                vector<int> item;
                for(int i = 0 ; i < pres.size(); ++i){
                    if(pres[i])
                        item.push_back(S[i]);
                }
                result.push_back(item);
            }
            //2.pregress
            bool overflow = true;
            for(int i = 0 ; overflow && i < pres.size(); ++ i) {
                overflow = overflow && pres[i];
                pres[i] = !pres[i];
                //if i is present then propogate backward to the same ones.
                if(pres[i] == true) {
                    for(int j = i - 1; j >= 0 && S[j] == S[i]; -- j)
                        pres[j] = true;
                }
            }
            if(overflow) break;
        }//end of while
        return result;
    }
};