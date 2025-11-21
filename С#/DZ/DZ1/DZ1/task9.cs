namespace DZ1;

public class task9
{
    static void Main()
    {
        Console.WriteLine("Hello, type any number!");
        
        int number = int.Parse(Console.ReadLine());
        int originalNumber = number;
        
        int sum = 0;

        for (int i = 1; i <= number; i++)
        {
            if (number % i == 0)
            {
                sum += i;
            }
        }

        if (sum == originalNumber)
        {
            Console.WriteLine($"{originalNumber} is a prime number.");
        }
        else
        {
            Console.WriteLine($"{originalNumber} is not a prime number.");
        }
    }
}