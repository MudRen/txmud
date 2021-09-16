// Room: /d/huanggong/yuhy.c

inherit ROOM;

void create()
{
        set("short", "御花园");
        set("long", @LONG
这里就是天下闻名的御花园，里面几乎汇集了人间所有的名
花、异草，每当踏进园门就使人有一种心旷神怡的感觉，举目望
去，园中盛开着千姿百态的洛阳牡丹，猛然间，你闻到一股沁人
心脾的幽香，不禁回头望去，哇！好大的一株百合花，娇艳欲滴
。从这里向西就是御景亭了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yanhg",
  "west" : __DIR__"taihjs",
  "south" : __DIR__"kunng",
  "north" : __DIR__"qinad",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");
	setup();
	replace_program(ROOM);
}