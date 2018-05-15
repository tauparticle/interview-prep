using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ManagedInterviewPrep
{
    class Program
    {
        static void Main(string[] args)
        {
            var wb = new WordBreak();
            var result = wb.BreakString("abear", WordBreakHelper.GenerateDictionary());
            Console.WriteLine(result);
            Console.ReadKey();
        }
    }
}
