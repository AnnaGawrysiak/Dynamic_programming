/*
Given weights and values of n items, put these items in a knapsack of capacity M to get the maximum total value in the knapsack.
Note that, you can select items, the sum of whose weight is less than or equal to the capacity of knapsack, W.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int knapsack(const std::vector<int>& values, const std::vector<int>& weights, int maxWeightConstraint);

int main()
{
    std::vector<int> values = { 60, 50, 70, 30 };
    std::vector<int> weights = { 5, 3, 4, 2 };
    int capacity = 5;

    std::cout << "Knapsack value is: " << knapsack(values, weights, capacity);

    return 0;
}

int knapsack(const std::vector<int>& values, const std::vector<int>& weights, int maxWeightConstraint)
{
    //Create a matrix of order(n + 1)* (M + 1), ie.knapsack[n + 1][M + 1]
    int nr_of_items = values.size();
    std::vector<int> row(maxWeightConstraint + 1, 0);
    std::vector<std::vector<int>> subproblems(nr_of_items + 1, row);

    for (int i = 1; i < subproblems.size(); i++)
    {
        for (int j = 1; j < row.size(); j++)
        {
            if (j >= weights[i - 1])
                subproblems.at(i).at(j) = std::max(subproblems.at(i - 1).at(j), values.at(i-1) +  subproblems.at(i-1).at(j - weights.at(i-1))); // to wyra¿enie poiwnno równaæ w dó³ do pe³nego inta :maxWeightConstraint - weights.at(i). Co jeœli waga to czêœæ u³amkowa 
            else
                subproblems.at(i).at(j) = subproblems.at(i - 1).at(j);
        }
    }

    for (int i = 0; i < subproblems.size(); i++)
    {
        for (int j = 0; j < row.size(); j++)
        {
            std::cout << subproblems.at(i).at(j) << " ";
        }

        std::cout << std::endl;
    }

    return subproblems.at(nr_of_items).at(maxWeightConstraint);
}