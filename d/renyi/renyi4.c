// Room: /d/renyi/renyi4.c

inherit ROOM;

inherit __DIR__"die";

void create()
{
	set("short", "庄门");
	set("long", @LONG
这里是一处用毛竹扎绑的大门，静悄悄的没有一个人把守，
门的正上方是一块木匾，上写着“仁义庄”三个大字。
LONG
	);

	set(SAFE_ENV, 1);
	set("no_memory", 1);

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"renyi3",
  "southwest" : __DIR__"renyi5",
]));

	set("outdoors", "renyi");

	setup();
}

int valid_leave(object ob, string dir)
{
	mapping q;

	if(!userp(ob))
		return 1;

	if(mapp(q = ob->query("enyi_class")) && sizeof(q))
		return 1;

	if(dir == "north")
	{
		ob->set_mask_name("陌生人");
		ob->set_mask_id("xiake");
	}
	else
	{
		ob->remove_mask_name();
		ob->remove_mask_id();
	}

	return 1;
}
