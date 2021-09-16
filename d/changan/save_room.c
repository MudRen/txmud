// Room: /d/changan/save_room.c

inherit ROOM;

void create()
{
	set("short", "空房间");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);

	setup();
}

void refresh_inv()
{
	object *inv;

	if(!previous_object() || (previous_object() != find_object(__DIR__"selling_room")))
		return;

	if(sizeof(inv = filter_array(all_inventory(this_object()), (: !$1->is_character() :))))
		foreach(object ob in inv)
			destruct(ob);
}

int clean_up()
{
	if(find_object(__DIR__"selling_room"))
		return 1;

	return ::clean_up();
}

void reset() { return; }
