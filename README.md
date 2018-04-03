# algorithms_project

compile with: g++ *.cpp

to generate graphs, run the executable file with no input

after the program runs, it will create a file called "generated_graphs.txt"

to run the algorithms, run the executable with "generated_graphs.txt"
(or your own input file with the same format)

here is a sample of an input file with 1 graph on 10 vertices

1 <--------------------- number of graphs in this file
10 <-------------------- number of vertices in each graph
0	8	7	2	4	2	8	3	5	2 --
6	0	3	4	3	4	4	7	5	3 	|
5	1	0	4	1	8	6	7	3	7 	|
4	4	8	0	2	3	7	3	6	8 	|
2	1	4	3	0	6	6	6	8	1 	|-- weights of edges
2	7	5	4	3	0	6	7	4	5 	|
5	2	7	3	5	2	0	2	6	5 	|
8	1	2	7	2	2	2	0	5	8 	|
7	2	7	8	3	5	4	7	0	8 	|
1	5	3	5	1	4	4	3	8	0 --|

and this would be the output for that input

0	4	5	2	3	2	5	3	5	2	--
4	0	3	4	3	4	4	6	5	3	 	|
3	1	0	4	1	5	5	6	3	2	 	|
4	3	5	0	2	3	5	3	6	3	 	|
2	1	4	3	0	4	5	4	6	1	 	|-- shortest paths
2	4	5	4	3	0	6	5	4	4	 	|
4	2	4	3	4	2	0	2	6	5	 	|
4	1	2	5	2	2	2	0	5	3	 	|
5	2	5	6	3	5	4	6	0	4	 	|
1	2	3	3	1	3	4	3	6	0	--|

please note that each graph in one input file must have the same number of vertices
