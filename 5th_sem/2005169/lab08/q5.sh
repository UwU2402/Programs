read -p "Enter the size of array: " n 
echo "Enter the elements: "
for((i=0;i<n;i++))
do
    read arr[$i]
done
for((i=0;i<n;i+=2))
do
	if test `expr $n % 2` -eq 0
	then
		temp=${arr[$i]}
		arr[i]=${arr[$((i+1))]}
		arr[$((i+1))]=$temp
	else
		if test $i -eq $((n-1))
		then
			arr[i]=${arr[$((n-1))]}
		else
			temp=${arr[$i]}
                	arr[i]=${arr[$((i+1))]}
                	arr[$((i+1))]=$temp
		fi
	fi

done
for((i=0;i<n;i++))
do
    echo -n ${arr[$i]}
done
echo ""
