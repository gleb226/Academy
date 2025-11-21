namespace Lesson2;

internal class Program
{
    static void Main()
    {
        Random rand = new Random();
        int[] array = new int[10];

        for (int i = 0; i < array.Length; i++)
        {
            array[i] = rand.Next(1, 100);
        }
        
        Console.WriteLine(string.Join(", ", array));

        Array.Sort(array);
        
        Console.WriteLine(string.Join(", ", array));
        
        int min = array[0];
        int max = array[0];

        for (int i = 0; i < array.Length; i++)
        {
            if (array[i] < min) min = array[i];
            if (array[i] > max) max = array[i];
        }

        Console.WriteLine($"Min: {min}, Max: {max}");

        int isEven = 0;
        int isOdd = 0;

        for (int i = 0; i < array.Length; i++)
        {
            if (array[i] % 2 == 0) isEven++;
            else isOdd++;
        }

        Console.WriteLine($"Even: {isEven}, Odd: {isOdd}");
        
    }
}