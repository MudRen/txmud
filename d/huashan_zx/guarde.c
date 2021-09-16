// Room: guarde.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "门房");
	set("long",@LONG
这里是华山派的门房，只有一个老道人住在这里，老人脾气
古怪，耳又背，没有什么人知道，或许是根本没有人想知道他的
来历。他只是晚上打打更，白天也没有什么事作。白天很难找到
他，你要是想找他不如晚上来。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"doorgd",
]));
	set("indoors", "huashan_p");
	set("objects", ([__DIR__"npc/guard":1 ]));
	setup();
	replace_program(ROOM);
}