/**
A 1
Z 26
AA 26*1 + 1
AZ 26*1+26

ZZ 26*26+26
AAA 26*26+26+1
**/

const int base = 26;
//将十进制数转换为excel数
string decToExcel(int decNum)
{
	string excelNum = "";
    int b = base;
	while (decNum > 0)
    {
        int num = (decNum - 1) % base;
        string ch(1, char('A' + num));
        excelNum.insert(0, ch);
        decNum -= num + 1;
        decNum /= b;
    }


	return excelNum;
}
//将excel数转换为十进制数
int excelToDec(string excelNum)
{
	int result = 0;
	for (int i = 0; i <= excelNum.size() - 1; ++ i)
	{
		int num = excelNum[i] - 'A' + 1;
		result = result * base + num;
	}
	return result;
}