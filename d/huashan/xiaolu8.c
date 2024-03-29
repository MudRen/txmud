// Room: /d/huashan/xiaolu8.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条狭窄的山间小路，一旁是山崖，一旁是深涧，稍不
留神，就有可能掉下山去。白云不时从你脚下漂过，你不禁感到
有些累了。西边丛生着一簇簇荆棘(jingji)，传来一阵阵哗哗的
声响。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"xiaolu9",
  "southdown" : __DIR__"xiaolu7",
]));

	set("item_desc", ([
	"jingji" : "好像在荆棘背后有一条小路，你似乎可以推开(push)荆棘。\n",
]));

	set("outdoors", "huashan");
	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if(!arg || (arg != "jingji" && arg != "荆棘")) 
		return 0;

	if(undefinedp(query("exits/westup")))
	{
		set("exits/westup",__DIR__"huapo");
		message_vision("$N拔开了荆棘，发现了一条向西的路。\n",me);
		call_out("do_close",10);
	}

	else
		message_vision("$N拔动着荆棘，发出了沙沙的声响。\n",me);
	return 1;
}

void do_close()
{
	if(!undefinedp(query("exits/westup")))
	{
		tell_room(__FILE__,"一阵山风吹来，向西的路被荆棘掩没了。\n");
		delete("exits/westup");
	}
}
