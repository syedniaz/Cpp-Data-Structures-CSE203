void Enqueue (int n)
{
    if (isFull() == false)
    {
        if (FrontIndex == -1) FrontIndex++;
        Rearindex++;
        QueueArr [Rearindex] = n;
    }
    else cout << "Queue is full" << endl;
}