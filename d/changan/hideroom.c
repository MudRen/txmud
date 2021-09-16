// Room: /d/changan/hideroom.c

inherit ROOM;

void create()
{
	object obj = new(GOLD_OB);
	obj->set_amount(20);
	obj->move(this_object());

	set("short", "密室");
	set("long", @LONG
这是一间什麽也没有的空房间，左面的墙上有一扇很小的窗
户。
LONG
	);
	set("no_clean_up", 0);
	set("hide_exits",([
	"southeast" : __DIR__"fruitroom",
]));

	setup();
	replace_program(ROOM);
}
