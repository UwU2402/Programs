echo "Input array 1"
read -p "Enter the size of Array: " m
echo "Enter the elements: "
for((i=0;i<m;i++));
do
    read arr1[$i]
done
echo
echo "Input array 2"
read -p "Enter the size of Array: " n
echo "Enter the elements: "
for((i=0;i<n;i++));
do
    read arr2[$i]
done
echo
arr1+=(${arr2[@]})
echo "Array Elements: "
for((i=0;i<m+n;i++));
do
    echo -n ${arr1[$i]} ""
done
echo
