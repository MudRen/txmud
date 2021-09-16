// Room: /d/huashan/dongfeng.c

inherit ROOM;

void create()
{
	set("short", "东峰");
	set("long", @LONG
这里就是华山的东峰，也是也叫做朝阳峰，是华山观日出的
最佳山峰。在东崖上，有一块形如手掌的石壁，据说是巨灵神留
下的手印。四周地上开满了野花。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"shanquan",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
