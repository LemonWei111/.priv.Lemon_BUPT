#include<iostream>
using namespace std;


char s[1000000];

int main() {
	cout << "���������뼰�ܳ�" << endl;
	int m = 0; char t = getchar();
	for (; !isdigit(t); t = getchar())
		s[++m] = t;
	
	for (int i = 1; i <= m; ++i) {
		if (!isalpha(s[i])) continue;
		if (s[i] - 'A' + 1 <= (t - '0'))
			s[i] += 26;
		s[i] -= (t - '0');
		
}
	printf("%s", s + 1);
	return 0;
}


/*int main() {
	int n = 0;
	cout << "�������ܳ�" << endl;
	cin >> n;
	char sm;
	cout << "����������" << endl;
	cout << "����������" << endl; 
	for (int i = 1; i >0; i++)
	{
		char s = getchar();//ÿһ������ʼ�ջ�������n��ȡΪs��������ͬ��ֵת�������Դ˴�Ӧ�ÿ�������forѭ��
		sm =((s - 'a') - n )%26+ 'a';//�������ַ�Ҳ��ȡ��ASCII�룬�����ڵڶ�����forѭ��ʱ��Ӧ������
		cout << sm;
	}
	cin.get();
		return 0;
}*/