First aim of the program is to pack string variable into compressed version. When string of letters is repetead in string variable, program puts it into squared brackets and give number of repetition before them. It's possible to put any number of brackets inside other ones as well as put them next to themselves. It's assumed that there's no element of input string, which is a number. Examples:

Input: abcbcbcbcabcbcbcbcabcbcbcbc
Output: 3[a4[bc]]
Input: 2[the]3[string]
Output: thethestringstringstring

Second function of the program is to unpack string variable from format given above. It reverse action of packing function assuming that format of input is correct (no incomplete brackets and no numbers which aren't number of repetition).