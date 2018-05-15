using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.OOD.CardGame
{
    public class Hand<T> where T : Card
    {
        protected List<T> cards = new List<T>();

        public void AddCard(T card)
        {
            cards.Add(card);
        }

        public int Score()
        {
            int score = 0;
            foreach (T card in this.cards)
            {
                score += card.value();
            }
            return score;
        }
    }

    public class BlackJackHand : Hand<BlackJackCard>
    {
        public int score()
        {
            List<int> scores = possibleScores();
            int maxUnder = int.MinValue;
            int minOver = int.MaxValue;
            foreach (int score in scores)
            {
                if (score > 21 && score < minOver)
                {
                    minOver = score;
                }
                else if (score <= 21 && score > maxUnder)
                {
                    maxUnder = score;
                }
                
            }
            return maxUnder == int.MinValue ? minOver : maxUnder;
        }

        private List<int> possibleScores()
        {
            // figure out all possible scores for cards in hand against possible aces
            return new List<int>();
        }

        public bool busted()
        {
            return this.score() > 21;
        }

        public bool is21()
        {
            return this.score() == 21;
        }
    }
}
