using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.OOD.CardGame
{
    public class Deck<T> where T : Card
    {
        private List<T> cards = new List<T>();
        private int deltIndex = 0;


        public void SetDeck(IEnumerable<T> deck)
        {
            this.cards.AddRange(deck);
        }

        public T[] DealHand(int numCards)
        {
            T[] deltCards = new T[numCards];
            for (int i = 0; i < numCards && this.deltIndex < cards.Count; ++i)
            {
                deltCards[i] = this.cards[deltIndex++];
            }
            return deltCards;
        }

        public T DealCard()
        {
            return this.cards[this.deltIndex++];
        }

        public int CardsRemaining()
        {
            return this.cards.Count - this.deltIndex;
        }


        public void Shuffle()
        {
            // shuffle the deck
        }
    }
}
