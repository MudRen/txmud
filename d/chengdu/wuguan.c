// Room: /wiz/louth/c/wuguan.c

inherit ROOM;

void create()
{
	set("short", "川候武馆");
	set("long", @LONG
这里是成都最大的川候武馆。馆内的教头和弟子不下数十人，
每天都能看到武馆弟子在认真练习武功。这里向东走是武王道。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wwdao2",
]));
        set("objects",([
                __DIR__"npc/jiaotou" :1,        
        ]));

	setup();
	replace_program(ROOM);
}
