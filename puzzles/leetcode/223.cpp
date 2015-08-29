/***************
Rectangle Area：https://leetcode.com/problems/rectangle-area/

Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
**/

//time complexity: O(1)
//space complexity: O(1)
//2A : not understanding clearly of the puzzles caused the first failure
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int cover, total;
    if (C <= E || G <= A || D <= F || H <= B) {
        cover = 0;
    } else {
        int xL = max(A, E);
        int xR = min(C, G);
        int yB = max(B, F);
        int yT = min(D, H);
        
        cover = (xR - xL) * (yT - yB);
    }
        
    total = (C-A) * (D -B) + (G-E) * (H -F);
    return total - cover;
}
