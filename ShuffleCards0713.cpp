/************************************************************************/
/* ϴ����������ʮ�ֳ�����������Ҫдһ������ģ��ϴ�ƵĹ��̡� ������Ҫϴ2n���ƣ����ϵ��������ǵ�1�ţ���2�ţ���3��һֱ����2n�š����ȣ����ǰ���2n���Ʒֳ����ѣ��������ŵ�1�ŵ���n�ţ��ϰ�ѣ����������ŵ�n+1�ŵ���2n�ţ��°�ѣ������žͿ�ʼϴ�ƵĹ��̣��ȷ������ֵ����һ���ƣ��ٷ������ֵ����һ���ƣ����ŷ������ֵĵ����ڶ����ƣ��ٷ������ֵĵ����ڶ����ƣ�ֱ�����������ֵĵ�һ���ơ����Ű��ƺϲ������Ϳ����ˡ� ������6���ƣ��ʼ�Ƶ�������1,2,3,4,5,6�����ȷֳ����飬��������1,2,3����������4,5,6����ϴ�ƹ����а�˳�������6,3,5,2,4,1�������������ٴκϳ�һ����֮�����ǰ��մ������µ�˳�������ƣ��ͱ��������1,4,2,5,3,6�� ���ڸ���һ��ԭʼ���飬������⸱��ϴ��k��֮��������µ����С� 
��������:
��һ��һ����T(T �� 100)����ʾ��������������ÿ�����ݣ���һ��������n,k(1 �� n,k �� 100)��������һ����2n����a1,a2,...,a2n(1 �� ai �� 1000000000)����ʾԭʼ������ϵ��µ����С�


�������:
����ÿ�����ݣ����һ�У����յ����С�����֮���ÿո��������Ҫ����ĩ�������Ŀո�

��������1:
3
3 1
1 2 3 4 5 6
3 2
1 2 3 4 5 6
2 2
1 1 1 1

�������1:
1 4 2 5 3 6
1 5 4 3 2 6
*/
/************************************************************************/
//�ó������ʵ��һ���������������飬���һ���԰�ÿ����ϴ�ƽ����� 

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	void ShuffleCards(vector<int>&cardArray,int k,vector<vector<int> >&outArray,int &t);
	int T,x;
	cin>>T;
	vector<int> xArray;
	int n,k;

	vector<vector<int> >outArray(T);//����T�еĶ�ά���飬��ͬ�п��Բ��ȳ�
	int t=0;
	while (T--)
	{
		cin>>n>>k;
		vector<int> cardArray(2*n);//һ����
		for (int i=0;i<2*n;i++)
			cin>>cardArray[i];
		ShuffleCards(cardArray,k,outArray,t);
		t++;
	}
	for (int outi=0;outi<t;outi++)
	{
		for(vector<int>::const_iterator p=outArray[outi].begin();p!=outArray[outi].end();p++)
		{
			if (p==outArray[outi].end()-1)
				cout<<*p;
			else
				cout<<*p<<" ";
		}
		if (outi<t-1)
			cout<<endl;
	}
	return 0;
}
void ShuffleCards(vector<int>&cardArray,int k,vector<vector<int> >&outArray,int&t)
{
	int len=cardArray.size();
	vector<int>a(len);
	while (k--)
	{
		for (int j=len-1,i=len/2;j>0;j=j-2,i--)
		{
			a[j]=cardArray[i+len/2-1];
			a[j-1]=cardArray[i-1];

		}
		for (int j=0;j<len;j++)
			cardArray[j]=a[j];
	}
	outArray[t].resize(len);
	for (int j=0;j<len;j++)
		outArray[t][j]=cardArray[j];
}

