add()
{
	echo "Enter first number "
	read a
	echo "Enter Second "
	read b	
	sum = `expr $a + $b`
	echo "Sum $sum"
}
add
