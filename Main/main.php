<?php
$con = mysql_connect("192.168.31.70","root","","door_lock_system");
if(!$con)
{
    die('database connection failed'.mysql_error());
}
else
{
    mysql_query("set names utf8");
    $result = mysql_query("select * from data");
    echo "<table border= '200' width= '300' margin='right'>
    <tr>
    <th>Visitor information</th>
    </tr>";

    while($row=mysql_fetch_array($result))
    {
        echo "<tr>"
        echo "<td>".$row['Photo']."</td>";
        echo "<td>".$row['temperature']."</td>";
        echo "</tr>"
    }

    echo "</table>"
}

$tem = $row['temperature'];
if($tem>37.3)
{
    echo "The visitor's body temperature is too high!" ;
}
else
{
    echo "The visitor's body temperature is normal.";
}
mysql_close($con);





?>