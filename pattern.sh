#NAME   : MONISHA.S 
#REG.NO : 21BCT0414 
#AIM    : IMPLEMENTATION OF FOR LOOP
echo "*********************************"
echo "      NAME   : MONISHA.S"
echo "      REG.NO : 21BCT0414"
echo "*********************************"
echo
n=5
for(( i=1;i<=n;i++ ))
    do 
        for(( j=n-i;j>=0;j-- ))
            do
                echo -n " "
            done
        count1=0
        for(( j=1;j<=i;j++ ))
            do 
                x=`expr $i + $count1`
                echo -n "$x"
                count1=`expr $count1 + 1`
            done 
        count1=`expr $i - 1`
        for(( j=i-1;j>=1;j-- ))
            do 
                x=`expr $j + $count1`
                echo -n "$x"
                count1=`expr $count1 - 1`
            done 
        echo
    done
