main()
{
int i;
int width,height;
int size;
int more;
int n;
int x=0,y,ys;
int num;
int style;
char zw[10]="占";
char font[10],color[10];
char names[50][50];
char til[50],bz[50];
printf("-素材制作2.0-[智能5完整]\n");
printf("输入[字体文件名]");
scanf("%s",&font);
printf("输入[字体颜色]：#");
scanf("%s",&color);
printf("输入整个图片[总宽度]");
scanf("%d",&width);
printf("输入字体大小[单元格高度]");
scanf("%d",&size);
printf("输入[起始高度]");
scanf("%d",&ys);
printf("输入字体溢出调节值[单元格上下边距]");
scanf("%d",&more);
printf("输入所需的[素材个数]");
scanf("%d",&n);
height=size*n+2*more*n;
printf("1>输入并精确生成|6>快速生成空模板\n7>快速占位|8>快速数字占位\n选择：");
scanf("%d",&num);
switch(num)
{
case 1:{
for (i=0;i<n;i++)
{
printf("输入[第%d个素材]",i+1);
scanf("%s",&names[i]);
}
break;
}
/*case 2:{
printf("输入示例素材的个数");
for (i=0;i<n;i++)
{
printf("输入示例的[素材序号]",i+1);
scanf("%s",&names[i]);
}
break;
}*/
case 6:
case 7:
case 8:{
break;
}
/*case 9:{
printf("输入[占位文本]");
scanf("%s",&zw);
for (i=0;i<n;i++)
{
names[i]=zw;
}
break;
}*/
}
printf("---\n-下面生成源码文件-\n\n");
if(ys==0){
printf("<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>\n");
printf("<style width=\"%d\" height=\"%d\">\n",width,height);
}
switch(num)
{
case 1:{
for (i=0;i<n;i++)
{
y=size*i+size-(size+3)/7+more+2*more*i+ys;
printf("   <text align=\"center\" x=\"0.0\" y=\"%d\.0\" rotate=\"0\" size=\"%d\" font=\"%s\" text=\"%s\" color=\"\#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,names[i],color);
}
break;
}
/*case 2:{
break;
}*/
case 6:{
for (i=0;i<n;i++)
{
y=size*i+size-(size+3)/7+more+2*more*i+ys;
printf("   <text align=\"center\" x=\"0.0\" y=\"%d\.0\" rotate=\"0\" size=\"%d\" font=\"%s\" text=\"\" color=\"\#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,color);
}
break;
}
case 7:
/*case 8:*/{
for (i=0;i<n;i++)
{
y=size*i+size-(size+3)/7+more+2*more*i+ys;
printf("   <text align=\"center\" x=\"0.0\" y=\"%d\.0\" rotate=\"0\" size=\"%d\" font=\"%s\" text=\"%s\" color=\"\#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,zw,color);
}
break;
}
case 8:{
for (i=0;i<n;i++)
{
y=size*i+size-(size+3)/7+more+2*more*i+ys;
printf("   <text align=\"center\" x=\"0.0\" y=\"%d\.0\" rotate=\"0\" size=\"%d\" font=\"%s\" text=\"%d\" color=\"\#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,i+1,color);
}
break;
}
}
printf("</style>\n\n");
printf("---\n-下面生成切片文件-\n\n");
if(ys==0){printf("[GLOBAL]\n");
printf("USE_ALPHA=1\n");
printf("TILE_NUM=%d\n",n);
}
for (i=0;i<n;i++)
{
y=(size+2*more)*i+ys;
printf("\n[IMG%d]\n",ys/(size+more*2)+i+1);
printf("SOURCE_RECT=%d,%d,%d,%d\n",x,y,width,size+2*more);
}
printf("\n---\n-下面生成css配置文件-\n");
printf("输入[起始样式序号]");
scanf("%d",&style);
printf("输入[切片文件名]");
scanf("%s",&til);
if (num<=5){
printf("输入[备注文本]");
scanf("%s",&bz);
}
for(i=0;i<n;i++)
{
switch(num)
{
case 1:{
printf("\n[STYLE%d]%s-%s\n",style+i,bz,names[i]);
break;
}
case 6:
case 7:
case 8:{
printf("\n[STYLE%d]\n",style+i);
break;
}
}
printf("NM_IMG=%s,%d\n",til,ys/(size+more*2)+i+1);
printf("HL_IMG=%s,%d\n",til,ys/(size+more*2)+i+1);
}
}/*by百度贴吧@齿轮key*/
