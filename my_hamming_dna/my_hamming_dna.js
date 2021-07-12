function my_hamming_dna(dna1, dna2) {
    if (dna1.length != dna2.length) {
        return -1;
    }
    else {
        count = 0;
        for (i = 0; i < dna1.length; i++) {
            if (dna1[i] != dna2[i]) {
                count++;
            }
        }
        return count;
    }
}