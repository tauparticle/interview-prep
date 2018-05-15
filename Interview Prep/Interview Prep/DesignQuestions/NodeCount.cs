using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.DesignQuestions
{
    using System.Threading;

    public class NodeCounter
    {

        private long numOfRequests = 0;
        private AutoResetEvent waitEvent = new AutoResetEvent(false);
        private bool IsPinging = false;

        private Int32 numOnLeft = 0;
        private Int32 numOnRight = 0;

        private void PrintNumNodes()
        {
            // write code here to print out the number of nodes.
            var right = this.HasRight();
            var left = this.HasLeft();

            if (!right && !left)
            {
                Console.WriteLine("Number of nodes = 0");
                return;
            }
       
            this.IsPinging = true;
            if (this.HasLeft())
            {
                Interlocked.Increment(ref this.numOfRequests);
                this.SendMsgLeft(0);
            }
            if (this.HasRight())
            {
                Interlocked.Increment(ref this.numOfRequests);
                this.SendMsgRight(0);
            }

            this.waitEvent.WaitOne();
            this.IsPinging = false;

            Console.WriteLine("Number of nodes = " + this.numOnLeft + 1 + this.numOnRight);

        }

        private bool HasLeft()
        {
            /* returns true if there is a left node */
            throw new NotImplementedException();
        }

       
        private bool HasRight()
        {
            /* return true if there is a right node */
            throw new NotImplementedException();
        }

        

        private void SendMsgLeft(Object msg)
        {
            /* sends msg to the left node */
            Interlocked.Increment(ref this.numOfRequests);
        }

        private void SendMsgRight(Object msg)
        {
            /* sends msg to the right node */
           
        }

        private void ReceiveMsgFromRight(Object msg)
        {
            Int32 count = (Int32)msg;

            if (!this.IsPinging)
            {
                // someone else is pinging.  Pass the note to the left and
                // kick the count

                count++;
                if (this.HasLeft())
                {
                    this.SendMsgLeft(count);
                }
                else if (this.HasRight())
                {
                    // we're the end node, 
                    // send back right
                    this.SendMsgRight(count);
                }
            }
            else
            {
                // we're the node pinging.  Check if pending message count is zero and kick wait event
                this.numOnRight = count;

                if (Interlocked.Decrement(ref this.numOfRequests) == 0)
                {
                    this.waitEvent.Set();
                }
            }
        }

        private void ReceiveMsgFromLeft(Object msg)
        {
            Int32 count = (Int32)msg;

            if (!this.IsPinging)
            {
                // someone else is pinging.  Pass the note to the right and
                // kick the count
                count++;
                if (this.HasRight())
                {
                    this.SendMsgRight(count);
                }
                else if (this.HasLeft())
                {
                    // we're the end node, 
                    // send back left
                    this.SendMsgLeft(count);
                }
            }
            else
            {
                // we're the node pinging.  Check if pending message count is zero and kick wait event
                this.numOnLeft = count;
                
                if (Interlocked.Decrement(ref this.numOfRequests) == 0)
                {
                    this.waitEvent.Set();
                }
            }
        }
    }
}


           
