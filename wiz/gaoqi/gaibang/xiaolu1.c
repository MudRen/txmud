
inherit ROOM;

void create()
{
   set("short", "С·");
	set("long", @LONG
����С·1�������ǲݳ��������Ǹ�С���¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/wiz/gaoqi/gaibang/caochang.c",
  "south" : "/wiz/gaoqi/gaibang/tupo.c",
]));	setup();
}
