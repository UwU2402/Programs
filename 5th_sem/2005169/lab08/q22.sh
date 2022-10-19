read -p "Enter the size of array: " n
echo "Enter the elements: "
for((i=0;i<n;i++))
do
    read arr[$i]
done
m=$(((n+1)/2))
echo $m
for((i=0;i<m;i++))
do
        if test `expr $n % 2` -eq 0
        then
                temp=${arr[$i]}
                arr[i]=${arr[$((n-1-i))]}
                arr[$((n-1-i))]=$temp
        else
		if test $i -eq $m
                then
                       break
                else
                        temp=${arr[$i]}
                        arr[i]=${arr[$((n-1-i))]}
                        arr[$((n-1-i))]=$temp
                fi
        fi

done
for((i=0;i<n;i++))
do
    echo -n ${arr[$i]}
done
echo ""

