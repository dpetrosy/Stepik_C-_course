int** transpose(const int* const* m, unsigned rows, unsigned cols)
{
    int** M = new int*[cols];
    for (unsigned i = 0; i < cols; ++i)
        M[i] = new int[rows];

    for (unsigned i = 0; i < cols; ++i)
        for (unsigned j = 0; j < rows; ++j)
            M[i][j] = m[j][i];

    return M;
}
