class Solution 
{
public:
	string getSpace(int number)
	{
		if (number <= 0)
			return "";
		string s(number, ' ');
		return s;
	}
	
    vector<string> fullJustify(vector<string> &words, int L) 
	{
		vector<string> justificated;
		int n = words.size();
		if (words.empty())
			return justificated;
		for (int i = 0; i < n; ++ i)
		{
			int length = 0;
			vector<string> line;
			length += words[i].size();
			line.push_back(words[i]);
			while (true)
			{
				if (i == n-1 || length + 1 + words[i+1].size() > L) {
					break;
				}
				++ i;
				length += (words[i].size() + 1);
				line.push_back(words[i]);				
			}
			int leftSpace = L - length;
			int spaceNum = line.size() - 1;
			string lineStr = "";
			// For the last line of text, it should be left justified and no extra space is inserted between words.
			if (i == n-1)
			{
				lineStr += line[0];
				for (int j = 1; j < line.size(); ++ j)
				{
					lineStr += " ";
					lineStr += line[j];
				}
				if (lineStr.size() < L)
					lineStr += getSpace(L-lineStr.size());
				justificated.push_back(lineStr);
				break;
			}
			if (spaceNum == 0) {
				lineStr = line[0] + getSpace(leftSpace);
				justificated.push_back(lineStr);
			} else {
				int a = leftSpace / spaceNum;
				int b = leftSpace % spaceNum;
				lineStr += line[0];
				for (int j = 1; j < line.size(); ++ j)
				{
					int temp = a;
					if (b > 0) {
						b --;
						temp += 1;
					}
					lineStr += getSpace(temp + 1);
					lineStr += line[j];
				}
				justificated.push_back(lineStr);
			}
		}
		return justificated;
    }
};