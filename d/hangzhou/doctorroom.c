// Room: /d/hangzhou/doctorroom.c

inherit ROOM;

void create()
{
	set("short", "郎中家");
	set("long", @LONG
这是薛郎中的家，薛郎中也是杭州府有名的医生，特别的是
薛郎中治病从来不用药，全凭一副七寸银针，无论内伤外伤，针
到病去。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yongningn1",
]));

	set("objects",([
	__DIR__"npc/doctor" : 1,
]));

	setup();
	replace_program(ROOM);
}
