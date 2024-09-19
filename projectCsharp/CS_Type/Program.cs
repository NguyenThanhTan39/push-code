using System;
using System.Reflection;
using ChoViDu;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;

namespace CS_Type
{
    [AttributeUsage(AttributeTargets.Class | AttributeTargets.Property | AttributeTargets.Method)]
    class MotaAttribute : Attribute
    {
        public string Notice {set; get;}
        public MotaAttribute(string Notice)
        {
            this.Notice = Notice;
        }
    }
    [MotaAttribute("Lớp biểu diễn người dùng")]
    class User
    {
        [MotaAttribute("Thuộc tính lưu tên")]
        public string Name {set; get;}
        [MotaAttribute("Thuộc tính lưu tuổi")]
        public int Age {set; get;}
        [MotaAttribute("Thuộc tính lưu số điện thoại")]
        public string PhoneNumber {set; get;}
        [MotaAttribute("Thuộc tính lưu email")]
        public string Email {set; get;}
    }
    class Program
    {
        static void Main(string[] args)
        {
            User user = new User(){
                Name = "Nguyễn Thanh Tân",
                Age = 20,
                PhoneNumber = "1234567890",
                Email = "Example@gmail.com"
            };
            foreach (var attr in user.GetType().GetCustomAttributes(false))
            {
                MotaAttribute mota = attr as MotaAttribute;
                if (mota!=null) Console.WriteLine($"{mota.GetType().Name}: {mota.Notice}");
            }
            foreach (var property in user.GetType().GetProperties())
            {
                foreach (var attr in property.GetCustomAttributes(false))
                {
                    MotaAttribute mota = attr as MotaAttribute;
                    if (mota!=null) Console.WriteLine($"{property.Name, 13}: {mota.Notice}");  
                }
            }
            Profile  profiles = new Profile()
            {
                Name = "Ta",
                Age = 10,
                PhoneNumber = "010101",
                Email = "nguyenthanhtan"
            };
            ValidationContext context = new ValidationContext(profiles, null, null);
            List<ValidationResult> results = new List<ValidationResult>();
            bool valid = Validator.TryValidateObject(profiles,context,results,true);
            if (!valid)
            {
                foreach (var vr in results)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.Write($"{vr.MemberNames.First(), 13}: ");
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.WriteLine($"{vr.ErrorMessage}");
                }
            }
        }
    }
}