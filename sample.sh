# This script is written by xub to compile all the samples
#

for o in sample1 sample2 sample3 sample4 sample5 sample6
do
    g++ -g -o $o ${o}.cpp lua_tinker.cpp -llua -ldl
    echo $o
done

