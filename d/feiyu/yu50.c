// Room: /u/w/wangs/a/yu50.c

inherit ROOM;

void create()
{
	set("short", "÷��԰");
	set("long", @LONG
����������÷������ɫ��ǳһ���һ����ٴ�˿������״��
�������ˣ�����ʹ������÷�����Կຮ�����ľ��䣬����
����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yu99",
  "east" : __DIR__"yu51",
]));
        set("objects", ([
        __DIR__"npc/liuaiai": 1,
                        ]) );
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
