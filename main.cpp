/*
 
最长食物链
题目描述
 Andrew在做生物题。有一道题给出了一个食物网，要求写出其中最长的一条食物链。他告诉了你生物间的捕食关系，并请你计算答案。
输入格式
 若干行，每行两个正整数a和b，每个正整数对应一种生物，表示b捕食a。最后一行为0，表示结束。输入保证 1）每行a<b； 2）解唯一； 3）有序。
 注：有序是指 1）a被b和c捕食，且b小于c时，先输入“a b”再输入“a c"；2）a和b被c捕食，且a小于b时，先输入“a c”再输入“b c"；并且1）优先。
输出格式
 一行用空格隔开的正整数，表示最长的一条食物链。其中任意两个相邻的正整数代表的生物a和b遵循b捕食a。注意末尾没有多余空格。
输入样例1
 1 3
 1 4
 1 5
 1 6
 2 4
 2 6
 3 7
 4 7
 5 6
 6 7
 0
输出样例1
 1 5 6 7
 */
#include <iostream>
#define N 1001
using namespace std;
struct creature {
    int p[N];  //猎物数组
    int maxp;  //猎物中食物链最长的一个
    int l = 0;  //猎物数量
    int maxl = 0;  //最长的食物链长度
    bool top = 1;  //是否位于顶端
} c[N];  //生物结构体数组
int ans[N];  //存储答案数组
int main() {
    int n = 0, a, b, i, j, t = 0, k = 0;
    cin >> a;
    while(a != 0) {
        cin >> b;
        c[b].p[++c[b].l] = a;
        if(a > n)
            n = a;
        if(b > n)
            n = b;
        cin >> a;
    }
    for(i = 1; i <= n; i++) {
        if(c[i].l == 0)
            c[i].maxl = 0;
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= c[i].l; j++) {
            if(c[c[i].p[j]].maxl > c[i].maxl)
                c[i].maxl = c[c[i].p[j]].maxl;
        }
        for(j = 1; j <= c[i].l; j++) {
            if(c[c[i].p[j]].maxl == c[i].maxl)
                c[i].maxp = c[i].p[j];
        }
        c[i].maxl++;
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= c[i].l; j++)
            c[c[i].p[j]].top = 0;
    }
    for(i = 1; i <= n; i++) {
        if(c[i].top == 1)
            t = i;
    }
    ans[++k] = t;
    while(c[t].l != 0) {
        t = c[t].maxp;
        ans[++k] = t;
    }
    for(i = k; i >= 1; i--) {
        cout << ans[i];
        if(c[ans[i]].top == 0)
            cout << ' ';
    }
}
