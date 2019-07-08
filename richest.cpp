/*
 * description:
 * APPAPT 字符串有两个PAT, 2-》4-》6 3-》4-》6
 */
#include<cstring>
#include<algorithm>
#include <cstdio>

const int MAXN=100010;
char str[MAXN];


int solution1()
{
    gets(str);
    int len = strlen(str);
    int leftNum[MAXN] = {0};
    int rightNum[MAXN] = {0};
    bool a[MAXN] = {false};
    for(int i=0;i<len;i++)
    {
        if(str[i]=='P'){
            for(int j=i+1;j<len;j++)
                leftNum[j] ++;
        }
        if (str[i] == 'A'){
            a[i] = true;
        }
        if (str[i] == 'T'){
            for(int j=i-1;j>0;j++)
                rightNum[j] ++ ;
        }
    }
    int num = 0;
    for(int i=0;i<len;i++){
        if(a[i]){
            num += leftNum[i]*rightNum[i];
        }
    }
    return num;
}

int solution2(){
    gets(str);
    int leftNum[MAXN] = {0};
    int rightNum = 0;
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        if(i>0){
            leftNum[i] = leftNum[i-1];
        }
        if(str[i]=='P')
        {
            leftNum[i] ++;
        }
    }

    int ans=0, rightNumT=0;
    for(int i=len-1;i>=0;i--)
    {
        if(str[i]=='T'){
            rightNumT ++;
        }
        else if(str[i]=='A'){
            ans = ans + leftNum[i]* rightNumT;
        }
    }
    printf("%d/n", ans);
    return 0;
}
