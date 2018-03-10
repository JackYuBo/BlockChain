#include"sha256.h"



int main(void) 
{
	char text[256];
	cout << "请输入原文：\n";
	while (cin >> text)
	{
		cout << "请输入原文：\n";
		char sha256[256];
		StrSHA256(text, sizeof(text) - 1, sha256);  // sizeof()包含了末尾的终止符'\0'故 -1  
		cout << "执行SHA-256算法后的结果如下：\n";
		puts(sha256);

	}

	system("pause");
	return 0;
}