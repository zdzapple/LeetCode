long long prime = 999999997L;
long long highDigit;
int d = 10;
typedef vector<char*> vc;
map<long long, vc *> h[11];

void calL(int len)
{
    highDigit = 1;
    for (int i = 1; i < len; i ++)
	{
        highDigit = highDigit * d;
        highDigit = highDigit % prime;
    }
}

// 预处理初始化
void initWithString(char *str)
{
	int LEN = strlen(str);
     for (int len = 1; len <= 10 && len <= LEN; len ++)
	 {
        calL(len);
        long long hash = 0;

        for (int i = 0; i < len; i++)
		{
            hash = (hash * d + str[i]) % prime;
        }
		if (h[len].find(hash) == h[len].end()) {
			h[len][hash] = new vector<char*>();
		}
        h[len][hash]->push_back(str);
       // cout << hash;
       // cout << " " + string(str, len) << endl;
        for (int i = 1; i <= LEN - len; i ++)
		{
            hash = (((hash - str[i-1] * highDigit) * d) + str[i - 1 +len]) % prime;
            if (hash < 0)
                hash += prime;
			if (h[len].find(hash) == h[len].end()) {
				h[len][hash] = new vector<char*>();
			}
			char *temp = str + i;
            h[len][hash]->push_back(str + i);
           // cout << hash;
           // cout << " " + string(str + i, len) << endl;
        }
    }
}



// 如果query是str的字串,返回true,否则返回false
bool existSubString(char *query)
{
    long long hash = 0;
	char *str = query;
	int n = strlen(query);
    while (*str != '\0')
	{
        hash = (hash * d + *str) % prime;
		str ++;
    }
   // cout << endl << hash << endl;
    if (h[n].find(hash) != h[n].end()) {
		vector<char *> *vec = h[n][hash];
		vector<char *> v = *vec;

       for (int i = 0; i < v.size(); ++ i)
       {
           str = v[0];
		   // 不能用strcmp
           while (*query != '\0')
           {
               if (*query == *str) {
                str ++;
                query ++;
               }
           }
           if (*query == '\0')
                return true;
       }


	}
    return false;
}

/**
超时
因为c++的map不是O(n)
**/