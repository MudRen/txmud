//t_left1.c 德木寺练武场。
inherit ROOM;
void create()
{
        set("short", "广场");
        set("long", @LONG
这里是德木寺的练武场，有几个喇嘛正在对打，还有几个在
做基本的功夫，举举石锁，打打沙袋什么的。你看了看，似乎没
有什么高深的功夫。看来密宗的功夫还是布达拉宫才是真传。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"temple1",
]));
        set("objects",([
        __DIR__"obj/shisuo":2,
]));
        setup();
}
