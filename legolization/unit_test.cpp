//
// Created by Bijoy Kochar on 3/26/16.
//

#include "LegoBlock.h"
#include "LegoBlockUtils.h"
#include "LegoBlockGraph.h"

void setToSphere(short ***image, short sx, short sy, short sz, short max_value, short r) {
    for (int i = 0; i < sx; i++) {
        for (int j = 0; j < sy; j++) {
            for (int k = 0; k < sz; k++) {
                float value = (i - (sx / 2)) * (i - (sx / 2)) + (j - (sy / 2)) * (j - (sy / 2)) +
                              (k - (sz / 2)) * (k - (sz / 2));
                value = sqrt(value);
                value = max_value * (value / r);

                if (value > max_value)
                    image[i][j][k] = -2;
                else if (value <= max_value / 2)
                    image[i][j][k] = -1;
                else
                    image[i][j][k] = (short) value;
            }
        }
    }
}

void setValue(short ***image, short sx, short sy, short sz, short value) {
    for (int i = 0; i < sx; i++) {
        for (int j = 0; j < sy; j++) {
            for (int k = 0; k < sz; k++) {
                image[i][j][k] = (short) value;
            }
        }
    }
}

short ***getImageMatrix(short sx, short sy, short sz) {
    srand(time(NULL));
    short ***image = new short **[(int) sx];
    for (int i = 0; i < sx; i++) {
        image[i] = new short *[(int) sy];
        for (int j = 0; j < sy; j++) {
            image[i][j] = new short[(int) sz];
        }
    }

    return image;
}


int main() {
    short size = 40;
    short sx = size, sy = size, sz = size, max_value = 4;
    short ***r = getImageMatrix(sx, sy, sz);
    short ***g = getImageMatrix(sx, sy, sz);

    setToSphere(r, sx, sy, sz, max_value, 16);
    setValue(g, sx, sy, sz, 0);

    LegoBlockGraph graph;
    graph.add_blocks(r, g, g, sx, sy, sz);

    /*
    ofstream fout;
    fout.open("triangles.txt");
    fout << triangles.size() << endl;
    for (Triangle triangle : triangles) {
        triangle.print(fout);
    }
    fout.close();
     */
}
