#! /bin/sh

# immediate exit in case of any failure
set -e


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

for f in "${files[@]}"; do
    cp ../"$f" .
done


# compatibility with lnxsrv
if [[ "$HOSTNAME" == *"lnxsrv"* ]]; then
    sed 's/CXX *= *g++/CXX = g32/g' < makefile > tmp
    mv tmp makefile
fi


# make sure linear.cpp can compile
echo "bool somePredicate(double x);" > tmp.cpp
cat linear.cpp >> tmp.cpp
mv tmp.cpp linear.cpp


# keyword check

# test for linear.cpp
# strip single line comment
sed 's/\/\/.*$//g' < linear.cpp > tmp.cpp
mv tmp.cpp linear.cpp

if grep "\(while\|for\|goto\|static\)" linear.cpp
then
    echo "*** KEY WORD CHECK FAIL ***"

    echo "your solution must not use the keywords while, for, or goto.
You must not use variables declared with the keyword static"
fi


# test for tree.cpp
# strip single line comment
sed 's/\/\/.*$//g' < tree.cpp > tmp.cpp
mv tmp.cpp tree.cpp

if grep "\(while\|for\|goto\|static\)" linear.cpp
then
    echo "*** KEY WORD CHECK FAIL ***"

    echo "your solution must not use the keywords while, for, or goto.
You must not use variables declared with the keyword static"
fi


# testing begin

echo
echo "--> testing landmark.cpp ..."
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


echo
echo "--> testing linear.cpp ..."
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


echo
echo "--> testing maze.cpp ..."
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


echo
echo "--> testing tree.cpp ..."
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
