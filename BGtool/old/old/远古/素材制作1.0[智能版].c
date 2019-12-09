main()
{
int i;
int width,height;
int size;
int more;
int n;
int y;
char font[10],color[10];
char names[50][50];
printf("-素材制作1.0-[完整测试]\n");
printf("输入[字体文件名]");
scanf("%s",&font);
printf("输入[字体颜色]：#");
scanf("%s",&color);
printf("输入整个图片[总宽度]");
scanf("%d",&width);
printf("输入字体大小[单元格高度]");
scanf("%d",&size);
printf("输入字体溢出调节值[单元格上下边距]");
scanf("%d",&more);
printf("输入所需的[素材个数]");
scanf("%d",&n);
height=size*n+2*more*n;
for (i=0;i<n;i++)
{
printf("输入[第%d个素材]",i+1);
scanf("%s",&names[i]);
}
printf("<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>\n");
printf("<style width=\"%d\" height=\"%d\">\n",width,height);
for (i=0;i<n;i++)
{
y=size*i+size-(size+3)/7+more+2*more*i;
printf("   <text align=\"center\" x=\"0.0\" y=\"%d\.0\" rotate=\"0\" size=\"%d\" font=\"%s\" text=\"%s\" color=\"\#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"97\" />\n",y,size,font,names[i],color);
}
printf("</style>");
}
