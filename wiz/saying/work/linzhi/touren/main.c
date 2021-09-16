//main.c 林芝镇头人府大厅
#include <room.h>
inherit ROOM;
int do_touch(string arg);
void create()
{
        set("short","大厅");
        set("long", @LONG
这里是头人府的大厅。迎面墙上是一副非常大的毡布画，好
像画的是查查头人驱逐圣兽的故事。两边的墙壁上挂满了兵器，
看上去杀气腾腾的，倒也符合头人的身份。东北墙角有一个小木
门，西边通往后堂。
LONG
        );
        set("exits", ([
        "east":__DIR__"secrety",
        "west":__DIR__"garden",
        "south":__DIR__"courtyard",
]));
        set("item_desc",([
        "画":"画面上是四个青年率领许多藏人歼灭圣兽的故事，当先的一个似乎是查查头人。\n",
]));
        setup();
        create_door("east", "木门", "west", DOOR_CLOSED,LOCKED,__DIR__"obj/jail_key");
}
void init()
{
        add_action("do_touch","touch");
}
int do_touch(string arg)
{
        object obj;
        object me;
        me=this_player();
        if (!arg||arg!="画")
        {
                tell_object(me,"你想触摸什么？\n");
                return 0;
        }
        if (arg=="画")
        {
                obj=new(__DIR__"obj/jail_key");
                obj->move(me);
                tell_object(me,"忽然你摸到了什么东西，赶快偷偷的把它揣到怀里。\n");
                message("vision",me->name()+"在画后面摸出什么东西。\n",environment(me),({me}));
                return 1;
        }
}
