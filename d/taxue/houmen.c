// houmen.c
// by dicky

#include <room.h>
inherit ROOM;

void create()
{
	set("short","踏雪山庄侧门");
	set("long",@LONG
这里是踏雪山庄的后侧门，后门上方有一块横匾，上书“踏雪山庄”四个大
字，匾的左右垂下两个大红灯笼。后门紧闭着，并且有踏雪山庄专门的弟子看
守，由于后山多野兽，所以没有经过允许，一般人是不允许随便出入。
LONG);

	set(SAFE_ENV, 1);

	set("exits",([
                "north" : __DIR__"xiaolu",
                "south":__DIR__"shilu6",         
	]));

	set("objects",([
		
	]));

	setup();
	replace_program(ROOM);
}

/*
int valid_leave(object me,string dir)
{
        if(dir == "north" || dir == "n")
                return notify_fail("山庄弟子挺身一拦说道：“没有经过特别允许，山庄弟子不得随便出去！”\n\n");
        else
                return ::valid_leave(me,dir);
}
*/
