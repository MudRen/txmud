// xiaoxiang.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "小巷");
        set("long", @LONG
这是一条黑暗、肮脏的小巷，空气中仿佛飘扬着一股罪恶的气息，西
北边通向小巷深处，正人君子是不会往那边走去的。西边是一家破旧的民
居，门前卧着一只看门狗，往东北走就会回到镇中大路了。
LONG
        );

        set("outdoors", "houjizhen");

        set("exits", ([ /* sizeof() == 2 */
  	"west" : __DIR__"minju2",
  	"northwest" : __DIR__"xiaoxiang1",
  	"southeast" : __DIR__"shilu5",
]));
        
        set("objects", ([
                __DIR__"npc/dog": 1,
	]));

        setup();
        replace_program(ROOM);
}


