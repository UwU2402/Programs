echo "CONVERSION OF SECONDS TO EQUIVALENTS HOURS AND MINUTES \n"
read -p "Enter the seconds.:" s 
m=`expr $s / 60`
h=`expr $m / 60`
s=`expr "$s % 60"|bc`
m=`expr "$m % 60"|bc`
echo "$h:$m:$s \n"

