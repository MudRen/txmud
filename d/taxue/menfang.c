// menfang.c  门房
// by dicky

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","踏雪山庄大门");
	set("long",
HBBLU+HIR"\n                     踏雪山庄                           \n\n"NOR
"    这里是踏雪山庄的大门，大门两侧耸立着两头青石狮子。大门上方有一\n"
"块横匾，上书“踏雪山庄”四个大字，匾的左右垂下两个大红灯笼。大门敞\n"
"开着。可惜，门外是万丈悬崖，悬崖中雾气腾腾，真不知道主人为什么在这\n"
"儿开了一个门，而且还有灯笼。\n"
);

	set("exits",([
                "enter" : __DIR__"huayuan",
                "south":__DIR__"kongdi",         
	]));

	set("objects",([
		
	]));
	setup();
	replace_program(ROOM);
}
