/************************************************************************/
/* 洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿着第n+1张到第2n张（下半堆）。接着就开始洗牌的过程，先放下右手的最后一张牌，再放下左手的最后一张牌，接着放下右手的倒数第二张牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。接着把牌合并起来就可以了。 例如有6张牌，最开始牌的序列是1,2,3,4,5,6。首先分成两组，左手拿着1,2,3；右手拿着4,5,6。在洗牌过程中按顺序放下了6,3,5,2,4,1。把这六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，就变成了序列1,4,2,5,3,6。 现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。 
输入描述:
第一行一个数T(T ≤ 100)，表示数据组数。对于每组数据，第一行两个数n,k(1 ≤ n,k ≤ 100)，接下来一行有2n个数a1,a2,...,a2n(1 ≤ ai ≤ 1000000000)。表示原始牌组从上到下的序列。


输出描述:
对于每组数据，输出一行，最终的序列。数字之间用空格隔开，不要在行末输出多余的空格。

输入例子1:
3
3 1
1 2 3 4 5 6
3 2
1 2 3 4 5 6
2 2
1 1 1 1

输出例子1:
1 4 2 5 3 6
1 5 4 3 2 6
*/
/************************************************************************/
//该程序可以实现一次性连续输入多个组，最后一次性把每个组洗牌结果输出 

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

	vector<vector<int> >outArray(T);//定义T行的二维数组，不同行可以不等长
	int t=0;
	while (T--)
	{
		cin>>n>>k;
		vector<int> cardArray(2*n);//一组牌
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

