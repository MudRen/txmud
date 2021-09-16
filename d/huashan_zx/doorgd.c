// Room: doorgd.c by pian
inherit ROOM;

void create()
{
	set("short", "前厅走廊");
	set("long",@LONG
踏进紫霞宫大门，这里是一个雕梁画柱的门廊，四下里洒扫
的极是干净。向北可以看见一座紫红色的影壁。东边是一间小小
的门房。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"yingbi",
	"south" : __DIR__"gongmen",
	"east" : __DIR__"guarde",
]));
	set("indoors", "huashan_p");
	setup();
	replace_program(ROOM);
}