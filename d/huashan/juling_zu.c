// Room: /d/huashan/juling_zu.c

inherit ROOM;

void create()
{
	set("short", "巨灵足");
	set("long", @LONG
陟峭的山壁上隐约显出一个巨大的足印，这里就是有名的巨
灵足了。到了这里，离华山的西峰已经不远了。不时有白云从你
头顶漂过，你不禁想休息一下，还是先吃点喝点吧。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xiaolu4",
  "southdown" : __DIR__"xiaolu3",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
