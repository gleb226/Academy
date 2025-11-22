// namespace DZ2;
//
// internal class task1
// {
//     static void Main()
//     {
//         Random rand = new Random();
//         int[] A = new int[5];
//         float[,] B = new float[3, 4];
//
//         for (int i = 0; i < 5; i++)
//         {
//             Console.Write($"Enter number {i + 1}: ");
//             A[i] = int.Parse(Console.ReadLine());
//         }
//
//         for (int i = 0; i < B.GetLength(0); i++)
//         {
//             for (int j = 0; j < B.GetLength(1); j++)
//             {
//                 B[i, j] = rand.Next(100);
//             }
//         }
//
//         Console.WriteLine("Array A:");
//         Console.WriteLine(string.Join(", ", A));
//
//         Console.WriteLine("Array B:");
//         for (int i = 0; i < B.GetLength(0); i++)
//         {
//             for (int j = 0; j < B.GetLength(1); j++)
//             {
//                 Console.Write(B[i, j] + " ");
//             }
//             Console.WriteLine();
//         }
//
//         float max = A[0];
//         float min = A[0];
//         float sum = 0;
//         float product = 1;
//         float sumEvenA = 0;
//         float sumOddColumns = 0;
//
//         foreach (int x in A)
//         {
//             if (x > max) max = x;
//             if (x < min) min = x;
//             sum += x;
//             product *= x;
//             if (x % 2 == 0) sumEvenA += x;
//         }
//
//         for (int i = 0; i < B.GetLength(0); i++)
//         {
//             for (int j = 0; j < B.GetLength(1); j++)
//             {
//                 if (B[i, j] > max) max = B[i, j];
//                 if (B[i, j] < min) min = B[i, j];
//                 sum += B[i, j];
//                 product *= B[i, j];
//                 sumOddColumns += B[i, j];
//             }
//             Console.WriteLine($"Max element: {max}");
//             Console.WriteLine($"Min element: {min}");
//             Console.WriteLine($"Sum: {sum}");
//             Console.WriteLine($"Product: {product}");
//             Console.WriteLine($"Sum of even elements: {sumEvenA}");
//             Console.WriteLine($"Sum of odd columns: {sumOddColumns}");
//         }
//     }
// }