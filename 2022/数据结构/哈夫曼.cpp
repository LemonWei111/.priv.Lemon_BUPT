#include<iostream>
#include<cstring>
#include<stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct HNode  //��������� 
{
	int weight;
	int parent;
	int LChild;
	int RChild;
};
struct HCode  //�����
{
	char data;
	char code[100];
};
class Huffman //��������
{
private:
	HNode* HTree;
	HCode* HCodetable;
	char str[1024] = { 0 };  //ԭʼ�ַ���
	char leaf[256] = { 0 };   //Ҷ�ӽ���Ӧ�ַ�
	int amount[256] = { 0 };   //�ַ����ִ���
public:
	int n=0;          //Ҷ�ӽ����
	void putin();  //д��ԭ�ַ�������¼���ֹ����ַ�
	void getmin(HNode*, int, int& , int& );
	void createHTree();
	void Init();
	void CreateTable();
	void Encoding();
	void Decoding();
	void printHTree();
	~Huffman();
};
void Huffman::putin() 
{
	int a[256] = { 0 };
	int x = cin.get();
	int i = 0;
	while ((x != '\n') && (x != '\r')) 
	{
		a[x]++;
		str[i++] = x;
		x = cin.get();
	}
	str[i] = '\0';
	n = 0;
	for (i = 0; i < 256; i++) 
	{
		if (a[i] > 0)  //�ж��ַ��Ƿ���֣�=0˵��δ���֣� 
		{
			leaf[n] = (char)i;
			amount[n] = a[i];
			n++;
		}
	}
}
void Huffman::getmin(HNode*Htree, int n, int &lf, int&ls) 
{
	int j;
	//��һ���Ƚ�ֵ����ʼֵ
	for (j = 0; j < 2*n-1; j++) //��lf
	{
		if (Htree[j].parent == -1)
		{
			lf = j;      break;
		}
	}
	j++;
	for (; j < 2*n-1; j++) //��ls
	{
		if (Htree[j].parent == -1)
		{
			ls = j;           break;
		}
	}
	if (Htree[lf].weight > Htree[ls].weight) //lfָ����С��
	{
		int x = ls;           ls = lf;          lf = x;
	}
	j++;
	for (; j < 2*n-1; j++)
	{
		if (Htree[j].parent == -1)
		{
			if (Htree[j].weight < Htree[lf].weight)
			{
				ls =lf;              lf = j;
			}
			else if (Htree[j].weight < Htree[ls].weight)
			{
				ls = j;
			}
		}
	}
}
void Huffman::createHTree() 
{
	HNode* HTree = new HNode[2 * n - 1];
	for(int i=0;i<2*n-1;i++)
	{
		HTree[i].weight = amount[i];
		HTree[i].LChild = -1;
		HTree[i].RChild = -1;
		HTree[i].parent = -1;
	}
	int lf, ls;    //��С��Ȩ�ص��±�
	for (int i = 0; i < 2*n-1; i++) 
	{
		getmin(HTree,n,lf, ls);
		HTree[lf].parent = HTree[ls].parent = i;
		HTree[i].weight= HTree[lf].weight +HTree[ls].weight ;
		HTree[i].LChild = lf;
		HTree[i].RChild = ls;
		HTree[i].parent = -1;
	}
}
void Huffman::Init() 
{
	cout << "��������Ҫ���������" << endl;
	putin();
	createHTree();
}
void Huffman::CreateTable() 
{
	HCode* HCodetable = new HCode[n];
	cout << "���ڴ��������" << endl;
	for (int i = 0; i < n; i++) 
	{
		HCodetable[i].data = str[i];
		int i1 = i;
		int i2 = HTree[i].parent;
		int k = 0;
		while (i2 != -1) 
		{
			if (i1 == HTree[i2].LChild)
				HCodetable[i].code[k] = '0';
			else
				HCodetable[i].code[k] = '1';
			k++;
			i1 = i2;
			i2 = HTree[i1].parent;
		}
		HCodetable[i].code[k] = '\0';
		int tmp = 0;
		char* s = new char[1000];
		for (int j = strlen(HCodetable[i].code)-1; j>=0; j--)
		{
			tmp = HCodetable[i].code[j];
			for(int k=0;k < strlen(HCodetable[i].code);k++)
			s[k] = tmp;
		}
		for (int j = 0; j < strlen(HCodetable[i].code); j++)
		{
			HCodetable[i].code[j] = s[j];
			cout <<"'"<<HCodetable[i].data<<"' " << HCodetable[i].code[j] << endl;
		}
		delete[]s;
	}
}
void Huffman::Encoding() 
{
	cout << "���ڱ���" << endl;
	char* s = str;
	char* am=new char[1000];
	while (*s != '\0') 
	{
		for(int i=0;i<strlen(str);i++)
			if (*s == HCodetable[i].data) 
			{
				for (int j = 0; j < strlen(str); j++)
					am[j] = HCodetable[i].code[j];
				break;
			}
		s++;
	}
	for(int i=0;i< strlen(str);i++)
		str[i] = am[i];
	cout <<"��������"<<endl<< str << endl;
	delete[]am;
}
void Huffman::Decoding() 
{
	cout << "���ڽ���" << endl;
	char* s=str;
	char* d=new char[1000];
	while (*s != '\0')
	{
		int k = 2 * n - 2;
		while (HTree[k].LChild != -1) 
		{
			if (*s == '0')
				k = HTree[k].LChild;
			else
				k = HTree[k].RChild;
			s++;
		}
		*d= HCodetable[k].data;
		d++;
	}
	cout << *d;
	delete[]d;
}
void Huffman::printHTree()
{
	for (int i = 0; i < 2 * n - 1; i++)
	{
		cout << amount[i] << " ";
		cout << HTree[i].weight << "  " << HTree[i].parent << endl;
	}
}
Huffman::~Huffman() 
{
	cout << "�����˳�" << endl;
	delete[]HTree;
	delete[]HCodetable;
	cout << "���˳�" << endl;
}	
int main() 
{
	Huffman huffman;
	huffman.Init();
	huffman.createHTree();
	huffman.printHTree();
	huffman.CreateTable();
	huffman.Encoding();
	cout << "�Ƿ�鿴������? 1 yes,0 no" << endl;
	int x=0;
	if (x)
		huffman.Decoding();
	else;
	return 0;
}
