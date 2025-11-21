namespace Lesson1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a = 0;
            while (a < 10)
            {
                Console.WriteLine(a);
                a++;
            }

            int b = 0;
            do
            {
                Console.WriteLine(b);
                b++;
            } while (b < 10);

            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine(i);
            }
            int[] arr = {1, 2, 3, 4, 5};
            foreach (int item in arr)
            {
                Console.WriteLine(item);
            }
        }
    }
}
