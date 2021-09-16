// Room: /d/shaolin/jjting.c

inherit ROOM;

int check_weapon(object who);

void create()
{
	set("short", "解剑亭");
	set("long", @LONG
这是山半腰的一个亭子，也许由于年代的久远亭柱上的字已
经斑驳的看不出来了，亭上有一块匾，上书“解剑亭”三个苍劲
有力的大字，亭旁有一块小石碑上书少林寺。一条蜿蜒的小路通
向山下，往上看是一条笔直的山道。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shandao5",
  "southeast" : __DIR__"xiaolu1",
]));

	set("objects",([
	__DIR__"npc/jjseng" : 1,
]));

	setup();
}

int valid_leave(object ob,string dir)
{
	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob) && !wizardp(ob)
	&& (dir == "northup" || dir == "nu")
	&& ob->query("class") != "shaolin"
	&& !check_weapon(ob) )
		return notify_fail("知客僧说道：“少林寺乃佛门清静之地，施主请将随身兵器留在这里。\n”");
	else
		return ::valid_leave(ob,dir);
}

int check_weapon(object who)
{
	object checker, *ob;

	checker = present("zhike seng",this_object());
	if(!objectp(checker))
		return 1;

	ob = filter_array(deep_inventory(who),(: $1->is_weapon() :));
	if(arrayp(ob) && sizeof(ob))
		return 0;
	else
		return 1;
}