//servant_room1.c 仆人住房。
inherit ROOM;
void create()
{
        set("short","仆人宿处");
        set("long", @LONG
这里是头人府仆人住宿的地方。屋里面一列通铺，下人们就
住在这里。这里虽然宽敞，但是光线并不是很好，收拾的也还算
整齐，毕竟大人们是不会来这里的。
LONG
        );
        set("exits", ([
        "west":__DIR__"courtyard",
]));
        setup();
}
