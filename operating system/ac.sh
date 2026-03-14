// This script implements an advanced calculator that performs various operations on two numbers.and its features include addition, subtraction, multiplication, division, modulus, power, maximum, minimum, and average. The user can choose to continue using the calculator or exit after each operation. And keep save it in .sh file and run it in terminal(sh filename.sh). 
#!/bin/bash

while true
do
echo "Advanced Calculator"
read -p "Enter first number: " num1
read -p "Enter second number: " num2

echo "Menu"
echo "1.Addition" 
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"
echo "5.Modulus"
echo "6.Power"
echo "7.Maximum"
echo "8.Minimum"
echo "9.Average"
echo "10.Exit"

read -p "Enter choice: " choice

case $choice in
    1)
        echo "Result = $(( num1 + num2 ))"
        ;;
    2)
        echo "Result = $(( num1 - num2 ))"
        ;;
    3)
        echo "Result = $(( num1 * num2 ))"
        ;;
    4)
        echo "Result = $(( num1 / num2 ))"
        ;;
    5)
        echo "Result = $(( num1 % num2 ))"
        ;;
    6)
        echo "Result = $(( num1 ** num2 ))"
        ;;
    7)
        if [ $num1 -gt $num2 ]; then
            echo "Maximum = $num1"
        else
            echo "Maximum = $num2"
        fi
        ;;
    8)
        if [ $num1 -lt $num2 ]; then
            echo "Minimum = $num1"
        else
            echo "Minimum = $num2"
        fi
        ;;
    9)
        avg=$(awk "BEGIN {printf \"%.2f\", ($num1 + $num2)/2}")
        echo "Average = $avg"
        ;;
    10)
        echo "Exiting..."
        exit
        ;;
    *)
        echo "Invalid choice"
        ;;
esac

read -p "Do you want to continue? (yes/no): " option

if [[ $option == "yes" || $option == "y" || $option == "Y" ]]
then
    continue
else
    echo "Calculator closed."
    break
fi

done
