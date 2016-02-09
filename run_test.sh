#! /bin/sh

# immediate exit in case of any failure
 set -e

# Debug trick: Stop at every line
# set -x
# trap read debug

declare -a files=(
    "landmark.cpp"
    "linear.cpp"
    "maze.cpp"
    "tree.cpp"
)

function cleanup {
    make -s clean
    for f in "${files[@]}"; do
        rm "$f"
    done
    rm output
}

function checkLoop {
    # strip single line comment
    sed 's/\/\/.*$//g' < $1 > tmp.cpp
    mv tmp.cpp $1

    if grep "\(while\|for\|goto\|static\)" $1
    then
        echo "*** KEY WORD CHECK FAIL ***"

        echo "your solution must not use the keywords while, for, or goto.
    You must not use variables declared with the keyword static"
    fi

}

function checkComment {
    # Primitive: check if lines with comment accounts for at least 10% of the program
    n_comment=`cat $1 | grep '//' | wc -l`
    n_line=`cat $1 | wc -l`
    if [[ $((n_comment * 100 / n_line))  -lt 10 ]]; then
        echo "HINT: To not lose points, you may want to add more comments for $1 ."
    fi
}

function animateLoading {
    # Better visual effect. Will be integrated to show real progress later.
    # Cool animation
    for (( i=0; i<30; i++ ));  do
        sleep 0.01;
        printf "."
    done
    printf "DONE\n"
}
#{ cleanup; } > /dev/null

printf "=== COPYING FILES ..."
for f in "${files[@]}"; do
    cp ../"$f" .
    printf "......"
done
printf "DONE\n"

printf "=== OPTIMIZING FOR YOUR OPERATING SYSTEM..."

# compatibility with lnxsrv
if [ "$HOSTNAME" == *"lnxsrv07"* ] || [ "$HOSTNAME" == *"lnxsrv09"* ] ; then
    sed 's/CXX *= *g++/CXX = g32/g' < makefile > tmp
    mv tmp makefile
fi
animateLoading


# make sure linear.cpp doesn't contain somePredicate
printf "=== RUNNING SANITY TEST..."
animateLoading
echo "bool somePredicate(double x);" > tmp.cpp
cat linear.cpp >> tmp.cpp
mv tmp.cpp linear.cpp


# comment check
printf "=== LOOKING FOR HUMOROUS COMMENTS..."
animateLoading
for f in "${files[@]}"; do
    checkComment "$f";
done


# keyword check
printf "=== CENSORING CURSE WORDS..."
animateLoading

checkLoop linear.cpp
checkLoop maze.cpp


echo;
printf '>>> testing landmark.cpp ...'
animateLoading
make -s landmark || {
    echo "*** FATAL ERROR ***";
    echo ;
    echo "landmark.cpp does not compile";
    echo ;
    echo "NOTE: What you'll turn in for this problem will
be a file named landmark.cpp containing the definitions and
implementations of the four classes, and nothing more";
}
[[ -x landmark.out ]] && ./landmark.out > output
if ! diff -u expected output
then
    echo "*** UNEXPECTED OUTPUT ***"
else
    echo "landmark PASSED"
fi


echo;
printf '>>> testing linear.cpp ...'
animateLoading
make -s linear || {
    echo "*** FATAL ERROR ***";
    echo ;
    echo "linear.cpp does not compile";
    echo ;
    echo "NOTE: you will turn in one file named
linear.cpp that contains the five functions and
nothing more: no implementation of somePredicate
and no main routine";
}
[[ -x linear.out ]] && ./linear.out


echo;
printf '>>> testing maze.cpp ...'
animateLoading
make -s maze || {
    echo "*** FATAL ERROR ***";
    echo ;
    echo "maze.cpp does not compile";
    echo ;
    echo "NOTE: you will turn in one file named maze.cpp
that contains the Coord class (if you use it) and the
pathExists function and nothing more";
}
[[ -x maze.out ]] && ./maze.out


echo;
printf '>>> testing tree.cpp ...'
animateLoading
make -s tree || {
    echo "*** FATAL ERROR ***";
    echo ;
    echo "tree.cpp does not compile";
    echo ;
    echo "NOTE: you will turn in one file named tree.cpp
that contains the four functions above and nothing more";
}
[[ -x tree.out ]] && ./tree.out


cleanup
