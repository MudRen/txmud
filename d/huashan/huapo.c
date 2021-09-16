// Room: /d/huashan/huapo.c

inherit ROOM;

void create()
{
	set("short", "滑坡");
	set("long", @LONG
这是一条向下的滑坡，脚下全是碎石和泥沙。不远处传来巨
大的水声。你不禁加快了脚步，向前走去。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"xiaolu8",
  "westup" : __DIR__"sl_dong",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
