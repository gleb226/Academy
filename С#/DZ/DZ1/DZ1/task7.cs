namespace DZ1;

public class task7
{
    static void Main()
    {
        Console.WriteLine("Hello, input 2 numbers: ");
        Console.Write("Number 1: ");
        int a = int.Parse(Console.ReadLine());
        Console.Write("Number 2: ");
        int b = int.Parse(Console.ReadLine());

        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        Console.WriteLine($"Even numbers between {a} and {b} is:");

        for (int i = a; i <= b; i++)
        {
            if (i % 2 == 0)
            {
                Console.WriteLine(i);
            }
        }
    }
}