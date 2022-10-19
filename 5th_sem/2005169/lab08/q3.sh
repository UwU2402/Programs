read -p "Enter the size of Array: " n 
echo "Enter the elements: "
for((i=0;i<n;i++));
do
    read arr[$i]
done
echo
for ((i = 0; i<n; i++))
do
    
    for((j = 0; j<n-i-1; j++))
    do
        if [ ${arr[j]} -gt ${arr[$((j+1))]} ]
        then
            temp=${arr[j]}
            arr[$j]=${arr[$((j+1))]}  
            arr[$((j+1))]=$temp
        fi
    done
done
echo "Display Order:"
echo "1. Ascending Order"
echo "2. Descending Order"
read -p "Enter Choice: " ch
case $ch in
    1)
    echo "Array Elements: "
    for((i=0;i<n;i++));
    do
        echo -n ${arr[$i]} ""
    done
    echo
    ;;
    2)
    echo "Array Elements in reverse: "
    for((i=n;i>=0;i--));
    do
        echo -n ${arr[$i]} ""
    done
    echo
    ;;
    *) echo "Wrong Input!!!"
    ;;
esac
