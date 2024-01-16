void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min_index = 0;
    int min_value = m[0][0];
    
    for (unsigned i = 0; i < rows; ++i)
    {
        for (unsigned j = 0; j < cols; ++j)
        {
            if (m[i][j] < min_value)
            {
               min_value = m[i][j];
               min_index = i;
            }
        }
    }
    int *temp = m[0];
    m[0] = m[min_index];
    m[min_index] = temp;
}
