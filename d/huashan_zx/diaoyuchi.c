// room: huashan diaoyuchi.c by pian

inherit ROOM;

void create()
{
        set("short","碧潭垂钓");
        set("long", @LONG
阳光下一道飞瀑如练，瀑布下是一方水潭。幽绿的潭水泛着
青波。潭边一块突出的岩石有人在垂钓。边上还有几幅钓具，你
不想试试吗？
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"taolin",
]));
        setup();
	replace_program(ROOM);
}
