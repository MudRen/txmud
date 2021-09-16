// nhroad1  北环路

inherit ROOM;

void create()
{
        set("short", "北环路");
        set("long", @LONG
这里是长安城内环路北面，内环路由于紧邻皇宫内城加之又
是各衙门的所在地所以禁卫森严，不时有巡城军队从这里走过。
北面是国家的文事重地--国子监，门口有官军把守，不时有文官
书生模样的人出入，门边停着几乘小轿。
LONG
        );
       set("exits", ([
                "west"             : __DIR__"nhroad2",
                "east"             : __DIR__"ehroad4",
                "north"            : "/d/guozijian/gzj_gate",
]) );
       set("outdoors","changan");
        setup();
	replace_program(ROOM);
}