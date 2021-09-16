// Room: /d/huashan/lvzu.c

inherit ROOM;

void create()
{
	set("short", "吕祖殿");
	set("long", @LONG
吕祖殿是道士们祭拜仙人的地方，供奉的三清像前面，摆放
着一个香案。殿内清烟缭绕，似真有神灵其间游荡。穿过此殿，
就到了三息台。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"santai",
  "southeast" : __DIR__"xianguan",
]));
	
	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
