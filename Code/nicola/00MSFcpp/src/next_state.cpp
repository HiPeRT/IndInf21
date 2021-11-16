int NextState(int table[3][3], int currentState, char input) {
    switch (input)
    {
        case 'a': return table[currentState][0];
        case 'b': return table[currentState][1];  
        case 'c': return table[currentState][2];
        default: return -1;
    }
}