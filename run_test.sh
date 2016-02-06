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
}

for f in "${files[@]}"; do
    cp ../"$f" .
done


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
echo "testing landmark.cpp ..."
make -s landmark || {
    echo "*** FATAL ERROR ***";
    echo -e "\nlandmark.cpp does not compile\n";
}
[[ -x landmark.out ]] && ./landmark.out


echo
echo "testing linear.cpp ..."
make -s linear || {
    echo "*** FATAL ERROR ***";
    echo -e "\nlinear.cpp does not compile\n";
    echo "NOTE: you will turn in one file named
linear.cpp that contains the five functions and
nothing more: no implementation of somePredicate
and no main routine";
}
[[ -x linear.out ]] && ./linear.out


echo
echo "testing maze.cpp ..."
make -s maze || {
    echo "*** FATAL ERROR ***";
    echo -e "\nmaze.cpp does not compile\n";
    echo "NOTE: you will turn in one file named maze.cpp
that contains the Coord class (if you use it) and the
pathExists function and nothing more";
}
[[ -x maze.out ]] && ./maze.out


echo
echo "testing tree.cpp ..."
make -s tree || {
    echo "*** FATAL ERROR ***";
    echo -e "\ntree.cpp does not compile\n";
    echo "NOTE: you will turn in one file named tree.cpp
that contains the four functions above and nothing more";
}
[[ -x tree.out ]] && ./tree.out


cleanup
