//huang_room.c 钱庄秘道出口。
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","钱庄密室");
        set("long", @LONG
这里是林芝村钱庄下的密室，墙壁上的牛油大烛照得这里十
分明亮，不过还是让人感觉此地阴森恐怖，可能是由于这里的杀
气太重了。前方墙壁上正中的『铜火炬』甚是显眼。
LONG
        );
        set("exits", ([
        "east":__DIR__"bank_d/exit",
]));
        set("item_desc",([
        "铜火炬":"火炬的柄锃明刷亮，似乎经常有人触摸。你可以摇摇（yao）看。"
]));
        set("objects",([
        __DIR__"npc/real_huang":1
]));
        setup();
}
void init()
{
        add_action("do_yao","yao");
}
int do_yao(string arg)
{
        object me=this_player();
        if (!arg||arg!="铜火炬")
        {
                tell_object(CYN"你要摇什么？\n"NOR,me);
                return 0;
        }
        else 
        {
                say("$N摇了摇墙壁上的火炬，闪进了旁边打开的暗门",me);
                me->move(__DIR__"lz_wroad2");
        }
}
