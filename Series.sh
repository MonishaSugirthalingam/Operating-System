#NAME   : MONISHA.S 
#REG.NO : 21BCT0414 
#AIM    : IMPLEMENTATION OF N-terms Series
echo "*********************************"
echo "      NAME   : MONISHA.S"
echo "      REG.NO : 21BCT0414"
echo "*********************************"
echo

echo -n "Enter the Number : "
read a 
echo -n "Series is : "
i=1
while [ $a -gt 0 ]
do
    a=`expr $a / $i`
    echo -n "$a "
    i=`expr $i + 1`
done