#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

vector <pair<int, int>> order;	//<���۽ð�, �����½ð�>
priority_queue <int, vector<int>, greater<int>> pq;	//�� ���ǰ� ������ �ð�

int main()
{
	int n;
	int s, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s, &t);
		order.push_back(make_pair(s, t));
	}
	sort(order.begin(), order.end());	//�迭 ���� ���� ����
	pq.push(order[0].second);			//pq�� ù��° �����½ð� �־���
	int ans = 1;					//ù ���Ǵ� ������ ���ǽ� �ʿ��ϱ� ����	
	for (int i = 1; i < order.size(); i++) {
		if (order[i].first >= pq.top()) {	//���� ���ǽ� ��밡���ϸ�
			pq.pop();
			pq.push(order[i].second);		//pq�� ������Ʈ
		}
		else {						//���ο� ���ǽ� �ʿ��ϸ�
			pq.push(order[i].second);	//pq�� ���ο� ���� ������ �ð� �־���
			ans++;		//���ǽ� �ϳ� �߰������Ƿ� ans++
		}
	}
	printf("%d\n", ans);
	return 0;
}