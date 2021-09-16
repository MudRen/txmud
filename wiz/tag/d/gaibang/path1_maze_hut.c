// path1_maze_hut.c

inherit ROOM;

void create()
{
        set("short", "草屋");
        set("long", @LONG
这里是破落大院的侧厅，杂物乱七八糟地扔了一地没人收拾。
有一个乞丐躺在席子哼着什么，见你进来，他打了个哈欠。整个
房间只能用破烂不堪形容，天花板上还不时掉点灰土下来。
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
                "south" : __DIR__"path1_maze/exit",
        ]));

        set("objects",([
        __DIR__"npc/dt_old_beggar" : 1,
        ]));
 
        setup();
        replace_program(ROOM);
}
