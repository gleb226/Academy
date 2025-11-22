namespace DZ2;

public class task2
{
    static void Main()
    {
        Random rand = new Random();
        int[,] arr1 = new int[5, 5];
        int[,] arr2 = new int[5, 5];

        for (int i = 0; i < arr1.GetLength(0); i++)
            for (int j = 0; j < arr1.GetLength(1); j++)
                arr1[i, j] = rand.Next(-100, 100);

        Console.WriteLine("Array 1:");
        for (int i = 0; i < arr1.GetLength(0); i++)
        {
            for (int j = 0; j < arr1.GetLength(1); j++)
                Console.Write(arr1[i, j] + " ");
            Console.WriteLine();
        }

        for (int i = 0; i < arr1.GetLength(0); i++)
            for (int j = 0; j < arr1.GetLength(1); j++)
                arr1[i, j] = rand.Next(-100, 100);

        Console.WriteLine("Array 1:");
        for (int i = 0; i < arr2.GetLength(0); i++)
        {
            for (int j = 0; j < arr2.GetLength(1); j++)
                Console.Write(arr2[i, j] + " ");
            Console.WriteLine();
        }

        for (int i = 0; i < arr2.GetLength(0); i++)
            for (int j = 0; j < arr2.GetLength(1); j++)
                arr2[i, j] = rand.Next(-100, 100);

        Console.WriteLine("Array 2:");
        for (int i = 0; i < arr2.GetLength(0); i++)
        {
            for (int j = 0; j < arr2.GetLength(1); j++)
                Console.Write(arr2[i, j] + " ");
            Console.WriteLine();
        }

        int rows = arr1.GetLength(0);
        int cols = arr1.GetLength(1);

        int min = arr1[0, 0], max = arr1[0, 0];
        int minRow = 0, minCol = 0, maxRow = 0, maxCol = 0;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (arr1[r, c] < min)
                {
                    min = arr1[r, c];
                    minRow = r;
                    minCol = c;
                }

                if (arr1[r, c] > max)
                {
                    max = arr1[r, c];
                    maxRow = r;
                    maxCol = c;
                }
            }
        }

        int minIndex = minRow * cols + minCol;
        int maxIndex = maxRow * cols + maxCol;

        int left = Math.Min(minIndex, maxIndex);
        int right = Math.Max(minIndex, maxIndex);

        int sum = 0;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int index = r * cols + c;
                if (index > left && index < right)
                    sum += arr1[r, c];
            }
        }

        Console.WriteLine("Sum between min and max: " + sum);
    }
}
