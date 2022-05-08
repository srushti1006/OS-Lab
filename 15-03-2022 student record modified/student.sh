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
		echo $record>student  
		;;  
	#view database 
	2) 	echo "showing database of student"  
		cat student ;;  
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
		echo $record>>student  
		;;  
	#delete record
	4) 	echo "enter roll number "  
		read rn  
		grep ^$rn student  
		if [ $? -ne 0 ]; then  
		echo "record of roll number does not exist "  
		else  
		grep -v $rn student>>delete  
		cp delete student  
		echo "deletion is complete "  
		rm delete
		fi  
		;;  
	#modify a record
	5) 	echo "enter roll number "  
		read rn1  
		grep ^$rn1 student  
		if [ $? -ne 0 ]; then  
		echo "record of roll number does not exist "  
		else  
		echo "enter modified roll number "  
		read rn  
		echo "enter modified name of student "  
		read nm  
		echo "enter modified marks of DBMS "  
		read dbms  
		echo "enter modified marks of OS "  
		read os  
		echo "enter modified marks of MC "  
		read mc  
		record="$rn $nm $dbms $os $mc "  
		var=`grep -n ^$rn1 student | cut -c 1`  
		echo $var  
		var1=`expr $var - 1`  
		head -$var1 student>temporary  
		echo $record>>temporary  
		var3=`wc -l < student`  
		var2=`expr $var3 - $var `  
		tail -$var2 student>>temporary  
		cp temporary student  
		rm temporary
		fi  
		;;  
	#result of particular student
	6) 	echo "enter roll number "  
		read rn  
		grep ^$rn student  
		if [ $? -ne 0 ]; then  
		echo "record of roll number does not exist "
		fi  
		;;  
	7)	exit;;  
	* ) echo "enter right choice"  
	esac
done
