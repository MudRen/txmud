// /d/changan/sroad3 华瑞街

inherit ROOM;

void create()
{
        set("short", "华瑞街");
        set("long", @LONG
这里是长安城的南大街，由于这里离官道很远，所以在这里
比较僻静，多是外地的人在此来往。偶尔也有几个带刀的巡捕从
这里经过。华瑞街由这里向东西两方向延伸。
LONG
        );
       set("exits", ([
	"west" : __DIR__"sroad2",
	"east" : __DIR__"sroad4",
	"north" : __DIR__"business",
 ]) );
       set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
