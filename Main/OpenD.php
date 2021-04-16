<?php
$con = mysql_connect("192.168.31.70","root","") or die ("connection failed!");
mysql_query("set names utf8");
mysql_select_db("door_lock_system",$con);

$_username = $_GET['username'];

mysql_query("Updata User set status='true' where Username = $username",$con) or die('Failed to open'.mysql_error());

?>