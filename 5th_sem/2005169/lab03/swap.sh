echo "SWAP OPERATIONS\n"
read -p "Enter 1st no.:" a
read -p "Enter 2nd no.:" b
a=`expr $a + $b`
b=`expr $a - $b`
a=`expr $a - $b`
echo "After swapping a=$a & b = $b \n"
