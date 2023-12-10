#include <stdio.h>
#include <stdlib.h>

void decrypt(unsigned int *v, unsigned int *key, unsigned int round) {
    unsigned int l = v[0], r = v[1], sum = 0, delta = 0x88408067;
    sum = delta * round;
    for (size_t i = 0; i < round; i++) {
        sum -= delta;
        r -= (((l << 4) ^ (l >> 5)) + l) ^ (sum + key[(sum >> 11) & 3]);
        l -= (((r << 4) ^ (r >> 5)) + r) ^ (sum + key[sum & 3]) ^ sum;
    }
    v[0] = l;
    v[1] = r;
}

int main() {
    unsigned int v[11] = {0xADD4F778, 0xA6D7F132, 0x61813290, 0x2D4A40A6, 0x00B05F11, 0xB6D59424, 0x231BBFC6, 0xCD405B31, 0x03020100, 0x00C30504};
    unsigned int key[4] = {98, 111, 109, 98};

    for (int i = 0; i < 4; i++) {
        decrypt(v + i * 2, key, 33);
    }

    for (int i = 0; i < 8; i++) {
        printf("%c%c%c%c", *((char *) &v[i] + 0), *((char *) &v[i] + 1), *((char *) &v[i] + 2), *((char *) &v[i] + 3));
    }
    return 0;
}
//2d326e43eb8fea8837737fc0f50f83f2