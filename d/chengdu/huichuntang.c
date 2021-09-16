// Room: /wiz/louth/c/huichuntang.c

inherit ROOM;

void create()
{
	set("short", "回春堂");
	set("long", @LONG
这里是是在全国都数的上数的回春堂药店。它有天麻这味独
特中药。天麻味甜，性微寒，中医根据它的益气、定惊、养肝、
上晕、祛风湿、强筋骨等作用。因为次物是回春堂都有的，每年
都有大批药材贩子来次购要。从西面出来就是武王道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wwdao1",
]));
        set("objects",([
        __DIR__"npc/longboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
