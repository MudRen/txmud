//servant_room2.c 婢女住房。
inherit ROOM;
void create()
{
        set("short","婢女宿处");
        set("long", @LONG
这里是头人府婢女住宿的地方。屋里面一列通铺，女仆们就
住在这里。这里还算宽敞，收拾的也很整齐，似乎女人们确实喜
欢干净，旁边居然还有一个不小的玻璃窗，因此屋里非常明亮。
LONG
        );
        set("exits", ([
        "east":__DIR__"courtyard",
]));
        setup();
}
