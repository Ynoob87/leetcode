#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        for (int i = 0; i < image.size(); i++)
        {
            int left = 0;
            int right = image[i].size() - 1;

            while (left <= right)
            {
                swap(image[i][left], image[i][right]);

                image[i][left] = image[i][left] == 0 ? 1 : 0;
                image[i][right] =
                    ((left != right) ? (image[i][right] == 0 ? 1 : 0)
                                     : image[i][right]);

                left++;
                right--;
            }
        }

        return image;
    }
};
