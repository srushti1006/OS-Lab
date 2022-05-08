#!/bin/bash

# creating a menu with the following options

# reading choice
while [ 1 ]
do
	echo "SELECT YOUR YOUR OPTION";
	echo "1. find if the number is odd or even"
	echo "2. find if the number is prime number"
	echo "3. Find if the year is leap or not"
	echo "4. Find factorial"
	echo "5. Swap two numbers"
	echo "6. Exit from menu"
	echo -n "Enter your menu choice [1-6]: "
	read choice
	# case statement is used to compare one value with the multiple cases.
	case $choice in
	  # Pattern 1
	  1)  	echo "Enter the Number to decide if it is odd or even"
		read n
		r=`expr $n % 2`
		if  [ $r -eq 0 ]
		then
			echo "$n is Even number"
		else	
			echo "$n is Odd number"
		fi;;
	  # Pattern 2
	  2)    echo -e "Enter Number to know if it is prime or not : \c"
		read n
		if [ $n -eq 0 ]
		then
			echo "$n is not a prime number."
			exit 0
		fi
		for((i=2; i<=$n/2; i++))
		do
		  ans=$(( n%i ))
		  if [ $ans -eq 0 ]
		  then
		    echo "$n is not a prime number."
		    exit 0
		  fi
		done
		echo "$n is a prime number.";;
	  # Pattern 3
	  3)
		echo "Enter the year"
		read y
		b=`expr $y % 4`
		if [ $b -eq 0 ]
		then
		echo "$y is a leap year
"
		else
		echo "$y is not a leap year"
		fi;;

	  # Pattern 4
	  4)
		echo "Enter Number to find it's factorial"
		read n
		i=`expr $n - 1`
		p=1
		while [ $i -ge 1 ]
		do
		n=`expr $n \* $i`
		i=`expr $i - 1`
		done
		echo "The Factorial of the given Number is $n";;

          # Pattern 5
	  5)
		echo "Enter Two Numbers to swap"
		read a b
		temp=$a
		a=$b
		b=$temp
		echo "after swapping"
		echo $a $b;;

	  # Pattern 6
	  6)  echo "Quitting ..."
	      exit;;
	  # Default Pattern
	  *) echo "invalid option";;
	  
	esac
done

