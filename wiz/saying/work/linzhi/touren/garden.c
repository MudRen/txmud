//garden.c 林芝镇头人府花园
inherit ROOM;
void create()
{
        set("short","小花园");
        set("long", @LONG
这里是头人府的小花园。想不到这样的地方居然也有这么一
个温馨的小天地，跟前面刀枪并列杀气腾腾迥然不同。你暗暗的
想：莫非查查这个土人也懂得风花雪月不成？南边是厨房，西边
是柴房，北边则通向后院。
LONG
        );
        set("exits", ([
        "east":__DIR__"main",
        "west":__DIR__"wood_room",
        "north":__DIR__"road1",
        "south":__DIR__"cook_room",
]));
        setup();
}
