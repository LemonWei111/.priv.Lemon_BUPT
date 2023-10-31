#include <iostream>
#include <Cstdlib>
#include <iostream>
#include <cmath> 
using namespace std;
template< class E>
struct Node {
    E data;
    struct Node* LCh;
    struct Node* RCh;
    int balanceFctor;           //ƽ������
};
template< class E>
class BalanceBiTree {
public:
    BalanceBiTree(Node<E>*& T);                         //��ʼ��
    static void menu();                                 //�˵�
    void destory(Node<E>*& T);                        //���ٶ�����
    void insert(Node<E>*& T, Node<E>* S);   		//��ָ��S��ָ�ڵ�������������
    int BiTreeDepth(Node <E>* T);                  //�����ĸ߶�
    int getNodeFactor(Node<E>* T);                 //�����нڵ��ƽ������
    void factorForTree(Node<E>*& T);
    //�����е�ÿ���ڵ��ƽ������
    void nodeFctorIsTwo(Node<E>*& T, Node<E>*& p);
    //���ƽ������Ϊ2��-2�Ľڵ�
    void nodeFctorIsTwoFather(Node<E>*& T, Node<E>*& f);
    //���ƽ������Ϊ2��-2�Ľڵ�ĸ��ڵ�
    void LLAdjust(Node<E>*& T, Node<E>*& p, Node<E>*& f);
    void LRAdjust(Node<E>*& T, Node<E>*& p, Node<E>*& f);
    void RLAdjust(Node<E>*& T, Node<E>*& p, Node<E>*& f);
    void RRAdjust(Node<E>*& T, Node<E>*& p, Node<E>*& f);
    void AllAdjust(Node<E>*& T);
    //����ƽ������
    void BiTreeToArray(Node <E>* T, E A[], int i, int& count);
    //������ת����
    void LevelTraverse(Node <E>* T, E B[], int num);
    //�Զ��������ʾ�Ķ������������ϵ��£������Ҵ�ӡ���ֵ��������δ�ӡ
    void createSubBalanceBiTree(Node<E>*& T);          //������������ƽ����
    void search(Node <E>*& T, Node <E>*& p, E x);
    //����Ԫ��x
    Node <E>* getElementFatherPointer(Node <E>*& T, Node <E>*& f, E x);
    //��ȡĳ��Ԫ�صĸ���ָ�룬�����ڷ���NULL
    void getPriorElement(Node <E>*& T, E& min, E& max);                 	//��ȡǰ��Ԫ��
    Node <E>* getElementPriorPointer(Node <E>*& T);
    //��ȡĳ��Ԫ�ص�ǰ��ָ��
    void getNextElement(Node <E>*& T, E& min, E& max);                  	//��ȡ���Ԫ��
    Node <E>* getElementNextPointer(Node <E>*& T);
    //��ȡĳ��Ԫ�صĺ��ָ��
    void deleteLeafNode(Node <E>*& T, Node <E>*& p, Node <E>*& f);
    //ɾ��Ҷ�ӽڵ�
    void deleteO(Node <E>*& T, Node <E>*& p, Node <E>*& f);
    //ɾ��������������ֻ���������Ľڵ�
    void deleteT(Node <E>*& T, Node <E>*& p);
    //ɾ�����������������������Ľڵ�
    void alldelete(Node <E>*& T, E x);
private:
    Node<E>* root;   //����
};
template< class E>
BalanceBiTree<E>::BalanceBiTree(Node<E>*& T)
{
    T = NULL;
}
template< class E>
void BalanceBiTree<E>::menu()
{
    cout << "1��������ƽ����" << endl;
    cout << "2����" << endl;
    cout << "3ɾ��" << endl;
    cout << "4���" << endl;
    cout << "0����ƽ�������" << endl;
}
template< class E>
void BalanceBiTree<E>::destory(Node<E>*& T)
{
    if (T)
    {
        destory(T->LCh);
        destory(T->RCh);
        delete T;
    }
}
template< class E>
void BalanceBiTree<E>::insert(Node<E>*& T, Node<E>* S)
{
    if (T == NULL)
        T = S;
    else if (S->data < T->data)
        insert(T->LCh, S);
    else
        insert(T->RCh, S);
}
template< class E>
int BalanceBiTree<E>::BiTreeDepth(Node <E>* T)
{
    int m, n;
    if (T == NULL)
        return 0;           //�������߶�Ϊ0
    else {
        m = BiTreeDepth(T->LCh);   //���������߶ȣ��ݹ飩
        n = BiTreeDepth(T->RCh);   //���������߶ȣ��ݹ飩
        if (m > n)
        {
            return m + 1;
        }
        else {
            return n + 1;
        }
    }
}
template< class E>
int BalanceBiTree<E>::getNodeFactor(Node<E>* T)
{
    int m = 0, n = 0;
    if (T)
    {
        m = BiTreeDepth(T->LCh);
        n = BiTreeDepth(T->RCh);
    }
    return m - n;
}
template< class E>
void BalanceBiTree<E>::factorForTree(Node<E>*& T)
{
    if (T)
    {
        T->balanceFctor = getNodeFactor(T);
        factorForTree(T->LCh);
        factorForTree(T->RCh);
    }
}
template< class E>
void BalanceBiTree<E>::nodeFctorIsTwo(Node<E>*& T, Node<E>*& p)
{
    if (T)
    {
        if (T->balanceFctor == 2 || T->balanceFctor == -2)
        {
            p = T;
        }
        nodeFctorIsTwo(T->LCh, p);
        nodeFctorIsTwo(T->RCh, p);
    }
}
template< class E>
void BalanceBiTree<E>::nodeFctorIsTwoFather(Node<E>*& T, Node<E>*& f)
{
    if (T)
    {
        if (T->LCh != NULL)
        {
            if (T->LCh->balanceFctor == 2 || T->LCh->balanceFctor == -2)
            {
                f = T;
            }
        }
        if (T->RCh != NULL)
        {
            if (T->RCh->balanceFctor == 2 || T->RCh->balanceFctor == -2)
            {
                f = T;
            }
        }
        nodeFctorIsTwoFather(T->LCh, f);
        nodeFctorIsTwoFather(T->RCh, f);
    }
}
template< class E>
void BalanceBiTree<E>::LLAdjust(Node<E>*& T, Node<E>*& p, Node<E>*& f)
{
    Node<E>* r;
    if (T == p)           //->balanceFctor==2&&T->LCh->balanceFctor!=2
    {
        T = p->LCh;        //��P����������Ϊ�µĸ��ڵ�
        r = T->RCh;
        T->RCh = p;        //��p��Ϊ�����ӵ��Һ���
        p->LCh = r;        //��pԭ�������ӵ��Һ���������p������

    }
    else {
        if (f->LCh == p)     //f��������p
        {
            f->LCh = p->LCh;        //��P����������Ϊ�µĸ��ڵ�
            r = f->LCh->RCh;
            f->LCh->RCh = p;        //��p��Ϊ�����ӵ��Һ���
            p->LCh = r;        //��pԭ�������ӵ��Һ���������p������
        }
        if (f->RCh == p)     //f��������p
        {
            f->RCh = p->LCh;        //��P����������Ϊ�µĸ��ڵ�
            r = f->RCh->RCh;
            f->RCh->RCh = p;        //��p��Ϊ�����ӵ��Һ���
            p->LCh = r;        //��pԭ�������ӵ��Һ���������p������
        }
    }
}
template< class E>
void BalanceBiTree<E>::LRAdjust(Node<E>*& T, Node<E>*& p, Node<E>*& f)
{
    Node<E>* l, * r;
    if (T == p)           //->balanceFctor==2&&T->LCh->balanceFctor!=2
    {
        T = p->LCh->RCh;    //��P�����ӵ��Һ�������Ϊ�µĸ��ڵ�
        r = T->RCh;
        l = T->LCh;
        T->RCh = p;
        T->LCh = p->LCh;
        T->LCh->RCh = l;
        T->RCh->LCh = r;
    }
    else {
        if (f->RCh == p)     //f��������p
        {
            f->RCh = p->LCh->RCh;    //��P�����ӵ��Һ�������Ϊ�µĸ��ڵ�
            r = f->RCh->RCh;
            l = f->RCh->LCh;
            f->RCh->RCh = p;
            f->RCh->LCh = p->LCh;
            f->RCh->LCh->RCh = l;
            f->RCh->RCh->LCh = r;
        }
        if (f->LCh == p)     //f��������p
        {
            f->LCh = p->LCh->RCh;    //��P�����ӵ��Һ�������Ϊ�µĸ��ڵ�
            r = f->LCh->RCh;
            l = f->LCh->LCh;
            f->LCh->RCh = p;
            f->LCh->LCh = p->LCh;
            f->LCh->LCh->RCh = l;
            f->LCh->RCh->LCh = r;
        }
    }
}
template< class E>
void BalanceBiTree<E>::RLAdjust(Node<E>*& T, Node<E>*& p, Node<E>*& f)
{
    Node<E>* l, * r;
    if (T == p)           //->balanceFctor==-2&&T->RCh->balanceFctor!=-2
    {
        T = p->RCh->LCh;
        r = T->RCh;
        l = T->LCh;
        T->LCh = p;
        T->RCh = p->RCh;
        T->LCh->RCh = l;
        T->RCh->LCh = r;
    }
    else {
        if (f->RCh == p)     //f��������p
        {
            f->RCh = p->RCh->LCh;
            r = f->RCh->RCh;
            l = f->RCh->LCh;
            f->RCh->LCh = p;
            f->RCh->RCh = p->RCh;
            f->RCh->LCh->RCh = l;
            f->RCh->RCh->LCh = r;
        }
        if (f->LCh == p)     //f��������p
        {
            f->LCh = p->RCh->LCh;
            r = f->LCh->RCh;
            l = f->LCh->LCh;
            f->LCh->LCh = p;
            f->LCh->RCh = p->RCh;
            f->LCh->LCh->RCh = l;
            f->LCh->RCh->LCh = r;
        }
    }
}
template< class E>
void BalanceBiTree<E>::RRAdjust(Node<E>*& T, Node<E>*& p, Node<E>*& f)
{
    Node<E>* l;
    if (T == p)                   //->balanceFctor==-2&&T->RCh->balanceFctor!=-2
    {
        T = p->RCh;        //��P���Һ�������Ϊ�µĸ��ڵ�
        l = T->LCh;
        T->LCh = p;        //��p��Ϊ���Һ��ӵ�����
        p->RCh = l;        //��pԭ�����Һ��ӵ�����������p���Һ���
    //ע�⣺p->RCh->balanceFctor==0����ڵ�ʱ�ò��ϣ�ɾ���ڵ�ʱ����
    }
    else {
        if (f->RCh == p)     //f���Һ�����p
        {
            f->RCh = p->RCh;        //��P���Һ�������Ϊ�µĸ��ڵ�
            l = f->RCh->LCh;
            f->RCh->LCh = p;        //��p��Ϊ���Һ��ӵ�����
            p->RCh = l;        //��pԭ�����Һ��ӵ�����������p���Һ���
        }
        if (f->LCh == p)     //f��������p
        {
            f->LCh = p->RCh;        //��P����������Ϊ�µĸ��ڵ�
            l = f->LCh->LCh;
            f->LCh->LCh = p;        //��p��Ϊ�����ӵ�����
            p->RCh = l;        //��pԭ�����Һ��ӵ�����������p���Һ���
        }
    }
}
template< class E>
void BalanceBiTree<E>::AllAdjust(Node<E>*& T)
{
    Node<E>* f = NULL, * p = NULL;
    factorForTree(T);
    nodeFctorIsTwoFather(T, f);
    nodeFctorIsTwo(T, p);
    while (p)
    {
        factorForTree(T);
        if (p->balanceFctor == 2 && (p->LCh->balanceFctor == 1 || p->LCh->balanceFctor == 0))
        {
            LLAdjust(T, p, f);
            factorForTree(T);
        }
        else if (p->balanceFctor == 2 && p->LCh->balanceFctor == -1)
        {
            LRAdjust(T, p, f);
            factorForTree(T);
        }
        else if (p->balanceFctor == -2 && p->RCh->balanceFctor == 1)
        {
            RLAdjust(T, p, f);
            factorForTree(T);
        }
        else if (p->balanceFctor == -2 && (p->RCh->balanceFctor == -1 || p->RCh->balanceFctor == 0))  //||p->RCh->balanceFctor==0
        {
            RRAdjust(T, p, f);
        }
        f = NULL;
        p = NULL;
        nodeFctorIsTwoFather(T, f);
        nodeFctorIsTwo(T, p);
    }
}
template<class E>
void BalanceBiTree<E>::BiTreeToArray(Node <E>* T, E A[], int i, int& count)
{
    if (T != NULL)
    {
        A[i] = T->data;
        if (i > count)
            count = i;
        BiTreeToArray(T->LCh, A, 2 * i, count);
        BiTreeToArray(T->RCh, A, 2 * i + 1, count);
    }
}
template<class E>
void BalanceBiTree<E>::LevelTraverse(Node <E>* T, E B[], int num)
{
    int n, i, j, t, q, s, p, m = 0, k = 0;
    n = (int)((log(num) / log(2)) + 1);
    p = n;
    for (i = 0; i < n; i++)
    {
        k += pow(2, m) ;
        t = pow(2, m);
        j = pow(2, p - 1) - 1;
        q = pow(2, p) - 1;
        s = q;
        for (j; j > 0; j--)
        {
            cout << " ";
        }
        for (t; t <= k; t++)
        {
            if (B[t] == 0)
            {
                cout << "*";
                for (q; q > 0; q--)
                    cout << " ";
                q = s;
            }
            else {
                cout << B[t];
                for (q; q > 0; q--)
                    cout << " ";
                q = s;
            }
        }
        m++;
        p--;
        j = n - i - 1;
        cout << endl;
    }
}
template< class E>
void BalanceBiTree<E>::createSubBalanceBiTree(Node<E>*& T)
{
    int level = 1;
    int i = 1, j = 0;
    int A[100] = { 0 };
    int length = 0;
    E x;
    Node<E>* S, * p;
    T = new Node<E>;
    T->balanceFctor = 0;
    T->LCh = NULL;
    T->RCh = NULL;
    p = T;
    cout << "������Ԫ��(-9999�˳�)��";
    cin >> x;
    T->data = x;
    while (x != -9999)
    {
        cout << "������Ԫ�أ�";
        cin >> x;
        if (x == -9999)
            return;
        S = new Node<E>;
        S->data = x;
        S->balanceFctor = 0;
        S->LCh = NULL;
        S->RCh = NULL;
        insert(p, S);
        AllAdjust(T);
        p = T;
        cout << endl;
        BiTreeToArray(T, A, i, length);
        cout << "����״ͼΪ��" << endl;
        LevelTraverse(T, A, length);
        j = 0;
        for (j; j < 100; j++)
            A[j] = 0;
        level = 1;
        i = 1;
    }
}
template<class E>
void BalanceBiTree<E>::search(Node <E>*& T, Node <E>*& p, E x)
{
    if (T)
    {
        if (T->data == x)
            p = T;
        search(T->LCh, p, x);
        search(T->RCh, p, x);
    }
}
template<class E>
Node <E>* BalanceBiTree<E>::getElementFatherPointer(Node <E>*& T, Node <E>*& f, E x)
{
    if (T)
    {
        if (T->LCh != NULL)
        {
            if (T->LCh->data == x)
                f = T;
        }
        if (T->RCh != NULL)
        {
            if (T->RCh->data == x)
                f = T;
        }
        getElementFatherPointer(T->LCh, f, x);
        getElementFatherPointer(T->RCh, f, x);
    }
    return f;
}
template<class E>
void BalanceBiTree<E>::getPriorElement(Node <E>*& T, E& min, E& max)
{
    if (T)
    {
        min = T->data;
        if (min > max)
            max = min;
        getPriorElement(T->LCh, min, max);
        getPriorElement(T->RCh, min, max);
    }
}
template<class E>
Node <E>* BalanceBiTree<E>::getElementPriorPointer(Node <E>*& T)
{
    Node <E>* p;
    E min = 0, max = -9999;
    getPriorElement(T, min, max);
    search(T, p, max);
    return p;
}
template<class E>
void BalanceBiTree<E>::getNextElement(Node <E>*& T, E& min, E& max)
{
    if (T)
    {
        max = T->data;
        if (min > max)
            min = max;
        getNextElement(T->LCh, min, max);
        getNextElement(T->RCh, min, max);
    }
}
template<class E>
Node <E>* BalanceBiTree<E>::getElementNextPointer(Node <E>*& T)
{
    Node <E>* p;
    E min = 9999, max = 0;
    getNextElement(T, min, max);
    search(T, p, min);
    return p;
}
template<class E>
void BalanceBiTree<E>::deleteLeafNode(Node <E>*& T, Node <E>*& p, Node <E>*& f)
{
    if (p == NULL)
    {
        cout << "�˽ڵ㲻���ڣ�����ɾ��" << endl;
        return;
    }
    if (T == p)        //���ڵ㼴ΪҶ�ӽڵ�
    {
        delete p;
        T = NULL;
    }
    else {           //ɾ���ڵ�Ϊ�Ǹ��ڵ��Ҷ�ӽڵ�
        if (f->LCh == p)
        {
            delete p;
            f->LCh = NULL;
        }
        if (f->RCh == p)
        {
            delete p;
            f->RCh = NULL;
        }
    }
}
template<class E>
void BalanceBiTree<E>::deleteO(Node <E>*& T, Node <E>*& p, Node <E>*& f)
{
    if (p == NULL)
    {
        cout << "�˽ڵ㲻���ڣ�����ɾ��" << endl;
        return;
    }
    if (T == p)
    {
        if (T->LCh == NULL && T->RCh != NULL)
        {
            T = p->RCh;
            delete p;
        }
        if (T->RCh == NULL && T->LCh != NULL)
        {
            T = p->LCh;
            delete p;
        }
    }
    else {
        if (p->LCh != NULL)
        {
            if (f->LCh == p)
                f->LCh = p->LCh;
            else
                f->RCh = p->LCh;
        }
        if (p->RCh != NULL)
        {
            if (f->LCh == p)
                f->LCh = p->RCh;
            else
                f->RCh = p->RCh;
        }
    }
}
template<class E>
void BalanceBiTree<E>::deleteT(Node <E>*& T, Node <E>*& p)
{
    Node <E>* f, * next, * prior;
    if (p == NULL)
    {
        cout << "�˽ڵ㲻���ڣ�����ɾ��" << endl;
        return;
    }
    if (p->balanceFctor == 1)                             //p��ƽ������Ϊ1ʱ����p��ǰ���ڵ����p
    {
        prior = getElementPriorPointer(p->LCh);             //���x��ǰ��ָ��
        if (prior->LCh != NULL && prior->RCh == NULL)   //���һǰ���ڵ�ֻ������
        {
            p->data = prior->data;
            prior->data = prior->LCh->data;
            delete prior->LCh;
            prior->LCh = NULL;
        }
        if (prior->LCh == NULL && prior->RCh == NULL)    //�����ǰ���ڵ�ΪҶ�ӽڵ�
        {
            getElementFatherPointer(T, f, prior->data); //�õ�ǰ���ڵ�ĸ��ڵ�
            p->data = prior->data;
            delete prior;
            f->RCh = NULL;
        }
    }
    else if (p->balanceFctor == -1)                             //p��ƽ������Ϊ-1ʱ����p�ĺ�̽ڵ����p
    {
        next = getElementNextPointer(p->RCh);                //���x�ĺ��ָ��
        cout << next->data;
        int level = 1;
        if (next->RCh != NULL && next->LCh == NULL)      //���һ��̽ڵ�ֻ���Һ���
        {
            p->data = next->data;
            next->data = next->RCh->data;
            delete next->RCh;
            next->RCh = NULL;
        }
        else if (next->RCh == NULL && next->LCh == NULL)       //�������̽ڵ�ΪҶ�ӽڵ�
        {
            getElementFatherPointer(T, f, next->data);     //�õ���̽ڵ�ĸ��ڵ�
            p->data = next->data;
            delete next;
            f->LCh = NULL;
        }
    }
    else if (p->balanceFctor == 0)     //p��ƽ������Ϊ0ʱ����p��ǰ�����̽ڵ����p��������ǰ��
    {
        prior = getElementPriorPointer(p->LCh);               //���x��ǰ��ָ��
        if (prior->LCh != NULL && prior->RCh == NULL)     //���һǰ���ڵ�ֻ������
        {
            p->data = prior->data;
            prior->data = prior->LCh->data;
            delete prior->LCh;
            prior->LCh = NULL;
        }
        if (prior->LCh == NULL && prior->RCh == NULL)      //�����ǰ���ڵ�ΪҶ�ӽڵ�
        {
            getElementFatherPointer(T, f, prior->data);     //�õ�ǰ���ڵ�ĸ��ڵ�
            p->data = prior->data;
            delete prior;
            if (p == f)                                      //�����Ҫ������䣬Ψ��p->balanceFctor==0��Ҫ����***
                f->LCh = NULL;
            else
                f->RCh = NULL;

        }
    }
}
template<class E>
void BalanceBiTree<E>::alldelete(Node <E>*& T, E x)
{
    Node <E>* f, * p = NULL;
    search(T, p, x);
    getElementFatherPointer(T, f, x);
    if (p == NULL)
    {
        cout << "�����ڴ˽ڵ㣬ɾ��ʧ�ܣ�" << endl;
        return;
    }
    if (p->LCh == NULL && p->RCh == NULL)  //���һɾ���ڵ�ΪҶ�ӽڵ�
    {
        deleteLeafNode(T, p, f);
        if (T != NULL)
            AllAdjust(T);
    }
    else if ((p->LCh == NULL && p->RCh != NULL) || (p->LCh != NULL && p->RCh == NULL))
    {
        deleteO(T, p, f);
        if (T != NULL)
            AllAdjust(T);
    }
    else                           //if(p->LCh!=NULL&&p->RCh!=NULL)
    {
        deleteT(T, p);
        if (T != NULL)
            AllAdjust(T);
    }
}
void initArray(int A[])
{
    int i = 0;
    for (i; i < 100; i++)
        A[i] = 0;
}
int main()
{
    int x, y;
    int i = 1;
    int level = 1;
    int A[100] = { 0 };
    int B[100] = { 0 };
    int length = 0;       //�洢����A����ЧԪ�ظ���
    Node<int>* root;
    Node<int>* p;
    BalanceBiTree<int> T(root);
    BalanceBiTree<int>::menu();
    cout << "������ִ����ţ�";
    cin >> x;
    while (x != 0)
    {
        switch (x)
        {
        case 1:
            T.createSubBalanceBiTree(root);
            break;
        case 2:
            cout << "������Ҫ��ѯԪ�ص�ֵ��";
            cin >> x;
            T.search(root, p, x);
            if (p != NULL)
            {
                if (p->data == x)
                    cout << "Ԫ�ش��ڣ�" << endl;
                else
                    cout << "Ԫ�ز����ڣ�" << endl;
            }
            else {
                cout << "Ԫ�ز����ڣ�" << endl;
            }
            break;
        case 3:
            i = 1;
            initArray(A);
            level = 1;
            cout << "������Ҫɾ��Ԫ�ص�ֵ��";
            cin >> x;
            T.alldelete(root, x);
            T.BiTreeToArray(root, A, i, length);
            cout << "����״ͼΪ��" << endl;
            T.LevelTraverse(root, A, length);
            break;
        case 4:
            i = 1;
            initArray(A);
            T.AllAdjust(root);
            T.BiTreeToArray(root, A, i, length);
            cout << "����״ͼΪ��" << endl;
            T.LevelTraverse(root, A, length);
            break;
        }
        system("pause");
        system("CLS");
        BalanceBiTree<int>::menu();
        cout << "������ִ����ţ�";
        cin >> x;
    }
    if (root != NULL)
        T.destory(root);
    return 0;
}