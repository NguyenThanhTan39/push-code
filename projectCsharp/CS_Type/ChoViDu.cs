using System;
using System.Reflection;
using System.ComponentModel.DataAnnotations;

namespace ChoViDu
{
    public class Profile
    {
        [Required(ErrorMessage = "profile {0} is required")]
        [StringLength(100, MinimumLength  = 3, ErrorMessage = "Tên phải từ 3 đến 100 kí tự")]
        [DataType(DataType.Text)]
        public string Name {set; get;}
        [Range(18, 99, ErrorMessage = "Age phải từ 18 đến 25 tuổi")]
        public int Age {set; get;}
        [DataType(DataType.PhoneNumber)]
        public string PhoneNumber {set; get;}
        [DataType(DataType.EmailAddress)]
        [EmailAddress]
        public string Email {set; get;}
    }
}

