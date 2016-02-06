#! /bin/sh

# immediate exit in case of any failure
set -e

declare -a files=(
    "mazestack.cpp"
    "mazequeue.cpp"
    "eval.cpp"
)

function cleanup {
    make -s clean
    for f in "${files[@]}"; do
        rm -f "$f"
    done
}

for f in "${files[@]}"; do
    cp ../"$f" .
done


# substitute out possible main function
sed 's/int  *main *(/int main__(/g' < mazestack.cpp > TMPmazestack.cpp
mv TMPmazestack.cpp mazestack.cpp

sed 's/int  *main *(/int main__(/g' < mazequeue.cpp > TMPmazequeue.cpp
mv TMPmazequeue.cpp mazequeue.cpp

sed 's/int  *main *(/int main__(/g' < eval.cpp > TMPeval.cpp
mv TMPeval.cpp eval.cpp

# compile and test
make -s all

echo "testing mazestack.cpp"
./stack.out
echo
echo "testing mazequeue.cpp"
./queue.out
echo
echo "testing eval.cpp"
./eval.out
echo

echo "clean up ..."
cleanup
