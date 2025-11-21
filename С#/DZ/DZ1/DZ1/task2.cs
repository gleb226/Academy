namespace DZ1;

public class task2
{
    static void Main()
    {
        Console.WriteLine("Write 2 numbers. First it`s value and second interest");
        Console.Write("Number 1: ");
        var number = double.Parse(Console.ReadLine());
        Console.Write("Number 2: ");
        var percent = double.Parse(Console.ReadLine());
        
        var result = number * percent / 100;
        
        Console.WriteLine($"Result is: {result}");

    }
}

