// Room: /d/hangzhou/linhouse.c

inherit ROOM;

void create()
{
	set("short", "林员外府");
	set("long", @LONG
这里是杭州府最大的财主林员外的府第门口，汉白玉的石阶
，红漆大门两旁蹲着两只狰狞的石狮子，门里隐隐传来阵阵马嘶。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"yongningn2",
  "east" : __DIR__"linyuanzi",
]));

	set("objects",([
	__DIR__"npc/jiading" : 2,
]));

	setup();
	replace_program(ROOM);
}
