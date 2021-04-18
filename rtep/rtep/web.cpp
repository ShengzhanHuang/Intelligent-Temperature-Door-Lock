#include <stdio.h>
#include <string.h>
#include "mysql.h"
int main()
{
    MYSQL ceshi;
    mysql_init(&ceshi);   //初始化MYSQL变量

    bool check;

    if (mysql_real_connect(&ceshi, "192.168.31.70", "root", "", "door_lock_system", 3306, NULL, 0))  //连接到mysql
    {
        cout << "\n\t-----MySql is connected----" << endl;
    }

    if (!mysql_query(&ceshi, "SELECT status FROM User"))   //若查询成功返回0，失败返回随机数
    {
        cout << "\n\t  ----Search successful----" << endl;
    }
    check = mysql_store_result(&ceshi);    //将查询到的结果集储存到check中

    if (check == True)
    {
        printf("Temperature is normal! Open the door");
    }

    else
    {
        printf("Temperature is abnormal! Warning!");
    }


    mysql_free_result(result);     //释放结果集所占用的内存
    mysql_close(&ceshi);          //关闭与mysql的连接

}