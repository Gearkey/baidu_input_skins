#include<stdio.h>
main()
{
int i;
int width,height;//总宽，高
int size;//字体大小
int more;//溢出调节值
int n;
int x=0,y,ys;//til的x，高
int num;
int style;//css
char zw[10]="占";
char font[10],color[10];
char names[50][50];
char til[50],bz[50];//备注
printf("-素材制作3.0-[智能5完整]\n");
printf("字体>[文件名]:");
scanf("%s",&font);
printf("字体>[颜色]：#");
scanf("%s",&color);
printf("素材>[总宽度]:");
scanf("%d",&width);
printf("素材>[起始高度]:");
scanf("%d",&ys);
printf("字体>大小>[单元格高度]:");
scanf("%d",&size);
printf("字体>溢出调节值>[单元格上下边距]:");
scanf("%d",&more);
printf("素材>[切片个数]:");
scanf("%d",&n);
height=size*n+2*more*n;
printf("css>[起始样式]:");
scanf("%d",&style);
printf("css>[素材文件名]:");
scanf("%s",&til);
/*printf("css>[是否需要备注]");
scanf("%d",&bzxz);
*/
if (num<5){/*为避免多余的抉择，如果无需备注，将数字改为1即可*/
printf("css>[备注文本]:");
scanf("%s",&bz);
}
printf("1>输入并精确生成|6>快速生成空模板\n7>快速占位|8>快速数字占位\n选择：");
scanf("%d",&num);
if (num==1)
{
for (i=0;i<n;i++)
{
printf("输入>[第%d个素材]:",i+1);
scanf("%s",&names[i]);
}
}
/*printf("---\n源码文件>>\n\n");*/
printf("文件>已生成>[前往程序目录查收]");
freopen("1.xml","w",stdout);
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
printf("   <text align=\"center\" x=\"0.0\" y=\"%d\.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%s\" color=\"\#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,names[i],color);
}
break;
}
case 6:{
for (i=0;i<n;i++)
{
y=size*i+size-(size+3)/7+more+2*more*i+ys;
printf("   <text align=\"center\" x=\"0.0\" y=\"%d\.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"\" color=\"\#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,color);
}
break;
}
case 7:{
for (i=0;i<n;i++)
{
y=size*i+size-(size+3)/7+more+2*more*i+ys;
printf("   <text align=\"center\" x=\"0.0\" y=\"%d\.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%s\" color=\"\#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,zw,color);
}
break;
}
case 8:{
for (i=0;i<n;i++)
{
y=size*i+size-(size+3)/7+more+2*more*i+ys;
printf("   <text align=\"center\" x=\"0.0\" y=\"%d\.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%d\" color=\"\#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,i+1,color);
}
break;
}
}
printf("</style>");
fclose(stdout);
/*printf("---\n切片文件>>\n\n");*/
freopen("2.til","w",stdout);
if(ys==0){
printf("[GLOBAL]\n");
printf("USE_ALPHA=1\n");
printf("TILE_NUM=%d\n",n);
}
for (i=0;i<n;i++)
{
y=(size+2*more)*i+ys;
printf("\n[IMG%d]\n",ys/(size+more*2)+i+1);
printf("SOURCE_RECT=%d,%d,%d,%d\n",x,y,width,size+2*more);
}
fclose(stdout);
/*printf("\n---\ncss配置文件>>\n");*/
freopen("3.css","w",stdout);
for(i=0;i<n;i++)
{
switch(num)
{
case 1:{
printf("[STYLE%d]%s-%s\n",style+i,bz,names[i]);
break;
}
case 6:
case 7:
case 8:{
printf("[STYLE%d]\n",style+i);
break;
}
}
printf("NM_IMG=%s,%d\n",til,ys/(size+more*2)+i+1);
printf("HL_IMG=%s,%d\n\n",til,ys/(size+more*2)+i+1);
}
fclose(stdout);
}/*by百度贴吧@齿轮key*/
