// Room: /u/w/wangs/a/yu86.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������˽�˷��䣬���ϱ�������������룬
����Ҳ��һ����Ⱦ������ôððʧʧ�Ĵ��˽����ƺ���Щ��
̫��ò��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yu84",
]));
        set("objects", ([
        __DIR__"npc/huan": 1,
                        ]) );

	setup();
	replace_program(ROOM);
}
