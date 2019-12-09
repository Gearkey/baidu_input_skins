main()
{
int back;
int n;
int i;
int x,xs;
int xx,xxs;
int key,y,ys;
int h,hs;
int w[20],ws[20];
int jg;
int fz;
printf("-皮肤工具1.0-[半自动式]\n");
printf("输入[起始Key]");
scanf("%d",&key);
printf("输入按键[默认背景样式]");
scanf("%d",&back);
printf("输入此行[按键总数]");
scanf("%d",&n);
printf("输入[显示x及实际xs]");
scanf("%d%d",&x,&xs);
xx=x;
xxs=xs;
printf("输入[显示y及实际ys]");
scanf("%d%d",&y,&ys);
printf("输入[显示h及实际hs]");
scanf("%d%d",&h,&hs);
printf("输入每个按键[显示宽度w]");
for(i=0;i<n;i++)
{
scanf("%d",&w[i]);
}
printf("输入按键[显示间隔]");
scanf("%d",&jg);
printf("输入每个按键[实际宽度ws]");
for(i=0;i<n;i++)
{
scanf("%d",&ws[i]);
}
do
{
for(i=0;i<n;i++)
{
printf("\n[KEY%d]\nBACK_STYLE=%d\nFORE_STYLE=\n",key,back);
printf("VIEW_RECT=%d,%d,%d,%d\n",x,y,w[i],h);
printf("TOUCH_RECT=%d,%d,%d,%d\n",xs,ys,ws[i],hs);
printf("CENTER=\n");
key++;
x=x+w[i]+jg;
xs=xs+ws[i];
}
printf("-输入1复制一份作为下一行-\n");
scanf("%d",&fz);
x=xx;
xs=xxs;
y=y+h+jg;
ys=ys+hs;
printf("输入对于h及hs的调整：");
scanf("%d%d",&h,&hs);
}
while(fz=1);
}
