using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    using System.Collections;

    public static class CircularArrayTest
    {
        public static void Test()
        {
            CircularArray<string> ca = new CircularArray<string>(10);

            for (int i = 0; i < 10; ++i)
            {
                ca.set(i, i.ToString());
            }

            ca.rotate(3);

            ca.rotate(2);

            Console.Write("Circular array: ");
            for (int i = 0; i < 10; ++i)
            {
                Console.Write(ca.get(i) + ",");
            }
            Console.WriteLine("\n");

            Console.Write("Printing Iterator: ");

            foreach (string s in ca)
            {
                Console.Write(s + ",");
            }
            Console.WriteLine("\n");

        }

        /// <summary>
        /// Circular array with rotate and Iterator
        /// </summary>
        public class CircularArray<T> : IEnumerable
        {
            private T[] items;
            private int head = 0;

            public CircularArray(int size)
            {
                items = new T[size];
            }

            private int convert(int index)
            {
                if (index < 0)
                {
                    index += items.Length;
                }
                
                int i = (head + index) % items.Length;
                return i;
            }

            public void rotate(int shiftRight)
            {
                head = this.convert(shiftRight);
            }

            public T get(int i)
            {
                if (i < 0 || i > items.Length)
                {
                    throw new ArgumentOutOfRangeException();
                }

                return items[this.convert(i)];
            }

            public void set(int i, T item)
            {
                items[this.convert(i)] = item;
            }

            public IEnumerator GetEnumerator()
            {
                return new CircularArrayIterator<T>(this);
            }

            private class CircularArrayIterator<TI> : IEnumerator<TI>
            {
                private int current = -1;
                private TI[] items;
                private CircularArray<TI> a; 

                public CircularArrayIterator(CircularArray<TI> array)
                {
                    this.items = array.items;
                    this.a = array;
                    this.Reset();
                }

                public void Dispose() { }

                public bool MoveNext()
                {
                    return ++current < items.Count();
                }

                public void Reset()
                {
                    this.current = -1;
                }

                public TI Current { get; private set; }

                object IEnumerator.Current
                {
                    get
                    {
                        if (current == -1) return items[a.convert(a.head)];
                        if (0 <= current && current < items.Count()) return items[a.convert(current)];
                        return default(TI);
                    }
                }
            }
        }
    }
}


