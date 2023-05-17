for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (Diag1[i] < Diag1[j])
            {
                Diag1[i] = Diag1[i] + Diag1[j];
                Diag1[j] = Diag1[i] - Diag1[j];
                Diag1[i] = Diag1[i] - Diag1[j]; //swap
            }
        }
    }