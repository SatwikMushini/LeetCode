class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int cx = max(x1, min(x2, xc)); // closest x cordinate to xc
        int cy = max(y1, min(y2, yc)); // closest y cordinate to yc

        return (cx - xc) * (cx - xc) + (cy - yc) * (cy - yc) <= r * r;
    }
};