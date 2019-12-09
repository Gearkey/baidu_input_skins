main()
{
int i;
int wm,hm;
int han,hans;
int key=1,back;
int xjg,yjg;
int h,hs;
int keys;
int sf;
int num;
int more;
int cc,ccs,cw,cws,cckeys,ccc=0;
int x,y,xs,ys;
int xx;
int xbj,ybj;
int w[20],ws[20],wn,wsn;
printf("-皮肤工具3.0-[智能完整版]\n");
printf("输入面板[总宽wm及总高hm]");
scanf("%d%d",&wm,&hm);
printf("输入按键[默认背景样式]");
scanf("%d",&back);
printf("输入面板[总行数]");
scanf("%d",&hans);
printf("输入按键[左右边距]");
scanf("%d%d",&x,&xbj);
wm=wm-x-xbj;
xx=x;
xs=x;
printf("输入按键[上边距]");
scanf("%d",&y);
ys=y;
printf("输入按键显示[横向间隔]");
scanf("%d",&xjg);
printf("输入按键显示[纵向间隔]");
scanf("%d",&yjg);
/*开始行的大循环*/
for (han=1;han<=hans;han++)
{
printf("-第%d行-\n",han);
printf("输入此行按键[显示h及实际hs]");
scanf("%d%d",&h,&hs);
printf("输入此行[按键个数]");
scanf("%d",&keys);
printf("1>平均值法|2>输入算法\n[请选择]");
scanf("%d",&sf);
switch(sf)
{
case 1:{
/*计算w由此开始*/
wn=(wm-(xjg*(keys-1)))/keys;
for (i=0;i<keys;i++)
{
	w[i]=wn;
}
wn=0;
for (i=0;i<keys;i++)
{
	wn=wn+w[i];
}
wn=xjg*(keys-1)+wn;
more=wm-wn;
if (more!=0)
{
printf("按键显示平均无法为整数！需要闰%d个像素！输入[需要闰的按键号]",more);
}
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
if (more!=0)
{
printf("按键实际平均无法为整数！需要闰%d个像素！输入[需要闰的按键号]",more);
}
for (i=0;i<more;i++)
{
scanf("%d",&num);
ws[num-1]=ws[num-1]+1;
}
break;
}
case 2:{
printf("输入总共的[层次数]");
scanf("%d",&ccs);
for (cc=1;cc<=ccs;cc++)
{
printf("输入第%d层次按键个数",cc);
scanf("%d",&cckeys);
printf("输入第%d层次的按键[显示及实际宽度]",cc);
scanf("%d%d",&cw,&cws);
for (i=0;i<cckeys;i++)
{
	i=i+ccc;
	w[i]=cw;
	ws[i]=cws;
	i=i-ccc;
}
ccc=ccc+cckeys;
}
break;
}
}/*switch的*/
/*以下输出结果*/
for(i=0;i<keys;i++)
{
printf("\n[KEY%d]\nBACK_STYLE=%d\nFORE_STYLE=\n",key,back);
printf("VIEW_RECT=%d,%d,%d,%d\n",x,y,w[i],h);
printf("TOUCH_RECT=%d,%d,%d,%d\n",xs,ys,ws[i],hs);
printf("UP=\nDOWN=\n");
/*printf("LEFT=\nRIGHT=\n");*/
printf("CENTER=\n");
key++;
x=x+w[i]+xjg;
xs=xs+ws[i];
}
x=xx;
xs=xx;
y=y+h+yjg;
ys=ys+hs;
ccc=0;
}
}
