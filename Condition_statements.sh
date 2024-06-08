#NAME   : MONISHA.S 
#REG.NO : 21BCT0414 
#AIM    : IMPLEMENTATION OF CONDITIONAL STATEMENTS
echo "*********************************"
echo "      NAME   : MONISHA.S"
echo "      REG.NO : 21BCT0414"
echo "*********************************"
echo "Enter the Total number of Ratings"
read n;
sum=0
for(( i=1;i<=n;i++ ))
    do
        echo "Enter the Rating $i"
        read  r
        if [ $r -gt 0 ]
            then
                sum=`expr $sum + $r`
        else
            echo "Re-enter the Rating(Rating Should not be less than zero) $i"
            read  r
        fi
    done

avg=`expr $sum / $n`
echo "Remarks According to the Average of Ratings"
echo "Average is $avg"
if [ $avg -gt 90 ]
    then
        echo "Excellent"
elif [ $avg -ge 80 -a $avg -lt 90 ]
    then
        echo "Very Good"
elif [ $avg -ge 70 -a $avg -lt 80 ]
    then
        echo "Good"
elif [ $avg -ge 60 -a $avg -lt 70 ]
    then
        echo "Fair"
elif [ $avg -ge 55 -a $avg -lt 60 ]
    then 
        echo "Bad"
else
    echo "Poor"
fi