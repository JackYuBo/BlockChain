#include"sha256.h"



int main(void) 
{
	char text[256];
	cout << "������ԭ�ģ�\n";
	while (cin >> text)
	{
		cout << "������ԭ�ģ�\n";
		char sha256[256];
		StrSHA256(text, sizeof(text) - 1, sha256);  // sizeof()������ĩβ����ֹ��'\0'�� -1  
		cout << "ִ��SHA-256�㷨��Ľ�����£�\n";
		puts(sha256);

	}

	system("pause");
	return 0;
}