#include <stdio.h>
#include <string.h>
#include "mysql.h"
int main()
{
    MYSQL ceshi;
    mysql_init(&ceshi);   //��ʼ��MYSQL����

    bool check;

    if (mysql_real_connect(&ceshi, "192.168.31.70", "root", "", "door_lock_system", 3306, NULL, 0))  //���ӵ�mysql
    {
        cout << "\n\t-----MySql is connected----" << endl;
    }

    if (!mysql_query(&ceshi, "SELECT status FROM User"))   //����ѯ�ɹ�����0��ʧ�ܷ��������
    {
        cout << "\n\t  ----Search successful----" << endl;
    }
    check = mysql_store_result(&ceshi);    //����ѯ���Ľ�������浽check��

    if (check == True)
    {
        printf("Temperature is normal! Open the door");
    }

    else
    {
        printf("Temperature is abnormal! Warning!");
    }


    mysql_free_result(result);     //�ͷŽ������ռ�õ��ڴ�
    mysql_close(&ceshi);          //�ر���mysql������

}