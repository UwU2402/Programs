read -p "Enter the size of Array: " n 
echo "Enter the elements: "
for((i=0;i<n;i++));
do
    read arr[$i]
done
mid=`expr $n / 2`
j=`expr $n - 1`
for((i=0;i<mid;i++))
do
    temp=${arr[$i]}
    arr[$i]=${arr[$j]}
    arr[$j]=$temp
    j=`expr $j + 1`
done
echo "Array Elements: "
for((i=0;i<n;i++));
do
    echo -n ${arr[$i]}
done
