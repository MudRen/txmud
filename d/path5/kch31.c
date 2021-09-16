// Room: /d/path5/kch31.c

inherit ROOM;

void create()
{
	set("short", "青城山顶峰");
	set("long", @LONG
你终于爬山了青城山顶峰。但见青山削翠，碧岫堆云。山间
流水潺漫，涧内声声鸣玉佩。若非道侣修行，定有仙翁炼药。忽
一片白云浮过，弄得你上半身湿露露的，你毫不在意的用袖子抹
了抹脸。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"kch30",
  "southdown" : __DIR__"kch32",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
