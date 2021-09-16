// Room: /u/w/wangs/b/kai130.c

inherit ROOM;

void create()
{
	set("short", "灌肠店");
	set("long", @LONG
灌肠店的门面并不大，装潢也不考究，但是这的老板不但可
以将一口猪做出一百零八种不同的的肠，而且是关外数一数二的
摔跤高手。他腰上扎着宽皮带、秃着脑袋、挺着胸站在门口，就
是块活招牌。经过这里的江湖豪杰若没有到灌肠店来喝两杯，就
好像觉得有点不大够意思。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai129",
]));

        set("objects",([
        __DIR__"npc/gcboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
