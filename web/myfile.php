	<html>
	<head>
	<title>Write to a text file</title>
	</head>
	<body>


	
    <FORM METHOD="POST" ACTION="myfile.php">
        <TABLE BORDER="1">
          <TR>
            <TD>
              <INPUT TYPE="TEXT" NAME="one[]" SIZE="20">
            </TD>
          </TR>
          <TR>
            <TD><INPUT TYPE="TEXT" NAME="one[]" SIZE="20"></TD>
          </TR>
        </TABLE>
    <P><INPUT TYPE="SUBMIT" VALUE="Submit" NAME="B1"></P>
    </FORM>

<?php
$arr = array("value1","value2","value3","value4");
echo "<table>";
$rows = array_chunk($arr,3);
foreach($rows as $row) {
  echo "<tr>";
  foreach($row as $cell) {
    echo "<td>".$cell."</td>";
  }
  echo "</tr>";
}
echo "</table>";
?>



	<?php

	// Open the text file
	$f = fopen("textfile.txt", "w");

	// Write text

    foreach ($_POST["one"] as $one) {
	fwrite($f, $_POST["one[]"]); 
    }



	// Close the text file
	fclose($f);

	// Open file for reading, and read the line
	$f = fopen("textfile.txt", "r");

	// Read text
	echo fgets($f); 
	fclose($f);

	?>
	
	</body>

	</html>