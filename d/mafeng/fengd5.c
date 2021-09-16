// Room: /d/path3/fengd5.c

inherit ROOM;

void create()
{
	set("short", "半山树林");
	set("long",  @LONG
这里是一小片浓密的树林，参天的古树这天蔽日，地上是齐
脚深的枯枝败叶，山风吹过四处沙沙乱想，说不出的阴森恐怖。
LONG
);
	set("exits", ([
  "south" : __DIR__"fengd2",
  "north" : __DIR__"fengd8",
  "west" : __DIR__"fengd6",
  "east" : __DIR__"fengd4",
]));

	set("outdoors", "mafeng");
	setup();
}

void init()
{
	object me;

	if(!random(3)
	|| (find_call_out("do_begin") != -1)
	|| !objectp(me = this_player())
	|| !userp(me) )
		return;
	call_out("do_begin",2);
}

protected void do_begin()
{
	object cob;

	if(!objectp(cob = find_object(__DIR__"control")) && !objectp(cob = load_object(__DIR__"control")))
		return;

	cob->query_leader();
}