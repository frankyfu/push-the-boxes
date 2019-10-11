#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//█ ☆ ★ √♀0:地面      1： █  3： ☆  4： ★   5： ♀ 7：  √  8： ♀
int map[8][8]=
{
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 3, 3, 1, 1, 1,
	1, 1, 1, 0, 3, 1, 1, 1,
	1, 1, 0, 0, 4, 3, 1, 1,
	1, 1, 0, 4, 0, 0, 1, 1,
	1, 0, 0, 1, 4, 4, 0, 1,
	1, 0, 0, 5, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1
};



void drawmap()//显示地图 
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			switch(map[i][j])
			{
			case 0:
				printf("  ");
			    break;
		    case 1:
		    	printf("█");
			    break;
			case 3:
				printf("☆");
			    break;
			case 4:
				printf("★");
			    break;
		    case 5:
		    	printf("♀");
			    break;
			case 7:
				printf("√");
			    break;
			case 8:
			    printf("♀");
			    break;
		    }
		}
		printf("\n");
    }
}

void control()//控制功能
{
	//确定人的位置
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(map[i][j]==5||map[i][j]==8)
		    break;
		}
		if(map[i][j]==5||map[i][j]==8)
		    break;//一个break只能跳出一个for循环，所以用两个break跳出两个循环 
	}
	//移动
	char ch=_getch();//不可见输入
	switch(ch)
	{
		//几个控制的ascll值   上72    下80    左75     右77
		case 'W':
		case 'w':
		case 72: 
		    {
			//能走的地方
			if(map[i-1][j]==0||map[i-1][j]==3) //不推箱子 
			{
				//交换两个数的位置
				map[i][j]=map[i][j]-5;
				map[i-1][j]=map[i-1][j]+5;			 
			}
		    else if(map[i-1][j]==4||map[i-1][j]==7) //推箱子 
		    {
		    	//箱子上面是否是空地或目的地 
		    	if(map[i-2][j]==0||map[i-2][j]==3)
		    	{
		    		map[i-2][j]+=4;
					map[i-1][j]+=1;
					map[i][j]-=5;
				} 
			}
	        break;
	        }
	    case 'S':
		case 's':
		case  80: 
		    if(map[i+1][j]==0||map[i+1][j]==3) 
			{
				map[i][j]=map[i][j]-5;
				map[i+1][j]=map[i+1][j]+5;			 
			}
		    else if(map[i+1][j]==4||map[i+1][j]==7)  
		    {
		    	if(map[i+2][j]==0||map[i+2][j]==3)
		    	{
		    		map[i+2][j]+=4;
					map[i+1][j]+=1;
					map[i][j]-=5;
				} 
			}
	        break;
	    case 'A':
		case 'a':
		case 75: 
		    if(map[i][j-1]==0||map[i][j-1]==3) 
			{
				map[i][j]=map[i][j]-5;
				map[i][j-1]=map[i][j-1]+5;			 
			}
		    else if(map[i][j-1]==4||map[i][j-1]==7)  
		    {
		    	if(map[i][j-2]==0||map[i][j-2]==3)
		    	{
		    		map[i][j-2]+=4;
					map[i][j-1]+=1;
					map[i][j]-=5;
				} 
			}
	        break;
	    case 'D':
		case 'd':
		case  77: 
		    if(map[i][j+1]==0||map[i][j+1]==3) 
			{
				map[i][j]=map[i][j]-5;
				map[i][j+1]=map[i][j+1]+5;			 
			}
		    else if(map[i][j+1]==4||map[i][j+1]==7)  
		    {
		    	if(map[i][j+2]==0||map[i][j+2]==3)
		    	{
		    		map[i][j+2]+=4;
					map[i][j+1]+=1;
					map[i][j]-=5;
				} 
			}
	        break;
	 } 
}

int c=0;

int judge()//判断游戏是否结束
{
	int i,j;
	int x=0;
	for(i=0;i<8;i++)//统计剩余箱子的数量 x 
	{
		for(j=0;j<8;j++)
		{
			if(map[i][j]==4)
			{
				x=x+1;
			}
		}
	}
	if(x==0)
	{
		system("cls");
		printf("you win!");
		c=1;
		printf("\ninput any key to continue");
		scanf("%d");
		system("cls") ;
	}
	else
	{
		system("cls");
	}
 } 

int map2[7][7]=
{
	1, 1, 1, 1, 1, 1, 1,
	1, 3, 0, 3, 0, 3, 1,
	1, 0, 4, 4, 4, 0, 1,
	1, 3, 4, 5, 4, 3, 1,
	1, 0, 4, 4, 4, 0, 1,
	1, 3, 0, 3, 0, 3, 1,
	1, 1, 1, 1, 1, 1, 1,
};

void drawmap2()//显示地图 2
{
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			switch(map2[i][j])
			{
			case 0:
				printf("  ");
			    break;
		    case 1:
		    	printf("█");
			    break;
			case 3:
				printf("☆");
			    break;
			case 4:
				printf("★");
			    break;
		    case 5:
		    	printf("♀");
			    break;
			case 7:
				printf("√");
			    break;
			case 8:
			    printf("♀");
			    break;
		    }
		}
		printf("\n");
    }
}

void control2()//控制功能
{
	//确定人的位置
	int i,j;
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if(map2[i][j]==5||map2[i][j]==8)
		    break;
		}
		if(map2[i][j]==5||map2[i][j]==8)
		    break;//一个break只能跳出一个for循环，所以用两个break跳出两个循环 
	}
	//移动
	char ch=_getch();//不可见输入
	switch(ch)
	{
		//几个控制的ascll值   上72    下80    左75     右77
		case 'W':
		case 'w':
		case 72: 
		    {
			//能走的地方
			if(map2[i-1][j]==0||map2[i-1][j]==3) //不推箱子 
			{
				//交换两个数的位置
				map2[i][j]=map2[i][j]-5;
				map2[i-1][j]=map2[i-1][j]+5;			 
			}
		    else if(map2[i-1][j]==4||map2[i-1][j]==7) //推箱子 
		    {
		    	//箱子上面是否是空地或目的地 
		    	if(map2[i-2][j]==0||map2[i-2][j]==3)
		    	{
		    		map2[i-2][j]+=4;
					map2[i-1][j]+=1;
					map2[i][j]-=5;
				} 
			}
	        break;
	        }
	    case 'S':
		case 's':
		case  80: 
		    if(map2[i+1][j]==0||map2[i+1][j]==3) 
			{
				map2[i][j]=map2[i][j]-5;
				map2[i+1][j]=map2[i+1][j]+5;			 
			}
		    else if(map2[i+1][j]==4||map2[i+1][j]==7)  
		    {
		    	if(map2[i+2][j]==0||map2[i+2][j]==3)
		    	{
		    		map2[i+2][j]+=4;
					map2[i+1][j]+=1;
					map2[i][j]-=5;
				} 
			}
	        break;
	    case 'A':
		case 'a':
		case 75: 
		    if(map2[i][j-1]==0||map2[i][j-1]==3) 
			{
				map2[i][j]=map2[i][j]-5;
				map2[i][j-1]=map2[i][j-1]+5;			 
			}
		    else if(map2[i][j-1]==4||map2[i][j-1]==7)  
		    {
		    	if(map2[i][j-2]==0||map2[i][j-2]==3)
		    	{
		    		map2[i][j-2]+=4;
					map2[i][j-1]+=1;
					map2[i][j]-=5;
				} 
			}
	        break;
	    case 'D':
		case 'd':
		case  77: 
		    if(map2[i][j+1]==0||map2[i][j+1]==3) 
			{
				map2[i][j]=map2[i][j]-5;
				map2[i][j+1]=map2[i][j+1]+5;			 
			}
		    else if(map2[i][j+1]==4||map2[i][j+1]==7)  
		    {
		    	if(map2[i][j+2]==0||map2[i][j+2]==3)
		    	{
		    		map2[i][j+2]+=4;
					map2[i][j+1]+=1;
					map2[i][j]-=5;
				} 
			}
	        break;
	 } 
}

int judge2()//判断游戏是否结束
{
	int i,j;
	int x=0;
	for(i=0;i<8;i++)//统计剩余箱子的数量 x 
	{
		for(j=0;j<8;j++)
		{
			if(map2[i][j]==4)
			{
				x=x+1;
			}
		}
	}
	if(x==0)
	{
		system("cls");
		printf("you win!");
		c=1;
		printf("\ninput any key to continue");
		scanf("%d");
		system("cls") ;
	}
	else
	{
		system("cls");
	}
 }

int main()
{
	int level;
	printf("which level do u want to play\n1.easy\n2.hard\n3.back to windows\n");
	scanf("%d",&level);
	system("cls");
	if(level==1)
	{
	    while(c==0)
	    {
	        drawmap();
	        control();
	        judge();
	    } 
	    c=0;
	    main ();
    }
    else if(level==2)
    {
    	while(c==0) 
    	{
    		drawmap2();
    		control2();
    		judge2();
		}
	    c=0;
	    main ();
	}
	else if(level==3)
	{
		;
	}
	else
	{
		printf("input error!");
		printf("\ninput any key to continue");
		scanf("%s");
		system("cls");
		main();
	}
}
	



