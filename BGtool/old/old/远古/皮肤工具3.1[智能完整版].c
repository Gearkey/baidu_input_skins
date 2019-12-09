main()
{
int i;
int ms,sf;
int wm,wms;
int han=1,hans=1;
int key=1,back;
int xjg,yjg;
int h,hs;
int keys;
int num;
int more;
int cc,ccs,cw,cws,cckeys,ccc=0;
int x=0,y=0,xs=0,ys=0;
int xx=0,xxs=0;
int xbj=0,xsbj=0;
int w[20],ws[20],wn,wsn;
printf("-皮肤工具3.0-[智能4完整版]\n");
printf("1>轻量级|2>标准型|3>进阶型\n6>单行制作|7>单行进阶|8>单列制作\n选择：");
scanf("%d",&ms);
switch (ms)
{
case 1:{
printf("面板>[总宽]:");
scanf("%d",&wm);
printf("默认>[背景样式]:");
scanf("%d",&back);
printf("面板>[总行数]:");
scanf("%d",&hans);
wms=wm;
printf("按键>[间隔]:");
scanf("%d",&xjg);
yjg=xjg;
break;
}
case 2:{
printf("面板>[总宽]:");
scanf("%d",&wm);
printf("按键>[背景样式]:");
scanf("%d",&back);
printf("面板>[总行数]:");
scanf("%d",&hans);
printf("按键>[左边距]:");
scanf("%d",&x);
printf("按键>[右边距]:");
scanf("%d",&xbj);
wm=wm-x-xbj;
wms=wm;
xx=x;
xs=x;
xxs=x;
xsbj=xbj;
printf("按键>[上边距]:");
scanf("%d",&y);
ys=y;
printf("按键>[横向间隔]:");
scanf("%d",&xjg);
printf("按键>[纵向间隔]:");
scanf("%d",&yjg);
break;
}
case 3:{
printf("面板>[总宽]:");
scanf("%d",&wm);
printf("按键>[背景样式]:");
scanf("%d",&back);
printf("面板>[总行数]:");
scanf("%d",&hans);
printf("按键>显示>[左边距]:");
scanf("%d",&x);
printf("按键>实际>[左边距]:");
scanf("%d",&xs);
printf("按键>显示>[右边距]:");
scanf("%d",&xbj);
printf("按键>实际>[右边距]:");
scanf("%d",&xsbj);
wm=wm-x-xbj;
xx=x;
wms=wm-xs-xsbj;
xxs=xs;
printf("按键>显示>[上边距]:");
scanf("%d%d",&y,&ys);
printf("按键>实际>[上边距]:");
scanf("%d%d",&y,&ys);
printf("按键>[横向间隔]:");
scanf("%d",&xjg);
printf("按键>[纵向间隔]:");
scanf("%d",&yjg);
break;
}
case 6:{
printf("bar>[总宽]:");
scanf("%d",&wm);
wms=wm;
printf("按键>[背景样式]:");
scanf("%d",&back);
printf("按键>[起始序号]:");
scanf("%d",&key);
printf("按键>[起始x]:");
scanf("%d",&x);
xx=x;
xs=x;
printf("按键>[起始y]:");
scanf("%d",&y);
ys=y;
printf("按键>[显示间隔]:");
scanf("%d",&xjg);
yjg=xjg;
break;
}
case 7:{
printf("bar>[总宽]:");
scanf("%d",&wm);
wms=wm;
printf("按键>[背景样式]:");
scanf("%d",&back);
printf("按键>[起始序号]:");
scanf("%d",&key);
printf("按键>[起始x]:");
scanf("%d",&x);
printf("按键>[起始xs]:");
scanf("%d%d",&xs);
xx=x;
xxs=xs;
printf("按键>[起始y]:");
scanf("%d",&y);
printf("按键>[起始ys]:");
scanf("%d",&ys);
printf("按键>[显示间隔]:");
scanf("%d",&xjg);
yjg=xjg;
break;
}
case 8:{
break;
}
default:{
printf("输入错误！请退出");
break;
}
}
/*开始行的大循环*/
for (han=1;han<=hans;han++)
{
if(ms<=5){
printf("第%d行>>\n",han);
}
printf("此行按键>显示>[高度]:");
scanf("%d",&h);
printf("此行按键>实际>[高度]:");
scanf("%d",&hs);
printf("此行按键>[总数]:");
scanf("%d",&keys);
printf("1>平均值法|2>输入算法\n选择:");
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
printf("按键>平均无法为整数！需要闰%d个像素！\n显示>[需要闰的按键号]:",more);
}
for (i=0;i<more;i++)
{
scanf("%d",&num);
w[num-1]=w[num-1]+1;
}
/*计算ws由此开始*/
wsn=wms/keys;
for (i=0;i<keys;i++)
{
	ws[i]=wsn;
}
wsn=0;
for (i=0;i<keys;i++)
{
	wsn=wsn+ws[i];
}
more=wms-wsn;
if (more!=0)
{
printf("按键>平均无法为整数！需要闰%d个像素！\n实际>[需要闰的按键号]:",more);
}
for (i=0;i<more;i++)
{
scanf("%d",&num);
ws[num-1]=ws[num-1]+1;
}
break;
}
case 2:{
printf("总共>[层次数]:");
scanf("%d",&ccs);
for (cc=1;cc<=ccs;cc++)
{
printf("第%d层次>[按键个数]:",cc);
scanf("%d",&cckeys);
printf("显示>[按键宽度]:");
scanf("%d",&cw);
printf("实际>[按键宽度]:");
scanf("%d",&cws);
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
}
/*以下输出结果*/
for(i=0;i<keys;i++)
{
printf("\n[KEY%d]\n",key);
printf("VIEW_RECT=%d,%d,%d,%d\n",x,y,w[i],h);
printf("TOUCH_RECT=%d,%d,%d,%d\n",xs,ys,ws[i],hs);
printf("BACK_STYLE=%d\nFORE_STYLE=\n",back);
printf("UP=\nDOWN=\n");
/*printf("LEFT=\nRIGHT=\n");*/
printf("CENTER=\n");
key++;
x=x+w[i]+xjg;
xs=xs+ws[i];
}
x=xx;
xs=xxs;
y=y+h+yjg;
ys=ys+hs;
ccc=0;
}
}/*by百度贴吧@齿轮Key*/
