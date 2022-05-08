#!/bin/bash

while [ 1 ]
do
	echo "SELECT YOUR YOUR OPTION";
	echo "1. create database "  
	echo "2. view database "  
	echo "3. insert a record "  
	echo "4. delete record "  
	echo "5. modify a record "  
	echo "6. result of particular student "  
	echo "7. exit"  
	echo "enter ur choice "  
	read d  
	case $d in  
	#create database 
	1)  
		echo "enter rollnumber of student "  
		read rn  
		echo "enter name of student "  
		read nm  
		echo "enter marks of DBMS "  
		read dbms  
		echo "enter marks of OS "  
		read os  
		echo "enter marks of MC "  
		read mc  
		record="$rn $nm $dbms $os $mc "  
		echo $record>stud   
		;;  
	#view database 
	2) 	echo "showing database of student"  
		cat stud ;;  
	#insert a record
	3)   
		echo "enter rollnumber of student "  
		read rn  
		echo "enter name of student "  
		read nm  
		echo "enter marks of DBMS "  
		read dbms  
		echo "enter marks of OS "  
		read os  
		echo "enter marks of MC "  
		read mc  
		record="$rn $nm $dbms $os $mc "  
		echo $record>>stud  
		;;  
	#delete record
	4) 	echo "enter roll number "  
		read rn  
		grep ^$rn stud  
		if [ $? -ne 0 ]; then  
		echo "record of roll number does not exist "  
		else  
		grep -v $rn stud>>tmp  
		cp tmp stud  
		echo "deletion is complete "  
		fi  
		;;  
	#modify a record
	5) 	echo " enter roll number "  
		read rn1  
		grep ^$rn stud  
		if [ $? -ne 0 ]; then  
		echo "record of roll number does not exist "  
		else  
		echo "enter roll number "  
		read rn  
		echo "enter name of student "  
		read nm  
		echo "enter marks of DBMS "  
		read dbms  
		echo "enter marks of OS "  
		read os  
		echo "enter marks of MC "  
		read mc  
		record="$rn $nm $dbms $os $mc "  
		var=`grep -n ^$rn1 stud | cut -c 1`  
		echo $var  
		var1=`expr $var - 1`  
		head -$var1 stud>temp  
		echo $record>>temp  
		var3=`wc -l < stud`  
		var2=`expr $var3 - $var `  
		tail -$var2 stud>>temp  
		cp temp stud  
		fi  
		;;  
	#result of particular student
	6) echo "enter roll number "  
		read rn  
		echo "printing result "  
		grep ^$rn stud  
		;;  
	7) exit;;  
	* ) echo "enter right choice"  
	esac
done
