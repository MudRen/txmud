//house3.c 林芝村的民居
inherit ROOM;
void create()
{
        set("short", "民居");
        set("long", @LONG
这是一家普通的民居，看得出日子过得还算充裕。墙壁上挂
着钢刀猎叉，看得出这里的人们还是很强悍，不过他们对朋友也
很是热情，家里的人一看见你进来就拉住你喝奶茶。这一家的院
子里晾着几件刚洗过的衣服。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"lz_sroad2",
]));
        set("objects",([
        __DIR__"npc/lady" : 1,
]));
        setup();
}
