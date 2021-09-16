// semote.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping emote;
	string *e;
	string result,msg;
	int i;

	if( !arg )
	{
		e = sort_array(EMOTE_D->query_all_emote(), 1);

		result = "";
		for(i=0; i<sizeof(e); i++)
			result = result + sprintf("%-15s%s", e[i], (i%5==4)?"\n": "");
		result += "\n";
		me->start_more(result);
		return 1;
	}

	else
	{ 
		if(arg!="all")
		{
			emote = EMOTE_D->query_emote(arg);
			msg="";
			if(emote["myself"]==0)
				msg=msg+RED+"myself       :ц╩сп\n"+CYN;else msg=msg+CYN+"myself       :"+emote["myself"];
			if(emote["others"]==0)
				msg=msg+RED+"others       :ц╩сп\n"+CYN;else msg=msg+CYN+"others       :"+emote["others"];
			if(emote["myself_self"]==0)
				msg=msg+RED+"myself_self  :ц╩сп\n"+CYN;else msg=msg+CYN+"myself_self  :"+emote["myself_self"];
			if(emote["others_self"]==0)
				msg=msg+RED+"others_self  :ц╩сп\n"+CYN;else msg=msg+CYN+"others_self  :"+emote["others_self"];
			if(emote["myself_target"]==0)
				msg=msg+RED+"myself_target:ц╩сп\n"+CYN;else msg=msg+CYN+"myself_target:"+emote["myself_target"];
			if(emote["target"]==0)
				msg=msg+RED+"target       :ц╩сп\n"+CYN;else msg=msg+CYN+"target       :"+emote["target"];
			if(emote["others_target"]==0)
				msg=msg+RED+"others_target:ц╩сп\n"+CYN;else msg=msg+CYN+"others_target:"+emote["others_target"];
			printf(RED"=======================THIS EMOTE IS %s===========================\n"NOR,arg);
			printf(CYN"%s"NOR,msg);
			return 1;
		}

		else
		{
		return 0;
			e = sort_array(EMOTE_D->query_all_emote(), 1);
			result = "";
			for(i=0; i<sizeof(e); i++)
			{
				emote = EMOTE_D->query_emote(e[i]);   
				msg="";
				if(emote["myself"]==0)
					msg+=RED+"myself       :ц╩сп\n"+CYN;else msg+=CYN+"myself       :"+emote["myself"];
				if(emote["others"]==0)
					msg+=RED+"others       :ц╩сп\n"+CYN;else msg+=CYN+"others       :"+emote["others"];
				if(emote["myself_self"]==0)
					msg+=RED+"myself_self  :ц╩сп\n"+CYN;else msg+=CYN+"myself_self  :"+emote["myself_self"];
				if(emote["others_self"]==0)
					msg+=RED+"others_self  :ц╩сп\n"+CYN;else msg+=CYN+"others_self  :"+emote["others_self"];
				if(emote["myself_target"]==0)
					msg+=RED+"myself_target:ц╩сп\n"+CYN;else msg+=CYN+"myself_target:"+emote["myself_target"];
				if(emote["target"]==0)
					msg+=RED+"target       :ц╩сп\n"+CYN;else msg+=CYN+"target       :"+emote["target"];
				if(emote["others_target"]==0)
					msg+=RED+"others_target:ц╩сп\n"+CYN;else msg+=CYN+"others_target:"+emote["others_target"];
				result = result + sprintf(RED"=======================THIS EMOTE IS %s===========================\n"NOR,e[i])+CYN+msg;
			}
			result += "\n";
			me->start_more(result);
			return 1;
		}
	}

}

int help(object me)
{
  write(@HELP
ж╦аН╦Яй╫ : semote    апЁЖд©г╟кЫдэй╧сц╣дкЫспemote.

ж╦аН╦Яй╫ : semote all  апЁЖд©г╟кЫдэй╧сц╣дкЫспemote ╟Эю╗цХйЖ.
 [1;31m (в╒рБсисзо╣мЁнйлБц╩спльйБр╙гС╡╩р╙юосцуБ╦ЖцЭаН) [2;37;0m

ж╦аН╦Яй╫ : semote <emote>   отй╬рясп╣дemote. фДжп:

$N ╠Мй╬вт╪╨╣дцШвж║ё
$n ╠Мй╬й╧сц╤тоС╣дцШвж║ё
$P ╠Мй╬вт╪╨╣дхкЁф╢ЗцШ╢йё╛хГдЦ║╒кШ║╒кЩ║╒кЭ║╒кЭ║ё
$p ╠Мй╬й╧сц╤тоС╣дхкЁф╢ЗцШ╢йё╛хГдЦ║╒кШ║╒кЩ║╒кЭ║╒кЭ║ё

ц©╦Жemoteфъ╬Д╩╟╣дкЁпРн╙ё╨
1). ╡╩ж╦╤╗╤тоСй╧сцуБ╦Ж emote й╠ё╛дЦвт╪╨©╢╣╫╣дя╤о╒
2). ╡╩ж╦╤╗╤тоСй╧сцуБ╦Ж emote й╠ё╛фДкШхк©╢╣╫╣дя╤о╒ё╨
3). ╤твт╪╨й╧сцуБ╦Ж emote й╠ё╛вт╪╨©╢╣╫╣дя╤о╒
4). ╤твт╪╨й╧сцуБ╦Ж emote й╠ё╛фДкШхк©╢╣╫╣дя╤о╒
5). ╤т╠Пхкй╧сцуБ╦Ж emote й╠ё╛вт╪╨©╢╣╫╣дя╤о╒
6). ╤т╠Пхкй╧сцуБ╦Ж emote й╠ё╛й╧сц╤тоС©╢╣╫╣дя╤о╒
7). ╤т╠Пхкй╧сцуБ╦Ж emote й╠ё╛фДкШхк©╢╣╫╣дя╤о╒

HELP
    );
    return 1;
}
