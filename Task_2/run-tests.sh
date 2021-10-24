#!/bin/bash

set -e

if [[ $(dirname $0) != "." ]]; then
    echo "Test must be run from $(dirname $0)"
fi

if [[ ! -f $1 ]]; then
    echo "Usage: ./run-tests.sh <binary>"
    exit 1
fi

binary=$1

echo "Running test 1..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" tests/data/test_001.txt tests/test_001.out
echo -e "Test 1 done\n"

echo "Running test 2..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" tests/data/test_002.txt tests/test_002.out
echo -e "Test 2 done\n"

echo "Running test 3..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" tests/data/test_003.txt tests/test_003.out
echo -e "Test 3 done\n"

echo "Running test 4..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" -n 100 tests/data/test_random_004.txt tests/test_004.out
echo -e "Test 4 done\n"

echo "Running test 5..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" -n 1000 tests/data/test_random_005.txt tests/test_005.out
echo -e "Test 5 done\n"

echo "Running test 6..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" -n 5000 tests/data/test_random_006.txt tests/test_006.out
echo -e "Test 6 done\n"

echo "Running test 7..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" -n 5000 tests/data/test_random_007.txt tests/test_007.out
echo -e "Test 7 done\n"

echo "Running test 8..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" -n 10000 tests/data/test_random_008.txt tests/test_008.out
echo -e "Test 8 done\n"

echo "Running test 9..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" -n 10000 tests/data/test_random_009.txt tests/test_009.out
echo -e "Test 9 done\n"

echo "Running test 10..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" -n 10000 tests/data/test_random_010.txt tests/test_010.out
echo -e "Test 10 done\n"

echo "Running test 11..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" tests/data/test_011.txt tests/test_011.out
echo -e "Test 11 done\n"

echo "Running test 12..."
/usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" "$binary" -n 10000 tests/data/test_random_012.txt tests/test_012.out
echo -e "Test 12 done\n"
