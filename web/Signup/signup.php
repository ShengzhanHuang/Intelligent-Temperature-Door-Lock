<?php

include('../connnect.php');
mysqli_query($conn,"set names utf8");
$Username = $_GET['username'];
$password = $_GET['pwd1'];
$exe = mysqli_query($conn,"insert int User (Username,password)values('$Username','$password')");
if($exe)
{
    $check = mysqli_query("select Username from User where Username = '$Username' limit 1");
    
    if(mysql_fetch_array($check))
    {
        echo 'error Username',$Username 'is existing! <a href="javascript:history.back(-1);">Return</a>';
        exit;
    }

    echo 'registration success! Click to jump<a href = "login.php">Login</a>';
}
else
{
    echo 'registration failed! Click to return <a href = "javascript:history.back(-1);">Return</a>';
}

?>