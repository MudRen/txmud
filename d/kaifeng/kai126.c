// Room: /u/w/wangs/b/kai126.c

inherit ROOM;

void create()
{
	set("short", "豆腐店");
	set("long", @LONG
这里就是开封的豆腐店了。豆腐店的门不宽，也不是时常开
着的。但门旁的窗户却是很大，用两根竹竿支得高高的。东城区
有名的千里飘香--豆腐花就站在这个窗户后，每天只是在天色刚
刚发亮的时候卖豆腐，不过买的人却很多。     
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai125",
]));

        set("objects",([
        __DIR__"npc/dfboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
