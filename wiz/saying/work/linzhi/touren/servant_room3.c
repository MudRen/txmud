//servant_room3.c 婢女住房。
inherit ROOM;
void create()
{
        set("short","女婢房间");
        set("long", @LONG
这里是夫人和小姐的贴身婢女的宿处。屋里有几张香喷喷的
牙床，还有梳妆台，红木衣柜等家具，还有一个大大的玻璃窗，
看来待遇比外面那些干粗活的奴仆们高多了。
LONG
        );
        set("exits", ([
        "east":__DIR__"backyard2",
]));
        setup();
}
