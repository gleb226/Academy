namespace DZ1;

public class task6
{
    static void Main()
    {
        Console.WriteLine("Chose system: Celcius or Forengeits (1 - Celcius, 2 - Forengeits): ");
        double choice = double.Parse(Console.ReadLine());

        if (choice == 1)
        {
            Console.Write("Enter temperature in Celcius: ");
            var F = int.Parse(Console.ReadLine()) * 9 / 5 + 32;
            Console.WriteLine($"Result is: {F}");
        }
        else if (choice == 2)
        {
            Console.Write("Enter temperature in Forengeits: ");
            var C = (int.Parse(Console.ReadLine()) - 32) * 5 / 9;
            Console.WriteLine($"Result is: {C}");
        }
        else
        {
            Console.WriteLine("Error: wrong choice");
        }
    }
}