// Room: /d/huashan/maonv.c

inherit ROOM;

void create()
{
	set("short", "毛女洞");
	set("long", @LONG
相传战国时期一位公主甚爱玉笙，常常夜里独自吹笙，忽然
一阵萧声由天籁传来与笙乐相呼应，国王派人在华山找到了吹萧
的萧使，于是将他招为驸马，二人成亲后来到这里隐居。后人就
将此洞叫作毛女洞。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wolf1" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"maonv1.c",
  "south" : __DIR__"shanlu2",
]));
	set("no_clean_up", 0);
	set("indoors", "huashan");

	setup();
	replace_program(ROOM);
}
