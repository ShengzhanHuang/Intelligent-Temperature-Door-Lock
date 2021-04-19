#include <stdio.h>
#include <string.h>
#include "mysql.h"
int main()
{
    MYSQL ceshi; 
    mysql_init(&ceshi);   //Initialize MYSQL variables

    bool check;
      
    if (mysql_real_connect(&ceshi, "192.168.31.70", "root", "", "door_lock_system", 3306, NULL, 0))  //Connect to mysql
    {
        cout << "\n\t-----MySql is connected----" << endl;
    }
    
    if (!mysql_query(&ceshi, "SELECT status FROM User"))   //If the query succeeds, it returns 0, if it fails, it returns a random number
    {
        cout << "\n\t  ----Search successful----" << endl;
    }
    check = mysql_store_result(&ceshi);    //Store the query result set to check

    if (check==True)
    {
        printf("Temperature is normal! Open the door");
    }

    else
    {
        printf("Temperature is abnormal! Warning!");
    }
    
    
    mysql_free_result(result);     //Release the memory occupied by the result set
    mysql_close(&ceshi);          //Close the connection with mysql
    
}
