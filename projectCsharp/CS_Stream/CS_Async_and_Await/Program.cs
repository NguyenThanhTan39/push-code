using System;

using System.Net;

using System.Threading;

using System.Threading.Tasks;

namespace CS_Async_and_Await
{
    class Program
    {
        /* asynchronous là lập trình ra những ứng dụng có khả năng 
        chạy đa luồng */
        static void DoSomeThing(int scd, string msg, ConsoleColor color)
        {
            lock (Console.Out)
            {
                Console.ForegroundColor = color;

                Console.WriteLine($"{msg, 10} ...Start");

                Console.ResetColor();
            }

           for (int i=1; i<= scd; i++)
           {
                lock (Console.Out)
                {
                    Console.ForegroundColor = color;

                    Console.WriteLine($"{msg, 10} {i, 2}");

                    Console.ResetColor(); 
                }
                Thread.Sleep(1000);
           }
           lock (Console.Out)
           {
                Console.ForegroundColor = color;

                Console.WriteLine($"{msg, 10} ...End");

                Console.ResetColor();
           }
        }
        static Task task2()
        {
            Task t2 = new Task(
                () => {
                    DoSomeThing(10, "T2", ConsoleColor.Green);
                }
            );
            t2.Start();
            return t2;
        }
        static Task task3()
        {
            Task t3 = new Task(
                (object ob) => {
                    string Tentacvu = (string)ob;
                    DoSomeThing(4, Tentacvu, ConsoleColor.Red);
                }
            , "T3");
            t3.Start();
            return t3;
            
        }
        static async Task<string> GetWeb(string url)
        {
            HttpClient httpclient = new HttpClient();

            HttpResponseMessenge kq = await httpclient.GetAsync(url);

            string content = await kq.Content.ReadAsStringAsync();
            
            return content;
        }
        static void Main(string[] args)
        {
            // task2.Start();

            // task3.Start();  

            // Task t2 = task2();

            // Task t3 = task3();

            var task = GetWeb("http://youtube.com");

            DoSomeThing(6, "T1", ConsoleColor.Yellow);

            //Task.WaitAll(t2,t3);

            // Console.WriteLine("Hello, World!");

            var content = await task;

            Console.WriteLine(content);

            Console.ReadKey();
        }
    }  
}


