namespace DZ1;

public class task4
{
    static void Main()
    {
        Console.Write("Enter 6-digit number: ");
        string number = Console.ReadLine();
        
        if (number.Length != 6 || !int.TryParse(number, out _))
        {
            Console.WriteLine("Error: number must be 6 digits.");
            return;
        }

        if (number.Length > 1)
        {
            char first = number[0];
            char last = number[number.Length - 1];
            
            string result = last + number.Substring(1, number.Length - 2) + first;
            Console.WriteLine($"Result is: {result}");
        }
        
    }
}