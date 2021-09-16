// Room: /u/w/wangs/a/yu4.c

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是一间客房，靠墙放了一张梨木大床，上面的被褥尽
是苏绣，工美绝伦。正中放了一张八仙桌，桌上摆着些果品，
使人垂涎欲滴。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yu2",
]));

        set("objects", ([
        __DIR__"npc/han": 1,
                        ]) );
	setup();
	replace_program(ROOM);
}
