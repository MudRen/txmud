// kai190.c
// by dicky

inherit ROOM;

void create ()
{
        set ("short", "民居");
        set ("long", @LONG
这栋房子里象是很久没有人居住了，墙脚屋檐下到处都是灰，四周
到处都是灰尘和蜘蛛网，还经常可以看到肥肥的老鼠跑来跑去。院中杂
草从生，还可听到几声蛐蛐叫。
LONG);

        set("exits", ([
                "south" : __DIR__"kai23",
                "east" : __DIR__"kai191",
        ]));

        setup();
        replace_program(ROOM);
}
