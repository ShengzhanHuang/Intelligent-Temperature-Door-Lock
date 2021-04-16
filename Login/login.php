<?php

include('../connnect.php');
mysql_query($conn,"set names utf8");
$Username = $_GET['Username'];
$password = $_GET['password'];

$check = mysql_query($conn,"select Username from User where Username='$Username' and password = '$password' limit 1");

$result = mysql_frech_array($check);

if($result)
{
    echo 'success! Click to jump <a href ="file:///F:/VS%20HTML/Main/main.html?username=$Username">Main</a>';
}
else
{
    echo 'failed! Wrong user name or password! Click to return <a href = "javascript:history.back(-1);">Return</a>';
}

?>