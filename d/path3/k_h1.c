// Room: /d/path3/k_h1.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条黄土铺成的官道，路上喷洒了不少的清水，街上十
分热闹，卖冰糖葫芦的、打风车的、卖花生米的四处都是。你得
不时闪躲着，才能向前。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"k_h2",
  "west" : "/d/kaifeng/out_kaifeng_e",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
