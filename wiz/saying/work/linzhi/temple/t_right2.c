//t_right2.c 德木寺兵器室。
inherit ROOM;
void create()
{
        set("short", "兵器室");
        set("long", @LONG
这里是德木寺的兵器室，但是里面空落落的没有什么东西，
真是奇怪护寺的僧兵们的兵器都是哪里拿的。不过似乎这些僧兵
的功夫也都很稀松，拿不拿兵器没什么两样。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "west":__DIR__"temple2",
]));
        setup();
}
