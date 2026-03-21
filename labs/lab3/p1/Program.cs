using System;

namespace MyApp
{
    class Program
    {
        static void Main(string[] args) 
        {
            Console.WriteLine("Введите коэфиценты квадратного уравнения через пробел (a, b, c для ax^2+bx+c=0)");
            while (true)
            {
                string[] parts = Console.ReadLine().Split();
                if (parts.Length == 3 &&
                    int.TryParse(parts[0], out int a) &&
                    int.TryParse(parts[1], out int b) &&
                    int.TryParse(parts[2], out int c))
                {
                    Console.WriteLine($"Вы ввели: {a}, {b}, {c}");
                    int d = b * b - 4 * a * c;
                    if (d < 0)
                    {
                        Console.WriteLine("Уравнение решений не имеет");
                    }
                    else if (d == 0)
                    {
                        Console.WriteLine("Уравнение имеет единственное решение:");
                        double ans1 = (-b + Math.Pow(d, 0.5)) / 2;
                        Console.WriteLine($"x = {ans1}");
                    }
                    else
                    {
                        Console.WriteLine("Решения уравнения:");
                        double ans1 = (-b + Math.Pow(d, 0.5)) / 2;
                        double ans2 = (-b - Math.Pow(d, 0.5)) / 2;
                        Console.WriteLine($"x1 = {ans1}, x2 = {ans2}");
                    }
                    break;
                }
                else
                {
                    Console.WriteLine("Ошибка: нужно ввести ровно три целых числа через пробел.");
                }
            }
        }
    }
}