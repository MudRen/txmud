// Room: /d/changan/gaibang.c

inherit ROOM;

void create()
{
	set("short", "侧殿");
	set("long", @LONG
这里是破落大院的厢房，此时却是丐帮的长安分舵。丐帮一
度是江湖上第一大帮派，门徒遍及四海，可是谁也想不到长安的
分舵，竟会在这个破旧的大宅内，不远处，有几个丐帮弟子，懒
洋洋的晒着太阳，不时的用眼角撇着你。东面便是破落大院的正
院了。
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"badroom",
]));

	setup();
	replace_program(ROOM);
}
