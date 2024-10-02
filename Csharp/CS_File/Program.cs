using System;

using System.IO;

namespace CS_File
{
    class Program
{
    static void Main(string[] args)
    {
        // Lớp DriveInfo để lấy thông tin về một hoặc nhiều ổ đĩa.
        #region 
        // var drives = DriveInfo.GetDrives();

        // foreach(var drive in drives)
        // {
        //     Console.WriteLine("Drive's name: {0}",drive.Name);
        //     Console.WriteLine("Drive's type: {0}",drive.DriveType);
        //     if (drive.IsReady)
        //     {
        //         Console.WriteLine("Volume label: {0}",drive.VolumeLabel);
        //         Console.WriteLine("File system: {0}",drive.DriveFormat);
        //         Console.WriteLine("Available space to curent user: {0,15} bytes", drive.AvailableFreeSpace);
        //         Console.WriteLine("Total available space: {0,15} bytes", drive.TotalFreeSpace);
        //         Console.WriteLine("Total size of drive: {0,15} bytes", drive.TotalSize);
        //         Console.WriteLine("///////////////////////////////////////////////////");
        //     }
        // }
        #endregion
        // Lớp Directory chứa các phương thức tĩnh (static)để làm việc với thư mục
        #region 
        // string path = "Abc";

        // Directory.CreateDirectory(path);

        // if (Directory.Exists(path))
        // {
        //     Console.WriteLine("Co ton tai");
        // }
        // else 
        // {
        //     Console.WriteLine("Khong ton tai");
        // }
        // Console.ReadKey();
        // Directory.Delete(path);
        #endregion
        // Lớp Path đường dẫn files
        #region 
        // Console.WriteLine(Path.DirectorySeparatorChar);

        // Console.Clear();

        // var path = Path.Combine("Dir1","Dir2","NguyenTan.txt");

        // // đổi phần mở rộng "txt" thành "md"

        // var path1 = Path.ChangeExtension(path,"md");

        // Console.WriteLine(path);

        // Console.WriteLine(path1);
        #endregion
        // Lớp File chứa 1 số phương thức tĩnh (static) giúp chúng ta làm việc với file (xoá, tạo, đọc file, v.v)
        #region

        if (File.Exists("abc.txt")) File.Delete("abc.txt");
            
        if (File.Exists("123.txt"))  File.Delete("123.txt");

        string filename = "abc.txt";

        string content = "Xin chao moi nguoi, toi ten la Tan";

        File.WriteAllText(filename, content);

        string take = File.ReadAllText(filename);

        Console.WriteLine(take);

        File.Move(filename, "123.txt");

        File.Delete("123.txt");

        #endregion

    }
}
}


