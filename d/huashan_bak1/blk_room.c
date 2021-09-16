// Room: /d/huashan/blk_room.c

inherit ROOM;

void create ()
{
        set("short", "暗室");
    set("long", @LONG
这里是一间非常昏暗的小屋，阳光透过很小的天窗，你只能
模糊看见屋内四周。小屋阴森冰冷，好像曾经是关押过犯人的牢
房，也许要仔细调查一下。
LONG
        );

  set("exits", ([ /* sizeof() == 1 */
  "westup" : __DIR__"blk_road2",
]) );

  set("light_up", 1);

  setup();
}

void init()
{
   add_action("do_diaocha","diaocha");
   add_action("do_diaocha","check");
   add_action("open_my_door","za");
   add_action("enter_my_door","enter");
}

int do_diaocha(string str)
{
        tell_object(this_player(),"你仔细调查了一下，发现有一堵墙有些奇怪，也许是个暗门。\n");
        return 1;
}

int open_my_door(string str)
{

    if (!str)
                return notify_fail("你要砸什么？\n");
        if (str!="墙" && str!="wall")
                return notify_fail("你要砸什么？\n");
        if (this_player()->query("force",1)<1000 ||
                this_player()->query_str()<40)
                return notify_fail("你试着砸对面的墙，但是墙却纹丝不动。\n");

        tell_object(this_player(),"你运足内力，“喝”的一声将对面墙的暗门推开了。\n");
    this_player()->start_busy(2);
        this_player()->set_temp("dilao_enter", 1);
        this_player()->add("force", -600);
        return 1;
}

int enter_my_door(string str)
{
    if (!str || !this_player()->query_temp("dilao_enter"))
                return notify_fail("你进入哪里？\n");
        if (str!="dilao" && str!="prizon" && str!="地牢")
                return notify_fail("你进入哪里？\n");
        message_vision("$N走进了暗门。\n暗门“啪”的一声关上了！\n",this_player());
        this_player()->delete_temp("dilao_enter");
        this_player()->move(__DIR__"dilao");
        return 1;
}


