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


cleanup
