echo "CONVERSION OF FAHRENHEIT TO CELSIUS \n"
read -p "Enter the fahrenheit temperature.:" f
c=`echo "($f-32)*5/9"|bc`
echo "Celsius temperature is $c \n"
