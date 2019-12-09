#include<stdio.h>
main()
{
int i,wn;
int wm,jg,keys,more;
printf("总宽:");
scanf("%d",&wm);
printf("间隔:");
scanf("%d",&jg);
printf("按键总数:");
scanf("%d",&keys);
/*计算w由此开始*/
wn=(wm-(jg*(keys-1)))/keys;
//不算小数部分的按键标准值=(总宽-总间隔)/按键总数
printf("标准值为:%d\n",wn);
//加起总的标准宽度
wn=jg*(keys-1)+wn*keys;
//间隔也算上
more=wm-wn;
//空闲的像素个数
printf("计算得出需要闰%d个像素\n\n",more);
printf("顺序运算结果:");
for (i=0;i<more;i++)
{
printf("%d ",i+1);
}
}/*百度贴吧 @齿轮Key*/