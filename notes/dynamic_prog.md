# Dynamické programování

## Canon examples

### Tight words
Given is an alphabet $\{0,1,\dots, k\}, 0 \leq k \leq 9$. We say that a words of length $n$ over this alphabet is **tight** if any two neighbour digits in the word do not differ by more than 1.

#### Input 
We get two numbers $n,k$. For each input output thee percentage of tight words of length n over the alphabet $\{0,1,\dots,k\}$ with n fractional digits

#### Solution
We create a table that we will fill as we go. Each column is the length of the word and each row is the last character. 

For example: How many words there are for words of length 2? $|\{00, 01, 10, 11, 12, 21,22,23,32,33\}| = 10$. Each of these words end with some character. Look at it in terms of the previous characters. If we had last character $0$, what could have been there previously? Only $\{0,1\}$. What if we had last character $1$? We could have had previously only $\{0, 1, 2\}$. 

Therefore we can fill in these possibilities of the previously filled cells in the table.

For the input $n=5, k=3$ we get this table:

| Last char/length of word | 1 | 2 | 3 | 4  | 5  |
|--------------------------|---|---|---|----|----|
| 0                        | 1 | 2 | 5 | 13 | 34 |
| 1                        | 1 | 3 | 8 | 21 | 54 |
| 2                        | 1 | 3 | 8 | 21 | 54 |
| 3                        | 1 | 2 | 5 | 13 | 34 |

Notice how we got each cell dynamically, using this:

`words[x][y] = words[x-1][y-1]+words[x][y-1]+words[x+1][y-1]`

### Brick Wall Patterns
This is basically computing factorial.

If we want to build a brick wall out of the usual size of brick which has a length twice as long as its height, and if our wall is to be two units tall, we can make our wall in a number of patterns, depending on how long we want it. From the figure one observe that:

* There is just one wall pattern which is 1 unit wide made by putting the brick on its end.
* There are 2 patterns for a wall of length 2: two sideways bricks laid on top of each other and two bricks long-ways up put next to each other.
* There are three patterns for walls of length 3.

Your task is to write a program that given the length of a wall, determines how many patterns there may be for a wall of that length.

#### Solution 
Again we will create a table. Look at all the possible configurations of the last few cells: 
* We can end having two bricks side by side, like this: $=$. 
* We can end having one brick as such: $|$.

We can get all the different possibilities from the previously created cases and add these two possibilities to the end.

Our table for 5 positions might look like this:

|        | 1 | 2 | 3 | 4 | 5 |
|--------|---|---|---|---|---|
| $\mid$ | 1 | 1 | 2 | 3 | 5 |
| $=$    | 0 | 1 | 1 | 2 | 3 |

```
c[x][0] = c[x-3][0] + c[x-3][1]
c[x][1] = c[x-1][0] + c[x-1][1]
```

### Rectangles perimeter

Given are n rectangles, numbered from 1 to n. We place them tightly on the $x$ axis, from left to right, according to rectangles' numbers. Each rectangle stays on the axis OX either by its shorter or by its longer side (see the picture below). Compute the length of the upper envelop line, i.e. perimeter's length of the obtained figure minus the length of the left, right and bottom straight line segments of the picture. Write program to find the maximum possible length of the upper envelop line.

Basically we get a lot of rectangles and we have to assemble them side by side. We want to get the longest possible length of the top outline. The order of these rectangles is given, however we can turn them on their sides as we wish. We need to maximize the top outline of these rectangles. 

#### Sample input
```
2 5
3 8
1 10
7 14
2 5
```

#### Solution
Again we can create a table for each rectangle index. 

| last rect/# rect | 1 | 2                              | 3 | 4 | 5 |
|------------------|---|--------------------------------|---|---|---|
| norm             | 5 | ... |
| turned           | 2 | ... |

```
c[x][norm] = max(c[x-1][norm] + sizes[x][norm][0] + abs(sizes[x-1][norm][0] - sizes[x][norm][1]), c[x-1][turned] + sizes[x][norm][0] + abs(sizes[x-1][turned][0] - sizes[x][norm][1]))
...
```

### Princess Farida
Once upon time there was a cute princess called Farida living in a castle with her father, mother and uncle. On the way to the castle there lived many monsters. Each one of them had some gold coins. Although they are monsters they will not hurt. Instead they will give you the gold coins, but if and only if you didn't take any coins from the monster directly before the current one. To marry princess Farida you have to pass all the monsters and collect as many coins as possible. Given the number of gold coins each monster has, calculate the maximum number of coins you can collect on your way to the castle.

#### Input
The first line of input contains the number of test cases. Each test case starts with a number N, the number of monsters, $0 \leq N \leq 10^4$. The next line will have N numbers, number of coins each monster has, $0 \leq$ The number of coins with each monster $\leq 10^9$. Monsters described in the order they are encountered on the way to the castle.

#### Output
For each test case print “Case C: X” without quotes. C is the case number, starting with 1. X is the maximum number of coins you can collect.

#### Sample input:
```
Input:
2
5
1 2 3 4 5
1
10

Output:
Case 1: 9
Case 2: 10
```

#### Solution
Let's say we have this input: $\{7,4,2,6,8,5,1,2\}$. We can create this table


|          | 7 | 4 | 2 | 6  | 8  | 5  | 1  | 2  |
|----------|---|---|---|----|----|----|----|----|
| Take     | 7 | 4 | 9 | 13 | 17 | 18 | 18 | 20 |
| Not Take | 0 | 7 | 7 | 9  | 13 | 17 | 18 | 18 |


```
Y[i] = C[i] + Y[i-1]
N[i] = max(Y[i-1],N[i-1])
```

### Longest common sub-sequence
|A\B| a | g | g | t | a | b |
|---|---|---|---|---|---|---|
| g | 0 | 1 | 1 | 1 | 1 | 1 |
| x | 0 | 1 | 1 | 1 | 1 | 1 |
| t | 0 | 1 | 1 | 2 | 2 | 2 |
| x | 0 | 1 | 1 | 2 | 2 | 2 |
| a | 1 | 1 | 1 | 2 | 3 | 3 |
| y | 1 | 1 | 1 | 2 | 3 | 3 |
| b | 1 | 1 | 1 | 2 | 3 | 4 |


We have two strings $A,B$ and the table $S$. And this algorithm:

`S[x][y] = (A[y]==B[x] ? 1 : 0) + max(S[x-1][y], S[x][y-1])`