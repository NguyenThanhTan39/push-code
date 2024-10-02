using System;

using System.IO;
using System.Text;

namespace CS_Stream
{
    class Product
    {
        public int ID {set; get;}
        public double Price {set; get;}
        public string Name {set; get;}

        public void Save (Stream stream)
        {
            // đổi int về bit
            var byte_int = BitConverter.GetBytes(ID);
            stream.Write(byte_int, 0, 4);
            // đổi double về bit
            var byte_double = BitConverter.GetBytes(Price);
            stream.Write(byte_double, 0, 8);
            // đổi string về bit
            var byte_name = Encoding.UTF8.GetBytes(Name);
            var byte_length = BitConverter.GetBytes(byte_name.Length);
            stream.Write(byte_length, 0, 4);
            stream.Write(byte_name, 0, byte_name.Length);
        }
        public void Restore (Stream stream)
        {
            var byte_int = new byte[4];
            stream.Read(byte_int, 0, 4);
            this.ID = BitConverter.ToInt32(byte_int, 0);

            var byte_double = new byte[8];
            stream.Read(byte_double, 0, 8);
            this.Price = BitConverter.ToDouble(byte_double, 0);

            var byte_length = new byte[4];
            stream.Read(byte_length, 0, 4);
            int name_length = BitConverter.ToInt32(byte_length);
            var byte_name = new byte[name_length];
            stream.Read(byte_name, 0, name_length);
            this.Name = Encoding.UTF8.GetString(byte_name);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var path = "data.dat";
            //using var stream = new FileStream(path: path, FileMode.Create);
            using var stream = new FileStream(path: path, FileMode.Open);
            Product product = new Product();
            // {
            //     ID = 10,

            //     Price = 12.25,

            //     Name = "Thuoc tri hoi nach"
            // };

            //product.Save(stream);

            product.Restore(stream);
            Console.WriteLine($"{product.ID} - {product.Name} - {product.Price}");
        }
    }
}

