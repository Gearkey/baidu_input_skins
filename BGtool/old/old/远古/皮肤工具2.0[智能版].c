main()
{
int i;
int wm,hm;
int han,hans;
int key=1,back;
int jg;
int h,hs;
int keys;
int num;
int more;
int x=0,y=0,xs=0,ys=0;
int w[20],ws[20],wn,wsn;
printf("-皮肤工具2.0-[智能版]\n");
printf("输入面板[总宽wm及总高hm]");
scanf("%d%d",&wm,&hm);
printf("输入按键[默认背景样式]");
scanf("%d",&back);
printf("输入面板[总行数]");
scanf("%d",&hans);
printf("输入按键[显示间隔]");
scanf("%d",&jg);

for (han=1;han<=hans;han++)
{
printf("-第%d行-\n",han);
printf("输入此行按键[显示h及实际hs]");
scanf("%d%d",&h,&hs);
printf("输入此行[按键个数]");
scanf("%d",&keys);
/*计算w由此开始*/
wn=(wm-(jg*(keys-1)))/keys;
for (i=0;i<keys;i++)
{
	w[i]=wn;
}
wn=0;
for (i=0;i<keys;i++)
{
	wn=wn+w[i];
}
wn=jg*(keys-1)+wn;
more=wm-wn;
printf("按键显示平均无法为整数！需要闰%d个像素！输入[需要闰的按键号]",more);
for (i=0;i<more;i++)
{
scanf("%d",&num);
w[num-1]=w[num-1]+1;
}
/*计算ws由此开始*/
wsn=wm/keys;
for (i=0;i<keys;i++)
{
	ws[i]=wsn;
}
wsn=0;
for (i=0;i<keys;i++)
{
	wsn=wsn+ws[i];
}
more=wm-wsn;
printf("按键实际平均无法为整数！需要闰%d个像素！输入[需要闰的按键号]",more);
for (i=0;i<more;i++)
{
scanf("%d",&num);
ws[num-1]=ws[num-1]+1;
}
/*以下输出结果*/
for(i=0;i<keys;i++)
{
printf("\n[KEY%d]\nBACK_STYLE=%d\nFORE_STYLE=\n",key,back);
printf("VIEW_RECT=%d,%d,%d,%d\n",x,y,w[i],h);
printf("TOUCH_RECT=%d,%d,%d,%d\n",xs,ys,ws[i],hs);
/*printf("UP=\nDOWN=\nLEFT=\nRIGHT=\n");*/
printf("CENTER=\n");
key++;
x=x+w[i]+jg;
xs=xs+ws[i];
}
x=0;
xs=0;
y=y+h+jg;
ys=ys+hs;
}
}
