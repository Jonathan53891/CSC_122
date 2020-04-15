
/*
// choices
0 - use character
1 - frame, single line
2 - frame, single line, shaded
3  frame, double line
4 frame, double line , shaded

// framing with character

if (f.align == 'L')
{
    out << string(width + 4, f.frame_ch) << endl;
    for (str_type i = 0; i < height; i++)
    {
        out << f.frame_ch << ' ' << setw(width) << left << f.word_list[i];
        out << ' ' << f.frame_ch << endl;
    }
    out << string(width + 4, f.frame_ch) << endl;

}
else if (f.align == 'C')
{
    out << string(width + 4, f.frame_ch) << endl;
    size_t padding_L, padding_R;
    for (str_type i = 0; i < height; i++)
    {
        size_t word_length = f.word_list[i].length();
        padding_L = (width - word_length) / 2;
        padding_R = width - word_length - padding_L;
        out << f.frame_ch << ' ' << string(padding_L, ' ');
        out << f.word_list[i] << string(padding_R, ' ');
        out << ' ' << f.frame_ch << endl;
    }
    out << string(width + 4, f.frame_ch) << endl;

}
*/