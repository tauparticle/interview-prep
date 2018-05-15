using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class ShuffleDeck
    {
        public static void Test()
        {
            int[] deck = new int[52];
            Console.Write("Original Deck:");
            for (int i = 0; i < 52; ++i)
            {
                Console.Write(i + ",");
                deck[i] = i;
            }
            Console.WriteLine("\n");

            Shuffle(deck);
            Console.Write("Shuffled Deck:");
            for (int i = 0; i < 52; ++i)
            {
                Console.Write(deck[i] + ",");
            }
            Console.WriteLine("\n");

            Shuffle(deck);
            Console.Write("ReShuffled Deck:");
            for (int i = 0; i < 52; ++i)
            {
                Console.Write(deck[i] + ",");
            }
            Console.WriteLine("\n");



        }
        public static void Shuffle(int[] deck)
        {
            Random rand = new Random();
            int index = 0;
            int temp = 0;
            while (index < deck.Length)
            {
                int pivot = rand.Next(index, deck.Length);
                temp = deck[pivot];
                deck[pivot] = deck[index];
                deck[index] = temp;
                index++;
            }
        }
    }
}
