// more.c

#include <ansi.h>

void remove_more_lable(); // by Find.

void more(string cmd, string *text, int line)
{
	int i;

	switch(cmd)
	{
		case "":
			if(line) remove_more_lable();
			for(i=line + 23; line<sizeof(text) && line<i; line++)
				write(text[line] + "\n");
			if( line>=sizeof(text) ) return;
			break;

		case "b":
			remove_more_lable();
			line = line - 46;
			if(line<-22) return;
			for(i=line + 23; line < i;line++)
				write(text[line]+"\n");
			break;

		case "q":
			remove_more_lable();
			return;
			break;
		default:
			remove_more_lable();
	}
	printf(WHT+"== δ����� "+HIY+"%d%%"+NOR+WHT+" == [ENTER ������һҳ��q �뿪��b ǰһҳ]"+NOR,
		(line*100/sizeof(text)) );
	input_to("more", text, line);
}

// Modified by Find.
void remove_more_lable()
{
	printf(CUP(1)+DELLINE);
}
// end.

void start_more(string msg)
{

// added by find.
        if(!msg)
                return;
// end.

	more("", explode(msg, "\n"), 0);
}
