// Room: /u/w/wangs/a/yu12.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
���߽���һ��С�ݣ������С������һ��С���Ų��±�
�Ķ����ˡ����Ϻ����м���������������Ĵֲ�����ϴ�ĸ�
�ɾ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"yu11",
]));
        set("objects", ([
        __DIR__"npc/master1": 1,
                        ]) );

	setup();
	replace_program(ROOM);
}
