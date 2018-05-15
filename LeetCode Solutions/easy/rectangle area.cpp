/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        
        //one top >= another bottom, one left >= another right
        if(A>=G || E>=C || B>=H || F>=D){return area1 + area2;}
        
        // min left - max right, min up - max bottom.
        return area1 + area2 - (min(C,G) - max(A,E))*(min(D,H) - max(B,F));
    }
};