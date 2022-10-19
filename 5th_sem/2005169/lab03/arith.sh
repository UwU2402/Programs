echo "ARITHMATIC OPERATIONS\n"
read -p "Enter 1st no.:" a
read -p "Enter 2nd no.:" b
sum=`expr $a + $b`
dif=`expr $a - $b`
pro=`expr $a \* $b`
div=`expr $a / $b`
echo "$a + $b = $sum \n"
echo "$a - $b = $dif \n"
echo "$a * $b = $pro \n"
echo "$a / $b = $div \n"
