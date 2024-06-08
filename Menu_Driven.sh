#NAME   : MONISHA.S 
#REG.NO : 21BCT0414 
#AIM    : IMPLEMENTATION OF MENU DRIVEN PROGRAM
echo "*********************************"
echo "      NAME   : MONISHA.S"
echo "      REG.NO : 21BCT0414"
echo "*********************************"
echo

echo -n "Enter the number : "
read a
echo
echo "Decide your need according to the serial number given below"
echo "1.Check if a number is a Composite number"
echo "2.Check if a number is an Automorphic number"
echo "3.Check if a number is an Abundant number"
echo
echo -n "Enter your choice : "
read input
echo   
while [ $input -ne 4 ]
do
    
    case $input in 
    
    1) 
        fac=0
        for(( i=1;i<=a;i++ ))
        do  
            s=`expr $a % $i`
            if [ $s -eq 0 ] ;then
                fac=`expr $fac + 1`
            fi
        done
        if [ $fac -gt 2 ]
            then 
                echo "Given number $a is a Composite number"
        else
                echo "Given number $a is Not a Composite number"
        fi
        echo
    ;;
    2)
        s=`expr $a \* $a`
        p=$a
        q=$s
        i=0
        j=0
        while [ $p -ne 0 ]
        do 
            amod=`expr $p % 10`
            smod=`expr $q % 10`
            if [ $amod = $smod ]
            then
                j=`expr $j + 1`
            fi
            i=`expr $i + 1`
    
            p=`expr $p / 10`
            q=`expr $q / 10`
        done
        if [ $i = $j ]
        then
                echo "Given number $a is a Automorphic number"
        else
                echo "Given number $a is Not a Automorphic number"
        fi
        
        echo
    ;;
    3)
        sum=0
        for(( i=1;i<a;i++ ))
        do
        x=`expr $a % $i`
        if [ $x -eq 0 ]
        then 
            sum=`expr $sum + $i`
        fi
        done

        y=`expr $sum - $a`
        z=`expr $a % $y`

        if [ $z -eq 0 ]
        then
            echo "Given number $a is a Abundant Number"
        else
            echo "Given number $a is Not a Abundant Number"
        fi
        echo
    ;;
    *)
        echo "Invalid Input"
        echo
    esac
    
    echo -n "Enter the number : "
    read a
    echo
    echo "Decide your need according to the serial number given below"
    echo "1.Check if a number is a Composite number"
    echo "2.Check if a number is an Automorphic number"
    echo "3.Check if a number is an Abundant number"
    echo "4.Quit the process"
    echo
    echo -n "Enter your choice : "
    read input
    
done