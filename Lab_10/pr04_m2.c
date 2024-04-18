#include<stdio.h>
#include<string.h>

int find_next_state(char *pattern, int cur_state, int character) {
    int pattern_len = strlen(pattern);

	if( cur_state<pattern_len && character==pattern[cur_state] )
		return cur_state+1;

	for( int nextState=cur_state, i=0;nextState>0;nextState-- ) {
		if( pattern[nextState-1]==character ) {
			for( i=0;i<nextState-1;i++ ) {
				if( pattern[i]!=pattern[cur_state-nextState+i+1])
					break;
            }
			if( i==nextState-1 )
				return nextState;
		}
	}
	return 0;
}

int my_finite_automata_algo(char *pattern, char *text, int char_len) {
	int pattern_length = strlen(pattern);
	int text_length = strlen(text);

	int tr_table[pattern_length+1][char_len];
	for( int cur_state=0;cur_state<=pattern_length;cur_state++ )
		for( int character=0;character<char_len;character++ )
			tr_table[cur_state][character] = find_next_state(pattern, cur_state, character);

	int cur_state = 0;
	for( int i=0;i<text_length;i++ ) {
		cur_state = tr_table[cur_state][text[i]];
		if( cur_state==pattern_length ) {
            return i-pattern_length+1;
        }
	}
    return -1;
}

int main() {
	char *text = "ccaccadaaebbaaa";
    int char_len = 256;
	char *pattern = "dba";

	int index = my_finite_automata_algo(pattern, text, char_len);

    printf("Text : %s\n", text);
    printf("Pattern : %s\n", pattern);
    if( index!=-1 )
        printf("Pattern found at index : %d\n", index+1);
    else
        printf("Pattern Not found\n");
	return 0;
}
