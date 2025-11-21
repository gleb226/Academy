namespace DZ1;

public class task1
{
    static void Main()
    {
        Console.Write("Hello, enter any number from 1 to 100: ");
        int number = int.Parse(Console.ReadLine());

        if (number < 1 || number > 100)
        {
            Console.WriteLine("Error: you typed wrong number(not from 1 to 100)");
        }
        else if (number % 3 == 0 && number % 5 == 0)
        {
            Console.WriteLine("Fizz Buzz");
        }
        else if (number % 3 == 0)
        {
            Console.WriteLine("Fizz");
        }
        else if (number % 5 == 0)
        {
            Console.WriteLine("Buzz");
        }
        else
        {
            Console.WriteLine(number);
        }
    }
}