#include <stdio.h>

int max (int a, int b, int c)
{
    int ans = a;
    if (ans<b)
    {
        ans = b;
    }
    if (ans<c)
    {
        ans = c;
    }
    return ans;
}

int main()
{
    int a = 100;
    int b = 200;
    int c = 500;
    int ret;
    ret = max(a,b,c);
    printf("maximum is %d",ret);
    return 0;

}