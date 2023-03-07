# Word Count Demo

This simple demo uses an unordered map to count the number of occurrences of
each word in a text file. The words and their counts are then copied to a
vector of pairs, and the vector is sorted by the number of occurrences in
descending order, to produce a list of the most frequently used words.

## How to

After cloning the repository, you can build and run the demo with the
following commands:

    $ g++ -std=c++17 wordcount.cpp -o wordcount
    $ ./wordcount
    Enter filename: getty.txt
    that                   13
    the                    11
    we                     10
    here                    8
    to                      8
    a                       7
    and                     6
    it                      5
    can                     5
    for                     5
