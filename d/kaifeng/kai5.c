// Room: /wiz/louth/k/kai5.c

inherit ROOM;

void create()
{
	set("short", "天虹武场");
	set("long", @LONG
这里是开封府的天虹武场，武场的主人叫柳传志，是一位江
湖中大大有名的拳师。这位拳师当年只凭着一双铁拳便打遍开封
无敌手，闯下了赫赫威名，人称“铁拳镇关中”。这都是二十年
前的往事了，现在柳老拳师赋闲在家，左右无事，便开了这家武
场，每日里教弟子们练拳，日子过得倒也充实。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"kai6",
  "west" : __DIR__"kai3",
]));
        set("objects",([
        __DIR__"npc/dizi": 3,
]));

	setup();
	replace_program(ROOM);
}
