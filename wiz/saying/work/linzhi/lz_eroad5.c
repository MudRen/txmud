//lz_eroad5.c 林芝村东口跟森林相连接的地方
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","村东山路");
        set("long", @LONG
走出原始森林，一条小路往西迤逦而去，似乎通向一个小村
庄，不过建筑风格迥异于中原，南边有一片枫林，枫叶如火，风
景宜人，随着微风似乎有水声传来。东边倒是有一间茅屋，依稀
倒是有点汉族的影子。路边有一个牌子。
LONG
        );

        set("item_desc",([
        "牌子":HIR"注意！前方森林无路可通，且有护树圣兽伤人！\n"NOR,
]));
        set("exits", ([
        "east":__DIR__"maowu",
        "west":__DIR__"lz_eroad4",
        "north":__DIR__"forestend",
]));
        setup();
}
void init()
{
        add_action("do_pass","pass");
}
int do_pass(string arg)
{
        object me;
       me=this_player();
        if (!arg)
        return notify_fail("你要穿越哪里？\n");
        if (arg=="枫树林"||arg=="maple") {
        if (this_player()->query_temp("mark/枫树林")) {
        write("你一头钻进枫树林.......\n");
        message("vision",me->name()+"一头钻进枫树林，转眼间就不见了.......\n",environment(me),({me}));
        me->move(__DIR__"maple_s");
        message("vision",me->name()+"走了过来。\n",environment(me),({me}));
         return 1;
}
        else return notify_fail("你看了半天，不得其门而入。\n");
        }
}
