// Room: /d/fengtian/quest4.c

inherit ROOM;

void create()
{
	set("short", "土山洞");
	set("long", @LONG
这是一个黑漆漆的小土洞，洞壁上插着一只火把。迎面的土
墙上嵌着一块石板。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"quest3",
]));

	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player(),ob;

	if(arg != "石板")
		return notify_fail("你要推什么？\n");

	ob = find_object(__DIR__"quest5");
	if(!ob)
		ob = load_object(__DIR__"quest5");

	if(!ob || (me->query("force") < 200))
		return notify_fail("你用力推了一下，可是石板纹丝没动。\n");

	message_vision("$N推开石板，后面露出了一个出口。\n",me);

	tell_room(ob,"有人推开石板，露出了一个出口。\n");

	set("exits/north",__DIR__"quest5");
	ob->set("exits/south",__DIR__"quest4");

	call_out("do_close",8);
	return 1;
}

private void do_close()
{
	object ob;

	tell_room(__FILE__,"石板慢慢的移回了原位。\n");
	delete("exits/north");

	ob = find_object(__DIR__"quest5");
	if(!ob)
		ob = load_object(__DIR__"quest5");

	if(ob)
	{
		tell_room(ob,"石板慢慢的移回了原位。\n");
		ob->delete("exits/south");
	}
}
