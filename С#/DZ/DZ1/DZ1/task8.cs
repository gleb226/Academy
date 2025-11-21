namespace DZ1;

public class task8
{
    static void Main()
    {
        Console.WriteLine("Hello, type any number!");
        int number = int.Parse(Console.ReadLine());
        int originalNumber = number;

        int digitsCount = number.ToString().Length;
        int sum = 0;

        while (number > 0)
        {
            int digit = number % 10;

            int power = 1;
            for (int i = 0; i < digitsCount; i++)
            {
                power *= digit;
            }

            sum += power;
            number /= 10;
        }

        if (sum == originalNumber)
        {
            Console.WriteLine($"{originalNumber} is an Armstrong number.");
        }
        else
        {
            Console.WriteLine($"{originalNumber} is not an Armstrong number.");
        }
    }
}