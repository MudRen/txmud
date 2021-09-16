// bingqi.c  ±øÆ÷ÆÌ

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "Àî¼Ç±øÆ÷ÆÌ");
        set("long", @LONG
Àî¼Ç±øÆ÷ÆÌÊÇãë´¨×ÖºÅ×îÀÏµÄ±øÆ÷ÆÌÁË£¬Ç½ÉÏ¹ÒÂúÁË¸÷Ê½¸÷
ÑùµÄ±øÆ÷£,±øÆ÷ÆÌµÄÀîÀÏ°åÕıÔÚ¹ñÌ¨ºóÃæ¿´Êé£¬Ò»¼ûÄã½øÀ´£¬Âí
ÉÏ·ÅÏÂÊé£¬Ğ¦ÃĞÃĞµÄÓ­ÁËÉÏÀ´¡£
LONG
        );

        set("night_long", @LONG
Àî¼Ç±øÆ÷ÆÌÊÇãë´¨×ÖºÅ×îÀÏµÄ±øÆ÷ÆÌÁË£¬Ç½ÉÏ¹ÒÂúÁË¸÷Ê½¸÷
ÑùµÄ±øÆ÷£,²»¹ıÕâÀïÒÑ¾­´òìÈÁË£¬±øÆ÷ÆÌµÄÀîÀÏ°åÕıÔÚ¹ñÌ¨ºóÃæ
ÄÃ×ÅÕÊ±¾ËãÕÊ¡£
LONG
        );

       set("exits", ([
		"west" : __DIR__"shilu",
           ]));

	set("no_sleep_room",1);

	set("objects",([
//	__DIR__"npc/xxxx" : 1,
           ]));

        setup();
}

/*void open_close_door(string msg,object user)
{
	object ob = present("xxxx",this_object());

	if(!msg || !user)
		return;
	if( msg == "begain_day")
	{
		if(ob)
			tell_object(user,CYN"xxx"+
			RANK_D->query_respect(user)+"xxx¡£\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"¿ªÊ¼ÓªÒµÁË¡£\n"NOR);
		return;
	}

	else if( msg == "begain_night")
	{
		if(ob)
			tell_object(user,CYN"xxxxxÕâÎ»"+
			RANK_D->query_respect(user)+"¶Ô²»Æğ£¬Ğ¡ºÅ´òìÈÁË£¬ÇëÄúÃ÷ÌìÔÙÀ´°É¡£\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"´òìÈÁË¡£\n"NOR);
		return;
	}
}
*/