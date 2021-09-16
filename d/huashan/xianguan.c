// Room: /d/huashan/xianguan.c

inherit ROOM;

void create()
{
	set("short", "通仙观");
	set("long", @LONG
这里是通仙观，据说处虚道长当年在此悟道通仙。处虚道长
俗名陈抟，据说当时皇帝多次诏他出山，他都没有接受。为了躲
避皇帝一诏再请，他就隐居在华山一个小山洞里。再向南面就是
西道院。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"w_daoguan",
  "northwest" : __DIR__"lvzu",
  "southeast" : __DIR__"huixin",
]));
        set("outdoors", "huashan");
        set("objects", ([__DIR__"npc/bird":1 ]));
	setup();
	replace_program(ROOM);
}
