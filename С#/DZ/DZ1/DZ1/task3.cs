namespace DZ1;

public class task3
{
    static void Main()
    {
        Console.WriteLine("Write 4 numbers: ");

        Console.Write("Number 1: ");
        var number1 = int.Parse(Console.ReadLine());
        Console.Write("Number 2: ");
        var number2 = int.Parse(Console.ReadLine());
        Console.Write("Number 3: ");
        var number3 = int.Parse(Console.ReadLine());
        Console.Write("Number 4: ");
        var number4 = int.Parse(Console.ReadLine());

        string result1 = $"{number1}{number2}{number3}{number4}";
        string result2 = number1.ToString() + number2.ToString() + number3.ToString() + number4.ToString();
        int result3 = number1;
        result3 = result3 * 10 + number2;
        result3 = result3 * 10 + number3;
        result3 = result3 * 10 + number4;


        Console.WriteLine($"Result 1 is: {result1}");
        Console.WriteLine($"Result 2 is: {result2}");
        Console.WriteLine($"Result 3 is: {result3}");
    }
}