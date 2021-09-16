// Room: /wiz/louth/a/shanlu7.c

inherit ROOM;

void create()
{
	set("short", "小庙");
	set("long", @LONG
这是一座已经破败的小庙，烟火已断，无人打理，到处都落
满了厚厚的灰尘，墙角、房梁上都结了蜘蛛网。庙内那高高的神
像也因年久失修，变得破落不堪。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shanlu6",
]));
        set("item_desc",([
        "神像" : "一座旧的不能再旧的神像了。好象还被人挪开过。\n",
        "shen xiang" : "一座旧的不能再旧的神像了。好象还被人挪开过。\n",
]));

	setup();
}

void init()
{
        add_action("do_move","move");
}

int do_move(string arg)
{
        object me = this_player();

        if (arg != "神像" && arg != "shen xiang")
                return 0;
        message_vision("$N使劲推了推神像，发现后边原来是一条通往后山的小路\n",me);
        set("exits/north", __DIR__"houlu1");
        call_out("greeting",6);
        return 1;
}

void greeting()
{
        write ("神像慢慢的回到了原来的位置。\n");
        delete("exits/north");
}

