// Room: /u/w/wangs/a/yu30.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������һ�����ң�ֻ��֪����λ���ס�����
��������ʰ�øɸɾ�����������������ӿ��Կ�����һ����
λ��Ư�������ͻݵĽ��ס�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yu29",
]));
        set("objects", ([
        __DIR__"npc/ning": 1,
                        ]) );

	setup();
	replace_program(ROOM);
}
