// ft_fenduo.c

inherit ROOM;

void create()
{
        set("short", "侧殿");
        set("long", @LONG
你来到了神武祠的侧殿，这里就是丐帮奉天分舵所在。丐帮
一直是以保家卫国而为老百姓所尊重的，在这里设立分舵，也可
以说是对外国匪帮的威慑。你要是在奉天城里打听丐帮打罗刹鬼
的事，还可以听到不少的传说和小道故事。
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
                "south" : "/d/fengtian/shenwu",
        ]));

        set("objects",([
        __DIR__"npc/ft_duozhu" : 1,
        ]));
 
        setup();
        replace_program(ROOM);
}
