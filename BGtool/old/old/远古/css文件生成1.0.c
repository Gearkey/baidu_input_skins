main()
{
int i,n;
int style,qp;
char bz[10];
char til[10];
printf("css文件生成1.0\n");
printf("素材>[总数]:");
scanf("%d",&n);
printf("切片>[文件名]:");
scanf("%s",&til);
printf("起始>[样式序号]:");
scanf("%d",&style);
printf("起始>[切片序号]:");
scanf("%d",&qp);
for(i=0;i<n;i++)
{
printf("\n[STYLE%d]\n",style+i);
printf("NM_IMG=%s,%d\n",til,i+qp);
printf("HL_IMG=%s,%d\n",til,i+qp);
}
}/*by百度贴吧@齿轮key*/
