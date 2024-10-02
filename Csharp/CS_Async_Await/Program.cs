using System;

using System.Threading.Tasks;

namespace CS_Async_Await
{
    class Program
    {
        static void DoSomeThing (int time, string name, ConsoleColor color)
        {
            lock (Console.Out)
            {
                Console.ForegroundColor = color;
                Console.WriteLine(name + "... Start!");
                Console.ResetColor();
            }
            for (int i=1; i<=time; i++)
            {
                lock (Console.Out)
                {
                    Console.ForegroundColor = color;
                    Console.WriteLine($"{i}---{name}");
                    Thread.Sleep(1000);
                    Console.ResetColor();
                }
            }
            lock (Console.Out)
            {
                Console.ForegroundColor = color;
                Console.WriteLine(name + "... End!");
                Console.ResetColor();
            }
        }
    static async Task task2()
    {
        Task t2 = new Task
        (
            () => 
            {
                DoSomeThing(time:10, name: "T2", ConsoleColor.Red);
            }
        );
        t2.Start();
        await t2;
        Console.WriteLine("T2 hoàn thành");
    }
    static async Task task3()
    {
        Task t3 = new Task
        (
            (object ob) =>
            {
                string ans = (string)ob;
                DoSomeThing(4,ans,ConsoleColor.Green);
            }
        , "T3");
        t3.Start();
        await t3;
        Console.WriteLine("T3 hoàn thành");
    }
        static Task<string> task4()
        {
            Task<string> t4 = new Task<string>
            (
                () => 
                {
                    DoSomeThing(8,"T4",ConsoleColor.Magenta);
                    return "T4 trả về";
                }
            );
            t4.Start();
            return t4;
        }
        static Task<string> task5()
        {
            Task<string> t5 = new Task<string>
            (
                (object ob) =>
                {
                    string ans = (string)ob;
                    DoSomeThing(7,ans,ConsoleColor.Yellow);
                    return "T5 trả về";
                }
            , "T5");
            t5.Start();
            return t5;
        }
        static async Task Main(string[] args)
        {
            Task t2 = task2();
            Task t3 = task3();
            Task<string> t4 = task4();
            Task<string> t5 = task5();
            DoSomeThing(6,"T1",ConsoleColor.Blue);
            Task.WaitAll(t2,t3,t4,t5);
            Console.WriteLine("Press any key: ");
            Console.ReadKey();
            var result4 = t4.Result;
            var result5 = t5.Result;
            Console.WriteLine($"result of T4:{result4}");
            Console.WriteLine($"result of T5:{result5}");
        }
    }
}
