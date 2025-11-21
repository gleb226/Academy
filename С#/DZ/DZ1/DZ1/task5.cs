namespace DZ1;

public class task5
{
    static void Main()
    {
        Console.WriteLine("Hello, write any date(example: 22.12.2021):");
        var date = Console.ReadLine();
        
        string[] parts = date.Split('.');
        int day = int.Parse(parts[0]);
        int month = int.Parse(parts[1]);
        int year = int.Parse(parts[2]);

        string season;
        if (month == 12 || month == 1 || month == 2) season = "winter";
        else if (month == 3 || month == 4 || month == 5) season = "spring";
        else if (month == 6 || month == 7 || month == 8) season = "summer";
        else season = "autumn";

        int m = month;
        int y = year;

        if (m < 3)
        {
            m += 12;
            y -= 1;
        }
        
        int K = y % 100;
        int J = y / 100;
        
        int h = (day + (13 * (m + 1)) / 5 + K + K/4 + J/4 + 5*J) % 7;
        
        string weekday = h switch
        {
            0 => "Saturday",
            1 => "Sunday",
            2 => "Monday",
            3 => "Tuesday",
            4 => "Wednesday",
            5 => "Thursday",
            6 => "Friday",
            _ => "Unknown"
        };
        Console.Write($"{weekday} is {season} season");
    }
}