<?php
$con= mysql_connect("192.168.31.70","root","");
if(!$con)
{
    die('database connection failed'.mysql_error());
}
else
{
    mysql_query("set names utf8");
    mysql_select_db("door_lock_system",$con);
    $oldpwd = $_GET['oldpwd'];
    $newpwd = $_GET['pwd1'];

    $check = mysql_query("update User set password='$newpwd' where password = '$oldpwd' limit 1");
    if(mysql_fetch_array($check))
    {
        echo "Password has been changed!";
    }
    else
    {
        echo "Password modification failed!";
    }
}

mysql_close($con);





?>