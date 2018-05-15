using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.OOD.CardGame
{
    public enum Suit
    {
        Spade, 
        Hearts,
        Diamonds,
        Clubs,
    }

    public abstract class Card
    {
        public bool Available { get; set; }
        public Suit Suit { get { return this._suit; } }
        protected int _faceValue;
        protected Suit _suit;

        public Card(int value, Suit suit)
        {
            this.Available = false;
            this._faceValue = value;
            this._suit = suit;
        }

        public abstract int value();
    }

    public class BlackJackCard : Card
    {
        public BlackJackCard(int value, Suit suit) : base(value, suit)
        {
            
        }

        public bool isAce()
        {
            return this._faceValue == 1;
        }

        public int minValue()
        {
            if (this.isAce()) return 1;
            else return this.value();
        }

        public int maxValue()
        {
            if (this.isAce()) return 11;
            else return this.value();
        }

        public override int value()
        {
            if (this.isAce()) return 1;
            else if (this._faceValue >= 11 && this._faceValue <= 13) return 10;
            else return this._faceValue;
        }
    }
}
