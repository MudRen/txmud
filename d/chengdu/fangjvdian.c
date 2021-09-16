// Room: /wiz/louth/c/fangjvdian.c

inherit ROOM;

void create()
{
	set("short", "防具店");
	set("long", @LONG
这里是成都的防具店。店内摆放，排挂着各式各样的护具。
防具店老板正笑眯眯的等者你的到来。东面出门就是武王道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wwdao1",
]));
        set("objects",([
        __DIR__"npc/jinboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
