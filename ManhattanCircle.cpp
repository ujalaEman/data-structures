#include <iostream>

int main()
{
    int n, m;
    cin >> n >> m;

    char grid[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int centerX = 0, centerY = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#')
            {
                centerX += i + 1;
                centerY += j + 1;
                count++;
            }
        }
    }

    centerX /= count;
    centerY /= count;

    cout << centerX << " " << centerY << endl;

    return 0;
}
