<?php

//include('../connnect.php');
$conn = mysqli_connect('192.168.31.70','root','','door_lock_system');
mysqli_query($conn,"set names utf8");
$Username = $_GET['Username'];
$password = $_GET['password'];
//echo $Username;
//echo $password;
$check = mysqli_query($conn,"select Username from User where Username='$Username' and password = '$password' limit 1");
//echo 'bbbbbb';
$result = mysqli_fetch_array($check);

if($result)
{
//    echo 'success! Click to jump <a href ="../Main/main.html?username=$Username">Main</a>';
    header("location:../Main/main.html?username=$Username");
//$url = "http://localhost/Main/main.html?username=$Username";
//echo "</script> language='javascript'
//type ='text/javascript'>";
//echo "window.location.href='$url'";
//echo"</script>";
}
else
{
    echo 'failed! Wrong user name or password! Click to return <a href = "javascript:history.back(-1);">Return</a>';
}

?>