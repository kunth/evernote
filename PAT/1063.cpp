//Date : 
//Author : fibonacci
//Note: http://pat.zju.edu.cn/contests/pat-a-practise/1063
//Accepted

#include<cstdio>
#include<algorithm>
using namespace std;

int num[51][10001];

int main()
{
    int N, M, K, A, B;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
    {
        scanf("%d", &M);
        for(int j=1; j<=M; ++j)
            scanf("%d", &num[i][j]);
        num[i][0] = M;
    }
    scanf("%d", &K);

    for(int i = 0; i<K;++i)
    {
        scanf("%d %d", &A, &B);
        sort(num[A]+1, num[A] + 1 + num[A][0]);
        sort(num[B]+1, num[B] + 1 + num[B][0]);
        int pa=1, pb=1, cnt=0, sum=0;
        while(pa<=num[A][0] && pb<=num[B][0])
        {
            if(num[A][pa] < num[B][pb])
            {
                ++pa;
            }
            else if(num[A][pa] > num[B][pb])
            {
                ++pb;
            }
            else
            {
                ++pa;
                ++pb;
                ++cnt;
            }
            ++sum;
            while(pa > 1 && num[A][pa] == num[A][pa-1])
                ++pa;
            while(pb > 1 && num[B][pb] == num[B][pb-1])
                ++pb;
        }
        if(num[A][num[A][0]] != num[B][num[B][0]])
            ++sum;
        printf("%.1f%%\n", 100*(float)cnt/sum);
    }
    return 0;
}

//下面用set的代码有一个case超时
//个人感觉用set比上面的代码中用快排然后两个指针比较要在逻辑上简单许多
#include<cstdio>
#include<set>
using namespace std;

int num[51][10001];

int main()
{
    int N, M, K, A, B;
    //freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
    {
        scanf("%d", &M);
        for(int j=1; j<=M; ++j)
            scanf("%d", &num[i][j]);
        num[i][0] = M;
    }
    scanf("%d", &K);
    set<int> setA, setB;
    for(int i = 0; i<K;++i)
    {
        scanf("%d %d", &A, &B);
        setA.clear();
        setB.clear();
        for(int j = 1; j<=num[A][0]; ++j)
            setA.insert(num[A][j]);
        for(int j = 1; j<=num[B][0]; ++j)
            setB.insert(num[B][j]);
        int cnt = 0;
        for(set<int>::iterator outiter = setA.begin(); outiter!=setA.end(); ++outiter)
        {
            for(set<int>::iterator inniter = setB.begin(); inniter!=setB.end(); ++inniter)
            {
                if(*outiter == *inniter)
                {
                    ++cnt;
                    break;
                }
            }
        }
        printf("%.1f%%\n", 100*(float)cnt/(int)(setA.size()+setB.size()-cnt));
    }
    return 0;
}
