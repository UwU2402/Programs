read -p "Enter the size of array: " n 
echo "Enter the elements: "
for((i=0;i<n;i++));
do
    read ar[$i]
done
echo "Array: "
for((i=0;i<n;i++));
do
    echo -n ${ar[$i]}  
done
echo "Reversed Array: "
for((i=n;i>=0;i--));
do
    echo -n ${ar[$i]}
done
