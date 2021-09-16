// citang.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "祠堂");
        set("long", @LONG
穿过后花园就来到祠堂内。那里是安放踏雪山庄历代列祖列宗灵位的地方
，桌椅都是甚为干净，看来经常有人来这里打扫。由于庄主告诫弟子，没有特
殊的事情，不要随便进出，所以很少有人来到这里。如果你感觉自己罪孽深重
，也可以来这里对着灵位(lingwei)进行忏悔(chanhui)。
LONG
        );
        	 
        set("exits", ([
               "south" : __DIR__"shilu4",               
        ]));

        setup();
	replace_program(ROOM);
}

void init()
{
	add_action("do_chanhui","chanhui");
}

int do_chanhui(string arg)
{
	object me = this_player();
	if(arg != "lingwei")
		return 0;

	write("你对着历代列祖列宗的灵位，开始忏悔自己生前的罪孽，身心都得到了净化。\n");
	if( me->query("bellicosity") > 0)
		me->add("bellicosity",-((me->query_int())*2+random(me->query_int())) );
	return 1;
}
