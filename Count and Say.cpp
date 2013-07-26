class Solution 
{
public:
    string countAndSay(int n) 
	{
        if (n < 0)
			return "";
		string sequence = to_string(1);
		/*
		char temp[64];		
		sprintf(temp, "%d", n);
		string sequence(temp);
		*/
		for (int i = 2; i <= n; ++ i)
		{
			string str = "";
			
			for (int j = 0; j < sequence.size(); ++ j)
			{
				int count = 1;
				while (j < sequence.size() - 1 && sequence[j+1] == sequence[j])
				{
					count ++;
					j ++;
				}
				str += ('0' + count);
				str += sequence[j];
				
			}
			sequence = str;
		}
		return sequence;
    }
};