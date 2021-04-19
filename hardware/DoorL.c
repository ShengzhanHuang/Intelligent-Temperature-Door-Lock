#include <stdio.h>
#include <string.h>
#include <mysql.h>
#define BOOL int
#define TRUE 1
#define FALSE 0
int main()
{
//1、连接服务器
    MYSQL mysql;
    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql,"192.168.31.70","root","","door_lock_system",3306,NULL,0))
    {
        fprintf(stderr, "Failed to connect to database: Error: %s\n",
                mysql_error(&mysql));
    }
    mysql_query(&mysql, "set names utf8"); //设置编码
BOOL check = FALSE;
BOOL True = TRUE;
//	char check ="0";
//	char True ="1";
    //查
    char sql[300] = "SELECT status FROM user";
   //strcpy(sql, "SELECT status FROM User");
    if(mysql_query(&mysql, sql))//查询
    {
        fprintf(stderr, "Failed to select: Error: %s\n",
                mysql_error(&mysql));
    }
    else
    {
        MYSQL_RES* res = NULL;//从堆区申请空间保存一行查询内容

        res = mysql_store_result(&mysql);


        if (check==True)
        {
            printf("Temperature is normal! Open the door");
        }

         else
        {
            printf("Temperature is abnormal! Warning!");
        }

    }
//3、关闭
    mysql_close(&mysql);
    return 0;
}
